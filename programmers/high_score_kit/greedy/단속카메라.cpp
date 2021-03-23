#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cmp(vector<int> a,vector<int> b){
    return a[1] < b[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    //��ӵ��� ������ �ð��� ������������ �����ؼ�
    //���� ������ �ð� 
    sort(routes.begin(),routes.end(),cmp);
    int end = -30001;
    
    for(int i = 0; i < routes.size(); i++){
        int start = routes[i][0];
        if(end < start) {
            answer++;
            end = routes[i][1];
        }
        
    }
    
    return answer;
}