//
// Created by curti on 2019-01-29.
//

#include "matrix.hpp"
#include <iomanip>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>



matrix::matrix() {
    myVector.resize(1, vector<double>(1));
}


matrix::matrix(int n) {
    try{
        if(n <= 0)
            throw exception();
    }catch (exception e){
        cerr << "Error occurred. Integer must be positive and greater than zero." << endl;
        exit(1);
    }
    myVector.resize(n, vector<double>(n));

}


matrix::matrix(int r, int c) {
    try {
        if (r <= 0 || c <= 0) {
            throw exception();
        }

        myVector.resize(r, vector<double>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                myVector[i][j] = 0.0;
            }
        }

    } catch (exception &e) {
        cerr << "Exception occurred. Input numbers must be greater than zero." << endl;
        exit(1);
    }
}


matrix::matrix(double arr[], int arraySize) {
    double squareRoot = sqrt(arraySize);
    try {
        if (squareRoot - floor(squareRoot) != 0) {
            throw exception();
        } else {

            myVector.resize(squareRoot, vector<double>(squareRoot));
            for(int i = 0; i < arraySize; i++) {
                myVector[i / squareRoot][i % (int) squareRoot] = arr[i];
            }
        }

    } catch (exception e) {
        cerr << "Error occurred. Vector size must be a perfect square." << endl;
        exit(1);
    }
}

//Ask jeff what integers too large means
void matrix::set_value(int r, int c, double val) {
    try{
        if(r < 0 || r > myVector.size())
            throw exception();
        else if(c < 0 || c > myVector[0].size())
            throw exception();
        else
            myVector[r][c] = val;
    } catch (exception e){
        cerr << "Error occurred. Array indexes do not exist." << endl;
        exit(1);
    }
}


//Ask jeff what integers too large means
double matrix::get_value(int r, int c) const {
    try{
        if(r < 0 || r > myVector.size())
            throw exception();
        else if(c < 0 || c > myVector[0].size())
            throw exception();
        else
            return myVector[r][c];
    } catch (exception e){
        cerr << "Error occurred. Array indexes do not exist." << endl;
        exit(1);
    }
}

void matrix::clear() {
    for (int i = 0; i < myVector.size(); ++i) {
        for (int j = 0; j < myVector[i].size(); ++j) {
            myVector[i][j] = 0.0;
        }
    }
}


matrix::~matrix() {
    // because not using new keyword, gets de alloocated on stack
}


ostream &operator<<(std::ostream &os, const matrix& obj) {
    for (int i = 0; i < obj.myVector.size(); i++) {
        for (int j = 0; j < obj.myVector[i].size(); j++) {
//            cout << showpoint << setprecision(2) <<  myVector[i][j] << " ";
            os << obj.myVector[i][j] << " ";
        }
        os << endl;
    }
    return os;
}


bool operator== (const matrix& lhs, const matrix& rhs){
    if (lhs.myVector.size() != rhs.myVector.size())
        return false;
    else {
        for (int i = 0; i < lhs.myVector.size(); i++) {
            for (int j = 0; j < lhs.myVector[i].size(); j++) {
                //if((std::max(lhs.get_value(i, j), rhs.get_value(i, j)) - std::min(lhs.get_value(i, j), rhs.get_value(i, j))) > matrix::TOLERANCE){
                if(abs(lhs.get_value(i, j) - rhs.get_value(i, j) > matrix::TOLERANCE)){
                    return false;
                }
            }
        }
    }
    return true;

}

bool operator!= (const matrix& lhs, const matrix& rhs){
    if (lhs.myVector.size() != rhs.myVector.size())
        return true;
    else {
        for (int i = 0; i < lhs.myVector.size(); i++) {
            for (int j = 0; j < lhs.myVector[i].size(); j++) {
//                if (lhs.get_value(i, j) != rhs.get_value(i, j)) {
                if((std::max(lhs.get_value(i, j), rhs.get_value(i, j)) - std::min(lhs.get_value(i, j), rhs.get_value(i, j))) > matrix::TOLERANCE){
                    return true;
                }
            }
        }
    }
    return false;

}

//prefix
matrix& matrix::operator++() {
    for (int i = 0; i < myVector.size(); ++i) {
        for (int j = 0; j < myVector[i].size(); ++j) {
            myVector[i][j] += 1.0;
        }
    }
    return *this;
}

//postfix
matrix matrix::operator++(int x) {
    matrix temp(*this);
    operator++();
    return temp;
}

matrix& matrix::operator=(matrix rhs) {
    mySwap(*this, rhs);
    return *this;
}

void mySwap(matrix &first, matrix &second) {
    using std::swap;
    swap(first.myVector, second.myVector);
}

matrix& matrix::operator+=(const matrix& rhs) {
    try{
        if (rhs.myVector.size() != myVector.size() || rhs.myVector[0].size() != myVector[0].size())
            throw exception();
        else {
            for (int i = 0; i < myVector.size(); ++i) {
                for (int j = 0; j < myVector[i].size(); ++j) {
                    myVector[i][j] += rhs.myVector[i][j];
                }
            }
            return *this;
        }
    } catch (exception e){
        cerr << "Error occurred. Vectors must be the same size." << endl;
        exit(1);
    }
}

matrix& matrix::operator-=(const matrix &rhs) {
    try{
        if (rhs.myVector.size() != myVector.size() || rhs.myVector[0].size() != myVector[0].size())
            throw exception();
        else {
            for (int i = 0; i < myVector.size(); ++i) {
                for (int j = 0; j < myVector[i].size(); ++j) {
                    myVector[i][j] -= rhs.myVector[i][j];
                }
            }
            return *this;
        }
    } catch (exception e){
        cerr << "Error occurred. Vectors must be the same size." << endl;
        exit(1);
    }
}

matrix operator+(matrix lhs, const matrix &rhs) {
    try{
        if (lhs.myVector.size() != rhs.myVector.size() || lhs.myVector[0].size() != rhs.myVector[0].size())
            throw exception();
        else {
            for (int i = 0; i < lhs.myVector.size(); ++i) {
                for (int j = 0; j < lhs.myVector[i].size(); ++j) {
                    lhs.myVector[i][j] += rhs.myVector[i][j];
                }
            }
            return lhs;
        }
    } catch (exception e){
        cerr << "Error occurred. Vectors must be the same size." << endl;
        exit(1);
    }
}

matrix operator-(matrix lhs, const matrix &rhs) {
    try{
        if (lhs.myVector.size() != rhs.myVector.size() || lhs.myVector[0].size() != rhs.myVector[0].size())
            throw exception();
        else {
            for (int i = 0; i < lhs.myVector.size(); ++i) {
                for (int j = 0; j < lhs.myVector[i].size(); ++j) {
                    lhs.myVector[i][j] -= rhs.myVector[i][j];
                }
            }
            return lhs;
        }
    } catch (exception e){
        cerr << "Error occurred. Vectors must be the same size." << endl;
        exit(1);
    }
}

matrix operator*(matrix lhs, const matrix &rhs) {
    try{
        if(lhs.myVector[0].size() != rhs.myVector.size())
            throw exception();
        else{
            vector<vector<double>> temp;
            temp.resize(lhs.myVector.size(), vector<double>(rhs.myVector[0].size()));
            for(int i = 0; i < lhs.myVector.size(); ++i) {
                for (int j = 0; j < rhs.myVector[0].size(); ++j) {
                    for (int k = 0; k < lhs.myVector[0].size(); ++k) {
                        temp[i][j] = lhs.myVector[i][k] * rhs.myVector[k][j];
                    }
                }
            }
            lhs.myVector = temp;
            return lhs;

        }

    } catch (exception e){
        cerr << "Error occurred. In order to multiply, the number of columns "
                "in the first matrix must be equal to the number of rows in the second matrix.";
        exit(1);
    }
}

matrix& matrix::operator*=(const matrix &rhs) {
    try{
        if(myVector[0].size() != rhs.myVector.size())
            throw exception();
        else{
            vector<vector<double>> temp;
            temp.resize(myVector.size(), vector<double>(rhs.myVector[0].size()));
            for(int i = 0; i < myVector.size(); ++i) {
                for (int j = 0; j < rhs.myVector[0].size(); ++j) {
                    for (int k = 0; k < myVector[0].size(); ++k) {
                        temp[i][j] = myVector[i][k] * rhs.myVector[k][j];
                    }
                }
            }
            myVector = temp;
            return *this;

        }

    } catch (exception e){
        cerr << "Error occurred. In order to multiply, the number of columns "
                "in the first matrix must be equal to the number of rows in the second matrix.";
        exit(1);
    }
}


