//
// Created by curti on 2019-01-29.
//

#include "matrix.hpp"

matrix::matrix() {
    matrix::myVector = {{0.0}, {0.0}};
}

matrix::matrix(int n) {
    matrix::myVector.resize(n, vector<int>(n));
    //int n = number of rows, m = number of columns;
    //myVector.resize(n, vector<int>(m));
}