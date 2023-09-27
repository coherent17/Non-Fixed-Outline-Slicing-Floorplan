#include "Node.h"

Node::Node(Module *m, int type){
    this->m = m;
    this->type = type;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node(){
    
}