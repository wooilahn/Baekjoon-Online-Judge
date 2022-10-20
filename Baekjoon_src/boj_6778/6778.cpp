#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int antenna;
  int eyes;

  scanf("%d %d", &antenna, &eyes);

  if(antenna >= 3 && eyes <= 4)
    printf("TroyMartian\n");
  if(antenna <= 6 && eyes >= 2)
    printf("VladSaturnian\n");
  if(antenna <= 2 && eyes <= 3)
    printf("GraemeMercurian\n");

  return 0;
}
