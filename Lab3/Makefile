all:
	@(if [ ! -d build ]; then mkdir build; fi; cd build;\
	  if [ ! -d compress_text ]; then mkdir compress_text; fi; cmake ..; make)

clean:
	rm -rf build /compress_text
	rm -rf build /CMakeCache.txt
