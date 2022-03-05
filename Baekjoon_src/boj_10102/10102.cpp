#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
  int V;
  scanf("%d", &V);

  char str[20] = {0};
  scanf("%s", str);

  int n_A = 0;
  int n_B = 0;

  for(int i=0; i<V; i++){
    if(str[i] == 'A')
	  n_A++;
	else if(str[i] == 'B')
	  n_B++;
  }

  if(n_A > n_B)
    printf("A\n");
  else if(n_A < n_B)
    printf("B\n");
  else if(n_A == n_B)
    printf("Tie\n");

  return 0;
}
