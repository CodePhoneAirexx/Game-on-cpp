#include <iostream>
#include <string>
#include <fstream>
#include <locale.h>
#include <chrono>

void Store();
class PLayerData;

class PlayerData{
private:
    long money;
public:
    PlayerData() {
        std::ifstream file;
        file.open("playerdata.txt");

        if (file.is_open()) {
            file >> money;
            file.close();
        } else {
            std::ofstream newFile;
            money = 200;
            newFile.open("playerdata.txt");
            if (newFile.is_open()) {
                newFile << money;
                newFile.close();
            }
        }
    }

    void GiveMoney(long amount) {
        money += amount;
        std::ofstream file;
        file.open("playerdata.txt");
        if (file.is_open()) {
            file << money;
            file.close();
        }
    }

    void TakeMoney(long amount) {
        if (money >= amount) {
            money -= amount;
            std::ofstream file;
            file.open("playerdata.txt");
            if (file.is_open()) {
                file << money;
                file.close();
            }
        } else {
            std::cout << "Недостаточно денег!\n";
        }
    }

    long GiveDataMoney() {
        return money;
    }

    ~PlayerData() {
        std::ifstream file;
        file.open("playerdata.txt");

        if (file.is_open()) {
            long savedMoney;
            file >> savedMoney;
            file.close();

            if (savedMoney != money) {
                std::ofstream saveFile;
                saveFile.open("playerdata.txt");
                if (saveFile.is_open()) {
                    saveFile << money;
                    saveFile.close();
                }
            }
        } else {
            std::ofstream newFile;
            newFile.open("playerdata.txt");
            if (newFile.is_open()) {
                newFile << money;
                newFile.close();
            }
        }
        std::cout << "Данные игрока сохранены.\n";    
    }
};

int main() {
    std::setlocale(LC_ALL, "Russian_Russia.utf8");

    PlayerData player;
    std::cout << "Добро пожаловать в игру!\n"; 

    std::cout << "Ваши деньги: " << player.GiveDataMoney() << "\n";

    std::cout << "Выберите игру:\n";
    std::cout << "1. Ограбление магазина\n";
    short choice;

    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Ограбление еще нету :)\n";
    }
    
    return 0;
}