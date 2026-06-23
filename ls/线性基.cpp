#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define int unsigned long long

unsigned long long a[N];




void solve()
{
    int n;cin>>n;

    for(int i=1;i<=n;i++)cin>>a[i];
    int k = 1;
    for(int i=62;~i;i--)
    {
        for(int j=k;j<=n;j++){
            if(a[j]>>i & 1){
                swap(a[j],a[k]);
                break;
            }
        }

        if((a[k]>>i & 1) == 0)continue;

        for(int j=1;j<=n;j++){
            if(j!=k && (a[j]>>i & 1)){
                a[j]^=a[k];
            }
        }
        k++;
        if(k==n+1)break;
    }

    for(int i=1;i<=n;i++){
        for(int j=62;~j;j--)cout<<((a[i]>>j) & 1)<<" ";cout<<endl;
    }


    for(int i=1;i<=k;i++)a[i]^=a[i-1];
    cout<<a[k-1]<<endl;



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