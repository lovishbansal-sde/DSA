#include <bits/stdc++.h>
using namespace std;
string solve(string s)
{
    string star="*";
    if(s.length()==0 or s.length()==1) return s;
    if(s[0]==s[1]){
    // string a=s[0] + star + s.substr(1);
    return s[0] + star+solve(s.substr(1));
    }
    else return s[0]+solve(s.substr(1));

}
int main(){
    string s;
    cin>>s;
    cout<<solve(s);
}
