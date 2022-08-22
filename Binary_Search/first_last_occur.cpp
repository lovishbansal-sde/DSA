#include<bits/stdc++.h>
using namespace std;
int binary_search_first(int*arr,int n,int k)
{
    int start = 0;
    int end = n-1;
    int ans=-1;
    while(start <= end)
    {
        int mid=(start+end)/2;
        if(arr[mid] ==k)
        {
            ans=mid;
            end=mid-1;
        }
        else if(arr[mid]>k)
        end=mid-1;
        else start=mid+1;
        return ans;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    cin>>arr[i];
    cout<<"Enter Key  ";
    int k;
    cin>>k;
    sort(arr,arr+n);
    cout<<"Sorted Array : ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    cout<<binary_search_first(arr,n,k);
}