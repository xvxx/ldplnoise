#include <string>

using std::string;

extern string VAR_RLr_UINPUT;           // RL-INPUT
extern string VAR_RLr_UPROMPT;          // RL-PROMPT
extern string VAR_RLr_UHISTORYr_UFILE;  // RL-HISTORY-FILE
void SUBPR_RLr_UACCEPT();               // RL-ACCEPT
void SUBPR_RLr_USAVEr_UHISTORY();       // RL-SAVE-HISTORY
void SUBPR_RLr_ULOADr_UHISTORY();       // RL-LOAD-HISTORY

#define RL_HISTORY_FILE VAR_RLr_UHISTORYr_UFILE
#define RL_INPUT        VAR_RLr_UINPUT
#define RL_PROMPT       VAR_RLr_UPROMPT
#define RL_ACCEPT       SUBPR_RLr_UACCEPT
#define RL_SAVE_HISTORY SUBPR_RLr_USAVEr_UHISTORY
#define RL_LOAD_HISTORY SUBPR_RLr_ULOADr_UHISTORY

