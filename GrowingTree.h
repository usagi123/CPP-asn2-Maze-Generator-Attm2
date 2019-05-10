//
// Created by Mai Pham Quang Huy on 2019-05-08.
//

#ifndef ASN2_ATT2_GROWINGTREE_H
#define ASN2_ATT2_GROWINGTREE_H

#include <stdlib.h>
#include "Maze.h"

class GrowingTree : public Maze {
public:
    vector<Edge> generate();
};


#endif //ASN2_ATT2_GROWINGTREE_H
