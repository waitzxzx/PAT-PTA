#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main(void){
	int nc,np;
	cin>>nc;ll *c = new ll[nc];
	for(int i=0;i<nc;i++) cin>>c[i];
	cin>>np;ll *p = new ll[np];
	for(int i=0;i<np;i++) cin>>p[i];
	sort(c,c+nc);
	sort(p,p+np);
	ll ans = 0;
	for(int i=nc-1,j=np-1;i>=0&&j>=0;i--,j--){
		if(c[i]>0&&p[j]>0) ans+=c[i]*p[j];
		else break;
	} 
	for(int i=0,j=0;i<nc&&j<np;i++,j++){
		if(c[i]<0&&p[j]<0) ans+=c[i]*p[j];
	}
	cout<<ans<<endl;
	return 0;
}
