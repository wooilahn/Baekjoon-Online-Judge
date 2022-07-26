#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int A_h1, A_m1, A_s1, A_h2, A_m2, A_s2;
  int B_h1, B_m1, B_s1, B_h2, B_m2, B_s2;
  int C_h1, C_m1, C_s1, C_h2, C_m2, C_s2;

  cin >> A_h1 >> A_m1 >> A_s1 >> A_h2 >> A_m2 >> A_s2;
  cin >> B_h1 >> B_m1 >> B_s1 >> B_h2 >> B_m2 >> B_s2;
  cin >> C_h1 >> C_m1 >> C_s1 >> C_h2 >> C_m2 >> C_s2;

  int total_A = (A_h2*3600 + A_m2*60 + A_s2) - (A_h1*3600 + A_m1*60 + A_s1);
  int total_B = (B_h2*3600 + B_m2*60 + B_s2) - (B_h1*3600 + B_m1*60 + B_s1);
  int total_C = (C_h2*3600 + C_m2*60 + C_s2) - (C_h1*3600 + C_m1*60 + C_s1);

  int total_Ah = total_A / 3600;
  int total_Am = (total_A - (total_Ah * 3600)) / 60;
  int total_As = (total_A - (total_Ah * 3600)) % 60;
  cout << total_Ah << " " << total_Am << " " << total_As << "\n";

  int total_Bh = total_B / 3600;
  int total_Bm = (total_B - (total_Bh * 3600)) / 60;
  int total_Bs = (total_B - (total_Bh * 3600)) % 60;
  cout << total_Bh << " " << total_Bm << " " << total_Bs << "\n";

  int total_Ch = total_C / 3600;
  int total_Cm = (total_C - (total_Ch * 3600)) / 60;
  int total_Cs = (total_C - (total_Ch * 3600)) % 60;
  cout << total_Ch << " " << total_Cm << " " << total_Cs << "\n";

  return 0;
}
