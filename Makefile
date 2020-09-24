CXX = g++

REQUIREMENTS_LIST = 'requirements.md'

test-generate-requirements:
	$(TESTING_FILES) -r tap-modified | ./requirement_tracer.py -o $(TEST_REPORT_FILE) -r $(REQUIREMENTS_LIST) -a $(FILES_TO_HASH)
