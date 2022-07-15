// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
#include <iostream>
#include <string>

int gamepath[9][9] = {
{ 0, 0, 0, 0, 0, 0, 2, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 2, 0, 0, 0, 0},
{ 0, 0, 0, 0, 1, 0, 0, 0, 0},
{ 0, 0, 0, 0, 2, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
	
int row;
int col;
int turns = 0;

void checkborders() {
	if (row < 0 || col < 0 || row > 8 || col > 8) {
		std::cout << "([" << row << "][" << col <<"]) Map limit, stepping back: ";
		if (row < 0) {
			row++;
		} else if (row > 8) {
			row--;
		} else if (col < 0) {
			col++;
		} else if (col > 8) {
			col--;
		} 
	}
}

void enemykill() {
	if (gamepath[row][col] == 2) {
		std::cout << "Enemy detected and killed\n";
	} else {
		std::cout << "Found nothing\n";
	}
}

int main () {
	row = 4;
	col = 4;  // start point
	
	while (turns < 10) {
		std::string movement;
		std::cout << "Go: ";
		std::cin >> movement;
		
		if (movement == "w") {
			std::cout << "Moving up: ";
			gamepath[row][col] = 0;
			row--;
			checkborders();
			enemykill();
			gamepath[row][col] = 1;
		} else if (movement == "s") {
			std::cout << "Moving down: ";
			gamepath[row][col] = 0;
			row++;
			checkborders();
			enemykill();
			gamepath[row][col] = 1;
		} else if (movement == "a") {
			std::cout << "Moving left: ";
			gamepath[row][col] = 0;
			col--;
			checkborders();
			enemykill();
			gamepath[row][col] = 1;
		} else if (movement == "d") {
			std::cout << "Moving right: ";
			gamepath[row][col] = 0;
			col++;
			checkborders();
			enemykill();
			gamepath[row][col] = 1;
		} else {
			std::cout << "Enter w,a,s,d!\n";
		}
		
		turns++;
	}
	
	return 0;
}

