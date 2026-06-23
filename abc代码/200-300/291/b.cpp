#include<iostream>
#include<algorithm>

using namespace std;

const int N= 110;
int a[N]; 

void solve()
{
    int n;cin>>n;

    for(int i=1;i<=5*n;i++)cin>>a[i];

    sort(a+1,a+5*n+1);

    double sum=0;

    for(int i=n+1;i<=4*n;i++)sum+=a[i];
    printf("%.12llf",sum/(3*n));

   // cout<<sum/3/n<<endl;

}

int main()
{
   // int t;cin>>t;while(t--)
    solve();
}