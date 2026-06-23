#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

int num[N];

typedef pair<int,int>PII;
PII a[N];


void solve()
{
    int n;cin>>n;

    for(int i=1;i<=3*n;i++)
    {
        int x;cin>>x;
        num[x]++;

        if(num[x]==2){
            a[x]={i,x};
        }
    }

    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++)cout<<a[i].second<<" ";



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