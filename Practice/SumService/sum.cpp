#include "sum.h"

Sum::Sum(newDisplay* dsptr):dsptr(dsptr) {

}

int Sum::getSum(int x, int y){
    int result =  x+y;
    dsptr->display(result);
    return result;
};

bool Sum::getStatus(){
    return false;
}
