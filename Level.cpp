#include <fstream>
#include <iostream>
#include <conio.h>

#include "Player.h"
#include "Recruit.h"
#include "Corporal.h"
#include "Major.h"
#include "General.h"
#include "Level.h"
#include "Interface.h" 
#include "Menu.h"

using namespace std;

Level::Level(bool startingEnd) {
	end = startingEnd;
}

Level::~Level() {}

void Level::pause()
{
	cout << endl << " Tastati orice buton pentru a continua...";
	while (!_kbhit()) {}
	_getch();
}

void Level::setPlayerName(string& playerName, Player& player) {
	cout << endl << " Text Mode Game | Zombie Assault" << endl;
	cout << endl << " My players name is: ";
	cin >> playerName;
	player.name = playerName;
}

void Level::save(Enemy& enemy, Player& player) {
	ofstream outputFile("savegame.txt");

	if (outputFile.is_open()) {

		outputFile << enemy.name << endl;

		outputFile << player.name << endl;
		outputFile << player.health << endl;
		outputFile << player.damage << endl;
		outputFile << player.armor << endl;
		outputFile << player.firstAidKits << endl;

		outputFile.close();
		cout << endl << " Jocul a fost salvat cu succes." << endl;
	}
}

void Level::load(Enemy& enemy, Player& player) {
	ifstream inputFile("savegame.txt");

	if (inputFile.is_open()) {

		inputFile >> enemy.name;

		inputFile >> player.name;
		inputFile >> player.health;
		inputFile >> player.damage;
		inputFile >> player.armor;
		inputFile >> player.firstAidKits;

		inputFile.close();
	}
}

void Level::story(Enemy& enemy, Player& player) {
	cout << endl << " Text Mode Game | Zombie Assault" << endl << endl;
	if (enemy.name == "Recruit")
	{
		cout << " Te trezesti intr-un spital militar, fara nicio amintire despre cum ai ajuns acolo." << endl;
		cout << " In momentul in care iti revii, constati ca baza militara a fost infectata de un virus necunoscut," << endl;
		cout << " transformand toti militarii in zombie." << endl;
		cout << " Esti un militar de rang inferior si esti hotarat sa supravietuiesti si sa dezvalui misterul" << endl;
		cout << " din spatele acestei infectii." << endl;
		cout << " Singur si cu resursele limitate, incepi cautarea unei arme pentru a-ti proteja viata." << endl;
	}
	else if (enemy.name == "Corporal")
	{
		cout << " Iesi din spitalul militar si intri in teritoriul bazei militare." << endl;
		cout << " Zombie-militarii de ranguri superioare iti ies in cale, reprezentand o provocare mai mare," << endl;
		cout << " decat cea din nivelul anterior." << endl;
		cout << " Folosindu-ti cunostintele de tactica militara si gasind noi echipamente, " << endl;
		cout << " iti faci drum prin baza militara, luptandu-te cu zombie - militari " << endl;
		cout << " si cautand indicii care te vor duce catre persoana responsabila de aceasta situatie." << endl;
	}
	else if (enemy.name == "Major")
	{
		cout << " In timp ce patrunzi adanc in baza militara, intalnesti grupuri de zombie-militarii specializati," << endl;
		cout << " cum ar fi sniperi si luptatori cu abilitati de lupta corporala superioare." << endl;
		cout << " Lupta devine din ce in ce mai dificila, iar resursele tale devin limitate." << endl;
		cout << " Totusi, nu renunti si continui sa avansezi prin baza militara, " << endl;
		cout << " cautand informatii si aliati pentru a - ti sprijini misiunea." << endl;
	}
	else if (enemy.name == "General")
	{
		cout << " Ultimul nivel te poarta prin bazele subterane ale bazei militare." << endl;
		cout << " Zombie-militarii pe care ii intalnesti sunt cei mai periculosi si mai bine antrenati." << endl;
		cout << " Ai in fata ta lupte grele si provocari care iti testeaza limitele." << endl;
		cout << " Totusi, stii ca trebuie sa mergi mai departe si sa aduci justitia acolo unde este necesar." << endl;
	}
}

void Level::final(Enemy& enemy, Player& player) {
	int randomChoice;
	cout << endl << " Text Mode Game | Zombie Assault" << endl << endl;
	if (enemy.name == "Recruit")
	{
		cout << " Dupa o lupta indelungata si epuizanta, reusesti sa elimini majoritatea zombie-militarilor," << endl;
		cout << " din zona spitalului militar." << endl;
		cout << " Descoperi indicii care dezvaluie ca virusul a fost produs intentionat si ca exista o persoana responsabila, " << endl;
		cout << " pentru aceasta catastrofa." << endl;
		cout << " Esti hotarat sa razbuni camarazii tai cazuti si sa pui capat acestei amenintari." << endl << endl;
		randomChoice = rand() % 2 + 1;
		if (randomChoice == 1)
		{
			cout << " Ati gasit intr-un dulap o vesta antiglont noua cu placi de armura moi." << endl;
			cout << " " << player.name << " + 5 AP" << endl;
			player.armor += 5;
		}
		else if (randomChoice == 2)
		{
			cout << " Ati gasit intr-un dulap o pereche de boxuri." << endl;
			cout << " " << player.name << " + 5 DP" << endl;
			player.damage = 15;
		}
	}
	else if (enemy.name == "Corporal")
	{
		cout << " Cu multa determinare si pricepere tactica, reusesti sa ajungi la comandantul bazei militare, " << endl;
		cout << " care s - a transformat si el intr - un zombie - militar, dar era deja infrant." << endl;
		cout << " In lupta finala, il invingi si obtii informatii cruciale despre persoana responsabila, " << endl;
		cout << " pentru crearea virusului." << endl;
		cout << " Esti pregatit sa mergi mai departe in cautarea adevarului si a justitiei." << endl << endl;
		randomChoice = rand() % 2 + 1;
		if (randomChoice == 1)
		{
			cout << " Ati gasit pe un sertar o armura tactica completa cu placi de armura tari." << endl;
			cout << " " << player.name << " + 10 AP" << endl;
			player.armor += 10;
		}
		else if (randomChoice == 2)
		{
			cout << " Ati gasit pe un sertar o baioneta M9." << endl;
			if (player.damage == 10)
			{
				cout << " " << player.name << " + 10 DP" << endl;
				player.damage += 10;
			}
			else if (player.damage == 15)
			{
				cout << " " << player.name << " + 5 DP" << endl;
				player.damage += 5;
			}
		}
	}
	else if (enemy.name == "Major")
	{
		cout << " Intr-un moment critic, descoperi un laborator secret in care virusul a fost creat si testat. " << endl;
		cout << " Acolo, te confrunti cu zombie - militarul de rang inalt, responsabil de crearea virusului." << endl;
		cout << " Dupa o lupta intensa, il invingi si distrugei laboratorul, oprind productia si raspandirea virusului." << endl;
		cout << " Esti un pas mai aproape de adevar si esti hotarat sa cauti persoana responsabila." << endl << endl;
		randomChoice = rand() % 2 + 1;
		if (randomChoice == 1)
		{
			cout << " Ati gasit rezemat de perete un scut antiglont." << endl;
			cout << " " << player.name << " + 15 AP" << endl;
			player.armor += 15;
		}
		else if (randomChoice == 2)
		{
			cout << " Ati gasit rezemat de perete un macete." << endl;
			player.damage = 25;
			if (player.damage == 10)
			{
				cout << " " << player.name << " + 15 DP" << endl;
				player.damage += 15;
			}
			else if (player.damage == 15)
			{
				cout << " " << player.name << " + 10 DP" << endl;
				player.damage += 10;
			}
			else if (player.damage == 20)
			{
				cout << " " << player.name << " + 5 DP" << endl;
				player.damage += 5;
			}
		}
	}
	else if (enemy.name == "General") {
		cout << " In lupta finala, te confrunti cu liderul corupt care a comandat experimentul si a lasat baza militara, " << endl;
		cout << " sa cada sub influenta virusului. " << endl;
		cout << " In ciuda dificultatilor, reusesti sa il infrangi si sa dezvalui adevarul intregii conspiratii." << endl;
		cout << " Baza militara este eliberata de amenintare, iar tu esti recunoscut ca un erou, " << endl;
		cout << " pentru curajul si determinarea ta." << endl << endl;
	}
}

void Level::resetEnemy(Enemy& enemy) {
	Recruit* recruit = dynamic_cast<Recruit*>(&enemy);
	Corporal* corporal = dynamic_cast<Corporal*>(&enemy);
	Major* major = dynamic_cast<Major*>(&enemy);
	General* general = dynamic_cast<General*>(&enemy);

	if (recruit)
		recruit->reset();
	else if (corporal)
		corporal->reset();
	else if (major)
		major->reset();
	else if (general)
		general->reset();
}

void Level::setEndLevel(bool value)
{
	end = value;
}

bool Level::endLevel() {
	return end;
}

void Level::choice(Player& player, Enemy& enemy) {

	string input = "";

	int randomChoice;
	int randomMedicine;

	Level level;

	while (input != "m" && input != "M" && input != "o" && input != "O" && !end)
	{
		system("cls");

		Interface interface;

		interface.showPlayerInterface(player, level, enemy);

		cout << " [M]ergi - pentru a merge mai departe." << endl;
		cout << " [O]dihna - pentru a restabili puterile." << endl;

		cout << endl << " Optiunea aleasa: ";
		cin >> input;
	}

	if (input == "m" || input == "M")
	{
		cout << endl << " Decizi sa mergi mai departe. Mergand ";

		randomChoice = rand() % 3 + 1;
		randomMedicine = rand() % 6 + 1;

		if ((randomChoice == 1 || randomChoice == 2) && randomMedicine != 6)
		{
			cout << "nu s-a intamplat nimic." << endl;
			level.pause();
			return;
		}
		else if ((randomChoice == 1 || randomChoice == 2) && randomMedicine == 6)
		{
			cout << "ai gasit o trusa de prim ajutor." << endl;
			player.firstAidKits++;
			level.pause();
			return;
		}
		else {
			if (enemy.nr > 0)
			{
				cout << "ai intalnit un Zombie " << enemy.name << endl;
				level.pause();
				Interface interface;
				interface.showBattleInterface(player, enemy, level);
				level.battle(player, enemy);
				return;
			}
			else {
				cout << "ai gasit iesirea" << endl;
				level.pause();
				end = true;
				return;
			}
		}
	}
	if (input == "o" || input == "O")
	{
		cout << endl << " Decizi sa te odihnesti. Stand rezemat de un perete ";

		randomChoice = rand() % 6 + 1;

		if (randomChoice != 6)
		{
			if (player.health <= 95)
			{
				cout << "ai restabilit putina energie." << endl;
				player.health += 5;
			}
			else if (player.health > 95 && player.health < 100)
			{
				cout << "ai restabilit putina energie." << endl;
				player.health += 100 - player.health;
			}
			else if (player.health == 100) {
				cout << "ai stat degeaba. Erai plin de puteri." << endl;
			}
			level.pause();
		}
		else
		{
			cout << " ai fost vazut de un Zombie " << enemy.name << endl;
			enemy.nr++;
			level.pause();
			Interface interface;
			interface.showBattleInterface(player, enemy, level);
			level.battle(player, enemy);
		}
	}
	input = "";
}

void Level::battle(Player& player, Enemy& enemy) {

	string input = "";

	int randomChoice;

	Level level;
	Interface interface;

	while (enemy.health > 0 && player.health > 0)
	{
		while (input != "a" && input != "A" && input != "b" && input != "B" && input != "v" && input != "V")
		{
			system("cls");

			interface.showBattleInterface(player, enemy, level);

			cout << " [A]taca - pentru a ataca inamicul." << endl;
			cout << " [B]locheaza - pentru a incerca sa blochezi atacul inamicului." << endl;
			cout << " [V]indeca - pentru a folosi trusa de prim ajutor." << endl;

			cout << endl << " Optiunea aleasa: ";
			cin >> input;
		}

		if (input == "a" || input == "A")
		{
			system("cls");

			interface.showBattleInterface(player, enemy, level);

			cout << " Il ataci pe Zombie " << enemy.name << "..." << endl << endl;

			cout << " " << enemy.name << " - " << player.damage - enemy.armor << " HP" << endl;

			enemy.health -= player.damage - enemy.armor;

			if (enemy.armor > 0) {
				cout << " " << enemy.name << " - 1 AP" << endl;
				enemy.armor -= 1;
			}

			level.pause();

			system("cls");

			interface.showBattleInterface(player, enemy, level);

			if (enemy.health > 0) {
				cout << " Zombie " << enemy.name << " te ataca..." << endl << endl;


				cout << " " << player.name << " - " << enemy.damage - player.armor << " HP" << endl;
				player.health -= enemy.damage - player.armor;

				if (player.armor > 0) {
					cout << " " << player.name << " - 1 AP" << endl;
					player.armor -= 1;
				}

				level.pause();

				system("cls");

				interface.showBattleInterface(player, enemy, level);
			}
		}
		else if (input == "b" || input == "B")
		{
			system("cls");

			interface.showBattleInterface(player, enemy, level);

			cout << " Incerci sa blocheazi atacul facut de Zombie " << enemy.name << "..." << endl << endl;

			randomChoice = rand() % 3 + 1;

			if (randomChoice != 3) {
				if (player.health <= 95)
				{
					cout << " Ai blocat atacul cu succes." << endl;
					cout << " " << player.name << " + 5 HP" << endl;
					player.health += 5;
				}
				else if (player.health > 95 && player.health < 100)
				{
					cout << " Ai blocat atacul cu succes." << endl;
					cout << " " << player.name << " + " << 100 - player.health << " HP" << endl;
					player.health += 100 - player.health;
				}
				else {
					cout << " Ai blocat atacul cu succes dar si asa esti in forma maxima." << endl;
				}
			}
			else {
				cout << " Nu ai putut bloca atacul inamicului." << endl;
				cout << " " << player.name << " - " << enemy.damage - player.armor << " HP" << endl;
				player.health -= enemy.damage - player.armor;
				if (player.armor > 0) {
					cout << " " << player.name << " - 1 AP" << endl;
					player.armor -= 1;
				}
			}

			level.pause();

			system("cls");

			interface.showBattleInterface(player, enemy, level);
		}
		else if (input == "v" || input == "V")
		{
			system("cls");

			interface.showBattleInterface(player, enemy, level);

			cout << " Te-ai ascuns dupa un perete si cauti in rucsac o trusa de prim ajutor..." << endl << endl;

			if (player.firstAidKits > 0) {
				if (player.health <= 70)
				{
					cout << " Ai folosit trusa cu succes." << endl;
					cout << " " << player.name << " + 30 HP" << endl;
					player.health += 30;
					player.firstAidKits -= 1;
				}
				else if (player.health > 70 && player.health < 100)
				{
					cout << " Ai folosit trusa cu succes." << endl;
					cout << " " << player.name << " + " << 100 - player.health << " HP" << endl;
					player.health += 100 - player.health;
					player.firstAidKits -= 1;
				}
				else if (player.health == 100) {
					cout << " Ai deschis trusa, dar ai inteles ca nu ai ce face cu ea, iar inamicul a ajuns prea aprope." << endl;
					cout << " El vrea sa te atace, dar tu arunci cu trusa in Zombie " << enemy.name << "." << endl;
					cout << " " << player.name << " - 1 Trusa de Prim Ajutor" << endl;
					player.firstAidKits -= 1;
				}
			}
			else {
				cout << " Nu ai gasit nimic in rucsac, iar inamicul a ajuns prea aprope pentru a reusi sa-i blochezi atacul." << endl;
				cout << " " << player.name << " - " << enemy.damage - player.armor << " HP" << endl;
				player.health -= enemy.damage - player.armor;
				if (player.armor > 0) {
					cout << " " << player.name << " - 1 AP" << endl;
					player.armor -= 1;
				}
			}

			level.pause();

			system("cls");

			interface.showBattleInterface(player, enemy, level);
		}
		input = "";
	}
	if (player.health == 0)
	{
		system("cls");

		cout << endl << " Text Mode Game | Zombie Assault" << endl << endl;
		cout << " Din pacate ai pierdut. Mai poti incerca de ori de cate ori vrei." << endl;

		level.pause();

		ofstream file("savegame.txt", ofstream::trunc);
		if (file.is_open()) {
			file.close();
		}

		exit(0);
	}
	cout << " Zombie " << enemy.name << " a cazut la pamant.";
	level.resetEnemy(enemy);

	randomChoice = rand() % 6 + 1;
	if (randomChoice == 6)
	{
		player.firstAidKits += 1;
		cout << endl << " Ai gasit in rucsacul inamicului cazut o trusa de prim ajutor." << endl;
	}
	else
		cout << endl << " Nu ai gasit nimic de folos in rucsacul inamicului cazut." << endl;

	enemy.nr -= 1;

	level.pause();
	input = "";
}