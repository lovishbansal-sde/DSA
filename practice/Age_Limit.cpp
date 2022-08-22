#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
        int n;
        cin>>n;
        map<int,int> freq;
        vector<int> v,result;
        while(n--)
        {
                int a,b;
                cin>>a>>b;
                if(a==1)
                {
                        v.push_back(b);
                        freq[b]+=1;
                }
                if(a==2)
                {
                        int most_freq=0,element,index;
                        for(int i=0;i<v.size();i++)
                        {
                                if(v[i]==-1) 
                                continue;
                                else if(freq[v[i]]>=most_freq)
                                {
                                        index=i;
                                        element=v[i];
                                        most_freq=freq[element];
                                }
                        }
                        // cout<<most_freq<<"  "<<endl;
                        v[index] = -1;
                        freq[element]-=1;
                        result.push_back(element);
                }
        }
        for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
}
