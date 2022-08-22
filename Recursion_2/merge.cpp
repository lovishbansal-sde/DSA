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
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
void merge(int* arr,int start,int end)
{
    int i=start;
    int mid=(start+end)/2;
    int j=mid+1;
    int temp[100];
    int k=0;
    while(i<=mid and j<=end)
    {
        if(arr[i]<arr[j])
        temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }
    while(i<=mid)
    temp[k++]=arr[i++];
    while(j<=end)
    temp[k++]=arr[j++];
    int l=0;
    for(int i=start;i<=end;i++){
    arr[i]=temp[l];
    l++;
    }
    return;
}
void mergesort(int *arr,int start,int end)
{
    if(start>=end)
    return;
    int mid=(start+end)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,end);
}
int32_t main(){
//OJ;
//fast
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){cin>>arr[i];}
    mergesort(arr,0,n-1);
    for(int i=0; i<n; i++){cout<<arr[i];}
}
