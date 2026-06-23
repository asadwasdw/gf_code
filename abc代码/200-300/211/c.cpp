#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N=2e5+10;
map<int,vector<int>>mp;
int st[N];
int num[N];
int main()
{
    int n,m;
    cin>>n>>m;
    memset(st,0x3f,sizeof st);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        //cout<<a<<" "<<b<<endl;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    queue<int>q;
    q.push(1);
    st[1]=0;
    num[1]=1;
    while(q.size())
    {
        int T=q.front();
        q.pop();
       //cout<<T<<endl;
        for(auto t:mp[T])
        {
           if(st[t]==st[T]+1){
            num[t]+=num[T];
           }
           if(st[t]!=0x3f3f3f3f)continue;
           st[t]=st[T]+1;
           num[t]=num[T];
           q.push(t);
        }
    }
   // cout<<endl;

    //for(int i=1;i<=n;i++)cout<<num[i]<<endl;

    cout<<num[n]<<endl;



}