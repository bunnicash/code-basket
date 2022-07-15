// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
#include <iostream>
#include <string>

// Use several floors
int gamepath[3][9][9] = {
	{
		{ 0, 0, 0, 0, 0, 0, 2, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 2, 0, 0, 0, 0},
		{ 0, 4, 0, 0, 1, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 2, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0}
	},
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 4, 2, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0}
	},
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 4, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0}
	}
};
	
int floors; 
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
	if (gamepath[floors][row][col] == 2) {
		std::cout << "Enemy detected and killed\n";
	} else {
		std::cout << "Found nothing\n";
	}
}

void checkfloors() {
	if (gamepath[floors][row][col] == 4) {
		std::cout << "Entered the elevator - Which floor? (A,B,C): ";
		std::string use_elevator;
		std::cin >> use_elevator;
		if (use_elevator == "A") {
			floors = 0;
		} else if (use_elevator == "B") {
			floors = 1;
		} else if (use_elevator == "C") {
			floors = 2;
		}
	}
}

int main () {
	floors = 0; 
	row = 4;
	col = 4;  // start point (0, 5, 5)
	
	while (turns < 10) {
		std::string movement;
		std::cout << "Go: ";
		std::cin >> movement;
		
		if (movement == "w") {
			std::cout << "Moving up: ";
			gamepath[floors][row][col] = 0;
			row--;
			checkborders();
			checkfloors();
			enemykill();
			gamepath[floors][row][col] = 1;
		} else if (movement == "s") {
			std::cout << "Moving down: ";
			gamepath[floors][row][col] = 0;
			row++;
			checkborders();
			checkfloors();
			enemykill();
			gamepath[floors][row][col] = 1;
		} else if (movement == "a") {
			std::cout << "Moving left: ";
			gamepath[floors][row][col] = 0;
			col--;
			checkborders();
			checkfloors();
			enemykill();
			gamepath[floors][row][col] = 1;
		} else if (movement == "d") {
			std::cout << "Moving right: ";
			gamepath[floors][row][col] = 0;
			col++;
			checkborders();
			checkfloors();
			enemykill();
			gamepath[floors][row][col] = 1;
		} else {
			std::cout << "Enter w,a,s,d!\n";
		}
		
		turns++;
	}
	
	return 0;
}

