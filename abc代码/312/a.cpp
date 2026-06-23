#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
unordered_map<string,int>st;

void solve()
{
    st["ACE"]=1;
    st["BDF"]=1;
    st["CEG"]=1;
    st["DFA"]=1;
    st["EGB"]=1;
    st["FAC"]=1;
    st["GBD"]=1;

    string s;
    cin>>s;
    if(st[s])cout<<"Yes";
    else cout<<"No";







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