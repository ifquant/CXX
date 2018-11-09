
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
    SECTION( "resizing bigger changes size and capacity" ) {
        REQUIRE( xquant::FindInMap(s2i,"ddd") == 1 );
    }
}

TEST_CASE( "xquant::utility_GetParam", "[GetParam]" ) {
    // For each section, vector v is anew:
    SECTION( "resizing bigger changes size and capacity" ) {
        map<string, std::variant<int64_t,int,double>> m2v = {
           {"ddd", std::variant<int64_t,int,double>{(int64_t)12}},
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

/*
template <typename M, typename V>
std::optional<V> GetParam(const M& var_map, const std::string& name) {
  auto it = var_map.find(name);
  if (it == var_map.end()) return {};
  if (auto pval = std::get_if<V>(&it->second)) return *pval;
  return {};
}

template <typename M, typename V>
inline V GetParam(const M& var_map, const std::string& name, V default_value) {
  return GetParam<M, V>(var_map, name).value_or(default_value);
}

template <typename M>
inline int GetParam(const M& var_map, const std::string& name,
                    int default_value) {
  return GetParam<M, int64_t>(var_map, name).value_or(default_value);
}

template <typename M>
inline std::string GetParam(const M& var_map, const std::string& name,
                            const char* default_value) {
  return GetParam<M, std::string>(var_map, name).value_or(default_value);
}
*/
