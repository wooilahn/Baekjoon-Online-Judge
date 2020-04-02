#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

char str[105] = { 0 };

int main() {

	int ans = 0;
	scanf("%s", str);

	for (int i = 0;i < strlen(str);i++) {
		if (str[i] == 'c' && (str[i+1]=='=' || str[i+1] == '-')) // c=, c-
			i++;
		else if (str[i] == 'd' && (str[i + 1] == 'z' && str[i + 2] == '='))  // dz=
			i += 2;
		else if (str[i] == 'd' && (str[i + 1] == '-')) // d-
			i++;
		else if ((str[i] == 'l' || str[i] == 'n') && str[i + 1] == 'j') // lj, nj
			i++;
		else if ((str[i] == 's' || str[i] == 'z') && str[i + 1] == '=') // s=, z= 
			i++;
		
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}
