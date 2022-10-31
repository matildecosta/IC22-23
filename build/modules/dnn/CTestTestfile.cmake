# CMake generated Testfile for 
# Source directory: /home/matilde/Desktop/IC/IC-Lab/opencv/modules/dnn
# Build directory: /home/matilde/Desktop/IC/IC-Lab/build/modules/dnn
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_dnn "/home/matilde/Desktop/IC/IC-Lab/build/bin/opencv_test_dnn" "--gtest_output=xml:opencv_test_dnn.xml")
set_tests_properties(opencv_test_dnn PROPERTIES  LABELS "Main;opencv_dnn;Accuracy" WORKING_DIRECTORY "/home/matilde/Desktop/IC/IC-Lab/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/matilde/Desktop/IC/IC-Lab/opencv/cmake/OpenCVUtils.cmake;1751;add_test;/home/matilde/Desktop/IC/IC-Lab/opencv/cmake/OpenCVModule.cmake;1352;ocv_add_test_from_target;/home/matilde/Desktop/IC/IC-Lab/opencv/modules/dnn/CMakeLists.txt;218;ocv_add_accuracy_tests;/home/matilde/Desktop/IC/IC-Lab/opencv/modules/dnn/CMakeLists.txt;0;")
add_test(opencv_perf_dnn "/home/matilde/Desktop/IC/IC-Lab/build/bin/opencv_perf_dnn" "--gtest_output=xml:opencv_perf_dnn.xml")
set_tests_properties(opencv_perf_dnn PROPERTIES  LABELS "Main;opencv_dnn;Performance" WORKING_DIRECTORY "/home/matilde/Desktop/IC/IC-Lab/build/test-reports/performance" _BACKTRACE_TRIPLES "/home/matilde/Desktop/IC/IC-Lab/opencv/cmake/OpenCVUtils.cmake;1751;add_test;/home/matilde/Desktop/IC/IC-Lab/opencv/cmake/OpenCVModule.cmake;1251;ocv_add_test_from_target;/home/matilde/Desktop/IC/IC-Lab/opencv/modules/dnn/CMakeLists.txt;223;ocv_add_perf_tests;/home/matilde/Desktop/IC/IC-Lab/opencv/modules/dnn/CMakeLists.txt;0;")
add_test(opencv_sanity_dnn "/home/matilde/Desktop/IC/IC-Lab/build/bin/opencv_perf_dnn" "--gtest_output=xml:opencv_perf_dnn.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
set_tests_properties(opencv_sanity_dnn PROPERTIES  LABELS "Main;opencv_dnn;Sanity" WORKING_DIRECTORY "/home/matilde/Desktop/IC/IC-Lab/build/test-reports/sanity" _BACKTRACE_TRIPLES "/home/matilde/Desktop/IC/IC-Lab/opencv/cmake/OpenCVUtils.cmake;1751;add_test;/home/matilde/Desktop/IC/IC-Lab/opencv/cmake/OpenCVModule.cmake;1252;ocv_add_test_from_target;/home/matilde/Desktop/IC/IC-Lab/opencv/modules/dnn/CMakeLists.txt;223;ocv_add_perf_tests;/home/matilde/Desktop/IC/IC-Lab/opencv/modules/dnn/CMakeLists.txt;0;")
