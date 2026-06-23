#include<iostream>
#include<algorithm>

using namespace std;

int mob(int n)
{
    int ans=1;
    
    for(int i=2;i<=n/i;i++)
    {
        if(n%i==0){
            ans*=(-1);
            int cnt=0;
            while(n%i==0)
            {
                cnt++;
                n/=i;
            }
            if(cnt>=2)
            {
                return 0;
            }
        }
    }

    if(n>1)
    {
        ans*=(-1);
    }

    return ans;

}


int main()
{
    int n;cin>>n;

    cout<<mob(n);
}