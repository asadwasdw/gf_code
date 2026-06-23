#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int a[6];
    int ans=0;
    for(int i=1;i<=5;i++)
    {
        cin>>a[i];
        if(!a[i])ans=i;
    }

    cout<<ans<<endl;
}