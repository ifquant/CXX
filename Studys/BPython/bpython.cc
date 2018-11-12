
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : bpython.cc
#   Last Modified : 2018-11-12 08:49
#   Describe      :
#
# ====================================================*/

#define BOOST_PYTHON_SOURCE
#include <boost/python.hpp>
#include <iostream>
using namespace std;

#include<string> 
#include<boost/python.hpp> 
using namespace std; 
using namespace boost::python; 
char const * greet() { return "hello,world"; } 
BOOST_PYTHON_MODULE(hello_ext) { def("greet", greet); }


int testX() { 
#if 1
    if (PyImport_AppendInittab(const_cast<char*>("hello_ext"),
#if PY_VERSION_HEX >= 0x03000000
                             PyInit_hello_ext
#else
                             inithello_ext
#endif
                             ) == -1)
{
  std::cout << "error" << std::endl;
}
#endif
  //PyImport_AppendInittab("hello_ext",PyInit_hello_ext); 
  Py_Initialize();
  FILE* file = fopen("./bpython.py", "r");
  PyRun_SimpleFile(file, "./bpython.py");
  //PyRun_File("bpython.py"); 
  Py_Finalize();
}

//int main()
//{
//  testX();
//}


