#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>

#define maxsize 1000
class INT {
    public:
        INT() {}
        INT operator=(INT);
        INT operator+(INT);
        friend std::istream &operator>>(std::istream &, INT &);
        friend std::ostream &operator<<(std::ostream &, INT);
    protected:
        char data[maxsize + 1];
        int len;
};

#endif
