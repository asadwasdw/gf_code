#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

unordered_map<int,int>mp;

void solve()
{
    mp.clear();
    int n;cin>>n;

    for(int i = 1; i <= n; i++){
        int x; cin>>x;
        
        for(int j = 2; j * j <= x; j++) {
            if( x % j == 0){
                while(x % j == 0){
                    mp[j]++;
                    x /= j;
                }
                
            }
        }
        if(x > 1) mp[x]++;
    }
    
    bool ky = true;
    for(auto t: mp) {
       // cout<<t.first<<" "<<t.second<<endl;
        if(t.second % n) ky = false;
    }
    if(ky)cout<<"YES\n";
    else cout<<"NO\n";

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