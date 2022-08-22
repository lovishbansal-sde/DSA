#include<iostream>
using namespace std;
int solve(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    return solve(n-1)+solve(n-2);
}
int nain()
{
    int n,k;
    cin>>n;
    cout<<solve(n);
}