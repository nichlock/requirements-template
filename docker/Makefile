# Makefile for docker container with SSH server/X11 client

IMAGE_TAG = test_template:latest

CONTAINER_NAME = test_template

# Docker commands
D_RUN = docker run
D_BUILD = docker build
D_RM_IMAGE = docker image rm
D_KILL = docker kill

# Dockerfile Locations
DOCKERFILE = ./Dockerfile

refresh: kill run

## LOCAL BUILDS ###############################################################
# These build off the source files found in ../
build:
	$(D_BUILD) \
	-t $(IMAGE_TAG) \
	-f $(DOCKERFILE) \
	../

run: build
	@echo ctrl-P then ctrl-Q to detach.
	$(D_RUN) \
	-p 22:22 \
	--rm \
	--env DISPLAY=host.docker.internal:0 \
	--name $(CONTAINER_NAME) \
	-it $(IMAGE_TAG)

## KILL DETATCHED CONTAINER ###################################################
kill:
	-$(D_KILL) $(CONTAINER_NAME)
