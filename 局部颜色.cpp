#include "stdio.h"
#include "Windows.h"
int main() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED); // 设置为红色
	printf("把这句话颜色变成红色\n");
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);// 设置为黄色
	printf("把这句话颜色变成黄色\n");
}
