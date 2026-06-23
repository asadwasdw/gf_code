#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
const int M = 1<<20;
int n,m;
int a[N];
int f[M];

struct edge{
    int l,r,w;
}E[N];

int fa[20];

struct node
{
    int y;
    inline bool operator > (const node &x) const {//小根堆，重载大于号，小的在前面
        return y>x.y;
    }
};


void solve()
{
    int S  = 5;
    for(int S0=S;S0;S0=(S0-1)&S){//枚举S的二进制子集，例如5的子集有1，4，5
        cout<<S0<<endl;
    }

    auto dfs = [&] (int x) {
        if(x == 1) return 1; 
        return x ;
    };
    cout << dfs(5) << endl;
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