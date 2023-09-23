#ifndef _MODULE_H_
#define _MODULE_H_

#include "Util.h"
#include <bits/stdc++.h>
using namespace std;

class Module{
    private:
        int Module_ID;
        string Module_Name;
        int Area;
        vector<pair<int, int>> Width_Length_Combination;

    public:
        Module(int, int);
        ~Module();
};

#endif