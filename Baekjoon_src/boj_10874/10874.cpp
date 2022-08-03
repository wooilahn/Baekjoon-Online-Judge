#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;
int sheet[105][11] = {0};
int answer[11] = {0};
vector<int> v;

int main(){
  int N;
  scanf("%d", &N);

  for(int i=0; i<10; i++){
    answer[i] = (i%5)+1;
  }

  for(int i=0; i<N; i++){
    int ans = 0;

    for(int k=0; k<10; k++){
	  scanf("%d", &sheet[i][k]);

	  if(answer[k] == sheet[i][k])
	    ans++;
	}

	if(ans == 10)
	  v.push_back(i+1);
  }

  for(int i=0; i<v.size(); i++)
    printf("%d\n", v[i]);

  return 0;
}
