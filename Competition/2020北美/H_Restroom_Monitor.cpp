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
    int s, n;
    cin >> s >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;cin >> x;
        char c;cin >> c;
        if (c == 'y') {
            a.emplace_back(x);
        } else {
            b.emplace_back(x);
        }
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    for (int t = 1; !a.empty() || !b.empty(); t++) {
        int cnt = s;
        bool flag = false;
        while (cnt && ((!a.empty() && !flag) || !b.empty())) {
            if ((b.empty() || (!a.empty() && a.back() <= b.back())) && !flag) {
                a.pop_back();
                flag = true;
                cnt--;
                continue;
            }
            b.pop_back();
            cnt--;
        }
        if ((!a.empty() && a.back() <= t) || (!b.empty() && b.back() <= t)) {
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
    





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