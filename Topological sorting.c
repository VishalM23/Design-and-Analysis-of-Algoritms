#include<stdio.h>
#include<stdlib.h>
int visited[10],count=0,pre[10],post[10],a[10][10],n,result[10],p;

void topological_sort(int i)
{
    int j;
    visited[i] = 1;
    pre[i]=count++;

    for(j=0;j<n;j++)
    {
        if(a[i][j]==1&&visited[j]==0)
        {
            topological_sort(j);
        }
    }
    post[i]=count++;
    result[p--]=i;
}

int main(){
    int i,j,indegree[10],temp_count=0;
    printf("\nEnter n: ");
    scanf("%d",&n);
    p=n-1;
    printf("Enter the adjacency matrix of DAG: \n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    for(i=0;i<n;i++)
        visited[i]=indegree[i]=0;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[j][i]==1)
                indegree[i]++;

    for(i=0;i<n;i++)
        if(indegree[i]==0)
            count++;

    if(count==0)
    {
        printf("Graph has a cycle");
        exit(0);
    }

    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            topological_sort(i);
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",result[i]);
    }
    return 0;
}
