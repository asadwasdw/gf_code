#include<iostream>
#include<algorithm>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
using namespace std;
const int N=1e5+10;
typedef long long ll;
ll a[N],b[N],c[N];



int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)cin>>c[i];

    if(m==2)
    {

        for(int i=1;i<=n/2;i++){
            int j=n-i+1;
            bool ky=false;
            for(int x=0;x<=1;x++){
                for(int y=0;y<=1;y++)
                {
                    if(c[i]==(x+y)%2&&c[j]==(x-y+2)%2){
                        a[i]=a[j]=x;
                        b[i]=y;
                        b[j]=(-y+2)%2;
                        ky=true;
                    }
                }
                
            }
             

             if(!ky){
                cout<<"No"<<endl;
                return 0;
             }
        }
    

    }
    else {
        ll iv2=(m+1)/2ll;
        
        for(int i=1;i<=n/2;i++){
            int j=n-i+1;
            a[i]=a[j]=(c[i]+c[j])*iv2%m;
            b[i]=((c[i]-c[j])%m+m)*iv2%m;
            b[j]=(-b[i]+m)%m;
        }
    }

    if(n%2){
        int i=n/2+1;
        a[i]=c[i];
        b[i]=0;
    }

    cout<<"Yes"<<endl;
for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
for(int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;

    
}