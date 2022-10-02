#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> v1[52];
vector<char> v2[104];

int main(){
  int R, C, ZR, ZC;
  cin >> R >> C >> ZR >> ZC;

  for(int i=0; i<R; i++){
    string s;
    cin >> s;
    
    for(int k=0; k<s.size(); k++)
     v1[i].push_back(s[k]);
  }

  for(int i=0; i<R; i++){
    for(int zr=0; zr<ZR; zr++){
        for(int c=0; c<v1[i].size(); c++){
          for(int zc=0; zc<ZC; zc++)
            cout << v1[i][c];
        }
        cout << '\n';
    }
  }

  return 0;
}
