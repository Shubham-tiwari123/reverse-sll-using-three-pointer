#include <iostream>
using namespace std;
class linklist{
    struct node{
        int data;
        node *next;
    };
    node *start,*temp,*newnode,*second,*third,*start1;
    int data1,num,num1;
public:
    linklist(){
        start = NULL;
        start1 = NULL;
    }
    void enter();
    void display();
    void reverse_list();
};
void linklist::enter(){
    cout<<"Enter the number of nodes:-";
    cin>>num;
    for(int i=0;i<num;i++){
        cout<<"\nEnter the data:-";
        cin>>data1;
        if(start == NULL){
            start = new node;
            start->data = data1;
            start->next = NULL;
        }
        else{
            temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }
            newnode = new node;
            newnode->data = data1;
            newnode->next = NULL;
            temp->next = newnode;
        }
    }
}
void linklist::display(){
    temp = start;
    while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
}
void linklist::reverse_list(){
    if(num>3){
        start1 = start;
        second = start1->next;
        third = second->next;
        start1->next=NULL;
        second->next=start1;

        while(third->next!=NULL){
            start1 = third;
            third=third->next;
            start1->next=second;
            second=start1;
        }
        if(third->next==NULL){
            third->next=start1;
        }
        temp = third;
        cout<<"\nAfter reversing:-"<<endl;
        while(temp!=NULL){
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
    else if(num == 3){
        start1 = start;
        second = start1->next;
        third = second->next;
        third->next = second;
        second->next = start1;
        start1->next = NULL;
        temp = third;
        cout<<"\nAfter reversing:-"<<endl;
        while(temp!= NULL){
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
    else if(num == 2){
        start1 = start;
        second = start1->next;
        second->next = start1;
        start1->next = NULL;
        temp = second;
        cout<<"\nAfter reversing:-"<<endl;
        while(temp!= NULL){
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
     else if(num == 1){
         temp = start;
         cout<<"\nAfter reversing:-"<<endl;
         cout<<temp->data<<"\t";
     }
}
int main()
{
    linklist l;
    l.enter();
    l.display();
    l.reverse_list();
}
