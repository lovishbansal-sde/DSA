#include<bits/stdc++.h>
using namespace std;
int binary_search(int* arr,int n,int key)
{
    int start = 0;
    int end=n-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==key)
        return mid;
        if(arr[mid]>key)
        end=mid-1;
        else start=mid+1;
    }
    return -1;
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
    for(int i=0;i<n;i++) cout<<arr[i];
    cout<<binary_search(arr,n,k);

}