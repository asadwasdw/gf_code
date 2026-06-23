#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define id second

//vector<vector<int>>adj(N);


void solve()
{
    int n;
    cin >> n;
    vector<PII> v(n + 1);
    set<int> s;
    for(int i = 1; i <= n; i ++) {
        cin >> v[i].first >> v[i].second;
        s.insert(v[i].id);
    }

    sort(v.begin() + 1, v.end(),[&](PII a, PII b){
        return a.x < b.x;
    });

    map<int,int> num;
    int cnt = 0;
    int ans = INF;

    for(int r = 1, l = 1; r <= n; r ++) {
        if(num[v[r].id] == 0) cnt ++;
        num[v[r].id] ++;

        while(num[v[l].id] > 1) {
            num[v[l].id] --;
            l ++;
        }

        if(cnt == s.size())ans = min(ans, v[r].x - v[l].x);
        // cout << l << " " << r << " " << cnt << " " << v[r].x - v[l].x << endl;
    }
    cout << ans;
}

void solve2() {
    int n;
    cin >> n;
    vector<PII> v(n + 1);
    set<int> s;
    for(int i = 1; i <= n; i ++) {
        cin >> v[i].first >> v[i].second;
        s.insert(v[i].id);
    }

    map<int,int> num;

    sort(v.begin() + 1, v.end(),[&](PII a, PII b){
        return a.x < b.x;
    });

    queue<PII> q;
    int cnt = 0;
    int ans = INF;
    for(int i = 1; i <= n; i ++) {
        if(num[v[i].id] == 0) cnt ++;
        num[v[i].id] ++;
        q.push(v[i]);
        while(q.size() && num[q.front().id] > 1) {
            num[q.front().id] --;
            q.pop();
        }

        if(cnt == s.size() && q.size()) {
            ans = min(ans, v[i].x - q.front().x);
            // cout << v[i].x << " " << q.front().x << endl;
        }
    }
    cout << ans << endl;

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
        solve2();
    }
    return 0;
}