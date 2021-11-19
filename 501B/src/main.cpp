#include <map>
//#include <unordered_map>
#include <string>
#include <stdio.h>

using namespace std;

int main() {

	map<string, string> hashMap;
	char _old[21];
	char _new[21];
	int n;
	int count = 0;
	scanf("%d", &n);
	while (n > 0) {
		scanf("%s %s", _old, _new);
		if (hashMap.find(string(_old) ) == hashMap.end()) {	//якщо немає додаємо
			hashMap[string(_new)] = _old;
			++count;
		}
		else {	//якщо є перезаписуємо
			auto it = hashMap.find(string(_old) );
			string old = it->second;	//зберігаємо початковий хендл
			hashMap.erase(it);
			hashMap[string(_new)] = old;
		}
		--n;
	}
	printf("%d\n", count);
	for (auto it = hashMap.begin(); it != hashMap.end(); it++) {
		printf("%s %s\n", it->second.c_str(), it->first.c_str());
	}

	return 0;
}