#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    int n;cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        bool ky = true;
        if(s[i]=='L')ky = false;
        if(i!=0 && s[i-1]=='L')ky=false;
        if(i!=s.size()-1 && s[i+1]=='L')ky=false;
        if(ky) {
            s[i]='C';
        }
    }

    for(int i=0;i<s.size();i++) cout<<s[i];
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}