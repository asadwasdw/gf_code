#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=4e6+10;
#define endl '\n'
#define int long long
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int s[N];
void solve()
{
    int k,q;cin>> k >> q;
    if(k%2==0){
        for(int i=1;i<=q;i++)cout<<0<<endl;return;
    }
    int len = 2;
    int t = k;
    while(t){
        t/=2;len*=2;
    }
    int al = 0;

    for(int i=1;i<=len;i++){
        if(__gcd((i*k)^k,k)==1)al++;
        s[i] = al;
    }

    while(q--){
        int l,r;cin>> l >> r;l--;
        int res = r/len*al;
        res += s[r-r/len*len];
        res -= l/len*al;
        res -= s[l-l/len*len];
        cout<<res<<endl;
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