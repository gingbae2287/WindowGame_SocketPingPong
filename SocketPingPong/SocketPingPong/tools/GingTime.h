#pragma once
#include <windows.h>
class Time
{
private:
	LARGE_INTEGER curTicks;
	LARGE_INTEGER prevTicks;
	LARGE_INTEGER freq;
public:
		static float deltaTime;
		static Time* Instance() {
			static Time time;
			return &time;
		}
		void Update() {
			QueryPerformanceCounter(&curTicks);
			QueryPerformanceFrequency(&freq);
			deltaTime = (curTicks.QuadPart - prevTicks.QuadPart) / (float)freq.QuadPart;
			prevTicks = curTicks;
		}
private:
	Time() { QueryPerformanceCounter(&curTicks);	prevTicks = curTicks; }
	~Time() {}
};
//