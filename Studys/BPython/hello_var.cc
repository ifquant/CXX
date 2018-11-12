
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : hello_var.cpp
#   Last Modified : 2018-11-12 13:58
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <boost/python.hpp>

using namespace std;
using namespace boost::python;

struct Var
{
  Var(string name):name(name),value(){}
  string const name;
  float value;
};

BOOST_PYTHON_MODULE(hello_var)
{
  class_<Var>("Var", init<string>())
    .def_readonly("name",&Var::name)
    .def_readwrite("value",&Var::value);
}


// int main() {

