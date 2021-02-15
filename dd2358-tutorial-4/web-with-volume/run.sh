#!/bin/bash

docker run --rm -v `pwd`/data:/data -p 80:8888 -it python-http:latest
