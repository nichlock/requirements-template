CXX = g++

BUILD_DIR = build

build: build_dir_created main

test:
	$(CXX) -c test.cpp -o $(BUILD_DIR)/test.o

main:
	$(CXX) -o $(BUILD_DIR)/out.exe $(BUILD_DIR)/test.o main.cpp

build_dir_created:
	-mkdir $(BUILD_DIR)
