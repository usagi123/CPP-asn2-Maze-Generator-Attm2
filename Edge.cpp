//
// Created by Mai Pham Quang Huy on 2019-05-08.
//

#include "Edge.h"

const Coordinator &Edge::getCoordinator1() const {
    return coordinator1;
}

void Edge::setCoordinator1(const Coordinator &coordinator1) {
    Edge::coordinator1 = coordinator1;
}

const Coordinator &Edge::getCoordinator2() const {
    return coordinator2;
}

void Edge::setCoordinator2(const Coordinator &coordinator2) {
    Edge::coordinator2 = coordinator2;
}
