//
// Created by curti on 2019-01-29.
//

#include "matrix.hpp"
#include <iomanip>
#include <math.h>

using namespace comp3512;

matrix::matrix() {
    myVector.resize(1, vector<double>(1));
    myVector[0][0] = 0.0;
}

matrix::matrix(int n) {
    myVector.resize(n, vector<double>(n));
}

matrix::matrix(int r, int c) {
    try{
        if (r <= 0 || c <= 0){
            throw exception();
        }

    } catch (exception& e){
        cerr << "Exception occurred. Input numbers must be greater than zero." << endl;
    }
}

matrix::matrix(vector<vector<double>> vec) {
    unsigned long squareRoot = sqrt(vec.size());
    try{
        if (squareRoot - floor(squareRoot) != 0){
            throw exception();
        } else {

            myVector.resize(vec.size(), vector<double>(vec.size()));
            for (int i = 0; i < vec.size(); i++) {
                for (int j = 0; j < vec[i].size(); j++) {
                    myVector[i][j] = vec[i][j];
                }
            }
        }

    } catch (exception e){
        cerr << "Error occurred. Vector size must be a perfect square." << endl;
    }
}

void matrix::print() {
    for (int i = 0; i < myVector.size(); i++) {
        for (int j = 0; j < myVector[i].size(); j++) {
//            cout << showpoint << setprecision(2) <<  myVector[i][j] << " ";
            cout << myVector[i][j] << " ";
        }
        cout << endl;
    }
}
