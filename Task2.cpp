#include <iostream>
#include <cstring>
#include "Task2.h"

using namespace std;

void Task2::sieve(int limit) {
    bool array[limit];
    memset(array, true, sizeof(array));

    for (int i = 2; i*i < limit; ++i) {
        if (array[i]) {
            for (int j = i*2; j < limit; j += i) {
                array[j] = false;
            }
        }
    }

    for (int i = 2; i < limit; ++i) {
        if (array[i]) cout << i << " ";
    }

    cout << endl;
}

