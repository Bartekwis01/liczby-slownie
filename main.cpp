#include <iostream>
#include <string>
#include <vector>
std::vector<std::string>jednosci_slownie = {"jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec"};
std::vector<std::string>l10_l19_slownie = {"dziesiec", "jedenascie", "dwanascie", "trzynascie", "czternascie", "pietnascie", "szesnascie", "siedemnascie", "osiemnascie", "dziewietnascie"};
std::vector<std::string>dziesiatki_slownie = {"dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat"};
std::vector<std::string>setki_slownie = {"sto", "dwiescie", "trzysta", "czterysta", "piecset", "szescset", "siedemset", "osiemset", "dziewiecset"};
int main() {

    int liczba;
    std::vector<std::string> output;
    std::cin >> liczba;

    if (liczba == 0) {
        std::cout << "zero";
        return 0;
    }

    //MINUS
    if (liczba < 0) {
        output.emplace_back("minus");
        liczba = -liczba;
    }

    //LICZENIE
    int setki_milionow = (liczba/100000000) % 10;
    int dziesiatki_milionow = (liczba/10000000) % 10;
    int miliony = (liczba/1000000) % 10;
    int setki_tysiecy = (liczba/100000) % 10;
    int dziesiatki_tysiecy = (liczba/10000) % 10;
    int tysiace = (liczba/1000) % 10;
    int setki = (liczba/100) % 10;
    int dziesiatki = (liczba/10) % 10;
    int jednosci = liczba % 10;

    //MILIONY
    if (setki_milionow != 0) {
        output.emplace_back(setki_slownie[setki_milionow -1]);
    }

    if (dziesiatki_milionow == 1) {
        output.emplace_back(l10_l19_slownie[miliony]);
        output.emplace_back("milionow");
    }
    else if (dziesiatki_milionow > 1) {
        output.emplace_back(dziesiatki_slownie[dziesiatki_milionow - 2]);
    }

    if (miliony == 1 and dziesiatki_milionow == 0 and setki_milionow == 0) {
        output.emplace_back("milion");
    }
    else if ((miliony == 2 or miliony == 3 or miliony == 4 ) and (dziesiatki_milionow > 1 or dziesiatki_milionow == 0)) {
        output.emplace_back(jednosci_slownie[miliony - 1]);
        output.emplace_back("miliony");
    }
    else if ((miliony == 1 or miliony == 5 or miliony == 6 or miliony == 7 or miliony == 8 or miliony == 9) and (dziesiatki_milionow > 1 or dziesiatki_milionow == 0)) {
        output.emplace_back(jednosci_slownie[miliony - 1]);
        output.emplace_back("milionow");
    }
    else if (miliony == 0 and (dziesiatki_milionow != 0 or setki_milionow != 0)) {
        output.emplace_back("milionow");
    }

    //TYSIACE
    if (setki_tysiecy != 0) {
        output.emplace_back(setki_slownie[setki_tysiecy -1]);
    }

    if (dziesiatki_tysiecy == 1) {
        output.emplace_back(l10_l19_slownie[tysiace]);
        output.emplace_back("tysiecy");
    }
    else if (dziesiatki_tysiecy > 1) {
        output.emplace_back(dziesiatki_slownie[dziesiatki_tysiecy - 2]);
    }

    if (tysiace == 1 and dziesiatki_tysiecy == 0 and setki_tysiecy == 0) {
        output.emplace_back("tysiac");
    }
    else if ((tysiace == 2 or tysiace == 3 or tysiace == 4 ) and (dziesiatki_tysiecy > 1 or dziesiatki_tysiecy == 0)) {
        output.emplace_back(jednosci_slownie[tysiace - 1]);
        output.emplace_back("tysiace");
    }
    else if ((tysiace == 1 or tysiace == 5 or tysiace == 6 or tysiace == 7 or tysiace == 8 or tysiace == 9) and (dziesiatki_tysiecy > 1 or dziesiatki_tysiecy == 0)) {
        output.emplace_back(jednosci_slownie[tysiace - 1]);
        output.emplace_back("tysiecy");
    }
    else if (tysiace == 0 and (dziesiatki_tysiecy != 0 or setki_tysiecy != 0)) {
        output.emplace_back("tysiecy");
    }

    //MNIEJSZE
    if (setki > 0 and setki < 9) {
        output.emplace_back(setki_slownie[setki - 1]);
    }

    if (dziesiatki > 1) {
        output.emplace_back(dziesiatki_slownie[dziesiatki - 2]);
    }

    if (dziesiatki == 1) {
        output.emplace_back(l10_l19_slownie[jednosci]);
    }

    else if (jednosci != 0) {
        output.emplace_back(jednosci_slownie[jednosci - 1]);
    }

    //WYPISZ
    for (int i = 0; i < output.size(); i++) {
        std::cout << output[i];
        if (i + 1 < output.size()) {
            std::cout << " ";
        }
    }
    return 0;
}