#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
       int x;
       cin>>x;

       bool ky=false;
       for(int i=0;i<11;i++)
       {
        if(x>=(111*i)&&(x-111*i)%11==0)
        {
            ky=true;
            //cout<<i<<" ";
        }
       }
       if(ky)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }



}