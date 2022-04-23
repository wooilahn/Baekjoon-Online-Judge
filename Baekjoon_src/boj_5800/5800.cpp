#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;

int main(){
  int K, N;
  scanf("%d", &K);

  for(int i=1; i<=K; i++){
    int num;
    scanf("%d", &N);
	v.clear();

	for(int i=0; i<N; i++){
	  scanf("%d", &num);
	  v.push_back(num);
	}

	sort(v.begin(), v.end());
	int l_gap = 0;
	for(int i=1; i<N; i++)
	  l_gap = max(l_gap, abs(v[i]-v[i-1]));
	printf("Class %d\n", i);
	printf("Max %d, Min %d, Largest gap %d\n", v[N-1], v[0], l_gap);
  }

  return 0;
}
