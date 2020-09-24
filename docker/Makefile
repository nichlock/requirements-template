# Makefile for docker container with SSH server/X11 client
# Environemnt variable GITHUB_ACCESS_TOKEN must have an access token that can push to repositories!

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
	--env GITHUB_ACCESS_TOKEN=$(GITHUB_ACCESS_TOKEN) \
	--env GITHUB_USER=$(GITHUB_USER_NAME) \
	--env GITHUB_EMAIL=nichlock@gmail.com \
	--env REQ_BRANCH=requirements \
	--env REPO_URL_NO_HTTP=github.com/nichlock/requirements-template.git \
	--name $(CONTAINER_NAME) \
	-it $(IMAGE_TAG)

## KILL DETATCHED CONTAINER ###################################################
kill:
	-$(D_KILL) $(CONTAINER_NAME)
