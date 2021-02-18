FROM ubuntu:20.04

ENV TZ=Europe/Stockholm
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get -y update \
  && apt-get -y install wget build-essential gfortran m4 libpng-dev libnetcdff-dev netcdf-bin ncl-ncarg \
  && wget https://www.ece.uvic.ca/~frodo/jasper/software/jasper-1.900.29.tar.gz \
  && tar xvf jasper-1.900.29.tar.gz

WORKDIR /

ENV WRF_VERSION 4.2
ENV WPS_VERSION 4.2.2

WORKDIR /jasper-1.900.29
RUN ./configure --prefix=/usr && make && make install

WORKDIR /
RUN rm -rf /jasper-1.900.29 /jasper-1.900.29.tar.gz \
  && wget https://github.com/wrf-model/WRF/archive/v4.2.2.tar.gz \
  && tar xvf v4.2.2.tar.gz \
  && mv WRF-4.2.2 WRF

WORKDIR /WRF
ENV NETCDF /usr
ENV NETCDF_classic 1
RUN echo "33\n1" | ./configure \
  && sed -i 's/-lwrfio_nf -L\/usr\/lib/-lwrfio_nf -L\/usr\/lib -lnetcdf -lnetcdff/g' configure.wrf \
  && ./compile -j 8 em_real

WORKDIR /
RUN rm v4.2.2.tar.gz \
  && wget https://github.com/wrf-model/WPS/archive/v4.2.tar.gz \
  && tar xvf v4.2.tar.gz && mv WPS-4.2 WPS

WORKDIR /WPS
ENV WRF_DIR ../WRF/
RUN echo "1" | ./configure \
  && sed -i 's/-lnetcdf/-lnetcdf -lnetcdff -lgomp/g' configure.wps \
  && ./compile

WORKDIR /
VOLUME /DATA
Add run-wrf.sh /usr/bin/
RUN chmod u+x /usr/bin/run-wrf.sh
ENTRYPOINT ["/usr/bin/run-wrf.sh"]
CMD ["JAN00", "fnl_2000012"]
