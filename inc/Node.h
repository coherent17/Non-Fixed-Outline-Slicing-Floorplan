#ifndef _NODE_H_
#define _NODE_H_

#include "Module.h"
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int type;
        Node *left;
        Node *right;
        Module *m;

    public:
        Node(Module *, int type);
        ~Node();
};

#endif