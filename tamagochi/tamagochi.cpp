#include <iostream>
#include <windows.h>
#include <locale>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include <iomanip>
#include <random>
#include <vector>
using namespace std;
string png[4]{ "sprite0.txt","sprite1.txt","sprite2.txt","sprite6.txt" };
class mining {
private:
	float meaning;
	float total;
	float now = 1;//+
	int Crypto_Exchange = 0;
public:
	int lvl_upgrade = 1;
	mining();
	int give_cost_upgrade() {
		return 10 * lvl_upgrade;
	}
	void mine() {
		now = lvl_upgrade * 1;
		total += now;
		cout << endl << setw(25) << "\033[3;100;30m+" << now << " coins\033[0m\n";
		Sleep(200);
	}
	void get_stream(int a) {
		if (a == 0)
			cout << setw(0) << "\n Докупить оборудование (cost) : " << 10 * lvl_upgrade << " Текущая оснащённость : " << lvl_upgrade;
		if (a == 1) {
			printf("\x1B[31m ");
			cout << "\n" << "\n Докупить оборудование (cost) : " << 10 * lvl_upgrade << " Текущая оснащённость : " << lvl_upgrade << "\033[0m";
		}

	}
	void next_stage_birsha() {
		Crypto_Exchange = 0;
		bool TrueFalse = (rand() % 100) < 75;
		if (TrueFalse == 1)
			meaning += ((meaning / 100) * (rand() % 20));
		else
			meaning -= ((meaning) / (rand() % 50));
	}
	void give_info(float& m) {
		now = lvl_upgrade * 1;
		Crypto_Exchange += 1;
		if (Crypto_Exchange >= 20) {
			next_stage_birsha();
			mine();

		}
		cout << " " << total << " coins" << endl;
		for (int i = 0; i < Crypto_Exchange; i++) {
			cout << "\033[3;100;30m| |";
		}
		cout << Crypto_Exchange / 20.0 * 100 << " %";
		cout << "\033[0m\nThe hamster course: " << meaning << endl;
		cout << "Yours : " << now << "MH/s\n";
		cout << "You can sell all for " << meaning * total << " (press key 'c')" << endl;
		if (GetKeyState('C') & 0x8000) {
			if (total >= 1)
			{
				cout << "Успех!!\n";
				Sleep(200);
				m += meaning * total;
				total = 0;
			}
		}
	}
};
mining::mining() : now(0), lvl_upgrade(1), meaning(1) {

	cout << "Module create :\tMc " << endl;
}
class food {
private:
	int cost, unHungr;
public:
	int have = 0; string name;
	food();
	int give_unhg() {
		return unHungr;
	}
	void foodC(string nm, int c, int h) {
		name = nm; cost = c; unHungr = h;
	}
	int buy_in_shop() {
		have += 1;
	}
	int get_cost() {
		return cost;
	}

	void get_stream(int a) {
		if (a == 0)
			cout << setw(0) << "\nНазвание:" << name << " Цена: " << cost << " Утоляет голода: " << unHungr;
		if (a == 1) {
			printf("\x1B[31m ");
			cout << "\n" << setw(0) << "|Sellect " << name << " Цена: " << cost << " Утоляет голода: " << unHungr << "\033[0m";
		}

	}
	void get_stream_inv(int a) {
		if (a == 0)
			cout << setw(0) << "\nНазвание:" << name << " У вас : " << have << " Утоляет голода: " << unHungr;
		else if (a == 1) {
			printf("\x1B[31m ");
			cout << "\n" << setw(0) << "|Sellect " << name << " У вас : " << have << " Утоляет голода: " << unHungr << "|\033[0m";
		}
	}
};
food::food() : name("___"), cost(0), unHungr(0) {

	cout << "\tС " << endl; have = 0;
}
class properties {
private:
	float money; int hp, iq, hungry, phyzick_state, sellect; food shop[5], inventory[5]; mining videocards;
public:
	int random_phraz_time = 0; int linee = 1; vector <string> variants;
	properties();
	~properties(void);
	void buy_videocard() {
		float tt = videocards.give_cost_upgrade();
		cout << videocards.give_cost_upgrade() << endl;Sleep(199);
		if (tt < money) {
			cout << "\n\x1B[36m	Улучшние было приобретено \033[0m\n";
			videocards.lvl_upgrade += 1;
			money -= videocards.give_cost_upgrade();
		}
		else
			cout << "Не удлалось улучшить!\n";
	}
	void mine() {
		videocards.give_info(money);
	}
	void bool_buy_shop(int b) {
		if (shop[sellect].get_cost() <= money && b == 0)
			buy_shop(shop[sellect], shop[sellect].get_cost(), 0);
		else
			if (b == 1)
				buy_shop(inventory[sellect], shop[sellect].get_cost(), 1);
	}
	void buy_shop(food a, int m, int d) {
		if (d == 0) {
			for (int i = 0; i < size(shop); i++) {
				if (i == sellect) {
					for (int j = 0; j < size(inventory); j++) {
						if (inventory[j].have == 0) {
							inventory[j] = shop[i];
							inventory[j].have += 1;
							money -= shop[i].get_cost();
							break;
						}
						else {
							if (inventory[j].name == shop[i].name && inventory[j].have > 0) {
								inventory[j].have += 1;
								money -= shop[i].get_cost();
								break;
							}
						}

					}
				}
			}
		}
		else
			if (d == 1) {//inventory use
				for (int i = 0; i < size(shop); i++) {
					if (i == sellect) {
						if (inventory[sellect].have >= 1) {
							inventory[sellect].have -= 1;
							hungry += inventory[sellect].give_unhg();
							cout << "\nВы успешно использовали предмет:" << inventory[sellect].name << endl;
							Sleep(250);
							break;
						}
						else {
							cout << "\nВы не можете совершить это действие !!!\n"; Sleep(100); break;
						}
					}
				}
			}
	}
	void key(string k, int a) {
		if ((k == to_string(a)) || (a == 0 && k == ("esc"))) {
			printf("\x1B[31m ");
			cout << setw(10) << "|Press " << k << "|\033[0m";
		}
		else
			cout << "\033[0m" << setw(10) << "|Press " << k << "|";
	}
	void shop_adder() {
		sellect = 0;
		shop[0].foodC("Salo", 10 * 6, 6);
		shop[1].foodC("Kolbasa", 10 * 12, 12);
		shop[2].foodC("Hleb", 10 * 3, 3);
		shop[3].foodC("Buter", 10 * 7, 7);
		shop[4].foodC("tomat", 10 * 2, 2);
	}
	int replics_giver() {
		int g = rand() % 4;
		if (g == 0)
			if (hungry >= 75)
				return 10;
			else
				if (hungry <= 50)
					return 11;
				else
					if (hungry <= 25)
						return 12;
					else
						if (hungry <= 10)
							return 13;
						else
							if (g == 1)
								if (iq >= 75)
									return 6;
								else
									if (iq <= 50)
										return 7;
									else
										if (iq <= 25)
											return 8;
										else
											if (iq <= 10)
												return 9;
											else
												if (g == 2)
													if (hp >= 75)
														return 2;
													else
														if (hp <= 50)
															return 3;
														else
															if (hp <= 25)
																return 4;
															else
																if (hp <= 10)
																	return 5;
																else
																	if (g == 3)
																	{
																		int ra = (rand() % 2);
																		if (ra == 0)
																			return 0;
																		else
																			return 1;
																	}
	}
	void interf(int k) {
		//keys
		if (hp <= 0) {
			string end_game = "К сожалению ваш питомец умер . . . . . . .";
			for (int i = 0; i < end_game.size();i++) {
				cout << end_game[i];Sleep(100);
			}
			Sleep(1000);
			exit(0);
		}
		if (GetKeyState('L') & 0x8000)
			hp = 1;

		key("esc", k);
		key("1", k);
		key("2", k);
		key("3", k);
		if (GetKeyState('S') & 0x8000 || GetKeyState(VK_DOWN) & 0x8000) {
			if (sellect <= size(shop) || sellect <= size(inventory))
				sellect += 1;
		}
		else
			if (GetKeyState('W') & 0x8000 || GetKeyState(VK_UP) & 0x8000) {
				if (sellect != 0)sellect -= 1;
			}
		///replic

		if (k == 0) {
			string line;
			int chislo;
			random_phraz_time += 1;

			// Счётчик для вызова реплики каждые 8 циклов
			if (random_phraz_time == 5) {
				linee = replics_giver();
				chislo = rand() % 10;
				random_phraz_time = 0; // Сбрасываем счётчик
			}

			cout << endl;
			for (int i = 0; i < 15 * 7; i++)
				cout << "-";

			ifstream in("replics.txt");
			cout << "\nGrigor: ";
			if (in.is_open())
			{
				int ln = 0;
				while (getline(in, line))
				{
					if (ln == linee) {
						vector<string> variants;
						int start = -1;
						for (int i = 0; i < line.size(); i++) {
							if (line[i] == '[') {
								start = i + 1;
							}
							else if (line[i] == ']' && start != -1) {
								variants.push_back(line.substr(start, i - start));
								start = -1;
							}
						}

						// Выбор случайного варианта (если есть варианты)
						if (!variants.empty()) {
							int r_request = rand() % variants.size();
							cout << variants[r_request] << endl;
							Sleep(400);
						}
						else {
							cout << "..." << endl; // Если вариантов нет
						}
						break;
					}
					ln += 1;
				}
			}
			in.close();

			for (int i = 0; i < 15 * 7; i++)
				cout << "-";
		}
		//shop
		if (k == 1) {
			cout << "\n" << setw(25) << "Shop:";
			for (int i = 0; i < size(shop); i++) {
				if (sellect == i)
					shop[i].get_stream(1);
				else
					shop[i].get_stream(0);
			}
		}
		//inventory
		if (k == 2) {
			cout << "\n" << setw(25) << "Inventory:";
			for (int i = 0; i < size(inventory); i++) {
				if (inventory[i].have != 0) {
					if (sellect == i) {
						inventory[i].get_stream_inv(1);
					}
					else
						inventory[i].get_stream_inv(0);
				}
				else
				{
					if (sellect == i)
						cout << "\n--->\t|Пусто|\t<---";
					else
						cout << "\n\t|Пусто|";
				}
			}
		}
		///minigame
		if (k == 3) {
			cout << "\n" << setw(25) << "Mining:";
			mine();
			if (sellect == 0)
				videocards.get_stream(1);
			else
				videocards.get_stream(0);
		}
	}
	void update_states(string sprite, int ls, int le, int k) {
		string line;
		ifstream in(sprite);
		if (in.is_open())
		{
			int ln = 1;
			while (getline(in, line))
			{
				if ((ls <= ln) && (ln <= le)) {
					cout << line << endl;
				}
				ln += 1;
				if (ln >= le)
					break;
			}
		}
		in.close();
		cout << setw(20) << "Money: " << money << endl;
		status();
		interf(k);
	}
	void stat(string a, int b) { //\033[0m
		cout << a << ":\033[3;42;30m";
		for (int i = 0; i < (b / 10); i++) {
			cout << " | ";
			if (i + 1 >= (b / 10))
				cout << "\033[0m";
		}
		if (b >= 10)
			cout << "\t" << b << endl;
		else
			cout << "\033[0m" << "\033[31m\t\t\t" << "<=10" << endl;
	}
	void status() {
		stat("HP", hp);
		stat("IQ", iq);
		stat("H-gry", hungry);
		stat("Физичесское состояние", phyzick_state);

	}
	void bio() {
		hungry -= 1;
		if (hungry <= 10)
			hp -= 1;
		if (hungry <= 50) {
			hp -= 1;
			if (phyzick_state >= 1)
				phyzick_state -= 1;
		}
	}
};
properties::properties() : hp(100), iq(100), hungry(50), phyzick_state(1), money(100), sellect(0) {

	cout << "Module create :\tc " << endl;
}

properties::~properties(void) {
	cout << "D\n";
}

class tamogochi
{
public:
	string name;
private:
	string ovner; int years, key; float g_time_s, g_time_m; properties he; bool enter = 0;
public:
	int vent = 1;
	tamogochi();
	~tamogochi(void);
	void init() {
		g_time_s = 0; g_time_m = 0;
		cout << "Загрузка:";
		for (int i = 0; i < 10; i++) {
			Sleep(100);
			cout << " | ";
		}
		he.shop_adder();

	}
	void t_main() {
		if ((g_time_s == 100) || (g_time_s == 200) || (g_time_s == 300) || (g_time_s == 400) || (g_time_s == 500) || (g_time_s == 599))he.bio();
		g_time_s += 2;
		if (g_time_s >= 600) {
			g_time_s -= 600; g_time_m += 1;
		}
		///Age
		years = g_time_m / 5;
		///
		cout << setw(63) << "|Time in game: " << g_time_m << "m :" << g_time_s / 10 << "s|" << endl;
		if (key == 0)cout << "\n" << setw(50) << "|Owner: " << ovner << " | Name : " << name << " | " << years << " лет|" << endl;
		next_frame();///next
		if (GetKeyState(VK_RETURN) & 0x8000)//ВВОД
			enter = 1;
		else
			enter = 0;
		if (GetKeyState(VK_ESCAPE) & 0x8000)//VK_ESCAPE
			key = 0;
		if (GetKeyState('1') & 0x8000)
			key = 1;
		else
			if (GetKeyState('2') & 0x8000)
				key = 2;
			else
				if (GetKeyState('3') & 0x8000)
					key = 3;
	}
	void next_frame() {
		if (key == 0)
			he.update_states(png[0], 1, 13, key);
		else
			if (key == 1) {
				he.update_states(png[1], 1, 15, key);
				if (enter == 1)
					he.bool_buy_shop(0);
			}
			else
				if (key == 2) {
					he.update_states(png[2], 1, 9, key);
					if (enter == 1)
						he.bool_buy_shop(1);
				}
				else
					if (key == 3) {
						if (vent == 4)vent = 1;
						if (vent == 1)
							he.update_states(png[3], vent, 19 * vent, key);//he.update_states(png[3], 1,16,key);
						else
							if (vent == 2)
								he.update_states(png[3], 19, 19 * 2, key);
							else
								if (vent == 3)
									he.update_states(png[3], 19 * 2, 19 * 2 * vent, key);
						vent = vent + 1;
						if (enter == 1)
							he.buy_videocard();
					}
		Sleep(200);
		system("cls");
	}
	void set_stream() {
		cout << " Данные внесены" << endl;
	}
	void get_stream() {
		cout << ovner << ":" << "\tИмя:" << name << "\tВозраст:" << years << " лет" << endl;
	}
	tamogochi(string a, string b, int c, int k) { //конструктор
		ovner = a; name = b; years = c; key = k;
		cout << "Module create :T";
	}
};
tamogochi::tamogochi() : ovner("---"), name("---"), years(000) {

	cout << "Module create :T";
}

tamogochi::~tamogochi(void) {
	cout << "Module delet :D";
}

//getch();



int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");


	tamogochi man("You", "Grigor", 0, 1);
	man.init();
	//	man.get_stream();
	while (true) {
		man.t_main();
	}
}
