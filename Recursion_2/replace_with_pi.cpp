#include <bits/stdc++.h>
using namespace std;
string solve(string s) {
if(s.length() == 0 or s.length() == 1) 
return s;
if(s[0] == 'p' && s[1] == 'i')
return "3.14"+solve(s.substr(2));
else
return s[0]+solve(s.substr(1));
}

int main(){
	string s = "pipppiiipi";

	string result = solve(s);

	cout << result << endl;

	return 0;
}
