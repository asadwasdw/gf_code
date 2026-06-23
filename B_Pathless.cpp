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
    int n, s;
    cin >> n >> s;
    int sum = 0;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        cnt[x] ++;
        sum += x;
    }

    if(sum > s) {
        for(int i = 0; i <= 2; i ++) {
            while(cnt[i] --) cout << i << " ";
        }
        cout << endl;
    } else if(sum == s) {
        cout << -1 << endl;
    } else {

        cout << endl;
    }







}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}