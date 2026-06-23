#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<map>
#include<cstring>

using namespace std;
#define int long long
const int N=1010;
const int mod=998244353;

int n,m,k;
int a[N*100];
unordered_map<int,vector<int>>edgs;
typedef pair<int,int>PII;


map<PII,int>num;
int f[N*1000];
int v[N*100];
int cnt;



bool dfs(int u,int f,int d){
    //cout<<u<<endl;
    if(u==d){
        return true;
    }


    for(auto t:edgs[u]){
        if(t==f)continue;
        if(dfs(t,u,d)){
            num[{min(t,u),max(t,u)}]++;
            return true;
        }
    }

    return false;
}

signed main()
{
    cin>>n>>m>>k;
    
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
       // cout<<a<<" "<<b<<endl;
        edgs[a].push_back(b);
        edgs[b].push_back(a);
    }

    // for(int i=1;i<=n;i++)
    // {
    //     for(auto t:edgs[i]){
    //         cout<<t<<" ";
    //     }
    //     cout<<endl;
    // }

    //dfs(2,-1,3);

   for(int i=1;i<m;i++) dfs(a[i],-1,a[i+1]);


  //  memset(f,0x3f,sizeof f);
    int sum=0;
    for(auto t:num)
    {
        v[++cnt]=t.second;
        sum+=t.second;
       // cout<<t.first.first<<" "<<t.first.second<<" "<<t.second<<endl;
    }
    //cout<<sum<<endl;


    if((sum + k)% 2 || sum + k < 0 ){
    cout << 0 << '\n';
    return 0;
    }
    
    sum=(sum+k)/2;

    f[0]=1;

    for(int i=1;i<n;i++)
    {
        for(int j=sum;j>=v[i];j--)
        {
            f[j]+=f[j-v[i]];
            f[j]%=mod;
        }
    }
   cout<<f[sum]%mod<<endl;

}