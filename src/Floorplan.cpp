#include "Floorplan.h"

Floorplan::Floorplan(){
    this->Num_Modules = 0;
}

Floorplan::~Floorplan(){
    for(size_t i = 0; i < Modules.size(); i++){
        delete Modules[i];
    }
}

void Floorplan::Parser(ifstream &fin){
    string line;
    getline(fin, line);
    stringstream ss(line);
    ss >> Num_Modules;
    for(int i = 0; i < Num_Modules; i++){
        getline(fin, line);
        stringstream sss(line);
        int Module_ID;
        int Area;
        sss >> Module_ID >> Area;
        Module *m = new Module(Module_ID, Area);
        Modules.push_back(m);
    }
    fin.close();

    for(size_t i = 0; i < Modules.size(); i++){
        cout << *Modules[i] << endl;
    }
}