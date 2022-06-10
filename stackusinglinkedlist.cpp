#include <bits/stdc++.h>
using namespace std;
 
 int j=0;
 int size=7;
// Declare linked list node
 
struct Node
{
    int data;
    struct Node* next;
};
 
struct Node* head;
 void display()
{
    struct Node* temp;
    if (head == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
    }
}
 
// data in the stack insert at the beginning
void push(int data)
{
     
    struct Node* temp;
    temp = new Node();
    if (!temp)
    {
        cout << "\nHeap Overflow";
        exit(1);
    }

    temp->data = data;
    temp->next = head;
    head = temp;
    j++;
}
// the stack is empty or not
int isEmpty()
{
    return head==NULL;
}
 
//function to return top element in a stack
void peek()
{
    if (!isEmpty())
        cout<<head->data;
    else
        exit(1);
}
 
// function to remove or pop the topmost element in the stack

void pop()
{
    struct Node* temp;
    if (head == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {
        temp = head;
        head= head->next;
        temp->next= NULL;
        free(temp);//delete the node
    } 
    j--;
}
 
// Function to print all the
// elements of the stack

 bool isFull(){
     if(j==size-1)
       cout<<"Stack is full";
       return true;
     else
        cout<<"stack is not full";
        return false;
 }
// Driver Code
int main()
{ 
    int k,n;
  
    char ch;
   do{
     cout<<"what do you want to do"<<endl;
     cout<<"1)push"<<endl;
     cout<<"2)pop"<<endl;
     cout<<"3)peek"<<endl;
     cout<<"4)isEmpty"<<endl;
     cout<<"5)isFull"<<endl;
     cout<<"6)display"<<endl;
     cout<<"enter choice:";
     cin>>k;
     switch(k){
         case 1:if(isFull()){
                   cout<<"push is not possible";
                   exit(1);
                }
                 int t;
                cin>>t;
                push(t);
                break;
         case 2:pop();
                break;
         case 3:peek();
                break;
         case 4:isEmpty();
                break;
         case 5:isFull(j);
                break;
         case 6:display();
                break;
         default:cout<<"Invalid Choice";                                 
     }
     cout<<"do you want to continue y/n";
     cin>>ch;
    }while(ch=='y'||ch=='Y');
    return 0;
}
 