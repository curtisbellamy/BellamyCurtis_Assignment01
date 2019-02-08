//
// Created by curti on 2019-02-06.
//

#ifndef BELLAMYCURTIS_ASSIGNMENT01_GOOGLEPAGERANK_HPP
#define BELLAMYCURTIS_ASSIGNMENT01_GOOGLEPAGERANK_HPP

#include "matrix.hpp"

using namespace std;

class GooglePageRank : public matrix{

    using matrix::matrix;

    double p{0.85};
    vector<vector<double>> Q; //teleporation matrix
    vector<vector<double>> S; //importance matrix
    vector<vector<double>> M; //transition matrix

public:

    matrix importanceMatrix(matrix m);

    double getSumCol(int x, matrix m);

    matrix teleportationMatrix(matrix m);

    matrix transitionMatrix(matrix m1, matrix m2);

    matrix markov(matrix m);

    void print(matrix m);


};


#endif //BELLAMYCURTIS_ASSIGNMENT01_GOOGLEPAGERANK_HPP
