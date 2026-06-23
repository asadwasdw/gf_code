#include<iostream>
#include<algorithm>

using namespace std;
   int a[50];
   int c[50];
    
int main()
{
 
    int cnt=0;

    for(int i=1;i<=3;i++)
    {
        char t;cin>>t;
        a[t-'a']++;
    }

    sort(a,a+30);
  // cout<<a[29]<<endl;
    if(a[29]==1){
        cout<<"6";
    }
    if(a[29]==2){
        cout<<"3";
    }
    if(a[29]==3)cout<<"1";
    return 0;
    


}