#include "Task1.h"

int Task1::euclid(int a, int b) {
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int Task1::euclidRec(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return euclidRec(b, a % b);
    }
}

int Task1::leastCommonMultiple(int a, int b) {
    return a * b / euclidRec(a, b);
}
