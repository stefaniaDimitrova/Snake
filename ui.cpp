#include "ui.hpp"

int UI::DisplayMenu()
{
    std::cout << "Snake Game Menu" << std::endl;
    std::cout << "1. Single Player" << std::endl;
    std::cout << "2. Two Players" << std::endl;
    std::cout << "3. Change Difficulty" << std::endl;
    std::cout << "4. Start Game" << std::endl;
    std::cout << "5. Help" << std::endl;
    std::cout << "Please enter your choice: ";
    int input;
    std::cin >>input;
    return input;
}

int UI::DisplayDifficultyMenu()
{
    std::cout << "Select Difficulty Level" << std::endl;
    std::cout << "1. Easy" << std::endl;
    std::cout << "2. Medium" << std::endl;
    std::cout << "3. Hard" << std::endl;
    std::cout << "Enter your choice: ";

    int input;
    std::cin >>input;
    return input;
}

int UI::playerSettings()
{
    std::cout << "1. Play with a friend" << std::endl;
    std::cout << "2. Play against a robot" << std::endl;
    std::cout << "Enter your choice: ";

    int input;
    std::cin >>input;
    return input;
}

void UI::DisplayHelp()
{
    std::cout << "Game Controls:" << std::endl;
    std::cout << "Player 1: W - Up, S - Down, A - Left, D - Right" << std::endl;
    std::cout << "Player 2: I - Up, K - Down, J - Left, L - Rigth" << std::endl;
    std::cout << "Q - quit" << std::endl;
    std::cout << "P - pause" << std::endl;
}