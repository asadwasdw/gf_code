#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


struct P{
    int id,sum;
};

struct tj{
    int sum,id;
    inline bool operator > (const tj &x) const {//小根堆，重载大于号，小的在前面
        return sum>x.sum;
    }
};

struct XM{
    int k;
    vector<P>jl;
}xm[N];

unordered_map<int,int>cnt;
unordered_map<int,priority_queue<tj,vector<tj>,greater<tj>>>gf;

void solve()
{
    int g;
    cin>>g;
    while(g--)
    {
        int t,u;
        cin>>t>>u;
        cnt[t]+=u;
    }
    int n;cin>>n;
    int ans = 0;
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        xm[i].k=k;

        while(k--)
        {
            int t,u;
            cin>>t>>u;
            if(cnt[t]>=u){
                xm[i].k--;
            }
            else 
            {
                gf[t].push({u,i});
            }
        }

        if(xm[i].k==0){
          //  cout<<i<<endl;
            ans++;
            q.push(i);
        }
        cin>>k;
        while(k--)
        {
            int t,u;
            cin>>t>>u;
            xm[i].jl.push_back({t,u});
            //cout<<i<<" "<<t<<" "<<u<<endl;
        }
    }


    while(q.size())
    {
        int u = q.front();q.pop();
        for(auto t:xm[u].jl){
            //cout<<u<<" "<<t.id<<endl;    
            cnt[t.id]+=t.sum;
            while(gf[t.id].size()&&gf[t.id].top().sum<=cnt[t.id]){
                xm[gf[t.id].top().id].k--;
                if(xm[gf[t.id].top().id].k==0)q.push(gf[t.id].top().id),ans++;
                gf[t.id].pop();
            }

        }
    }


    cout<<ans<<endl;







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