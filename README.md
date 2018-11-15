# 0x15. C - Simple Shell 
## Masu Shell
<p align="center"><img src ="https://petco.scene7.com/is/image/PETCO/849430-center-3?$ProductDetail-large$" /></p>

## Authors
[Martin Smith](http://www.github.com/Ostoyae) [![alt text][1.1]][1]

[Susan Su](http://www.github.com/suhearsawho) [![alt text][1.1]][2]

## Table of Context

* [Introduction](#introduction)
* [Usage](#usage)
* [Description](#description)
* [Features](#features)
* [Modules](#modules)
* [Acknowledgments](#acknowledgments)


## Introduction

"Simple shell" is a project to recreate shell in C using what we've learned up until now. While we can use a fair amount of pre-existing functions [^1] to build our shell most basic function-- such as strlen, strdup, etcetera -- have to be written by us, there are optional tasks to rewrite them.

Including our abilities to write a program in "C" this project is also meant to test our collaborative prowess and work ethic. As such we must work within the same GitHub repository, where communication is critical to avoid merge conflicts. Also, whiteboard and peer programming are also strongly encouraged and from our experience has worked wonders for our progress.

---

## Usage

### Basic usage

using masu shell in interactive mode.
```
user@ubuntu:~ $ ./masu 
masu:~ $
masu:~ $ ls -a
.   .bash_history  .bashrc     .lesshst  .profile  .sudo_as_admin_successful  .viminfo  Betty     work
..  .bash_logout   .gitconfig  .local    .ssh      .test_file.swp             .vimrc    dotfiles
masu@:~ $ cd work
masu@:~/work $ 
```

using masu shell in non-interactive.
```
user@ubuntu:~ $ echo "/bin/ls -a" | ./masu
.   .bash_history  .bashrc     .lesshst  .profile  .sudo_as_admin_successful  .viminfo  Betty     work
..  .bash_logout   .gitconfig  .local    .ssh      .test_file.swp             .vimrc    dotfiles
user@ubuntu:~ $ 
```
[_page top_](#0x15-c---simple-shell)

---
## Description

[^1]: list
<details>
<summary>List of allowed functions and system calls</summary>

* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* fork (man 2 fork)
* free (man 3 free)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)
* _exit (man 2 _exit)
* isatty (man 3 isatty)
* fflush (man 3 fflush)

</details>


[_page top_](#0x15-c---simple-shell)

---
## Features

[_page top_](#0x15-c---simple-shell)

---

## Modules

Files | Description
--- | ---
[main.c](./main.c) | Main entry point for the masu shell.
[shell.h](./file) | header file for the shell containing all the prototypes for the shell.
[prompt_util.c](./prompt_util.c) | Functions that that directly related to the shell basic functionality.
[string.c](./string.c) | Functions that are for related to processing strings for the shell.
[file](./file) | me
[file](./file) | me
[file](./file) | me
[_strtok.c](./_strtok.c) | TODO
[_getline.c](./_getline.c) | TODO
  

[_page top_](#0x15-c---simple-shell)

---

## Acknowledgments


[_page top_](#0x15-c---simple-shell)

---
<!-- icon with padding -->
[1.1]: http://i.imgur.com/tXSoThF.png (twitter icon with padding)

<!-- links -->
[1]: https://twitter.com/_Ostoyae
[2]: https://twitter.com/sususayshello
