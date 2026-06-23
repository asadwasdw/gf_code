#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;
typedef pair<ll,ll>PII;


vector<PII>d;



bool check(PII a,PII b,PII c)
{
    return (a.first-b.first)*(b.second-c.second)==(a.second-b.second)*(b.first-c.first);
}

bool dfs(vector<PII>t,int k)
{
    if(t.size()<=k)return true;
    if(k==0)return false;

    for(int i=0;i <= k;i++)
    {
        for(int j=i+1;j <= k;j++)
        {
            vector<PII>nt;
            for(int z=0;z<t.size();z++)
            if(!check(t[i],t[j],t[z])){
                nt.push_back(t[z]);
            }

            if(dfs(nt,k-1))return true;
        }
    }

    return false;
}


void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        d.push_back({l,r});
    }

    bool ky = dfs(d,3);

    if(ky)cout<<"possible";
    else cout<<"impossible";

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