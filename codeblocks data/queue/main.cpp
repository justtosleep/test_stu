#include "ex.h"

int main()
{
    int n[]={1,2,3,4,5,6,7,8,9,10};
    seqQueue<int> a(5);

    for(int i=0;i<10;i++)
        a.enQueue(n[i]);

    cout<<a.getHead();
    cout<<a.deQueue();
    cout<<a.getHead();
    cout<<a.isEmpty();

    return 0;
}
