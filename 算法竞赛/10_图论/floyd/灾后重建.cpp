//https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1119

#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;

const int N=210;

int st[N][N];
int cj[N];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>cj[i];
    }

    memset(st,0x3f,sizeof st);
    for(int i=0;i<n;i++)st[i][i]=0;


    for(int i=1;i<=m;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        st[a][b]=c;
        st[b][a]=c;
    }

    int q;cin>>q;
    int cnt=0;
    while(q--)
    {
        int a,b,t;
        cin>>a>>b>>t;

        while(cnt<n&&cj[cnt]<=t){
           //cout<<cnt<<endl;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++){
                    st[i][j]=min(st[i][j],st[i][cnt]+st[cnt][j]);
                }
            }

            cnt++;
        }


        if(cj[a]>t||cj[b]>t){
          //  cout<<a<<" "<<cj[a]<<" "<<b<<" "<<cj[b]<<" "<<t<<endl;
            cout<<"-1"<<endl;
        }
        else {
            if(st[a][b]==0x3f3f3f3f)cout<<"-1"<<endl;
            else cout<<st[a][b]<<endl;
        }
    }

}