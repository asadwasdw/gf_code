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
int b[N],a[N];

struct Node{
    int x, y;
    int id;
}no[N];


bool cmp(Node a, Node b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
int f[N];
int find(int x) {
    if(f[x] != x ) return f[x] = find(f[x]);
    return f[x];
}


void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        f[i] = i;
        cin >> a[i] >> b[i];
        
    }

    {
        for(int i = 1; i <= n; i ++) {
            no[i] = {a[i] - i, i - b[i], i};
        }

        sort(no + 1, no + n + 1,cmp) ;
        // for(int i = 1; i <= n; i ++) cout << no[i].y << endl;
        stack<PII>s;

        for(int i = 1; i <= n; i ++) {
            while(s.size() && s.top().first > no[i].y) s.pop();
            if(s.size()) {
                int u = s.top().second;
                int v = no[i].id;
                // cout << u << " " << v << endl;
                u = find(u), v = find(v);
                f[u] = v;
            }
            s.push({no[i].y,no[i].id});
        }
    }

    {

        for(int i = 1; i <= n; i ++) {
            no[i] = {-(i - b[i]), -(a[i] - i),i};
        }

        sort(no + 1, no + n + 1,cmp) ;
        // for(int i = 1; i <= n; i ++) cout << no[i].y << endl;
        stack<PII>s;

        for(int i = 1; i <= n; i ++) {
            while(s.size() && s.top().first > no[i].y) s.pop();
            if(s.size()) {
                int u = s.top().second;
                int v = no[i].id;
                // cout << u << " " << v << endl;
                u = find(u), v = find(v);
                f[u] = v;
            }
            s.push({no[i].y,no[i].id});
        }
    }



    int res = 0;
    for(int i = 1; i <= n; i ++) {
        if(find(i) == i) res++;
    }
    cout << res << endl;

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