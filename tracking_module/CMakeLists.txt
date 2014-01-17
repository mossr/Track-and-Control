cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(ProjectName TrackingModule)

set(CMAKE_DEFAULT_STARTUP_PROJECT ProjectName)

include_directories(${CMAKE_SOURCE_DIR}/../opencv/build/include)

link_directories(${CMAKE_SOURCE_DIR}/../opencv/build/x86/vc10/lib)

add_executable (${ProjectName} ${CMAKE_SOURCE_DIR}/Tracking.cpp)

target_link_libraries (${ProjectName} 
						opencv_calib3d248d.lib
						opencv_core248d.lib
						opencv_contrib248d.lib
						opencv_imgproc248d.lib
						opencv_highgui248d.lib
						opencv_ml248d.lib
						opencv_video248d.lib
						opencv_features2d248d.lib
						opencv_flann248d.lib
						opencv_gpu248d.lib
						opencv_legacy248d.lib
						opencv_nonfree248d.lib
						opencv_objdetect248d.lib
						opencv_ocl248d.lib
						opencv_photo248d.lib
						opencv_stitching248d.lib
						opencv_superres248d.lib
						opencv_ts248d.lib
						opencv_videostab248d.lib)
project(${ProjectName})