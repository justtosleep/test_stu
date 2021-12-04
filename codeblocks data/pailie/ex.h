#ifndef EX_H_INCLUDED
#define EX_H_INCLUDED

#include <iostream>

using namespace std;


//交换值
void swap(int &a,int &b)
{
    int tmp=a;
    a=b;
    b=tmp;
}


//判断元素是否相同
bool IsEqual(int p[],int k, int t)
{
	for (int i=k;i<t;i++)
		if (p[i]==p[t])
			return false;

	return true;
}


//递归函数
void AllRange(int p[],int k,int length)
{
    if(k==length-1)
    {
        for(int i=0;i<length;i++)
            cout<<p[i]<<" ";
        cout<<endl;
    }
    else
    {
        for(int i=k;i<length;i++)
        {
            if(IsEqual(p,k,i))              //元素相同则不交换
            {
                swap(p[k],p[i]);
                AllRange(p,k+1,length);
                swap(p[k],p[i]);
            }
        }
    }
}

#endif // EX_H_INCLUDED
