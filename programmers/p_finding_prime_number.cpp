#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    int * arr = new int[n+1]();

    for(int i = 2;i<=sqrt(n);i++){
        if(arr[i] == 0){
            for(int j = i*i ;j <= n;j+=i){
                arr[j] = 1;
            }
        }
    }
        
    for(int i = 2;i<=n;i++){
        if(arr[i] == 0)
            answer+= 1;
    }
    
    return answer;
}