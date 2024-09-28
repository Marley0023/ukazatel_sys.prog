
using namespace std;
#include <iostream>

struct Node {
	int data;
	Node* next;
	Node* prev;
	Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
public:
	Node* head;
	Node* tail;
public:
	DoublyLinkedList() : head(nullptr), tail(nullptr) {}
	void push_front(int data) {
		Node* ptr = new Node(data);
		ptr->next = head;
		if (head != nullptr)
		{
			head->prev = ptr;
		}
		if (tail == nullptr)
		{
			tail = ptr;
		}
		head = ptr;
		return;
	}

	void push_back(int data) {
		Node* ptr = new Node(data);
		ptr->prev = tail;
		if (tail != nullptr)
		{
			tail->next = ptr;
		}
		if (head == nullptr)
		{
			head = ptr;
		}
		tail = ptr;
		return;
	}
	void pop_front() {
		if (head == nullptr)
		{
			return;
		}
		Node* ptr = head->next;
		if (head != nullptr)
		{
			ptr->prev = nullptr;
		}
		else
		{
			tail = nullptr;
		}
		delete head;
		head = ptr;
	}
	void pop_back() {
		if (tail == nullptr)
		{
			return;
		}
		Node* ptr = tail->prev;
		if (tail != nullptr)
		{
			ptr->next = nullptr;
		}
		else 
		{
			head = nullptr;
		}
		delete tail;
		tail = ptr;
	}
	void display() const
	{
		Node* ptr = new Node(0);
		cout << head->data;
		ptr = head;
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
			cout << endl << ptr->data << endl;
		}

	}
};

int main()
{
	setlocale(0, "rus");
	while (true)
	{
		cout << "Меню:" << endl;
		cout << "1.Добавить элемент в начало.\n2.Добавить элемент в конец.\n"
			<< "3.Удалить элемент с начала.\n4.Удалить элемент с конца.\n"
			<< "5.Отобразить список.\n6.Сортировать список.\n7.Удалить дубликаты.\n8.Выйти." << endl;
		cout << "Введите номер команды: ";
		DoublyLinkedList list;
		int a;
		cin >> a;
		if (a <= 0 || a > 8)
		{
			cout << "Введено неверное значение." << endl;
		}
		switch (a)
		{
		case 1: {
			int value;
			cout << "Введите элемент который хотите добавить: ";
			cin >> value;
			list.push_front(value);
			break;
		}
		case 2: {
			int value;
			cout << "Введите элемент который хотите добавить: ";
			cin >> value;
			list.push_back(value);
			break;
		}
		case 3: {
			cout << "Удаление элемента из начала списка";
			list.pop_front();
			break;
		}
		case 4: {
			cout << "Удаление элемента из конца списка";
			list.pop_back();
			break;
		}
		case 5: {
			cout << "Список: ";
			list.display();
			break;
		}
		case 6: {

		}
		case 7: {

		}
		case 8: {

			terminate();
		}
		}
	}
}

