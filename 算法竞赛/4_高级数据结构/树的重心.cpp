#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

const int N =1e5+10;

int h[N],e[N],ne[N],idx;

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

int ans=0x3f3f3f3f;
vector<int>jf;
  int n;

int dfs(int u,int f)
{
   // cout<<u<<" "<<f<<endl;
    int sum=0;
    int res=0;
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
       
        if(j==f)continue;
        int t=dfs(j,u);
        

        res=max(t,res);
     //   cout<<res<<endl;
        sum+=t;

    }

    sum++;

    res=max(n-sum,res);
    if(res<ans)
    {
        jf.clear();
        jf.push_back(u);
        ans=res;
    }
    else if(res==ans)jf.push_back(u);
    // cout<<"---------------"<<endl;
    // cout<<u<<endl;
    // // for(auto t:jf)cout<<t<<" ";cout<<endl;
    //  cout<<res<<" "<<sum<<endl;

    return sum;

}


int main()
{
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<n;i++)
    {
     //   cout<<i<<endl;
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }

    dfs(1,-1);
    sort(jf.begin(),jf.end());
    
    for(int i=0;i<jf.size();i++)cout<<jf[i]<<" ";

}