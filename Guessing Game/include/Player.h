#ifndef GUESS_INCLUDE_PLAYER_H_
#define GUESS_INCLUDE_PLAYER_H_

class Player {
public:
	Player();

    bool TestFunction() { bool value; value = PlayerIsAlive(); return value; }

	void GeneratePlayer(int player_life) { player_life_ /= player_life; }

    void set_player_life(int player_life) { player_life_ = player_life;  }
	int  get_player_life() const				  { return player_life_; }

	void set_player_score(int player_score) { player_score_ = player_score;  }
	int  get_player_score()  const					{ return  player_score_; }

	Player & operator--()
	{
		player_life_ -= 1;
		return *this;
	}
private:
	bool PlayerIsAlive() { return player_life_; }							   //Checks if player life is != 0

	int	 player_life_;
	int	 player_score_;
};

#endif // !GUESS_INCLUDE_PLAYER_H_