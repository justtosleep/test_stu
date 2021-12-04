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
    virtual ~list(){};
};

template<class T>
class DoublelinkList:public list<T>
{
private:
    struct node
    {
        T data;
        node *next,*prev;

        node():next(NULL),prev(NULL){}
        node(const T&x,node *n=NULL,node *m=NULL)
        {
            data=x;
            next=n;
            prev=m;
        }
        ~node(){}
    };

    node *head,*tail;
    int CurrentLength;

    node *move(int i)const;

public:
    DoublelinkList();
    ~DoublelinkList()
    {
        clear();
        delete head;
        delete tail;
    }
    void clear();
    int length()const
    {
        return CurrentLength;
    }
    void insert(int i,const T &x);
    void remove(int i);
    int search(const T &x)const;
    T visit(int i)const;
    void traverse() const;
    void reverse() const;


    //homework

    //The 8 question.
    template<class T1>
    friend DoublelinkList<T1> operator+(const DoublelinkList<T1>&m,const DoublelinkList<T1> &n);         //重载+
    DoublelinkList<T> &operator=(const DoublelinkList<T> &m);                                              //重载=
    DoublelinkList(const DoublelinkList<T>&m);                                                             //复制构造函数

};


template<class T>
DoublelinkList<T> operator+(const DoublelinkList<T>&m,const DoublelinkList<T> &n)       //重载+
{
    DoublelinkList<T> q;
    int i=0;
    typename DoublelinkList<T>::node *p;

    q.CurrentLength=m.CurrentLength+n.CurrentLength;
    for(p=m.head->next;p!=m.tail;i++,p=p->next)
        q.insert(i,p->data);
    for(p=n.head->next;p!=n.tail;i++,p=p->next)
        q.insert(i,p->data);

    return q;
}

template<class T>
DoublelinkList<T> &DoublelinkList<T>::operator=(const DoublelinkList<T> &m)             //重载=
{
    if(this==&m) return *this;

    clear();
    node *p=m.head->next;

    CurrentLength=m.CurrentLength;
    for(int i=0;p!=m.tail;i++,p=p->next)
        insert(i,p->data);

    return *this;
}

template<class T>
DoublelinkList<T>::DoublelinkList(const DoublelinkList<T>&m)                            //复制构造函数
{
    node *p=m.head->next;
    head=new node;
    tail=new node;

    head->next=tail;
    tail->prev=head;
    CurrentLength=m.CurrentLength;

    for(int i=0;p!=m.tail;i++,p=p->next)
        insert(i,p->data);
}

template<class T>
DoublelinkList<T>::DoublelinkList()
{
    head=new node;
    tail=new node;
    head->next=tail;
    tail->prev=head;
    CurrentLength=0;
}

template<class T>
typename DoublelinkList<T>::node *DoublelinkList<T>::move(int i)const
{
    node *p=head;

    while(i-->=0) p=p->next;
    return p;
}

template<class T>
void DoublelinkList<T>::clear()
{
    node *p=head->next,*q;
    head->next=tail;
    tail->prev=head;
    while(p!=tail)
    {
        q=p->next;
        delete p;
        p=q;
    }
    CurrentLength=0;
}

template<class T>
void DoublelinkList<T>::insert(int i,const T &x)
{
    node *p=move(i),*q=new node(x,p,p->prev);

    p->prev->next=q;
    p->prev=q;
    ++CurrentLength;
}

template<class T>
void DoublelinkList<T>::remove(int i)
{
    node *p=move(i-1),*q=p->next;
    p->next=p->next->next;
    p->next->prev=p;
    delete q;
    --CurrentLength;


}

template<class T>
int DoublelinkList<T>::search(const T &x)const
{
    node *p=head->next;
    for(int i=0;p!=tail;i++)
    {
        if(p->data==x) return i;
        else p=p->next;
    }
    return -1;

}

template<class T>
T DoublelinkList<T>::visit(int i)const
{
   return move(i)->data;
}

template<class T>
void DoublelinkList<T>::traverse() const
{
    node *p=head->next;
    cout<<endl;
    while(p!=tail)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

template<class T>
void DoublelinkList<T>::reverse() const
{
    node *p=tail->prev;
    cout<<endl;
    while(p!=head)
    {
        cout<<p->data<<" ";
        p=p->prev;
    }
    cout<<endl;
}

#endif // EX_H_INCLUDED
