#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

struct gg {
	string name;
	int role;
	gg* next;
	gg* prev;
};

class g_list {
public:
	g_list();
	~g_list();
	gg* head; // Первый элемент (голова) списка
	gg* tail; // Последний элемент (хвост) списка
	bool chk_empty();
	void comp_in(string n, int r);
	//gg* search(string n);
	//void comp_edit(gg &c, int* r);
	//void print();
	//void comp_del(gg* c);	
};

g_list::g_list() : head(nullptr), tail(nullptr) {}

g_list::~g_list() {
	while (head != 0) {
		gg* c = head;
		head = head->next;
		delete c;
	}
}

bool g_list::chk_empty()
{
	return (head == nullptr);
}

void g_list::comp_in(string n, int r) {
	gg* c = new gg();
	c->name = n;
	c->role = r;
	if (chk_empty()) {
		c->next = nullptr;
		c->prev = nullptr;
		head = c;
		tail = c;
	}
	else {
		tail->next = c;
		c->prev = tail;
		tail = c;
		tail->next = head;
		head->prev = tail;
	}
}

class role : public g_list
{
public:
	int roles[7] = { 0, 1, 2, 3, 4, 5, 6 }; //0-hit;1-2-red;3-6-blue
	int used_role[7];
	const char* plrs[7] = { "p1", "p2", "p3", "p4", "p5", "p6", "p7" };
	int test_role;
	int used_num = 0;
	bool fucked;
	void choice_role();
	string name_role;
};

void role::choice_role() {
	for (int i = 0; i < 7; i++) {
		do {
			fucked = false;
			test_role = roles[rand() % 7];
			for (int j = 0; j < used_num; j++) {
				if (test_role == used_role[j])
					fucked = true;
			}
		} while (fucked == true);
    name_role = plrs[i];
		used_role[used_num] = test_role;
		used_num++;
		comp_in(name_role, test_role);
		cout << name_role << endl << test_role << endl << endl;
	}
}


int elections() 
{
	gg* c = new gg();
	c = head;
	string firts_steper;
	bool ya = 1, nei = 0;
	int firts_steper = rand() % 10;
	for (int i = 0; i < firts_steper; i++)
		c = r.head->next;

}

int main() {
	setlocale(LC_ALL, "Rus");
	srand((unsigned)time(NULL));

	g_list g;
	role r;
	r.choice_role();

	//17 законов

	system("PAUSE");
	return 0;
}