#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

set<string>st;

void solve()
{
    string s;
    cin>>s;

    for(int i=1;i<=8;i++) {
        string t =  s.substr(0,1) + (char)(i+'0');
        if(t!=s)st.insert(t);
        t = (char)(i+'a'-1) + s.substr(1,1);
        if(t!=s)st.insert(t);
    }

    for(auto t:st) cout<<t<<endl;
    st.clear();


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}