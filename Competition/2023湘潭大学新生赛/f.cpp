#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N=110;
string s[N];
unordered_map<int,vector<int>>edgs;
vector<int>ans;
int st[N];
int ST[N];

void bfs(int x)
{
    queue<int>q;
    q.push(x);
    st[x]=1;

    while(q.size())
    {
      
        int t=q.front();q.pop();
        //cout<<t<<endl;
        for(auto T:edgs[t]){
            st[T]++;
            if(st[T]==101){
                ans.push_back(T);
                ST[T]=true;
            }
            if(st[T]<=101)
            q.push(T);
        }
    }
}

void solve()
{
    edgs.clear();
    ans.clear();
    memset(st,0,sizeof st);
    memset(ST,0,sizeof ST);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }

    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x;
            cin>>x;
            edgs[i].push_back(x);
        }
    }

    bfs(m);
    if(!ans.size()){
        cout<<"No one is disturbed!"<<endl;
    }
    else {
        cout<<ans.size()<<endl;
        for(int i=1;i<=n;i++){
            if(ST[i]){
                cout<<s[i]<<" ";
            }
        }
        cout<<endl;
    }

}


int main()
{
    int t;cin>>t;while(t--)
    solve();
    return 0;
}
