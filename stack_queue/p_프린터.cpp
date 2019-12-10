#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
bool compare(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int solution(vector<int> priorities, int location) {
    int answer = 1;
    vector <pair<int, int>> v;
    vector <pair<int, int>> v2;
    int max = *max_element(priorities.begin(),priorities.end());
    
    for(int i = 0; i<priorities.size();i++){
        if(priorities[i] == max){
            while(i<priorities.size()){
                v.push_back(pair<int,int>(i,priorities[i]));
                i++;
            }
        }
        else{  
            v2.push_back(pair<int,int>(i,priorities[i]));
        }            
    }
    
    sort(v.begin(),v.end(),compare);
    sort(v2.begin(),v2.end(),compare);
  
    v.insert( v.end(), v2.begin(), v2.end() );   

    for(int i = 0; i<v.size();i++){
        if(v[i].first == location) break;
        else answer++;
    }
    
    return answer;
}