#include <iostream>
#include <string>
#include "linenoise.hpp"

using std::string;

extern string VAR_RLr_UINPUT;           // RL-INPUT
extern string VAR_RLr_UPROMPT;          // RL-PROMPT
extern string VAR_RLr_UHISTORYr_UFILE;  // RL-HISTORY-FILE

#define RL_HISTORY_FILE VAR_RLr_UHISTORYr_UFILE
#define RL_INPUT        VAR_RLr_UINPUT
#define RL_PROMPT       VAR_RLr_UPROMPT
#define RL_ACCEPT       SUBPR_RLr_UACCEPT
#define RL_SAVE_HISTORY SUBPR_RLr_USAVEr_UHISTORY
#define RL_LOAD_HISTORY SUBPR_RLr_ULOADr_UHISTORY
#define RL_ADD_HISTORY  SUBPR_RLr_UADDr_UHISTORY

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
