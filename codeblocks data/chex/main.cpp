#include "ex.h"

int main()
{
    int x[]={5,4,3,2,1};
    Linklist<int> c;
    for(int i=0;i<5;i++)
        c.insert(i,x[i]);

    c.traverse();
    c.erase(2,3);
    c.traverse();
    c.reverse();
    c.traverse();
    c.revisit(2);

    int y[]={7,8,9,2,3,4,5};
    Linklist<int> b;
    for(int i=0;i<7;i++)
        b.insert(i,y[i]);

    find(b,c);



    return 0;
}




