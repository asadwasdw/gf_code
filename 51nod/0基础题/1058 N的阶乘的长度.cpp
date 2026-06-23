#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
   double res=0;
   int n;cin>>n;

    for(int i=1;i<=n;i++)
    {
       // cout<<log10(i)<<endl;
        res+=log10(i*1.0);
    }

    cout<<(int)res+1<<endl;
}