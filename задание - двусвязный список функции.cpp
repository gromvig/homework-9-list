
#include <iostream>
#include "List.h"

using namespace std;
void add(list& list, int data)
{
	elem* newel = new elem;
	newel->a = data;
	if (!list.first)
	{
		list.first = list.last = newel;
	}
	else
	{
		list.last->next = newel;
		newel->prev = list.last;
		list.last = newel;
	}
}
void add(list_cycle& list, int data)
{
	elem* newel = new elem;
	newel->a = data;
	if (!list.head)
	{
		list.head = newel;
		list.head->next = list.head;
		list.head->prev = list.head;
	}
	else
	{
		list.head->prev->next = newel;
		newel->next = list.head;
		newel->prev = list.head->prev;
		list.head->prev = newel;
	}
}
void sum(list_cycle& list3, list& list1, list& list2)
{
	elem* curr1 = list1.first;
	elem* curr2 = list2.first;
	int carry = 0;
	while (curr1 || curr2 || carry) {
		int a = curr1 ? curr1->a : 0;
		int b = curr2 ? curr2->a : 0;
		int sum = a + b + carry;
		carry = sum >= base;
		if (carry)  sum -= base;
		add(list3, sum);
		curr1 = curr1 ? curr1->next : nullptr;
		curr2 = curr2 ? curr2->next : nullptr;
	}
}
void show_list(const list& list, bool reversed)
{
	elem* curr = reversed ? list.last : list.first;
	if (!curr) cout << "Список пуст\n";
	else while (curr)
	{
		elem* cmp = reversed ? list.first : list.last;
		cout << curr->a << ((curr == cmp) ? "\n" : " ");
		curr = reversed ? curr->prev : curr->next;
	}
}
void show_list(const list_cycle& list, bool reversed)
{
	elem* curr = reversed ? list.head->prev : list.head;
	if (!curr) cout << "Список пуст\n";
	else
	{
		elem* cmp = reversed ? list.head : list.head->prev;
		do
		{
			cout << curr->a << ((curr == cmp) ? "\n" : " ");
			curr = reversed ? curr->prev : curr->next;
		} while (curr != (reversed ? list.head->prev : list.head));
	}
}
void show_num(const list_cycle& list)
{
	if (!&list)
		return;
	elem* curr = list.head->prev;
	printf("%d", !curr ? 0 : curr->a);
	curr = curr->prev;
	while (curr->next != list.head)
	{
		printf("%09d", curr->a);
		curr = curr->prev;
	}
}
void clear(list& list)
{
	elem* rem;
	while (list.first)
	{
		rem = list.first;
		list.first = list.first->next;
		delete rem;
	}
	list.last = nullptr;
}
void clear(list_cycle& list)
{
	elem* rem;
	while (list.head->next != list.head)
	{
		rem = list.head->next;
		list.head->next = list.head->next->next;
		delete rem;
	}
	list.head = nullptr;
}