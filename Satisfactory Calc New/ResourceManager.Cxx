#include "ResourceManager.Hxx"

std::string Resources::ConsoleTitle;

void Resources::Initialize() {

    {
        std::ifstream ConsoleTitleFile(".\\ConsoleTitle.txt");

        std::string buffer = "";
        while(std::getline(ConsoleTitleFile, buffer)) {
            ConsoleTitle += buffer + '\n';
        };

        ConsoleTitleFile.close();
    }

}
