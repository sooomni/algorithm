#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(pair<char, string>a, pair<char, string>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}
vector<string> solution(vector<string> strings, int n) {
    vector <pair<char, string>> v;
    vector<string>answer;
    
    for(int i = 0;i<strings.size();i++){
        v.push_back(pair<char, string>(strings[i][n],strings[i]));
    }

    sort(v.begin(),v.end(),compare);    
    
    for(int i = 0;i<strings.size();i++){
        answer.push_back(v[i].second);
    }
    return answer;
}