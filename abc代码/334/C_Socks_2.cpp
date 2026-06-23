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
int s1[N];
int s2[N];

void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)cin>>a[i];
    if(k%2==0)
    {
        int ans = 0;
        for(int i=2;i<=k;i+=2){
            ans+=a[i]-a[i-1];
        }
        cout<<ans<<endl;
    }
    else {
        for(int i=1;i<=n;i++)
        {
            s1[i]=s1[i-1];
            s2[i]=s2[i-1];

            if(i%2){
                s1[i]+=a[i];
            }
            else s2[i]+=a[i];
        }
        int ans = INF;
        for(int i=1;i<=n;i++){
            ans = min(ans, abs(s2[i-1]-s1[i-1]) +  abs(s1[n]-s1[i] - (s2[n] - s2[i])));
        }
        cout << ans << endl;
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