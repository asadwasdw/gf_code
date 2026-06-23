#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


void solve()
{
    int cnt = 0 ;
    int sum = 0;
    int cz=INF;
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>=b){
            cnt++;
            sum+=a;
            cz=min(a-b,cz);
        }
        else 
        {
            sum+=b;
            cz=min(b-a,cz);
        }
    }

    if(cnt%2==0)cout<<sum<<endl;
    else cout<<sum-cz<<endl;

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