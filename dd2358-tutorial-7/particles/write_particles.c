#include <hdf5.h>
#include <math.h>

// particle data structure
typedef struct particle3D {
    double x, y, z; // coordinates 
} particle_t;

#define PARTICLE_COUNT 15

int main(int argc, char **argv){

     // define particles
     particle_t particles[PARTICLE_COUNT];

     for (int i=0; i < PARTICLE_COUNT; i++) {
         double t = i*0.2;
         particles[i].x = cos(t);
         particles[i].y = sin(t);
         particles[i].z = t;
     }

     // create HDF5 type layout in memory
     hid_t mtype = H5Tcreate(H5T_COMPOUND, sizeof(particle_t));
     H5Tinsert(mtype, "x coordinate", HOFFSET(particle_t, x), H5T_NATIVE_DOUBLE);
     H5Tinsert(mtype, "y coordinate", HOFFSET(particle_t, y), H5T_NATIVE_DOUBLE);
     H5Tinsert(mtype, "z coordinate", HOFFSET(particle_t, z), H5T_NATIVE_DOUBLE);

     // create data space
     hsize_t dim = PARTICLE_COUNT;
     hid_t space = H5Screate_simple(1, &dim, NULL);

     // create new file with default properties
     hid_t fd = H5Fcreate("particles.h5", H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);
     // create data set
     hid_t dset = H5Dcreate(fd, "particle data", mtype, space, H5P_DEFAULT,
     H5P_DEFAULT, H5P_DEFAULT);
     // write the entire dataset and close the file
     H5Dwrite(dset, mtype, H5S_ALL, H5S_ALL, H5P_DEFAULT, particles);
     H5Fclose(fd);
}
