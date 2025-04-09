#include "pch.h"
#include <iostream>
#include <vector>

using namespace System;
using namespace std;

// Funci�n para realizar la factorizaci�n LU
void luDecomposition(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U, int n) {
    for (int i = 0; i < n; i++) {
        // Calcular la matriz U
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += L[i][j] * U[j][k];
            U[i][k] = A[i][k] - sum;
        }

        // Calcular la matriz L
        for (int k = i; k < n; k++) {
            if (i == k)
                L[i][i] = 1;  // Diagonal de L es 1
            else {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += L[k][j] * U[j][i];
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

int main() {
    int n = 3;
    vector<vector<double>> A = {
        {2, -1, -2},
        {-4, 6, 3},
        {-4, -2, 8}
    };

    vector<vector<double>> L(n, vector<double>(n, 0));
    vector<vector<double>> U(n, vector<double>(n, 0));

    luDecomposition(A, L, U, n);

    // Mostrar matrices L y U
    cout << "Matriz L:\n";
    for (const auto& row : L) {
        for (double val : row)
            cout << val << " ";
        cout << endl;
    }

    cout << "Matriz U:\n";
    for (const auto& row : U) {
        for (double val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}