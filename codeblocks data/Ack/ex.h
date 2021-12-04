#ifndef EX_H_INCLUDED
#define EX_H_INCLUDED

#include <iostream>

using namespace std;


class stack
{
public:
    virtual bool isEmpty() const=0;
    virtual void push(const int &x,const int &y)=0;
    virtual void pop()=0;
    virtual void top() const=0;
    virtual ~stack(){}
};

class linkStack:public stack
{
public:
    struct node
    {
        int m,n;
        node *next;
        node(const int &x,const int &y,node *N=NULL)
        {
            m=x;
            n=y;
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
    void push(const int &x,const int &y);
    void pop();
    void top() const;



    //homework

    //非递归算法
    friend void Ack(int m,int n);

};


void Ack(int m,int n)
{
    linkStack  ack;
    ack.push(m,n);
    while(ack.top_p!=NULL)
    {
        if(ack.top_p->m==0 && ack.top_p->n>=0)
        {
            int x=ack.top_p->n+1;
            while(ack.top_p!=NULL && ack.top_p->n>=0)
                ack.pop();
            if(ack.top_p==NULL)
            {
                cout<<x;
                break;
            }
            else ack.top_p->n=x;
        }


        if(ack.top_p->m>0 && ack.top_p->n>0)
        {
            linkStack::node *p= new linkStack::node(ack.top_p->m-1,-1,ack.top_p);
            linkStack::node *q= new linkStack::node(ack.top_p->m,ack.top_p->n-1);

            ack.top_p=p;

            q->next=ack.top_p;\
            ack.top_p=q;

        }


        if(ack.top_p->m>0 && ack.top_p->n==0)
            ack.top_p= new linkStack::node(ack.top_p->m-1,1,ack.top_p);
    }

}

linkStack::linkStack()
{
    top_p=NULL;
}

linkStack::~linkStack()
{
    node *tmp;
    while(top_p!=NULL)
    {
        tmp=top_p;
        top_p=top_p->next;
        delete tmp;
    }
}

bool linkStack ::isEmpty() const
{
    return top_p==NULL;
}

void linkStack ::push(const int &x,const int &y)
{
    top_p=new node(x,y,top_p);
}


void linkStack ::pop()
{
    node *tmp=top_p;
    top_p=top_p->next;
    delete tmp;
}


void linkStack ::top() const
{
    cout<<top_p->m<<" "<<top_p->n;
}

#endif // EX_H_INCLUDED
