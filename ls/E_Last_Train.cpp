    #include<bits/stdc++.h>
    #define int long long
    using namespace std;
    typedef long long ll;
    typedef pair<int,int>PII;
    const int N=1e6+10;
    const int mod=998244353;
    const int INF  = 0x3f3f3f3f3f3f3f3f;
    const ll INFll  = 0x3f3f3f3f3f3f3f3f;



    struct lx{
        int to;
        int l,d,k,c;
    };
    vector<vector<lx>>edg(N);

    __int128 get(__int128 t,__int128 l,__int128 d,__int128 k) {
        k--;
        if(t<l)return -INF;
        if(t>=(__int128)l+k*d)return l+k*d;
        return l + (t-l)/d*d;
    }
    int n,m;
    int f[N];
    int rd[N];


    void solve()
    {
        // cout<<get(6,2,3,100)<<endl;
        cin>>n>>m;
        for(int i=1;i<=m;i++) {
            int l,d,k,c,a,b;
            cin>>l>>d>>k>>c>>a>>b;
            edg[b].push_back({a,l,d,k,c});
            // rd[a]++;
        }
        memset(f,-1,sizeof f);
        f[n]=INF;
        priority_queue<PII>q;
        // queue<int>q;
        q.push({INF,n});
        while(q.size()) {
            int u = q.top().second;q.pop();
            if(rd[u])continue;
            rd[u]=1;
            for(auto T:edg[u]) {
                int v = T.to;
                int ans = get(f[u]-T.c,T.l,T.d,T.k);

                // cout<<u<<" "<<v<<endl;

                if(ans>f[v]) {
                    f[v]=ans;
                    q.push({f[v],v});
                }
            }
        }



        // for(int i=1;i<=n;i++)cout<<rd[i]<<" "<<i<<endl;

        for(int i=1;i<n;i++) 
        {
            // cout<<i<<" ";
            if(f[i]==-1)cout<<"Unreachable\n";
            else cout<<f[i]<<"\n";
            
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