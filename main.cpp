#include <iostream>
#include "Task1.h"
#include "Task2.h"

using namespace std;

void task1();
void task2();

int main() {
    task1();
    task2();

    return 0;
}

void task2() {
    Task2 task2;
    task2.sieve(100000);
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
            cout << "ggT: " << euclidIter << endl << "kgV: " << leastComMul << endl << "a*b: " << i * j << endl;
        }
    }
}