#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int f[N*2];

int find(int x)
{
    if(x!=f[x])return f[x]=find(f[x]);
    return x;
}
int a[N*2],b[N*2];

void solve()
{

    for(int i=1;i<N+N;i++)f[i]=i;

    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        f[find(a)]=find(b+N);
    }

    for(int i=1;i<=N;i++){
        a[find(i)]++;
    }
    for(int j=N+1;j<N+N;j++){
        b[find(j)]++;
    }
    ll ans = 0;
    for(int i=1;i<N+N;i++){

        ans += 1ll*a[i]*b[i];
    }
    cout<<ans-n<<endl;







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