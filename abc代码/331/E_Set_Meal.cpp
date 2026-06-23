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

int n,m,l;
PII a[N],b[N];

map<PII,bool>st;

bool cmp(PII a,PII b)
{
    return a.first>b.first;
}

void solve()
{
    cin>>n>>m>>l;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a[i]={x,i};
    }
    for(int j=1;j<=m;j++){
        int x;cin>>x;
        b[j]={x,j};
    }

    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);

    for(int i=1;i<=l;i++){
        int x,y;
        cin>>x>>y;
        st[{x,y}]=1;
    }

    int ans = 0;

    for(int i=1;i<=n;i++) {

        for(int j=1;j<=m;j++){
            if(st[{a[i].second,b[j].second}]==0) {
                ans = max(ans,a[i].first+b[j].first);
                break;
            }
        }
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