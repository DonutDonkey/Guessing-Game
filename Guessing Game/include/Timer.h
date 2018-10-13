#ifndef GUESS_INCLUDE_TIMER_H_
#define GUESS_INCLUDE_TIMER_H_

#include <ctime>
#include <chrono>

using namespace std::chrono_literals;

class Timer {
public:
	Timer() { timer_begin_   =     0; timer_end_   =    0;
			  timer_running_ = false; timer_reset_ = true; };

	void Start();
	void Stop();
	void Reset();

	bool is_running()		    const;
	bool is_over(unsigned long) const;

	unsigned long get_time()    const;

private:
	unsigned long timer_begin_;
	unsigned long timer_end_;
	bool	      timer_running_;
	bool		  timer_reset_;
};

#endif // !GUESS_INCLUDE_TIMER_H
