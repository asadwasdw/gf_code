#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+30;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

struct node{
    char t;
    int x,y;
    inline bool operator > (const node &x) const {//小根堆，重载大于号，小的在前面
        return t>x.t;
    }
};

void solve()
{
    int n,m; cin >> n >> m;
    vector<vector<char>> a(n + 10, vector<char>(m+10));
    vector<vector<PII>> pre(n + 10, vector<PII>(m+10));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }

    if(n == 1 && m == 1) {
        cout << a[1][1] ;
        return ;
    } 

    priority_queue<node,vector<node>,greater<node>> q;
    priority_queue<node,vector<node>,greater<node>> q2;
    q.push({a[1][1],1,1});
    char now = a[1][1];
    pre[n][m] = {-1,0};

    while(pre[n][m].first == -1) {
        while(q.size()) {
           
            auto T = q.top();q.pop();
        
            if(now != T.t)continue;
            if(T.x != n) {
                q2.push({a[T.x + 1][T.y],T.x + 1,T.y});
                pre[T.x + 1][T.y] = {T.x, T.y};
            }
            
            if(T.y != m) {
                q2.push({a[T.x][T.y + 1],T.x,T.y + 1});
                pre[T.x][T.y + 1] = {T.x, T.y};
            }
        }

        while (q2.size())
        {
            auto T = q2.top();q2.pop();
            q.push(T);
        }   
        now = q.top().t;
    
    }

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1;j <= m;j ++) cout << "("<<pre[i][j].first <<","<<pre[i][j].second<<") ";
    //     cout << endl;
    // }

    stack<char>s;
    int x = n, y = m;
    while(!(x == 0 && y == 0)) {
        s.push(a[x][y]);
        PII t = pre[x][y];
        x = t.first;
        y = t.second;
    }
    // cout << a[1][1];
    while(s.size()) {
        cout << s.top();s.pop();
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