#ifndef EX_H_INCLUDED
#define EX_H_INCLUDED

#include <iostream>

using namespace std;

template<class T>
class queue
{
public:
    virtual bool isEmpty() const = 0;
    virtual void enQueue(const T &x) = 0;
    virtual T deQueue() = 0;
    virtual T getHead() const = 0;
    virtual ~queue(){}
};

template<class T>
class seqQueue
{
private:
    T *front;
    int maxSize;
    int rear;
    void doubleSpace();
public:
    seqQueue (int size=10);
    bool isEmpty() const;
    void enQueue(const T &x);
    T deQueue();
    T getHead() const;
    ~seqQueue()
    {
        delete [] front;
    }
};

template<class T>
void seqQueue<T>::doubleSpace()
{
    T *tmp=front;
    front =new T[maxSize*2];
    for(int i=0;i<maxSize;i++)
        front[i]=tmp[i];
    maxSize*=2;
    delete []tmp;
}

template<class T>
seqQueue<T>::seqQueue(int size)
{
    front=new T [size];
    rear=0;
    maxSize=size;
}
template<class T>
bool seqQueue<T>::isEmpty() const
{
    return front==0;
}

template<class T>
void seqQueue<T>::enQueue(const T &x)
{
    if(rear==maxSize-1) doubleSpace();
    front[rear++]=x;
}


template<class T>
T seqQueue<T>::deQueue()
{
    T x=front[0];
    for(int i=0;i<rear;i++)
        front[i]=front[i+1];
    rear--;
    return x;
}

template<class T>
T seqQueue<T>::getHead() const
{
    return front[0];
}

#endif // EX_H_INCLUDED
