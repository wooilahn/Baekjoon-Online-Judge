#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(){
  int T, num;
  scanf("%d", &T);

  while(T--){
    v.clear();
	
	for(int i=0; i<10; i++){
	  scanf("%d", &num);
	  v.push_back(num);
	}

	sort(v.begin(), v.end());
	printf("%d\n", v.at(v.size()-3));
  }

  return 0;
}
