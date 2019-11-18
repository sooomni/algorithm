#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string day[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int idx = 0;
    for(int i =0;i<a-1;i++){
        idx += month[i];    
    }
    idx = (idx+b-1)%7;
    string answer = day[idx];
    return answer;
}