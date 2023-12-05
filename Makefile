.PHONY: build xcode clean


build:
	cmake -G "Unix Makefiles" -S. -Bbuild

#生成xcode项目
xcode:
	cmake -G "Xcode" -S . -BxcodeBuild -DCMAKE_CXX_COMPILER:FILEPATH=/Library/Developer/CommandLineTools/usr/bin/c++ -DCMAKE_C_COMPILER:FILEPATH=/Library/Developer/CommandLineTools/usr/bin/cc


clean:
	rf -rf build 