#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
#define int long long

const int B = 63;
struct Base{
    int num[B];
    int rank;
    void clear() {
        rank = 0;
        for(int i=0;i<B;i++)num[i]=0;
    }

    bool insert(int x) {
        for(int i = B-1; ~i; i--) {
            if(x>>i & 1) {
                if(num[i] == 0) {num[i] = x,rank++;return true;}
                else x^=num[i];
            }
        }
        return false;
    }
}c[N];
int a[N],b[N];

int qw[N];

void init()
{
    qw[0]=1;
    for(int i=1;i<N;i++)qw[i]=qw[i-1]*2%mod;
}

void solve()
{

    int n;cin>>n;
    for(int i=0;i<=n+10;i++){
        b[i]=a[i]=0;
        c[i].clear();
    }


    for(int i=1;i<=n;i++){
        int x;cin>>x;a[x]++;
    }

    for(int i=1;i<=n;i++)
    {
        if(a[i])
        for(int j=0;i*j<=n;j++){
            b[i*j]+=a[i];
            c[i*j].insert(i);
        }
    }

    int ans = 0;

    for(int i=0;i<=n;i++){
        if(i==0 || a[i]) {
            ans = (ans+qw[b[i]-c[i].rank])%mod;
        }
    }
    ans = (ans-1+mod)%mod;
    cout<<ans<<endl;
}


signed main()
{
    init();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}