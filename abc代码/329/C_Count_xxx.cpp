#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

unordered_map<char,int>st;

void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    s=" "+s;

    char t = s[1];
    int res = 1;

    for(int i=2;i<=n;i++){
        if(t!=s[i]){
            st[t]=max(st[t],res);
            t=s[i];
            res=1;
        }
        else res++;
    }
    st[t]=max(st[t],res);
    

    int ans = 0;
    for(auto t:st) {
        ans+=t.second;
    }
    cout<<ans<<endl;

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