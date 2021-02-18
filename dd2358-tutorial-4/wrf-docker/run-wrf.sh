#!/bin/bash

if [[ $# -ne 2 ]]; then
	echo "Usage: run.sh [case name] [prefix]"
	exit 1
fi

CASE=$1
PREFIX=$2

# specify domain
cd /WPS
cp /DATA/namelist.wps .
rm -f geo_em.d*.nc
./geogrid.exe
cp geo_em.d*.nc /DATA/

# grib
ln -sf ungrib/Variable_Tables/Vtable.GFS Vtable
rm -f GRIBFILE.*
./link_grib.csh "../DATA/${CASE}/${PREFIX}"
rm -f FILE:*-*-*_*
./ungrib.exe

# interpolate to domain
rm -f met_em.d*.*-*-*_*:*:*.nc
./metgrid.exe
cp met_em.d*.*-*-*_*:*:*.nc /DATA/

# create WRF input
cd ../WRF/test/em_real
cp /DATA/namelist.input .
rm -f met_em.d*.*-*-*_*:*:*.nc
ln -sf ../../../WPS/met_em.d01.2000-01* .
rm -f wrfinput_d* wrfbdy_d*
./real.exe
cp wrfinput_d* wrfbdy_d* /DATA/

# run wrf
rm -f wrfout_d*_*-*-*_*:*:*
./wrf.exe

# move data to volume
for name in wrfout_d*; do
	mv ${name} /DATA/${name}.nc
done
