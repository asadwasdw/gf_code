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

PII s[N];

void solve()
{
    int n, d, k;
    cin >> n >> d >> k;
    for(int i = 1; i <= k; i ++) {
        cin >> s[i].first >> s[i].second;
    }

    sort(s + 1, s + k + 1, [&](PII a, PII b){
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    priority_queue<int, vector<int>, greater<int> > q;

    int z = 1;

    int mx = 0, mxi = 0;
    int mn = INF, mni = 0;

    for(int i = 1; i + d - 1 <= n; i ++) {
        int j = i + d - 1;
        while(z <= k && s[z].first <= j) {
            q.push(s[z].second);
            z ++;
        }

        while(q.size() && q.top() < i) {
            q.pop();
        }

        if(q.size() > mx) {
            mxi = i;
            mx = q.size();
        }

        if(q.size() < mn) {
            mni = i;
            mn = q.size();
        }

        // cout << i << " " << j << " " << q.size() << endl;
    }
 
    cout << mxi << " " << mni << endl;
}


void solve2() {
    int n, d, k;
    cin >> n >> d >> k;

    for(int i = 1; i <= k; i ++) {
        cin >> s[i].first >> s[i].second;
    }

    int mx = 0, mxi = 0;
    int mn = INF, mni = 0;

    for(int i = 1; i + d - 1 <= n; i ++) {
        int cnt = 0;
        int l = i, r = i + d - 1;
        for(int j = 1; j <= k; j ++) {
            if(max(l, s[j].first) <= min(r, s[j].second)) cnt ++;
        }

        if(cnt > mx) {
            mxi = i;
            mx = cnt;
        }
        
        if(cnt < mn) {
            mni = i;
            mn = cnt;
        }
    }

    cout << mxi << " " << mni << endl;

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
        solve2();
    }
} 