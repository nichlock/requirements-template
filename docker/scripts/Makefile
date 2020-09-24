CXX = g++
GIT_GLOBAL_CONFIG = git config --global
GIT = git

FILES_FOR_TEST = '../src/main'
TEST_REPORT_OUTFILE = 'req_trace.md'
DIR_TO_HASH_IN_REPORT = 'Makefile' # TODO

CODE_LOCATION = /src
REQ_CLONE_LOCATION = /requirements-template

# GITHUB_REPO = github.com/nichlock/requirements-template.git
GIHUB_REPO_REQUIREMENTS_BRANCH = requirements
GITHUB_NAME = "$(GITHUB_USER) <commit automated>"

AUTO_COMMIT_MSG = 'Automated requirements commit'

all: build test

build:
	cd $(CODE_LOCATION); make

test: build generate requirements-testing-report

generate requirements-testing-report: push-report-branch

pull-requirements-branch:
	$(GIT) clone -b $(GIHUB_REPO_REQUIREMENTS_BRANCH) https://$(REPO_URL_NO_HTTP)
	chmod 777 -R $(REQ_CLONE_LOCATION)/

# These will define where the report is generated as well as any inputs needed.
generate-report: export TESTING_FILES=$(FILES_FOR_TEST)
generate-report: export TEST_REPORT_FILE=$(TEST_REPORT_OUTFILE)
generate-report: export FILES_TO_HASH=$(DIR_TO_HASH_IN_REPORT)
generate-report: pull-requirements-branch
	cd $(REQ_CLONE_LOCATION); make

add-report-and-commit: generate-report
	cd $(REQ_CLONE_LOCATION); $(GIT) add $(TEST_REPORT_OUTFILE)
	$(GIT_GLOBAL_CONFIG) user.email $(GITHUB_EMAIL) # From environment
	$(GIT_GLOBAL_CONFIG) user.name $(GITHUB_NAME)
	cd $(REQ_CLONE_LOCATION); $(GIT) commit -m $(AUTO_COMMIT_MSG)

# Password is an access token with only repository access, from host system environment.
# Not all that secure, but at least it's not written in the files!
push-report-branch: add-report-and-commit
	cd $(REQ_CLONE_LOCATION); $(GIT) push --repo https://$(GITHUB_USER):$(GITHUB_ACCESS_TOKEN)@$(REPO_URL_NO_HTTP)
