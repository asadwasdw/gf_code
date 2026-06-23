#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int vis[maxn],Fa[maxn];
ll sum[maxn],w[maxn],a[maxn],color[maxn],fac[maxn];
vector<int>g[maxn];
void dfs(int u,int fa){
  sum[u]=0;
  Fa[u]=fa;
  w[u]=0;
  for(int i=0;i<g[u].size();i++){
      int v=g[u][i];
      if(v==fa) continue;
      dfs(v,u);
      sum[u]+=sum[v];
  }
  for(int i=0;i<g[u].size();i++){//将 该节点的儿子节点颜色加入桶中 
      int v=g[u][i];
      if(v==fa) continue;
      color[a[v]]++;
  }
  w[u]=color[a[u]];//该点与下属的贡献即为桶中 该点颜色的数量 
  //统计儿子节点之间产生的贡献
  vector<int>q;//存用了哪几种颜色 
  for(int i=0;i<g[u].size();i++){
      int v=g[u][i];
      if(v==fa) continue;
    if(!vis[a[v]])//如果这个点颜色没用过
    {
      q.push_back(a[v]);//把颜色丢进去 
      sum[u]+=(color[a[v]]-1)*(color[a[v]])/2;
      vis[a[v]]=1;
    } 
  }
  // 
  for(int i=0;i<q.size();i++) vis[q[i]]=0;//清空vis数组 
  for(int i=0;i<g[u].size();i++){//将 该节点的儿子节点颜色删除  清空桶 
      int v=g[u][i];
      if(v==fa) continue;
      color[a[v]]--;
  }

  sum[u]+=w[u];
 // cout<<sum[u]<<" "<<w[u]<<endl;
} 
ll ans[maxn];
int main()
{
    ios::sync_with_stdio(false);
    int n,m,u,v;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];    
    for(int i=1;i<n;i++){
      cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    g[0].push_back(1);//最顶层1加一层0 
    dfs(1,0);
    //cout<<Fa[1]<<endl; 
    for(int u=1;u<=n;u++){//枚举删除那个点
      ans[u]=sum[1]-w[u];//贡献必然先减去离职点的贡献 
      if(a[u]==a[Fa[u]])ans[u]--;//如果离职点和leader颜色相同  贡献减一 
      //cout<<"U: "<<u<<". 1: "<<ans[u]<<endl;
      //  离职点同层点的情况 
      for(int i=0;i<g[Fa[u]].size();i++){
          int v=g[Fa[u]][i];
        if(v==Fa[v]) continue; 
        fac[a[v]]++;//该层点颜色放入桶中 
      }
      ans[u]-=fac[a[u]]-1;//减去与同事的贡献
      fac[a[u]]--;//离职点颜色删除 
      //离职点的儿子节点颜色插入桶中 
      for(int i=0;i<g[u].size();i++){
          int v=g[u][i];
          if(v==Fa[u]) continue;
          color[a[v]]++;
      }
      //cout<<"U: "<<u<<". 2: "<<ans[u]<<endl;
      ll temp=-1e18;//记录改变值最小 
      for(int i=0;i<g[u].size();i++){//枚举离职点哪位儿子继位 
        ll res=0;//记录以该点时的贡献 
          int v=g[u][i];
          if(v==Fa[u]) continue;
          if(a[v]==a[Fa[u]]) res++;// 升职后和新的leader颜色相同 贡献加1 
          //
          
          res-=color[a[v]]-1;//  该点升职原本为兄弟时的贡献删去 
          res+=color[a[v]]-1;// 该点升职变为原来兄弟的leader  贡献加上 
          //这部分可以抵消 
          //
        //计算儿子变兄弟  产生的额外贡献 
          for(int j=0;j<g[v].size();j++){
            int vv=g[v][j];
          if(vv==Fa[v]) continue;
          res+=fac[a[vv]]; 
        }
        temp=max(temp,res); 
        //该儿子贡献计算完
      }
      //离职点的儿子节点颜色删除 
      for(int i=0;i<g[u].size();i++){
          int v=g[u][i];
          if(v==Fa[u]) continue;
          color[a[v]]--;
      }
      //删离职同层的颜色 
      for(int i=0;i<g[Fa[u]].size();i++){//删边 
          int v=g[Fa[u]][i];
        if(v==Fa[v]) continue; 
        fac[a[v]]--;//删去 
      } 
      fac[a[u]]++;//离职点删除多于一次补回nu<<". 3: "<<ans[u]<<' '<<temp<<endl;
      if(temp==-1e18) continue;
      ans[u]+=temp; 
      //cout<<"U: "<<u<<".final ans: "<<ans[u]<<endl; 
    }
//    for(int i=1;i<=n;i++) cout<<w[i]<<' ';cout<<endl;
//    for(int i=1;i<=n;i++) cout<<sum[i]<<' ';cout<<endl; 
//    for(int i=1;i<=n;i++) cout<<color[i]<<' '<<fac[i]<<' ';cout<<endl;
    for(int i=1;i<=n-1;i++){
      cout<<ans[i]<<' ';
    }
    cout<<ans[n]<<endl;
    return 0;
}

