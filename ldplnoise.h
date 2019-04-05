#include <string>

using std::string;

extern string VAR_RLr_UINPUT;  // RL-INPUT
extern string VAR_RLr_UPROMPT; // RL-PROMPT
void SUBPR_RLr_UACCEPT();      // RL-ACCEPT

#define RL_INPUT  VAR_RLr_UINPUT
#define RL_PROMPT VAR_RLr_UPROMPT
#define RL_ACCEPT SUBPR_RLr_UACCEPT

