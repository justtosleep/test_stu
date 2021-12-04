#ifndef EX_H_INCLUDED
#define EX_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

template<class T>
class list
{
public:
    virtual void clear()=0;
    virtual int length() const=0;
    virtual void insert(int i,const T &x)=0;
    virtual void remove(int i)=0;
    virtual int search(const T &x)const=0;
    virtual T visit(int i)const =0;
    virtual ~list(){}
};

template<class T>
class SeqList:public list<T>
{
private:
    T *data;
    int CurrentLength;
    int maxsize;
    void doublespace();
public:
    SeqList(int intsize=10);
    ~SeqList();
    void clear();
    int length() const;
    void insert(int i,const T&x);
    void remove(int i);
    int search(const T &x)const;
    T visit(int i) const;
    void traverse()const;

    //homework

    //The 7 question.
    template<class T1>
    friend SeqList<T1> operator+(const SeqList<T1> &m,const SeqList<T1> &n);        //重载+
    SeqList<T> &operator=(const SeqList<T> &m);                                      //重载=
    SeqList(const SeqList<T>&);                                                       //复制构造函数


};


template<class T>
SeqList<T> operator+(const SeqList<T> &m,const SeqList<T> &n)           //重载+
{
        SeqList<T> tmp(m.maxsize+n.maxsize);
        int i=0;
        for(;i<m.CurrentLength;i++)
            tmp.insert(i,m.data[i]);

        for(;i<m.CurrentLength+n.CurrentLength;i++)
            tmp.insert(i,n.data[i-m.CurrentLength]);

        return tmp;
}

template<class T>
SeqList<T>& SeqList<T>::operator=(const SeqList<T> &m)                   //重载=
{
    if(this==&m) return *this;
    delete []data;

    data=new T[m.maxsize];
    maxsize=m.maxsize;
    CurrentLength=m.CurrentLength;
    for(int i=0;i<m.CurrentLength;i++)
        data[i]=m.data[i];

    return *this;
}

template<class T>
SeqList<T>::SeqList(const SeqList<T> &m)                                  //复制构造函数
{
    data=new T[m.maxsize];
    maxsize=m.maxsize;
    CurrentLength=m.CurrentLength;
    for(int i=0;i<m.CurrentLength;i++)
        data[i]=m.data[i];
}




template<class T>
void SeqList<T>::doublespace()
{
    T*tmp=data;
    maxsize*=2;
    data=new T[maxsize];
    for(int i=0;i<CurrentLength;i++)
    {
        data[i]=tmp[i];
    }
    delete []tmp;
}

template<class T>
SeqList<T>::SeqList(int intsize)
{
    data=new T[intsize];
    maxsize=intsize;
    CurrentLength=0;
}



template<class T>
T SeqList<T>::visit(int i) const
{
    return data[i];
}

template<class T>
SeqList<T>::~SeqList()
{
    delete[]data;
}

template<class T>
void SeqList<T>::clear()
{
    CurrentLength=0;
}

template<class T>
int SeqList<T>::length() const
{
    return CurrentLength;
}

template<class T>
void SeqList<T>::insert(int i,const T&x)
{
    if(CurrentLength==maxsize)
        doublespace();

    for(int j=CurrentLength;j>i;j--)
    {
        data[j+1]=data[j];
    }
    data[i]=x;
    CurrentLength++;
}

template<class T>
void SeqList<T>::remove(int i)
{
    for(;i<CurrentLength-1;i++)
    {
        data[i]=data[i+1];
    }
    CurrentLength--;
}

template<class T>
int SeqList<T>::search(const T &x)const
{
    int i;
    for(i=0;i<CurrentLength;i++)
    {
        if(data[i]==x) return i;
    }

    return -1;
}

template<class T>
void SeqList<T>::traverse()const
{
    for(int i=0;i<CurrentLength;i++)
    cout<<data[i]<<' ';
}

#endif // EX_H_INCLUDED
