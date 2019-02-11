#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char player1, player2, player3, player4, player5, player6, player7;

struct gamer {
	char name[10];
	int role;
	gamer* next;
};

class game_list {
public:
	gamer* head; // Первый элемент (голова) списка
	gamer* tail; // Последний элемент (хвост) списка
	game_list();
	~game_list();
	bool chk_empty();
	void comp_in(char* n, int r);
	gamer* search(char *n);
	void comp_edit(gamer &c, int* r);
	void print();
	void comp_del(gamer* c);
	void write_in_file();
};

game_list::game_list() : head(nullptr), tail(nullptr) {}

game_list::~game_list() {
	while (head != 0) {
		gamer* c = head;
		head = head->next;
		delete c;
	}
}

bool game_list::chk_empty()
{
	return (head == nullptr);
}

void game_list::comp_in(char* n, int r) {
	gamer* c = new gamer();
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

class role {
	int role[7] = { 0, 1, 2, 3, 4, 5, 6 }; //0-hit;1-2-red;3-6-blue
	int used_role[7];
	char players[7] = { player1, player2, player3, player4, player5, player6, player7 };
	int test_role;
	int used_num = 0;
	bool fucked;
	void choice_role();
};

void role::choice_role() {

	for (int i = 0; i < 7; i++) {
		
	}

	for (int i = 0; i < 7; i++) {
		do {
			fucked = false;
			test_role = role[rand() % 7];
			for (int j = 0; j < used_num; j++) {
				if (test_role == used_role[j])
					fucked = true;				
			}
		} while (fucked == true);

		players[i] = test_role;
		used_role[used_num] = test_role;
		used_num++;
		cout << players[i] << " = " << endl;
	}	   
}

int main() {
	setlocale(LC_ALL, "Rus");
	srand((unsigned)time(NULL));

	role r;

	r.choice_role();


	system("PAUSE");
	return 0;
}
