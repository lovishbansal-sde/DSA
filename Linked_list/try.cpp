#include <bits/stdc++.h>
using namespace std;
//#define OJ freopen("E:/DS ALGO/Programing Question/input.txt", "r",stdin);  freopen("E:/DS ALGO/Programing Question/output.txt", "w",stdout);
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
// #define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

class node{
    public:
    int data;
    node* next;
    node(){};
    node(int d)
    {
        data=d;
        next=NULL;
    }
};
void insert(node*&head,int data)
{
    if(head==NULL)
    {
        node*n =new node(data);
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node*n =new node(data);
    temp->next=n;
    return;
}
void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}

node* even_after_odd(node* head)
{
    if(head==NULL or head->next==NULL)
    {
        return head;
    }

    node*newnode=even_after_odd(head->next);
    
    if((head->data%2)==0)
    {
        node*temp=newnode;

        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=head;
        temp->next->next=NULL;
        return newnode;
    }
    else{
        head->next=newnode;
        return head;
    }
}
int32_t main(){
    int n;
    cin>>n;
    node*head=NULL;
    while(n--)
    {
        int a;
        cin>>a;
        insert(head,a);
    }
    // print(head);
    // node* temp=kth_node_from_last(head,2);
    // cout<<temp->data;
    print(even_after_odd(head));
}
// #include<iostream>
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
