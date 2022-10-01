#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int woolim[10] = {0};
int startlink[10] = {0};

int main(){

  for(int i=0; i<9; i++)
    scanf("%d", &woolim[i]);
  for(int i=0; i<9; i++)
    scanf("%d", &startlink[i]);

  int cur_wl = 0;
  int cur_sl = 0;
  bool win_flag = false;
  bool ans_flag = false;

  for(int i=0; i<9; i++){
    cur_wl += woolim[i];

    if(cur_wl > cur_sl)
      win_flag = true;
    if(win_flag && cur_wl < cur_sl)
      ans_flag = true;

    cur_sl += startlink[i];

    if(cur_wl > cur_sl)
      win_flag = true;
    if(win_flag && cur_wl < cur_sl)
      ans_flag = true;
  }

  if(ans_flag)
    printf("Yes\n");
  else
    printf("No\n");

  return 0;
}
