#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;
const int N=1e6+10;

int sonsize[N];
int sonmin[N];
int w[N];

vector<int>b[N];

typedef pair <int,int> PII;

PII dfs(int t,int f)
{
    int g=1;
    int minson=t;
    int g0=0;

    for(auto a:b[t])
    {
        
        if(a==f)continue;
        PII T = dfs(a,t);
        
        minson=min(T.second,minson);
        g+=T.first;
        if(t==0)g0=max(g0,T.first);
    }
    //cout<<t<<" "<<minson<<endl;
    sonsize[t]=g;
    sonmin[t]=minson;
    if(t==0)sonsize[t]=g0;
    return {g,minson};

} 

int main()
{
    int n;cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }

    for(int i=2;i<=n;i++)
    {
        int x;scanf("%d",&x);
        b[w[i]].push_back(w[x]);
        b[w[x]].push_back(w[i]);
    }

    // for(int i=0;i<n;i++)
    // {
    //     cout<<i<<endl;
    //     for(auto t:b[i])cout<<t<<" ";
    //     cout<<endl;
    // }
  
    dfs(0,-1);

   cout<<sonsize[0]<<" ";

    // for(int i=1;i<n;i++)
    // {
    //     cout<<i<<" "<<sonmin[i]<<endl;
    // }

    for(int i=1;i<n;i++)
    {
        if(sonmin[i]<i)cout<<"0 ";
        else cout<<n-sonsize[i]<<" ";
    }
    cout<<n<<endl;


}