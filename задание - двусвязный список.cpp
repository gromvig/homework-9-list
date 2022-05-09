
#include <iostream>
#include"list.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	list* num1 = new list;
	list* num2 = new list;
	list_cycle* num3 = new list_cycle;
	char a[256];
	char b[256];
	cout << "Введите первое число для суммирования:" << endl;
	cin >> a;
	for (int i = (int)strlen(a); i > 0; i -= 9) {
		a[i] = 0;
		add(*num1, atoi(i >= 9 ? a + i - 9 : a));
	}
	cout << "Введите второе число для суммирования:" << endl;
	cin >> b;
	for (int i = (int)strlen(b); i > 0; i -= 9) {
		b[i] = 0;
		add(*num2, atoi(i >= 9 ? b + i - 9 : b));
	}
	sum(*num3, *num1, *num2);
	show_list(*num1, true);
	show_list(*num2, true);
	show_num(*num3);
	clear(*num1);
	clear(*num2);
	clear(*num3);
	return(0);
}