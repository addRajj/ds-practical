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
void insertattail(node* &head, int val)
{
    node* newnode=new node(val);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void remove(vector<int>&v, int target)
{
    v.erase(remove(v.begin(), v.end(), target), v.end());
}
void display(node* root)
{
    node* temp=root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    node* head=new node(1);
    insertathead(head  , 2);
    insertattail(head, 3);
    insertathead(head , 3);
    vector<int>v;
    node* temp=head;
    while(temp!=NULL)
    {
        v.push_back(temp->data);
        temp=temp->next;
    }
    
    cout<<"before deleation the Linked list is : "<<endl;
    display(head);
    cout<<endl;
    cout<<"enter the element, you want to delete all occurences  of :"<<endl;
    int a;
    cin>>a;
    cout<<"after deleation of all occurences of"<<a<<" we have Linked List as: "<<endl;
    remove(v, a);
    node* head1=new node(0);
    while(v.size()!=0)
    {
        insertattail(head1 , v[0]);
        v.erase(v.begin()+0);
    }
    display(head1->next);

}