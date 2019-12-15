#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack <int> block;
    
    for(int i = 0;i<prices.size();i++){
        block.push(prices[i]);
    }
    
    int tmp = 10001;
    int i = prices.size();
    
    while(!block.empty()){
        if(tmp < block.top()){
            answer.push_back(1);
        }
        else{
            answer.push_back(prices.size()-i);    
        }
        
        tmp = block.top();
        block.pop();
        i--;
    }
    
    reverse(answer.begin(),answer.end());
    return answer;
}