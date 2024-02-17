
DEEPAPI:="e8ad9dbd-17a0-9e73-615b-1acac4947e08:fx"

deepAPI:=URL_HEAD_INCLUDE_API="Authorization: DeepL-Auth-Key $(DEEPAPI)"

default:
	cmake -S. -Bbuild  -D$(deepAPI)


clean:
	if [ -d build ]; then rm -rf build ; fi
.PHONY:default clean
