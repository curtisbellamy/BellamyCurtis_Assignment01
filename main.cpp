#include <iostream>
#include "matrix.hpp"
#include "GooglePageRank.hpp"
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {

    int input = 0;
    vector<int> input2;
    int index = 0;

    ifstream infile;
    infile.open("connectivity.txt");

    if(!(infile.is_open())){
        cerr << "Unable to open file." << endl;
        exit(1);
    } else {
        while(infile >> input){
            input2[index] = input;
            index++;

        }

    }

    for (int i = 0; i < input2.size(); ++i) {
        cout << input2[i] << " ";
    }



//    double arr[25] = {0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//
//    matrix test(arr, 25);
//
//    GooglePageRank pr(arr, 25);
//
//    matrix importance = pr.importanceMatrix(test);
//
//    matrix teleport = pr.teleportationMatrix(test);
//
//    matrix transition = pr.transitionMatrix(importance, teleport);
//
//    matrix markov = pr.markov(transition);
//
//    pr.print(markov);

    return 0;
}