all: build run

build:
	@cmake -S . -B build
	@cmake --build build

run:
	@./build/nesnes

clean:
	@rm -rf build

.PHONY: build run clean
