#ifndef EX_H_INCLUDED
#define EX_H_INCLUDED

#include <iostream>

using namespace std;

template<class T>
class queue
{
public:
    virtual bool isEmpty()const = 0;
    virtual void enQueue(const T &x) = 0;
    virtual T deQueue() = 0;
    virtual T getHead() const = 0;
    virtual ~queue(){}
};

template<class T>
class linkQueue:public queue<T>
{
private:
    struct node
    {
        T data;
        node *next;
        node(const T &x,node *N =NULL){data = x;next = N;}
        node():next(NULL){}
        ~node(){}
    };

    node *front,*rear;

public:
    linkQueue();
    ~linkQueue();
    void enQueue(const T &x);
    bool isEmpty()const;
    T deQueue();
    T getHead() const;

};

template<class T>
bool linkQueue<T>::isEmpty() const
{
    return front == NULL;
}

template<class T>
linkQueue<T>::linkQueue()
{
    front = rear =NULL;
}

template<class T>
linkQueue<T>::~linkQueue()
{
    node *tmp;
    while(front !=NULL)
    {
        tmp = front;
        front = front->next;
        delete tmp;
    }
}

template<class T>
void linkQueue<T>::enQueue(const T &x)
{
    if(rear == NULL)
        front = rear = new node(x);
    else
        rear = rear->next = new node(x);
}

template<class T>
T linkQueue<T>::deQueue()
{
    node *tmp = front;
    T value = front->data;
    front = front->next;
    if(front == NULL) rear = NULL;
    delete tmp;
    return value;
}

template<class T>
T linkQueue<T>::getHead() const
{
    return front->data;
}


template <class T>
class bTree
{
public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual T Root(T flag) const = 0;
    virtual T parent(T x, T flag) const = 0;
    virtual T lchild(T x, T flag) const = 0;
    virtual T rchild(T x, T flag) const = 0;
    virtual void delLeft(T x) = 0;
    virtual void delRight(T x) = 0;
    virtual void preOrder() const = 0;
    virtual void midOrder() const = 0;
    virtual void postOrder() const = 0;

};


template <class T>
class binaryTree: public bTree<T>
{
private:
    struct Node
    {
        Node *left,*right;
        T data;

        Node():left(NULL),right(NULL){}
        Node(T item,Node *L=NULL,Node *R=NULL):data(item),left(L),right(R){}
    };

    Node *root;
public:
    binaryTree() :root(NULL){}
    binaryTree(T x) { root = new Node(x);}
    ~binaryTree();
    void createTree (T flag);
    void clear();
    bool isEmpty() const;
    T Root(T flag) const;
    T parent(T x, T flag) const{return flag;}
    T lchild(T x, T flag) const;
    T rchild(T x, T flag) const;
    void delLeft(T x);
    void delRight(T x);
    void preOrder() const;
    void midOrder() const;
    void postOrder() const;

private:
    Node *find(T x,Node *t) const;
    void clear(Node *&t);
    void preOrder(Node *t) const;
    void midOrder(Node *t) const;
    void postOrder(Node *t) const;




    //以下为作业部分
private:
    struct elem
    {
        Node *p;
        int num;
    };
    void exlr(Node *n);
    int countD2(Node *n);
    int height(Node *t);

public:
    void exlr();
    int countD2();
    int height();
    bool full();
    bool isCom();
    bool checkMirror(binaryTree<T> &t1,binaryTree<T> &t2);
    bool checkNode(Node *t1,Node *t2);
    bool checkEqual(Node *t1, Node *t2);
    bool operator ==(binaryTree<T> &t2);
};



    //作业实现
    //第一题
template <class T>
void binaryTree<T>::exlr()
{
    exlr(root);
}

template <class T>
void binaryTree<T>::exlr(binaryTree<T>::Node *n)
{
    Node *p;
    if(n->left) exlr(n->left);
    if(n->right) exlr(n->right);

    p=n->left;
    n->left=n->right;
    n->right=p;
}

    //第二题
template <class T>
int  binaryTree<T>::countD2()
{
    return countD2(root);
}

template <class T>
int  binaryTree<T>::countD2(binaryTree<T>::Node *n)
{
    if(n == NULL) return 0;
    if(n->left&&n->right)
        return 1+countD2(n->left) +countD2(n->right);
    else
        return countD2(n->left) +countD2(n->right);
}

    //第三题
template <class T>
int binaryTree<T>::height()
{
    return height(root);
}

template <class T>
int  binaryTree<T>::height(binaryTree<T>::Node *t)
{
    if(t==NULL) return 0;
    else
    {
        int lt=height(t->left),rt=height(t->right);
        return 1+((lt>rt)?lt:rt);
    }
}


template <class T>
bool  binaryTree<T>::full()
{
    return(root == NULL)||
        (root !=NULL&&full(root->left)&&full(root->right))&&
        (height(root->left) == height(root->right));
}


    //第四题
template <class T>
bool  binaryTree<T>::isCom()
{
    linkQueue<T> que;
    elem cur,child;
    int count=1;
    int last =1;

    if(root == NULL)return true;
    cur.p =root;
    cur.num =1;
    que.enQueue(cur);
    while(!que.isEmpty())
    {
        cur=que.deQueue();
        if(cur.p->left!=NULL)
        {
            ++count;
            child.p =cur.p->left;
            last =child.num=cur.num*2;
            que.enQueue(child);
        }
        if(cur.p->right!= NULL)
        {
            ++count;
            child.p=cur.p->right;
            last=child.num =cur.num *2+1;
            que.enQueue(child);
        }
    }
    return count ==last;
}

    //第五题
template <class T>
bool  binaryTree<T>::operator ==(binaryTree<T> &t2)
{
    return checkEqual(root,t2.root);
}

template <class T>
bool  binaryTree<T>::checkEqual(binaryTree<T>::Node *t1, binaryTree<T>::Node *t2)
{
    if(t1 == NULL&&t2 == NULL) return true;
    if(t1 == NULL||t2 == NULL) return false;
    if(t1->data !=t2->data) return false;
    return checkEqual(t1->left,t2->left)&&checkEqual(t1->right,t2->right);
}

    //第六题
template <class T>
bool  binaryTree<T>::checkNode(binaryTree<T>::Node *t1,binaryTree<T>::Node *t2)
{
    if(t1 == NULL&&t2 == NULL) return true;
    if(t1 == NULL||t2 == NULL) return false;
    if(t1->data!=t2->data) return false;
    return checkNode(t1->left,t2->right)&&checkNode(t1->right,t2->left);
}

template <class T>
bool  binaryTree<T>::checkMirror(binaryTree<T> &t1,binaryTree<T> &t2)
{
    return checkNode(t1.root,t2.root);
}




template <class T>
void binaryTree<T>::createTree (T flag)
{
    linkQueue<Node *>que;
    Node *tmp;
    T x,ldata,rdata;
    cout<<"\n 输入根节点:";
    cin>>x;
    root = new Node(x);
    que.enQueue(root);

    while(!que.isEmpty())
    {
        tmp = que.deQueue();
        cout<<"\n 输入"<<tmp->data<<"的两个儿子（"<<flag<<"表示空结点）:";
        cin>>ldata>>rdata;
        if(ldata!=flag)que.enQueue(tmp->left = new Node(ldata));
        if(rdata!=flag)que.enQueue(tmp->right = new Node(rdata));
    }

    cout<<"create completeted!\n";
}

template <class T>
typename binaryTree<T>::Node *binaryTree<T>::find(T x,binaryTree<T>::Node *t)const
{
    Node *tmp;
    if(t ==NULL) return NULL;
    if(t->data == x) return t;
    if(tmp = find(x,t->left)) return tmp;
    else return find(x,t->right);
}

template <class T>
bool binaryTree<T>::isEmpty() const
{
    return root == NULL;
}

template <class T>
T binaryTree<T>::Root(T flag) const
{
    if(root == NULL) return flag;
    else return root->data;
}

template <class T>
void binaryTree<T>::clear(binaryTree<T>::Node *&t)
{
    if(t == NULL) return;
    clear(t->left);
    clear(t->right);
    delete t;
    t = NULL;
}

template <class T>
void binaryTree<T>::clear()
{
    clear(root);
}

template <class T>
binaryTree<T>::~binaryTree()
{
    clear(root);
}

template <class T>
T binaryTree<T>::lchild(T x, T flag) const
{
    Node *tmp =find(x,root);
    if(tmp == NULL||tmp->left == NULL) return flag;

    return tmp->left->data;
}

template <class T>
T binaryTree<T>::rchild(T x, T flag) const
{
    Node *tmp =find(x,root);
    if(tmp == NULL||tmp->left == NULL) return flag;

    return tmp->right->data;
}

template <class T>
void binaryTree<T>::delLeft(T x)
{
    Node *tmp = find(x,root);
    if(tmp == NULL) return;
    clear(tmp->left);
}

template <class T>
void binaryTree<T>::delRight(T x)
{
    Node *tmp = find(x,root);
    if(tmp == NULL) return;
    clear(tmp->right);
}

template <class T>
void binaryTree<T>::preOrder(binaryTree<T>::Node *t) const
{
    if(t == NULL) return;
    cout<<t->data<<' ';
    preOrder(t->left);
    preOrder(t->right);
}

template <class T>
void binaryTree<T>::preOrder() const
{
    cout<<"\n 前序遍历:";
    preOrder(root);
}

template <class T>
void binaryTree<T>::postOrder(binaryTree<T>::Node *t) const
{
    if(t == NULL) return;
    postOrder(t->left);
    postOrder(t->right);
    cout<<t->data<<' ';
}

template <class T>
void binaryTree<T>::postOrder() const
{
    cout<<"\n 后序遍历:";
    postOrder(root);
}

template <class T>
void binaryTree<T>::midOrder(binaryTree<T>::Node *t) const
{
    if(t == NULL) return;
    midOrder(t->left);
    cout<<t->data<<' ';
    midOrder(t->right);
}

template <class T>
void binaryTree<T>::midOrder() const
{
    cout<<"\n 中序遍历:";
    midOrder(root);
}




#endif // EX_H_INCLUDED
