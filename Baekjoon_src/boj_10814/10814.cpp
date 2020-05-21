#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct member{
	char name[202];
	int age;
	int order;
};

bool cmp(member m1, member m2){
	if (m1.age < m2.age)
		return true;
	else if (m1.age == m2.age) {
		return m1.order < m2.order;
	}
	else
		return false;
}

vector<member> v;

int main() {

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		member m;
		m.order = i;

		scanf("%d %s", &m.age, &m.name);
		v.push_back(m);
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		printf("%d %s\n", v.at(i).age, v.at(i).name);
	}

	return 0;
}
