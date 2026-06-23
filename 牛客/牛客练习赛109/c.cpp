#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;
const int N=1e6+10;

unordered_map<int,vector<int>>m;
int sx[N];
int sum[N];
int wz=1;
int n;

int dfs(int t)
{
   // cout<<t<<endl;
    int ans=1;
    while(sum[t]>1&&wz<=n)
    {
        int T=sx[wz++];
        if(T<t)
        {
             m[T].push_back(t);
        }
        else m[t].push_back(T);
       int z=dfs(T);
       ans+=z;
       sum[t]-=z;
    }
    return ans;
}


int main()
{

    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&sx[i]);
    for(int i=1;i<=n;i++)scanf("%d",&sum[i]);
    wz++;
    dfs(sx[1]);    

    for(int i=1;i<=n;i++)
    {
        if(!m[i].size())continue;

        sort(m[i].begin(),m[i].end());

        for(auto t:m[i]){
            printf("%d %d\n",i,t);
        }
    }



}