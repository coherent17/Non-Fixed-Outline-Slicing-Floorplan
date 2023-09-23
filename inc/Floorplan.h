#ifndef _FLOORPLAN_H_
#define _FLOORPLAN_H_

#include "Module.h"
#include <bits/stdc++.h>
using namespace std;

class Floorplan{
    private:
        int Num_Modules;
        vector<Module *>Modules;

    public:
        Floorplan();
        ~Floorplan();

        void Parser(ifstream &);

};

#endif