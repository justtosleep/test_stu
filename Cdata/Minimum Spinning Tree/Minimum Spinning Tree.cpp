 // Add any standard library if needed.
#include <iostream>
using namespace std;
int size1=20;

class MinSpinTree
{
private:
    int **edge;
public:
    MinSpinTree(const int& size=size1);
    ~MinSpinTree();
    void insert();
    void pre();
};

void MinSpinTree::insert()
{
    int i=0,j=0,k=0;
    char* str;
    while (cin.getline(str,100))
    {
        for(j=k=0;str[k]!='\0';k++)
        {
            if(str[k]!=' ')
                edge[i][j++]=str[k]-'0';
        }
        i++;
    }
    
}
void MinSpinTree::pre()
{
    int i=0,j=0;
    for(i=0;i<size1&&edge[i][j]!=-1;i++)
     {
         for(j=0;j<size1&&edge[i][j]!=-1;j++)
            cout<<edge[i][j]<<' ';
        cout<<endl;
     }   
}

MinSpinTree::MinSpinTree(const int& size)
{
    edge=new int*[size];
    int i=0,j=0;
    for(i=0;i<size;i++)
        edge[i]=new int[size];
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            edge[i][j]=-1;
}

MinSpinTree::~MinSpinTree()
{
    int i=0;
    for(i=0;i<size1;i++)
        delete [] edge[i];
    delete []edge;
}



// Test your implementation
int main () {
    MinSpinTree a(5);
    a.insert();
    a.pre();


    return 0;
}