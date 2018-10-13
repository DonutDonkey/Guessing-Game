#ifndef GUESS_INCLUDE_INTERFACE_H_
#define GUESS_INCLUDE_INTERFACE_H_

#include <string>
#include <vector>

class GameInterface {
public:
	GameInterface() { condition_ = { "Too high", "Too low", "Perfect" }; }
	
	void ChangeText(std::string text) { text_ = text; }
	
	std::string get_text() const { return text_; }
	std::string get_condition(int player, int goal) const { return (player == goal) ? condition_[2] : ((player > goal) ? condition_[0] : condition_[1]); }

	friend std::ostream& operator<<(std::ostream& os, const GameInterface& GI) { os << GI.get_text(); return os; }

private:
	std::string text_;
	std::vector<std::string> condition_;
};

#endif // !GUESS_INCLUDE_INTERFACE_H_