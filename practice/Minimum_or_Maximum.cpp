#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    while(k--){
    int n;
    cin>>n;
    int arr[n];
    cin>>arr[0];
    int mini=arr[0];
    int maxi=arr[0];
    for(int i=1;i<n;i++)cin>>arr[i];
    int flag=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>maxi)
        maxi=arr[i];
        if(arr[i]<mini)
        mini=arr[i];
        if(arr[i]<maxi and arr[i]>mini)
        flag=1;
    }
    if(flag==1)
    cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
}