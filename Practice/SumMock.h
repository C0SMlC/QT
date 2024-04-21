#ifndef SUMMOCK_H
#define SUMMOCK_H

#include "display.h"
#include "gmock/gmock.h"

class DisplayMockClass:public Display{
public:
    MOCK_METHOD1(display, void(int));
};

#endif // SUMMOCK_H
