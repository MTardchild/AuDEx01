#ifndef AUDEX01_TASK1_H
#define AUDEX01_TASK1_H

// Which one to use depends on the hardware. For instance if the memory is very restricted the recursive implementation
// might be problematic due to the stack growth. The time complexity should be identical.
// Remarkable: a*b = euclid*leastCommonMultiple
class Task1 {
public:
    int euclid(int a, int b);
    int euclidRec(int a, int b);
    int leastCommonMultiple(int a, int b);
};


#endif //AUDEX01_TASK1_H
