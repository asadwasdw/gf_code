#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

const int N=4e5+10;
unordered_map<int,vector<int>> edgs;

int st[N];

bool bfs(int u)
{
    queue<int>q;
    q.push(u);
    int cntd=1;
    int cntb=0;
    st[u]=1;

    while(q.size())
    {
        int t=q.front();q.pop();
        //cout<<t<<endl;
        for(auto T:edgs[t]){
            cntb++;
            if(st[T])continue;
            st[T]=1;
            cntd++;
            q.push(T);
        }
    }
  //  cout<<cntd<<" "<<cntb<<endl;
    return (cntd*2)==cntb;

}

int main()
{
    int n,m;cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        edgs[a].push_back(b);
        edgs[b].push_back(a);
    }

 
   // for(auto T:edgs[1]) cout<<T<<" "; cout<<endl;
       
        
    

    
    bool ky=true;
    for(int i=1;i<=n;i++)
    {
        if(st[i])continue;
        if(bfs(i))continue;
       // cout<< i <<endl;
        ky=false;
    }

    if(ky)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}