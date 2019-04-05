#include <iostream>
#include "ldplnoise.h"
#include "linenoise.hpp"

using std::cout;
using std::endl;

void rl_accept() {
    linenoise::SetHistoryMaxLen(100);
    linenoise::SetMultiLine(true);

    linenoise::Readline(rl_prompt.c_str(), rl_input);
    linenoise::AddHistory(rl_input.c_str());
}
