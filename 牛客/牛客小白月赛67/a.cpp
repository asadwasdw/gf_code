#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;cin>>n;

    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=6;j++)
        {
            if(n>=1)cout<<"1";
            else cout<<"0";
            n--;
            
        }
        cout<<endl;

    }
    

}