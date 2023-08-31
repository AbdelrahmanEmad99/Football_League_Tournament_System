#include<map>
#include<list>
#include <string>
#include <fstream>
#include <assert.h>
#include <iostream>
#include <unordered_map>

using namespace std;

#pragma once
template<class T>
class transfer
{
	int size;
	int elements;
	T *arr;
public:

	transfer();
	void  pop();
	void push(T val);
	T top();
	void expand();
	bool Empty();

};

template<class T>
transfer<T>::transfer()
{
	elements = 0;
	size = 14;
	arr = new T[size];

}

template<class T>
void transfer<T>::pop()
{
	assert(!Empty());
	elements--;
}

template<class T>
void transfer<T>::push(T val)
{
	if (elements == size)
	{
		expand();
	}
	arr[elements] = val;
	elements++;
}

template<class T>
void transfer<T>::expand()
{
	T *newarr = new T[size * 2];
	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i];
	}
	size *= 2;
	delete[] arr;
	arr = newarr;
}

template<class T>
T transfer <T>::top()
{
	assert(!Empty());
	return arr[elements - 1];
}

template<class T>
bool transfer <T>::Empty()
{
	return(elements == 0);
}

struct rslt
{
	string chmp;
	string rnu;
	string topG;
	string topA;
	string bestP;
	string bestC;
	string reg[3];
	string prm[3];
};

struct admin
{
	string username;
	string password;
};

struct player
{
	string name;
	string position;
	string IN;
	string OUT;
	int games;
	int goals;
	int assist;
	int yellow;
	int red;
};

struct team
{
	string nickname;
	string coach;
	string founded;
	string ground;
	string capacity;
	unordered_map<int, player> player_detail;
	unordered_map<int, player> ::iterator pd;
	int league;
	int cup;
};

struct matches
{
	string Team_1;
	int Goals_1;
	string *score_1;
	int Assist_1;
	string *make_1;
	int Y_Cards_1;
	string *Yellow_1;
	int R_Cards_1;
	string *Red_1;

	string Team_2;
	int Goals_2;
	string *score_2;
	int Assist_2;
	string *make_2;
	int Y_Cards_2;
	string *Yellow_2;
	int R_Cards_2;
	string *Red_2;
};

struct weeks
{
	matches match[4];
	matches cup_Quarterfinal[4];
	matches cup_semifinal[4];
	matches cup_final[4];
};

struct stndg
{
	string index;
	string name;
	string win;
	string draw;
	string lose;
	string frw;
	string agn;
	string pts;
};

unordered_map<string, team> team_detail;
unordered_map<string, team> ::iterator tm;

int userNum;
admin *user;
weeks week[14];
stndg stn[8];
rslt rs;
int laa3ref = 0;

void add_match(int number, int i);
void add_cup_Ouartetfinal(int number, int i);
void add_cup_semifinal(int number, int i);
void add_cup_final(int number, int i);
void add_week();
void show_week();
int clear();
int login();
void autoSave();
void readData();
void writeData();
void adminFun();
void readAdmin();
void writeAdmin();
void add_admin();
void editPlayer();
void editTeam();
void add_player(int a, string str);
void display_player(int a, string str);
void delete_player();
void add_team();
void display_team();
void delete_team();
void read_team();
void write_team();
void search();
void stand();
void cards();
void asists();
void goals();
void weekFun();
void tranzf();
void add_stnd();
void read_stnd();
void show_stnd();
void stnd();
void write_stnd();
void showEnd();
void enterEnd();

int main()
{
	readData();

	int counter = 0;

	while (true)
	{
		if (system("CLS")) { system("clear"); }

		if (counter == 0)
		{
			cout << "1 - Standings" << "\n";
			cout << "2 - Search" << "\n";
			cout << "3 - Show Matches" << "\n";
			cout << "4 - Transfers" << "\n";
			cout << "5 - Login" << "\n";
			cout << "6 - End program" << "\n";
			if (laa3ref == 1)
			{
				cout << "7 - Season Results" << "\n";
			}
		}

		cout << "\n";

		int choose; cout << "Choose operation: "; cin >> choose;

		cout << "\n";

		if (choose == 1) { stand(); }

		else if (choose == 2) { search(); }

		else if (choose == 3) { weekFun(); }

		else if (choose == 4) { tranzf(); }

		else if (choose == 5)
		{
			if (login() == 1) { adminFun(); }
			else { break; }
		}

		else if (choose == 6) { cout << "THANK YOU" << "\n\n"; break; }

		else if (choose == 7 && laa3ref == 1) { showEnd(); }

		else
		{
			counter++;

			if (counter == 3) { cout << "TIME OUT" << "\n\n"; break; }

			else { cout << "Wrong choice, try again" << "\n"; }
		}

		if (choose > 0 && choose < 4)
		{
			counter = 0;

			cout << "To countine press (1)" << "\n";
			cout << "To exit press (2)" << "\n\n";

			int con = clear();

			if (con == 1)
			{
				if (system("CLS")) { system("clear"); }
			}

			else if (con == 2) { cout << "THANK YOU" << "\n\n"; break; }

			else if (con == 3) { break; }
		}

		autoSave();
	}

	writeData();

	return 0;
}

int clear()
{
	int clr;

	int counter = 0;

	while (true)
	{
		cout << "Your choice: "; cin >> clr;

		cout << "\n";

		if (clr == 1) { return 1; }

		else if (clr == 2) { return 2; }

		else
		{
			counter++;

			if (counter == 3) { cout << "TIME OUT" << "\n\n"; return 3; break; }

			else { cout << "Wrong choice, try again" << "\n\n"; }
		}
	}
}

int login()
{
	int break_counter = 0, index;

	string login_username;
	string login_password;

	cin.ignore();

	while (true)
	{
		cout << "Enter username: "; getline(cin, login_username);

		for (int i = 0; i < userNum - 1; i++)
		{
			if (login_username == user[i].username)
			{
				login_username = "Yes";
				index = i;
			}
		}

		if (login_username != "Yes")
		{
			break_counter++;

			if (break_counter == 3) { cout << "\n" << "TIME OUT" << "\n\n"; break; }

			else { cout << "\n" << "Username not found, try again" << "\n\n"; }
		}

		else { cout << "\n"; break; }
	}

	if (break_counter != 3)
	{
		break_counter = 0;

		while (true)
		{
			cout << "Enter password: "; getline(cin, login_password);

			if (login_password == user[index].password)
			{
				login_password = "Yes";
			}

			if (login_password != "Yes")
			{
				break_counter++;

				if (break_counter == 3) { cout << "\n" << "TIME OUT" << "\n\n"; break; }

				else { cout << "\n" << "Password not found, try again" << "\n\n"; }
			}

			else { cout << "\n"; break; }
		}
	}

	if (login_username == "Yes" && login_password == "Yes")
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

void autoSave()
{
	writeData();
	readData();
}

void readData()
{
	readAdmin();
	read_team();
	read_stnd();
}

void writeData()
{
	writeAdmin();
	write_team();
	write_stnd();
}

void readAdmin()
{
	ifstream read_user;
	read_user.open("Admin.txt");

	if (read_user.is_open())
	{
		string temp_str;
		getline(read_user, temp_str);
		userNum = stoi(temp_str);

		user = new admin[userNum];

		for (int i = 0; i < userNum; i++)
		{
			getline(read_user, user[i].username);
			getline(read_user, user[i].password);
		}

		read_user.close();
	}

	else { userNum = 0; }
}

void writeAdmin()
{
	ofstream write_user;
	write_user.open("Admin.txt");

	write_user << userNum << endl;

	for (int i = 0; i < userNum; i++)
	{
		write_user << user[i].username << endl;
		write_user << user[i].password << endl;
	}

	write_user.close();
}

void adminFun()
{


	int counter = 0;

	while (true)
	{
		if (system("CLS")) { system("clear"); }

		if (counter == 0)
		{
			cout << "1 - Add new admin" << "\n";
			cout << "2 - Edit team" << "\n";
			cout << "3 - Edit player" << "\n";
			cout << "4 - Season results" << "\n";
			cout << "5 - Logout" << "\n";
		}

		cout << "\n";

		int choose; cout << "Choose operation: "; cin >> choose;

		cout << "\n";

		if (choose == 1) { add_admin(); }

		else if (choose == 2) { editTeam(); }

		else if (choose == 3) { editPlayer(); }

		else if (choose == 4) { enterEnd(); }

		else if (choose == 5) { break; }

		else
		{
			counter++;

			if (counter == 3) { cout << "TIME OUT" << "\n\n"; break; }

			else { cout << "Wrong choice, try again" << "\n"; }
		}

		autoSave();
	}

	if (system("CLS")) { system("clear"); }
}

void add_admin()
{
	userNum++;

	admin *temp = new admin[userNum];

	string str; int cont = 1;

	cin.ignore();

	for (int l = 0; l < 3; l++)
	{
		cout << "Username: "; getline(cin, str);

		for (int i = 0; i < userNum - 1; i++)
		{
			if (str == user[i].username && l < 2) { cout << "\n" << "Username already used" << "\n\n"; cont = 0; }
		}

		if (l < 2 && cont == 1) { break; }

		else if (l == 2) { cout << "\n" << "TIME OUT" << "\n\n"; }
	}

	if (cont == 1)
	{
		for (int i = 0; i < userNum - 1; i++)
		{
			temp[i].username = user[i].username;
			temp[i].password = user[i].password;
		}

		delete[] user;

		user = temp;

		user[userNum - 1].username = str;
		cout << "\n" << "Password: "; getline(cin, user[userNum - 1].password);
		cout << "\n" << "ADMIN ADDED" << "\n\n";
	}

	int h; cout << "press any bottom to continue: "; cin >> h;

	h = 0;

	if (h == 0)
	{
		if (system("CLS")) { system("clear"); }
	}
}

void editTeam()
{
	if (system("CLS")) { system("clear"); }

	int counter = 0;

	while (true)
	{
		if (counter == 0)
		{
			cout << "1 - Add team" << "\n";
			cout << "2 - Display team" << "\n";
			cout << "3 - Delete team" << "\n";
			cout << "4 - Rreturn" << "\n";
		}

		cout << "\n";

		int choose; cout << "Choose operation: "; cin >> choose;

		cout << "\n"; cin.ignore();

		if (choose == 1) { add_team(); }

		else if (choose == 2) { display_team(); }

		else if (choose == 3) { delete_team(); }

		else if (choose == 4) { break; }

		else
		{
			counter++;

			if (counter == 3) { cout << "TIME OUT" << "\n\n"; break; }

			else { cout << "Wrong choice, try again" << "\n"; }
		}
	}

	if (system("CLS")) { system("clear"); }
}

void editPlayer()
{
	if (system("CLS")) { system("clear"); }

	int counter = 0;

	while (true)
	{
		if (counter == 0)
		{
			cout << "1 - Add players" << "\n";
			cout << "2 - Display player" << "\n";
			cout << "3 - Delete player" << "\n";
			cout << "4 - Return" << "\n";
		}

		cout << "\n";

		int choose; cout << "Choose operation: "; cin >> choose;

		cout << "\n"; cin.ignore();

		if (choose == 1) { add_player(0, ""); }

		else if (choose == 2) { display_player(0, ""); }

		else if (choose == 3) { delete_player(); }

		else if (choose == 4) { break; }

		else
		{
			counter++;

			if (counter == 3) { cout << "TIME OUT" << "\n\n"; break; }

			else { cout << "Wrong choice, try again" << "\n"; }
		}
	}

	if (system("CLS")) { system("clear"); }
}

void add_player(int a, string str)
{
	if (a == 0)
	{
		cout << "enter team: "; getline(cin, str);
	}

	int size; cout << "# of players: "; cin >> size;

	int plrNum;

	for (int i = 0; i < size; i++)
	{
		cout << "\n";
		cout << "Player no. " << i + 1 << ":\n";
		cout << "--> number: "; cin >> plrNum; cin.ignore();
		cout << "--> name: "; getline(cin, team_detail[str].player_detail[plrNum].name);
		cout << "--> position: "; getline(cin, team_detail[str].player_detail[plrNum].position);
		cout << "--> date in: "; getline(cin, team_detail[str].player_detail[plrNum].IN);
		cout << "--> date out: "; getline(cin, team_detail[str].player_detail[plrNum].OUT);
		cout << "--> played: "; cin >> team_detail[str].player_detail[plrNum].games;
		cout << "--> goals: "; cin >> team_detail[str].player_detail[plrNum].goals;
		cout << "--> assists: "; cin >> team_detail[str].player_detail[plrNum].assist;
		cout << "--> yellow cards: "; cin >> team_detail[str].player_detail[plrNum].yellow;
		cout << "--> red cards: "; cin >> team_detail[str].player_detail[plrNum].red;
		int q = 3;
		for (int a = 1; a < 14; a++){
			if (team_detail[str].player_detail[plrNum].yellow == q * a)
			{
				team_detail[str].player_detail[plrNum].red++;
			}
		}
	}
}

void display_player(int a, string str)
{
	if (a == 0)
	{
		cout << "enter team: "; getline(cin, str);
		int plrNum; cout << "# of player: "; cin >> plrNum;

		cout << "--> name: " << team_detail[str].player_detail[plrNum].name << "\t";
		cout << "--> position: " << team_detail[str].player_detail[plrNum].position << "\t";
		cout << "-->  date in: " << team_detail[str].player_detail[plrNum].IN << "\t";
		cout << "--> date out: " << team_detail[str].player_detail[plrNum].OUT << "\t";
		cout << "--> played: " << team_detail[str].player_detail[plrNum].games << "\t";
		cout << "--> goals: " << team_detail[str].player_detail[plrNum].goals << "\t";
		cout << "--> assists: " << team_detail[str].player_detail[plrNum].assist << "\t";
		cout << "--> yellow cards: " << team_detail[str].player_detail[plrNum].yellow << "\t";
		cout << "--> red cards: " << team_detail[str].player_detail[plrNum].red << "\t";
	}

	else
	{
		cout << "# of player" << "\t";
		cout << "name" << "\t";
		cout << "position" << "\t";
		cout << "date in" << "\t";
		cout << "date out" << "\t";
		cout << "played" << "\t";
		cout << "goals" << "\t";
		cout << "assists" << "\t\t";
		cout << "yellow cards" << "\t";
		cout << "red cards" << "\t";

		for (team_detail[str].pd = team_detail[str].player_detail.begin(); team_detail[str].pd != team_detail[str].player_detail.end(); team_detail[str].pd++)
		{

			cout << team_detail[str].pd->first << "\t\t";
			cout << team_detail[str].pd->second.name << "\t";
			cout << team_detail[str].pd->second.position << "\t\t";
			cout << team_detail[str].pd->second.IN << "\t";
			cout << team_detail[str].pd->second.OUT << "\t\t";
			cout << team_detail[str].pd->second.games << "\t";
			cout << team_detail[str].pd->second.goals << "\t";
			cout << team_detail[str].pd->second.assist << "\t\t";
			cout << team_detail[str].pd->second.yellow << "\t\t";
			cout << team_detail[str].pd->second.red << "\t";
			cout << "\n";
		}
	}
}

void delete_player()
{
	string str; cout << "enter team: "; getline(cin, str);

	int plrNum; cout << "# of player: "; cin >> plrNum;

	team_detail[str].player_detail.erase(plrNum);

	cout << "PLAYER REMOVED" << "\n";
}

void add_team()
{
	cout << "Team detail(s)" << "\n\n";
	string str; cout << "--> name: "; getline(cin, str);

	cout << "--> nickname: "; getline(cin, team_detail[str].nickname);
	cout << "--> coach: "; getline(cin, team_detail[str].coach);
	cout << "--> date founded: "; getline(cin, team_detail[str].founded);
	cout << "--> stadium: "; getline(cin, team_detail[str].ground);
	cout << "--> capacity: "; getline(cin, team_detail[str].capacity);
	cout << "\n" << "Player detail(s)" << "\n\n";
	add_player(1, str);
	cout << "\n" << "Title(s)" << "\n\n";
	cout << "--> league titles: "; cin >> team_detail[str].league;
	cout << "--> cup titles: "; cin >> team_detail[str].cup;

	if (system("CLS")) { system("clear"); }
}

void display_team()
{
	cout << "Team detail(s)" << "\n\n";
	string str; cout << "--> name: "; getline(cin, str);

	cout << "--> nickname: " << team_detail[str].nickname << "\n";
	cout << "--> coach: " << team_detail[str].coach << "\n";
	cout << "--> date founded: " << team_detail[str].founded << "\n";
	cout << "--> stadium: " << team_detail[str].ground << "\n";
	cout << "--> capacity: " << team_detail[str].capacity << "\n";
	cout << "\n" << "Player detail(s)" << "\n\n";
	display_player(1, str);
	cout << "\n" << "Title(s)" << "\n\n";
	cout << "--> league titles: " << team_detail[str].league << "\n";
	cout << "--> cup titles: " << team_detail[str].cup << "\n";
}

void delete_team()
{
	string str; cout << "enter team: "; getline(cin, str);

	team_detail.erase(str);

	cout << "TEAM REMOVED" << "\n";
}

void read_team()
{
	ifstream read_team;
	read_team.open("Team.txt");

	if (read_team.is_open())
	{
		int num;
		string str;

		getline(read_team, str);
		num = stoi(str);

		for (int i = 0; i < num; i++)
		{
			getline(read_team, str);
			getline(read_team, team_detail[str].nickname);
			getline(read_team, team_detail[str].coach);
			getline(read_team, team_detail[str].founded);
			getline(read_team, team_detail[str].ground);
			getline(read_team, team_detail[str].capacity);

			int plrNum;
			string plrStr;

			getline(read_team, plrStr);
			int num2 = stoi(plrStr);

			for (int j = 0; j < num2; j++)
			{
				getline(read_team, plrStr);
				plrNum = stoi(plrStr);

				getline(read_team, team_detail[str].player_detail[plrNum].name);
				getline(read_team, team_detail[str].player_detail[plrNum].position);
				getline(read_team, team_detail[str].player_detail[plrNum].IN);
				getline(read_team, team_detail[str].player_detail[plrNum].OUT);

				getline(read_team, plrStr);
				team_detail[str].player_detail[plrNum].games = stoi(plrStr);

				getline(read_team, plrStr);
				team_detail[str].player_detail[plrNum].goals = stoi(plrStr);

				getline(read_team, plrStr);
				team_detail[str].player_detail[plrNum].assist = stoi(plrStr);

				getline(read_team, plrStr);
				team_detail[str].player_detail[plrNum].yellow = stoi(plrStr);

				getline(read_team, plrStr);
				team_detail[str].player_detail[plrNum].red = stoi(plrStr);
			}

			getline(read_team, plrStr);
			team_detail[str].league = stoi(plrStr);

			getline(read_team, plrStr);
			team_detail[str].cup = stoi(plrStr);
		}
	}

	read_team.close();
}

void write_team()
{
	ofstream write_team;
	write_team.open("Team.txt");

	int counter = 0;

	for (tm = team_detail.begin(); tm != team_detail.end(); tm++)
	{
		counter++;
	}

	write_team << counter << endl;

	for (tm = team_detail.begin(); tm != team_detail.end(); tm++)
	{
		write_team << tm->first << endl;
		write_team << tm->second.nickname << endl;
		write_team << tm->second.coach << endl;
		write_team << tm->second.founded << endl;
		write_team << tm->second.ground << endl;
		write_team << tm->second.capacity << endl;

		counter = 0;

		for (tm->second.pd = tm->second.player_detail.begin(); tm->second.pd != tm->second.player_detail.end(); tm->second.pd++)
		{
			counter++;
		}

		write_team << counter << endl;

		for (tm->second.pd = tm->second.player_detail.begin(); tm->second.pd != tm->second.player_detail.end(); tm->second.pd++)
		{
			write_team << tm->second.pd->first << endl;
			write_team << tm->second.pd->second.name << endl;
			write_team << tm->second.pd->second.position << endl;
			write_team << tm->second.pd->second.IN << endl;
			write_team << tm->second.pd->second.OUT << endl;
			write_team << tm->second.pd->second.games << endl;
			write_team << tm->second.pd->second.goals << endl;
			write_team << tm->second.pd->second.assist << endl;
			write_team << tm->second.pd->second.yellow << endl;
			write_team << tm->second.pd->second.red << endl;
		}

		write_team << tm->second.league << endl;
		write_team << tm->second.cup << endl;
	}

	write_team.close();
}

void search()
{
	if (system("CLS")) { system("clear"); }

	int counter = 0;

	while (true)
	{
		if (counter == 0)
		{
			cout << "1 - Display player" << "\n";
			cout << "2 - Display team" << "\n";
			cout << "3 - Return" << "\n";
		}

		cout << "\n";

		int choose; cout << "Choose operation: "; cin >> choose;

		cout << "\n"; cin.ignore();

		if (choose == 1) { display_player(0, ""); }

		else if (choose == 2) { display_team(); }

		else if (choose == 3) { break; }

		else
		{
			counter++;

			if (counter == 3) { cout << "TIME OUT" << "\n\n"; break; }

			else { cout << "Wrong choice, try again" << "\n"; }
		}
	}

	if (system("CLS")) { system("clear"); }
}

void add_match(int number, int i)
{
	cout << "\n-------------------------------------\n\n";
	cout << "Match (" << i + 1 << ")\n\n";

	int chck;

	cin.ignore();
	for (int dodo = 0; dodo < 3; dodo++)
	{
		cout << "--> Team 1: ";
		getline(cin, week[number].match[i].Team_1);
		for (tm = team_detail.begin(); tm != team_detail.end(); tm++)
		{
			if (tm->first == week[number].match[i].Team_1)
			{
				chck = 1;
				break;
			}

			else
			{
				chck = 0;
			}
		}

		if (chck == 0 && dodo < 2)
		{
			cout << "No team found, try again" << "\n\n";
		}

		else if (chck == 0)
		{
			cout << "TIME OUT" << "\n\n";
		}

		else
		{
			break;
		}
	}

	if (chck == 1)
	{
		cout << "  --> # Goals: ";
		cin >> week[number].match[i].Goals_1;
		week[number].match[i].score_1 = new string[week[number].match[i].Goals_1];
		cin.ignore();
		for (int j = 0; j < week[number].match[i].Goals_1; j++)
		{
			cout << "    --> goal " << j + 1 << " scorer: ";
			getline(cin, week[number].match[i].score_1[j]);
		}
		cout << "  --> # Assists: ";
		cin >> week[number].match[i].Assist_1;
		week[number].match[i].make_1 = new string[week[number].match[i].Assist_1];
		cin.ignore();
		for (int y = 0; y < week[number].match[i].Assist_1; y++)
		{
			cout << "    --> assist " << y + 1 << " maker: ";
			getline(cin, week[number].match[i].make_1[y]);
		}
		cout << "  --> # Yellow Cards: ";
		cin >> week[number].match[i].Y_Cards_1;
		week[number].match[i].Yellow_1 = new string[week[number].match[i].Y_Cards_1];
		cin.ignore();
		for (int y = 0; y < week[number].match[i].Y_Cards_1; y++)
		{

			cout << "    --> card " << y + 1 << ": ";
			getline(cin, week[number].match[i].Yellow_1[y]);
		}
		cout << "  --> # Red Cards: ";
		cin >> week[number].match[i].R_Cards_1;
		week[number].match[i].Red_1 = new string[week[number].match[i].R_Cards_1];
		cin.ignore();
		for (int y = 0; y < week[number].match[i].R_Cards_1; y++)
		{
			cout << "    --> card " << y + 1 << ": ";
			getline(cin, week[number].match[i].Red_1[y]);
		}

		for (int dodo = 0; dodo < 3; dodo++)
		{
			cout << "--> Team 2: ";
			getline(cin, week[number].match[i].Team_2);
			for (tm = team_detail.begin(); tm != team_detail.end(); tm++)
			{
				if (tm->first == week[number].match[i].Team_2)
				{
					chck = 1;
					break;
				}

				else
				{
					chck = 0;
				}
			}

			if (chck == 0 && dodo < 2)
			{
				cout << "No team found, try again" << "\n\n";
			}

			else if (chck == 0)
			{
				cout << "TIME OUT" << "\n\n";
			}
			else
			{
				break;
			}
		}
		if (chck == 1)
		{
			cout << "  --> # Goals: ";
			cin >> week[number].match[i].Goals_2;
			week[number].match[i].score_2 = new string[week[number].match[i].Goals_2];
			cin.ignore();
			for (int j = 0; j < week[number].match[i].Goals_2; j++)
			{
				cout << "    --> goal " << j + 1 << " scorer: ";
				getline(cin, week[number].match[i].score_2[j]);
			}
			cout << "  --> # Assists: ";
			cin >> week[number].match[i].Assist_2;
			week[number].match[i].make_2 = new string[week[number].match[i].Assist_2];
			cin.ignore();
			for (int y = 0; y < week[number].match[i].Assist_2; y++)
			{
				cout << "    --> assist " << y + 1 << " maker: ";
				getline(cin, week[number].match[i].make_2[y]);
			}
			cout << "  --> # Yellow Cards: ";
			cin >> week[number].match[i].Y_Cards_2;
			week[number].match[i].Yellow_2 = new string[week[number].match[i].Y_Cards_2];
			cin.ignore();
			for (int y = 0; y < week[number].match[i].Y_Cards_2; y++)
			{

				cout << "    --> card " << y + 1 << ": ";
				getline(cin, week[number].match[i].Yellow_2[y]);
			}
			cout << "  --> # Red Cards: ";
			cin >> week[number].match[i].R_Cards_2;
			week[number].match[i].Red_2 = new string[week[number].match[i].R_Cards_2];
			cin.ignore();
			for (int y = 0; y < week[number].match[i].R_Cards_2; y++)
			{
				cout << "    --> card " << y + 1 << ": ";
				getline(cin, week[number].match[i].Red_2[y]);
			}
		}
	}
}

void add_cup_Ouartetfinal(int number, int i)
{
	cin.ignore();
	cout << "--> Team 1: ";
	getline(cin, week[number].cup_Quarterfinal[i].Team_1);
	cout << "  --> # Goals: ";
	cin >> week[number].cup_Quarterfinal[i].Goals_1;
	week[number].cup_Quarterfinal[i].score_1 = new string[week[number].cup_Quarterfinal[i].Goals_1];
	cin.ignore();
	for (int j = 0; j < week[number].cup_Quarterfinal[i].Goals_1; j++)
	{
		cout << "    --> goal " << j + 1 << " scorer: ";
		getline(cin, week[number].cup_Quarterfinal[i].score_1[j]);
	}
	cout << "  --> # Assists: ";
	cin >> week[number].cup_Quarterfinal[i].Assist_1;
	week[number].cup_Quarterfinal[i].make_1 = new string[week[number].cup_Quarterfinal[i].Assist_1];
	cin.ignore();
	for (int y = 0; y < week[number].cup_Quarterfinal[i].Assist_1; y++)
	{
		cout << "    --> assist " << y + 1 << " maker: ";
		getline(cin, week[number].cup_Quarterfinal[i].make_1[y]);
	}
	cout << "  --> # Yellow Cards: ";
	cin >> week[number].cup_Quarterfinal[i].Y_Cards_1;
	week[number].cup_Quarterfinal[i].Yellow_1 = new string[week[number].cup_Quarterfinal[i].Y_Cards_1];
	cin.ignore();
	for (int y = 0; y < week[number].cup_Quarterfinal[i].Y_Cards_1; y++)
	{

		cout << "    --> card " << y + 1 << ": ";
		getline(cin, week[number].cup_Quarterfinal[i].Yellow_1[y]);
	}
	cout << "  --> # Red Cards: ";
	cin >> week[number].cup_Quarterfinal[i].R_Cards_1;
	week[number].cup_Quarterfinal[i].Red_1 = new string[week[number].cup_Quarterfinal[i].R_Cards_1];
	cin.ignore();
	for (int y = 0; y < week[number].cup_Quarterfinal[i].R_Cards_1; y++)
	{
		cout << "    --> card " << y + 1 << ": ";
		getline(cin, week[number].cup_Quarterfinal[i].Red_1[y]);
	}
	cout << "\n--> Team 2: ";
	getline(cin, week[number].cup_Quarterfinal[i].Team_2);
	cout << "  --> # Goals: ";
	cin >> week[number].cup_Quarterfinal[i].Goals_2;
	week[number].cup_Quarterfinal[i].score_2 = new string[week[number].cup_Quarterfinal[i].Goals_2];
	cin.ignore();
	for (int j = 0; j < week[number].cup_Quarterfinal[i].Goals_2; j++)
	{
		cout << "    --> goal " << j + 1 << " scorer: ";
		getline(cin, week[number].cup_Quarterfinal[i].score_2[j]);
	}
	cout << "  --> # Assists: ";
	cin >> week[number].cup_Quarterfinal[i].Assist_2;
	week[number].cup_Quarterfinal[i].make_2 = new string[week[number].cup_Quarterfinal[i].Assist_2];
	cin.ignore();
	for (int y = 0; y < week[number].cup_Quarterfinal[i].Assist_2; y++)
	{
		cout << "    --> assist " << y + 1 << " maker: ";
		getline(cin, week[number].cup_Quarterfinal[i].make_2[y]);
	}
	cout << "  --> # Yellow Cards: ";
	cin >> week[number].cup_Quarterfinal[i].Y_Cards_2;
	week[number].cup_Quarterfinal[i].Yellow_2 = new string[week[number].cup_Quarterfinal[i].Y_Cards_2];
	cin.ignore();
	for (int y = 0; y < week[number].cup_Quarterfinal[i].Y_Cards_2; y++)
	{

		cout << "    --> card " << y + 1 << ": ";
		getline(cin, week[number].cup_Quarterfinal[i].Yellow_2[y]);
	}
	cout << "  --> # Red Cards: ";
	cin >> week[number].cup_Quarterfinal[i].R_Cards_2;
	week[number].cup_Quarterfinal[i].Red_2 = new string[week[number].cup_Quarterfinal[i].R_Cards_2];
	cin.ignore();
	for (int y = 0; y < week[number].cup_Quarterfinal[i].R_Cards_2; y++)
	{
		cout << "    --> card " << y + 1 << ": ";
		getline(cin, week[number].cup_Quarterfinal[i].Red_2[y]);

	}

	cout << "\n-------------------------------------\n\n";
}

void add_cup_semifinal(int number, int i)
{
	cin.ignore();

	cout << "--> Team 1: ";
	getline(cin, week[number].cup_semifinal[i].Team_1);
	cout << "  --> # Goals: ";
	cin >> week[number].cup_semifinal[i].Goals_1;
	week[number].cup_semifinal[i].score_1 = new string[week[number].cup_semifinal[i].Goals_1];
	cin.ignore();
	for (int j = 0; j < week[number].cup_semifinal[i].Goals_1; j++)
	{
		cout << "    --> goal " << j + 1 << " scorer: ";
		getline(cin, week[number].cup_semifinal[i].score_1[j]);
	}
	cout << "  --> # Assists: ";
	cin >> week[number].cup_semifinal[i].Assist_1;
	week[number].cup_semifinal[i].make_1 = new string[week[number].cup_semifinal[i].Assist_1];
	cin.ignore();
	for (int y = 0; y < week[number].cup_semifinal[i].Assist_1; y++)
	{
		cout << "    --> assist " << y + 1 << " maker: ";
		getline(cin, week[number].cup_semifinal[i].make_1[y]);
	}
	cout << "  --> # Yellow Cards: ";
	cin >> week[number].cup_semifinal[i].Y_Cards_1;
	week[number].cup_semifinal[i].Yellow_1 = new string[week[number].cup_semifinal[i].Y_Cards_1];
	cin.ignore();
	for (int y = 0; y < week[number].cup_semifinal[i].Y_Cards_1; y++)
	{

		cout << "    --> card " << y + 1 << ": ";
		getline(cin, week[number].cup_semifinal[i].Yellow_1[y]);
	}
	cout << "  --> # Red Cards: ";
	cin >> week[number].cup_semifinal[i].R_Cards_1;
	week[number].cup_semifinal[i].Red_1 = new string[week[number].cup_semifinal[i].R_Cards_1];
	cin.ignore();
	for (int y = 0; y < week[number].cup_semifinal[i].R_Cards_1; y++)
	{
		cout << "    --> card " << y + 1 << ": ";
		getline(cin, week[number].cup_semifinal[i].Red_1[y]);
	}
	cout << "\n--> Team 2: ";
	getline(cin, week[number].cup_semifinal[i].Team_2);
	cout << "  --> # Goals: ";
	cin >> week[number].cup_semifinal[i].Goals_2;
	week[number].cup_semifinal[i].score_2 = new string[week[number].cup_semifinal[i].Goals_2];
	cin.ignore();
	for (int j = 0; j < week[number].cup_semifinal[i].Goals_2; j++)
	{
		cout << "    --> goal " << j + 1 << " scorer: ";
		getline(cin, week[number].cup_semifinal[i].score_2[j]);
	}
	cout << "  --> # Assists: ";
	cin >> week[number].cup_semifinal[i].Assist_2;
	week[number].cup_semifinal[i].make_2 = new string[week[number].cup_semifinal[i].Assist_2];
	cin.ignore();
	for (int y = 0; y < week[number].cup_semifinal[i].Assist_2; y++)
	{
		cout << "    --> assist " << y + 1 << " maker: ";
		getline(cin, week[number].cup_semifinal[i].make_2[y]);
	}
	cout << "  --> # Yellow Cards: ";
	cin >> week[number].cup_semifinal[i].Y_Cards_2;
	week[number].cup_semifinal[i].Yellow_2 = new string[week[number].cup_semifinal[i].Y_Cards_2];
	cin.ignore();
	for (int y = 0; y < week[number].cup_semifinal[i].Y_Cards_2; y++)
	{

		cout << "    --> card " << y + 1 << ": ";
		getline(cin, week[number].cup_semifinal[i].Yellow_2[y]);
	}
	cout << "  --> # Red Cards: ";
	cin >> week[number].cup_semifinal[i].R_Cards_2;
	week[number].cup_semifinal[i].Red_2 = new string[week[number].cup_semifinal[i].R_Cards_2];
	cin.ignore();
	for (int y = 0; y < week[number].cup_semifinal[i].R_Cards_2; y++)
	{
		cout << "    --> card " << y + 1 << ": ";
		getline(cin, week[number].cup_semifinal[i].Red_2[y]);
	}

	cout << "\n-------------------------------------\n\n";
}

void add_cup_final(int number, int i)
{
	cin.ignore();
	cout << "--> Team 1: ";
	getline(cin, week[number].cup_final[i].Team_1);
	cout << "  --> # Goals: ";
	cin >> week[number].cup_final[i].Goals_1;
	week[number].cup_final[i].score_1 = new string[week[number].cup_final[i].Goals_1];
	cin.ignore();
	for (int j = 0; j < week[number].cup_final[i].Goals_1; j++)
	{
		cout << "    --> goal " << j + 1 << " scorer: ";
		getline(cin, week[number].cup_final[i].score_1[j]);
	}
	cout << "  --> # Assists: ";
	cin >> week[number].cup_final[i].Assist_1;
	week[number].cup_final[i].make_1 = new string[week[number].cup_final[i].Assist_1];
	cin.ignore();
	for (int y = 0; y < week[number].cup_final[i].Assist_1; y++)
	{
		cout << "    --> assist " << y + 1 << " maker: ";
		getline(cin, week[number].cup_final[i].make_1[y]);
	}
	cout << "  --> # Yellow Cards: ";
	cin >> week[number].cup_final[i].Y_Cards_1;
	week[number].cup_final[i].Yellow_1 = new string[week[number].cup_final[i].Y_Cards_1];
	cin.ignore();
	for (int y = 0; y < week[number].cup_final[i].Y_Cards_1; y++)
	{

		cout << "    --> card " << y + 1 << ": ";
		getline(cin, week[number].cup_final[i].Yellow_1[y]);
	}
	cout << "  --> # Red Cards: ";
	cin >> week[number].cup_final[i].R_Cards_1;
	week[number].cup_final[i].Red_1 = new string[week[number].cup_final[i].R_Cards_1];
	cin.ignore();
	for (int y = 0; y < week[number].cup_final[i].R_Cards_1; y++)
	{
		cout << "    --> card " << y + 1 << ": ";
		getline(cin, week[number].cup_final[i].Red_1[y]);
	}
	cout << "\n--> Team 2: ";
	getline(cin, week[number].cup_final[i].Team_2);
	cout << "  --> # Goals: ";
	cin >> week[number].cup_final[i].Goals_2;
	week[number].cup_final[i].score_2 = new string[week[number].cup_final[i].Goals_2];
	cin.ignore();
	for (int j = 0; j < week[number].cup_final[i].Goals_2; j++)
	{
		cout << "    --> goal " << j + 1 << " scorer: ";
		getline(cin, week[number].cup_final[i].score_2[j]);
	}
	cout << "  --> # Assists: ";
	cin >> week[number].cup_final[i].Assist_2;
	week[number].cup_final[i].make_2 = new string[week[number].cup_final[i].Assist_2];
	cin.ignore();
	for (int y = 0; y < week[number].cup_final[i].Assist_2; y++)
	{
		cout << "    --> assist " << y + 1 << " maker: ";
		getline(cin, week[number].cup_final[i].make_2[y]);
	}
	cout << "  --> # Yellow Cards: ";
	cin >> week[number].cup_final[i].Y_Cards_2;
	week[number].cup_final[i].Yellow_2 = new string[week[number].cup_final[i].Y_Cards_2];
	cin.ignore();
	for (int y = 0; y < week[number].cup_final[i].Y_Cards_2; y++)
	{

		cout << "    --> card " << y + 1 << ": ";
		getline(cin, week[number].cup_final[i].Yellow_2[y]);
	}
	cout << "  --> # Red Cards: ";
	cin >> week[number].cup_final[i].R_Cards_2;
	week[number].cup_final[i].Red_2 = new string[week[number].cup_final[i].R_Cards_2];
	cin.ignore();
	for (int y = 0; y < week[number].cup_final[i].R_Cards_2; y++)
	{
		cout << "    --> card " << y + 1 << ": ";
		getline(cin, week[number].cup_final[i].Red_2[y]);
	}

	cout << "\n-------------------------------------\n\n";
}

void add_week()
{
	int number;
	cout << "enter week no.: ";
	cin >> number;
	cin.ignore();
	for (int i = 0; i < 4; i++)
	{
		add_match(number, i);
	}
}

void show_week()
{
	int number;
	cout << "enter week no.: ";
	cin >> number;
	for (int i = 0; i < 4; i++)
	{
		cout << "\n-------------------------------------\n\n";
		cout << "Match (" << i + 1 << ")\n\n";
		cout << "--> Team 1: " << week[number].match[i].Team_1 << "\n";
		cout << "  --> # Goals: " << week[number].match[i].Goals_1 << "\n";
		for (int j = 0; j < week[number].match[i].Goals_1; j++)
		{
			cout << "    --> goal " << j + 1 << " scorer: " << week[number].match[i].score_1[j] << "\n";
		}
		cout << "  --> # Assists: " << week[number].match[i].Assist_1 << "\n";
		for (int y = 0; y < week[number].match[i].Assist_1; y++)
		{
			cout << "    --> assist " << y + 1 << " maker: " << week[number].match[i].make_1[y] << "\n";
		}
		cout << "  --> # Yellow Cards: " << week[number].match[i].Y_Cards_1 << "\n";

		for (int y = 0; y < week[number].match[i].Y_Cards_1; y++)
		{

			cout << "    --> card " << y + 1 << ": " << week[number].match[i].Yellow_1[y] << "\n";
		}
		cout << "  --> # Red Cards: " << week[number].match[i].R_Cards_1 << "\n";

		for (int y = 0; y < week[number].match[i].R_Cards_1; y++)
		{
			cout << "    --> card " << y + 1 << ": " << week[number].match[i].Red_1[y] << "\n";
		}
		cout << "--> Team 2: " << week[number].match[i].Team_2 << "\n";
		cout << "  --> # Goals: " << week[number].match[i].Goals_2 << "\n";
		for (int j = 0; j < week[number].match[i].Goals_2; j++)
		{
			cout << "    --> goal " << j + 1 << " scorer: " << week[number].match[i].score_2[j] << "\n";
		}
		cout << "  --> # Assists: " << week[number].match[i].Assist_2 << "\n";
		for (int y = 0; y < week[number].match[i].Assist_2; y++)
		{
			cout << "    --> assist " << y + 1 << " maker: " << week[number].match[i].make_2[y] << "\n";
		}
		cout << "  --> # Yellow Cards: " << week[number].match[i].Y_Cards_2 << "\n";

		for (int y = 0; y < week[number].match[i].Y_Cards_2; y++)
		{

			cout << "    --> card " << y + 1 << ": " << week[number].match[i].Yellow_2[y] << "\n";
		}
		cout << "  --> # Red Cards: " << week[number].match[i].R_Cards_2 << "\n";

		for (int y = 0; y < week[number].match[i].R_Cards_2; y++)
		{
			cout << "    --> card " << y + 1 << ": " << week[number].match[i].Red_2[y] << "\n";
		}
	}
}

void weekFun()
{
	if (system("CLS")) { system("clear"); }

	int counter = 0;

	while (true)
	{
		if (counter == 0)
		{
			cout << "1 - Add a week" << "\n";
			cout << "2 - Show week" << "\n";
			cout << "3 - Add match" << "\n";
			cout << "4 - Add cup quarter-final" << "\n";
			cout << "5 - Add cup semi-final" << "\n";
			cout << "6 - Add cup final" << "\n";
			cout << "7 - return" << "\n";
		}

		cout << "\n";

		int choose; cout << "Choose operation: "; cin >> choose;

		cout << "\n"; cin.ignore();

		if (choose == 1) { add_week(); }

		else if (choose == 2) { show_week(); }

		else if (choose == 3)
		{
			cout << "enter week number: ";
			int x; cin >> x;
			cout << "enter match number:";
			int i; cin >> i;
			add_match(x, i - 1);
		}

		else if (choose == 4)
		{
			cout << "enter week number: ";
			int x; cin >> x;
			for (int m = 0; m < 4; m++)
			{
				cout << "Match(" << m + 1 << ") :" << "\n";
				add_cup_Ouartetfinal(x, m);
			}
		}

		else if (choose == 5)
		{
			cout << "enter week number: ";
			int x; cin >> x;
			for (int m = 4; m < 6; m++)
			{
				cout << "Match(" << m + 1 << ") :" << "\n";
				add_cup_semifinal(x, m);
			}
		}

		else if (choose == 6)
		{
			cout << "enter week number: ";
			int x; cin >> x;
			cout << "Match(7) :" << "\n";
			add_cup_final(x, 6);
		}

		else if (choose == 7) { break; }

		else
		{
			counter++;

			if (counter == 3) { cout << "TIME OUT" << "\n\n"; break; }

			else { cout << "Wrong choice, try again" << "\n"; }
		}

		autoSave();
	}

	if (system("CLS")) { system("clear"); }
}

void stand()
{
	if (system("CLS")) { system("clear"); }

	int counter = 0;

	while (true)
	{
		if (counter == 0)
		{
			cout << "1 - League" << "\n";
			cout << "2 - Goals" << "\n";
			cout << "3 - Assists" << "\n";
			cout << "4 - Cards" << "\n";
			cout << "5 - return" << "\n";
		}

		cout << "\n";

		int choose; cout << "Choose operation: "; cin >> choose;

		cout << "\n"; cin.ignore();

		if (choose == 1) { stnd(); }

		else if (choose == 2) { goals(); }

		else if (choose == 3) { asists(); }

		else if (choose == 4){ cards(); }

		else if (choose == 5) { break; }

		else
		{
			counter++;

			if (counter == 3) { cout << "TIME OUT" << "\n\n"; break; }

			else { cout << "Wrong choice, try again" << "\n"; }
		}

		autoSave();
	}

	if (system("CLS")) { system("clear"); }
}

void goals()
{
	while (true)
	{
		int y;
		int q;


		cout << "enter the number of y" << "\n";
		cin >> y;
		if (y == -1)
		{
			break;
		}
		else
		{
			int z;
			cout << "enter the size of the string" << "\n";
			cin >> z;
			cout << "enter the key"<<"\n";
			cin >> q;
			string *arr = new string[z];
			string  x;
			list <string>l;
			cout << "enter the elements of the list" << "\n";
			for (int i = 0; i < z; i++)
			{
				cout << "  " << "_ > enter the " << i + 1 << "  " << "element" << "\n";
				cin >> x;
				l.push_back(x);
			}
			cout << "*******************************" << "\n";
			cout << q << endl;
			list<string>::iterator it;
			for (it = l.begin(); it != l.end(); it++){
				for (int i = 0; i < 1; i++){
					arr[i] = *it;


					map<int, string> ds;
					
                      ds[q] = arr[i];
                      map<int, string>::iterator it;	 
					  for (it = ds.begin(); it != ds.end(); it++)
					  cout << "\t" << it->second << "\n";

				}
			}
		}
	}


}

void asists()
{
	while (true)
	{
		int y;
		int q;


		cout << "enter the number of y" << "\n";
		cin >> y;
		if (y == -1)
		{
			break;
		}
		else
		{
			int z;
			cout << "enter the size of the string" << "\n";
			cin >> z;
			cout << "enter the key"<<"\n";
			cin >> q;
			string *arr = new string[z];
			string  x;
			list <string>l;
			cout << "enter the elements of the list" << "\n";
			for (int i = 0; i < z; i++)
			{
				cout << "  " << "_ > enter the " << i + 1 << "  " << "element" << "\n";
				cin >> x;
				l.push_back(x);
			}
			cout << "*******************************" << "\n";
			cout << q << endl;
			list<string>::iterator it;
			for (it = l.begin(); it != l.end(); it++){
				for (int i = 0; i < 1; i++){
					arr[i] = *it;


					map<int, string> ds;
					
                      ds[q] = arr[i];
                      map<int, string>::iterator it;	 
					  for (it = ds.begin(); it != ds.end(); it++)
					  cout << "\t" << it->second << "\n";

				}
			}
		}
	}
}

void cards()
{
	while (true)
	{
		int y;
		int q;


		cout << "enter the number of y" << "\n";
		cin >> y;
		if (y == -1)
		{
			break;
		}
		else
		{
			int z;
			cout << "enter the size of the string" << "\n";
			cin >> z;
			cout << "enter the key"<<"\n";
				cin >> q;
			string *arr = new string[z];
			string  x;
			list <string>l;
			cout << "enter the elements of the list" << "\n";
			for (int i = 0; i < z; i++)
			{
				cout << "  " << "_ > enter the " << i + 1 << "  " << "element" << "\n";
				cin >> x;
				l.push_back(x);
			}
			cout << "*******************************" << "\n";
			cout << q << endl;
			list<string>::iterator it;
			for (it = l.begin(); it != l.end(); it++){
				for (int i = 0; i < 1; i++){
					arr[i] = *it;


					map<int, string> ds;

					ds[q] = arr[i];
					map<int, string>::iterator it;
					for (it = ds.begin(); it != ds.end(); it++)
						cout << "\t" << it->second << "\n";

				}
			}
		}
	}
}

void tranzf()
{
	if (system("CLS")) { system("clear"); }

	int counter = 0;

	while (true)
	{
		if (counter == 0)
		{
			cout << "1 - Transfer a player" << "\n";
			cout << "2 - Show Transfer" << "\n";
			cout << "3 - return" << "\n";
		}

		cout << "\n";

		int choose; cout << "Choose operation: "; cin >> choose;

		cout << "\n"; cin.ignore();

		transfer <int>t;
		transfer <string> t1;

		if (choose == 1)
		{
			int z;
			cout << "Ener the  number of players" << "\n";

			cin >> z;
			cin.ignore();
			string q;
			for (int i = 0; i < z; i++){
				cout << "Enter the deatiels of the players" << i + 1 << endl;

				getline(cin, q);
				t1.push(q);
				getline(cin, q);
				t1.push(q);
				getline(cin, q);
				t1.push(q);
				getline(cin, q);
				t1.push(q);
			}
		}

		else if (choose == 2)
		{
			while (!t1.Empty())
			{
				cout << "the player detail:" << t1.top() << endl;
				t1.pop();
			}
		}

		else if (choose == 3) { break; }

		else
		{
			counter++;

			if (counter == 3) { cout << "TIME OUT" << "\n\n"; break; }

			else { cout << "Wrong choice, try again" << "\n"; }
		}

		autoSave();
	}

	if (system("CLS")) { system("clear"); }
}

void stnd()
{
	if (system("CLS"))
	{
		system("clear");
	}

	int counter = 0;

	while (true)
	{
		if (counter == 0)
		{
			cout << "1 - Edit standing" << "\n";
			cout << "2 - Show standing" << "\n";
			cout << "3 - return" << "\n";
		}

		cout << "\n";

		int choose; cout << "Choose operation: "; cin >> choose;

		cout << "\n"; cin.ignore();

		if (choose == 1) { add_stnd(); }

		else if (choose == 2) { show_stnd(); }

		else if (choose == 3) { break; }

		else
		{
			counter++;

			if (counter == 3)
			{
				cout << "TIME OUT" << "\n\n";
				break;
			}

			else { cout << "Wrong choice, try again" << "\n"; }
		}
	}

	if (system("CLS"))
	{
		system("clear");
	}
}

void add_stnd()
{
	for (int i = 0; i < 8; i++)
	{
		cout << "# : " << i + 1 << "\n";
		cout << "Team: "; getline(cin, stn[i].name);
		cout << "Win: "; getline(cin, stn[i].win);
		cout << "Draw: "; getline(cin, stn[i].draw);
		cout << "Loss: "; getline(cin, stn[i].lose);
		cout << "goals forward: "; getline(cin, stn[i].frw);
		cout << "goals againest: "; getline(cin, stn[i].agn);
		cout << "Points: "; getline(cin, stn[i].pts);
	}
}

void show_stnd()
{
	cout << "# : " << "\t";
	cout << "Team: " << "\t";
	cout << "Win: " << "\t";
	cout << "Draw: " << "\t";
	cout << "Loss: " << "\t";
	cout << "goals forward: " << "\t";
	cout << "goals againest: " << "\t";
	cout << "Points: " << "\t";

	for (int i = 0; i < 8; i++)
	{
		cout << i + 1 << "\t";
		cout << stn[i].name << "\t";
		cout << stn[i].win << "\t";
		cout << stn[i].draw << "\t";
		cout << stn[i].lose << "\t";
		cout << stn[i].frw << "\t";
		cout << stn[i].agn << "\t";
		cout << stn[i].pts << "\t";
	}
}

void read_stnd()
{
	ifstream read;
	read.open("Standing.txt");

	if (read.is_open())
	{
		for (int i = 0; i < 8; i++)
		{
			getline(read, stn[i].name);
			getline(read, stn[i].win);
			getline(read, stn[i].draw);
			getline(read, stn[i].lose);
			getline(read, stn[i].frw);
			getline(read, stn[i].agn);
			getline(read, stn[i].pts);
		}
	}

	read.close();
}

void write_stnd()
{
	ofstream write;
	write.open("Standing.txt");

	for (int i = 0; i < 8; i++)
	{
		write << stn[i].name << "\t";
		write << stn[i].win << "\t";
		write << stn[i].draw << "\t";
		write << stn[i].lose << "\t";
		write << stn[i].frw << "\t";
		write << stn[i].agn << "\t";
		write << stn[i].pts << "\t";
	}

	write.close();
}

void enterEnd()
{
	cin.ignore();

	cout << "champion: "; getline(cin, rs.chmp);
	cout << "runner up: "; getline(cin, rs.rnu);
	cout << "top goal sccorer: "; getline(cin, rs.topG);
	cout << "top assist maker: "; getline(cin, rs.topA);
	cout << "best player: "; getline(cin, rs.bestP);
	cout << "best coach: "; getline(cin, rs.bestC);

	for (int i = 0; i < 3; i++)
	{
		cout << "regulated team #" << i + 1 << ": "; getline(cin, rs.reg[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "promoted team #" << i + 1 << ": "; getline(cin, rs.prm[i]);
	}

	laa3ref = 1;
}

void showEnd()
{
	cout << "champion: " << rs.chmp << "\n";
	cout << "runner up: " << rs.rnu << "\n";
	cout << "top goal sccorer: " << rs.topG << "\n";
	cout << "top assist maker: " << rs.topA << "\n";
	cout << "best player: " << rs.bestP << "\n";
	cout << "best coach: " << rs.bestC << "\n";

	for (int i = 0; i < 3; i++)
	{
		cout << "regulated team #" << i + 1 << ": " << rs.reg[i] << "\n";
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "promoted team #" << i + 1 << ": " << rs.prm[i] << "\n";
	}

	int cn; cout << "to continue press any key: "; cin >> cn;
}
