#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "hdf5.h"

// source: https://github.com/takafumihoriuchi/MNIST_for_C/blob/master/mnist.h

void read_mnist_image(const char *file_path, int data_count, int len_info, int arr_n, double *data, int *info_arr)
{
    int fd;
    unsigned char data_char[arr_n];

    if ((fd = open(file_path, O_RDONLY)) == -1) {
        fprintf(stderr, "couldn't open image file\n");
        exit(-1);
    }

    // read header
    read(fd, info_arr, len_info * sizeof(int));

    // read data
    for (int i = 0; i < data_count; i++) {
        read(fd, data_char, arr_n * sizeof(unsigned char));   
        for (int j = 0; j < arr_n; j++) {
            data[i * arr_n + j] = (double)data_char[j] / 255.0;
        }
    }

    close(fd);
}

void read_mnist_label(const char *file_path, int data_count, int len_info, int arr_n, int *data, int *info_arr)
{
    int fd;
    unsigned char data_char;

    if ((fd = open(file_path, O_RDONLY)) == -1) {
        fprintf(stderr, "couldn't open label file\n");
        exit(-1);
    }

    // read header
    read(fd, info_arr, len_info * sizeof(int));

    // read data
    for (int i = 0; i < data_count; i++) {
        read(fd, &data_char, sizeof(unsigned char));
        data[i] = (int)data_char;
    }

    close(fd);
}


int main(int argc, char *argv[])
{
    herr_t  status;
    int info_image[4];
    int info_label[2];

    // prepare to read data
    double *mnist_image = (double*)malloc(60000 * 784 * sizeof(double));
    int    *mnist_label = (int*)malloc(60000 * sizeof(int));

    // read data from MNIST bin files
    read_mnist_image("./train-images-idx3-ubyte", 60000, 4, 784, mnist_image, info_image);
    read_mnist_label("./train-labels-idx1-ubyte", 60000, 2,   1, mnist_label, info_label);

    // define dataset size: 6k samples, 28x28 each
    hsize_t image_data_dim[3]    = {60000, 28, 28};

    // define chunking, storing 1000 samples per chunk
    hsize_t image_chunk_dims[3]  = {1000, 28, 28};

    // create a new HDF5 file
    hid_t file = H5Fcreate("./mnist.h5", H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);

    // set chunking scheme
    hid_t dcpl = H5Pcreate(H5P_DATASET_CREATE);
    status     = H5Pset_chunk(dcpl, 3, image_chunk_dims);

    // create space for dataset in rank 3 with 600000x28x28
    hid_t space = H5Screate_simple(3, image_data_dim, NULL);

    // create a dataset called "Image" in the space created, using float64 in little-endian
    hid_t dset  = H5Dcreate(file, "Image", H5T_IEEE_F64LE, space, H5P_DEFAULT, dcpl, H5P_DEFAULT);

    // write data in double format
    status = H5Dwrite(dset, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, mnist_image);

    // close this dataset
    status = H5Dclose(dset);
    status = H5Sclose(space);
    printf("Written Image dataset...\n");

    // create a new dataset for labels
    hsize_t label_data_dim[1]   = {60000};
    hsize_t label_chunk_dims[1] = {1000};

    // follow same chunking as image data
    status = H5Pset_chunk(dcpl, 1, label_chunk_dims);

    // create space for dataset in rank 1 with 60000
    space  = H5Screate_simple(1, label_data_dim, NULL);

    // create a dataset called "Label" in the space created, using int32 in little-endian
    dset   = H5Dcreate(file, "Label", H5T_STD_I32LE, space, H5P_DEFAULT, dcpl, H5P_DEFAULT);

    // write data in integer format
    status = H5Dwrite(dset, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT, mnist_label);

    // cleanup
    status = H5Dclose(dset);
    status = H5Sclose(space);
    status = H5Pclose(dcpl);
    status = H5Fclose (file);
    printf("Written Label dataset...\n");

    free(mnist_label);
    free(mnist_image);
}
