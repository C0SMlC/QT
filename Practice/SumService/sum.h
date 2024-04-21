#ifndef SUM_H
#define SUM_H

#include "display.h"

class Sum
{
private:
    Display* dsptr;

public:
    Sum(Display* dsptr);
    int getSum(int x, int y);
    bool getStatus();
};

#endif // SUM_H
