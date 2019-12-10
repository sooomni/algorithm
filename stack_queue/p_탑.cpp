#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> heights) {
 	vector<int> answer;
	queue <int> q;

	int end = heights.size() - 1;
	q.push(heights[end]);

	for (int i = end-1; i >= 0; i--) {
		if (heights[i] > q.back()) {
			while (!q.empty()) {
                if(heights[i] >q.front())
                    answer.push_back(i + 1);
                else
                    answer.push_back(0);
                q.pop();
            }
			q.push(heights[i]);
		}
		else
			q.push(heights[i]);
	}

	if (!q.empty()) {
		while (!q.empty()) {
			answer.push_back(0);
            q.pop();
		}
	}
    
    reverse(answer.begin(),answer.end());
    return answer;
}