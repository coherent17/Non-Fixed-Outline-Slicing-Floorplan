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
        vector<pair<double, double>> Width_Height_Combination;
        double Width;
        double Height;

    public:
        Module(int, int);
        ~Module();

        // Getter
        int Get_Module_ID()const;
        string Get_Module_Name()const;
        int Get_Module_Area()const;
        double Get_Width()const;
        double Get_Height()const;

    friend ostream &operator<<(ostream &, const Module &);
};

#endif