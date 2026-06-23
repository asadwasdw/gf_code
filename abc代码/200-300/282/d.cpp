#include<bits/stdc++.h>
using namespace  std;


const int N =2e5+10;
int n,m;
typedef long long ll;
int st[N];

vector<vector<int>>edg(N);

ll cnt1=0;
ll cnt2=0;
ll cntm=0;
bool dfs(int u,int fa,int color)
{
    st[u]=color;
    if(color==1)cnt1++;
    else cnt2++;

    for(auto t : edg[u]){
        cntm++;
        if(t==fa)continue;
        if(st[t]==st[u])return false;
        if(st[t])continue;
        if(!dfs(t,u,3-color)){
            return false;
        }
    }
    return true;


}




int main()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    ll ans1=0;
    ll ans2=0;

    for(int i=1;i<=n;i++)
    {
        if(st[i])continue;
        cnt1=cnt2=0;
        cntm=0;
        if(!dfs(i,-1,1)){
            cout<<"0\n";
            return 0;
        }
        cntm/=2;

        ans1+=cnt1*cnt2-cntm;

        ans2+=(n-cnt1-cnt2)*(cnt1+cnt2);

    }

    cout<<ans1+ans2/2<<endl;
    


}