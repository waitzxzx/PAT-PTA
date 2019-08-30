#include<iostream>
#include<algorithm>
#include<vector>
#define INF 0x3f3f3f3f
using namespace std;
struct station{
	double price,dis;//油价，离杭州距离，到下一个油站距离 
	bool operator < (const station &other) const{
		return dis<other.dis;
	}
};
vector<station> s;
int main(void){
	double c_max,D,d_avg;int N;//油箱容量，距离杭州的距离，公里/L，油站数量
	cin>>c_max>>D>>d_avg>>N;
	station sta;
	for(int i=0;i<N;i++){
		cin>>sta.price>>sta.dis;
		s.push_back(sta);
	}
	sort(s.begin(),s.end());
	/*到达加油站，在当前的最大可达范围内：
	A.有其它加油站
	1.如果有加油站比该站的价格低，那么加油使到达最近的站； 
	2.如果有加油站但是价格更贵
	a)不能到达终点，则加满（加满是因为，无论在范围之外有多小的油价，即使加满也无法到达，还需要中间一个加油站中转，但既然当前油价最低，能加满就加满，之后油钱高的就可以少加点）
	b)可以到达终点，加油使得刚好到达终点 
	B.没有其它的加油站
	1.可以到达终点，直接到达
	2.不能到达终点，加满油后能跑多远跑多远 
	*/
	if(s[0].dis>0){
		cout<<"The maximum travel distance = 0.00"<<endl;
		return 0; 
	} 
	double sumDis,sumPrice=0;//当前距离，总价格 
	double curCap=0;//当前油量
	int cur=0;//当前所在的油站 
	double maxToGo = c_max*d_avg;//最大可达范围 
	while(cur<s.size()){ 
		bool hasStation= false; 
		double stationPrice = s[cur].price;
		double stationDis = s[cur].dis;
		int dest=-1;
		
		for(int i=cur+1;i<s.size();i++){
			if(s[i].dis<=stationDis+maxToGo){
				hasStation = true;
				if(stationPrice>s[i].price){
					dest = i;break;//记录最近的低油价站 
				}
			}
			else break;
		}
		if(hasStation == false){//当前可达范围内没有油站了 
			if(stationDis+maxToGo>=D){//如果可以到达终点 
				double restDis = D-stationDis;//剩余的距离 
				if(curCap*d_avg>=restDis){//如果不再需要额外的油
					break;
				}else{
					double needDis = restDis - curCap * d_avg;//需要加油到达的路程 
					sumPrice+=(needDis / d_avg) *stationPrice; 
					break; 
				} 
			}else{//如果不能到达终点 
				sumDis = stationDis+maxToGo;
				sumPrice += (D-curCap)*stationPrice;
				printf("The maximum travel distance = %.2lf\n",sumDis);
                return 0;
			}
		}
		else{//当前可达范围内有油站
			if(dest!=-1){//在可达范围内有比当前油站更便宜的油站 
				double gapDis = s[dest].dis - stationDis;//到最近的油站的距离 
				if(curCap*d_avg >= gapDis) curCap-= gapDis/d_avg;//当前的油量足够
				else{//需要额外的加油，加油使得能够刚好到这个站 
					sumPrice +=(gapDis-curCap*d_avg)/ d_avg*stationPrice;
					curCap = 0;//因为是刚好的，跑过去就没有油了 
				} 
				cur=dest; 
			} 
			else{//在可达范围内没有更便宜的油
				if(stationDis+maxToGo>=D){//在可达范围内可以到达终点,直接到达 
				 	double restDis = D-stationDis;//如果可以通过加油直接到达 
				 	if(curCap*d_avg < restDis){//还需要额外的油 
				 		sumPrice+=(restDis-curCap*d_avg)/d_avg*stationPrice;
				 		break;
					} 
					else break;//不需要额外的油了，直接结束 
				} 
				//在可达范围内不可以到达终点，没有更便宜的油，加满，然后到达可达范围内最便宜的下一个油站 
				int minPrice = INF;
				int minCur = -1;
				for(int i=cur+1;i<s.size();i++){
					if(s[i].dis < stationDis + maxToGo){
						if(s[i].price < minPrice){
							minPrice = s[i].price;
							minCur = i;
						} 
					} 
					else break;
				} 
				cur = minCur;// 到达可达范围内最便宜的下一个油站  
				sumPrice +=(c_max-curCap)*stationPrice;//加上达到满油的价格 
				curCap = c_max-(s[minCur].dis-stationDis)/d_avg;	//调整达到下一个油站的油量 
			}
		} 
	}
	printf("%.2lf\n",sumPrice);
	return 0; 
}
