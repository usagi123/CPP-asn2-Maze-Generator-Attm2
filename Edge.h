//
// Created by Mai Pham Quang Huy on 2019-05-08.
//

#ifndef ASN2_ATT2_EDGE_H
#define ASN2_ATT2_EDGE_H


#include <stdio.h>
#include "Coordinator.h"

class Edge {
private:
    Coordinator coordinator1;
    Coordinator coordinator2;
public:
    const Coordinator &getCoordinator1() const;

    void setCoordinator1(const Coordinator &coordinator1);

    const Coordinator &getCoordinator2() const;

    void setCoordinator2(const Coordinator &coordinator2);
};


#endif //ASN2_ATT2_EDGE_H
