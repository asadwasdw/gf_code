#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    vector<vector<int>> a(10);
    a[2].push_back(1);
    a[3].push_back(2);
    a[4].push_back(3);
    for (int i = 0; i < 12; i++) {
        int x, y;cin >> x >> y;
        int idx = 0, idy = 0;
        for (int j = 1; j <= 9; j++) {
            for (int k = 0; k < a[j].size(); k++) {
                if (a[j][k] == x) {
                    idx = j, idy = k;
                                
                }
            }
        }
        for (int j = idy; j < a[idx].size(); j++) {
            a[idx + y].push_back(a[idx][j]);
        }

        while (a[idx].size() > idy) a[idx].pop_back();
    }
    // for (int i = 1; i <= 9; i++) cout << a[i].size() << ' ';
    if (a[9].size() == 3) cout << "Y\n";
    else cout << "N\n";

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}