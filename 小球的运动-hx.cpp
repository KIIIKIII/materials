#include<cstdio>
#include<cstring>

int ball[1001][2];
int count;

void check(int n, int L) {
	int i = 0;
	for (; i < n - 1; i++) {
		if ((ball[i][0] == L && !ball[i][1]) || (!ball[i][0] && ball[i][1])) ball[i][1] = !ball[i][1];
		for (int j = i + 1; j < n; j++)
			if (ball[i][0] == ball[j][0])
				ball[i][1] ^= ball[j][1] ^= ball[i][1] ^= ball[j][1];
	}
	if ((ball[i][0] == L && !ball[i][1]) || (!ball[i][0] && ball[i][1])) ball[i][1] = !ball[i][1];
}

void go(int n, int L) {
	for (int i = 0; i < n; i++)
		ball[i][0] += ball[i][1] ? -1 : 1;
}

int main() {
	int n, L, t;
	scanf("%d%d%d", &n, &L, &t);
	for (int i = 0; i < n; i++) scanf("%d", &ball[i][0]);
	for (int s = 0; s < t; s++) {
		check(n, L);
		go(n, L);
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ball[i][0]);
	printf("\n");

	char a = getchar();
	char aa = getchar();
	return 0;
}
