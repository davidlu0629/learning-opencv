# learning-opencv
# Opencv on ubuntu(step by step) Version(OpenCV:3.2.0, Ubuntu:16.04LTS)
step1. intall essential tool
>>>    sudo apt-get install build-essential

step2. something we may need
>>> sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev  
>>>   sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev

step3. download opencv
>>>    wget https://github.com/Itseez/opencv/archive/3.2.0.zip

step4. unzip opencv & cd to folder you unzip

step5. make a new folder named "build" 
>>> mkdir build  
>>> cd build

step6. cmake compile(the most important and easy to meet mistake)
>>>    cmake -DBUILD_TIFF=ON -DBUILD_opencv_java=OFF -DWITH_CUDA=OFF -DENABLE_AVX=ON -DWITH_OPENGL=ON -DWITH_OPENCL=ON -DWITH_IPP=ON -DWITH_TBB=ON -DWITH_EIGEN=ON -DWITH_V4L=ON -DWITH_VTK=OFF -DBUILD_TESTS=OFF -DBUILD_PERF_TESTS=OFF -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_INSTALL_PREFIX=$(python3 -c "import sys; print(sys.prefix)") -DPYTHON3_EXECUTABLE=$(which python3) -DPYTHON3_INCLUDE_DIR=$(python3 -c "from distutils.sysconfig import get_python_inc; print(get_python_inc())") -DPYTHON3_PACKAGES_PATH=$(python3 -c "from distutils.sysconfig import get_python_lib; print(get_python_lib())") ..

step7. compile
>>>    make -j4

step8. install opencv
>>>    sudo make install

FINISH

Test a file to see if it can work(use cmake)  
  Install cmake  
  >>>  sudo apt-get install cmake-gui     
  we can enter 'cmake-gui' to open the application
  
  Before we compile the file we need a 'CMakeLists.txt' file, the detail of the file seems like:
    # cmake needs this line(usually no need to change)
    cmake_minimum_required(VERSION 2.8)

    # Define project name(your project name)
    project(opencv_example_project)

    # Find OpenCV, you may need to set OpenCV_DIR variable
    # to the absolute path to the directory containing OpenCVConfig.cmake file
    # via the command line or GUI(usually no need to change)
    find_package(OpenCV REQUIRED)

    # If the package has been found, several variables will
    # be set, you can find the full list with descriptions
    # in the OpenCVConfig.cmake file.
    # Print some message showing some of them(usually no need to change)
    message(STATUS "OpenCV library status:")
    message(STATUS "    version: ${OpenCV_VERSION}")
    message(STATUS "    libraries: ${OpenCV_LIBS}")
    message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

    if(CMAKE_VERSION VERSION_LESS "2.8.11")
      # Add OpenCV headers location to your include paths
      include_directories(${OpenCV_INCLUDE_DIRS})
    endif()

    # Declare the executable target built from your sources(first part is your object file name, the second part is your file name)
    add_executable(opencv_example example.cpp)

    # Link your application with OpenCV libraries(change only first part which should be your project name)
    target_link_libraries(opencv_example ${OpenCV_LIBS})
    
  Then, use 'cmake-gui' to setup path to your source code, where you want to make binary code and set path to folder 'build'
  Click 'Configure' & 'Generate' to see if there are any error
  then,
  >>>cmake .
  >>>make
  execute object file
  >>>./opencv_example

Reference
http://www.cnblogs.com/simplelovecs/p/5156458.htm
http://www.cnblogs.com/woshijpf/p/3840530.html
https://gist.github.com/scienceopen/a855d6dbfa5406e67fe9
