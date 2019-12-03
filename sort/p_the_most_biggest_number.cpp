//가장 큰 수 | permutation, 시간초과

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector <int> perm_vec; 

void swap(vector<int>*v, int a, int b){
    int t = (*v)[a];
    (*v)[a] =  (*v)[b];
    (*v)[b] = t;
}

void perm_func(vector<int>*v){
    string t = "";
    for(int i = 0;i<(*v).size();i++){
        t+= to_string((*v)[i]);
    }
    perm_vec.push_back(atoi(t.c_str()));
} 

void perm(vector<int>*v,int dept, int n, int k){
    if(dept == k){
        perm_func(v);
        return;
    }
    else{
        for(int i = dept;i<n;i++){
            swap(v,i,dept);
            perm(v,dept+1,n,k);
            swap(v,i,dept);
        }
    }
}    
string solution(vector<int> numbers) {
    string answer = "";
    
    perm(&numbers,0,numbers.size(),numbers.size());
    sort(perm_vec.begin(),perm_vec.end(),greater<int>());
    answer = to_string(perm_vec[0]); 
    
    return answer;
}