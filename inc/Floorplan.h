#ifndef _FLOORPLAN_H_
#define _FLOORPLAN_H_

#include "Module.h"
#include "Node.h"
#include <bits/stdc++.h>
using namespace std;

class Floorplan{
    private:
        int Num_Modules;
        int Outline;
        vector<Module *>Modules;
        vector<int> Normalized_Polish_Expression;
        Node *SlicingTree_Root;

    public:
        Floorplan();
        ~Floorplan();

        void Parser(ifstream &);
        void Run();

    private:
        void Initialize_Normalized_Polish_Expression();
        void Build_SlicingTree();

};

#endif