#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;
int arr[7] = {0};

int max(int n1, int n2){
  return n1 > n2 ? n1 : n2;
}

int main(){
  int n1,n2,n3;
  scanf("%d %d %d", &n1, &n2, &n3);

  arr[n1]++;
  arr[n2]++;
  arr[n3]++;

  bool d_flag = false;
  bool t_flag = false;
  int d_val, t_val;

  for(int i=1;i<=6;i++){
    if(arr[i] == 2){
	  d_flag = true;
	  d_val = i;
  }
	if(arr[i] == 3){
	  t_flag = true;
	  t_val = i;
	}
  }

  if(d_flag == false && t_flag == false){
    int max_v = max(n1, max(n2, n3));
	printf("%d\n", max_v*100);
  }
  else if(d_flag == true){
    printf("%d\n", 1000 + d_val*100);
  }
  else if(t_flag == true){
    printf("%d\n", 10000 + t_val*1000);
  }

  return 0;
}
