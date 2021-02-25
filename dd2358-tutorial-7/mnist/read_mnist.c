#include <stdio.h>
#include <stdlib.h>
#include <hdf5.h>

int main(int argc, char *argv[])
{
    herr_t status;

    // open HDF5 file
    hid_t file  = H5Fopen("./mnist.h5", H5F_ACC_RDONLY, H5P_DEFAULT);

    // open image dataset
    hid_t dset  = H5Dopen(file, "Image", H5P_DEFAULT);

    // get handle to space for dataset
    hid_t space = H5Dget_space(dset);

    // get rank of dataset and prepare to get the dim
    int rank  = H5Sget_simple_extent_ndims(space);

    // get the dim of the dataset
    hsize_t image_dims[rank];
    status = H5Sget_simple_extent_dims(space, image_dims, NULL);

    // compute total memory required to read dataset and allocate memory
    int total_size = 1;
    for (int i = 0; i < rank; i++) total_size *= image_dims[i];
    double *mnist_image = (double*)malloc(total_size* sizeof (double));

    // read dataset in double format
    status = H5Dread(dset, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, mnist_image);

    // close this dataset
    H5Sclose(space);
    H5Dclose(dset);

    // open the label dataset
    dset  = H5Dopen(file, "Label", H5P_DEFAULT);

    // get handle to space that holds the dataset
    space = H5Dget_space(dset);

    // get the rank of the dataset
    rank  = H5Sget_simple_extent_ndims(space);

    // compute total memory required to read dataset and allocate memory
    hsize_t label_dims[rank];
    status = H5Sget_simple_extent_dims(space, label_dims, NULL);
    total_size = 1;
    for (int i = 0; i < rank; i++) total_size *= label_dims[i];
    int *mnist_label = (int*)malloc(total_size* sizeof (int));

    // read dataset in integer
    status = H5Dread(dset, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT, mnist_label);

    // close dataset and file
    H5Sclose(space);
    H5Dclose(dset);
    H5Fclose(file);

    // printout
    for (long int i = 0; i < image_dims[0]; i++) {
        printf("Label: %d\n\n", mnist_label[i]);
        for (long int j = 0; j < image_dims[1]; j++) {
            for (long int k = 0; k < image_dims[2]; k++) {
                double pixel = mnist_image[(i * (image_dims[1] * image_dims[2])) + image_dims[1] * j + k];
                if (pixel > 0.5)
                    printf("* ");
                else
                    printf(". ");
            }
            printf("\n");
        }
        printf("\n");
    }
}
