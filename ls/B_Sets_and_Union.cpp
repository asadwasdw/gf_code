#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


void solve()
{
    int n;cin>>n;
    set<int>jh[55];
    vector<int>st(55);
    set<int>s;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        while(k--){
            int x;cin>>x;
            st[x]+=(1ll<<i);
            //cout<<st[x]<<" "<<(1ll<<i)<<endl;
            s.insert(x);
            jh[i].insert(x);
        }
    }

    int ans = 0;

    for(int i=1;i<=50;i++)
    {
        if(st[i]==0)continue;
        set<int>s;
        for(int j=1;j<=n;j++)
        {
            if((st[i]>>j)&1)continue;
            for(auto t:jh[j]){
                s.insert(t);
            }
        }
       // cout<<s.size()<<endl;
        ans=max(ans,(int)s.size());
    }
    cout<<ans<<endl;

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