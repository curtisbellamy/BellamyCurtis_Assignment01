//
// Created by curti on 2019-01-29.
//

#ifndef BELLAMYCURTIS_ASSIGNMENT01_MATRIX_HPP
#define BELLAMYCURTIS_ASSIGNMENT01_MATRIX_HPP
#include <vector>
#include <iostream>



using namespace std;

class matrix {
    vector<vector<double>> myVector;
    static constexpr double TOLERANCE = 0.1;


public:
    matrix();

    matrix(int n);

    matrix(int r, int c);

    matrix(double arr[], int arraySize);

    void print() const;

    void set_value(int r, int c, double val);

    double get_value(int r, int c) const;

    void clear();

    ~matrix();

    friend ostream &operator<<(ostream &os, const matrix &obj);

    friend bool operator== (const matrix& lhs, const matrix& rhs);

    friend bool operator!= (const matrix& lhs, const matrix& rhs);

    //prefix
    matrix& operator++ ();

    //postfix
    matrix operator++ (int x);

    matrix& operator=(matrix rhs);

    friend void mySwap(matrix& first, matrix& second);

    friend matrix operator+(matrix lhs, const matrix& rhs);

    friend matrix operator-(matrix lhs, const matrix& rhs);

    matrix& operator+=(const matrix& rhs);

    matrix& operator-=(const matrix& rhs);

    friend matrix operator*(matrix lhs, const matrix& rhs);

    matrix& operator*=(const matrix& rhs);


};



#endif //BELLAMYCURTIS_ASSIGNMENT01_MATRIX_HPP
