#include<iostream>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<vector>
#include<cstring>

using namespace std;
const int N=2020;
int c[N];

typedef pair<int,int> PII;

unordered_map<int,vector<int> > edgs;

int st[N][N];

void solve()
{
    memset(st,0,sizeof st);
    edgs.clear();
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>c[i];

    for(int i=1;i<=m;i++)
    {

        int a,b;cin>>a>>b;
        edgs[a].push_back(b);
        edgs[b].push_back(a);
    }

    queue<PII>q;
    q.push({1,n});

    while(q.size())
    {
        PII T=q.front();q.pop();

        //cout<<T.first<<" "<<T.second<<endl;

        for(auto t1:edgs[T.first]){
        for(auto t2:edgs[T.second]){
            if(c[t1]!=c[t2]&&!st[t1][t2])
            {
                st[t1][t2]=st[T.first][T.second]+1;
                q.push({t1,t2});
            }
        }
        }
    }

    if(st[n][1])cout<<st[n][1]<<endl;
    else cout<<"-1"<<endl;
}

int main()
{
    int t;cin>>t;while(t--)
    solve();


}
