#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int * arr = new int[n+1]();
    
    for(int i = 0;i<lost.size();i++){
        arr[lost[i]]--;
    }
    for(int i = 0;i<reserve.size();i++){
        arr[reserve[i]]++;
     }
     
    for(int i=0;i<=n;i++){
        if(i != 0 && arr[i-1] <0){
            if(arr[i]>0){
                arr[i]--;
                arr[i-1]++;
            }
        }
        else if(i != n && arr[i+1] <0){
            if(arr[i]>0){
                arr[i]--;
                arr[i+1]++; 
            }  
        }
    }  
    
    for(int i = 1;i<n+1;i++){
        if(arr[i]>=0)
            answer+=1;
    }
    return answer;
}