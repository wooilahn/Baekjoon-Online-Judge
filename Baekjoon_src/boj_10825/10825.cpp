#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

typedef struct _student {
	int kor_s;
	int eng_s;
	int mat_s;
	char name[15];
}student;

bool cmp(const student& s1, const student& s2) {
	if (s1.kor_s < s2.kor_s)
		return true;
	else if (s1.kor_s == s2.kor_s) {
		if (s1.eng_s < s2.eng_s)
			return true;
		else if (s1.eng_s == s2.eng_s) {
			if (s1.mat_s < s2.mat_s)
				return true;
			else if (s1.mat_s == s2.mat_s) {
				if (strcmp(s1.name, s2.name) <= 0)
					return true;
			}
		}
	}

	return false;
}

vector<student> v;

int main() {
	int N;
	student stu;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s %d %d %d", stu.name, &stu.kor_s, &stu.eng_s, &stu.mat_s);
		stu.kor_s = -stu.kor_s;
		stu.mat_s = -stu.mat_s;
		v.push_back(stu);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) 
		printf("%s\n", v.at(i).name);
	
	return 0;
	
}
