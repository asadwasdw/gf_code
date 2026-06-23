#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);



void solve()
{
    unordered_map<char,int>num;
    int n;cin>>n;
    int mx =0;
    for(int i=1;i<=n;i++) {
        char t;cin>>t;
        num[t]++;
        mx = max(mx,num[t]);
    }

    int ans = max(mx - (n-mx),n%2);
    num.clear();
    cout << ans << endl;







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