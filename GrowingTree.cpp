//
// Created by Mai Pham Quang Huy on 2019-05-08.
//
// https://weblog.jamisbuck.org/2011/1/27/maze-generation-growing-tree-algorithm

#include "GrowingTree.h"

vector<Edge> GrowingTree::generate() {
    long seed = getSeed();
    int height = getHeight();
    int width = getWidth();
    bool withSeed = isWithSeed();
    // Kepp track visited cells
    bool visitedCells[height][width];
    for (int m = 0; m < height; ++m) {
        for (int i = 0; i < width; ++i) {
            visitedCells[m][i] = false;

        }
    }

    // Create vector to store edges
    vector<Edge> edges;
    //Create vectore to store visited coordinators
    vector<Coordinator> visitedCoordinators;
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
    visitedCoordinators.push_back(movingCell);

    while (!visitedCoordinators.empty()) {
        vector<Coordinator> neighbors;

        // Finding 4 directions of cell which direction is available to move
        // North
        if (movingCell.getX() - 1 > -1) {
            if (!visitedCells[movingCell.getX() - 1][movingCell.getY()]) {
                Coordinator northCell;
                northCell.setX(movingCell.getX() - 1);
                northCell.setY(movingCell.getY());
                neighbors.push_back(northCell);
            }
        }

        // East
        if (movingCell.getY() + 1 < width) {
            if (!visitedCells[movingCell.getX()][movingCell.getY() + 1]) {
                Coordinator eastCell;
                eastCell.setX(movingCell.getX());
                eastCell.setY(movingCell.getY() + 1);
                neighbors.push_back(eastCell);
            }
        }

        // West
        if (movingCell.getY() - 1 > -1) {
            if (!visitedCells[movingCell.getX()][movingCell.getY() - 1]) {
                Coordinator westCell;
                westCell.setX(movingCell.getX());
                westCell.setY(movingCell.getY() - 1);
                neighbors.push_back(westCell);
            }
        }

        // South
        if (movingCell.getX() + 1 < height) {
            if (!visitedCells[movingCell.getX() + 1][movingCell.getY()]) {
                Coordinator southCell;
                southCell.setX(movingCell.getX() + 1);
                southCell.setY(movingCell.getY());
                neighbors.push_back(southCell);
            }
        }

        // Pick a random neighbor to go
        if (!neighbors.empty()) {
            Edge edge;
            edge.setCoordinator1(movingCell);
            int currentRandom = rand() % neighbors.size();
            movingCell = neighbors[currentRandom];
            edge.setCoordinator2(movingCell);
            edges.push_back(edge);
            visitedCells[movingCell.getX()][movingCell.getY()] = true;
            visitedCoordinators.push_back(movingCell);
            currentRandom = rand() % visitedCoordinators.size();
            movingCell = visitedCoordinators[currentRandom];
        } else { // Trace back to find a cell that have available neighbor to go
            visitedCoordinators.erase(remove_if(
                    visitedCoordinators.begin(),
                    visitedCoordinators.end(),
                    [&movingCell](const Coordinator& coordinator) {
                        return coordinator.getX() == movingCell.getX() &&
                        coordinator.getY() == movingCell.getY();
                    }), visitedCoordinators.end());
            if (!visitedCoordinators.empty()) {
                int currentRandom = rand() % visitedCoordinators.size();
                movingCell = visitedCoordinators[currentRandom];
            }
        }
    }
    return edges;
}
