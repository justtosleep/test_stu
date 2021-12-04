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
class linkStack:public stack<T>
{
private:
    struct node
    {
        T data;
        node *next;
        node(const T &x,node *N=NULL)
        {
            data=x;
            next=N;
        }
        node():next(NULL){}
        ~node(){}
    };
    node *top_p;
public:
    linkStack();
    ~linkStack();
    bool isEmpty() const;
    void push(const T &x);
    T pop();
    T top() const;


};

template<class T>
linkStack<T>::linkStack()
{
    top_p=NULL;
}

template<class T>
linkStack<T>::~linkStack()
{
    node *tmp;
    while(top_p!=NULL)
    {
        tmp=top_p;
        top_p=top_p->next;
        delete tmp;
    }
}

template<class T>
bool linkStack<T>::isEmpty() const
{
    return top_p==NULL;
}

template<class T>
void linkStack<T>::push(const T &x)
{
    top_p=new node(x,top_p);
}

template<class T>
T linkStack<T>::pop()
{
    node *tmp=top_p;
    T x=tmp->data;

    top_p=top_p->next;
    delete tmp;
    return x;
}

template<class T>
T linkStack<T>::top() const
{
    return top_p->data;
}

#endif // EX_H_INCLUDED
