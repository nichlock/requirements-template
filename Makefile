CXX = g++

test-generate-requirements:
	../src/main -r p-modified | ./generate/requirement_tracer.py -o 'req_trace.md' -r 'requirements.md' -a 'Makefile'
