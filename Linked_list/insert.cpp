#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
    node(){}
};

void insert(node *&head,int d)
{
    if(head==NULL)

    
    {
        node*n =new node(d);
        head=n;
    }
    else
    {
        node*temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        node*n =new node(d);
        temp->next=n;
    }
    return;
}
void  print(node* head)
{
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}
void insertathead(node*&head,int k)
{
    node*n=new node(k);
    n->next=head;
    head=n;
    return;
}
void insertatmiddle(int d,int position,node*&head)
{
    int k=1;
    node*temp=head;
    while(k<position-1)
    {
        temp=temp->next;
        k++;
    }
    node*n=new node(d);
    n->next=temp->next;
    temp->next=n;
    // cout<<temp->data<<" ";
}
void deleteat(node*&head,int position,int length)
{
    if(head==NULL) return;
    if(position==1)
    {
        node*temp=head;
        head=head->next;
        delete temp;
        return;
    }
    int k=1;
    node*temp=head;
    while(k<position-1)
    {
        temp=temp->next;
        k++;
    }
    node*n=temp->next;
    temp->next=temp->next->next;
    delete n;
    return;
}
void insertdata(node*&head,int data)
{
    if(head==NULL)
    {

        node*temp=new node();
        temp->next=head;
        temp->data=data;
        head=temp;
    }
    else 
  {
    node*temp=new node();
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node*n=new node();
    n->next=temp->next;
    temp->next=n;
    n->data=data;
  }

}

int linearsearch(node* head,int key)
{
    if(head==NULL) return -1;
    int k=0;
    while(head!=NULL){
        if(head->data==key) 
            return k;
        k++;
        head=head->next;
    }
    return -1;
}
int searchrecursive(node* head,int key)
{
    if(head==NULL) return -1;
    if(head->data==key) return 1;
    else return searchrecursive(head->next,key);
}
void reverse_itrate(node*&head)
{
    node*C=head;
    node*P=NULL;
    node*N;
    while(C!=NULL)
    {
        N=C->next;
        C->next=P;
        P=C;
        C=N;
    }
    head=P;
}
node* reverse_recursive(node*head)
{
    if(head->next==NULL || head==NULL) return head;
    node* new_head=reverse_recursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_head;
}
void kthnode(node*head,int k)
{
    node*slow=head;
    node*fast=head;
    int a=1;
    while(a<k)
    {
        fast=fast->next;
        a++;
    }
    // cout<<fast->data<<"  "
    while(slow->next!=NULL && fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    cout<<slow->data;
    return;
}
node* evenafterodd_usingrecursion(node*head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node *newhead=evenafterodd_usingrecursion(head->next);
    if((head->data%2)==0)
    {
        node*temp=newhead;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
       temp->next=head;
       head->next=NULL; 
       head=newhead;
    }
    else
    {
        head->next=newhead;
    }
}
node*evenafterodd(node*head)
{
    node*oddhead=NULL;
    node*evenhead=NULL;
    node*temp=head;
    while(temp!=NULL)
    {
        if((temp->data%2)==0)
        {
            insertdata(evenhead,temp->data);
        }
        else 
        {
            insertdata(oddhead,temp->data);
        }
        temp=temp->next;
    }
    if(oddhead==NULL)
        return evenhead;
    else {
        temp=oddhead;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=evenhead;
        return oddhead;
    }
}
node* midpoint(node*head)
{
    if(head==NULL && head->next==NULL) return head;
    node*slow=head;
    node*fast=head->next;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node* merge(node*head1,node* head2)
{
    if(head1==NULL)
    return head2;
    if(head2==NULL)
    return head1;
    node*c=new node();
    if(head1->data<head2->data)
    {
        c=head1;
        c->next=merge(head1->next,head2);
    }
    else{
                c=head2;
        c->next=merge(head1,head2->next);
    }
    return c;
}
node* mergesort(node*head)
{
    if(head==NULL || head->next==NULL)
    return head;

    node* mid=midpoint(head);
    node* a=head;
    node* b=mid->next;
    mid->next=NULL;

    a=mergesort(a);
    b=mergesort(b);

    node*c=new node();
    c=merge(a,b);
    
    return c;
}
bool palindrome(node* head)
{
    stack<int> st;
    node*a=head;
    while(a!=NULL)
    {
        st.push(a->data);
        a=a->next;
    }
    while(head!=NULL)
    {
        if(head->data!=st.top())
        return false;
        else{
            st.pop();
            head=head->next;
        }
    }
    return true;
}
int main()
{
    int len,k;
    cin>>len;
    node*head=NULL;
    while(len--)
    {
        cin>>k;
        insert(head,k);
    }
    // print(head);
    cout<<endl;
    // 2nd LinkedList
    // cin>>len;
    // node*head2=NULL;
    // while(len--)
    // {
    //     cin>>k;
    //     insert(head2,k);
    // }
    // print(head2);
    // cout<<endl;
    // print(merge(head,head2));
    node*a=mergesort(head);
    print(a);
    // cout<<endl;
    // cout<<"Enter the element you want to insert at the start  ";
    // cin>>k;
    // insertathead(head,k);
    // print(head);
    // cout<<endl;
    // cout<<"Enter the position you want to insert at :  ";
    // int pos;
    // cin>>pos;
    // cout<<"Enter Data : ";
    // cin>>k;
    // print(head);
    // cout<<"Enter the position you want to delete :  ";
    // cin>>k;
    // deleteat(head,k,len);
    // print(head);
    // cout<<"Enter the element you want to search : ";
    // int key;
    // cin>>key;
    // cout<<"Found at index : "<<linearsearch(head,key);
    // reverse_itrate(head);
    // print(head);
    // head=reverse_recursive(head);
    // print(head);
    // cout<<"Kth node from end : ";
    // cin>>k;
    // kthnode(head,k);
    // cout<<"Mid point is : "<<midpoint(head);
}