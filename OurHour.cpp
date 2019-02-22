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

class role {
public:
	role();
	~role();
	gg* head;
	gg* tail;
	gg* head_l;
	gg* tail_l;
	bool chk_empty();
	void add_player(string n, int r);
	void add_law(int r);
	void print();
	int laws[17] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 }; //0 - fash; 1 - lib
	int used_laws[17];
	int used_role_num = 0;
	int roles[7] = { 0, 1, 2, 3, 4, 5, 6 }; //0-hit;1-2-red;3-6-blue
	int used_role[7];
	const char* plrs[7] = { "p1", "p2", "p3", "p4", "p5", "p6", "p7" };
	int test_role;
	int used_num = 0;
	bool fucked;
	void choice_role();
	string name_role;
	int elections();
	gg* president;
	gg* cancler;
	void deck_building();
	void delete_law();
};


role::role() : head(nullptr), tail(nullptr) {}

role::~role() {
	while (head != 0) {
		gg* c = head;
		head = head->next;
		delete c;
	}
}

void role::add_player(string n, int r) {
	gg* c = new gg();
	c->name = n;
	c->role = r;
	if (head == nullptr) {
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

void role::add_law(int l) {
	gg* c = new gg();
	c->role = l;
	if ((head_l == nullptr)) {
		c->next = nullptr;
		c->prev = nullptr;
		head_l = c;
		tail_l = c;
	}
	else {
		tail_l->next = c;
		c->prev = tail_l;
		tail_l = c;
		tail_l->next = head_l;
		head_l->prev = tail_l;
	}
}

void role::print() {
	gg* c = new gg();
	c = head;
	do {
		cout << "Name - " << c->name << endl;
		cout << "Role - " << c->role << endl << endl;
		c = c->next;
	} while (c != head);
}

//Расспределение ролей между игроками
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
		add_player(name_role, test_role);
	}
}

//Колода законов
void role::deck_building() {
	for (int i = 0; i < 17; i++) {
		do {
			fucked = false;
			test_role = roles[rand() % 17];
			for (int j = 0; j < used_role_num; j++) {
				if (test_role == used_role[j])
					fucked = true;
			}
		} while (fucked == true);
		add_law(test_role);
		used_laws[used_role_num] = test_role;
		used_role_num++;
	}
}

void role::delete_law() {
	gg* c = new gg();
	c = tail;
	tail = tail->prev;
	delete c;
}

//Выборы 
int role::elections()
{
	president = head;
	bool yah = 1, nein = 0;
	int choice_player;
	int first_steper = rand() % 7;
	for (int i = 0; i < first_steper; i++) {
		president = president->next;
	}
	cancler = president;
	cout << endl << "\t\tТоварищ президент был определён: " << president->name << endl;
	cout << "1 - " << president->next->name << endl;
	cout << "2 - " << president->next->next->name << endl;
	cout << "3 - " << president->next->next->next->name << endl;
	cout << "4 - " << president->prev->prev->prev->name << endl;
	cout << "5 - " << president->prev->prev->name << endl;
	cout << "6 - " << president->prev->name << endl;
	cout << "Введите номер игрока, которого хотите сделать канцлером: ";
	cin >> choice_player;
	for (int i = 0; i < choice_player; i++)
	{
		cancler = cancler->next;
	}
	cout << "Канцлер: " << cancler->name << endl;
	return 9;
}

int main() {
	setlocale(LC_ALL, "Rus");
	srand((unsigned)time(NULL));

	role r;
	r.choice_role();
	r.print();
	r.elections();
	//17 законов (11 fashicst, 6 liberal)
	system("PAUSE");
	return 0;
}