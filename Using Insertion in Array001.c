#include <stdio.h>
#include<stdlib.h>
void display(int b[], int k);
int Insert_Last(int b[], int k, int m);
int Insert_sp_position(int b[],int k,int m,int q);
int deletion (int b[], int k,int q);
void bubble_sort (int b[],int k);
void Linear_search(int b[],int k,int q);
void Binary_search(int b[], int k, int q);
int main()
{
    int n,a[100],i,c,v,p,q;
    printf("Enter the number of values ");
    scanf("%d",&n);
    printf("\nEnter values:\n");
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);

    while(1)
    {

           printf("\n........menu.......");
           printf("\npress 0 for quit");
           printf("\npress 1 for insertion at last position");
           printf("\npress 2 for specific insertion");
           printf("\npress 3 for display");
           printf("\npress 4 for deletion from specific position");
           printf("\npress 5 for linear search ");
           printf("\npress 6 for bubble sort ");
           printf("\npress 7 for binary search ");




           printf("\nenter your choice\n");
                 scanf("%d",&c);
                 switch(c)
                 {
                    case 0: exit(0);
                            break;

                    case 1:printf("\nchoice=insertion at last position");
                           printf("\nenter new value\n");
                           scanf("%d", &v);
                           n=Insert_Last (a,n,v);
                           break;

                    case 2: printf("\nchoice=insertion specific position");
                            printf("\nenter value\n");
                            scanf("%d",&v);
                            printf("\nenter position between %d to %d\n",1,n+1);
                            scanf("%d",&p);
                            if (p>=1 && p<=n+1)
                            n= Insert_sp_position(a,n,v,p);
                            else
                            {
                                printf("\n wrong position");
                            }
                            break;

                    case 3: printf("\nchoice display\n");
                            if(n!=0)
                                display(a,n);
                            else
                                printf("\n no data to display\n");
                            break;

                    case 4: printf("\nchoice=deletion from specific position");
                            if(n!=0)
                           {
                              printf("\nenter position between %d to %d\n ",1,n);
                              scanf("%d",&p);
                              if(p>=1 && p<=n)
                                n=deletion(a,n,p);
                              else {
                                  printf("\n wrong position");
                                   }
                           }
                           else
                            printf("\n no data to delete\n");
                           break;
                   case 5: printf("\nchoice=linear search");
                           printf("\nenter the value for searching\n");
                           scanf("%d",&v);
                           Linear_search(a,n,v);
                           break;
                   case 6: printf("\nchoice=bubble sort");
                           bubble_sort(a,n);
                           break;
                   case 7:printf("\nchoice=binary search");
                          printf("\n enter value for searching\n");
                          scanf("%d",&v);
                          Binary_search(a,n,v);
                          break;

                    default:
                           break;
                    }
       }


return 0;

}
void display (int b[], int k )
{
    int j;
    for (j=1;j<=k;j++)
        printf("%d ", b[j]);
}
int Insert_Last (int b[], int k, int m )
{
    b[k+1]=m;
    printf("\ninserted successfully\n");
    return k+1;
}
int Insert_sp_position(int b[],int k,int m,int q)
{
    int j;
    for (j=k;j>=q;j--)
    b[j+1]=b[j];
    b[q]=m;
    printf("\ninserted successfully\n");
    return k+1;
}
int deletion (int b[],int k,int q)
{
     int i;
    for (i=q;i<k;i++)
    b[i]=b[i+1];
    printf("\n deleted successfully\n");
    return k-1;
}
void Linear_search(int b[],int k,int q)
{
    int i,c=0;

    for(i=1;i<=k;i++)
    {
        if(q==b[i])
        {
            printf("\n found at position%d\n",i);
            c=c+1;
        }
        if(c==0)
            printf("\n not found\n");
        else
            printf("\n total found=%d\n",c);
    }
}
void bubble_sort (int b[], int k)
{
    int i,j,t;
    for (i=1;i<=k;i++)
    {
        for (j=1;j<=k-i;j++)
        {
            if(b[j]>b[j+1])
            {
                t=b[j];
                b[j]=b[j+1];
                b[j+1]=t;
            }
        }
    }
    printf("\n sort successfully\n");
}
void Binary_search (int b[], int k, int q)
{
    int beg,end,mid;
    bubble_sort(b,k);
    beg = 1;
    end = k;
    do
    {
        mid=(beg+end)/2;
        if(q<b[mid])
            end=mid-1;
        else if(q>b[mid])
            beg=mid+1;
    }
    while(q!=b[mid] && beg<=end);
    if(q==b[mid])
        printf("\nfound\n");
    else
        printf("\n not found \n");
}
