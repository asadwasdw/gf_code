#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    int n;cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<int> id(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        id[b[i]] = i;
    }
    int now = 0;
    deque<int> que;
    for (int i = 1; i <= n; i++) {
        a[i] = id[a[i]];
        que.push_back(a[i]);
    }
    
    string ans;
    while (now < n) {
        while (que.front() != now + 1) {
            que.push_back(que.front());
            que.pop_front();
            ans += '1';
        }
        int top = que.front(); que.pop_front();
        if (now == 0) {
            ans += '1';
            que.push_back(top);
        }else {
            while (que.front() != now) {
                que.push_back(que.front());
                que.pop_front();
                ans += '2';
            }
            que.push_back(que.front());
            que.pop_front();
            ans += '2';
            ans += '1';
            que.push_back(top);
        }
        now++;
    }
    cout << ans << '\n';
    





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