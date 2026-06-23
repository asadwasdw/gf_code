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
using db = long double;

void solve()
{
    vector<array<int, 2>> a, b, c;
    auto read = [&]() -> array<int, 2> {
        string s; cin >> s;
        return array<int, 2> ({s[0] - 'A', stoi(s.substr(1))});
    };
    for (int i = 0; i < 2; i++) a.push_back(read());
    for (int i = 0; i < 2; i++) b.push_back(read());
    for (int i = 0; i < 5; i++) c.push_back(read());
    auto calc = [&](vector<array<int, 2>> a) -> db {
        sort(a.begin(), a.end());
        db res = 0;
        do {
            auto getpow = [&](int id1, int id2) -> db {
                if (id1 == 0 && id2 == 1 ) {
                    return (2);
                }
                if (id1 == 0 && id2 == 3 ) {
                    return (1.5);
                }
                if (id1 == 0 && id2 == 4 ) {
                    return (1.5);
                }
                if (id1 == 1 && id2 == 4 ) {
                    return (1.5);
                }
                if (id1 == 1 && id2 == 2 ) {
                    return (1.5);
                }
                if (id1 == 1 && id2 == 3 ) {
                    return (3);
                }
                if (id1 == 3 && id2 == 4 ) {
                    return (1.5);
                }
                if (id1 == 2 && id2 == 4 ) {
                    return (2);
                }
                if (id1 == 0 && id2 == 2 ) {
                    return (2);
                }
                return 1;
            };
            auto get = [&](array<int, 2> a, array<int, 2> b) -> db {
                auto [id1, v1] = a;
                auto [id2, v2] = b;
                return getpow(id1, id2) * (v1 + v2);
            };
            auto get2 = [&](array<int, 2> a, array<int, 2> b, array<int, 2> c) -> db {
                auto [id1, v1] = a;
                auto [id2, v2] = b;
                auto [id3, v3] = c;
                if (id3 == 6) return getpow(id1, id2) * (v1 + v2 + v3);
                if (id1 == 0 && id2 == 2 && id3 == 4) return 4 * (v1 + v2 + v3);
                if (id1 == 0 && id2 == 1 && id3 == 2) return 4 * (v1 + v2 + v3);
                return v1 + v2 + v3;
            };
            if (a.size() == 5) {
                res = max(res, get2(a[0], a[1], a[2]) + get(a[3], a[4]));
                res = max(res, get(a[0], a[1]) + get(a[2], a[3]) + a[4][1]);
            } else {
                res = max(res, get2(a[0], a[1], a[2]));
                res = max(res, get(a[0], a[1]) + a[2][1]);
            }
        }while (next_permutation(a.begin(), a.end()));
        return res;
    };
    db mxa = 0, mxb = 0;
    for (int i = 0; i < 5; i++)
    for (int j = i + 1; j < 5; j++)
    for (int k = j + 1; k < 5; k++) {
        vector<array<int, 2>> d;
        d.push_back(c[i]);
        d.push_back(c[j]);
        d.push_back(c[k]);
        
        d.push_back(a[0]), d.push_back(a[1]);
        mxa = max(mxa, calc(d));
        d.pop_back(), d.pop_back();

        d.push_back(b[0]), d.push_back(b[1]);
        mxb = max(mxb, calc(d));
        d.pop_back(), d.pop_back();
    }

    vector<array<int, 2>> e;
    for (int i = 0; i < 7; i++)
    for (int j = 1; j <= 10; j++) {
        bool ok = true;
        for (auto t : {a, b, c}) {
            for (auto x : t) {
                if (x[0] == i && x[1] == j) ok = false;
            }
        }
        if (ok) e.push_back({i, j});
    }
    for (int k = 0; k < e.size(); k++) {
        vector<array<int, 2>> d;
        d.push_back(e[k]);
        
        d.push_back(a[0]), d.push_back(a[1]);
        mxa = max(mxa, calc(d));
        d.pop_back(), d.pop_back();

        d.push_back(b[0]), d.push_back(b[1]);
        mxb = max(mxb, calc(d));
        d.pop_back(), d.pop_back();
    }
    cout << mxa << ' ' << mxb << '\n';
    if (mxa <= mxb) cout << "Lose!\n";
    else cout << "Win!\n";
} 


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(2) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}