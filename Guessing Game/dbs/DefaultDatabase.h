#ifndef GUESS_SRC_DEFDBS_H_
#define GUESS_SRC_DEFDBS_H_

#include <vector>
#include <string>

/* System variables data */

#define SYSTEM_DIFFICULITY_EASY   1
#define SYSTEM_DIFFICULITY_MEDIUM 2
#define SYSTEM_DIFFICULITY_HARD   3

#define SYSTEM_COLOR_RED    12
#define SYSTEM_COLOR_GREEN  10
#define SYSTEM_COLOR_BLUE   9
#define SYSTEM_COLOR_WHITE  15
#define SYSTEM_COLOR_YELLOW 14
#define SYSTEM_COLOR_SELECT 16

/* Game Data */

//Commmon Equasions

#define GAME_SET_NUMBER(N,R) N = rand() % R

//Default Variables

#define GAME_KEY_UP    72
#define GAME_KEY_DOWN  80
#define GAME_KEY_LEFT  75
#define GAME_KEY_RIGHT 77
#define GAME_KEY_ENTER 13

namespace GUESS {

template <typename T>
inline size_t EQ_FIND_INDEX(T arr[], T value, size_t size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) return i;
	}
	return -1;
}

const int data_player_hp      = 10;
const int data_player_retries =  5;

const std::vector<std::string> data_interface_titlescreen = { "  _____                     _                _____                       ",
															  " / ____|                   (_)              / ____|                      ",
															  "| |  __ _   _  ___  ___ ___ _ _ __   __ _  | |  __  __ _ _ __ ___   ___  ",
															  "| | |_ | | | |/ _ \\/ __/ __| | '_ \\ / _` | | | |_ |/ _` | '_ ` _ \\ / _ \\ ",
															  "| |__| | |_| |  __/\\__ \\__ \\ | | | | (_| | | |__| | (_| | | | | | |  __/ ",
															  " \\_____|\\__,_|\\___||___/___/_|_| |_|\\__, |  \\_____|\\__,_|_| |_| |_|\\___| " };

const std::vector<std::string> data_inferface_menu = { "****************************************************************************",
													   "*                                                                          *",		    
													   "*", 
													    "                            SELECT DIFFICULITY                            ", 
                                                       "EASY", "MEDIUM", "HARD",
																														 "HIGH SCORE", };

}

#endif // !GUESS_SRC_DEFDBS_H_