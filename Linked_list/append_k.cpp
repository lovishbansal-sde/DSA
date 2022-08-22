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
node* kth_node_from_last(node* head,int position)
{
    int k=1;
    node*fast=head;
    node*slow=head;
    while(k<position+1)
    {
        fast=fast->next;
        k++;
    }
    while(slow->next!=NULL && fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}
node* solve(node*&head,node*&temp)
{
node* newhead=new node();
newhead=temp->next;
temp->next=NULL;
node *a=newhead;
while(a->next!=NULL)
{
    a=a->next;
}
a->next=head;
return newhead;

    
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
    node* temp=kth_node_from_last(head,2);
    // cout<<temp->data;
    print(solve(head,temp));
}
