#include<iostream>
#include<algorithm>


using namespace std;

int a[200010];
void solve()
{
    int n;cin>>n;
        a[1]=0;
        a[n]=1;

    bool yj=false;
    int l=1,r=n;
    while(1)
    {

        if(r-l<=1)
        {
            cout<<"! "<<l<<endl;
            
           cout.flush();

            break;
        }
        int mid=l+r>>1;

        cout<<"? "<<mid<<endl;
        
       cout.flush();
        int x;cin>>x;

        if(x==1)
        {
            r=mid;
        }
        else l=mid;
    }

    cout.flush();
}

int main()
{
    //int t=1;cin>>t;while(t--)
    solve();
    return 0;
}