#include<iostream>
#include<algorithm>

using namespace std;

const int N=2e5+10;

int a[N],b[N];

void solve()
{
    int n,k;cin>>n>>k;
    int max1=-1,max2=-1;
    int ans1=-1,ans2=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }



    for(int i=1;i<=n;i++)
    {
        cin>>b[i];

        if(a[i]==k)
        {
            if(b[i]>max1)
            {
                max1=b[i];
                ans1=i;
            }
        }
        if(a[i]==a[1]){
            if(b[i]>max2)
            {
                max2=b[i];
                ans2=i;
            }
        }
    }

    if(ans1!=-1)cout<<ans1<<endl;
    else cout<<ans2<<endl;

    

}


int main()
{
 //   int t=1;cin>>t;while(t--)
    solve();
    return 0;
}