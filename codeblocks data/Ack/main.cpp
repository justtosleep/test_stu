#include "ex.h"



//递归算法
template<class T>
T AckRecursion(T m,T n)
{
    if(m==0)
        return n+1;
    else if(m>0&&n==0)
        return AckRecursion(m-1,1);
    else if(m>0&&n>0)
        return AckRecursion(m-1,AckRecursion(m,n-1));
}


int main()
{
    cout<<"递归算法得到 A(3,6)答案为: ";
    cout<<AckRecursion(3,6);
    cout<<endl<<"非递归算法得到 A(3,6)答案为: ";
    Ack(3,6);

    return 0;
}
