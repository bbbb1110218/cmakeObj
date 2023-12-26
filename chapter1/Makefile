#不需要依赖任何文件的就是伪目标
.PHONY: build xcode clean


build:
	cmake -G "Unix Makefiles" -S. -Bbuild

#生成xcode项目  
# sudo xcode-select -s /Applications/Xcode.app/Contents/Developer
# xcodebuild -version
# sudo xcodebuild -license

xcode:
	cmake -G "Xcode" -S . -BxcodeBuild -DCMAKE_CXX_COMPILER:FILEPATH=/Library/Developer/CommandLineTools/usr/bin/c++ -DCMAKE_C_COMPILER:FILEPATH=/Library/Developer/CommandLineTools/usr/bin/cc


clean:
	rm -rf build 
	rm -rf xcodebuild