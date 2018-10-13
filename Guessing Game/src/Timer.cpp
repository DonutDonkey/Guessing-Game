#include "..\include\Timer.h"

void Timer::Start() {
	if (!timer_running_) {
		
		(timer_reset_) ? timer_begin_ = (unsigned long)clock() : timer_begin_ -= timer_end_ - (unsigned long)clock();
		timer_running_ =  true; timer_reset_    = false;
	}
}

void Timer::Stop() {
	if (timer_running_) {
		timer_end_    = (unsigned long)clock();
		timer_running_ =				  false;
	}
}

void Timer::Reset() {
	bool is_running = timer_running_;
	
	if (is_running) Stop();

	timer_reset_ = true;
	timer_begin_ =    0;
	timer_end_   =    0;

	if(is_running) Start();
}

bool Timer::is_running() const {
	return timer_running_;
}

bool Timer::is_over(unsigned long seconds) const {
	return seconds >= get_time();
}

unsigned long Timer::get_time() const {
	return (timer_running_) ? ((unsigned long)clock() - timer_begin_) / CLOCKS_PER_SEC : timer_begin_ - timer_end_;
}