#include<stdio.h>

int a[20][20],q[20],visited[20],n;

void dfs(int v)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[v][i]!=0 && visited[i]==0)
        {
            visited[i]=1;
            printf("%d",i);
            dfs(i);
        }
    }
}
int main()
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
    printf("\nDFS Traversal is:\n");
    visited[v]=1;
    printf("%d", v);
    dfs(v);
}
