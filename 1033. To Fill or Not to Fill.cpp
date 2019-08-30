#include<iostream>
#include<algorithm>
#include<vector>
#define INF 0x3f3f3f3f
using namespace std;
struct station{
	double price,dis;//�ͼۣ��뺼�ݾ��룬����һ����վ���� 
	bool operator < (const station &other) const{
		return dis<other.dis;
	}
};
vector<station> s;
int main(void){
	double c_max,D,d_avg;int N;//�������������뺼�ݵľ��룬����/L����վ����
	cin>>c_max>>D>>d_avg>>N;
	station sta;
	for(int i=0;i<N;i++){
		cin>>sta.price>>sta.dis;
		s.push_back(sta);
	}
	sort(s.begin(),s.end());
	/*�������վ���ڵ�ǰ�����ɴﷶΧ�ڣ�
	A.����������վ
	1.����м���վ�ȸ�վ�ļ۸�ͣ���ô����ʹ���������վ�� 
	2.����м���վ���Ǽ۸����
	a)���ܵ����յ㣬���������������Ϊ�������ڷ�Χ֮���ж�С���ͼۣ���ʹ����Ҳ�޷��������Ҫ�м�һ������վ��ת������Ȼ��ǰ�ͼ���ͣ��ܼ����ͼ�����֮����Ǯ�ߵľͿ����ټӵ㣩
	b)���Ե����յ㣬����ʹ�øպõ����յ� 
	B.û�������ļ���վ
	1.���Ե����յ㣬ֱ�ӵ���
	2.���ܵ����յ㣬�����ͺ����ܶ�Զ�ܶ�Զ 
	*/
	if(s[0].dis>0){
		cout<<"The maximum travel distance = 0.00"<<endl;
		return 0; 
	} 
	double sumDis,sumPrice=0;//��ǰ���룬�ܼ۸� 
	double curCap=0;//��ǰ����
	int cur=0;//��ǰ���ڵ���վ 
	double maxToGo = c_max*d_avg;//���ɴﷶΧ 
	while(cur<s.size()){ 
		bool hasStation= false; 
		double stationPrice = s[cur].price;
		double stationDis = s[cur].dis;
		int dest=-1;
		
		for(int i=cur+1;i<s.size();i++){
			if(s[i].dis<=stationDis+maxToGo){
				hasStation = true;
				if(stationPrice>s[i].price){
					dest = i;break;//��¼����ĵ��ͼ�վ 
				}
			}
			else break;
		}
		if(hasStation == false){//��ǰ�ɴﷶΧ��û����վ�� 
			if(stationDis+maxToGo>=D){//������Ե����յ� 
				double restDis = D-stationDis;//ʣ��ľ��� 
				if(curCap*d_avg>=restDis){//���������Ҫ�������
					break;
				}else{
					double needDis = restDis - curCap * d_avg;//��Ҫ���͵����·�� 
					sumPrice+=(needDis / d_avg) *stationPrice; 
					break; 
				} 
			}else{//������ܵ����յ� 
				sumDis = stationDis+maxToGo;
				sumPrice += (D-curCap)*stationPrice;
				printf("The maximum travel distance = %.2lf\n",sumDis);
                return 0;
			}
		}
		else{//��ǰ�ɴﷶΧ������վ
			if(dest!=-1){//�ڿɴﷶΧ���бȵ�ǰ��վ�����˵���վ 
				double gapDis = s[dest].dis - stationDis;//���������վ�ľ��� 
				if(curCap*d_avg >= gapDis) curCap-= gapDis/d_avg;//��ǰ�������㹻
				else{//��Ҫ����ļ��ͣ�����ʹ���ܹ��պõ����վ 
					sumPrice +=(gapDis-curCap*d_avg)/ d_avg*stationPrice;
					curCap = 0;//��Ϊ�Ǹպõģ��ܹ�ȥ��û������ 
				} 
				cur=dest; 
			} 
			else{//�ڿɴﷶΧ��û�и����˵���
				if(stationDis+maxToGo>=D){//�ڿɴﷶΧ�ڿ��Ե����յ�,ֱ�ӵ��� 
				 	double restDis = D-stationDis;//�������ͨ������ֱ�ӵ��� 
				 	if(curCap*d_avg < restDis){//����Ҫ������� 
				 		sumPrice+=(restDis-curCap*d_avg)/d_avg*stationPrice;
				 		break;
					} 
					else break;//����Ҫ��������ˣ�ֱ�ӽ��� 
				} 
				//�ڿɴﷶΧ�ڲ����Ե����յ㣬û�и����˵��ͣ�������Ȼ�󵽴�ɴﷶΧ������˵���һ����վ 
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
				cur = minCur;// ����ɴﷶΧ������˵���һ����վ  
				sumPrice +=(c_max-curCap)*stationPrice;//���ϴﵽ���͵ļ۸� 
				curCap = c_max-(s[minCur].dis-stationDis)/d_avg;	//�����ﵽ��һ����վ������ 
			}
		} 
	}
	printf("%.2lf\n",sumPrice);
	return 0; 
}
