LDPLNOISE
=========

LDPL extension with linenoise support. linenoise is a lite version of readline, originally at https://github.com/antirez/linenoise.

This version wraps https://github.com/yhirose/cpp-linenoise.

Only works on the `extensions` branch of https://github.com/dvkt/ldpl

Usage
-----

For readline-like behavior, first set the `RL-PROMPT` text variable to a prompt then call the `RL-ACCEPT` subroutine:

    STORE "Type something: " IN RL-PROMPT
    CALL RL-ACCEPT

What the user inputs will be put into the `RL-INPUT` text variable:

    DISPLAY "You entered: " RL-INPUT CRLF

To save and load history, first set the `RL-HISTORY-FILE` text  variable to the location of your history file, then use the  `RL-LOAD-HISTORY` and `RL-SAVE-HISTORY` subroutines to load/save the history and the `RL-ADD-HISTORY` subroutine to add the value of `RL-INPUT` to the current history:

    STORE "history.txt" IN RL-HISTORY
    RL-LOAD-HISTORY
    # code that calls RL-ACCEPT
    RL-ADD-HISTORY
    # then, before you exit:
    RL-SAVE-HISTORY


Example
-------

    git clone https://github.com/dvkt/ldplnoise 
    cd ldplnoise
    make test

This should launch you into a basic prompt that echos what you type and remembers you history for that session. To exit, just type  "quit" or "exit", submit an empty line, or hit Ctrl-C.

Check out `test.lsc` to see an example of using the extension.

LDPL API
--------

Variables:

    RL-PROMPT is TEXT
    RL-INPUT is TEXT
    RL-HISTORY-FILE is TEXT

Subroutines:

    RL-ACCEPT
    RL-LOAD-HISTORY
    RL-SAVE-HISTORY
    RL-ADD-HISTORY
