/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *link;
};
Node *head=NULL;
void insertEnd(int d){
    Node *ptr=new Node();
    ptr->data=d;
    ptr->link=NULL;
    if(head==NULL){
        head=ptr;
    }
    else{
        Node *temp=new Node();
        while(temp->link!=NULL){
            temp=temp->link;
        }
        
    }
    
}
void deleteEnd(){
    Node *ptr,*prev;
    if(head==NULL){
        cout<<"List is empty";
    }
    else{
        if(head->link=NULL){
            ptr=head;
            head=NULL;
            free(ptr);
        }
        else{
            ptr=head;
            while(ptr->link!=NULL){
                prev=ptr;
                ptr=ptr->link;
                
            }
            prev->link=NULL;
            free(ptr);
            
        }
        
    }
    
    
}
void showMid(){
    Node *slow=head;
    Node *fast=head;
    if(head==NULL){
        cout<<"list is empty";
    }
    else{
        while(fast!=NULL&&fast->link!=NULL){
            slow=slow->link;
            fast=fast->link->link;
        }
        cout<<"middle element is:"<<slow->data;
    }
    
}
void reverseList(){
    Node *pre,*current,*next;
    pre=NULL;
    current=head;
    while(current!=NULL){
        
        next=current->link;
        current->link=pre;
        pre=current;
        current=next;
    }
    head=pre;
    
    
}
void deleteNode(Node *ptr){
    Node *temp;
    temp=ptr->link;
    ptr->data=temp->data;
    ptr->link=temp->link;
    free(temp);
}
int main()
{
    Node *ptr=new Node();
    ptr->data=3;
    head=ptr;
    ptr->link=NULL;

    return 0;
}
