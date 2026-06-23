#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#define int long long

using namespace std;

const int N = 4e5+10;

unordered_map<int,int>x;
unordered_map<int,int>y;

typedef pair<int,int>PII;

map<PII,int>D;

PII dg[N];
int lshx[N];
int lshy[N];
int fgx[N];
int fgy[N];


signed main()
{
    int n,m;
    cin>>n>>m;

    int g;cin>>g;
    
    for(int i=1;i<=g;i++)
    {
        int a,b;cin>>a>>b;
        dg[i]={a,b};
        lshx[i]=a;
        lshy[i]=b;
    }

    int qx;
    cin>>qx;

    for(int i=1;i<=qx;i++)
    {
        int t;cin>>t;
        fgx[i]=t;
        lshx[i+g]=t;
    }

    int qy;
    cin>>qy;

    for(int i=1;i<=qy;i++)
    {
        int t;cin>>t;
        fgy[i]=t;
        lshy[i+g]=t;
    }



    sort(lshx+1,lshx+g+qx+1);
    sort(lshy+1,lshy+1+g+qy);
 //for(int i=1;i<=g+qx;i++)cout<<lshy[i]<<" ";cout<<endl;
   
   
    int cntx=1;
    int cnty=1;

    for(int i=1;i <= g+qx;i++)
    {
        if(fgx[cntx]==lshx[i])
        {
            cntx++;
        }

        if(lshx[i]!=lshx[i-1])
        {
            x[lshx[i]]=cntx;
        }
    }

    


    for(int i=1;i <= g+qy;i++)
    {
        if(fgy[cnty]==lshy[i])
        {
            cnty++;
        }

        if(lshy[i]!=lshy[i-1])
        {
            y[lshy[i]]=cnty;
        }
    }

    ///cout<<cntx<<" "<<cnty<<endl;

    int ansmin=0x3f3f3f3f;
    int ansmax=0;
    for(int i=1;i<=g;i++)
    {
        //cout<<i<<endl;
       // cout<<x[dg[i].first]<<y[dg[i].second]<<endl;
        D[{x[dg[i].first],y[dg[i].second]}]++;
        ansmax=max(ansmax,D[{x[dg[i].first],y[dg[i].second]}]);
    }

    // for(int i=1;i<=cntx;i++)
    // {
    //     for(int j=1;j<=cnty;j++)cout<<D[{i,j}]<<" ";cout<<endl;
    //     //cout<<i<<" "<<j<<" "<<D[{i,j}]<<endl;
    // }

    int I =4e5+10;

    for(int i=1;i<=cntx&&I;i++)
    {
        for(int j=1;j<=cnty&&I;j++)
        {
            I--;
            ansmin=min(D[{i,j}],ansmin);
            if(!ansmin)
            {
                //cout<<i<<j<<endl;
                I=0;
            }
        }
    }

    cout<<ansmin<<" "<<ansmax<<endl;






}



