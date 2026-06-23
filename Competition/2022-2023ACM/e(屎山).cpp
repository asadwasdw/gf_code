#include<iostream>
#include<algorithm>

using namespace std;



int solve(int n,int k,int e)
{
    
    int a=e,b=k,c=n-e-k;
   // cout<<a<<" "<<b<<" "<<c<<" ";
    if(b==n)
    {
        cout<<"0"<<endl;
        return 0 ;
    }

    if(a==0||c==0)
    {
        int t=max(a,c);

        if(b!=t){
             cout<<"0"<<endl;
           return 0;
        }

        if(t>=3){
            cout<<"0"<<endl;
        }
        else cout<<"1"<<endl;
        return 0;

    }

    if(a!=b&&a!=c&&b!=c){
        cout<<"0"<<endl;
        return 0;

    }


  int ans=n;
    if(a==b&&b==c)
    {
      
        if(b>=5)ans=0;
        if(b==4)ans=2;
        if(b==3)ans=3;
        if(b==2)ans=3;
        if(b==1)ans=2;
    }
    else if(a==c){

        if(b>a)
        {
            if(a>=3)ans=0;
            if(a==2)ans=1;
            if(a==1)ans=1;
        }
        else 
        {
            if(a > 4)ans = 0;
            if(a == 4){
                if(b == 3)ans = 1;
                if(b == 2)ans = 0;
                if(b == 1)ans = 1;
            }
            if(a == 3){
                if(b == 2)ans = 2;
                if(b == 1)ans = 1;
            }
            if(a == 2){
                ans = 2;
            }
        }

    }
    else{
        if(a!=b)swap(a,c);

        if(c>a){
            if(a>2)ans=0;
            else ans=1;
        }
        else{
            if(a > 4)ans = 0;
            if(a == 4){
                if(c == 3)ans = 1;
                if(c == 2)ans = 0;
                if(c == 1)ans = 1;
            }
            if(a == 3){
                if(c == 2)ans = 2;
                if(c == 1)ans = 1;
            }
            if(a == 2){
                ans = 2;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}

int main()
{
    int n,k,e;
    cin>>n>>k>>e;
    solve(n,k,e);
//   for(int n=1;n<=5;n++)
//   {
//     for(int k=1;k<=n;k++)
//     {
//         for(int e=0;e<=n-k;e++)
//         {
//             solve(n,k,e);
//         }
//     }
//   }

}