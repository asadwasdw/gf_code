#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int dp[N];

void solve()
{
    string s;
    cin>>s;
    int n = s.size();
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<=n;i++) {
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=mod;
    }    

    vector<string> T = {"mygo","m ygo","my go","myg o","m y go","m yg o","my g o","m y g o"};


    s=" "+s +"gfgfgfgf";
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(auto t:T) {
            string t2 = s.substr(i,t.size());
            bool ky = true;
            for(int j=0;j<t2.size();j++) {
                if(t[j]==' ')continue;
                if(t[j] != t2[j])ky = false;
            }
            if(ky)ans += dp[i-1] * dp[n - t2.size() - i + 1];
            ans %= mod;
        }

    }
    cout<<ans<<endl;

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