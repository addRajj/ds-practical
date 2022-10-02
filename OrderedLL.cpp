#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }

};
void insertathead(node* &head , int val)
{
    node* newnode=new node(val);
    newnode->next=head;
    head=newnode;
}
int sizee(node* head)
{
    node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
void insertinll(node* &head , int val)
{
   
    node* newnode=new node(val);
    node* temp=head;
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    else if(head->data<val && sizee(head)==1)
    {
        node* ll1=head->next;
        head->next=newnode;
        newnode->next=ll1;
        return;
    }
    else if(head->data>val )
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        while( temp->next!=NULL && temp->next->data < val)
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            temp->next=newnode;
        }
        else
        {
            node* ll=temp->next;
            temp->next=newnode;
            newnode->next=ll;
        }
    }

}
void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    
}
int main()
{
    node* root=new node(10);
    insertinll(root , 20);
    insertinll(root , 15);
    insertinll(root , 3);
    insertinll(root , 30);
    display(root);
}