#include <iostream>
#include "ldplnoise.h"
#include "linenoise.hpp"

using std::cout;
using std::endl;

void RL_ACCEPT() {
    linenoise::SetHistoryMaxLen(100);
    linenoise::SetMultiLine(true);

    linenoise::Readline(RL_PROMPT.c_str(), RL_INPUT);
    linenoise::AddHistory(RL_INPUT.c_str());
}
