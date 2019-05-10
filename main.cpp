#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include "Coordinator.h"
#include "Edge.h"
#include "Maze.h"
#include "GrowingTree.h"
#include "RecursiveBacktracking.h"
#include "Prim.h"

using namespace chrono;

void saveSvg(string fileName, const vector<Edge>& vector, int width, int height);
void drawThatSVGMazeForMe(string fileName, const vector<Edge>& mazeVector, int width, int height); //Draw maze details into SVG files
void yourMazeDetailsInBinary(string fileName, int seed, int width, int height); //Export maze details into binary file

int main() {
    vector<Edge> edgesVector;

//    GrowingTree growingTree;
//    Maze *maze1 = &growingTree;
//    maze1->setWithSeed(true);
//    maze1->setSeed(3);
//    maze1->setWidth(100);
//    maze1->setHeight(100);
//
//    edgesVector = growingTree.generate();
//
//    saveSvg("growingTree.svg", edgesVector, 10, 10);

//    RecursiveBacktracking recursiveBacktracking;
//    Maze *maze1 = &recursiveBacktracking;
//    maze1->setWithSeed(true);
//    maze1->setSeed(3);
//    maze1->setWidth(100);
//    maze1->setHeight(100);
//
//    edgesVector = recursiveBacktracking.generate();
//
//    saveSvg("recursiveBacktracking.svg", edgesVector, 100, 100);

//    Prim prim;
//    Maze *maze1 = &prim;
//    maze1->setWithSeed(true);
//    maze1->setSeed(3);
//    maze1->setWidth(100);
//    maze1->setHeight(100);
//
//    auto start = high_resolution_clock::now();
//    edgesVector = prim.generate();
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(stop-start);
//    cout << duration.count() << endl;
//
//    saveSvg("prim.svg", edgesVector, 100, 100);
    return 0;
}

void saveSvg(string fileName, const vector<Edge>& vector, int width, int height) {
    ofstream svg(fileName, ofstream::out);
    svg << "<svg" << " viewBox=" << "\"0 0 " << width << " " << height << "\""<< " width" << "=" << "\"" << width*10
        << "\"" << " height=\"" << height*10 << "\"" << " xmlns=" << "\"http://www.w3.org/2000/svg\">" << endl;
    svg << "<rect width =" << "\'" << width << "\' " << "height=\'" << height << "\' " << "style=\'"
        << "fill: white\' " << "/>" << endl;
    for (auto & edge : vector) {
        int x1 =  edge.getCoordinator1().getX();
        int y1 =  edge.getCoordinator1().getY();
        int x2 =  edge.getCoordinator2().getX();
        int y2 =  edge.getCoordinator2().getY();
        svg << "<line stroke=\'" << "black\' " << "stroke-width=\'" << "0.5\'" << " x1=\'" << x1 << "\' y1=\'" << y1
            << "\' x2=\'" << x2 << "\' y2=\'" << y2 << "\'/>" << endl;
    }
    svg << "</svg>";
    svg.close();
}