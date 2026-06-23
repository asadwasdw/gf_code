#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>>edg(N);
int d[N];
bool st[N];
vector<int>ans;


int cnt = 0;
void bfs(int x)
{
    queue<int>q;
    q.push(x);
    st[x]=true;

    while(q.size())
    {
        auto t =q.front();q.pop();
        //if(st[t])continue;
        // st[t]=true;
        ans.push_back(t);

        for(auto v :edg[t]){
            if(st[v.first])continue;
            d[v.first]--;
            if(d[v.first]==0){

                q.push(v.first);
                st[v.first]=true;
            }
            v.second++;
            cnt++;
        }
    }


}


void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        edg[a].push_back({b,0});
        d[b]++;
    }

    for(int i=1;i<=n;i++)
    {
        if(!st[i]&&d[i]==0)
        {
            bfs(i);
        }
    }

    if(ans.size()==n)
    {
        cout<<"1"<<endl;
        for(auto t:ans)cout<<t<<" ";cout<<endl;
    }
    else 
    {
        cout<<"2"<<endl;
        for(int i=1;i<=n;i++)cout<<i<<" ";cout<<endl;
        for(int i=n;i;i--)cout<<i<<" ";cout<<endl;
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