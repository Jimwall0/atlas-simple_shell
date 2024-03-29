# Simple Shell

This is a two week project, for "Atlas School," where we built our own version of the BASH shell. For this school project we are expected to learn about:

- How a shell works
- How to create proccesses and what are proccess IDs
- How to suspend proccesses until another finishes
- What are environment variables and how to manipulate them
- How does the shell use the `PATH` to find programs
- How to execute another program

With the addition of these new topics and skills there came new challenges that we had to work around.  Some of those challenges were how to split the interactive and non-interactive modes, how to utilize the `PATH` in our own shell, learning more about a good README page, and more.  We also needed to learn about system calls and how to use them and input additional arguments into them from our own shell to work.
<br>In this README you will read how to utilize it and it's functionality.

## The Shell

Our version of shell is based off of the BASH shell.  With that in mind we utilize very similar commands to BASH.  Our shell contains an interactive mode, where users may input commands after running `./hsh`, and a non-interactive mode, which takes commands from a command-line prompt.

## How to start the shell

To start the shell, please clone into our repository, then run the following code:
```
user@user:~/atlas-simple_shell$ ./hsh  
($)
```
`($)` indicates you are running in **Interactive Mode**.

## Interactive Mode

In this mode a user may input commands to navigate the shell.

## Non-Interactive Mode

From within a command-line prompt (e.g. wsl, linux, ubuntu, etc.) the user may run:
```
user@user:~/atlas-simple_shell$ echo "<command>" | ./hsh
```
where \<command> is the user input to be run. Command must be in quotes.

## Commands Table

| Command | Description | Help Text |
| ------- | ----------- | --------- |
| `ls` | List information about the files | Enter command "ls" to list information on files |
| `exit` | Exits ineractive mode of the shell | Enter command "exit" to exit shell |

## How to use the Shell

Here are the different examples of commands that can be used.  Please refer to "Commands Table" for a full list of compatible commands and more info.<br><br>
`ls` - displays files and directories within cwd.<br>
|Flags|description|
|---|---|
|`-a`|does not ignore entries starting with "."|
|`-l`|displays long listing format|
|`-S`|sort by size|
|`-t`|sort by time, newest first|
```
($) ls
AUTHORS README.md freearray.c hsh main.c main.h man_1_simple_shell user_input.c
($) ls -a
. .. .git .gitignore AUTHORS README.md freearray.c hsh main.c main.h man_1_simple_shell user_input.c
```
`exit` - exits interactive mode

## Authors
See authors [here](./AUTHORS)