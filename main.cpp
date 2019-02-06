#include <iostream>
#include "matrix.hpp"
#include <vector>

using namespace std;

int main() {

    double arr[9] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    double arr3[9] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};

    double arr2[4] = {3.0, 4.0};

    matrix test(arr, 9);
    matrix test2(arr2, 4);
    matrix test3(arr3, 9);

    matrix test4(3, 6);

    cout << test << endl;

    //test * test4;
    //cout << test;

    cout << test * test4;


    return 0;
}