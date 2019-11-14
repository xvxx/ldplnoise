#include <iostream>
#include "linenoise.hpp"
#include "ldpl-types.h"

using std::string;

ldpl_text RL_INPUT;         // RL-INPUT
ldpl_text RL_PROMPT;        // RL-PROMPT
ldpl_text RL_HISTORY_FILE;  // RL-HISTORY-FILE

#define CSTR(txt) txt.str_rep().c_str()

void RL_LOAD_HISTORY() 
{
    linenoise::LoadHistory(CSTR(RL_HISTORY_FILE));
}

void RL_SAVE_HISTORY()
{
    linenoise::SaveHistory(CSTR(RL_HISTORY_FILE));
}

void RL_ADD_HISTORY()
{
    linenoise::AddHistory(CSTR(RL_INPUT));
}

void RL_ACCEPT() 
{
    if(RL_PROMPT.empty()) RL_PROMPT = "> ";
    linenoise::SetHistoryMaxLen(100);
    string input = RL_INPUT.str_rep();
    linenoise::Readline(CSTR(RL_PROMPT), input);
    RL_INPUT = input;
}
