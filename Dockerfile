FROM debian:buster-slim

LABEL authors="Antonio Matteo Talamona <contact@talamona.com>, Team <contact@example.com>"

ENV DISPLAY=host.docker.internal:0
ENV DEBIAN_FRONTEND=noninteractive

RUN mkdir -p /app
WORKDIR /app

RUN apt update

RUN apt install -qy \
    build-essential \
    libsdl2-dev \
    libc6-dev \
    libc6 \
    libsdl-ttf2.0-dev \
    mesa-utils \
    libsdl2-image-dev 

# If you need them, just uncomment.
# RUN apt install -qy python-pip git-core unzip zip curl bash vim
# RUN apt install -qy gdb valgrind

# Cleanup, cam be commented
RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*