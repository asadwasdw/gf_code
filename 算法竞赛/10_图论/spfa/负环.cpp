#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<cstring>
#include<queue>
//https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P3385
#define int long long 
using namespace std;
typedef pair<int,int>PII;

unordered_map<int,vector<PII>>edgs;

const int N=5e5+10;
int cnt[N];
bool st[N];
int dist[N];
int n,m;
bool spfa(int s)
{
    memset(cnt,0,sizeof cnt);
    memset(st,0,sizeof st);
    memset(dist,0x3f,sizeof dist);
    queue<int>q;
    q.push(s);
    st[s]=true;
    dist[s]=0;
    cnt[s]=1;
   while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=false;

       for(auto T:edgs[t])
        {
            int j=T.first;
            int w=T.second;

            if(dist[j]>dist[t]+w)
            {
                dist[j]=dist[t]+w;
               
                if(!st[j])
                {
                    q.push(j);
                    st[j]=true;
                    cnt[j]++;
                    if(cnt[j]>=n+1)return true;
                }
            }
        }

    }
    
    return false;

}




void solve()
{
    edgs.clear();
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        edgs[a].push_back({b,c});
        if(c>=0)edgs[b].push_back({a,c});

    }
    //or(auto t:edgs[1])cout<<t.first<<" ";cout<<endl;


    if(spfa(1))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    //   for(int i=1;i<=n;i++)cout<<cnt[i]<<" ";cout<<endl;
}



signed main()
{
    int t;cin>>t;while(t--)
    solve();
    return 0;
}
