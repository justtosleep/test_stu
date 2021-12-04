#ifndef EX_H_INCLUDED
#define EX_H_INCLUDED

#include <iostream>

using namespace std;

template<class T>
class ex
{
public:
    //第一题（包括快速排序的实现）
    int deleteRepeat(T a[], int size);
    void quickSort(T a[], int size);
    void quickSort(T a[], int low, int high);
    int divide( T a[], int low, int high);

    //第二题 二分排序法
    void halfSort(T a[],int size);

    //第四题
    void digitalSort(int a[],int size);

    //第十题
    void norepeatSort(int a[],int size);

};


//第一题
template <class T>
int ex<T>::deleteRepeat(T a[], int size)
{
    quickSort(a,size);

    int i,j;
    for(i = 1,j = 0; i < size; ++i)
        if(a[i]!=a[j]) a[++j]=a[i];
    return j+1;
}

template <class T>  //快速排序的实现
void ex<T>::quickSort(T a[], int size)
{
    quickSort(a, 0, size-1);
}

template <class T>
void ex<T>::quickSort(T a[], int low, int high)
{
    int mid;
    if (low >= high) return;
    mid = divide(a, low, high);
    quickSort( a, low, mid-1);
    quickSort( a, mid+1, high);
}

template <class T>
int ex<T>::divide( T a[], int low, int high)
{
    T k = a[low];
    do
    {
        while (low < high && a[high] >= k) --high;
        if (low < high) { a[low] = a[high]; ++low;}
        while (low < high && a[low] <= k) ++low;
        if (low < high) {a[high] = a[low]; --high;}
    } while (low != high);
    a[low] = k;
    return low;
}

//第二题
template <class T>
void ex<T>::halfSort(T a[],int size)
{
    int i, j, k, mid;

    T tmp;
    for(k = 1; k < size; ++k)
    {
        i=0;
        j=k-1;
        while(i <= j)
        {
            mid = (i+j)/2;
            if(a[k] == a[mid]) break;
            if(a[k] < a[mid] ) j=mid - 1;
            else i=mid + 1;
        }

        if(a[k] < a[mid]) i=j;

        tmp = a[k];
        for(;k > i;--k) a[k] == a[k-1];
            a[i] = tmp;
    }

}

//第四题
template <class T>
void ex<T>::digitalSort(int a[],int size)
{
    int tmp;
    int low = 0;
    int high = size - 1;

    while(low < high)
    {
        while(low < high && a[low] < 0) ++low;
        while(low < high && a[high]> 0) -- high;
        if( low < high)
        {
            tmp = a[low];
            a[low] = a[high];
            a[high] = tmp;
        }
    }
}

//第十题
template <class T>
void ex<T>::norepeatSort(int a[],int size)
{
    int tmp,i;

    for(i = 0; i < size; i++)
    {
        if(a[i] = i) continue;
        else
        {
            tmp = a[i];
            a[i] = a[tmp];
            a[tmp] = a[i];
        }
    }
}


#endif // EX_H_INCLUDED
