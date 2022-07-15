// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
#include <iostream>
#include <string>

int main () {
    bool ships[8][8] = {
    { 0, 1, 1, 0, 0, 1, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 1, 0, 1, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 1, 0, 0, 1, 0, 0},
    { 0, 0, 0, 0, 0, 0, 1, 0}
    };

    int hits = 0;
    int turns = 0;

    while (hits < 8) {
        int col, row;
        std::cout << "Battleships 8X8 - Selecting coordinates!\n";
        std::cout << "Choose col, 1-8: ";
        std::cin >> col;
        col--;
        std::cout << "Choose row #, 1-8: ";
        std::cin >> row;
        row--;

        if (ships[row][col]) {
            ships[row][col] = 0;
            hits++;
            std::cout << "Ship down! " << (8-hits) << " left\n\n";
        } else {
            std::cout << "Turn " << (1+turns) << ": Miss\n\n";
        }

        turns++;
    }

    std::cout << "Success! Game finished in " << turns << " turns\n";
    return 0; 
}

