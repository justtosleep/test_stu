#include "ex.h"



//�ݹ��㷨
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
    cout<<"�ݹ��㷨�õ� A(3,6)��Ϊ: ";
    cout<<AckRecursion(3,6);
    cout<<endl<<"�ǵݹ��㷨�õ� A(3,6)��Ϊ: ";
    Ack(3,6);

    return 0;
}
