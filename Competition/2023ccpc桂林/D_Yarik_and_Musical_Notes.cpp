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
unordered_map<int,int>num;

void solve()
{
    num.clear();
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        num[x]++;
    }

    int ans = 0;

    for(auto t:num) {
        if(t.second>=2) {
          //  cout<<t.first<<" "<<t.second<<" "<<t.second*(t.second-1)*2<<endl;
            ans += t.second*(t.second-1)/2;
        }
    }

    ans+=(num[1]*num[2]);
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