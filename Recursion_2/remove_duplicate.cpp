#include <bits/stdc++.h>
using namespace std;
string solve(string s)
{
    if(s.length()==0) return s;
    string semi=solve(s.substr(1));
    if(s[0]==s[1]){
        return semi;
    // return s[0] +solve(s.substr(2));
    }
    else return s[0]+semi;
    // else return s[0]+solve(s.substr(1));

}
int main(){
    string s;
    cin>>s;
    cout<<solve(s);
}
