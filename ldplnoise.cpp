#include <iostream>
#include "ldplnoise.h"
#include "linenoise.hpp"

void RL_LOAD_HISTORY() 
{
    linenoise::LoadHistory(RL_HISTORY_FILE.c_str());
}

void RL_SAVE_HISTORY()
{
    linenoise::SaveHistory(RL_HISTORY_FILE.c_str());
}

void RL_ACCEPT() 
{
    linenoise::SetHistoryMaxLen(100);
    linenoise::SetMultiLine(true);

    linenoise::Readline(RL_PROMPT.c_str(), RL_INPUT);
    linenoise::AddHistory(RL_INPUT.c_str());
}
