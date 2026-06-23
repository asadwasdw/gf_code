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


int check(int x) {
    int cnt = 0;
    for(int i = x; i <= x + 20000; i ++) {
        int y = i;
        int sum = 0;
        while(y) {
            sum += y % 10;
            y /= 10;
        }
        if(i - sum == x) cnt ++;
    }
    cout << x << " " << cnt << endl;

    return cnt;
}

void solve()
{
     check(18);
    for(int i = 10000; i <= 11000; i ++) {
        check(i);
    }

    // int x;
    // cin >> x;

    // cout << check(x) << endl;

    // int x;
    // cin >> x;
    // if(x % 9 == 0) cout << "10\n";
    // else cout << "0\n";




}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        // printf("Case %d: ",i);
        solve();
    }
    return 0;
}

