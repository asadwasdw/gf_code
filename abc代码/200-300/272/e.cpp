#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


vector<int>v;
unordered_map<int,vector<int>>st;

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        int l = 1;
        if(x<0)
        {
            l=(abs(x)+i-1)/i;
        }
        //cout<<l<<endl;
        for(int j=l;j<=m;j++)
        {
            if(x+i*j>n)break;
            st[j].push_back(x+i*j);
        }
    }

    for(int i=1;i<=m;i++)
    {
        vector<bool>cnt(n+10);
        for(auto t:st[i])cnt[t]=true;
        int ans=0;
        while(cnt[ans])ans++;
        cout<<ans<<endl;
        
    }

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