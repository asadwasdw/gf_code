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
    unordered_map<char,vector<int>>wz;
    unordered_map<char,int>mxx;

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        char x;cin>>x;
        wz[x].push_back(i);
    }

    bool ky = true;
    for(int i=1;i<=m;i++){
        char x;
        cin>>x;
        int mx = 0;
        for(char j=x;j<='z';j++){
            mx=max(mxx[j],mx);
        }

        auto it = upper_bound(wz[x].begin(),wz[x].end(),mx);
        
        if(it==wz[x].end()){
            ky=false;
        }
        else mxx[x]=*it;
    }
    if(ky)cout<<"YES\n";
    else cout<<"NO\n";
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