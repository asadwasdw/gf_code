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

int fact[N], infact[N];
int qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}

void init()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i ++ )
    {
        fact[i] = (ll)fact[i - 1] * i % mod;
        infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

int C(int a,int b)
{
    return (ll)fact[a] * infact[b] % mod * infact[a - b] % mod;
}

int d[N];

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        d[a]++,d[b]++;
    }

    int js = 0,os = 0;
    for(int i=1;i<=n;i++){
        if(d[i]%2)js++;
        else os++;
    }
    int ans = 0;
    for(int i=0;i<=js;i+=2){
        int j = k-i;

        if(j>os)continue;

        ans+=C(js,i)*C(os,j);
        ans%=mod;
    }
    cout<<ans<<endl;
}


signed main()
{
    init();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}