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

bool sg(int p, int q, bool Alice) {
    // cerr << p << " " << q << endl;
    if(p == 0 && q == 1) {
        return true;
    }

    if(3 * p  == 2 * q) {
        return false;
    }

    if(Alice) {
        if(1.0 * p / q > 1.0 * 2 / 3 && q > 1) {
            return sg(p, q - 1, false);
        } else if(p > 0){
            return sg(p - 1, q, false);
        } else {
            return true;
        }
    } else {
        if(1.0 * p / q > 1.0 * 2 / 3 && q > 0) {
            return sg(p - 1, q , true);
        } else if(q - 1){
            return sg(p , q - 1, true);
        } else {
            return true;
        }
    }
}

int check(int p, int q) {
    if(p > 1 && p < q  && q * 2 <= p * 3) {
        return 0;
    }
    return 1;
}


void solve()
{
    // cerr << sg(1, 3, true) << endl; 
    // cout << sg(4, 6, true) << endl;
    // cout << sg(15, 15, true) << endl;

    // int n; cin >> n;
    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= n; j ++) {
    //         cout << sg(i, j, true) << " \n"[j == n];
    //         // cout << check(i, j) << " \n"[j == n];

    //         // if(!sg(i, j, true)) cout << i << " " << j << endl;
    //     }
    // }

    long long p, q;
    cin >> p >> q;
    if(p > 1 && p < q  && q * 2 <= p * 3) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
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
    return 0;
}


