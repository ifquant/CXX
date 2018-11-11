
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : test_utility.cc
#   Last Modified : 2018-11-08 16:18
#   Describe      :
#
# ====================================================*/


// main() provided in 000-CatchMain.cpp

#define CATCH_CONFIG_MAIN
#include <catch.hpp>


#include "xquant/utility.h"
#include <variant>
#include <iostream>
using namespace std;

//SCENARIO( "test xquant::utility", "[utility]" ) {
//template <typename V>
//const typename V::mapped_type& FindInMap(const V& map,
//                                         const typename V::key_type& key) {

//template <typename M, typename V>
//std::optional<V> GetParam(const M& var_map, const std::string& name) {

TEST_CASE( "xquant::utility_FindInmap", "[FindInMap]" ) {
    // FindInMap
    map<string,int> s2i = {{"ddd",1}};
    SECTION( "FindInMap GetValueTest" ) {
        REQUIRE( xquant::FindInMap(s2i,"ddd") == 1 );
    }
}

TEST_CASE( "xquant::utility_GetParam", "[GetParam]" ) {
    // For each section, vector v is anew:
    SECTION( " GetParam  GetParam test" ) {
        map<string, std::variant<int64_t,int,double>> m2v = { {"ddd", std::variant<int64_t,int,double>{(int64_t)12}},
           {"ZZZ", std::variant<int64_t,int,double>(1.2)}
        };
        int i = xquant::GetParam(m2v,"ddd",0);
        int j = xquant::GetParam(m2v,"kkk",0);
        double z = xquant::GetParam(m2v,"ZZZ",0.0); //模版匹配规则, 另外 12 总是转化成int,而不是int64
        REQUIRE( i == 12 );
        REQUIRE( j == 0  );
        REQUIRE( fabs(z - 1.2) <1e-6   );
    }
}

TEST_CASE( "xquant::utility_NowUtcInMicro", "[NowUtcInMicro]" ) {
    // For each section, vector v is anew:
    SECTION( "NowUtcInMicro  test" ) {
      int64_t t = xquant::NowUtcInMicro();
      REQUIRE( fabs(t - time(NULL)*1000000) < 1000000 );
    }
}

TEST_CASE( "xquant::utility_GetNowStr", "[GetNowStr]" ) {
    // For each section, vector v is anew:
    SECTION( "NowUtcInMicro  test" ) {
      xquant::GetNowStr();
    }
}

TEST_CASE( "xquant::utility_GetUtcTimeOffset", "[GetUtcTimeOffset]" ) {
    // For each section, vector v is anew:
    SECTION( "GetUtcTimeOffset  GetUtcTimeOffset" ) {
      xquant::GetUtcTimeOffset("GMT+8");
    }
}

TEST_CASE( "xquant::utility_GetUtcSinceMidNight", "[GetUtcSinceMidNight]" ) {
    // For each section, vector v is anew:
    SECTION( "GetUtcSinceMidNight  GetUtcSinceMidNight" ) {
      xquant::GetUtcSinceMidNight(0);
    }
}

TEST_CASE( "xquant::utility_Split", "[Split]" ) {
    // For each section, vector v is anew:
    SECTION( "Split" ) {
      vector<string> out = xquant::Split("34c", "34",true,true);
      REQUIRE( out.size() == 1);
    }
}





