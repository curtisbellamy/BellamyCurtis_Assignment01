#include <iostream>
#include "matrix.hpp"
#include "GooglePageRank.hpp"
#include <vector>
#include <iomanip>

using namespace std;

int main() {

    double arr[25] = {0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    matrix test(arr, 25);

    GooglePageRank pr(arr, 25);

    matrix importance = pr.importanceMatrix(test);

    matrix teleport = pr.teleportationMatrix(test);

    matrix transition = pr.transitionMatrix(importance, teleport);

    matrix markov = pr.markov(transition);

    pr.print(markov);

    return 0;
}