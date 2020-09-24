# This Dockerfile will create an image which can run GDBGUI in a linux environment

## Image Setup ##################################################################
# Start with base image
FROM ubuntu:latest

## Run Installs ###############################################################
# These are run first to avoid having to re-run them on file edits/rebuilds
# Update apt
RUN apt-get update
# Text editor
RUN apt-get -y install nano
# SSH server
RUN apt-get -y install openssh-server
# X11 server
RUN apt-get -y install x11-apps

RUN apt-get -y install git-core
RUN apt-get -y install python3
RUN apt-get -y install build-essential

# X11 setup
ENV DISPLAY=host.docker.internal:0

# Copy all files from repository
COPY ./src /src
ENV SRC_DIR=/src

# Copy and use the main makefile
COPY ./docker/scripts /
ENTRYPOINT ["make"]
