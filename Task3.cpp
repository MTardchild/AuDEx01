#include <cstdlib>
#include <cstring>
#include <iostream>
#include <chrono>
#include <cmath>

#include "Task3.h"

using namespace std;

Task3::Task3(int m, int n) {
    if (m < 1 || n < 1) return;

    int **matrix = (int**) malloc(m * sizeof(int*));
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
    if (isQuadratic() && isQuadratic(matrix)) {
        if (isCalculableInSeconds(60, pow(this->m * 2, 2))) return Task3(0, 0);
    }

    double operations = 0;
    auto timePre = chrono::high_resolution_clock::now();
    Task3 addedMatrix(static_cast<int>(this->m), static_cast<int>(this->n));

    for (int i = 0; i < this->m; ++i) {
        for (int j = 0; j < this->n; ++j) {
            addedMatrix.matrix[i][j] = this->matrix[i][j] + matrix->matrix[i][j];
            operations += 2;
        }
    }

    auto timePost = chrono::high_resolution_clock::now();

    cout << "Done Operations: " << operations << endl;
    cout << "Duration: " << chrono::duration_cast<chrono::milliseconds>(timePost-timePre).count() << endl;

    return addedMatrix;
}

Task3 Task3::mult(Task3* matrix) {
    if (isNotMultipliable(matrix)) return Task3(0, 0);
    if (isQuadratic() && isQuadratic(matrix)) {
        if (isCalculableInSeconds(63, pow(this->m * 5, 3))) return Task3(0, 0);
    }

    double operations = 0;
    auto timePre = chrono::high_resolution_clock::now();
    Task3 multipliedMatrix(static_cast<int>(this->m), static_cast<int>(matrix->n));

    for (int i = 0; i < this->m; ++i) {
        for (int j = 0; j < matrix->n; ++j) {
            for (int k = 0; k < this->n; ++k) {
                multipliedMatrix.matrix[i][j] += this->matrix[i][k] * matrix->matrix[k][j];
                operations += 5; // AccessEntries(2x), Multiply, StoreResult (2 ops, store and add)
            }
        }
    }

    auto timePost = chrono::high_resolution_clock::now();

    cout << "Done Operations: " << operations << endl;
    cout << "Duration: " << chrono::duration_cast<chrono::milliseconds>(timePost-timePre).count() << endl;

    return multipliedMatrix;
}

void Task3::randomize() {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < this->m; ++i) {
        for (int j = 0; j < this->n; ++j) {
            matrix[i][j] = rand() % 20000000 - 10000000;
        }
    }
}

bool Task3::isNotAddable(Task3* matrix) {
    return this->m != matrix->m
           || this->n != matrix->n;
}

bool Task3::isNotMultipliable(Task3* matrix) {
    return this->n != matrix->m;
}

bool Task3::isCalculableInSeconds(unsigned long long seconds, double operations) {
    int opsPerMs = 16000000; // OPs my PC can do :-P
    double ms = seconds * 1000;
    double neededMs = operations / opsPerMs;

    cout << "Estimated time needed: " << neededMs << " Time given: " << ms << endl;

    return neededMs > ms;
}

bool Task3::isQuadratic() {
    return this->m == this->n;
}

bool Task3::isQuadratic(Task3 *matrix) {
    return matrix->m == matrix->n;
}
