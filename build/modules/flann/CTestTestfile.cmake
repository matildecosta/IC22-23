# CMake generated Testfile for 
# Source directory: /home/matilde/Desktop/IC/IC-Lab/opencv/modules/flann
# Build directory: /home/matilde/Desktop/IC/IC-Lab/build/modules/flann
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_flann "/home/matilde/Desktop/IC/IC-Lab/build/bin/opencv_test_flann" "--gtest_output=xml:opencv_test_flann.xml")
set_tests_properties(opencv_test_flann PROPERTIES  LABELS "Main;opencv_flann;Accuracy" WORKING_DIRECTORY "/home/matilde/Desktop/IC/IC-Lab/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/matilde/Desktop/IC/IC-Lab/opencv/cmake/OpenCVUtils.cmake;1751;add_test;/home/matilde/Desktop/IC/IC-Lab/opencv/cmake/OpenCVModule.cmake;1352;ocv_add_test_from_target;/home/matilde/Desktop/IC/IC-Lab/opencv/cmake/OpenCVModule.cmake;1110;ocv_add_accuracy_tests;/home/matilde/Desktop/IC/IC-Lab/opencv/modules/flann/CMakeLists.txt;2;ocv_define_module;/home/matilde/Desktop/IC/IC-Lab/opencv/modules/flann/CMakeLists.txt;0;")
