#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
#define int long long
int a[N];

void solve()
{
    int mn = INF;
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans = 0;
    for(int i=n;i;i--) {
      //  cout<<a[i]<<" "<<mn<<endl;
        if(a[i]>mn) {
            int num = ((a[i]+mn-1)/mn);
            mn=min(mn,a[i]/num);
            ans+=(num-1);
        }
        mn=min(a[i],mn);
    }
    cout<<ans<<endl;

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