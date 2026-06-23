    #include<iostream>
    #include<algorithm>
    using namespace std;
    typedef pair<int,int>PII;

    const int mod=998244353;
    const int INF  = 0x3f3f3f3f;
    
    const int N=1e2+10;
    char a[N][N];
    
    void solve()
    {
        int n,m;
        cin>>n>>m;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int x;
                cin>>x;
                char t;
                if(x==0)t='.';
                else t=x-1+'A';
                cout<<t;
            }
            cout<<endl;
        }
    }
    
    
    signed main()
    {
        ios::sync_with_stdio(false);
        int t;t=1;
        //cin>>t;
        for(int i=1;i<=t;i++){
            //printf("Case %d: ",i);
            solve();
        }
    }