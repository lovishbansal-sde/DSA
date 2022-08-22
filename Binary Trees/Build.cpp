#include<iostream>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;
class node
{
    public:
    int data;
    node*right;
    node*left;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
node* buildTree()
{
    int d;
    cin>>d;
    if(d==-1) return NULL;
    node* root = new node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void print(node* root)
{
    if(root==NULL) return;
    cout<<root->data;
    print(root->left);
    print(root->right);
    return;
}
void printPreorder(node* root)
{
    if(root==NULL) return;
    cout<<root->data;
    print(root->left);
    print(root->right);
    return;
}
void printInorder(node* root)
{
    if(root==NULL) return;
    print(root->left);
    cout<<root->data;
    print(root->right);
    return;
}
void printPostorder(node* root)
{
    if(root==NULL) return;
    print(root->left);
    print(root->right);
    cout<<root->data;
    return;
}
int Height(node* root)
{
    if(root==NULL) return 0;
    int lh=Height(root->left);
    int rh=Height(root->right);
    return max(lh,rh)+1;
}
void printKthLevel(node* root,int k)
{    
    if(root==NULL) return;
    if(k==1)
    cout<<root->data<<" ";
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);

    return;
}
void bfs(node* root)
{
    queue<node*> q;
    q.push(root);
    while(q.empty()==false)
    {
        cout<<q.front()->data<<" ";
        if(q.front()->left)
        q.push(q.front()->left);
        if(q.front()->right)
        q.push(q.front()->right);
        q.pop();
    }
}
void bfsLevelWise(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(q.empty()==false)
    {

        if(q.front()==NULL)
        {
            // cout<<"Hi";
            cout<<endl;
            q.pop();
            if(q.empty()==false)
                q.push(NULL);  
        }
        else
        {
            cout<<q.front()->data<<" ";
            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)
                q.push(q.front()->right);
            q.pop();
                // cout<<"Hiiii";
        }
    }
}
int countNodes(node* root)
{
    if(root==NULL) return 0;
    else return countNodes(root->left)+countNodes(root->right)+1;
}
int totalSum(node* root)
{
    if(root==NULL) return 0;
    int a=totalSum(root->left);
    int b=totalSum(root->right);
    return a+b+root->data;
}
int diameter(node* root)
{
    if(root==NULL) return 0;
    int h1=Height(root->left);
    int h2 =Height(root->right);
    int a=h1+h2;
    int b=diameter(root->left);
    int c=diameter(root->right);
    return max(max(a,b),c);
}
class Pair{
    public:
    int height;
    int diameter;
};
Pair fastDiameter(node* root)
{
    Pair p;
    if(root==NULL){
        p.diameter=p.height=0;
        return p;
    }
    //Otherwise
    Pair left=fastDiameter(root->left);
    Pair right=fastDiameter(root->right);
    p.height=max(left.height,right.height)+1;
    p.diameter=max(max(left.height+right.height,left.diameter),right.diameter);
    return p;
}
int replacesum(node* root)
{
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    int temp=root->data;
    int a=replacesum(root->left);
    int b=replacesum(root->right);
    
    root->data=a+b;
    return a+b+temp;
}
class HBpair{
    public:
    int height;
    bool balanced;
};
HBpair heightBalancedTree(node* root)
{
    HBpair p;
    if(root==NULL)
    {
        p.height=0;
        p.balanced=true;
        return p;
    }
    HBpair a=heightBalancedTree(root->right);
    HBpair b=heightBalancedTree(root->left);
    p.height=max(a.height,b.height)+1;
    if (abs(a.height-b.height)<=1 && a.balanced && b.balanced)
    p.balanced=true;
    else p.balanced=false;
    return p;
}
node* buildTreeFfromArray(int* a,int s,int e)
{
    if(s>e)
        return NULL;
    // Recursive Case
    int mid=(s+e)/2;
    node*root=new node(a[mid]);
    root->left=buildTreeFfromArray(a,s,mid-1);
    root->right=buildTreeFfromArray(a,mid+1,e);
    return root;
}
node* createTreeFromTraversal(int* in,int* pre,int s,int e){
    static int i=0;
    if(s>e)
    return NULL;
    node*root=new node(pre[i]);
    int index=-1;
    for(int j=s;j<=e;j++)
    {
        if(pre[i]==in[j])
        {
            index=j;
            break;
        }
    }
    i++;
    root->left=createTreeFromTraversal(in,pre,s,index-1);
    root->left=createTreeFromTraversal(in,pre,index+1,e);
    return root;
}
void rightView(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(q.empty()==false)
    {

        if(q.front()==NULL)
        {

            // cout<<"Hi";
            cout<<endl;
            q.pop();
            if(q.empty()==false)
                q.push(NULL);  
        }
        else
        {
            int a=q.front()->data;
            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)
                q.push(q.front()->right);
            q.pop();
            if(q.front()==NULL)
            cout<<a<<" ";
                // cout<<"Hiiii";
        }
    }
}
void bfsnew(node* root)
{
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    while(q.empty()==false)
    {
        // cout<<q.front()->data<<" ";
        int size=q.size();
        node* a;
        while(size--)
        {
            // cout<<q.front()->data<<" ";
            if(q.front()->left)
            q.push(q.front()->left);
            if(q.front()->right)
            q.push(q.front()->right);
            a=q.front();
            q.pop();
        }
        cout<<a->data;
        cout<<endl;
        
    }
    return;
}
// vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
// {
//     unordered_map<TreeNode*,TreeNode*> mp;
//     queue<TreeNode*> q;
//     q.push(root);
//     while(q.empty()==false)
//     {
//         if(q.front()->left){
//         mp[q.front()->left]=q.front();
//         q.push(q.front()->left);
//         }
//         if(q.front()->right){
//         q.push(q.front()->right);
//         mp[q.front()->right]=q.front();
//         }
//         q.pop();
//     }

//     q.push(target);
//     unordered_map<TreeNode*,bool> visited;
//     visited[target]=true;
//     int dis=0;
//     while(q.empty()==false)
//     {
//         int size=q.size();
//         if(dis==k)
//         break;
//         while(size--)
//         {
//             TreeNode* ele=q.front();
//             q.pop();
//             if(ele->left && visited[ele->left]==false)
//             {
//                 q.push(ele->left);
//                 visited[ele->left]=true;
//             }
//             if(ele->right && visited[ele->right]==false)
//             {
//                 q.push(ele->right);
//                 visited[ele->right]=true;
//             }
//             if(mp.count(ele) and visited[mp[ele]] == false)
//             {
//                 q.push(mp[ele]);
//                 visited[mp[ele]]=true;
//             }
//     
//         }
//          dis++;
//     }
//     vector<int> ans;
//         while(!q.empty())
//         {
//             ans.push_back(q.front()->val);
//             q.pop();
//         }
//         return ans;
// }
void traverseTree(node*root,map<int,vector<int> >&mp,int d)
{
    if(root==NULL) return;
    mp[d].push_back(root->data);
    traverseTree(root->left,mp,d-1);
    traverseTree(root->right,mp,d+1);
}
void verticalOrder(node*root)
{
    map<int,vector<int>> m;
    int d=0;
    traverseTree(root,m,d);
    for(auto it:m)
    {
        vector<int> v=it.second;
        for(auto data: v)
        {
            cout<<data<<" ";
        }
        cout<<endl;
    }
    return;
}
node* lca(node*root,int a,int b)
{
    if(root==NULL) return NULL;
    if(root->data==a || root->data==b) return root;

    //Search  in left and right subtree for either a or b
    node* leftans=lca(root->left,a,b);
    node* rightans=lca(root->right,a,b);
    if(leftans!=NULL && rightans!=NULL)
    return root;
    if(leftans==NULL && rightans!=NULL)
    return rightans;
    else return leftans;
}
#define maxim(a,b,c,d) max(max(max(a,b),c),d)
class Pair_{
    public:
    int branchSum;
    int maxSum;
    Pair_(){
        branchSum=0;
        maxSum=0;
    }
};

Pair_ maxSumPath(node* root)
{
    Pair_ p;
    if(root==NULL) return p;
    Pair_ left=maxSumPath(root->left);
    Pair_ right=maxSumPath(root->right);
    int op1=root->data;
    int op2=left.branchSum+root->data;
    int op3=right.branchSum+root->data;
    int op4=left.branchSum+ right.branchSum + root->data;

    int current_ans=maxim(op1,op2,op3,op4);

    p.branchSum=max(left.branchSum,max(right.branchSum,0))+root->data;
    p.maxSum=max(left.maxSum,max(right.maxSum,current_ans));
    return p;
}
int findDistanceHelper(node *root,int key,int level)
{
    if(root==NULL) return -1;
    if(root->data==key)
    return level;
    int left=findDistanceHelper(root->left,key,level+1);
    if(left!=-1)
    return left;
    else return findDistanceHelper(root->right,key,level+1);
}
int findDistance(node* root,int a,int b)
{
    node* la=lca(root,a,b);
    int p=findDistanceHelper(la,a,0);  // Level
    int q=findDistanceHelper(la,b,0);
    return p+q;
}
bool printPath(node*root,int k,vector<int> &v)
{
    if(root==NULL) return false;
    v.push_back(root->data);
    if(root->data==k) return true;
    if(printPath(root->right,k,v)||printPath(root->left,k,v))
    {
        return true;
    }
    v.pop_back();
    return false;
}

int main()
{
    // node*root=buildTree();
    // print(root);
    // int height=Height(root);
    // for(int i=1;i<=height;i++){
    // printKthLevel(root,i);
    // cout<<endl;
    // }
    // bfs(root);
    // bfsLevelWise(root);
    // cout<<countNodes(root);
    // cout<<totalSum(root);
    // cout<<diameter(root);
    // Pair p=fastDiameter(root);
    // cout<<p.diameter;
    // replacesum(root);
    // cout<<endl;
    // bfsLevelWise(root);
    // HBpair p;
    // p=heightBalancedTree(root);
    // if(p.balanced)
    // cout<<1;
    // else cout<<0;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    node*root=NULL;
    root=buildTreeFfromArray(arr,0,n-1);
    // bfsLevelWise(root);
    // cout<<endl<<Height(root);
    // cout<<endl<<diameter(root);
    // rightView(root);
    bfsnew(root);
    // verticalOrder(root);
    // cout<<endl<<lca(root,13,8)->data; 
    // vector<int> v;
    // printPath(root,13, v);  
    // for(auto it:v)
    // cout<<it<<" "; 
}