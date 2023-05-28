#pragma once
#include <iostream>

/*! Class to manage the user interface */
class UI
{
    public:
    /*! Method to display the main user menu
    @return the user's choice */
    int DisplayMenu();

    /*! Method to display the different choices of difficulty */
    int DisplayDifficultyMenu();

    /*! Method to display the options for players */
    int playerSettings();

    /*! Method that displays the help menu */
    void DisplayHelp();
};