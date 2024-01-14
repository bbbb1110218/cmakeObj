


default:
	make clean
	cmake -S. -Bbuild 
.PHONY:default

install:default
	cd build && make

clean:
	if [ -d build/ ]; then\
		rm -rf build; \
	fi
