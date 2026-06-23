//https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P5960

#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>

using namespace std;
const int N=1e5+10,M=2*N;

int dist[N],cnt[N];
bool st[N];
int n,m;
typedef pair<int,int> PII;
map<int,vector<PII>>edgs;

bool spfa(int s)
{
    queue<int>q;
    q.push(s);
    st[s]=true;
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;

   while(!q.empty())
    {
        int t=q.front();
        q.pop();
        //cnt[0]++;
        st[t]=false;

       for(auto T:edgs[t])
        {
          
            int j=T.first;
            int w=T.second;
            //cout<<j<<endl;

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



int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        edgs[0].push_back({i,0});
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>b>>a>>c;
         edgs[a].push_back({b,c});
    }

    if(spfa(0)){
        cout<<"NO"<<endl;
    }
    else {
        for(int i=1;i<=n;i++)
        {
            cout<<dist[i]<<" ";
        }
    }



}