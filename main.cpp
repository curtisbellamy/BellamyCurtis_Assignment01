#include <iostream>
#include "matrix.cpp"
#include <vector>


int main() {
//    vector<vector<double>> myVector;
//    myVector.resize(9, vector<double>(9));
//    for (int i = 0; i < myVector.size(); i++) {
//        for (int j = 0; j < myVector.size(); j++) {
//            myVector[i][j] = i;
//        }
//    }
//
//    for (int i = 0; i < myVector.size(); i++) {
//        for (int j = 0; j < myVector[i].size(); j++) {
//            cout << myVector[i][j] << " ";
//        }
//        cout << endl;
//    }




    comp3512::matrix test(-5, 5);
    test.print();
    return 0;
}