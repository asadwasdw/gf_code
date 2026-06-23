#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


void solve()
{

    int n;cin>>n;

    bool ky=false;
    for(int i=0;i<=n&&!ky;i++)
    {
        if(i*4>n)break;

        for(int j=0;j<=n&&!ky;j++)
        {
            if(i*4+j*5>n)break;

            if((n-(i*4+5*j))%6==0){

            int k=(n-(i*4+5*j))/6;
            int t=0;

            for(int g=1;g<=i;g++)
            {
                t++;
                cout<<t+2<<" ";
                t++;
                cout<<t+2<<" ";
                t++;
                cout<<t-2<<" ";
                t++;
                cout<<t-2<<" ";
            }


            for(int g=1;g<=j;g++)
            {
                t++;
                cout<<t+3<<" ";
                t++;
                cout<<t+3<<" ";
                t++;
                cout<<t-2<<" ";
                t++;
                cout<<t-2<<" ";
                t++;
                cout<<t-2<<" ";
            }

            for(int g=1;g<=k;g++)
            {
                t++;
                cout<<t+3<<" ";
                t++;
                cout<<t+3<<" ";
                t++;
                cout<<t+3<<" ";
                t++;
                cout<<t-3<<" ";
                t++;
                cout<<t-3<<" ";
                t++;
                cout<<t-3<<" ";
            }




            ky=true;
            break;

            }
        }

    }

    if(!ky)cout<<-1<<endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}