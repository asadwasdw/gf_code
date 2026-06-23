#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector<int> add(vector<int>a,vector<int>b)
{

    vector<int>res;
    int t=0;
    for(int i=0;i<a.size()||i<b.size();i++)
    {
        int ta=0;
        int tb=0;
        if(i<a.size())ta=a[i];
        if(i<b.size())tb=b[i];
        t+=ta+tb;

        res.push_back(t%10);
        t/=10;
    }

    while(t){
      res.push_back(t%10);
      t/=10;
    }
   while(res.size()>1&&res[res.size()-1]==0)res.pop_back();
    return res;
}

vector<int> j(vector<int>a,vector<int>b)
{
    vector<int>res;
    int t=0;
    for(int i=0;i<a.size()||i<=b.size();i++)
    {
       int ta=0;
        int tb=0;
        if(i<a.size())ta=a[i];
        if(i<b.size())tb=b[i];
        t+=ta-tb;
        if(t<0){
            t+=10;
            a[i+1]--;
        }
        res.push_back(t%10);
        t/=10;
    }
    while(t){
      res.push_back(t%10);
      t/=10;
    }
     while(res.size()>1&&res[res.size()-1]==0)res.pop_back();
    return res;
}


void print(vector<int>a){
    for(int i=a.size()-1;i>=0;i--)cout<<a[i];
    cout<<endl;
}

bool pd(vector<int>a,vector<int>b)
{
    if(a.size()!=b.size())return a.size()>b.size();

    for(int i=a.size()-1;i>=0;i--){
        if(a[i]!=b[i])return a[i]>b[i];
    }

    return false;
}



int main()
{
    vector<int>a,b;

    string A,B;
    cin>>A>>B;
    bool sta=true,stb=true;

    for(int i=A.size()-1;i>=0;i--)
    {
        if(i==0&&A[i]=='-'){
            sta=false;
           break;
        }
        a.push_back(A[i]-'0');
    }

    for(int i=B.size()-1;i>=0;i--)
    {
         
         if(i==0&&B[i]=='-'){
            stb=false;
           break;
        }
        b.push_back(B[i]-'0');
    }

  //  print(a);
 //   print(b);
   


   if(sta&&stb){

       auto c=add(a,b);
       print(c);
   }
   else if((!sta)&&(!stb)){
      cout<<"-";
       auto c=add(a,b);
       print(c);
   }
   else{
    //cout<<"3"<<endl;
    vector<int>c;

    if(pd(a,b))c=j(a,b);
    else c=j(b,a);

    if(pd(a,b)&&!sta){
        cout<<"-";
    }
    else if(pd(b,a)&&!stb) {
        cout<<"-";
    }
    print(c);
   }


}

