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

bool compare(pair<int,int> a, pair<int,int> b)
{
     return a.second < b.second;
}
int32_t main(){
    int k;
    cin>>k;
    while(k--){
    int n;
    cin>>n;
    pair<int,int> arr[n];
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr[i]=make_pair(a,b);
    }
    sort(arr,arr+n,compare);
    // for(int i=0;i<n;i++)
    // cout<<arr[i].first<<" "<<arr[i].second<<endl;
    int last_activity=arr[0].second,cnt=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i].first>=last_activity)
        {
            cnt++;
            last_activity=arr[i].second;
        }
    }
    cout<<cnt<<endl;
}
}