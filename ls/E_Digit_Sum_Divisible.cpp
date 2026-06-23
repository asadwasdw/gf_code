#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int num[N];

int js(int x)
{
    int t=0;
    int y=x;
    while(x){
        t+=x%10;
        x/=10;
    }
    return !(y%t);
}

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        num[i]=num[i-1]+js(i);
        cout<<num[i]<<" "<<i<<endl;
    }cout<<endl;

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