
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : rvalue.cc
#   Last Modified : 2018-11-03 23:14
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <utility>
#include <vector>
using namespace std;
void f(vector<int> &vs)
{
        //vector<int> &v2 = std::move(vs);
}

vector<int>  ff() {
        vector<int> i = {1,2,3};
        return i;
}

vector<int>&  fff() {  //bad code 
        //vector<int> *i =new vector<int> {1,2,3};
        //return *i;
        vector<int> i = {1,2,3};
        return i;

}


int main(int argc, char *argv[])
{
        vector<int> ia = {1,2,3};
        const vector<int> &b = std::move(ia);
        std::cout << b.size();
        const vector<int> c = std::move(ia);
        std::cout << b.size();
        int i = 10;

        // int &j = std::move(i); bad
        vector<int> &j = fff();
        for(auto x:j) {
                std::cout <<x;
        }
        return 0;
}
