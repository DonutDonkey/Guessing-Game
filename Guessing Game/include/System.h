#ifndef GUESS_INCLUDE_SYSTEM_H_
#define GUESS_INCLUDE_SYSTEM_H_

#include "..\include\Player.h"
#include "..\include\Timer.h"
#include "..\include\Interface.h"
#include "..\dbs\DefaultDatabase.h"

#include <memory>
#include <iostream>
#include <thread>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include <algorithm>

class System {
public:
	System(); ~System();

	void Refresh() { system("cls"); };
	void Draw()    { std::cout << system_interface_; }
	void Draw(std::string text) { std::cout << text; }

	void Launch();
	void WindowIntro();
	void WindowSelect();
	
	
	void SetConsoleColor(int);

	void generate_number(int);

	bool main_game();
private:
	Player		  system_player_;
	Timer         system_timer_;
	GameInterface system_interface_;
	size_t		  system_difficulity_[3];

	bool is_playing_;
	bool is_paused_;

	int		    game_number_;
	size_t 	   input_number_;
	unsigned int game_input_;

	HANDLE   handle_console_;

	std::unique_ptr<std::thread> thread_worker_;

};

#endif // !GUESS_INCLUDE_SYSTEM_H_
