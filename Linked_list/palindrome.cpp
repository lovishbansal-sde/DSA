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
node* mid_point(node* head)
{
    node*slow=head;
    node*fast=head->next;
    while(slow!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
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
    cout<<solve(head);
}
