//
// Created by curti on 2019-01-29.
//

#ifndef BELLAMYCURTIS_ASSIGNMENT01_MATRIX_HPP
#define BELLAMYCURTIS_ASSIGNMENT01_MATRIX_HPP
#include <vector>


namespace comp3512 {
    using namespace std;

    class matrix {
        vector<vector<double>> myVector;
    public:
        matrix();

        matrix(int n);

        matrix(int r, int c);

        matrix(vector<vector<double>> vec);

        void print();

    };
}


#endif //BELLAMYCURTIS_ASSIGNMENT01_MATRIX_HPP
