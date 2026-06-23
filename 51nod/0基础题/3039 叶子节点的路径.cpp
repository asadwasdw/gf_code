#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;


const int N=2e3+10;

int edge[N][N];
int n;

vector<int>ans;
void dfs(int u,int father)
{
    bool gjd=true;

    for(int i=1;i<=n;i++)
    {
        if(i==father)continue;
        if(!edge[u][i])continue;

        ans.push_back(i);

        dfs(i,u);

        gjd=false;
        ans.pop_back();

    }

    if(gjd){
        for(auto t:ans)cout<<t<<" ";
        cout<<endl;
    }

}


int main()
{
    //memset(h,-1,sizeof h);

    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        edge[a][b]=edge[b][a]=1;
    }
    ans.push_back(1);
    dfs(1,-1);
}