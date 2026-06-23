//https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1993


#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<queue>
#include<cstring>


using namespace std;
typedef pair<int,int>PII;

unordered_map<int,vector<PII>>edge;
const int N=1e5+10,M=2*N;

int dist[N],cnt[N];
int st[N];
int n,m;

int mm[M][5];



bool spfa(int s)
{
    queue<int>q;
    q.push(s);
    st[s]=true;
    memset(dist,0x3f,sizeof dist);
    
    dist[s]=0;
    while(q.size())
    {
        int t=q.front();q.pop();
        st[t]=false;

        for(auto T:edge[t]){

            int x=T.first;
            int y=T.second;

            if(dist[x]>dist[t]+y){
                dist[x]=dist[t]+y;
                
                if(!st[x]){
                    st[x]=true;
                    cnt[x]++;
                    if(cnt[x]>n)return true;
                    q.push(x);
                }
            }
            
        }

    }
    return false;
}



int main()
{

   
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        edge[0].push_back({i,0});
    }


    for(int i=1;i<=m;i++)
    {
        cin>>mm[i][0]>>mm[i][1]>>mm[i][2];
        if(mm[i][0]!=3)cin>>mm[i][3];
    }

    for(int i=1;i<=m;i++)
    {
        int op,a,b,c;
        op=mm[i][0];
        a=mm[i][1];
        b=mm[i][2];
        c=mm[i][3];
        if(op==3)
        {
            edge[a].push_back({b,0});//a<=b+w
            edge[b].push_back({a,0});//b<=a+w
        }
        else if(op==1)
        {

            edge[b].push_back({a,-c});
        }
        else{
            edge[a].push_back({b,c});
        }
    }

    bool ky=true;

    if(spfa(0)) ky=false;

    if(ky)cout<<"Yes";
    else cout<<"No";

    
   



}