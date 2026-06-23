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

int a[N];

int t[1005][1005];

int sg(int l, int r) {
    if (t[l][r] != -1) return t[l][r];
    if (l > r) return 0;
    if ((a[r] ^ a[l - 1]) == 0) return 0;
    set<int> s;
    s.insert(sg(l + 1, r));
    s.insert(sg(l, r - 1));
    int tmp = 0;
    while (s.find(tmp) != s.end())tmp++;
    return t[l][r] = tmp;
}
void solve()
{
    // for (int i = 0; i < 1005; i++)
    // for (int j = 0; j < 1005; j++)
    //     t[i][j] = -1;
    
    // for(int i = 1; i <= 4; i ++) {
    //     for(int j = 1; j<= 4; ++j)cout << sg(i, j) << ' ';
    //     cout << endl;
    // }
    
    // for (int i = 1; i <= 100; i++) {
    //     cout << sg(1, i) << ' ';
    // }
    int n; cin >> n;
    if (n % 4 <= 1 ) cout << "Fluttershy\n";
    else cout << "Pinkie Pie\n";
    

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for (int i = 1; i < N; i++) {
        a[i] = a[i - 1] ^ i;
    }
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}