#ifndef EX_H_INCLUDED
#define EX_H_INCLUDED

#include <iostream>

using namespace std;

template <class T>
class dynamicSearchTable
{
public:
    virtual T find(const T &x) const = 0;
    virtual void insert(const T &x) = 0;
    virtual void remove(const T &x) = 0;
    virtual ~dynamicSearchTable() {};
};

template <class T>
class BinarySearchTree: public dynamicSearchTable<T>
{
public:
    struct BinaryNode
    {
        T data;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode( const T& thedata, BinaryNode *lt=NULL, BinaryNode *rt=NULL )
        : data( thedata ), left( lt ), right( rt ) { }
    };
    BinaryNode *root;
public:
    BinarySearchTree( ) ;
    ~BinarySearchTree( );
    T find(const T &x) const ;
    void insert( const T & x );
    void remove( const T & x );
private:
    void insert( const T & x, BinaryNode * & t );
    void remove( const T & x, BinaryNode * & t );
    T find(const T &x, BinaryNode *t ) const;
    void makeEmpty( BinaryNode *t );


    //作业函数
public:
    bool isOrder();
    void delHigh(const T & x);
    void delLow (const T & x);
    void delRange(const T & low,const T & high);
    int  height(const T & x);
    T max();
    T min();
    bool maxi(int i,T & x);
    bool mini(int i,T & x);
private:
    bool isOrder(BinaryNode * & t);
    void delHigh(const T & x,BinaryNode * & t);
    void delLow (const T & x,BinaryNode * & t);
    void delRange(const T & low,const T & high,BinaryNode * & t);
    int height(const T & x,const BinaryNode * t);
    bool maxi(int i,T & x,BinaryNode * & t);
    bool mini(int i,T & x,BinaryNode * & t);
    int size(BinaryNode *t);
};


    //第一题，检查有序性
template <class T>
bool BinarySearchTree<T>::isOrder()
{
    return isOrder(root);
}

template <class T>
bool BinarySearchTree<T>::isOrder(BinaryNode * & t)
{
    if(t=NULL)
        return true;
    if(t->left->data < t->data && t->right->data > t->data)
    {
        return isOrder(t->left);
        return isOrder(t->right);
    }
    else return false;
}

    //第二题，删除大于，小于，某一范围值
template <class T>
void BinarySearchTree<T>::delHigh(const T & x)
{
    delHigh(x,root);
}

template <class T>
void BinarySearchTree<T>::delHigh(const T & x,BinaryNode *&t)
{
    if(t->data >= x)
    {
        makeEmpty(t);
        return ;
    }
    else delHigh(x,t->right);
}

template <class T>
void BinarySearchTree<T>::delLow(const T & x)
{
    delLow(x,root);
}

template <class T>
void BinarySearchTree<T>::delLow(const T & x,BinaryNode *&t)
{
    if(t->data <= x)
    {
        makeEmpty(t);
        return ;
    }
    else delLow(x,t->left);
}

template <class T>
void BinarySearchTree<T>::delRange(const T & low,const T & high)
{
    delRange(low,high,root);
}

template <class T>
void BinarySearchTree<T>::delRange(const T & low,const T & high,BinaryNode *&t)
{
    if(t == NULL) return;
    if(t->data > high)
        delRange(low,high,t->left);
    if(t->data < low)
        delRange(low,high,t->right);
    if(t->data >= low && t->data <= high )
    {
        remove(t);
        delRange(low,high,t);
    }
}

    //第五题，返回指定结点深度
template <class T>
int BinarySearchTree<T>::height(const T & x)
{
    return height(x,root);
}

template <class T>
int BinarySearchTree<T>::height(const T & x,const BinaryNode *t)
{
    if(t = NULL)
        return -1;
    if(t -> data == x) return 1;

    int level;
    if(x<t->data) level = height(x,t -> left);
    else level = height(x,t->right);

    return (level == -1 ? -1:level+1);
}


    //第六题，查找最大最小值
template <class T>
T BinarySearchTree<T>:: max()
{
    BinaryNode* t=root;
    while(t->right != NULL) t=t->right;
    return t->data;
}

template <class T>
T BinarySearchTree<T>:: min()
{
    BinaryNode* t=root;
    while(t->left != NULL) t=t->left;
    return t->data;
}

    //第七题，查找第i大值
template <class T>
bool BinarySearchTree<T>:: maxi(int i,T &x)
{
    return maxi(i,x,root);

}

template <class T>
bool BinarySearchTree<T>:: maxi(int i,T &x,BinaryNode * & t)
{
    if(t == NULL) return false;
    int rs = size(t -> right);
    if( rs == i-1)
    {
        x = t -> data;
        return true;
    }
    if( rs >= i)return maxi(i,x,t->right);
    else return maxi(i-rs-1,x,t->left);
}

template <class T>
int BinarySearchTree<T>::size(BinaryNode *t)
{
    if(t == NULL)return 0;
    return 1+size(t ->left) + size(t -> right);
}

    //第八题，查找第i小值
template <class T>
bool BinarySearchTree<T>:: mini(int i,T &x)
{
    return mini(i,x,root);

}

template <class T>
bool BinarySearchTree<T>:: mini(int i,T &x,BinaryNode * & t)
{
    if(t == NULL) return false;
    int ls = size(t -> left);
    if( ls == i-1)
    {
        x = t -> data;
        return true;
    }
    if( ls >= i) return mini(i,x,t->left);
    else return mini(i-ls-1,x,t->right);
}






template <class T>
T BinarySearchTree<T>::find( const T &x ) const
{
    return find( x, root );
}

template <class T>
T BinarySearchTree<T>::find( const T & x, BinaryNode *t ) const
{
    if(t == NULL)
        return 0;
    if ( t->data == x )
        return  t->data;
    if( x < t->data ) return find( x, t->left );
    else return find( x, t->right );
}

template <class T>
void BinarySearchTree<T>::insert( const T & x )
{
    insert( x, root );
}

template <class T>
void BinarySearchTree<T>::insert( const T & x, BinaryNode *&t )
{
    if( t == NULL )
    t = new BinaryNode( x, NULL, NULL );
    else if( x < t->data )
    insert( x, t->left );
    else if( t->data < x )
    insert( x, t->right );
}

template <class T>
void BinarySearchTree<T>::remove( const T & x )
{
    remove( x, root );
}

template <class T>
void BinarySearchTree<T>::remove( const T & x, BinaryNode * & t )
{
    if( t == NULL ) return;

    if ( x < t->data ) remove( x, t->left );
    else if( t->data < x ) remove( x, t->right );
            else if( t->left != NULL && t->right != NULL )
            {
                BinaryNode *tmp = t->right;
                while (tmp->left != NULL) tmp = tmp->left;
                t->data = tmp->data;
                remove( t->data, t->right );
            }
                    else
                    {
                        BinaryNode *oldNode = t;
                        t = ( t->left != NULL ) ? t->left : t->right;
                        delete oldNode;
                    }
}

template <class T>
BinarySearchTree<T>::BinarySearchTree ()
{
    root=NULL;
}

template <class T>
void BinarySearchTree<T>::makeEmpty(BinaryNode* t)
{
    if(t==NULL) return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree ()
{
    makeEmpty(root);
}

#endif // EX_H_INCLUDED
