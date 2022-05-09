#include<iostream>
#include<string>
using namespace std;
struct elem
{
	int a;
	elem* next = nullptr;
};
bool find_elem(elem* first, int data) {
	if (first) {
		elem* curr = first;
		while ((curr)) {
			if (curr->a == data) {
				cout << "элемент со значением: " << data << " уже есть в списке!" << endl;
				return(true);
			}
			curr = curr->next;
		}
	}
	return(false);
}
void add(elem*& first, int data)
{
	if (!find_elem(first, data)) {
		elem* newel = new elem;
		newel->a = data;
		if (first)
		{
			elem* curr = first;
			while (curr->next)
			{
				curr = curr->next;
			}
			curr->next = newel;
		}
		else
		{
			first = newel;
		}
	}
}
void insert(elem*& first, int data, int pos)
{
	if (!find_elem(first, data)) {
		elem* newel = new elem;
		newel->a = data;
		if (first && pos > 0)
		{
			elem* curr = first;
			int p = 0;
			while (curr->next && p < pos - 1)
			{
				curr = curr->next;
				p++;
			}
			newel->next = curr->next;
			curr->next = newel;
		}
		else
		{
			newel->next = first;
			first = newel;
		}
	}
}
void clear(elem*& first)
{
	while (first)
	{
		elem* del = first;
		first = first->next;
		delete del;
	}
}
void show_list(elem* list)
{
	elem* curr = list;
	if (!curr) cout << "EMPTY LIST" << endl;
	else while (curr)
	{
		cout << curr->a << (curr->next ? " " : "\n");
		curr = curr->next;
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	elem* elem = nullptr;
	add(elem, 1); //elem, значение элемента
	add(elem, 2);
	add(elem, 3);
	add(elem, 4);
	add(elem, 3);
	insert(elem, 6, 2);  //elem, значение элемента, позиция
	insert(elem, 4, 3);
	insert(elem, 1, 4);
	show_list(elem);
	clear(elem);
}