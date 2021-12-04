#include "ex.h"

int main()
{
    int m[]={1,3,5,7,9},n[]={2,4,6};
    DoublelinkList<int> A,B;

    for(int i=0;i<5;i++)
        A.insert(i,m[i]);

    for(int i=0;i<3;i++)
        B.insert(i,n[i]);

    A.traverse();
    cout<<endl;
    B.traverse();
    cout<<endl;

    DoublelinkList<int> C=A+B;

    //C=A+B;
    C.traverse();

    return 0;
}
