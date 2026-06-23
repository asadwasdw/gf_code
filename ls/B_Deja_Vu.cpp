    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef pair<int,int>PII;
    const int N=1e6+10;
    const int mod=998244353;
    const int INF  = 0x3f3f3f3f;
    const ll INFll  = 0x3f3f3f3f3f3f3f3f;
    #define int long long

    //vector<vector<int>>edg(N);

    int a[N];

    void solve()
    {
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++)cin>>a[i];
        set<int>s;
        vector<int>ans;
        for(int i=1;i<=q;i++){
            int x;cin>>x;
            if(s.count(x))continue;
            ans.push_back(x);
            s.insert(x);
        }
        for(int i=1;i<=n;i++){
            
            for(auto t:ans){
                if(a[i]%(1<<t)==0){
                    a[i]+=(1<<(t-1));
                }
            }
            cout<<a[i]<<" ";
        }cout<<endl;

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
       