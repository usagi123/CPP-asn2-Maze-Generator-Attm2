//
// Created by Mai Pham Quang Huy on 2019-05-09.
//

#ifndef ASN2_ATT2_HUNTANDKILL_H
#define ASN2_ATT2_HUNTANDKILL_H

#include <stdlib.h>
#include "Maze.h"

class HuntAndKill: public Maze {
public:
    vector<Edge> generate();
};


#endif //ASN2_ATT2_HUNTANDKILL_H
