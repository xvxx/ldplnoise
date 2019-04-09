#include <iostream>
#include <string>
#include "linenoise.hpp"

using std::string;

string RL_INPUT;         // RL-INPUT
string RL_PROMPT;        // RL-PROMPT
string RL_HISTORY_FILE;  // RL-HISTORY-FILE

void RL_LOAD_HISTORY() 
{
    linenoise::LoadHistory(RL_HISTORY_FILE.c_str());
}

void RL_SAVE_HISTORY()
{
    linenoise::SaveHistory(RL_HISTORY_FILE.c_str());
}

void RL_ADD_HISTORY()
{
    linenoise::AddHistory(RL_INPUT.c_str());
}

void RL_ACCEPT() 
{
    if(RL_PROMPT.empty()) RL_PROMPT = "> ";
    linenoise::SetHistoryMaxLen(100);
    linenoise::Readline(RL_PROMPT.c_str(), RL_INPUT);
}
