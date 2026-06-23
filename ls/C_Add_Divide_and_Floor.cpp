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
void solve()
{
    int n;
    cin>>n;
    int mx = 0, mn = 1e18+1;

    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        mx = max(x, mx);
        mn = min(x, mn);
    }

    if(mx == mn){
        cout<<"0\n";
    }
    else 
    {
       
        int res = 0;
        vector<int>ans;
        while(mx != mn) {
            if((mx-mn)%2){
                res = mn%2;
            }
            else res = 0;
            ans.push_back(res);
            mx = (res + mx)/2;
            mn = (res + mn)/2;
            //cout << mn << " " << mx << endl;
        }
        cout<<ans.size()<<"\n";
        if(ans.size() <= n) {
            for(auto t : ans) cout << t << ' ';
        } cout << '\n';
      
    }



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