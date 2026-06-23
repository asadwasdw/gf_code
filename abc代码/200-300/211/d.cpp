#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N=2e5+10;
const int MOD=1e9+7;
map<int,vector<int>>mp;
int st[N];
long long num[N];
int main()
{
    int n,m;
    cin>>n>>m;
    memset(st,0x3f,sizeof st);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
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
            num[t]%=MOD;
           }
           if(st[t]!=0x3f3f3f3f)continue;
           st[t]=st[T]+1;
           num[t]=num[T];
           q.push(t);
        }
    }
   
    cout<<num[n]%MOD<<endl;

}