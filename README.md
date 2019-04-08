LDPLNOISE
=========

LDPL extension with linenoise support. linenoise is a lite version of readline, originally at https://github.com/antirez/linenoise.

This version wraps https://github.com/yhirose/cpp-linenoise.

Only works on the `extensions` branch of https://github.com/dvkt/ldpl

Usage
-----

Any LDPL program using this extension must declare these three variables, even if you're not going to use them:

    DATA:
    RL-INPUT is TEXT
    RL-PROMPT is TEXT
    RL-HISTORY-FILE is TEXT

- `RL-INPUT` will be filled with the user's input after prompting them.
- `RL-PROMPT` will default to `> ` and allows you to customize the prompt shown to users. Optional.
- `RL-HISTORY-FILE` can be set by you to the location of the history file for this program. Optional.

To actually use the library, call the `RL-ACCEPT` subroutine to prompt the user for input:

    STORE "Type something: " IN RL-PROMPT
    CALL EXTERNAL RL-ACCEPT

What the user inputs will be put into the `RL-INPUT` text variable:

    DISPLAY "You entered: " RL-INPUT CRLF

So the above will print:

    Type something: <user types Dave and presses >
    You entered: Dave

To record history for a single session, call `RL-ADD-HISTORY` after calling `RL-ACCEPT`. The content of the `RL-INPUT` variable will be added to the history.

To persist history across sessions, you need to save and load a history file. To do so, first set the `RL-HISTORY-FILE` text  variable to the location of your history file, then use the  `RL-LOAD-HISTORY` and `RL-SAVE-HISTORY` subroutines to load/save the history when your LDPL program begins and ends:

    # ...program starts...
    STORE "history.txt" IN RL-HISTORY
    CALL EXTERNAL RL-LOAD-HISTORY
    # ...main program code...
    CALL EXTERNAL RL-ACCEPT
    CALL EXTERNAL RL-ADD-HISTORY
    # ...before the program exits...
    CALL EXTERNAL RL-SAVE-HISTORY

Setup
-----

The easy way to include LDPLNOISE in your project is to just clone this repo into it and tell the the `ldpl` compiler where to find `ldplnoise.cpp`:

    cd my-great-ldpl-project
    git clone https://github.com/dvkt/ldplnoise
    ldpl -i=ldplnoise/ldplnoise.cpp my-code.ldpl
    ./my-code-bin

Example
-------

    git clone https://github.com/dvkt/ldplnoise
    cd ldplnoise
    make test

This should launch you into a basic prompt that echos what you type and remembers you history for that session. To exit, just type  "quit" or "exit", submit an empty line, or hit Ctrl-C.

Check out `test.ldpl` to see an example of using the extension.

LDPL API
--------

Variables:

    RL-PROMPT is TEXT        # prompt shown to user
    RL-INPUT is TEXT         # the user's input after a RL-ACCEPT
    RL-HISTORY-FILE is TEXT  # path to history file

Subroutines:

    RL-ACCEPT                # main readline()-like prompt function. 
    RL-LOAD-HISTORY          # load command history from RL-HISTORY-FILE 
    RL-SAVE-HISTORY          # save command history to RL-HISTORY-FFILE
    RL-ADD-HISTORY           # add content of RL-INPUT to the history
                             # should be called after RL-ACCEPT
