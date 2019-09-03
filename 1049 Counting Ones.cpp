#include<iostream>
using namespace std;
int CountOnes(int n)
{
    int factor = 1,lownum = 0,highnum = 0,cur = 0,countones = 0;
    while(n/factor){
        highnum = n/(factor*10);
        lownum = n - (n/factor)*factor;
        int cur = (n/factor) % 10;
        if(cur == 0) countones += highnum * factor;
        else if (cur == 1) countones += highnum * factor + lownum + 1;
        else countones += ( highnum + 1) * factor;
        factor *= 10;
    }
    return countones;
}
int main(){
    int n; cin >> n;
    cout << CountOnes(n);
    return 0;
}
