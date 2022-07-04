# CMake generated Testfile for 
# Source directory: /home/bharath/catkin_ws/src/rosserial/rosserial_client
# Build directory: /home/bharath/catkin_ws/build/rosserial_client
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_rosserial_client_gtest_float64_test "/home/bharath/catkin_ws/build/rosserial_client/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/bharath/catkin_ws/build/rosserial_client/test_results/rosserial_client/gtest-float64_test.xml" "--return-code" "/home/bharath/catkin_ws/devel/.private/rosserial_client/lib/rosserial_client/float64_test --gtest_output=xml:/home/bharath/catkin_ws/build/rosserial_client/test_results/rosserial_client/gtest-float64_test.xml")
set_tests_properties(_ctest_rosserial_client_gtest_float64_test PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/catkin/cmake/test/gtest.cmake;98;catkin_run_tests_target;/opt/ros/noetic/share/catkin/cmake/test/gtest.cmake;37;_catkin_add_google_test;/home/bharath/catkin_ws/src/rosserial/rosserial_client/CMakeLists.txt;14;catkin_add_gtest;/home/bharath/catkin_ws/src/rosserial/rosserial_client/CMakeLists.txt;0;")
add_test(_ctest_rosserial_client_gtest_subscriber_test "/home/bharath/catkin_ws/build/rosserial_client/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/bharath/catkin_ws/build/rosserial_client/test_results/rosserial_client/gtest-subscriber_test.xml" "--return-code" "/home/bharath/catkin_ws/devel/.private/rosserial_client/lib/rosserial_client/subscriber_test --gtest_output=xml:/home/bharath/catkin_ws/build/rosserial_client/test_results/rosserial_client/gtest-subscriber_test.xml")
set_tests_properties(_ctest_rosserial_client_gtest_subscriber_test PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/catkin/cmake/test/gtest.cmake;98;catkin_run_tests_target;/opt/ros/noetic/share/catkin/cmake/test/gtest.cmake;37;_catkin_add_google_test;/home/bharath/catkin_ws/src/rosserial/rosserial_client/CMakeLists.txt;15;catkin_add_gtest;/home/bharath/catkin_ws/src/rosserial/rosserial_client/CMakeLists.txt;0;")
add_test(_ctest_rosserial_client_gtest_time_test "/home/bharath/catkin_ws/build/rosserial_client/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/bharath/catkin_ws/build/rosserial_client/test_results/rosserial_client/gtest-time_test.xml" "--return-code" "/home/bharath/catkin_ws/devel/.private/rosserial_client/lib/rosserial_client/time_test --gtest_output=xml:/home/bharath/catkin_ws/build/rosserial_client/test_results/rosserial_client/gtest-time_test.xml")
set_tests_properties(_ctest_rosserial_client_gtest_time_test PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/catkin/cmake/test/gtest.cmake;98;catkin_run_tests_target;/opt/ros/noetic/share/catkin/cmake/test/gtest.cmake;37;_catkin_add_google_test;/home/bharath/catkin_ws/src/rosserial/rosserial_client/CMakeLists.txt;16;catkin_add_gtest;/home/bharath/catkin_ws/src/rosserial/rosserial_client/CMakeLists.txt;0;")
subdirs("gtest")
