#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<int> completed;
    queue <int> in_the_bridge;
    
    int sum = 0;
    int i = 0;
    while(completed.size() < truck_weights.size()){
        answer++;
        
        if(answer%bridge_length == 0){
            sum-= in_the_bridge.front();
            completed.push_back(in_the_bridge.front());
            in_the_bridge.pop();
        } 
        
        if(in_the_bridge.empty()){
            in_the_bridge.push(truck_weights[i]);
            sum += truck_weights[i];
            i++;
        }
            while(sum+truck_weights[i]<=weight){
                in_the_bridge.push(truck_weights[i]);
                sum += truck_weights[i];
                i++;
            }                
    }
    return answer;
}