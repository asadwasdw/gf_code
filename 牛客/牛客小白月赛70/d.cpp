#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e6+10;
int f[N];


typedef long long ll;

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>f[i];

    ll l=0,r=0;

    bool y1=false;
    ll ans=0;

    for(int i=1;i<=n;i++)
    {
        if(f[i]){

            if(y1)
            {
                ans+=(l+1)*(r+1);
                l=r;
                r=0;
            }
            else {
                y1=true;
            }
        }
        else {
            if(y1){
                r++;
            }
            else l++;
        }

      //  cout<<l<<" "<<r<<endl;
    }

    if(y1)ans+=(l+1)*(r+1);

    cout<<ans<<endl;


}
