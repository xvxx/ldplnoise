LDPLNOISE
=========

LDPL extension with linenoise support. linenoise is a lite version of readline, originally at https://github.com/antirez/linenoise.

This version wraps https://github.com/yhirose/cpp-linenoise.

Only works on the `extensions` branch of https://github.com/dvkt/ldpl

Usage
-----

For a readline-like prompt, first set the `RL-PROMPT` text variable to a prompt something then call the `RL-ACCEPT` subroutine:

    STORE "> " IN RL-PROMPT
    CALL RL-ACCEPT

What the user inputs will be put into the `RL-INPUT` text variable:

    DISPLAY "You entered: " RL-INPUT CRLF

To save and load history, first set the `RL-HISTORY-FILE` text  variable to the location of your history file, then use the  `RL-LOAD-HISTORY` and `RL-SAVE-HISTORY` subroutines:

    STORE "history.txt" IN RL-HISTORY
    RL-LOAD-HISTORY

    # code that calls RL-ACCEPT
    
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

    RL-PROMPT
    RL-INPUT
    RL-HISTORY-FILE

Subroutines:

    RL-ACCEPT
    RL-LOAD-HISTORY
    RL-SAVE-HISTORY
