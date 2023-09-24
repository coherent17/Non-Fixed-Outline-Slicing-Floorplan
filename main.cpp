#include "Floorplan.h"

int main(int argc, char *argv[]){
    ifstream fin(argv[1]);
    Floorplan *fp = new Floorplan();
    fp->Parser(fin);
    fp->Run();
    delete fp;
    return 0;
}