
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : auto.cc
#   Last Modified : 2018-11-04 14:13
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <functional>
using namespace std;

auto print(auto x, auto y)
{
        std::cout << x + y;
        return  x + y;
}

void f(double y) {
        //auto z4 = [=,&y]()->int {if (y>1) return 1 ;else return 2;};
        auto z4 = [=,&y]()->int {if (y>1) return 1 ;else return 2.0;};

}

void f(string &s1, string &s2)
{
        //auto rev = [&rev](char *b, char *e) {if (1<e-b){swap(*b,*--e);rev(++b,e);};};
        function<void(char *b, char *e)> rev = 
                [&rev](char *b, char *e){ if (1<e-b){swap(*b,*--e);rev(++b,e);};};
        //function<void(char *b, char *e)> rev = 
        //        [rev](char *b, char *e){ if (1<e-b){swap(*b,*--e);rev(++b,e);};};
        rev(&s1[0],&s1[0]+s1.size());
        rev(&s2[0],&s2[0]+s1.size());
        std::cout << s1 << "   " << s2;
}

void f3() {
        double (*p1)(double) = [](double a) {return sqrt(a);};
}

int main(int argc, char *argv[])
{
        int x=1;
      double y=3;
      auto z =   print(x,y);

      string s1 = "abcd";
      string s2 = "cddd";
      f(s1,s2);
}

