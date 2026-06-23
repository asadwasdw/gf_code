#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
#define int long long
const int N=1e6+10;
const int mod=998244353;
const int INF  = 1e9;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{

    int n;cin >> n;
    vector<array<int, 6>> ask;
    ask.push_back({1ll, -INF, -INF, INF, INF, 46ll});
    for (int i = 0; i < n; i++) {
        string s;cin >> s;
        if (s == "Circle") {
            char col;
            int x1, y1, r1; cin >> x1 >> y1 >> r1 >> col;
            ask.push_back({0ll, x1, y1, r1, 0ll, col});
        }else if (s == "Rectangle") {
            char col;
            int x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2 >> col;
            ask.push_back({1ll, x1, y1, x2, y2, col});
        }else {
            int x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;
            int res = 0;

            auto calc = [&](int x, int y) -> int{
                
                for (int i = ask.size() - 1; i >= 0; i--) {
                    if (ask[i][0] == 0) {
                        int x1 = ask[i][1], y1 = ask[i][2], r = ask[i][3];
                        if ((x - x1) * (x - x1) + (y - y1) * (y - y1) <= r * r) {
                            return ask[i][5];
                        } 

                    }else {
                        int x1 = ask[i][1], y1 = ask[i][2], x2 = ask[i][3], y2 = ask[i][4];
                        if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
                            return ask[i][5];
                        }
                    }
                }
                
            };

            for (int j = y2; j >= y1; j--) {
                for (int k = x1; k <= x2; k++) {
                    cout << (char)calc(k, j);
                }
                cout << '\n';
            }
        }
        
    }





}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}