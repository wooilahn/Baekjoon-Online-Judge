#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int S;
	cin >> S;

	int sy, ey;

	while (S--) {
		cin >> sy >> ey;
		vector<pair<int, string>> v;

		for (int i = sy; i <= ey; i++) {
			int yy = i;

			switch (yy) {
			case 1967:
				v.push_back(make_pair(1967, "DavidBowie"));
				break;
			case 1969:
				v.push_back(make_pair(1969, "SpaceOddity"));
				break;
			case 1970:
				v.push_back(make_pair(1970, "TheManWhoSoldTheWorld"));
				break;
			case 1971:
				v.push_back(make_pair(1971, "HunkyDory"));
				break;
			case 1972:
				v.push_back(make_pair(1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"));
				break;
			case 1973:
				v.push_back(make_pair(1973, "AladdinSane"));
				v.push_back(make_pair(1973, "PinUps"));
				break;
			case 1974:
				v.push_back(make_pair(1974, "DiamondDogs"));
				break;
			case 1975:
				v.push_back(make_pair(1975, "YoungAmericans"));
				break;
			case 1976:
				v.push_back(make_pair(1976, "StationToStation"));
				break;
			case 1977:
				v.push_back(make_pair(1977, "Low"));
				v.push_back(make_pair(1977, "Heroes"));
				break;
			case 1979:
				v.push_back(make_pair(1979, "Lodger"));
				break;
			case 1980:
				v.push_back(make_pair(1980, "ScaryMonstersAndSuperCreeps"));
				break;
			case 1983:
				v.push_back(make_pair(1983, "LetsDance"));
				break;
			case 1984:
				v.push_back(make_pair(1984, "Tonight"));
				break;
			case 1987:
				v.push_back(make_pair(1987, "NeverLetMeDown"));
				break;
			case 1993:
				v.push_back(make_pair(1993, "BlackTieWhiteNoise"));
				break;
			case 1995:
				v.push_back(make_pair(1995, "1.Outside"));
				break;
			case 1997:
				v.push_back(make_pair(1997, "Earthling"));
				break;
			case 1999:
				v.push_back(make_pair(1999, "Hours"));
				break;
			case 2002:
				v.push_back(make_pair(2002, "Heathen"));
				break;
			case 2003:
				v.push_back(make_pair(2003, "Reality"));
				break;
			case 2013:
				v.push_back(make_pair(2013, "TheNextDay"));
				break;
			case 2016:
				v.push_back(make_pair(2016, "BlackStar"));
				break;
			}
		}

		cout << v.size() << "\n";
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].first << " " << v[i].second << "\n";
		}
	}

	return 0;
}
