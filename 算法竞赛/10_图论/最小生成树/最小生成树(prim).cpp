//https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P3366

#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

typedef pair<int,int>PII;


const int N=5010,M=4e5+10;

int n,m;

int h[M],e[M],ne[M],idx,w[M];

bool st[N];

void add(int a,int b,int c)
{
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);

    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }

    priority_queue<PII,vector<PII>,greater<PII>>q;

    q.push({0,1});

    int ans=0;
    int cnt=0;

    while(q.size())
    {
        auto t=q.top();q.pop();

        if(st[t.second])continue;
        st[t.second]=true;

        ans+=t.first;
        cnt++;

        for(int i=h[t.second];~i;i=ne[i])
        {
            int j=e[i];

            if(st[j])continue;

            q.push({w[i],j});
        }

    }

    if(cnt==n)cout<<ans;
    else cout<<"orz";


}
