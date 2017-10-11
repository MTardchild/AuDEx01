#include <cstdlib>
#include <cstring>
#include <iostream>
#include "Task3.h"

using namespace std;

Task3::Task3(int m, int n) {
    if (m < 1 || n < 1) return;

    int **matrix = (int**) malloc(m * sizeof(int));
    for (int i = 0; i < m; ++i) {
        matrix[i] = (int*) malloc(n * sizeof(int));
    }

    this->matrix = (matrix);
    this->m = static_cast<size_t>(m);
    this->n = static_cast<size_t>(n);
    this->init();
}

void Task3::init() {
    for (int i = 0; i < this->m; ++i) {
        memset(this->matrix[i], 0, this->n);
    }
}

void Task3::print() {
    for (int i = 0; i < this->m; ++i) {
        for (int j = 0; j < this->n; ++j) {
            cout << this->matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void Task3::input() {
    for (int i = 0; i < this->m; ++i) {
        for (int j = 0; j < this->n; ++j) {
            cin >> this->matrix[i][j];
        }
    }
}

Task3 Task3::add(Task3* matrix) {
    if (isNotAddable(matrix)) return Task3(0, 0);

    Task3 addedMatrix(static_cast<int>(this->m), static_cast<int>(this->n));

    for (int i = 0; i < this->m; ++i) {
        for (int j = 0; j < this->n; ++j) {
            addedMatrix.matrix[i][j] = this->matrix[i][j] + matrix->matrix[i][j];
        }
    }

    return addedMatrix;
}

Task3 Task3::mult(Task3* matrix) {
    if (isNotMultipliable(matrix)) return Task3(0, 0);

    Task3 multipliedMatrix(static_cast<int>(this->m), static_cast<int>(matrix->n));

    for (int i = 0; i < this->m; ++i) {
        for (int j = 0; j < matrix->n; ++j) {
            for (int k = 0; k < this->n; ++k) {
                multipliedMatrix.matrix[i][j] += this->matrix[i][k] * matrix->matrix[k][j];
            }
        }
    }

    return multipliedMatrix;
}

bool Task3::isNotAddable(Task3* matrix) {
    return this->m != matrix->m
           || this->n != matrix->n;
}

bool Task3::isNotMultipliable(Task3* matrix) {
    return this->n != matrix->m;
}

void Task3::randomize() {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < this->m; ++i) {
        for (int j = 0; j < this->n; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
}
