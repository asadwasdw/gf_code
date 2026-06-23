#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int a[N];

void solve()
{
    int n;
    cin>>n;
    int l = 1,r=1;
    bool flag = true;
    for(int i=1;i<=n;i++)cin>>a[i];
    while(r<=n){
        //cout<<l<<" "<<r<<endl;
        for(int i=l+1;i<=r;i++){
            if(a[i]<a[i-1])flag=false;
        }
        if(r==n)break;
        l=r+1;
        r=min(n,r*2);

    }
    if(flag)cout<<"YES\n";
    else cout<<"NO\n";







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