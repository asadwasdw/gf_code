#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

unordered_map<int,vector<int>>edg;
unordered_map<int,vector<int>>fedg;
const int N = 1e6+10;

int dis[N];

vector<int> jh[N];
int n,m;

bool st[N];
bool jhst[N];

int main()
{
    cin>>n>>m;

    memset(dis,0x3f,sizeof dis);
    queue<int>q;

    int k;
    for(int i=1;i<=n;i++)
    {
        cin>>k;

        int t;
        for(int j=1;j<=k;j++)
        {
            cin>>t;
            jh[i].push_back(t);
            fedg[t].push_back(i);

            if(t==1)
            {
                dis[i]=0;
                q.push(i);
            }
        }
    }


    while(q.size())
    {
        auto T = q.front();q.pop();
        vector<int>gb;

        for(auto t : jh[T])
        {
            if(st[t])continue;
            st[t]=true;
            gb.push_back(t);
        }

        for(auto t:gb)
        {
            if(jhst[t])continue;
            jhst[t]=true;

            for(auto tt:fedg[t])
            {
                if(dis[tt]!=0x3f3f3f3f)continue;
                dis[tt]=dis[T]+1;
                q.push(tt);
            }
        }
    }
    int ans=0x3f3f3f3f;

    //for(int i=1;i<=n;i++)cout<<dis[i]<<" ";cout<<endl;

    for(auto t : fedg[m])
    {
       // cout<<t<<endl;
        ans=min(ans,dis[t]);
    }

    if(ans==0x3f3f3f3f)ans=-1;

    cout<<ans<<endl;


}