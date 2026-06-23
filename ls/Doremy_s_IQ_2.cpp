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

int a[N];


void solve()
{

    int n; cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + n + 1);

    vector<int> v;

    auto check = [&](int x, int X) -> bool {
        int len = X - x;
        return (len <= v.size() && v)
    }


    auto js = [&](int x) -> int {

        int len = 1;
        int X = x;
        while(len) {
            if(check(x, X + len)) {
                len *= 2;
                X += len;
            }
            else {
                len /= 2;
            }
        }
        int num = upper_bound(v.begin(), v.end(),X) - v.begin();
        num = min(num, (int)v.size() - (X - x));
        return num;
    };

    auto calc = [&]() -> int {
        v.clear();
        int res = 0;
        deque<int> f;
        for(int i = 1; i <= n; i ++) {
            if(a[i] < 0) f.push_back(a[i]);
            else v.push_back(a[i]);
        }
        int x = 0, w = 0;

        while(f.size()) {
            if(f.front() < x) {
                x--;
                f.pop_front();
            }
            else break;
            while(f.size() && f.back() >= x) {
                w++;
                f.pop_back();
            }

            res = max(res, js(x) + w);
        }
    };






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