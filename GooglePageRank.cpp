//
// Created by curti on 2019-02-06.
//

#include "GooglePageRank.hpp"
#include <cmath>
#include <array>
#include <iomanip>


double GooglePageRank::getSumCol(int x, matrix m){
    double sum = 0;
    for (int j = 0; j < m.getCol(); j++) {
        sum += m.get_value(x, j);
    }
    return sum;
}

matrix GooglePageRank::importanceMatrix(matrix m) {
    double sum = 0;
    matrix temp(m.getRow(), m.getCol());
    for(int i = 0; i < m.getRow(); i++) {
        for (int j = 0; j < m.getCol(); j++) {
            sum = getSumCol(j, m);
            if (m.get_value(i, j) != 0) {
                temp.set_value(i, j, (m.get_value(i, j) / sum));
            }
            if( sum == 0){
                temp.set_value(i ,j, (1.0 / m.getCol()));
            }
        }
    }
    this->S = temp.getVector();
    return temp;
}

matrix GooglePageRank::teleportationMatrix(matrix m) {
    matrix temp(m.getRow(), m.getCol());
    double value = 1.0 / m.getVector().size();
    for (int i = 0; i < temp.getVector().size(); ++i) {
        for (int j = 0; j < temp.getVector()[i].size(); ++j) {
            temp.set_value(i, j, value);
        }

    }
    return temp;

}

matrix GooglePageRank::transitionMatrix(matrix m1, matrix m2) {
    double value = 1.0 - p;
    for (int i = 0; i < m1.getRow(); ++i) {
        for (int j = 0; j < m1.getCol(); ++j) {
            m1.set_value(i, j, (m1.get_value(i, j) * p));
        }
    }

    for (int k = 0; k < m2.getRow(); ++k) {
        for (int i = 0; i < m2.getCol(); ++i) {
            m2.set_value(k, i, (m2.get_value(k, i) * value));
        }
    }

    return m1 + m2;

}

matrix GooglePageRank::markov(matrix m) {
    matrix rank(m.getRow(), 1);
    for (int i = 0; i < rank.getRow(); ++i) {
        for (int j = 0; j < rank.getCol(); ++j) {
            rank.set_value(i, j, 1.0);
        }
    }
    rank = m * rank;
    for (int k = 0; k < 1000; ++k) {
        rank = m * rank;
    }

    long double sum = 0.0f;
    for (int l = 0; l < rank.getRow(); ++l) {
        for (int i = 0; i < rank.getCol(); ++i) {
            sum += rank.get_value(l, i);
        }
    }

    for (int n = 0; n < rank.getRow(); ++n) {
        for (int i = 0; i < rank.getCol(); ++i) {
            rank.set_value(n, i, (rank.get_value(n, i) / sum));
        }
    }
    return rank;
}

void GooglePageRank::print(matrix m) {
    char page = 'A';
    for (int i = 0; i < m.getRow(); ++i) {
        for (int j = 0; j < m.getCol(); ++j) {
            double percent = ((m.get_value(i, j) / 1) * 100);
            cout << "Page " << page << ":   " << fixed << setprecision(2) << percent << "%" << endl;
            page++;

        }
    }
}


