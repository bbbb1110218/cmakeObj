
all: default 

default:
	mkdir -p build
	cd build && cmake .. && make
debug:
	mkdir -p build
	cd build && cmake -DNEEDDEBUG=TURE .. && make


clean:
	if [ -d "build" ]; then rm -rf build; fi
.PHONY: clean