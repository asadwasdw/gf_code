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

map<array<int,3>, int> SG;

int sg(array<int,3> a) {

    if(SG.count(a)) return SG[a];

    set<int> s;
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 3; j ++) {
            if(i == j) continue;
            for(int k = 1; k < a[i]; k ++) {
                array<int,3> b = a;
                b[i] = k, b[j] = a[i] - k;
                sort(b.begin(), b.end());
                s.insert(sg(b));
            }
        }
    }

    int res = 0;
    while(s.count(res)) res++;
    return SG[a] = res;
}

int js(int x, int y, int z) {

    int ans = 1;

    if(x == y && y == z) {
        ans = 0;
    } else if(x%2 == y%2 && x%2 == z%2) {

        while(x%2 == 0 && x%2 == y%2 && x%2 == z%2) {
            x/=2, y/=2, z/=2;
        }

        if( x%2 == y%2 && x%2 == z%2 && x%2 == 1) ans = 0;

    }
    return ans;
}

void solve()
{
    // int n; cin >> n;
    // for(int i = 1; i <= n; i ++) {
    //     for(int j = i; j <= n; j ++) {
    //         for(int k = j; k <= n; k ++) {
    //             array<int,3> a;
    //             a[0] = i;
    //             a[1] = j;
    //             a[2] = k;
    //             // if(sg(a) == 0)
    //             // if(i%2==j%2 && i%2==k%2 && i%2 == 0)
    //             // cout << i/2 << " " << j/2 << " " << k/2 << " - " << sg(a) << " " << i + j + k << endl;
    //             int ans1 = js(i, j, k); 
    //             int ans2 = sg({i, j, k});
    //             if(ans2) ans2 = 1;
    //             if(ans1 != ans2) {
    //                 cout << i << " " << j << " " << k << endl;
    //                 cout << ans1 << " " << ans2 << endl;
    //             }
    //         }
    //     }
    // } 

    int x, y, z;
    cin >> x >> y >> z;
    if(js(x, y, z)) cout << "YES\n";
    else cout << "NO\n";

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