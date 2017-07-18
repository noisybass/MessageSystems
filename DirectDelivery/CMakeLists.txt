#boost
set(Boost_ADDITIONAL_VERSIONS "1.64" "1.64.0")
set(Boost_USE_STATIC_LIBS   ON)
set(BOOST_ROOT ../Libs/boost_1_64_0)
find_package(Boost 1.64.0)

if(Boost_FOUND)
  	include_directories(${Boost_INCLUDE_DIRS})
  	  
  	file(GLOB SOURCES "./*.cpp")
	add_executable(directDelivery ${SOURCES})
else()
    message(STATUS "Fail to load Boost!!")
endif()
