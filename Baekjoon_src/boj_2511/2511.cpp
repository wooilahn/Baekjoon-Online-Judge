#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v1;
vector<int> v2;

int main(){
  int num;
  for(int k=0; k<2; k++){
    for(int i=0; i<10; i++){
	  scanf("%d",&num);

	  if(k == 0)
	    v1.push_back(num);
	  else if(k == 1)
	    v2.push_back(num);
	}
  }

  int score_A=0, score_B=0;

  for(int i=0; i<10; i++){
    if(v1[i] > v2[i])
	  score_A += 3;
	else if(v1[i] < v2[i])
	  score_B += 3;
	else if(v1[i] == v2[i]){
	  score_A++;
	  score_B++;
	}
  }

  printf("%d %d\n", score_A, score_B);

  if(score_A > score_B)
    printf("A\n");
  else if(score_A < score_B)
    printf("B\n");
  else if(score_A == score_B){
    bool flag = false;

	for(int k=9; k>=0; k--){
	  if(v1[k] == v2[k])
	    continue;
	  
	  if(v1[k] > v2[k])
	    printf("A\n");
	  else if(v1[k] < v2[k])
	    printf("B\n");

	  flag = true;
	  break;
	}

	if(!flag)
	  printf("D\n");
  }

  return 0;
}
