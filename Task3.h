#ifndef AUDEX01_TASK3_H
#define AUDEX01_TASK3_H

class Task3 {
public:
    Task3(int m, int n);
    void init();
    void print();
    void input();
    void randomize();
    Task3 add(Task3* matrix);
    Task3 mult(Task3* matrix);
private:
    bool isNotAddable(Task3* matrix);
    bool isNotMultipliable(Task3* matrix);
    bool isCalculableInSeconds(unsigned long long seconds, double operations);
    bool isQuadratic();
    bool isQuadratic(Task3* matrix);

    int** matrix;
    size_t m;
    size_t n;
};

#endif //AUDEX01_TASK3_H
