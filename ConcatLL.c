#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node* next;
};

void insert(struct node** head);
void del(struct node** head);
struct node* sort(struct node* head);
struct node* rev(struct node* head);
struct node* concat(struct node* head1,struct node* head2);
void dislay(struct node* head);

void insert(struct node** head)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value:");
    scanf("%d",&(newnode->val));
    newnode->next=*head;
    *head=newnode;
}

void del(struct node** head)
{
    if(*head==NULL)
    {
        printf("Empty List");
        return;
    }
    struct node* temp=*head;
    *head=(*head)->next;
    free(temp);
}

struct node* sort(struct node* head)
{
    if(head==NULL || head->next==NULL) return head;
    struct node* temp=head;
    struct node* sorted=NULL;
    while(temp!=NULL)
    {
        struct node* next=temp->next;
        if(sorted==NULL || sorted->val>temp->val)
        {
            temp->next=sorted;
            sorted=temp;
        }
        else
        {
            struct node* prev=sorted;
            while(prev->next!=NULL && prev->next->val<temp->val)
            {
                prev=prev->next;
            }
            temp->next=prev->next;
            prev->next=temp;
        }
        temp=next;
    }
    return sorted;
}

struct node* rev(struct node* head)
{
    struct node* prev=NULL;
    struct node* next=NULL;
    struct node* curr=head;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

struct node* concat(struct node* head1,struct node* head2)
{
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    struct node* temp=head1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head2;
    return head1;
}

void display(struct node* head)
{
    if(head==NULL) printf("Empty list");
    else
    {
        struct node* temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->val);
            temp=temp->next;
        }
    }
}
void main()
{
    struct node* head1=NULL;
    struct node* head2=NULL;
    int o;
    char check='y';
    while(check=='y')
    {
        printf("1:Insert List1 2:Insert List2 3:Delete List1 4:Delete List2-");
        scanf("%d",&o);
        switch(o)
        {
        case 1:
            insert(&head1);
            break;
        case 2:
            insert(&head2);
            break;
        case 3:
            del(&head1);
            break;
        case 4:
            del(&head2);
            break;
        default:
            printf("Wrong option");
        }
        printf("Continue(y/n)-");
        scanf(" %c",&check);
    }

    printf("\nList1-");
    display(head1);

    head1=sort(head1);
    printf("\nNew List1 Sorted-");
    display(head1);

    head1=rev(head1);
    printf("\nNew List1 Reversed-");
    display(head1);

    printf("\nList2-");
    display(head2);

    head2=sort(head2);
    printf("\nNew List2 Sorted-");
    display(head2);

    head2=rev(head2);
    printf("\nNew List2 Reversed-");
    display(head2);

    head1=concat(head1,head2);
    printf("\nConcatenated List-");
    display(head1);


}
