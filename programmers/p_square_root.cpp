#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long check = sqrt(n);
    
    if(check * check == n)
        answer = (check+1)*(check+1);
    else
        answer = -1;
        
    return answer;
}