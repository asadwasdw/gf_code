#include <bits/stdc++.h>
using namespace std;
struct p{
  long long  a = 0,id = 0;
};
bool cmp(p a,p b){
  return a.a < b.a;
  
}


p a[1100];

int main() {
    
    int len;
    string s,b;
    cin >> b;
    
    len = b.size();
    for (int i = 0;i < len;i ++){
      a[i].id = i;
      for (int j = 0;j < len;j ++){
        if (b[j] == b[i])a[i].a++;
      }
    }
    sort(a,a + len,cmp);
    for (int i = 0;i < len;i ++){
      //不是最大的
      if(a[i].a == a[len - 1].a && a[i].a != 0)break;
      cout << b[a[i].id];
    }
    
}