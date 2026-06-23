#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
typedef pair<int,int>PII;
const int N=16;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

char a[N][N];
char b[N][N];
char c[N][N];

char A[N][N];
char C[N][N];
char B[N][N];
int HA,WA,HC,HB,WB,WC;

int num=0;

void CIN()
{
    int l,r,x,s;
    l=10,r=0,s=10,x=0;
    int ha,wa;
    cin>>ha>>wa;
    for(int i=1;i<=ha;i++)
        for(int j=1;j<=wa;j++)
        {
            cin>>a[i][j];

            if(a[i][j]=='#'){
            l=min(j,l);
            s=min(i,s);
            r=max(j,r);
            x=max(x,i);
            }
        }

    for(int i=s;i<=x;i++)
        for(int j=l;j<=r;j++)
        A[i-s+1][j-l+1]=a[i][j];

    
    HA=x-s+1;
    WA=r-l+1;
    l=10,r=0,s=10,x=0;
    int hb,wb;
    cin>>hb>>wb;
    for(int i=1;i<=hb;i++)
        for(int j=1;j<=wb;j++)
        {
            cin>>b[i][j];

            if(b[i][j]=='#'){
            l=min(j,l);
            s=min(i,s);
            r=max(j,r);
            x=max(x,i);
            }
            
        }

    for(int i=s;i<=x;i++)
        for(int j=l;j<=r;j++)
        B[i-s+1][j-l+1]=b[i][j];
    HB=x-s+1;
    WB=r-l+1;
    l=10,r=0,s=10,x=0;

    int hc,wc;
    cin>>hc>>wc;
    for(int i=1;i<=hc;i++)
        for(int j=1;j<=wc;j++)
        {
            cin>>c[i][j];
            if(c[i][j]=='#'){
            l=min(j,l);
            s=min(i,s);
            r=max(j,r);
            x=max(x,i);
            num++;
            }
        }

    
    for(int i=s;i<=x;i++)
        for(int j=l;j<=r;j++)
        C[i-s+1][j-l+1]=c[i][j];
  //  cout<<c[2][1]<<endl;
    HC=x-s+1;
    WC=r-l+1;
}


void print()
{
    for(int i=1;i<=HA;i++){

        for(int j=1;j<=WA;j++)cout<<A[i][j]<<" ";cout<<endl;
    }
cout<<endl;
    for(int i=1;i<=HB;i++){

        for(int j=1;j<=WB;j++)cout<<B[i][j]<<" ";cout<<endl;
    }
cout<<endl;
    for(int i=1;i<=HC;i++){

        for(int j=1;j<=WC;j++)cout<<C[i][j]<<" ";cout<<endl;
    }
}
typedef pair<int,int>PII;



void solve()
{

    CIN();

 //  print();

   vector<PII>ansa,ansb;
 
    for(int i=1;i<=HC-HA+1;i++)
        for(int j=1;j<=WC-WA+1;j++){
            bool ky=true;
            for(int I=1;I<=HA;I++)
            {
                for(int J =1;J<=WA;J++){
                    if(A[I][J]=='#'&&C[I+i-1][J+j-1]=='.'){
                        ky=false;
                    }
                }
            }
            if(ky==false)continue;
            ansa.push_back({i,j});
        }
    
    for(int i=1;i<=HC-HB+1;i++)
        for(int j=1;j<=WC-WB+1;j++){
            bool ky=true;
            for(int I=1;I<=HB;I++)
            {
                for(int J =1;J<=WB;J++){
                    if(B[I][J]=='#'&&C[I+i-1][J+j-1]=='.'){
                        ky=false;
                    }
                }
            }
            if(ky==false)continue;
            ansb.push_back({i,j});
        }
    
    //cout<<ansa.size()<<" "<<ansb.size()<<endl;
    //cout<<A[1][3]<<endl;
    for(auto t1:ansa)
        for(auto t2:ansb)
        {
           set<PII>ans;

           for(int i=1;i<=HA;i++)
                for(int j=1;j<=WA;j++)
                    if(A[i][j]=='#')
                    {
                        
                        ans.insert({i+t1.first-1,j+t1.second-1});
                    //  cout<<i+t1.first-1<<" "<<j+t2.first-1<<endl;
                    } 

           for(int i=1;i<=HB;i++)
                for(int j=1;j<=WB;j++)
                    if(B[i][j]=='#')
                    {
                        ans.insert({i+t2.first-1,j+t2.second-1});
                     // cout<<i+t1.first-1<<" "<<j+t2.first-1<<endl;
                    } 

            // cout<<ans.size()<<" "<<num<<endl;
            if(ans.size()==num){
                cout<<"Yes";
                return;
            }
          //  cout<<endl;
        }

        cout<<"No";

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}