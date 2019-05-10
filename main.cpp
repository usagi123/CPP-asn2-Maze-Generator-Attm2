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

const string PRIM = "--gp";
const string GROWING_TREE = "--gg";
const string RECURSIVE = "--gr";
const string SAVE_BINARY = "--sb";
const string SAVE_SVG = "--sv";
const string EXPORT_SVG = "Exporting SVG";
const string EXPORT_BINARY = "Exporting Binary";
unsigned seed;
unsigned width;
unsigned height;

string checkFileSavingFlag(string input);
string checkFileName(string input);
string checkAlgorithmFlag(string input);
string checkBinarySavingFlag(string input);
string checkSvgSavingFlag(string input);
string checkBinaryFileType(string input);
string checkSvgFileType(string input);
void saveSvg(string fileName, const vector<Edge>& vector, int width, int height);
void saveBinary(string fileName, const vector<Edge>& vector, int width, int height);

int main(int argc, char* argv[]) {
    try {
        int i = 1;
        string algorithm = checkAlgorithmFlag(argv[i]);
        if (argc == 7 ){
            try {
                i++;
                seed = (int) stol(argv [i]);
            } catch (const invalid_argument) {
                cout << "Invalid seed" <<endl;
                return 1;
            }
            try {
                i++;
                width = (int) stol(argv [i]);
                i++;
                height = (int) stol(argv [i]);
                i++;
            } catch (const invalid_argument) {
                cout << "Invalid width and height" <<endl;
            }
            string fileName = checkFileName(argv[i+1]);
            if (algorithm == GROWING_TREE) {
                vector<Edge> edgesVector;
                GrowingTree growingTree;
                Maze *maze = &growingTree;
                maze->setWithSeed(true);
                maze->setSeed(seed);
                maze->setWidth(width);
                maze->setHeight(height);
                cout << "Generating maze with Growing Tree algorithm" << endl;
                auto begin = high_resolution_clock::now();
                edgesVector = growingTree.generate();
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(end - begin);
                cout << "Total time to generate " << to_string(duration.count()) << " milliseconds" << endl;

                if (checkFileSavingFlag(argv[i]) == SAVE_SVG) {
                    cout << EXPORT_SVG << endl;
                    auto begin = high_resolution_clock::now();
                    saveSvg(fileName, edgesVector, width, height);
                    auto end = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(end - begin);
                    cout << "Total time to export " << to_string(duration.count()) << " milliseconds" << endl;
                } else {
                    cout << EXPORT_BINARY << endl;
                    auto begin = high_resolution_clock::now();
                    saveBinary(fileName, edgesVector, width, height);
                    auto end = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(end - begin);
                    cout << "Total time to export " << to_string(duration.count()) << " milliseconds" << endl;
                }
            } else if (algorithm == RECURSIVE) {
                vector<Edge> edgesVector;
                RecursiveBacktracking recursiveBacktracking;
                Maze *maze = &recursiveBacktracking;
                maze->setWithSeed(true);
                maze->setSeed(seed);
                maze->setWidth(width);
                maze->setHeight(height);
                cout << "Generating maze with Recursive Backtracking algorithm" << endl;
                auto begin = high_resolution_clock::now();
                edgesVector = recursiveBacktracking.generate();
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(end - begin);
                cout << "Total time to generate " << to_string(duration.count()) << " milliseconds" << endl;

                if (checkFileSavingFlag(argv[i]) == SAVE_SVG) {
                    cout << EXPORT_SVG << endl;
                    auto begin = high_resolution_clock::now();
                    saveSvg(fileName, edgesVector, width, height);
                    auto end = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(end - begin);
                    cout << "Total time to export " << to_string(duration.count()) << " milliseconds" << endl;
                } else {
                    cout << EXPORT_BINARY << endl;
                    auto begin = high_resolution_clock::now();
                    saveBinary(fileName, edgesVector, width, height);
                    auto end = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(end - begin);
                    cout << "Total time to export " << to_string(duration.count()) << " milliseconds" << endl;
                }
            } else if (algorithm == PRIM){
                vector<Edge> edgesVector;
                Prim prim;
                Maze *maze = &prim;
                maze->setWithSeed(true);
                maze->setSeed(seed);
                maze->setWidth(width);
                maze->setHeight(height);
                cout << "Generating maze with Prim's algorithm" << endl;
                auto begin = high_resolution_clock::now();
                edgesVector = prim.generate();
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(end - begin);
                cout << "Total time to generate " << to_string(duration.count()) << " milliseconds" << endl;

                if (checkFileSavingFlag(argv[i]) == SAVE_SVG) {
                    cout << EXPORT_SVG << endl;
                    auto begin = high_resolution_clock::now();
                    saveSvg(fileName, edgesVector, width, height);
                    auto end = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(end - begin);
                    cout << "Total time to export " << to_string(duration.count()) << " milliseconds" << endl;
                } else {
                    cout << EXPORT_BINARY << endl;
                    auto begin = high_resolution_clock::now();
                    saveBinary(fileName, edgesVector, width, height);
                    auto end = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(end - begin);
                    cout << "Total time to export " << to_string(duration.count()) << " milliseconds" << endl;
                }
            }
        } else if(argc == 6) {
            try {
                i++;
                width = (int) stol(argv [i]);
                i++;
                height = (int) stol(argv [i]);
                i++;
            } catch (const invalid_argument) {
                cout << "Invalid width and height" <<endl;
            }
            string fileName = checkFileName(argv[i+1]);
            if (algorithm == GROWING_TREE) {
                vector<Edge> edgesVector;
                GrowingTree growingTree;
                Maze *maze = &growingTree;
                maze->setWithSeed(true);
                maze->setSeed(seed);
                maze->setWidth(width);
                maze->setHeight(height);
                cout << "Generating maze with Growing Tree algorithm" << endl;
                auto begin = high_resolution_clock::now();
                edgesVector = growingTree.generate();
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(end - begin);
                cout << "Total time to generate " << to_string(duration.count()) << " milliseconds" << endl;

                if (checkFileSavingFlag(argv[i]) == SAVE_SVG) {
                    cout << EXPORT_SVG << endl;
                    auto begin = high_resolution_clock::now();
                    saveSvg(fileName, edgesVector, width, height);
                    auto end = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(end - begin);
                    cout << "Total time to export " << to_string(duration.count()) << " milliseconds" << endl;
                } else {
                    cout << EXPORT_BINARY << endl;
                    auto begin = high_resolution_clock::now();
                    saveBinary(fileName, edgesVector, width, height);
                    auto end = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(end - begin);
                    cout << "Total time to export " << to_string(duration.count()) << " milliseconds" << endl;
                }
            } else if (algorithm == RECURSIVE) {
                vector<Edge> edgesVector;
                RecursiveBacktracking recursiveBacktracking;
                Maze *maze = &recursiveBacktracking;
                maze->setWithSeed(true);
                maze->setSeed(seed);
                maze->setWidth(width);
                maze->setHeight(height);
                cout << "Generating maze with Recursive Backtracking algorithm" << endl;
                auto begin = high_resolution_clock::now();
                edgesVector = recursiveBacktracking.generate();
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(end - begin);
                cout << "Total time to generate " << to_string(duration.count()) << " milliseconds" << endl;

                if (checkFileSavingFlag(argv[i]) == SAVE_SVG) {
                    cout << EXPORT_SVG << endl;
                    auto begin = high_resolution_clock::now();
                    saveSvg(fileName, edgesVector, width, height);
                    auto end = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(end - begin);
                    cout << "Total time to export " << to_string(duration.count()) << " milliseconds" << endl;
                } else {
                    cout << EXPORT_BINARY << endl;
                    auto begin = high_resolution_clock::now();
                    saveBinary(fileName, edgesVector, width, height);
                    auto end = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(end - begin);
                    cout << "Total time to export " << to_string(duration.count()) << " milliseconds" << endl;
                }
            } else if (algorithm == PRIM) {
                vector<Edge> edgesVector;
                Prim prim;
                Maze *maze = &prim;
                maze->setWithSeed(true);
                maze->setSeed(seed);
                maze->setWidth(width);
                maze->setHeight(height);
                cout << "Generating maze with Prim's algorithm" << endl;
                auto begin = high_resolution_clock::now();
                edgesVector = prim.generate();
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(end - begin);
                cout << "Total time to generate " << to_string(duration.count()) << " milliseconds" << endl;

                if (checkFileSavingFlag(argv[i]) == SAVE_SVG) {
                    cout << EXPORT_SVG << endl;
                    auto begin = high_resolution_clock::now();
                    saveSvg(fileName, edgesVector, width, height);
                    auto end = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(end - begin);
                    cout << "Total time to export " << to_string(duration.count()) << " milliseconds" << endl;
                } else {
                    cout << EXPORT_BINARY << endl;
                    auto begin = high_resolution_clock::now();
                    saveBinary(fileName, edgesVector, width, height);
                    auto end = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(end - begin);
                    cout << "Total time to export " << to_string(duration.count()) << " milliseconds" << endl;
                }
            }
        } else {
            throw "Invalid argument";
        }

    } catch (const char* msg) {
        cout << msg << endl;
        cout << "Wrong param" << endl;
    }
    return 0;
}

string checkFileSavingFlag(string input) {
    if (input == SAVE_SVG || input == SAVE_BINARY) {
        return input;
    }
    else {
        throw "Saving argument must be: --sv or --sb";
    }
}

string checkFileName(string input) {
    string fileType = input.substr(input.find_last_of(".") + 1);
    if ( fileType == "svg" || fileType == "bin") {
        return input;
    } else {
        throw "Invalid file type. File type must be .svg or .bin";
    }
}

string checkAlgorithmFlag(string input) {
    if (input == "--gg" || input == "--gp" || input == "--gr") {
        return input;
    } else if (input == "help") {
        cout << "--gg: Growing tree algorithm with custom seed \n"
                "-gg: Growing tree algorithm with ramdom seed \n"
                "--gr: Recursive backtracking algorithm with custom seed \n"
                "-gr: Recursive backtracking algorithm with random seed \n"
                "--gp: Prim's algorithm with custom seed \n"
                "-gp: Prim's algorithm with random seed \n"
                "--sv: Export maze to SVG \n"
                "--sb: Export maze to binary \n"
                "Param: ./mazer -algorithm flag -export file type \n"
                "Example: ./mazer --gg 123 1000 1000 --sv mygrowingtreemaze.svg";
    } else {
        throw "Must be --gg or --gp or --gr.";
    }
}

string checkBinarySavingFlag(string input) {
    if (input == "--sb") {
        return input;
    } else {
        throw "Invalid arguments for --sb";
    }
}

string checkSvgSavingFlag(string input) {
    if (input == "--sv") {
        return input;
    } else {
        throw "Invalid arguments for --sv";
    }
}

string checkBinaryFileType(string input) {
    string fileType = input.substr(input.find_last_of(".") + 1);
    if (fileType == "bin") {
        return input;
    } else {
        throw "Invalid file type. File type must be .bin";
    }
}

string checkSvgFileType(string input) {
    string fileType = input.substr(input.find_last_of(".") + 1);
    if ( fileType == "svg") {
        return input;
    } else {
        throw "Invalid fileType. FileType must be .svg";
    }
}

void saveSvg(string fileName, const vector<Edge>& vector, int width, int height) {
    ofstream svg(fileName, ofstream::out);
    svg << "<svg" << " viewBox=" << "\"0 0 " << width << " " << height << "\""<< " width" << "=" << "\"" << width*10
        << "\"" << " height=\"" << height*10 << "\"" << " xmlns=" << "\"http://www.w3.org/2000/svg\">" << endl;
    svg << "<rect width =" << "\'" << width << "\' " << "height=\'" << height << "\' " << "style=\'"
        << "fill: black\' " << "/>" << endl;
    for (auto & edge : vector) {
        int x1 =  edge.getCoordinator1().getX();
        int y1 =  edge.getCoordinator1().getY();
        int x2 =  edge.getCoordinator2().getX();
        int y2 =  edge.getCoordinator2().getY();
        svg << "<line stroke=\'" << "white\' " << "stroke-width=\'" << "0.05\'" << " x1=\'" << x1 << "\' y1=\'" << y1
            << "\' x2=\'" << x2 << "\' y2=\'" << y2 << "\'/>" << endl;
    }
    svg << "</svg>";
    svg.close();
}

void saveBinary(string fileName, const vector<Edge>& vector, int width, int height) {
    fstream binary(fileName, ios::binary | ios::in | ios::out | ios::trunc);
    if (!binary.is_open()) {
        cout << "Cannot open the binary file" << endl;
    } else {
        binary.write((char *) &width, sizeof(width));
        binary.write((char *) &height, sizeof(height));
        long numberOfEdges = vector.size();
        binary.write((char *) &numberOfEdges, sizeof(width));

        for (auto & edge : vector) {
            int x1 =  edge.getCoordinator1().getX();
            int y1 =  edge.getCoordinator1().getY();
            int x2 =  edge.getCoordinator2().getX();
            int y2 =  edge.getCoordinator2().getY();
            binary.write((char *) &x1, sizeof(x1));
            binary.write((char *) &y1, sizeof(y1));
            binary.write((char *) &x2, sizeof(x2));
            binary.write((char *) &y2, sizeof(y2));
        }

        binary.seekg(0);
        binary.close();
    }
}