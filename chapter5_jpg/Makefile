

project_name:=/Users/min122218/temp/jpg/build/jpeg.out

arg:=/Users/min122218/Downloads/7d7eec7b72addb3d0b9a5bb8cdcd5704.JPG

build:
	make clean 
	cmake -S. -Bbuild 
.PHONY:build 




install:build 
	cd build 
	make 
	cmake --install . --prefix "$HOME/app"
	cd ..


run:
	./$(project_name) $(arg)
.PHONY:run

project_name:CMakelists.txt jpg.c
	make clean
	cmake -S. -Bbuild 
	cd build 
	


.PHONY:clean 
clean:
	if [ -d build ] ;then \
	rm -rf build ; \
	fi
