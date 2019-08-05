#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct node
{ int x;
int y;
struct node*next;};

int print(struct node*head)
{if(head==NULL)
{cout<<"No element in list"<<endl;
return(0);}
while(head!=NULL)
{cout<<"("<<head->x<<","<<head->y<<")"<<endl;
head=head->next;}}

void add(struct node**head,int a,int b)
{struct node *c=new node();
if(*head==NULL)
{
c->x=a;
c->y=b;
c->next==NULL;
*head=c;
}
else
{c->x=a;
c->y=b;
c->next=*head;
*head=c;}}

int delf(struct node **head)
{struct node *a;
    if(*head==NULL)
{cout<<"Can not delete the node"<<endl;
return(0);}
else
{a=*head;
*head=a->next;
free(a);}}

int del(struct node **head,int a,int b)
{struct node* c=*head;
if(c->x=a&&c->y==b)
{*head=c->next;
free(c);
     return(0);
}
else
{
     struct node *prev=*head;
     c=c->next;
    while(c!=NULL)
{
if(c->x==a&&c->y==b)
{prev->next=c->next;
struct node* temp=c;
c=c->next;
free(temp);
    return(0);
}
else
{prev=c;
 c=c->next;}
  
}
      if(c==NULL)
    return(-1);
}}

int search(struct node*head,int d)
{struct node*a;
    if(head==NULL)
return(0);
else
{while(head!=NULL)
{int a=head->x,b=head->y;
if((a*a+b*b)<=d*d)
cout<<"("<<a<<","<<b<<")"<<" ";
    head=head->next;
}cout<<endl;}}

int srch(struct node*head,int a,int b)
{if(head==NULL)
{cout<<"False"<<endl;
return(0);}
else
{while(head!=NULL)
{if(head->x==a&&head->y==b)
{cout<<"True"<<endl;
return(1);}
     head=head->next;
}
if(head==NULL)
cout<<"False"<<endl;
return(0);
}}

int length(struct node*head)
{int c=0;
if(head==NULL)
return(0);
else
{while(head!=NULL)
{c++;
head=head->next;}}
return(c);}


int main()
{struct node *head=NULL;
long long int t,i,c,d,x;
cin>>t;
for(i=0;i<t;i++)
{cin>>x;
if(x==1)
{cin>>c>>d;
add(&head,c,d);}
if(x==2)
{delf(&head);}
if(x==3)
{int j;
cin>>c>>d;
j=del(&head,c,d);
cout<<j<<endl;}
if(x==4)
{cin>>c;
search(head,c);}
if(x==5)
{cin>>c>>d;
srch(head,c,d);}
if(x==6)
{c=length(head);
cout<<c;}}
}
