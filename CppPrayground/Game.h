#pragma once

#include <string>

class Game {
public:
	static void Notify(std::string msg, bool mustConfirm = false);
};

