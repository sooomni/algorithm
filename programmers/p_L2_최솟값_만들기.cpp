#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<int>());
    
    int i = 0;
    int j = B.size();
    
    while(i<A.size()){
        answer += (A[i]*B[i]);        
        i++;
        j--;        
    }
    return answer;
}