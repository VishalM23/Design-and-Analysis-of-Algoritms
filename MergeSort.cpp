//Design and analysis of Mergesort(Divide and Conquer)
#include <iostream>
#include<cstdlib>

int count=0;//For complexity analysis

using namespace std;

void mergearr(int a[],int l,int m,int r)
{
    int i,j,k=l,n1=m-l+1,n2=r-m;
    int l1[n1],r1[n2];//Temporary arrays
    for(i=0;i<=(m-l);i++)
        l1[i]=a[k++];
    for(i=0;i<(r-m);i++)
        r1[i]=a[k++];
    i=j=0,k=l;
    while(i<n1&&j<n2)//Merging in sorted order
    {
        if(l1[i]<=r1[j])
            a[k++]=l1[i++];
        else
            a[k++]=r1[j++];
        count++;
    }
    //Inserting remnant sorted elements in the original array
    while(i<n1)
    {
        a[k++]=l1[i++];
        count++;
    }
    while(j<n2)
    {
        a[k++]=r1[j++];
        count++;
    }
}
void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2; //In every recursive trace, its important to perform (r-l) otherwise get ready to face segmentation fault ;)
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        mergearr(a,l,m,r);
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
        mergesort(A,1,i);   //Either best/worst case
        c1=count;
        count=0;
        mergesort(B,1,i);   //Either best or worst case
        c2=count;
        count=0;
        mergesort(C,1,i);   //Random input
        c3=count;
        cout<<i<<"\t"<<c1<<"\t"<<c2<<"\t"<<c3<<"\n";
    }
}
