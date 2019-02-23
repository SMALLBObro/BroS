#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <windows.h>


using namespace std;

void start()
{
	char gamemode;
	cout << "Приветствуем Вас в нашей игре \"Тайный Гитлер\"!" << endl;
	cout << "\t\tЧтобы начать игру, нажмите Y. Выйти - N: ";
	while (true) {
		cin >> gamemode;
		if (gamemode == 'y') break;
		if (gamemode == 'n') exit(0); else cout << "Неверная кнопка, повторите своё действие!" << endl;
	}
}

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
	int roles[7] = { 0, 1, 2, 3, 4, 5, 6 }; //0-hitler;1-2-red;3-6-blue
	int used_role[7];
	const char* plrs[7] = { "p1", "p2", "p3", "p4", "p5", "p6", "p7" };
	int test_role;
	int used_num = 0;
	bool fucked;
	void choice_role();
	string name_role;
	void elections();
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
void role::elections()
{
	president = head;
	int choice_player;
	int first_steper = rand() % 7;
	for (int i = 0; i < first_steper; i++) {
		president = president->next;
	}
	cancler = president;
	cout << endl << "\t\tТоварищ президент был определён, это игрок: " << president->name << endl;
	cout << "Выбирете игрока, которого хотите назначить канцлером: " << endl;
	cout << "\t1 - " << president->next->name << endl;
	cout << "\t2 - " << president->next->next->name << endl;
	cout << "\t3 - " << president->next->next->next->name << endl;
	cout << "\t4 - " << president->prev->prev->prev->name << endl;
	cout << "\t5 - " << president->prev->prev->name << endl;
	cout << "\t6 - " << president->prev->name << endl;
	cout << "Ваш выбор: ";

	cin >> choice_player;

	cout << "\t\tПроводим голосование:" << endl;
	system("pause");
	bool voice; int j;
	int law;
	for (j = 1; j < 4; j++)
	{
		cout << j << " голосование:" << endl;
		int ya = 0, nein = 0;
		for (int i = 0; i < 7; i++)
		{
			cout << "Игрок под именем #" << president->name << "# голосуй!(1 - ya, 0 - nein): "; cin >> voice;
			if (voice == 1) ya++;
			else nein++;
			president = president->next;
		}

		if (ya > nein)
		{
			for (int i = 0; i < choice_player; i++)
			{
				cancler = cancler->next;
				j = 1;
			}
			break;
		}
		else continue;

	}
	if (j > 3)
	{
		law = laws[rand() % 17];
		cout << "Выбирается случайный закон, потому что канцлер не был выбран трижды...Подождите..." << endl;
		Sleep(3000);
		if (law == 0) cout << "Выбран случайный закон: ФАШИСТСКИЙ!" << endl;
		else cout << "Выбран случайный закон: ЛИБЕРАЛЬНЫЙ!" << endl;
		goto m1;
	}
	cout << "Игрок #" << cancler->name << "# назначен канцлером! " << endl;
m1:	system("pause");
	system("cls");
}

int main() {
	setlocale(LC_ALL, "Rus");
	srand((unsigned)time(NULL));
	start();
	role r;
	r.choice_role();
	r.print();
	r.elections();
	//17 законов (11 fashicst, 6 liberal)
	system("PAUSE");
	return 0;
}