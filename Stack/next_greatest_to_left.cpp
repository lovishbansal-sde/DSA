#include <bits/stdc++.h>
using namespace std;
void solve(int* input, int n)
{
    int output[n];
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(s.empty())
        {
            output[i]=-1;
        }
        if(s.empty()==false)
        {
            while(s.empty()==false and s.top()<=input[i])
            {
                s.pop();
            }
            if(s.empty()==true)
                output[i]=-1;
            else output[i]=s.top();
        }
        s.push(input[i]);
    }
    for(int i=0;i<n;i++)
        cout<<output[i]<<" ";
    
}
int32_t main(){
        int n;
    cin>>n;
    int input[n],output[n];
    for(int i=0;i<n;i++)
    cin>>input[i];
    solve(input,n);
    // for(int i=0;i<n;i++)
    // cout<<output[i]<<" 0 ";
    
}
