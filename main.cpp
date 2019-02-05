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
    myVector2.resize(10, vector<double>(9));
    for (int i = 0; i < myVector2.size(); i++) {
        double k = 0.0;
        for (int j = 0; j < myVector2[i].size(); j++) {
            myVector2[i][j] = k;
            k++;
        }
    }
    matrix test(5, 6);

    cout << test;




    return 0;
}