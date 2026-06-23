#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define int long long
// vector<vector<int>>edg(N);

// int x[N];
// int a[N];
// int d[N];

ll extend_gcd(ll a,ll b, ll &x, ll &y) {
    if(b==0){x=1;y=0;return a;}
    ll d = extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

void solve()
{
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        sum+=x;
    }

    int a,b,x,y,k1,t;
    a=n;b=n*(n+1)/2;

    int g1 = __gcd(a,b);
    int g2 = __gcd(g1,m);

    int ans = sum%g2;

    extend_gcd(g1,m,k1,t);
    k1*=((ans-sum)/g2)%m;//转成最小正整数
    k1%=m;

    extend_gcd(a,b,x,y);// = g1 的最小解
    x*=k1,y*=k1; //因为a*x+b*y = k1*g1;

    cout<<ans<<"\n";
    cout<<(x%m+m)%m<<" "<<(y%m+m)%m<<endl;




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