#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;
const int N=810;
int n,m;
int sx,sy,q;
int a[N][N];
int st[N][N];
int ST[N][N];
typedef pair <int,int> PII;


void bfs1(){
    sx++;
    sy++;
//cout<<sx<<" "<<sy<<endl;
    queue<PII>q;
    memset(ST,-1,sizeof ST);
    q.push({sx,sy});
    int dx[]={0,0,-1,1};
    int dy[]={1,-1,0,0};
    ST[sx][sy]=0;
    while(q.size()){
        PII t=q.front();
        q.pop();

        for(int k=0;k<4;k++){
            int x=t.first+dx[k];
            int y=t.second+dy[k];
          
            if(x<1||x>n||y<1||y>m)continue;
            //if(x==3&&y==7)cout<<"ssss   "<<ST[x][y]<<endl;
            if(ST[x][y]!=-1)continue;
            if(a[x][y]=='#')continue;
            ST[x][y]=ST[t.first][t.second]+1;
            q.push({x,y});
        }
    }

    // for(int i=1;i<=n;i++){
    // for(int j=1;j<=m;j++){
    //     cout<<ST[i][j]<<" ";
    // }
    // cout<<endl;
    // }
}

int main()
{
    cin>>n>>m>>sx>>sy>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            char t;cin>>t;
            a[i][j]=t;
        }
    }
    bfs1();
   
    int qid=0;

    while(q--){
         int ans=99999999;
        int x,y;
        cin>>x>>y;
        x++,y++;
       
        int d=0;
        qid++;
        while(st[x][y]!=qid){
            //cout<<x<<" "<<y<<endl;
            if(d>=ST[x][y]&&ST[x][y]!=-1){
                ans=min(ans,d);
                //cout<<x<<"     "<<y<<" "<<ans<<endl;
                st[x][y]=qid;
            }
            if(ST[x][y]==-1)st[x][y]=qid;
            int dx=x,dy=y;
            if(a[x][y]=='L')dy--;
            if(a[x][y]=='R')dy++;
            if(a[x][y]=='U')dx--;
            if(a[x][y]=='D')dx++;
            if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&a[dx][dy]!='#'){
                x=dx;
                y=dy;
            }
           
            d++;
        }

        if(ans==99999999)ans=-1;
        cout<<ans<<endl;
       // cout<<bfs(x,y)<<endl;
    }

    

    
}