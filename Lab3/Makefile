all:
	@(if [ ! -d build ]; then mkdir build; fi; cd build;\
	  if [ ! -d text_analysis ]; then mkdir text_analysis; fi; cmake ..; make)

clean:
	rm -rf build /text_analysis
	rm -rf build /CMakeCache.txt
