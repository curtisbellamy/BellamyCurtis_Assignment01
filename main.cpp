#include <iostream>
#include "matrix.hpp"
#include <vector>

using namespace std;

int main() {
    vector<vector<double>> myVector;
    myVector.resize(9, vector<double>(9));
    for (int i = 0; i < myVector.size(); i++) {
        double k = 0.0;
        for (int j = 0; j < myVector[i].size(); j++) {
            myVector[i][j] = k;
            k++;
        }
    }

    vector<vector<double>> myVector2;
    myVector2.resize(9, vector<double>(9));
    for (int i = 0; i < myVector2.size(); i++) {
        double k = 0.1;
        for (int j = 0; j < myVector2[i].size(); j++) {
            myVector2[i][j] = k;
            k++;
        }
    }

    vector<vector<double>> myVector3;
    myVector3.resize(16, vector<double>(16));
    for (int i = 0; i < myVector3.size(); i++) {
        double k = 0.0;
        for (int j = 0; j < myVector3[i].size(); j++) {
            myVector3[i][j] = k;
            k++;
        }
    }

    vector<vector<double>> myVector4;
    myVector4.resize(9, vector<double>(9));
    for (int i = 0; i < myVector4.size(); i++) {
        double k = 0.1;
        for (int j = 0; j < myVector4[i].size(); j++) {
            myVector4[i][j] = k;
            k++;
        }
    }

    matrix test(myVector);
    matrix test2(myVector2);
    matrix test3(myVector3);
    matrix test4(myVector4);

    if(test == test2)
        cout << "Matrices (1 & 2) are the same dawg" << endl;

    if(test != test2)
        cout << "Matrices (1 & 2) aint the same dawg" << endl;

    if(test3 == test4)
        cout << "Matrices (3 & 4) are the same dawg" << endl;

    if(test3 != test4)
        cout << "Matrices (3 & 4) aint the same dawg" << endl;



    return 0;
}