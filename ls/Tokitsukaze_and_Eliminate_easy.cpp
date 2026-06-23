#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

unordered_map<int,vector<int>>edg;
int a[N];

int get(int x) {
    edg[x].pop_back();
    if(edg[x].size())return edg[x].back();
    return INF;
}

void solve()
{
    for(auto &t:edg) {
        t.second.clear();
    }
    edg.clear();

    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        edg[a[i]].push_back(i);
    }
    
    int mn = INF;
    for(auto t:edg) {
        mn = min(t.second.back(),mn);
    }
    int w = n;
    int ans = 0;
    while(w&&mn!=INF) {
        int t = mn;
        // cout<<a[mn]<<endl;
        for(int i=w;i>=mn;i--) {
            t = min(t,get(a[i]));
        }
        w=mn-1;
        mn = t;
        ans++;
    }

    cout<<ans<<"\n";

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