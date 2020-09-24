CXX = g++

test-generate-requirements:
	../src/main -r tap-modified | ./requirement_tracer.py -o 'req_trace.md' -r 'requirements.md' -a 'Makefile'
