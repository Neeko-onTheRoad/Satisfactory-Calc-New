#include "ResourceManager.Hxx"

std::string Resources::ConsoleTitle;
std::string Resources::Credit;

void Resources::Initialize() {

    { // ConsoleTitle
        std::ifstream ConsoleTitleFile(".\\res\\ConsoleTitle.txt");

        std::string buffer = "";
        while (std::getline(ConsoleTitleFile, buffer)) {
            ConsoleTitle += buffer + '\n';
        };

        ConsoleTitleFile.close();
    }

    { // Credit

        std::ifstream CreditFile(".\\res\\Credit.txt");

        std::string buffer = "";
        while (std::getline(CreditFile, buffer)) {
            Credit += buffer + '\n';
        }

        CreditFile.close();
    }

}
