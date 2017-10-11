#include <iostream>
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"

using namespace std;

void task1();
void task2();
void task3();

int main() {
    task1();
    task2();
    task3();

    return 0;
}

void task3() {
    Task3 matrix(2000, 2000);
    Task3 anotherMatrix(2000, 2000);
    matrix.randomize();
    anotherMatrix.randomize();

    //matrix.print();
    //anotherMatrix.print();

    Task3 added = matrix.add(&anotherMatrix);
    Task3 multiplied = matrix.mult(&anotherMatrix);
}

void task2() {
    Task2 task2;
    task2.sieve(100001);
}

void task1() {
    Task1 task1;
    int euclidIter = task1.euclid(5024, 234);
    int euclidRec = task1.euclidRec(5024, 234);
    int leastComMul = task1.leastCommonMultiple(5024, 234);

    cout << euclidIter << endl << euclidRec << endl << leastComMul << endl;

    for (int i = 30; i < 41; ++i) {
        for (int j = 30; j < 41; ++j) {
            euclidIter = task1.euclid(i, j);
            leastComMul = task1.leastCommonMultiple(i, j);
            cout << i << ", " << j << ": ggT: " << euclidIter << " kgV: " << leastComMul << " a*b: " << i * j << endl;
        }
    }
}