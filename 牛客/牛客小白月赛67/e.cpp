#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1e5+10;

double a[N],b[N];

void solve()
{
        int n;cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }

        for(int i=1;i<=n;i++)cin>>b[i];

        double qw=1e6+10;

        for(int i=n;i;i--)
        {
            
            qw=(min(a[i],qw)+min(b[i],qw))/2;
         //   cout<<i<<" "<<qw<<endl;
        }

        cout<<qw<<endl;
}


int main()
{
    int n;cin>>n;
    while(n--)solve();

}