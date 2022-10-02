#include<bits/stdc++.h>
using namespace std;
#define sizee 6
int arr[sizee];
int front=-1;
int rear=-1;

void enqueu(int val)
{
    if(front==-1 && rear==-1)
    {
        rear++;
        front++;
        arr[rear]=val;
    }
    else if(((rear+1)%sizee)==front)
    {
        cout<<"Can't add any-more element , Overflow"<<endl;
        return ;
    }
    else
    {
        rear=(rear+1) % sizee;
        arr[rear]=val;
    }
}
void  dequeue()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Underflow Condition"<<endl;
        return ;
    }
    else if(front==rear)
    {
        cout<<arr[front];
        front=-1;
        rear=-1;
    }
    else
    {
        cout<<arr[front];
        front=(front+1)%sizee;
    }
}
void display()
{
    if(front==-1 && rear==-1)
    {
        cout<<"The Circular queue is empty";
    }
    else
    {
        for(int i=front ; i<=rear;)
        {
            cout<<arr[i]<<" ";
            i=(i+1)%sizee;
        }
    }
}
int main()
{   
    enqueu(10);
    enqueu(20);
    enqueu(30);
    enqueu(40);
    dequeue();
    cout<<endl;
    display(); 
}