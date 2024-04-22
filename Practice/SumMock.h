#ifndef SUMMOCK_H
#define SUMMOCK_H

#include "newdisplay.h"
#include "gmock/gmock.h"

class DisplayMockClass:public newDisplay{
public:
    MOCK_METHOD1(display, void(int));
};

#endif // SUMMOCK_H
