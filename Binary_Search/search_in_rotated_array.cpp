#include<bits/stdc++.h>
using namespace std;
binary_search_rotated(int*arr,int n,int k)
{
    int start = 0;
    int end = n-1;
    while (start <= end)
    {
        int mid = (start + end)/2;
        if(arr[mid] == k)
        return mid;
        else if(arr[mid]>=arr[start])
        {
            if(k>=arr[start] and k<=arr[mid])
            end=mid-1;
            else start=mid+1;
        }
        else
        {
            if(k<=arr[end] and k>=arr[mid])
            start=mid+1;
            else end=mid-1;
        }
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
    // sort(arr,arr+n);
    // cout<<"Sorted Array : ";
    // for(int i=0;i<n;i++) cout<<arr[i];
    cout<<binary_search_rotated(arr,n,k);

}