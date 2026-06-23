#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

ll qpow(ll a,ll b) {
    ll res = 1;
    while(b) {
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return res;
}

ll inv(ll x) {
    return qpow(x,mod-2);
}

struct Trie{
    #define type ll
    static const int mx = 30;
    int root,tot,nex[N*mx][2];
    type val[N*mx];//存权值
    
    int newnode() {
        memset(nex[tot],0,sizeof nex[tot]);
        val[tot]=0;
        return tot++;
    }

    void init() {
        memset(nex[0],0,sizeof nex[0]);
        val[0]=0;
        tot=1;
        root=newnode();
    }

    void upd(type x,type v) {//增加一个数x，权值是v
        int id,t,i;
        id = root;
        for(int i=mx;~i;i--) {
            t=(x>>i)&1;
            if(!nex[id][t]) nex[id][t] = newnode();
            id = nex[id][t];
            val[id] = (val[id]+v)%mod;
        }
    }

    void add(type x) {
            upd(x,1);
    }

    type ask(type x,type k) {//与x异或不超过k的数的权值和
        int id,t,i;
        type res = 0;
        id = root;
        for(int i=mx;~i;i--) {
            t=(x>>i)&1;
            if(((k>>i)&1)==1) {
                if(nex[id][t]) res = (res+val[nex[id][t]])%mod;
                id = nex[id][t^1];
            }
            else id = nex[id][t];
        }
        res = (res+val[id])%mod;
        return res;
    }

    type querymax(type x){ // 与x异或（能产生的最大的数）的数
        type res = 0;
        int q[35];
        int id = root;
        for(int i=mx;~i;i--) {
            int t=(x>>i)&1;
            if(nex[id][t^1]){
                q[i]=t^1;
                id=nex[id][t^1];
            }
            else id=nex[id][t],q[i]=t;
        }
        
        for(int i=0;i<=30;i++) res+=q[i]*pow(2,i);
        return res;
    }


    #undef type
}tr;

int a[N];

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    tr.init();
    ll ans = 0;
    for(int i=1;i<=n;i++)tr.add(a[i]);
    
    for(int i=1;i<=n;i++) {
        ans = max(ans,a[i]^tr.querymax(a[i]));
    }
    cout<<ans<<endl;


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    // cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}   