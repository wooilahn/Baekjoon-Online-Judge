#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int map[105][105] = {0};

int main(){ 
  int n;
  scanf("%d", &n);

  int x, y;

  for(int i=0; i<n; i++){
    scanf("%d %d", &x, &y);

	for(int r=x; r<x+10; r++){
	  for(int c=y; c<y+10; c++){
	    map[r][c]++;
	  }
	}
  }

  int ans = 0;

  for(int i=0; i<=100; i++){
    for(int j=0; j<=100; j++){
	  if(map[i][j])
	    ans++;
	}
  }

  printf("%d\n", ans);

  return 0;
}
