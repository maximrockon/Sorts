#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <ctime>

class Stopwatch
{
private:
	bool isStarted = false;
	bool isEnded = false;
	clock_t start_;
	clock_t end_;
public:
	void start();
	void end();
	double show();
};

#endif
