//https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1462

#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

const int N = 4e6+10;

typedef long long  ll;
#define int long long

ll dis[N];
ll rmb[N];
bool st[N];
int n,m,b;

int h[N],idx,e[N],ne[N],w[N];

void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

typedef pair<ll,ll>PII;

bool dj(int x)
{
    if(rmb[1]>x)return false;

	for(int i = 1; i <= n; ++ i){
		dis[i] = 1e18;//必备的初始化,没有会致错 
		st[i] = false;
	}
    
    dis[1]=0;
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,1});
    while(q.size())
    {
        PII t=q.top();q.pop();
        if(st[t.second])continue;
        st[t.second]=true;
        //cout<<t.second<<endl;

        for(int i=h[t.second];i!=-1;i=ne[i])
        {
            ll j=e[i];
            ll z=w[i];
            if(rmb[j]>x)continue;
           // cout<<j<<endl;
            if(dis[j]>dis[t.second]+z)
            {
                dis[j]=dis[t.second]+z;
                q.push({dis[j],j});
            }
        }
    }

    if(dis[n]<=b)return true;
    return false;
}





signed main()
{

    cin>>n>>m>>b;

    memset(h,-1,sizeof h);
   

    for(int i=1;i<=n;i++)
    {
        cin>>rmb[i];
    }
  //  cout<<r<<endl;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
        //r=max(c,r);
    }

   

   ll l=0,r=100000000000;
 //  if(dj(9))cout<<"Yes"<<endl;

   //for(int i=1;i<=n;i++)cout<<dis[i]<<" ";


    while(l<r)
    {
        int mid=l+r>>1;
      // cout<<mid<<endl;
        if(dj(mid))r=mid;
        else l=mid+1;
    }
    dj(l);

   if(dis[n]<=b)cout<<l<<endl;
   else cout<<"AFK"<<endl;

}