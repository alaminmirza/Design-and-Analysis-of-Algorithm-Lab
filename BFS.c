#include<stdio.h>

int a[20][20],q[20],visited[20],n,f=-1,r=-1;

void bfs(int v)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[v][i]!=0 && visited[i]==0)
        {
            r=r+1;
            q[r]=i;
            visited[i]=1;
            printf("%d",i);

        }
    }
    f=f+1;
    if(f<=r)
        bfs(q[f]);
}
 main()
{
    int v,i,j;
    printf("\nEnter The Number of Vertex:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    printf("\nEnter Graph in matrix Form:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    printf("\nEnter Starting vertex:");
    scanf("%d",&v);
    f=r=0;
    q[r]=0;
    printf("\nBFS Traversal is:\n");
    visited[v]=1;
    printf("%d", v);
    //bfs(v);
    if (r!=n-1)
        printf("\n BFS is not possible");
}
