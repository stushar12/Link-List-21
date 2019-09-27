#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
  int data;
  struct node *next;
};
struct node * create()
{
  struct node *temp,*start=NULL,*q,*p,*r,*t;
while(1)
{
char str1[10];
printf("\n Enter yes or no\n");
scanf("%s",str1);
if(strcmp(str1,"no")==0)
break;
else
{
temp=(struct node *)malloc(sizeof(struct node));
printf("Enter a value ");
scanf("%d",&temp->data);
  temp->next=NULL;
  if(start==NULL)
  {
    start=temp;
    p=temp;
    q=temp;
  }
  else
  {
    p->next=temp;
    p=temp;
  }
}
}
return q;
}
struct node *merge(struct node *p,struct node *q)
{
    struct node *temp,*start,*r,*t,*s;
    if(p==NULL)       //if only one element is there in the p list  which is smaller than q's first element
    return q;
    if(q==NULL)       //if only one element is there in the q list  which is smaller than p's first element
    return p;
  if(p->data<=q->data)
  {
    temp=p;
    p=p->next;
  }
  else if (p->data>=q->data)
    {
      temp=q;
      q=q->next;
}
t=temp;
if(p==NULL)
temp->next=q;
else if(q==NULL)
  temp->next=p;
  else
  {
while(p!=NULL&&q!=NULL)
{
if(p->data<=q->data)
{
  temp->next=p;
  temp=p;
  p=p->next;
}
else if(q->data<p->data)
{
  temp->next=q;
  temp=q;
  q=q->next;
}
if(p==NULL)
    temp->next=q;
else if(q==NULL)
    temp->next=p;
}
}
return t;
}
void display(struct node *p)
{
  while(p!=NULL)
  {
    printf("%d ",p->data);
    p=p->next;
  }
}
int main()
{
struct node *p,*q,*r;
p=create();
q=create();
r=merge(p,q);
display(r);
}
