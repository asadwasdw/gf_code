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


void solve()
{

    vector<array<int, 2>> a(4);
    for (int i = 0; i < 4; i++) {
        cin >> a[i][0] >> a[i][1];
        if (a[i][0] > a[i][1]) swap(a[i][0], a[i][1]);
    }
    sort(a.begin(), a.end());

    auto check = [&](vector<array<int, 2>> b) -> bool {
        int n = b[0][1];
        if (n == b[0][0] + b[1][0] && b[1][0] == b[2][0] && b[2][0] == b[3][0] && b[1][1] + b[2][1] + b[3][1] == n)
            return true;
        if (n == b[0][0] + b[1][0] && b[1][1] + b[2][1] == n && b[2][1] == b[3][1] && b[0][0] + b[2][0] + b[3][0] == n)
            return true;
        if (n == b[0][0] + b[1][0] + b[2][0] && b[1][1] == n && b[2][0] == b[3][0] && b[2][1] + b[3][1] == n)
            return true;
        if (n == b[0][0] + b[1][0] + b[2][0] + b[3][0] && b[1][1] == n && b[2][1] == n && b[3][1] == n)
            return true;

        n = b[0][1] + b[1][1];
        if (b[0][0] + b[2][0] == n && b[1][0] + b[3][0] == n) {
            if (b[0][0] == b[1][0] && b[2][1] + b[3][1] == n) return true;
            if (b[0][0] != b[1][0] && b[0][1] == b[2][1] && b[1][1] == b[3][1]) return true;
        }
        return false;
    };

    do {
        for (int i = 0; i < (1 << 4); i++) {
            auto b = a;

            for (int j = 0; j < 4; j++) {
                if ((i >> j) & 1) swap(b[j][0], b[j][1]);
            }
            if (check(b)) {
                cout << "Yes\n";
                return;
            }
        }
    }while (next_permutation(a.begin(), a.end()));

    cout << "No\n";


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