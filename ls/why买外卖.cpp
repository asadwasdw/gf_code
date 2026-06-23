#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

PII a[N];
int c[N];

bool cmp(PII a, PII b) {
    return a.first<b.first;
}
map<int,int>b;

void solve()
{
    b.clear();
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
    {
        int u,v;cin>>u>>v;
        b[u]+=v;
    }


    n=0;
    for(auto t:b) {
        if(t.second>=t.first) {
            m+=t.second;
        }
        else {
            ++n;
            a[n]={t.first,t.second};
            
        }

    }

    int ans = m;
    sort(a+1,a+n+1,cmp);

    for(int i=1;i<=n;i++){
        c[i]=c[i-1]+a[i].second;
    }

    for(int i=1;i<=n;i++){
        
        if(m+c[i]>=a[i].first){
            ans = m + c[i]; 
        }
        // cout<<ans<<endl;
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