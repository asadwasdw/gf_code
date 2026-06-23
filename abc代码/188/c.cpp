#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

int w[N];

void solve()
{

    int n;cin>>n;

    int a =0,b=0 ;

    for(int i=1;i<= 1ll<<n ;i++)
    {
        int x;
        cin>>w[i];
        if(i<= 1ll<<(n-1))a=max(w[i],a); 
        else b= max(w[i],b);
    }

    int t =min(a,b);
    //cout<<a<<" "<<b<<endl;
    //cout<<t<<endl;
    for(int i=1;i<= 1ll<<n ;i++)
    {
        if(w[i]==t)
        {
            cout<<i<<endl;
            return ;
        }
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