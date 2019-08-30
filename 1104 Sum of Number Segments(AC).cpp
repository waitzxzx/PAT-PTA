#include <stdio.h>
int n;
double x;
int main()
{
    double ans;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&x);
        ans+=x*i*(n-i+1);
    }
    printf("%.2f\n",ans);
    return 0;
}
