#include<iostream>
#include<algorithm>

using namespace std;


string s;
int pd(int l,int r)
{

    for(int i=l,j=r;i<= (l+r>>1) ;i++,j--)
    {
        if(s[i]!=s[j])return false;
    }

    return true;

}



int main()
{
   
    cin>>s;
    int n=s.size();
    s=" "+s;
    int res=1;
    for(int l=1;l<n;l++){
        for(int r=l+1;r<=n;r++)
        {
            if(pd(l,r)){
                res=max(r-l+1,res);
            }
    
        }
    }

    cout<<res<<endl;






}