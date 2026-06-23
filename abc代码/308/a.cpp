#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

int a[N];
void solve()
{
    bool ky=true;

    for(int i=1;i<=8;i++)
    {
        int x;cin>>x;
        a[i]=x;
        if(x%25)ky=false;
        if(x<100||x>675)ky=false;
       if(i!=1&&a[i-1]>a[i])ky=false;
    }

    if(ky)cout<<"Yes";
    else cout<<"No";







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