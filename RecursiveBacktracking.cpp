//
// Created by Mai Pham Quang Huy on 2019-05-09.
//
// https://weblog.jamisbuck.org/2010/12/27/maze-generation-recursive-backtracking

#include "RecursiveBacktracking.h"
#include <stack>

vector<Edge> RecursiveBacktracking::generate() {
    long seed = getSeed();
    int height = getHeight();
    int width = getWidth();
    bool withSeed = isWithSeed();
    // Keep track visited cells
    bool visitedCells[height][width];
    for (int m = 0; m < height; ++m) {
        for (int i = 0; i < width; ++i) {
            visitedCells[m][i] = false;
        }
    }

    // Create vector to store edges
    vector<Edge> edges;
    stack<Coordinator> visitedCoordinators;
    // check input seed
    if (!withSeed) {
        seed = time(0);
    }
    srand((int) seed);

    // Pick a random cell to start
    Coordinator carvingCell;
    carvingCell.setX(rand() % height);
    carvingCell.setY(rand() % width);
    // Add it to visitedCells list
    visitedCells[carvingCell.getX()][carvingCell.getY()] = true;
    visitedCoordinators.push(carvingCell);

    while (!visitedCoordinators.empty()) {
        bool findingState = true;
        while (findingState) {
            vector<Coordinator> neighbors;

            // Finding 4 directions of cell which directing available to move
            // North
            if (carvingCell.getX() - 1 > -1) {
                if (!visitedCells[carvingCell.getX() - 1][carvingCell.getY()]) {
                    Coordinator northCell;
                    northCell.setX(carvingCell.getX() - 1);
                    northCell.setY(carvingCell.getY());
                    neighbors.push_back(northCell);
                }
            }

            // East
            if (carvingCell.getY() + 1 < width) {
                if (!visitedCells[carvingCell.getX()][carvingCell.getY() + 1]) {
                    Coordinator eastCell;
                    eastCell.setX(carvingCell.getX());
                    eastCell.setY(carvingCell.getY() + 1);
                    neighbors.push_back(eastCell);
                }
            }

            // West
            if (carvingCell.getY() - 1 > -1) {
                if (!visitedCells[carvingCell.getX()][carvingCell.getY() - 1]) {
                    Coordinator westCell;
                    westCell.setX(carvingCell.getX());
                    westCell.setY(carvingCell.getY() - 1);
                    neighbors.push_back(westCell);
                }
            }

            // South
            if (carvingCell.getX() + 1 < height) {
                if (!visitedCells[carvingCell.getX() + 1][carvingCell.getY()]) {
                    Coordinator southCell;
                    southCell.setX(carvingCell.getX() + 1);
                    southCell.setY(carvingCell.getY());
                    neighbors.push_back(southCell);
                }
            }

            // Pick a random neighbor to go
            if (!neighbors.empty()) {
                Edge edge;
                edge.setCoordinator1(carvingCell);
                int currentRandom = rand() % neighbors.size();
                carvingCell = neighbors[currentRandom];
                edge.setCoordinator2(carvingCell);
                edges.push_back(edge);
                visitedCells[carvingCell.getX()][carvingCell.getY()] = true;
                visitedCoordinators.push(carvingCell);
            } else {
                visitedCoordinators.pop();
                if (!visitedCoordinators.empty()) {
                    carvingCell = visitedCoordinators.top();
                }
                findingState = false;
            }
        }
    }
    return edges;
}
