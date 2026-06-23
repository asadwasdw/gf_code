#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int dyj=2e17+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int n,m;
int a[N];

bool check(int mid){

    int res = 1;
    int t = 0; 
    for(int i=1;i<=n&&res<=m;i++)
    {
        // cout<<" s"<<t+a[i]<<" "<<mid<<endl;
        if(a[i]>mid)res=m+1;
        if(t+a[i]<=mid){
            t+=a[i]+1;
        }
        else {
            t=a[i]+1;
            res++;
        }
    }
    //cout<<res<<endl;
    return res<=m;
}

void solve()
{

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
   // cout<<check(122)<<endl;

    int l = a[1] ,r = dyj;
    //cout<<a[1]<<endl;
    while(l<r)
    {
        int mid = l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
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