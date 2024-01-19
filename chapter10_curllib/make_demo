
DEEPAPI:="27fb772c-d742-6af2-931d-54f25ef67f7e:fx"

deepAPI:=URL_HEAD_INCLUDE_API="Authorization: DeepL-Auth-Key $(DEEPAPI)"

default:
	cmake -S. -Bbuild  -D$(deepAPI)


clean:
	if [ -d build ]; then rm -rf build ; fi
.PHONY:default clean