#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int p = arr1.size();
    int q = arr2[0].size();
    int r = arr2.size();
    
    for(int i = 0;i<p;i++){
        vector<int> col; 
        for(int j = 0;j<q;j++){
            int result = 0;
            for(int k = 0;k<r;k++){                
              result += (arr1[i][k]*arr2[k][j]);
            }
            col.push_back(result);
            cout<<endl;
        }
         answer.push_back(col);        
     }    
              
    return answer;
}