#include <string>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

void card_rule(queue <int> *q)
{
	while (!q.empty) {
		q->pop();
		if (q->size() == 1){
			cout<<q.front();
			return;
		}
		q->push(p.front())
			q->pop();
	}
}

int solution(int n) {
	int answer = 0;
	queue <int> q;

	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	//answer = card_rule(q);

	return answer;
}

int main(void) {
	cout<<solution(6);
	return 0;
}