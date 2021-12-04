#include "ex.h"

int main()
{
    int a[]={12,56,56,89,43,32,89,67,80,74,29,89};

    ex<int> n;
    cout<<n.deleteRepeat(a,12);
}
