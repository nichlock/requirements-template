CXX = g++
GIT_GLOBAL_CONFIG = git config --global
GIT = git

TESTING_FILES = '../src/main'
TEST_REPORT_FILE = 'req_trace.md'

CODE_LOCATION = /src
REQ_CLONE_LOCATION = /requirements-template

# GITHUB_REPO = github.com/nichlock/requirements-template.git
GIHUB_REPO_REQUIREMENTS_BRANCH = requirements
GITHUB_NAME = "$(GITHUB_USER) <commit automated>"

AUTO_COMMIT_MSG = 'Automated requirements commit'

all: build test

build:
	cd $(CODE_LOCATION); make

test: build requirements-tracing

requirements-tracing: push-github-with-credentials

pull-requirements-branch:
	$(GIT) clone -b $(GIHUB_REPO_REQUIREMENTS_BRANCH) https://$(REPO_URL_NO_HTTP)
	chmod 777 -R $(REQ_CLONE_LOCATION)/

write-tracer-file: export TESTING_FILES = '../src/main' TEST_REPORT_FILE = 'req_trace.md'
write-tracer-file: pull-requirements-branch
	cd $(REQ_CLONE_LOCATION); make

add-file-and-commit: write-tracer-file
	cd $(REQ_CLONE_LOCATION); $(GIT) add $(TEST_REPORT_FILE)
	$(GIT_GLOBAL_CONFIG) user.email $(GITHUB_EMAIL) # From environment
	$(GIT_GLOBAL_CONFIG) user.name $(GITHUB_NAME)
	cd $(REQ_CLONE_LOCATION); $(GIT) commit -m $(AUTO_COMMIT_MSG)

# Password is an access token with only repository access, from host system environment.
# Not all that secure, but at least it's not written in the files!
push-github-with-credentials: add-file-and-commit
	cd $(REQ_CLONE_LOCATION); $(GIT) push --repo https://$(GITHUB_USER):$(GITHUB_ACCESS_TOKEN)@$(REPO_URL_NO_HTTP)
