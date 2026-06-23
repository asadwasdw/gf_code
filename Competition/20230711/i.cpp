#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int w[]={0,7,27,41,49,63,78,108,0};

void solve()
{
    int n;
    cin>>n;
    set<int>s;
    ll sum=0;
    for(int i=1;i<=n;i++){
         ll x;cin>>x;
        s.insert(x);
        sum+=w[x];
      //  cout<<sum<<endl;
    }

    // for(auto t:s){
    //     sum+=w[t];
    // }

    if(sum>=120)sum-=50;
    else if(sum>=89)sum-=30;
    else if(sum>=69)sum-=15;
    cout<<sum<<endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}