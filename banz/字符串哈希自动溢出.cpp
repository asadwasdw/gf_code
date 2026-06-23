#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;
const ull mod = 1e9+7;
int n;
const int P =13331;
ull p[N];
ull h[N];
ull fh[N];



ull get(int l,int r)
{
    if(l>r)return 0;
    return h[r]-h[l-1]*p[r-l+1];
}

ull get2(int L,int R)
{
    int l=2*n-R+1;
    int r=2*n-L+1;
    if(l>r)return 0;
    return fh[r]-fh[l-1]*p[r-l+1];
}


void solve()
{
    cin>>n;

    p[0]=1;
    string s;
    cin>>s;
    string fs=s;
    reverse(fs.begin(),fs.end());
   
    s=" "+s;
    fs=" "+fs;
    for(int i=1;i<=2*n;i++)
    {
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+s[i]-'a'+1;
        fh[i]=fh[i-1]*P+fs[i]-'a'+1;
    }
    
    for(int i=1;i<=2*n;i++)
    {
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+s[i]-'a'+1;
        fh[i]=fh[i-1]*P+fs[i]-'a'+1;
    }

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