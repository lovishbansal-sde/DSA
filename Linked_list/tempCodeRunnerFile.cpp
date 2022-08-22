#include<iostream>
// #include<algorithm>
// using namespace std;
// class node{
// public:
//     int data;
//     node* next;
// };
// void insertdata(node*&head,int data)
// {
//     if(head==NULL)
//     {

//         node*temp=new node();
//         temp->next=head;
//         temp->data=data;
//         head=temp;
//     }
//     else 
//   {
//     node*temp=new node();
//     temp=head;
//     while(temp->next!=NULL)
//     {
//         temp=temp->next;
//     }
//     node*n=new node();
//     n->next=temp->next;
//     temp->next=n;
//     n->data=data;
//   }

// }
// node* evenafterodd_usingrecursion(node*head)
// {
//     if(head==NULL or head->next==NULL)
//     {
//         return head;
//     }
//     node *newhead=evenafterodd_usingrecursion(head->next);
//     if((head->data%2)==0)
//     {
//         node*temp=newhead;
//         while(temp->next!=NULL)
//         {
//             temp=temp->next;
//         }
//        temp->next=head;
//        head->next=NULL; 
//        head=newhead;
//     }
//     else
//     {
//         head->next=newhead;
//     }
// }
// node*evenafterodd(node*head)
// {
//     node*oddhead=NULL;
//     node*evenhead=NULL;
//     node*temp=head;
//     while(temp!=NULL)
//     {
//         if((temp->data%2)==0)
//         {
//             insertdata(evenhead,temp->data);
//         }
//         else 
//         {
//             insertdata(oddhead,temp->data);
//         }
//         temp=temp->next;
//     }
//     if(oddhead==NULL)
//         return evenhead;
//     else {
//         temp=oddhead;
//         while(temp->next!=NULL)
//         {
//             temp=temp->next;
//         }
//         temp->next=evenhead;
//         return oddhead;
//     }
// }
