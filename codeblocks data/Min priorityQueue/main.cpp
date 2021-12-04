#include "ex.h"

int main()
{
    int n[15] = {10,12,1,14,6,5,8,15,3,9,7,4,11,13,2};
    priorityQueue <int> a(n,15);
    //a.decreaseKey(4,1);
    cout<<a.findMin(1);
    /*for(int i = 0;i < 15; i++)
        cout<<a.deQueue()<<' ';*/



    return 0;
}
