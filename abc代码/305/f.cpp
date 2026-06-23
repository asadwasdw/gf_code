#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int  N = 110;
bool f[N];
int last[N];
int n,m;
int cnt=0;
void dfs(int u,int fa)
{


    if(u==n)
    {
        string s;
        cin>>s;
        exit(0);
    }
    int num;
    cin>>num;
    if(num==-1)
    {
        exit(0);
    }
    vector<int>v;
    for(int i=1;i<=num;i++){
        int x;cin>>x;
        v.push_back(x);
    }
    int cg=0;
    for(auto t:v)if(!f[t])
    {
        f[t]=true;
        cg=1;
        cout<<t<<endl;
        last[t]=u;
        dfs(t,u);
        break;
    }
    if(u==1&&fa==1)return;
    if(!cg)cout<<fa<<endl,dfs(fa,last[fa]);

    return;
}

int main()
{
    cin>>n>>m;
    f[1]=true;
    last[1]=1;
    dfs(1,1);
}