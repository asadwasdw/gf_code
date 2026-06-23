#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int n,m;

bool tppx(vector<vector<int>>edg,vector<int>d)
{
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(d[i]==0)q.push(i);
    }
    int cnt = 0;

    while(q.size())
    {
        auto t = q.front();q.pop();
        cnt++;
        for(auto T :edg[t]){
            // if(T==t)cnt=n+1;
            d[T]--;
            if(!d[T])q.push(T);
        }
    }

    return cnt==n;
}

int bfs(vector<vector<int>>edg,int u)
{

    vector<int>st(n+10);
    queue<int>q;
    q.push(u);
    set<int>s;
    st[u]=true;
    while(q.size()){
        
        auto t= q.front();q.pop();
       
        //cout<<t<<endl;
        s.insert(t);
        for(auto T : edg[t])
        {
            if(st[T])continue;
            st[T]=true;
            q.push(T);
        }
    }
    //cout<<cnt<<endl;
    return s.size()-1;

}

void solve()
{
   
    cin>>n>>m;

    vector<vector<int>>edg1(n+10);
    vector<vector<int>>edg2(n+10);
    vector<int>d(n+10);

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        //cout<<a<<b<<endl;
        edg1[a].push_back(b);
        edg2[b].push_back(a);
        d[b]++;
    }

    if(!tppx(edg1,d)){
        for(int i=1;i<=n;i++)cout<<"0";cout<<endl;
        return;
    }

    //bfs(edg1,1);


    for(int i = 1;i<=n;i++)
    {
       // cout<<bfs(edg1,i)<<" "<<bfs(edg2,i)<<endl;
        int t1=bfs(edg1,i);
        int t2=bfs(edg2,i);
        if(t1<(n+1)/2&&t2<(n+1)/2){
            cout<<"1";
        }
        else cout<<"0";
    }

    cout<<endl;



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