#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insertion_at_last_position(struct node*head,int value);
void display (struct node *head);
int count(struct node*head);
void insertion_sepcific_position(struct node *head,int vv,int pp);
void deletion(struct node *head, int pp);
void liner_search(struct node *head, int vv);
int main()
{int n,i,c,v,p,q;
struct node *list;
list=(struct node *) malloc(1*sizeof(struct node));
list->data=0;
list->next=NULL;
    while(1)
    {

          printf("\n........menu........");
          printf("\npress 0 for quit");
          printf("\npress 1 for insertion at last position");
          printf("\npress 2 for specific position");
          printf("\npress 3 for display");
          printf("\npress 4 for deletion from specific position");
          printf("\npress 5 for count node");
          printf("\npress 6 for liner search\n");
          printf("\nEnter Your Choice\n");
          scanf("%d",&c);
            switch(c)
            {
               case 0: exit(0);
                       break;
               case 1:printf("\nchoice=insertion at last position\n");
                      printf("\nEnter value\n");
                      scanf("%d",&v);
                      insertion_at_last_position(list,v);
                      break;
                case 2:printf("\nchoice=insertion specific position\n");
                       printf("\nEnter value\n");
                       scanf("%d",&v);
                       if(list->next!=NULL)
                       {
                           printf("\nenter position between %d to %d\n",1,count(list));
                           scanf("%d",&p);
                           if(p>=1 && p<=count(list)){
                            insertion_specific_position(list,v,p);
                           }
                           else{
                                printf("\n invalid position\n");

                           }
                       }
                          else
                            printf("\n please initialize the list first\n");
                            break;
               case 3: printf("\nchoice display\n");
                       if(list->next!=NULL)
                       display(list);
                       else
                        printf("\n no information to display\n");

                       break;
               case 4:  printf("\nchoice=deletion from specific position");
                        n=count(list);
                        if(n!=0)
                           {
                              printf("\nenter position between %d to %d\n ",1,n);
                              scanf("%d",&p);
                              if(p>=1 && p<=n)
                              deletion(list,p);
                              else {
                                  printf("\n wrong position");
                                   }
                           }
                           else
                            printf("\n The list is empty\n");
                           break;
               case 5:printf("\nchoice= count node/n");
                      n=count(list);
                      printf("\n Total node=%d",n);
                      break;
               case 6:  printf("\nchoice=linear search");
                        printf("\nenter search value\n");
                        scanf("%d",&v);
                        if (count(list)==0)
                           printf("\nlist is empty\n");
                        else
                            linear_search(list,v);
                            break;

               default:
                    printf("\n wrong choice\n");
                    break;




            }
    }
return 0;
}
void linear_search(struct node *head,int vv){
    int ct = 0, ck = 0;
    struct node *temp = head;
    temp = temp->next;
    while(temp->next!=NULL){
        ck++;
        if(temp->data == vv){
            ct++;
            printf("Fount at: %d\n",ck);
        }
        temp = temp->next;
    }
    if(ct==0)
        printf("Not Found!");
    else
        printf("Total Found: %d\n",ct);

}
void insertion_at_last_position(struct node*head,int value)
{
    struct node*temp;
    while(head->next!=NULL)
        head=head->next;
    temp=(struct node*)malloc(1*sizeof(struct node));
    temp->data=value;
    temp->next=head->next;
    head->next=temp;
}
void display(struct node*head)
{
    while (head->next!=NULL)
    {
        printf("\t %d \t",head->next->data);
        head=head->next;
    }
}
int count (struct node*head)
{
    int t=0;
    while (head->next!=NULL)
    {
        t=t+1;
        head=head->next;
    }
    return t;


}
void insertion_specific_position(struct node *head,int vv,int pp)
{
    int i=0;
    struct node*temp;
    while(head->next!=NULL)
    {
        if(i==pp-1)
            break;
        head=head->next;
        i++;
    }
    temp=(struct node*)malloc(1*sizeof(struct node));
    temp->data=vv;
    temp->next=head->next;
    head->next=temp;
}
void deletion (struct node *head,int pp)
{
     int i;
    for(i=0;i<pp-1;i++)
    head=head->next;
    struct node *del =head->next;
    head->next=head->next->next;
    printf("\n deleted successfully\n");
    del->next=NULL;
    free(del);
}
