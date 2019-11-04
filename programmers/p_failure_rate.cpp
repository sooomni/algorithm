#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(pair<double,int> a ,pair <double,int> b){
    if(a.first == b.first)
        return a.second<b.second;
    else
        return a.first>b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair <double, int> >p;

    int * try_ = new int[N+1]();
    int * check = new int[N+1]();
         
    for(int i =1;i<=N;i++){
        for(int j =0;j<stages.size();j++){   
            if(stages[j] == i){
               check[i]+=1;
               try_[i]+=1;
            }
            else if(stages[j]>i)
              try_[i]+=1;
            else
                continue;
        }
    }
   
    for(int i =0;i<N;i++){
        if(try_[i+1] == 0)
            p.push_back(pair <float, int>(0,i+1));
        else
            p.push_back(pair <float, int>((double)check[i+1]/(double)try_[i+1],i+1));
    }
    
    sort(p.begin(),p.end(),compare);
   
    for(int i =0;i<N;i++){       
       answer.push_back(p[i].second);
    }
    
    return answer;
}