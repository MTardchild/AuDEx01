#ifndef AUDEX01_TASK3_H
#define AUDEX01_TASK3_H

class Task3 {
public:
    Task3(int, int);
    void init();
    void print();
    void input();
    void randomize();
    Task3 add(Task3*);
    Task3 mult(Task3*);
private:
    bool isNotAddable(Task3*);
    bool isNotMultipliable(Task3 *);

    int** matrix;
    size_t m;
    size_t n;
};

#endif //AUDEX01_TASK3_H
