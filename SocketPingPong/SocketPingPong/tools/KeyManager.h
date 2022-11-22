#pragma once
#include <windows.h>
class KeyManager {
private:
	KeyManager() {}
	~KeyManager() {}
public:
	static KeyManager* Instance() {
		static KeyManager keymanager;
		return &keymanager;
	}
	void init() {
	}
	void Update() {
		/*if (GetAsyncKeyState(VK_LEFT) & 0x8000) {

		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {

		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {

		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {

		}*/
	}
};