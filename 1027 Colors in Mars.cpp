#include<iostream>
using namespace std;
void print(int x){
	if(x>=0&&x<=9) printf("%d",x);
	else printf("%c",x-10+'A');
}
void fun(int n){
	int d1 = n / 13;
	int d2 = n % 13;
	print(d1);
	print(d2);
}
int main(void){
	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
	printf("#");
	fun(r);fun(g);fun(b);
	printf("\n");
	return 0;
} 
