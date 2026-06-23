#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
using namespace std;
const int N=2e3+10;

unordered_map<int,vector<int>>edgs;

int ST[N][N];
int res;
int st[N];
int n,m;


void bfs(int u)
{
    set<int>ans;
    memset(st,0,sizeof st);
    queue<int>q;
    q.push(u);

    while(q.size())
    {
       
        int t=q.front();
        q.pop();
        //cout<<t<<endl;
       for(auto i:edgs[t]){
            if(i==u)continue;
            if(st[i])continue;
            st[i]=st[t]+1;
            ans.insert(i);
            q.push(i);
        }
    }

    res+=ans.size()-edgs[u].size();

}




int main()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        edgs[a].push_back(b);
        if(a==b)res--;
    }

   
     
    for(int i=1;i<=n;i++)
        bfs(i);
    
    cout<<res<<endl;


}