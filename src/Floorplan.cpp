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

void Floorplan::Run(){
    Initialize_Normalized_Polish_Expression();
}

void Floorplan::Initialize_Normalized_Polish_Expression(){
    Normalized_Polish_Expression.push_back(Modules[0]->Get_Module_ID());
    for(size_t i = 1; i < Modules.size(); i++){
        Normalized_Polish_Expression.push_back(Modules[i]->Get_Module_ID());
        if(i != Modules.size() - 1){
            Normalized_Polish_Expression.push_back(V);
        }
    }
    cout << "Normalized Polish Expression: ";
    for(size_t i = 0; i < Normalized_Polish_Expression.size(); i++){
        if(Normalized_Polish_Expression[i] == V){
            cout << "V";
            continue;
        }
        cout << Normalized_Polish_Expression[i];
    }
    cout << endl;
}