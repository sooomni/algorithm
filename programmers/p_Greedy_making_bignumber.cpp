#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector <int> v;
    
    string t = "";
    for(int i = 0;i<number.size();i++){
        t = number[i];
        v.push_back(atoi(t.c_str()));
    }
    
    int n = number.size()-k;

    vector <int> ::iterator iter = max_element(v.begin(),v.begin()+k);
    answer += *iter;
    
    vector <int> ::iterator iter_compare = min_element(iter+1,iter+n-1);
    
    vector <int> ::iterator iter2 =iter+n;
    while(iter2 < v.end()){
        if(*iter_compare <= *iter2){
            *iter_compare = 0;
            iter_compare = min_element(iter_compare+1,iter+n-1);
        }            
        iter2++;
    }
    
    int count = 1;
    iter += 1;
    while(count <n){
        if(*iter != 0){
            answer+= *iter;
            count++;
        }   
    }
    return answer;
}