#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"
#include <ctime>

class Timer {
private:
	sf::Clock clock;
	bool timerEnd = true;
	int timegoes = 0;
public:
	void StartTimer(int time, int delay)
	{
		timerEnd = false;
		while (timerEnd == false) {
			sf::Time now = clock.getElapsedTime();
			if (now.asMilliseconds() > delay) {
				timegoes += delay;
				if (timegoes < time) {
					clock.restart();
				}
				else {
					timerEnd = true;
				}
			}
		}
	}

	bool IstimerEnd() {
		return timerEnd;
	}
};
