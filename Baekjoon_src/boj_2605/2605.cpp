#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <deque>
#include <vector>

using namespace std;

deque<int> d;

int main(){
  int N;
  scanf("%d", &N);

  int num;
  for(int i=1; i<=N; i++){
    scanf("%d", &num);

	if(d.empty()){
		d.push_back(i);
		continue;
	}

	vector<int> v;
	for(int k=0; k<num; k++){
	  v.push_back(d.back());
	  d.pop_back();
	}
	d.push_back(i);

	for(int k=v.size()-1; k>= 0; k--){
	  d.push_back(v[k]);
	}
  }

  for(int k=0; k<d.size(); k++){
    printf("%d ", d[k]);
  }
  printf("\n");

  return 0;
}
