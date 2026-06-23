#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=2e6+10;

const int INF  = 0x3f3f3f3f;
typedef long long ll;

typedef unsigned long long ull;
int n,m,k;
const ull P1 =131;
const ull P2 =13331;
const ull mod=998244353;
ull p1[N];
ull h1[N];
ull fh1[N];

ull p2[N];
ull h2[N];
ull fh2[N];

ull get1(int l,int r)
{
    if(l>r)return 0;
    return h1[r]-h1[l-1]*p1[r-l+1];
}

ull get2(int l,int r)
{
    if(l>r)return 0;
    return (h2[r]-(h2[l-1]%mod*p2[r-l+1]%mod)%mod+mod)%mod;
}

ull fget1(int L,int R)
{
    int l=n-R+1;
    int r=n-L+1;
    if(l>r)return 0;
    return fh1[r]-fh1[l-1]*p1[r-l+1];
}

ull fget2(int L,int R)
{
    int l=n-R+1;
    int r=n-L+1;
    if(l>r)return 0;
    return (fh2[r]-(fh2[l-1]%mod*p2[r-l+1]%mod)%mod+mod)%mod;
}
bool check(int l1,int r1,int l2,int r2)
{
    if(get1(l1,r1)==get1(l2,r2)&&get2(l1,r1)==get2(l2,r2)){
        return true;
    }
    return false;
}

bool fcheck(int l1,int r1,int l2,int r2)// 正的l1-r1 是否等于 反的l2-r2;
{
    if(get1(l1,r1)==fget1(l2,r2)&&get2(l1,r1)==fget2(l2,r2)){
        return true;
    }
    return false;
}

void init(string s)
{
    p1[0]=1;
    p2[0]=1;
    string fs=s;
    reverse(fs.begin(),fs.end());


    int t;
    t = '0'-1;
   // t='a'-1;

    s=" "+s;
    fs=" "+fs;

    for(int i=1;i<=n;i++)
    {
        p1[i]=p1[i-1]*P1;
        h1[i]=h1[i-1]*P1+s[i]-t;
        fh1[i]=fh1[i-1]*P1+fs[i]-t;
    }
    for(int i=1;i<=n;i++)
    {
        p2[i]=(p2[i-1]*P2)%mod;
        h2[i]=((h2[i-1]*P2)%mod+s[i]-t+mod)%mod;
        fh2[i]=((fh2[i-1]*P2)%mod+fs[i]-t+mod)%mod;
    }
}



void solve()
{
    
    string s;
    cin>>s;
    n = s.size();
    init(s);

    int ans = 0;
    for(int len = 1; len <= n; len ++) {
        int l = n - len + 1;
        if(fcheck(l, n, l, n)) {
            ans = max(ans, len);
        }
    }
    // cout << ans << endl;
    cout << s;
    for(int i = n - ans; i; i --) cout << s[i - 1];

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