FROM ubuntu:20.04

WORKDIR /
COPY dd2358-tutorial-1.0.tar.gz .
RUN apt-get update && apt-get install -y build-essential && tar -xvzf dd2358-tutorial-1.0.tar.gz
WORKDIR /dd2358-tutorial-1.0
RUN ./configure --prefix=/usr && make && make install
WORKDIR /
ENTRYPOINT ["/usr/bin/main.out"]
