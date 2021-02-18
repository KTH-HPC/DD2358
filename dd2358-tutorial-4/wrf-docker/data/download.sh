#!/bin/bash

#wget https://www2.mmm.ucar.edu/wrf/TUTORIAL_DATA/JAN00_GFS_FNL.tar.gz
#tar -xvzf JAN00_GFS_FNL.tar.gz
#rm JAN00_GFS_FNL.tar.gz
#
#wget https://www2.mmm.ucar.edu/wrf/src/wps_files/geog_low_res_mandatory.tar.gz \
#  && wget https://www2.mmm.ucar.edu/wrf/src/wps_files/topo_gmted2010_30s.tar.bz2 \
#  && wget https://www2.mmm.ucar.edu/wrf/src/wps_files/modis_landuse_20class_30s_with_lakes.tar.bz2 \
#  && wget https://www2.mmm.ucar.edu/wrf/src/wps_files/soiltype_bot_30s.tar.bz2 \
#  && wget https://www2.mmm.ucar.edu/wrf/src/wps_files/soiltype_top_30s.tar.bz2 \
#  && wget https://www2.mmm.ucar.edu/wrf/src/wps_files/greenfrac_fpar_modis.tar.bz2 \
#  && wget https://www2.mmm.ucar.edu/wrf/src/wps_files/orogwd_10m.tar.bz2 \
#  && tar -xvzf geog_low_res_mandatory.tar.gz \
#  && rm geog_low_res_mandatory.tar.gz

cd WPS_GEOG_LOW_RES \
 && tar -xvjf ../topo_gmted2010_30s.tar.bz2 \
 && tar -xvjf ../modis_landuse_20class_30s_with_lakes.tar.bz2 \
 && tar -xvjf ../soiltype_bot_30s.tar.bz2 \
 && tar -xvjf ../soiltype_top_30s.tar.bz2 \
 && tar -xvjf ../greenfrac_fpar_modis.tar.bz2 \
 && tar -xvjf ../orogwd_10m.tar.bz2 \
 && rm ../topo_gmted2010_30s.tar.bz2 \
 && rm ../modis_landuse_20class_30s_with_lakes.tar.bz2 \
 && rm ../soiltype_bot_30s.tar.bz2 \
 && rm ../soiltype_top_30s.tar.bz2 \
 && rm ../greenfrac_fpar_modis.tar.bz2 \
 && rm ../orogwd_10m.tar.bz2
