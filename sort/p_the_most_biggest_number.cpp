#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}
string solution(vector<int> numbers) {
    string answer = "";
    int sum = 0;
    vector<pair<int,int>> v;
    
    for(int i = 0;i<numbers.size();i++){
        string original = to_string(numbers[i]);
        int index = 0;
        while(original.size() <4){
            original+=(original[index]);
            index = (index+1)%original.size();
        }
        v.push_back(pair<int,int>(atoi(original.c_str()),numbers[i]));
    }

    sort(v.begin(),v.end(),compare);
    
    for(int i = 0;i<v.size();i++){
        sum+= v[i].second;
        answer += to_string(v[i].second);
    }
    
    if(sum == 0)
        answer = "0";
    
    return answer;
}