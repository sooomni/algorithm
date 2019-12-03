//k번째 수
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    vector <int> t;
    for(int i = 0; i<commands.size();i++){
        for(int j = commands[i][0]-1;j <commands[i][1];j++){
            t.push_back(array[j]);            
        }
        sort(t.begin(),t.end());        
        answer.push_back(t[commands[i][2]-1]);
        t.clear();
    }    
    return answer;
}