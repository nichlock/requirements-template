CXX = g++

test:
	./main.exe -r tap | ./generate/requirement_tracer.py -o 'req_trace.md' -r 'requirements.md' -a 'Makefile'

build: main
