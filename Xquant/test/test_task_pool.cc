
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : test_task_pool.cc
#   Last Modified : 2018-11-07 12:39
#   Describe      :
#
# ====================================================*/

// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include <iostream>
using namespace std;

#include "xquant/task_pool.h"



TEST_CASE( "Test poll", "[single-file]" ) {

  xquant::TaskPool pool;
  //void AddTaskForward(T &&func, Args&&...args) {
  //void AddTask(T &&func, Args&&...args) {
  boost::posix_time::ptime  time_before (boost::posix_time::microsec_clock::universal_time() /*+ boost::posix_time::seconds(5)*/);
  boost::posix_time::ptime  time_after=time_before + boost::posix_time::time_duration(0,0,0,100*1000);
  volatile int val = 1;
  pool.AddTask([&val](){
      val = 0;
      },time_after);
  while (1 == val);
  boost::posix_time::ptime  time_now ( boost::posix_time::microsec_clock::universal_time() );
  boost::posix_time::time_duration td = time_now - time_after;
  //std::cout << td.total_nanoseconds() << " : " << td.total_milliseconds();
  REQUIRE( td.total_nanoseconds() < 50000 );
}




