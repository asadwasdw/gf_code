#include <iostream>
#include <algorithm>

using namespace std;



int main()
{
    unsigned long long a,b;
    cin>>a>>b;
    unsigned long long ans=0x3f3f3f3f3f3f3f3f;

    if(a>=b)ans=b;

    if(a*a<b)
    {
        cout<<"-1"<<endl;return 0;
    }

   
    for(int i=2;i<=min(a,(unsigned long long)1e8+9);i++)
    {
        unsigned long long t=b/i;
        if(b%i!=0)t++;
        if(t<=a&&i<=a)
        {
            ans=min(ans,t*i);
        }
    }

    cout<<ans<<endl;

    return 0;
}