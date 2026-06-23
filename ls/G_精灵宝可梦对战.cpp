    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef pair<int,int>PII;
    #define int ll
    const int N=1e6+10;
    const int mod=998244353;
    const int INF  = 0x3f3f3f3f;
    const ll INFll  = 0x3f3f3f3f3f3f3f3f;

    //vector<vector<int>>edg(N);

    struct node {
        int h, a, b, c, d, e, w, nowe;
    };

    void solve()
    {
        int n, m, k;cin >> n >> m >> k;
        int res = 0;
        deque<node> qa, qb;
        for (int i = 0; i < n; i++) {
            int h, a, b, c, d, e, w;
            cin >> h >> a >> b >> c >> d >> e >> w;
            qa.push_back({h, a, b, c, d, e, w, 0});
        }
        for (int i = 0; i < m; i++) {
            int h, a, b, c, d, e, w;
            cin >> h >> a >> b >> c >> d >> e >> w;
            qb.push_back({h, a, b, c, d, e, w, 0});    
        }
        for (int i = 1; i <= k; i++) {

            {
                node now = qa.front(); qa.pop_front();
                node ne = qb.front(); qb.pop_front();
                
                int val = max(max(0ll,now.a - ne.c), max(0ll, now.b - ne.d));
                if (now.nowe >= now.e && now.w > val) val = now.w, now.nowe -= now.e;
                else now.nowe++;
                ne.h -= val;

                qa.push_back(now);
                if (ne.h > 0) qb.push_front(ne);
                if (qb.size() == 0) {
                    res = 1;
                    break;
                }
            }
            {
                node now = qb.front(); qb.pop_front();
                node ne = qa.front(); qa.pop_front();
                
                int val = max(max(0ll,now.a - ne.c), max(0ll, now.b - ne.d));
                if (now.nowe >= now.e && now.w > val) val = now.w, now.nowe -= now.e;
                else now.nowe++;
                ne.h -= val;

                qb.push_back(now);
                if (ne.h > 0) qa.push_front(ne);    
                if (qa.size() == 0) {
                    res = 2;
                    break;
                }
            }
        }

        if (res == 0) {
            cout << "Draw\n";
        }else if (res == 1) {
            cout << "Alice\n";
        }else {
            cout << "Bob\n";
        }




    }


    signed main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0),cout.tie(0);
        int t;t=1;
        //cin>>t;
        for(int i=1;i<=t;i++){
            //printf("Case %d: ",i);
            solve();
        }
    }