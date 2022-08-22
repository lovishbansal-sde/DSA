#include<iostream>
#include<vector>
#include<climits>
// #include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node* right;
    node(int a)
    {
        data=a;
        left=right =NULL;
    }
};

node* insertInBst(node* root,int a)
{
    if(root==NULL)
    {
        return new node(a);        
    }
    if(a<=root->data)
    {
        root->left=insertInBst(root->left,a);
    }
    else
    {
        root->right=insertInBst(root->right,a);
    }
    return root;
}
void print(node* root)
{
    if(root==NULL) return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
    return;
}
bool search(node* root,int key)
{
    if(root==NULL) return false;
    if(root->data==key) return true;
    if(key>root->data)
    return search(root->right,key);
    else    return search(root->left,key);
}
node* deleteInBst(node* root,int k)
{
    if(root==NULL) return NULL;
    else if(k<root->data)
    {
        root->left=deleteInBst(root->left,k);
    }
    else if(root->data==k)
    {
        // 0 Children
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        // 1 children
        if(root->right!=NULL && root->left==NULL)
        {
            node*temp=root->right;
            delete root;
            return temp;
        }
        if(root->right==NULL && root->left!=NULL)
        {
            node*temp=root->left;
            delete root;
            return temp;
        }
        // 2 children
        node* replace=root->right;
        while(replace->left!=NULL)
            replace=replace->left;

        root->data=replace->data;
        root->right=deleteInBst(root->right,replace->data);
        return root;

    }
    else 
    {
        root->right=deleteInBst(root->right,k);
        return root;
    }
}
bool isBst(node* root,int minv=INT_MIN,int maxv=INT_MAX)
{
    if(root==NULL) return true;
    if((root->data>minv && root->data<=maxv) && isBst(root->left,minv,root->data) && isBst(root->right,root->data,maxv))
    return true;
    return false;
}

void preOrderPush(node* root,vector<node*> &v)
{
    if(root==NULL) return;
    preOrderPush(root->left,v);
    v.push_back(root);
    preOrderPush(root->right,v);
    return;
}
// void flatternTree(node* root)
// {
//     vector<node*> v;

//     preOrderPush(root,v);
//     for(int i=0;i<v.size();i++)
 //     cout<<v[i]->data<<"   ";
//     cout<<endl;
//     node *temp=root;
//     // root=v[0];
//     for(int i=1;i<v.size();i++)
//     {
//         temp->right=v[i];
//         temp->left=NULL;
//         temp=temp->right;
//     }
// }
class linkedList{
    public:
    node*head;
    node*tail;
};
linkedList flatternTree(node*root)
{
    linkedList p;
    if(root==NULL) 
    {
        p.head=p.tail=NULL;
        return p;
    }
    if(root->left==NULL && root->right==NULL){
        p.head=p.tail=root;
        return p;
    }
    if(root->left!=NULL && root->right==NULL)
    {
        linkedList leftLL=flatternTree(root->left);
        //DOUBT
        leftLL.tail->right=root;

        p.head=leftLL.head; 
        p.tail=root;      
        return p;  
    }

    if(root->left==NULL && root->right!=NULL)
    {
        linkedList rightLL=flatternTree(root->right);
        root->right=rightLL.head;
        p.head=root; 
        p.tail=rightLL.tail;
        return p;
    }
    if(root->left!=NULL && root->right!=NULL)
    {
    
        linkedList leftLL=flatternTree(root->left);
        linkedList rightLL=flatternTree(root->right);

        leftLL.tail->right=root;
        root->right=rightLL.head;

        p.head=leftLL.head;
        p.tail=rightLL.tail;
        return p;
    }
    
}
int main()
{
    int n,d;
    cin>>n;
    node* root=NULL;
    while(n--)
    {
        cin>>d;
       root= insertInBst(root,d);
    }
    // print(root);
    // int k;
    // cin>>k;
    // cout<<search(root,k);
    // flatternTree(root);
    // 
    linkedList l=flatternTree(root);
    node*temp=l.head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp->left=NULL;
        temp=temp->right;
    }
    cout<<endl;
    print(root);
}


