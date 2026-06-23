    #include<bits/stdc++.h>
    #define int short
    using namespace std;
    typedef long long ll;
    typedef pair<int,int>PII;
    const int N=25;
    const int mod=998244353;
    const int INF  = 0x3f3f3f3f;
    const ll INFll  = 0x3f3f3f3f3f3f3f3f;
    #define endl "\n" 

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    //vector<vector<int>>edg(N);
    int n,m;
    int a[N][N];
    vector<PII> now;
    vector<PII> sum;

    bool st[20][20];

    inline bool bfs(int sx,int sy) {
        bool res = false;
        queue<PII> q;
        q.push({sx, sy});
        while(q.size()) {
            auto [x, y] = q.front();q.pop();
            if(st[x][y]) continue;
            now.push_back({x, y});
            sum.push_back({x,y});
            st[x][y] = true;
            for(int i = 0; i < 4; i ++ ) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if(tx < 1 || tx > 19 || ty < 1 || ty > 19) continue;
                if(a[tx][ty] == 0) res = true;
                else if(a[tx][ty] == a[sx][sy]) {
                    q.push({tx, ty});
                }
            }
        }
        return res;
    }

    inline void clear() {
        for(auto [x, y] : now) a[x][y] = 0;
    }

    stack<int>s;
    inline int clearwhite() {
        int res = 0;
        // memset(st, 0, sizeof st);
        for(int i = 1; i <= 19; i ++) {
            for(int j = 1; j <= 19; j ++) {
                if(a[i][j] != -1) continue;
                if(st[i][j]) continue;
                now.clear();

                if(!bfs(i, j)) {
                    res += now.size();
                    clear();
                }
            }
        }

        return res;
    }

    inline int clearblack() {
        int res = 0;
        // memset(st, 0, sizeof st);
        for(int i = 1; i <= 19; i ++) {
            for(int j = 1; j <= 19; j ++) {
                if(a[i][j] != 1) continue;
                if(st[i][j]) continue;
                 now.clear();

                if(!bfs(i, j)) {
                    res += now.size();
                    clear();
                }
            }
        }

        return res;
    }



    void solve()
    {
        ll n;
        // scanf("%lld",&n);
        cin >> n;
        for(ll i = 1; i <= n; i ++) {
            int x, y;
            cin >> x >> y;
            // scanf("%d %d\n",&x, &y);
            int ans1 = 0, ans2 = 0;
            if(i % 2) {
                a[x][y] = 1;
                ans1 = clearwhite();
                ans2 = clearblack();
            }
            else {
                a[x][y] = -1;
                ans2 = clearblack();
                ans1 = clearwhite();
            }

            for(auto [x, y] : sum) st[x][y] = 0;
            sum.clear();
            // printf("%d %d\n", ans2, ans1);
            cout << ans2 << " " << ans1 << endl;
        }
    }


    signed main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0),cout.tie(0);
        // cout << setprecision(11) << fixed;
        int t;t=1;
        //cin>>t;
        for(int i=1;i<=t;i++){
            //printf("Case %d: ",i);
            solve();
        }
    }