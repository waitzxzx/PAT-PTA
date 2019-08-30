#include<stdio.h> 
#define ll long long
ll gcd(ll a,ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
} 
void output(ll a,ll b){//a ·Ö×Ó b·ÖÄ¸ 
	if(a==0){
		printf("0");return;
	} 
	bool isNeg = false;
	if(a>0&&b<0){
		isNeg = true; b = -b;
	}else if(a<0&&b>0){
		isNeg = true; a = -a;
	}else if(a<0&&b<0){
		a=-a;b=-b;
	}
	ll f = gcd(a,b);
	a = a/f; b = b/f;
	ll i = a / b;
	a = a - i * b;
	if(isNeg){
		printf("(-");
		if(i!=0){
			printf("%lld",i);
		}
		if(a!=0){
			if(i!=0) printf(" ");
			printf("%lld/%lld",a,b);
		}
		printf(")");
	}else{
		if(i!=0){
			printf("%lld",i);
		}
		if(a!=0){
			if(i!=0) printf(" ");
			printf("%lld/%lld",a,b);
		}		
	}
}
void sum(ll a1,ll b1,ll a2,ll b2){
	ll b = b1*b2;
	ll a = a1*b2+a2*b1;
	output(a1,b1);printf(" + ");
	output(a2,b2);printf(" = ");
	output(a,b);printf("\n");
}
void difference(ll a1,ll b1,ll a2,ll b2){
	ll b = b1*b2;
	ll a = a1*b2-a2*b1;
	output(a1,b1);printf(" - ");
	output(a2,b2);printf(" = ");
	output(a,b);printf("\n");
}
void product(ll a1,ll b1,ll a2,ll b2){
	ll b = b1*b2;
	ll a = a1*a2;
	output(a1,b1);printf(" * ");
	output(a2,b2);printf(" = ");
	output(a,b);printf("\n");
}
void quotient(ll a1,ll b1,ll a2,ll b2){
	output(a1,b1);printf(" / ");
	output(a2,b2);printf(" = ");
	if(a2==0){
		printf("Inf\n");
	}
	else{
		ll b = b1*a2;
		ll a = a1*b2;
		output(a,b);printf("\n");
	}
} 
int main(void){
	ll a1,a2,b1,b2;
	scanf("%lld/%lld",&a1,&b1);
	scanf("%lld/%lld",&a2,&b2);
	sum(a1,b1,a2,b2);
	difference(a1,b1,a2,b2);
	product(a1,b1,a2,b2);
	quotient(a1,b1,a2,b2);
	return 0;
}
