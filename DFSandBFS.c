#include<stdio.h>
#include<stdlib.h>
int a[100][100],visited[100],n;

void dfs(int i)
{
    int j;
    printf("\n%d",i);
    visited[i]=1;
    for(j=0;j<n;j++)
    {
        if(!visited[j]&&a[i][j]==1)
            dfs(j);
    }
}
void bfs(int i)
{
    int q[100],f=0,r=-1,j,k;
    printf("\n%d",i);
    visited[i]=1;
    q[++r]=i;
    while(f<=r)
    {
        k=q[f++];
        for(j=0;j<n;j++)
        {
            if(a[k][j]==1&&visited[j]==0)
            {
                q[++r]=j;
                visited[j]=1;
                printf("\n%d",j);
            }
        }
    }

}

void main()
{

    int i,j,com=0,x;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter Adjacency matrix:");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[i][j]==1)
                a[j][i]=1;
    for(i=0;i<n;i++)
        visited[i]=0;
    printf("1.DFS\n2\nBFS\nEnter your choice:");
    scanf("%d",&x);
    switch(x)
    {
        case 1: for(i=0;i<n;i++)
                {
                    if(visited[i]==0)
                    {
                        dfs(i);
                        com++;
                    }
                }
                if(count==1)
                    printf("Graph is Connected");
                else
                    printf("\nGraph is not connected and the number of components: %d",com);
                break;

        case 2: for(i=0;i<n;i++)
                {
                    if(visited[i]==0)
                    {
                        bfs(i);
                        com++;
                    }
                }
                if(count==1)
                    printf("Graph is Connected");
                else
                    printf("\nGraph is not connected and the number of components: %d",com);
                break;
    }


}

