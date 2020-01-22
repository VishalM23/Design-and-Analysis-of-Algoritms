//lLab Program 2: QuickSort(Divide and Conquer)
#include <iostream>
#include <cstdlib>
int count=0;
using namespace std;


void Swap(int *p,int *q)   // Typical swap function
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}

int partion(int a[],int l,int h)
{
    int i=l+1,j=h;   // As it is known that first index will get incremented no matter what, we start from incremented lower index
    while(i<j)
    {
        while(a[i]<=a[l] && i<=h) // i<=h must be checked, though it may not give segmentation fault, time complexity is not justified
        {
            i++;
            count++;
        }

        while(a[j]>a[l] && j>=l)
        {
            j--;
            count++;
        }

        if(i<j)
            {
                Swap(&a[j],&a[i]); // complete partition by swapping pivot
            }
    }

    Swap(&a[j],&a[l]);

    return j;

}

void QuickSort(int a[],int l,int h)
{
    if(l<h)
    {
        int j=partion(a,l,h);
        QuickSort(a,l,j-1);
        QuickSort(a,j+1,h);
    }
}

int main()
{
    int i,j,c1,c2,c3;
    int A[1500],B[1500],C[1500];
    cout<<"Size"<<"\t"<<"A\tB\tRandom\n";
    for(i=16;i<1000;i*=2)
    {
        for(j=1;j<=i;j++)
        {
            A[j]=j;
            B[j]=i-j+1;
            C[j]=(rand()%i)+1;
        }
        count=0;
        QuickSort(A,1,i);   //Either best/worst case
        c1=count;
        count=0;
        QuickSort(B,1,i);   //Either best or worst case
        c2=count;
        count=0;
        QuickSort(C,1,i);   //Random input
        c3=count;
        cout<<i<<"\t"<<c1<<"\t"<<c2<<"\t"<<c3<<"\n";
    }
}
