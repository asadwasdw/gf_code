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

struct node{
    int l, r, w;
};

void solve()
{
    int q; cin >> q;
    stack<node> s;
    while(q -- ) {
        int op, x;
        cin >> op;
        // cout << op << endl;
        if(op == 1) {
            int x; cin >> x;
            node t; t.l = s.size(); t.r = s.size(); t.w = x;
            // node t = (node){s.size(),s.size(), x};
            if(s.size() && s.top().w == x) {
                node tp = s.top(); s.pop();
                tp.r ++;
                s.push(tp);
            } else s.push(t);
        } else if(op == 2) {
            node tp = s.top(); s.pop();
            tp.r --;
            if(tp.r >= tp.l)s.push(tp);  
        } else if(op == 3) {
            cout << s.top().w << endl;
        } else {
            cin >> x;
            int cnt = 0;
            int l = INF, r = 0, w = 0, lastw = 0;
            while(cnt < x) {
                node tp = s.top(); s.pop();
                r = max(tp.r, r);
                l = min(tp.l, l);
                w = __gcd(w, tp.w);
                lastw = tp.w;
                cnt += tp.r - tp.l + 1;
            }
            node t1 = (node){r - x + 1, r, w};
            if(l != r - x + 1) s.push({l, r - x, lastw});
            s.push(t1);
        }
    }


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