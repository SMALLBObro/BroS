#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char p1, p2, p3, p4, p5, p6, p7;

/*struct gg {
	char name[10];
	int role;
	gg* next;
};

class g_list {
public:
	gg* head; // Первый элемент (голова) списка
	gg* tail; // Последний элемент (хвост) списка
	g_list();
	~g_list();
	bool chk_empty();
	void comp_in(char* n, int r);
	gg* search(char *n);
	void comp_edit(gg &c, int* r);
	void print();
	void comp_del(gg* c);
	void write_in_file();
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

void g_list::comp_in(char* n, int r) {
	gg* c = new gg();
	int nn;
	strcpy_s(c->name, 20, n);
	c->role = r;
	c->next = nullptr;
	if (chk_empty())
		head = c;
	else
		tail->next = c;
	tail = c;
}
*/
class role {
public:
	int roles[7] = { 0, 1, 2, 3, 4, 5, 6 }; //0-hit;1-2-red;3-6-blue
	int used_role[7];
	char pls[7] = { p1, p2, p3, p4, p5, p6, p7 };
	int test_role;
	int used_num = 0;
	bool fucked;
	void choice_role();
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

		pls[i] = test_role;
		used_role[used_num] = test_role;
		used_num++;
		cout << pls[i] << " = " << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	srand((unsigned)time(NULL));

	//g_list g;
	role r;

	r.choice_role();


	system("PAUSE");
	return 0;
}