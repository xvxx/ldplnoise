#include <string>

using std::string;

extern string VAR_RLr_UINPUT;
extern string VAR_RLr_UPROMPT;
void SUBPR_RLr_UACCEPT();

#define rl_input  VAR_RLr_UINPUT
#define rl_prompt VAR_RLr_UPROMPT
#define rl_accept SUBPR_RLr_UACCEPT

