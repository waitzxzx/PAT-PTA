#include <iostream>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
 
using namespace std;
 
#define INF 99999999
 
struct GasStation{
 
    double price;
    double dis;
 
    GasStation(double _p, double _d) : price(_p), dis(_d) {}
 
};
 
int compare(GasStation a, GasStation b){
 
    return a.dis < b.dis;
 
}
 
int main()
{
    int cons,gasCnt;
    double cap;
    double dis;
    double price;
    double dist;
    vector<GasStation> stations;
    cin >> cap >> dis >> cons >> gasCnt;
    double maxToGo = cap * cons;
    for(int i = 0; i < gasCnt; i++){
        scanf("%lf %lf",&price,&dist);
        stations.push_back(GasStation(price,dist));
    }
    sort(stations.begin(),stations.end(),compare);
 
    if(stations[0].dis > 0){
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
 
    int cur = 0;
    double now_cap = 0;
    double sumPrice = 0;
    int curEnd = stations.size();
    double stationPrice = 0;
    double stationDis = 0;
    int hasStation = 0;
    int dest = 0;
 
    // ����ж��������վ��ѡ���Ǹ�����˵ļ��͡�
    // ��ʵ֤����Ŀ�в�û�д��಻����ʵ�ʵ����塣
    int minPrice = stations[0].price;
    for(int i = 0; i < stations.size(); i++){
        if(stations[i].dis == 0){
            if(minPrice > stations[i].price){
                cur = i;
            }
        }else break;
    }
 
    while(cur < curEnd){
        stationPrice = stations[cur].price;
        stationDis = stations[cur].dis;
        dest = -1;
        hasStation = 0;
 
        for(int i = cur + 1; i < stations.size(); i++){ // �����жϵ�ǰվ��֮����û�п��Ե����
            if((stations[i].dis - stationDis) <= maxToGo){ // �����пɵ����վ�㣬���ҳ����������˵ġ�
                hasStation = 1;
                // �ҳ�����˵��������������һ���бȵ�ǰվ����˵ģ��������������������������վ�㡣
                // ���߶��ȵ�ǰվ�������͵��ܵ�������˵��Ǹ���
                // �������ж��ǳ�ͻ�ģ���Ϊ�бȵ��ڱ��˵�ʱ��ѡ��Ĳ����Ǹ�����˵Ķ�������ģ������ʱ���ҵ�������˵�
                // ������ж���û�бȵ�ǰ���˵ģ�û���ٽ�һ�����Ǹ���������˵ġ�
                if(stationPrice > stations[i].price){ // �ҵ��˸����˵ģ��������жϲ��ң���֤�ҵ���������ġ�
                    dest = i;
                    break;
                }
            }else{ // ��û�пɵ����վ���ˡ�
                break;
            }
        }
        if(hasStation != 1){ // û�пɵ���վ��
            if((dis - stationDis) <= maxToGo){ // ���ܵ��յ㣬����͵������ܵ��յ�
                double need = dis - stationDis;
                if(now_cap * cons >= need){ // ���㹻����
                    break;
                }else{ // �Ͳ������ӵ����ܵ��յ�
                    double last = (need - now_cap * cons);
                    sumPrice += (last / cons) * stationPrice;
                    break;
                }
            }else{ // �ܲ����յ㣬���ܶ�Զ�ܶ�Զ
                double sumDis = stationDis + cap * cons;
                printf("The maximum travel distance = %.2lf\n",sumDis);
                return 0;
            }
        }else{ // �п��Ե����վ��
            if(dest != -1){ // �ҵ��˱ȵ�ǰ�����Ҿ��뵱ǰ����ļ���վ�����͵��ܵ����Ȼ��������Ǹ�վ�㿼��
                double need = stations[dest].dis - stationDis;
                if(need <= now_cap * cons){ // ���㹻����
                    now_cap -= need / cons;
                }else{ // �Ͳ���������
                    sumPrice += (need - now_cap * cons) / cons * stationPrice;
                    now_cap = 0; // �ܹ�ȥ��û������
                }
                cur = dest;
            }else{ // û�б��˵ģ�ѡ���Ǹ�����˵ļ����ܹ�ȥ��
 
                // �������ȿ��ܷ��յ㣬�ܵ���ֱ�ӵ��յ㣬һ��ע���������������
                if((dis - stationDis) <= maxToGo){
                    double need = dis - stationDis;
                    if(now_cap * cons < need){
                        sumPrice += (need - now_cap * cons) / cons * stationPrice;
                    }
                    break;
                }
 
 
                int minPrice = INF;
                int minCur = -1;
                for(int i = cur + 1; i < stations.size(); i++){
                    if((stations[i].dis - stationDis) < maxToGo){
                        if(stations[i].price < minPrice){
                            minPrice = stations[i].price;
                            minCur = i;
                        }
                    }else{
                        break;
                    }
                }
                cur = minCur;
                sumPrice += (cap - now_cap) * stationPrice;
                now_cap = cap - (stations[cur].dis - stationDis) / cons;
            }
        }
 
 
    }
    printf("%.2lf\n",sumPrice);
 
    return 0;
}
