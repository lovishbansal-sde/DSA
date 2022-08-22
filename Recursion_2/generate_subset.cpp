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

void solve(string s,string out)
{
    if(s.length()==0){ cout<<out<<"    "; return;}
    string smaller = s.substr(1);
    solve(smaller,out+s[0]);
    solve(smaller,out);

}
int32_t main(){
    string s="abc",out="";

    solve(s,out);
    
}



