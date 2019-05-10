//
// Created by Mai Pham Quang Huy on 2019-05-09.
//
// https://weblog.jamisbuck.org/2011/1/10/maze-generation-prim-s-algorithm

#include "Prim.h"

vector<Edge> Prim::generate() {
    long seed = getSeed();
    int height = getHeight();
    int width = getWidth();
    bool withSeed = isWithSeed();
    // Keep track visited cells
    bool visitedCells[height][width];
    for (int k = 0; k < height; ++k) {
        for (int i = 0; i < width; ++i) {
            visitedCells[k][i] = false;
        }
    }
    // Create vector to store edges
    vector<Edge> edges;
    // Create vector to store frontiers
    vector<Coordinator> frontiers;
    // Check input seed
    if (!withSeed) {
        seed = time(0);
    }
    srand((int) seed);

    // Pick random cell to start
    Coordinator movingCell;
    movingCell.setX(rand() % height);
    movingCell.setY(rand() % width);
    // Add it to visitedCells list
    visitedCells[movingCell.getX()][movingCell.getY()] = true;

    // Check frontiers of the initial moving cell
    // North
    if (movingCell.getX() - 1 > -1) {
        if (!visitedCells[movingCell.getX() - 1][movingCell.getY()]) {
            Coordinator northCell;
            northCell.setX(movingCell.getX() - 1);
            northCell.setY(movingCell.getY());
            frontiers.push_back(northCell);
        }
    }

    // East
    if (movingCell.getY() + 1 < width) {
        if (!visitedCells[movingCell.getX()][movingCell.getY() + 1]) {
            Coordinator eastCell;
            eastCell.setX(movingCell.getX());
            eastCell.setY(movingCell.getY() + 1);
            frontiers.push_back(eastCell);
        }
    }

    // West
    if (movingCell.getY() - 1 > -1) {
        if (!visitedCells[movingCell.getX()][movingCell.getY() - 1]) {
            Coordinator westCell;
            westCell.setX(movingCell.getX());
            westCell.setY(movingCell.getY() - 1);
            frontiers.push_back(westCell);
        }
    }

    // South
    if (movingCell.getX() + 1 < height) {
        if (!visitedCells[movingCell.getX() + 1][movingCell.getY()]) {
            Coordinator southCell;
            southCell.setX(movingCell.getX() + 1);
            southCell.setY(movingCell.getY());
            frontiers.push_back(southCell);
        }
    }

    // Pick a random frontier to go
    while (!frontiers.empty()) {
        int currentRandom = rand() % frontiers.size();
        movingCell = frontiers[currentRandom];
        visitedCells[movingCell.getX()][movingCell.getY()] = true;
        Edge edge;
        edge.setCoordinator1(movingCell);
        frontiers.erase(remove_if(
                frontiers.begin(),
                frontiers.end(),
                [&movingCell](const Coordinator &coordinator) {
                    return coordinator.getX() == movingCell.getX() && coordinator.getY() == movingCell.getY();
                }), frontiers.end());

        // Visited neighbors vector
        vector<Coordinator> neighbors;

        // Finding 4 directions of cell which direction is available to move
        // North
        if (movingCell.getX() - 1 > -1) {
            Coordinator northCell;
            northCell.setX(movingCell.getX() - 1);
            northCell.setY(movingCell.getY());
            if (visitedCells[movingCell.getX() - 1][movingCell.getY()]) {
                neighbors.push_back(northCell);
            } else {
                frontiers.push_back(northCell);
            }
        }

        // East
        if (movingCell.getY() + 1 < width) {
            Coordinator eastCell;
            eastCell.setX(movingCell.getX());
            eastCell.setY(movingCell.getY() + 1);
            if (visitedCells[movingCell.getX()][movingCell.getY() + 1]) {
                neighbors.push_back(eastCell);
            } else {
                frontiers.push_back(eastCell);
            }
        }

        // West
        if (movingCell.getY() - 1 > -1) {
            Coordinator westCell;
            westCell.setX(movingCell.getX());
            westCell.setY(movingCell.getY() - 1);
            if (visitedCells[movingCell.getX()][movingCell.getY() - 1]) {
                neighbors.push_back(westCell);
            } else {
                frontiers.push_back(westCell);
            }
        }

        // South
        if (movingCell.getX() + 1 < height) {
            Coordinator southCell;
            southCell.setX(movingCell.getX() + 1);
            southCell.setY(movingCell.getY());
            if (visitedCells[movingCell.getX() + 1][movingCell.getY()]) {
                neighbors.push_back(southCell);
            } else {
                frontiers.push_back(southCell);
            }
        }

        // Pick a random neighbor to go
        currentRandom = rand() % neighbors.size();
        movingCell = neighbors[currentRandom];
        edge.setCoordinator2(movingCell);
        edges.push_back(edge);
    }
    return edges;
}