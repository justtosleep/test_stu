#ifndef EX_H_INCLUDED
#define EX_H_INCLUDED

#include <iostream>

using namespace std;

template<class T>
class stack
{
public:
    virtual bool isEmpty() const=0;
    virtual void push(const T &x)=0;
    virtual T pop()=0;
    virtual T top() const=0;
    virtual ~stack(){}
};

template<class T>
class seqStack:public stack<T>
{
private:
    T *data;
    int top_p;
    int maxSize;
    void doubleSpace();

public:
    seqStack(int initSize=10);
    ~seqStack();
    bool isEmpty() const;
    void push(const T &x);
    T pop();
    T top() const;


    //homework

    template<class T1>
    friend void TentoTwo(const T1 &x);          //The 2 question.


};

template<class T>
void TentoTwo(const T &x)
{
   seqStack<T> a;
    T n=x/2;
    a.push(x%2);
    a.push(n);
    while(a.top()>1)
    {
        n=a.pop();
        a.push(n%2);
        a.push(n/2);
    }
    while(a.top_p>=0)
        cout<<a.pop();
    cout<<endl;
}


template<class T>
void seqStack<T>::doubleSpace()
{
    T *p=data;

    data=new T[maxSize*2];

    for(int i=0;i<maxSize;i++)
        data[i]=p[i];
    maxSize*=2;
    delete[]p;
}

template<class T>
seqStack<T>::seqStack(int initSize)
{
    data=new T[initSize];
    maxSize=initSize;
    top_p=-1;
}

template<class T>
seqStack<T>::~seqStack()
{
    delete[]data;
}

template<class T>
bool seqStack<T>::isEmpty() const
{
    return top_p==-1;
}

template<class T>
void seqStack<T>::push(const T &x)
{
    if(top_p==maxSize-1) doubleSpace();
    top_p++;
    data[top_p]=x;
}

template<class T>
T seqStack<T>::pop()
{
    return data[top_p--];
}

template<class T>
T seqStack<T>::top() const
{
    return data[top_p];
}


#endif // EX_H_INCLUDED
