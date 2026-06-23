#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);


void solve()
{
    map<int,int> cnt;
    map<int,int> id;
    int n; 
    cin >> n;

    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        cnt[x] ++;
        id[x] = i;
    } 
    
    int ans = -1;
    for(auto[x, y] : cnt) {
        if(y == 1) {
            ans = max(ans, x);
        }
    }
    id[-1] = -1;
    cout << id[ans]; 








}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}