#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue <pair<int, int>> q;
    priority_queue <int> pq;
    
    for(int i = 0;i<priorities.size();i++){
        q.push(pair<int, int>(i,priorities[i]));
        pq.push(priorities[i]);       
    }
    
    while(!q.empty()){
        if(pq.top() == q.front().second){
            if(location == q.front().first){
                return ++answer;
            }
            else{
                answer++;
                pq.pop(); q.pop();
            }
        }
        else{
            q.push(q.front());
            q.pop();
        }     
    }
    return answer;
}