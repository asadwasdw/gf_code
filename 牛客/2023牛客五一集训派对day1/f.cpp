#include<bits/stdc++.h>
using namespace std;



void solve(string a,string b )
{
    
        a=a+a;
        b=b+b;
        bool jhl=false;
        if(a.size()>b.size())
        {
            jhl=true;
            swap(a,b);
        }

        while (a.size()<=b.size())a+=a;

        for(int i=0;i<a.size()&&i<b.size();i++)
        {
            if(a[i]!=b[i]){
                if(a[i]<b[i])
                {
                    if(jhl)cout<<">"<<endl;
                    else cout<<"<"<<endl;
                }
                else 
                {
                    if(jhl)cout<<"<"<<endl;
                    else cout<<">"<<endl;
                }
                return;
            }
        } 

        cout<<"="<<endl;
        return;
}


int main(){
    string a,b;
    while(cin>>a>>b){
        solve(a,b);
    }
}