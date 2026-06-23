#include<bits/stdc++.h>
using namespace std;

int n,m;

const int N=1010;
typedef pair<int,int>PII;
int dt[N][N];

 int a[111];
bool st[N][N];

bool pd(int x,int y)
{
    for(int i=1;i<=m;i++)
    {
        if(a[i]&&dt[x][y+i-1])return false;
    }

    return true;

}

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};


int main()
{
    
   
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
       
        int t;
        scanf("%1d",&t);
        a[i]=t;

    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
                  
            int t;
           scanf("%1d",&t);
              dt[i][j]=dt[i][j+m]=t;
        }
    }

    queue<PII>q;

    q.push({0,1});

    st[0][1]=true;

    while(q.size())
    {
        auto t = q.front();q.pop();

        int x=t.first;
        int y=t.second;

        for(int i=0;i<4;i++)
        {

            int X=x+dx[i];
            int Y=y+dy[i];
            if(Y==m+1)Y-=m;
            if(Y==0)Y+=m;
    
            if(X<0||X>n||Y<1||Y>m)continue;

            if(!pd(X,Y))continue;
            if(st[X][Y])continue;

       //     cout<<X<<" "<<Y<<endl;
    
            st[X][Y]=true;

            q.push({X,Y});

        }
    }



    bool ky=false;

    for(int i=1;i<=m;i++)
    {
        if(st[n][i])
        {
           // cout<<n<<" "<<i<<endl;
            ky=true;
        }
    }

    if(!ky)
    {
        reverse(a+ 1, a + 1 + m);
          queue<PII>q;
          memset(st,0,sizeof st);

    q.push({0,1});

    st[0][1]=true;

    while(q.size())
    {
        auto t = q.front();q.pop();

        int x=t.first;
        int y=t.second;


        for(int i=0;i<4;i++)
        {

            int X=x+dx[i];
            int Y=y+dy[i];
            if(Y==m+1)Y-=m;
            if(Y==0)Y+=m;
            if(X<0||X>n||Y<1||Y>m)continue;

            if(!pd(X,Y))continue;
            if(st[X][Y])continue;

            //cout<<X<<" "<<Y<<endl;
    
            st[X][Y]=true;

            q.push({X,Y});

        }
    }



    for(int i=1;i<=m;i++)
    {
        if(st[n][i])
        {
            ky=true;
        }
    }
    }

    if(ky)cout<<"Y";
    else cout<<"N";












}