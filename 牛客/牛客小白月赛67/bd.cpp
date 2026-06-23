#include<iostream>
#include<algorithm>

using namespace std;
const int N=2e5+10;
int a[N];

int main()
{
    int m,q;cin>>m>>q;
    int ans=0;
    while(q--)
    {
        int t,x;
        cin>>t>>x;
        if(t==1)
        {
            if(x+3<=m){
                if(a[x+3]==0)ans++;
                a[x+3]++;
            }

            if(x-3>=1)
            {
                if(a[x-3]==0)ans++;
                a[x-3]++;
            }
        }

        else{

            if(x+3<=m){
                a[x+3]--;
                if(a[x+3]==0)ans--;    
            }

            if(x-3>=1)
            {
                a[x-3]--;
                if(a[x-3]==0)ans--;
            }
            
        }

        cout<<ans<<endl;

    }
}