#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define int long long
//vector<vector<int>>edg(N);

int a[N];
int n,m;

int js(int x) {
    int ans = 0;
    vector<int>v;
    for(int i = 1;i <= n;i++){
        int t = a[i];
        int cnt = 0;
        int res = abs(t - x);
        while(t > x / 2) {
            res = min(abs(t - x) + cnt,res);
            cnt ++;
            t/=2;
        }
        v.push_back(res);
    }
    sort(v.begin(),v.end());
    int num = n - m;
    for(auto t:v) {
        ans+=t;
        num -- ;
        if(!num)break;
    }
   // cout<<x<<" "<<ans<<endl;
    return ans;

}




void solve()
{
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans = INF;
    for(int i = 1;i<=n;i++){
        int t = a[i];
        while(t) {
            ans = min(ans, js(t));
            t/=2;
        }
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