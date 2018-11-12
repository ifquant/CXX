#set(IFQCONF_SOURCE_FILES
#    ifqconf_test.cpp)

#ADD_EXECUTABLE(test_ifqconf ${IFQCONF_SOURCE_FILES})
#TARGET_LINK_LIBRARIES(test_idata ifq wiredtiger mongocxx bsoncxx pthread dl)

cmake_minimum_required (VERSION 2.8)

project (ifqtest)
include(${CMAKE_SOURCE_DIR}/../../cmake/find_all.cmake)

# some 3rd-party/customed include/link path
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -export-dynamic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations -std=c++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")


INCLUDE_DIRECTORIES(
${CMAKE_SOURCE_DIR}/../../Thirds/ 
${CMAKE_SOURCE_DIR}/../src/ 
)

LINK_DIRECTORIES(
${CMAKE_SOURCE_DIR}/ThirdParty/
${CMAKE_SOURCE_DIR}/build/
${LOG4CXX_LIBRARY_PATH}
${QUICKFIX_LIBRARY_PATH}
${PYTHON_LIBRARY_PATH}
${SOCI_CORE_LIBRARY_PATH}
${SOCI_POSTGRES_LIBRARY_PATH}
${TBB_LIBRARY_PATH}
)


# add external libraries
set (EXTRA_LIBS ${EXTRA_LIBS} dl ${Boost_LIBRARIES}  crypto pthread)


aux_source_directory (. SRC_LIST)
execute_process (
  COMMAND echo "start"
  COMMAND echo ${SRC_LIST}
  #COMMAND echo ${CMAKE_SOURCE_DIR}
  )


# get source files holding main() function
execute_process (
  COMMAND echo ${SRC_LIST}
  COMMAND xargs egrep "main" -l
  #  COMMAND xargs egrep "main[ \t]*(.*)[ \t]*$" -l
  WORKING_DIRECTORY ../../test/                      # NOTICE: Assumed build directory is ${SOURCE_DIR}/build, so
# You may change the value of WORKING_DIRECTORY to suit your needs
  OUTPUT_VARIABLE TARGET_LIST
  #COMMAND echo ${TARGET_LIST}
  )

execute_process (
  COMMAND echo "start"
  COMMAND echo ${SRC_LIST}
  COMMAND echo ${TARGET_LIST}
  #COMMAND echo ${CMAKE_SOURCE_DIR}
  )


string (REGEX REPLACE "\n$" "" TARGET_LIST ${TARGET_LIST})

# count number of targets
execute_process (
  COMMAND echo ${TARGET_LIST}
  COMMAND wc -l
  OUTPUT_VARIABLE TARGET_NUM
  )

# convert string from "./$1\n./$2\n..." to "$1 $2 ..."
string (REGEX REPLACE "[.]/" "" TARGET_LIST ${TARGET_LIST})
string (REGEX REPLACE "\n" " " TARGET_LIST ${TARGET_LIST})

enable_testing ()
foreach ( i RANGE 1 ${TARGET_NUM})
  execute_process (
    COMMAND echo "${TARGET_LIST}"
    COMMAND cut -d " " -f ${i}
    OUTPUT_VARIABLE SRC
  )
  string (REGEX REPLACE "\n" "" SRC ${SRC})
  string (REGEX REPLACE "[.]cc$" ".elf" ELF ${SRC})
  add_executable (${ELF} ${SRC})
  ADD_TEST(NAME ${ELF} COMMAND ${ELF})

  execute_process (
	  COMMAND echo "${ELF}"
  )

  target_link_libraries (${ELF} ${EXTRA_LIBS})
  #add_test (${ELF}_Runs ${ELF})
endforeach (i)

# do sth more, like add more tests...#


