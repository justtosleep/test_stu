#ifndef EX_H_INCLUDED
#define EX_H_INCLUDED

#include <iostream>

using namespace std;


//����ֵ
void swap(int &a,int &b)
{
    int tmp=a;
    a=b;
    b=tmp;
}


//�ж�Ԫ���Ƿ���ͬ
bool IsEqual(int p[],int k, int t)
{
	for (int i=k;i<t;i++)
		if (p[i]==p[t])
			return false;

	return true;
}


//�ݹ麯��
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
            if(IsEqual(p,k,i))              //Ԫ����ͬ�򲻽���
            {
                swap(p[k],p[i]);
                AllRange(p,k+1,length);
                swap(p[k],p[i]);
            }
        }
    }
}

#endif // EX_H_INCLUDED
