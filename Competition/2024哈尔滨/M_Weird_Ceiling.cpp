#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int f(int a, int b) {
    int i = b;
    while(i >= 2) {
        if(a % i == 0) {
            return a/i;
        } else {
            i --;
        }
    }
    return a;
}

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1;  i<= n; i ++) ans += f(n, i);
    cout << ans << endl;


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
}