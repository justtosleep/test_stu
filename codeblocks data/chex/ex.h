#ifndef EX_H_INCLUDED
#define EX_H_INCLUDED

#include <iostream>

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
class Linklist:public list<T>
{
private:
    struct node
    {
        T data;
        node *next;

        node():next(NULL){}
        node(const T&x,node *n=NULL)
        {
            data=x;
            next=n;
        }
        ~node(){}
    };

    node *head;
    int CurrentLength;

    node *move(int i)const;

public:
    Linklist();
    ~Linklist()
    {
        clear();
        delete head;
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


    //Homework


    //The 1 question.
    void erase(const T &x,const T &y);

    //The 6 question.
    void reverse();

    //The 9 question.
    int revisit(const int &k);

    //The 10 question.
    template<class T1>
    friend void find(const Linklist<T1> &x,const Linklist<T1> &y);

};

template<class T>
void Linklist<T>::erase(const T &x,const T &y)                      //The 1 question.
{
    node *p=head->next,*q;
    while(p->next!=NULL)
    {
        if(p->next->data>=x&&p->next->data<=y)
        {
            q=p->next;
            p->next=q->next;
            delete q;
            CurrentLength--;
        }
        else p=p->next;
    }

    cout<<"已经删除[x,y]间的所有元素"<<endl;
}


template<class T>
void Linklist<T>::reverse()                             //The 6 question.
{
    if(head->next==NULL) return;

    Linklist<T> p;
    for(int i=CurrentLength;i>0;i--)
        p.insert(CurrentLength-i,move(i-1)->data);
    p.CurrentLength=CurrentLength;

    clear();
    for(int i=0;i<p.CurrentLength;i++)
        insert(i,p.move(i)->data);
    CurrentLength=p.CurrentLength;

    cout<<"已经逆置当前链表"<<endl;
}


template<class T>
int Linklist<T>::revisit(const int &k)                  //The 9 question.
{
    if (k>CurrentLength) return 0;

    node *p=head->next,*q=p;

    for(int i=1;i<k;i++)
        p=p->next;

    while(p->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }

    cout<<q->data<<endl;

    return 1;
}


template<class T>
void find(const Linklist<T> &str1,const Linklist<T> &str2)              //The 10 question.
{
    int i,j;
    typename Linklist<T>::node *p=str1.head->next,*q=str2.head->next;

    i=j=1;
    while(p->next!=NULL)
    {
        i++;
        p=p->next;
    }
    while(q->next!=NULL)
    {
        j++;
        q=q->next;
    }

    if(i>=j)
    {
        int difference=i-j;

        i=difference+1;
        j=1;
        p=str1.head->next;
        q=str2.head->next;

        while(difference-->0)
            p=p->next;
    }
    else
    {
        int difference=j-i;

        j=difference+1;
        i=1;
        p=str1.head->next;
        q=str2.head->next;

        while(difference-->0)
            q=q->next;
    }

    while((p->data!=q->data)&&(p->next!=NULL))
    {
        p=p->next;
        q=q->next;
        i++;
        j++;
    }

    cout<<"str1的第"<<i<<"个结点和"<<"str2的第"<<j<<"个结点为公共结点"<<endl;
    cout<<"公共结点的值为"<<p->data;

}


template<class T>
Linklist<T>::Linklist()
{
    head=new node;
    CurrentLength=0;
}

template<class T>
typename Linklist<T>::node *Linklist<T>::move(int i)const
{
    node *p=head;

    while(i-->=0) p=p->next;
    return p;
}

template<class T>
void Linklist<T>::clear()
{
    node *p=head->next,*q;
    head->next=NULL;
    while(p!=NULL)
    {
        q=p->next;
        delete p;
        p=q;
    }
    CurrentLength=0;
}

template<class T>
void Linklist<T>::insert(int i,const T &x)
{
    node *p=move(i-1);

    p->next=new node(x,p->next);
    ++CurrentLength;
}

template<class T>
void Linklist<T>::remove(int i)
{
    node *p=move(i-1),*q=p->next;
    p->next=p->next->next;
    delete q;
    --CurrentLength;
}

template<class T>
int Linklist<T>::search(const T &x)const
{
    node *p=head->next;
    for(int i=0;p!=NULL;i++)
    {
        if(p->data==x) return i;
        else p=p->next;
    }
    return -1;

}

template<class T>
T Linklist<T>::visit(int i)const
{
   return move(i)->data;
}

template<class T>
void Linklist<T>::traverse() const
{
    node *p=head->next;
    cout<<endl;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}


#endif // EX_H_INCLUDED
