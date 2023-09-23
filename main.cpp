#include "Module.h"

int main(int argc, char *argv[]){
    ifstream fin(argv[1]);
    int n;
    string line;
    getline(fin, line);
    stringstream ss(line);
    ss >> n;
    while(getline(fin, line)){
        stringstream sss(line);
        int id;
        int area;
        sss >> id >> area;
        Module *m = new Module(id, area);
    }
    fin.close();
    return 0;
}