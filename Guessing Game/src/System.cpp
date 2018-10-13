#include "..\include\System.h"

using namespace GUESS;

System::System() : is_paused_(true), is_playing_(false), game_number_(10),
				   input_number_(NULL), game_input_(NULL), handle_console_(GetStdHandle(STD_OUTPUT_HANDLE)),
				   system_difficulity_{ SYSTEM_DIFFICULITY_EASY, SYSTEM_DIFFICULITY_MEDIUM, SYSTEM_DIFFICULITY_HARD } {}


System::~System() {}

void System::SetConsoleColor(int color) {
	SetConsoleTextAttribute(handle_console_, color);
}

void System::Launch() {
	is_playing_ =  true;
	(is_paused_) ? is_paused_ = false : is_paused_;

	thread_worker_ = std::make_unique<std::thread>(&System::WindowIntro, this);

	std::cin.get();
	game_input_ = 1;
	
	thread_worker_->join();

	game_input_ = NULL;

	while (!input_number_)
	{
		WindowSelect();
	}

	switch (input_number_) {
		case 0:
			system_player_.GeneratePlayer(SYSTEM_DIFFICULITY_EASY);
															 break;
		case 1:
			system_player_.GeneratePlayer(SYSTEM_DIFFICULITY_MEDIUM);
														   	   break;
		case 2:
			system_player_.GeneratePlayer(SYSTEM_DIFFICULITY_HARD);
															 break;
		default:
															 break;
	}
}

void System::WindowIntro() {

	while (!game_input_)
	{
		SetConsoleColor(SYSTEM_COLOR_RED);
		for (auto i : data_interface_titlescreen) {
			system_interface_.ChangeText(i);
			Draw();
			system_interface_.ChangeText("\n");
			Draw();
		}
		SetConsoleColor(SYSTEM_COLOR_WHITE);
		system_interface_.ChangeText("\n PRESS ENTER TO START"); Draw();

											std::this_thread::sleep_for(1s);
																  Refresh();
																  if (game_input_) break;
		SetConsoleColor(SYSTEM_COLOR_YELLOW);
		for (auto i : data_interface_titlescreen) {
			system_interface_.ChangeText(i);
			Draw();
			system_interface_.ChangeText("\n");
			Draw();
		}
		SetConsoleColor(SYSTEM_COLOR_WHITE);
		system_interface_.ChangeText("\n PRESS ENTER TO START"); Draw();

											std::this_thread::sleep_for(1s);
																  Refresh();
	}
}

void System::WindowSelect() {
	Refresh();
	SetConsoleColor(SYSTEM_COLOR_GREEN); system_interface_.ChangeText(data_inferface_menu[0]);
																					   Draw();
																	   std::cout << std::endl;

	system_interface_.ChangeText(data_inferface_menu[1]);							   Draw();
																	   std::cout << std::endl;

	system_interface_.ChangeText(data_inferface_menu[2]);							   Draw();
	SetConsoleColor(SYSTEM_COLOR_WHITE); system_interface_.ChangeText(data_inferface_menu[3]);
																					   Draw();
	SetConsoleColor(SYSTEM_COLOR_GREEN); system_interface_.ChangeText(data_inferface_menu[2]);
																					   Draw();
	SetConsoleColor(SYSTEM_COLOR_GREEN); 
	
	(!game_input_) ? game_input_ = system_difficulity_[1] : game_input_;


	thread_worker_ = std::make_unique<std::thread>([=]{

		switch (_getch())
		{
			case GAME_KEY_LEFT:
				game_input_ = [](size_t pos_current, size_t arr[])-> size_t {
								auto i = EQ_FIND_INDEX(arr, pos_current, 3);
								(i - 1 != -1) ? pos_current = arr[i - 1] : pos_current = arr[i];
																			 return pos_current;
								}(game_input_, system_difficulity_);				      break;
			case GAME_KEY_RIGHT:
				game_input_ = [](size_t pos_current, size_t arr[])-> size_t {
								auto i = EQ_FIND_INDEX(arr, pos_current, 3);
								(i + 1 != 3) ? pos_current = arr[i + 1] : pos_current = arr[i];
																		    return pos_current;
								}(game_input_, system_difficulity_);		   			 break;
			case GAME_KEY_ENTER:
				input_number_ = game_input_; break;
			default:
				break;
		}
	});
																	   std::cout << std::endl;
	system_interface_.ChangeText(data_inferface_menu[1]);							   Draw();
																	   std::cout << std::endl;
	system_interface_.ChangeText(data_inferface_menu[2]);							   Draw();

	std::cout << "                           ";
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			(i == EQ_FIND_INDEX(system_difficulity_, game_input_, 3)) ? SetConsoleColor(SYSTEM_COLOR_SELECT) : SetConsoleColor(SYSTEM_COLOR_WHITE);
			system_interface_.ChangeText(data_inferface_menu[4]);																			Draw();
		} if (i == 1) {
			(i == EQ_FIND_INDEX(system_difficulity_, game_input_, 3)) ? SetConsoleColor(SYSTEM_COLOR_SELECT) : SetConsoleColor(SYSTEM_COLOR_WHITE);
			system_interface_.ChangeText(data_inferface_menu[5]);																			Draw();
		} if (i == 2) {
			(i == EQ_FIND_INDEX(system_difficulity_, game_input_, 3)) ? SetConsoleColor(SYSTEM_COLOR_SELECT) : SetConsoleColor(SYSTEM_COLOR_WHITE);
			system_interface_.ChangeText(data_inferface_menu[6]);																			Draw();
		}

		system_interface_.ChangeText("   "); Draw();
	}SetConsoleColor(SYSTEM_COLOR_WHITE);

	std::cout << "                        ";
	SetConsoleColor(SYSTEM_COLOR_GREEN);
	system_interface_.ChangeText(data_inferface_menu[2]);							   Draw();
																	   std::cout << std::endl;
	system_interface_.ChangeText(data_inferface_menu[1]);							   Draw();
																	   std::cout << std::endl;
	system_interface_.ChangeText(data_inferface_menu[0]);							   Draw();

	thread_worker_->join();

}

void System::generate_number(int range) {
	GAME_SET_NUMBER(game_number_, range);
}

bool System::main_game() {
	Refresh();

	input_number_ = NULL;

	while (true)
	{
		generate_number(game_input_ * game_number_);
		std::cout << "GUESS NUMBER BETWEEN 0 and " << game_number_ << std::endl;
		std::cin >> input_number_;

		while (input_number_ != game_number_)
		{
			if(system_player_.get_player_life() == 0) {

			} else if (input_number_ < game_number_) {
				Refresh(); std::cout << "WRONG NUMBER TOO LOW" << std::endl;
				--system_player_;
			} else if (input_number_ > game_number_) {
				Refresh(); std::cout << "WRONG NUMBER TOO HIGH" << std::endl;
				--system_player_;
			}
			std::cin >> input_number_;
		}
	}

	return true;
}