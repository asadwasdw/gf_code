#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];


void solve()
{

    int c, d;cin >> c >> d;
    vector<int> vis1(d + 2, 1), vis2(d + 2, 1);

    auto calc = [&](int x) -> vector<int> {
        vector<int> res;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                res.push_back(i);
                if (i * i != x) res.push_back(x / i);
            }
        }
        return res;
    };
    auto get = [&](int x, int op) -> void {
        auto fc = calc(x);
        // for (auto c : fc) {
        //     cout << c << ' ';
        // }
        // cout << '\n';
        if (op == 0) {
            for (auto c : fc) {
                vis1[c] = vis2[c] = 0;
            }
        } else if (op == 1) {
            
            for (auto c : fc) {
                if (vis1[c] == 1)
                    vis1[c] = 2;
            }
            for (int i = 1; i <= d + 1; i++) {
                if (vis1[i] == 2) {
                    
                    vis1[i] = 1;
                }else {
                    vis1[i] = 0;
                }
            }
        } else if(op == 2){
            for (auto c : fc) {
                if (vis2[c] == 1)
                    vis2[c] = 2;
            }
            for (int i = 1; i <= d + 1; i++) {
                if (vis2[i] == 2) {
                    vis2[i] = 1;
                }else {
                    vis2[i] = 0;
                }
            }
        } else if (op == 3) {
            for (auto c : fc) {
                vis1[c] = 0;
            }
        } else if (op == 4) {
            for (auto c : fc) {
                vis2[c] = 0;
            }
        }
    };

    bool ok1 = false, ok2 = false;
    for (int i = c; i <= d; i++) {
        string t;cin >> t;
        if (t == "Fizz") {
            if (!ok1) {
                ok1 = true;
                get(i, 1);
            }
            get(i, 4);
        } else if (t == "Buzz") {
            if (!ok2) {
                ok2 = true;
                get(i, 2);
            }
            
            get(i, 3);
        } else if (t == "FizzBuzz") {
            if (!ok1) {
                ok1 = true;
                get(i, 1);
            }
            if (!ok2) {
                ok2 = true;
                get(i, 2);
            }
        } else {
            get(i, 0);
        }
    }

    for (int i = 1; i <= d + 1; i++) {
        if (vis1[i]) {
            cout << i << ' ';
            break;
        }
    }
    for (int i = 1; i <= d + 1; i++) {
        if (vis2[i]) {
            cout << i << '\n';
            break;
        }
    }


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