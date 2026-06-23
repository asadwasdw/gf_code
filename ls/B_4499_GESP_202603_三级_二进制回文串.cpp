#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        string res; 
        int x = i;
        while(x) {
            res += x % 2 + '0';
            x /= 2;
        }
        string res2 = res;
        reverse(res.begin(), res.end()); // 翻转字符串
        if(res == res2) cnt ++;
    }
    cout << cnt;
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
    return 0;
}