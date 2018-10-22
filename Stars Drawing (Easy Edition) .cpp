#include <string>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <assert.h>
using namespace std;
typedef long long ll;
const int N = 100 + 5;
const int M = 200 + 5;
const int INF = 0x3f3f3f3f;
int n, m;
char a[N][N] = { 0 };

typedef struct star {
	int x;
	int y;
	int size;
}star;
star ans[N * N] = { 0 };

bool is_central(int x, int y) {
	if ((a[x][y] == '*' || a[x][y] == '#') 
		&& x - 1 >= 0 && x + 1 < n 
		&& y - 1 >= 0 && y + 1 < m)
		return (a[x - 1][y] == '*' || a[x - 1][y] == '#') 
		&& (a[x + 1][y] == '*' || a[x + 1][y] == '#')
		&& (a[x][y - 1] == '*' || a[x][y - 1] == '#') 
		&& (a[x][y + 1] == '*' || a[x][y + 1] == '#');
	return false;
}

int cal_size(int x, int y) {
	int size = 0;
	for (int i = 1; ; i++) {
		if (x - i >= 0 && x + i < n 
			&& y - i >= 0 && y + i < m) {
			if ((a[x - i][y] == '*' || a[x - i][y] == '#') 
				&& (a[x + i][y] == '*' || a[x + i][y] == '#')
				&& (a[x][y - i] == '*' || a[x][y - i] == '#') 
				&& (a[x][y + i] == '*' || a[x][y + i] == '#')) {
				size++;
				a[x][y] = '#';
				a[x - i][y] = '#'; a[x + i][y] = '#';
				a[x][y - i] = '#'; a[x][y + i] = '#';
			}
		}
		else break;
	}
	return size;
}

int main() {
	int cnt = 0;
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (is_central(i, j)) {
				ans[cnt].x = i;
				ans[cnt].y = j;
				ans[cnt++].size = cal_size(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '*') {
				cnt = -1;
				break;
			}
		}
	}

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		//while (ans[i].size > 0)
			printf("%d %d %d\n", ans[i].x + 1, ans[i].y + 1, ans[i].size);
	}

	return 0;
}
