#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

bool checkMove(std::string p_move, std::string c_move);

int main() {
	const std::string moves[] = {"Rock", "Paper", "Scissors"};
	srand(time(NULL));

	bool play = true;
	while (play) {
		std::cout << "Please make a move!\n";
		std::string p_move;
		// Could use std::cin here, but will stop on the first white space, instead, we do:
		std::getline(std::cin, p_move);
		srand(time(NULL)); // This is great, but the prediction is dependent on the time,
				   // so it's not completely random. See better results later!
		std::string c_move = moves[std::rand() % 3];
		std::cout << "Your move: " << p_move << " Computer move: " << c_move << '\n';

		if (checkMove(p_move, c_move)) {
			play = false;
			std::cout << "You win!" << std::endl;
		} else if (checkMove(c_move, p_move)) {
			play = false;
			std::cout << "Computer win!" << std::endl;
		}
	}
	return 0;
}

bool checkMove(std::string p_move, std::string c_move) {
	bool hasWon = false;
	if (p_move == "Rock" && c_move == "Scissors") {
		hasWon = true;
	} else if (p_move == "Paper" && c_move == "Rock") {
		hasWon = true;
	} else if (p_move == "Scissors" && c_move == "Paper") {
		hasWon = true;
	} else {
		// Do nothing
	}

	/* This doesn't work as switch statements only work with variables that
	 * can be associated with an integer... i.e basic data types
	 *
	 * Also, note that C++ doens't have a string type, std::string is in the
	 * Standard Library which isn't part of the language per se.
	 *
	 * Also, C/C++ switch statements are typically generated as branch tables, which
	 * aren't nearly as easy to generate for a string style switch.
	 *
	switch(p_move) {
		case "Rock":
			if (c_move == "Scissors")
				hasWon = true;
			break;
		case "Paper":
			if (c_move == "Scissors")
				hasWon = true;
			break;
		case "Scissors":
			if (c_move == "Paper")
				hasWon = true;
			break;
		default:
			continue;
	}
	*/
	return hasWon;
}
