#include "Stopwatch.h"

void Stopwatch::start()
{
	start_ = clock();
	isStarted = true;
	isEnded = false;
}

void Stopwatch::end()
{
	end_ = clock();
	isEnded = true;
}

double Stopwatch::show()
{
	if (!isStarted || !isEnded)
	{
		return -1;
	}
	else
	{
		return ((double)(end_ - start_)) / CLOCKS_PER_SEC;
	}
}