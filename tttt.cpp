#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;
 
struct window
{
   int mm;
   int hh;
   int ss;
   bool operator<(const window& a)const
   {
       if(hh>a.hh)
           return true;
      else if(hh==a.hh&&mm>a.mm)
          return true;
     else if(hh==a.hh&&mm==a.mm&&ss>a.ss)
         return true;
     else
         return false;
    }
};
 
struct customer
{
    int h;
    int m;
    int s;
    int last;
 bool operator<(const customer& a)const
 {
     if(h>a.h)
       return true;
     else if(h==a.h&&m>a.m)
       return true;
     else if(h==a.h&&m==a.m&&s>a.s)
       return true;
     else
       return false;
  }
};
 
priority_queue<window> bank;
priority_queue<customer> cu;
 
int main()
{ 
    int n,k,i;
    cin>>n>>k;
    window w;
    for(i=0;i<k;i++)
    {
        w.ss=0;
        w.mm=0;
        w.hh=8;
        bank.push(w);
     }
    customer cust;
    for(i=0;i<n;i++)
    {
        cin>>cust.h;
        getchar();
        cin>>cust.m;
        getchar();
        cin>>cust.s>>cust.last;
       cu.push(cust);
    }
    int c=0;
    double total=0;
    while(!cu.empty())
    {
         cust=cu.top();
         cu.pop();
         if(cust.h>17||(cust.h==17&&cust.m)||(cust.h==17&&!cust.m&&cust.s))
             break;
         c++;
        w=bank.top();
        bank.pop();
       if(cust.h<w.hh||(cust.h==w.hh&&cust.m<w.mm)||(cust.h==w.hh&&cust.m==w.mm&&cust.s<w.ss))
       {
            total+=(w.hh-cust.h)*60.0+(w.mm-cust.m)+(w.ss-cust.s)/60.0;
            w.mm+=cust.last;
            w.hh+=w.mm/60;
            w.mm%=60;
      }
      else  //have window but the customer not come yet  so no need to wait
      {
            w.ss=cust.s;
            w.mm=cust.m+cust.last;
			w.hh=cust.h+w.mm/60;
            w.mm%=60;
       }
      bank.push(w);
   }
   cout<<total<<" "<<c<<endl;
 cout<<fixed<<setprecision(1)<<total/c<<endl;
 return 0;
}
