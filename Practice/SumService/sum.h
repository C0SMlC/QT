#ifndef SUM_H
#define SUM_H

#include "newdisplay.h"

class Sum
{
private:
    newDisplay* dsptr;

public:
    Sum(newDisplay* dsptr);
    int getSum(int x, int y);
    bool getStatus();
};

#endif // SUM_H
