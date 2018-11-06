
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : test_singleton.cc
#   Last Modified : 2018-11-07 03:22
#   Describe      :
#
# ====================================================*/

// 010-TestCase.cpp

// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include <catch.hpp>


#include "xquant/common.h"
#include <iostream>
using namespace std;
using namespace xquant;

class Test : public Singleton<Test> {
  public:
    int test() {return 1;}
};

class AccountManager : public Singleton<AccountManager> {
};


TEST_CASE( "Factorial of 0 is 1 (fail)", "[single-file]" ) {
    REQUIRE( Test::Instance().test() == 1 );
    REQUIRE( 2 == 2 );
}
