#pragma once
const int base = 1000000000;
struct elem
{
	int a;
	elem* next = nullptr;
	elem* prev = nullptr;
};
struct list
{
	elem* first = nullptr;
	elem* last = nullptr;
}; 
struct list_cycle
{
	elem* head = nullptr;
	int count = 0;
};
void add(list& list, int data);
void add(list_cycle& list, int data);
void sum(list_cycle& list3, list& list1, list& list2);
void show_list(const list& list, bool reversed = false);
void show_list(const list_cycle& list, bool reversed = false);
void show_num(const list_cycle& list);
void clear(list& list);
void clear(list_cycle& list);
