#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>
#include "tokenizer.h"
#include <fcntl.h>

/* Convenience macro to silence compiler warnings about unused function parameters. */
#define unused __attribute__((unused))

/* Whether the shell is connected to an actual terminal or not. */
bool shell_is_interactive;

/* File descriptor for the shell input */
int shell_terminal;

/* Terminal mode settings for the shell */
struct termios shell_tmodes;

/* Process group id for the shell */
pid_t shell_pgid;

int cmd_exit(struct tokens *tokens);
int cmd_help(struct tokens *tokens);
int cmd_pwd(struct tokens *tokens);
int cmd_cd(struct tokens *tokens);

/* Built-in command functions take token array (see parse.h) and return int */
typedef int cmd_fun_t(struct tokens *tokens);

/* Built-in command struct and lookup table */
typedef struct fun_desc {
  cmd_fun_t *fun;
  char *cmd;
  char *doc;
} fun_desc_t;

fun_desc_t cmd_table[] = {
  {cmd_help, "?", "show this help menu"},
  {cmd_exit, "exit", "exit the command shell"},
  {cmd_pwd, "pwd", "print current working directory"},
  {cmd_cd, "cd", "open the directory"},
};

/* Prints a helpful description for the given command */
int cmd_help(unused struct tokens *tokens) {
  for (unsigned int i = 0; i < sizeof(cmd_table) / sizeof(fun_desc_t); i++)
    printf("%s - %s\n", cmd_table[i].cmd, cmd_table[i].doc);
  return 1;
}

/* Exits this shell */
int cmd_exit(unused struct tokens *tokens) {
  exit(0);
}

/*pwd Command*/
int cmd_pwd(unused struct tokens *tokens) {
  char buff[256];
  getcwd(buff, sizeof(buff));
  printf("%s\n", buff);
  return 0;
}

/*cd Command*/
int cmd_cd(unused struct tokens *tokens) {
  int ret;
  ret = chdir(tokens_get_token(tokens, 1));
  if (ret != 0) {
    printf("Invalid directory! Please try again!\n");
  }
  return 0;
}

/* Looks up the built-in command, if it exists. */
int lookup(char cmd[]) {
  for (unsigned int i = 0; i < sizeof(cmd_table) / sizeof(fun_desc_t); i++)
    if (cmd && (strcmp(cmd_table[i].cmd, cmd) == 0))
      return i;
  return -1;
}

/* Execute command */
int exe_command(unused struct tokens *tokens) {  
  int newfd;
  char *cmd[256];
  unsigned int i;
  for (i = 0; i < tokens_get_length(tokens); i++) {
    char *token; 
    token = tokens_get_token(tokens, i);
    if (strcmp(">", token)== 0) {
      newfd = open(tokens_get_token(tokens, i+1), O_CREAT|O_TRUNC|O_WRONLY, 0644);
      dup2(newfd, 1);
      break;
    }
    else if (strcmp("<", token)== 0) {
      newfd = open(tokens_get_token(tokens, i+1), O_CREAT|O_RDONLY);
      dup2(newfd, 0);
      break;
    }
    cmd[i] = token;
  }
  cmd[i] = 0;
  execvp(cmd[0], cmd);
  perror(cmd[0]);
  exit(1);
}

/* Intialization procedures for this shell */
void init_shell() {
  /* Our shell is connected to standard input. */
  shell_terminal = STDIN_FILENO;

  /* Check if we are running interactively */
  shell_is_interactive = isatty(shell_terminal);

  if (shell_is_interactive) {
    /* If the shell is not currently in the foreground, we must pause the shell until it becomes a
     * foreground process. We use SIGTTIN to pause the shell. When the shell gets moved to the
     * foreground, we'll receive a SIGCONT. */
    while (tcgetpgrp(shell_terminal) != (shell_pgid = getpgrp()))
      kill(-shell_pgid, SIGTTIN);

    /* Saves the shell's process id */
    shell_pgid = getpid();

    /* Take control of the terminal */
    tcsetpgrp(shell_terminal, shell_pgid);

    /* Save the current termios to a variable, so it can be restored later. */
    tcgetattr(shell_terminal, &shell_tmodes);
  }
}

int main(unused int argc, unused char *argv[]) {
  init_shell();
  //signal(SIGINT, SIG_IGN);

  static char line[4096];
  int line_num = 0;

  /* Please only print shell prompts when standard input is not a tty */
  if (shell_is_interactive)
    fprintf(stdout, "%d: ", line_num);

  while (fgets(line, 4096, stdin)) {
    /* Split our line into words. */
    struct tokens *tokens = tokenize(line);

    /* Find which built-in function to run. */
    int fundex = lookup(tokens_get_token(tokens, 0));
    signal(SIGINT, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);  
    signal(SIGTSTP, SIG_IGN);
    if (fundex >= 0) {
      cmd_table[fundex].fun(tokens);
    } else {
      /* REPLACE this to run commands as programs. */
      pid_t pid = fork();
      if (pid == 0) {
        signal(SIGINT, SIG_DFL);
        signal(SIGTTOU, SIG_DFL);
        signal(SIGTTIN, SIG_DFL);
        signal(SIGQUIT, SIG_DFL);
        signal(SIGTSTP, SIG_DFL);
        pid_t program_pid = getpid();
        setpgid(program_pid, program_pid);
        while (tcgetpgrp(shell_terminal) != getpgrp())
          kill(-shell_pgid, SIGTTIN);
        exe_command(tokens);
      }
      else {
        setpgid(pid, pid);
        tcsetpgrp(0, pid);
        wait(NULL);
        tcsetpgrp(0, getpgrp());
        tcsetattr(shell_terminal, TCSANOW, &shell_tmodes);  
        printf("back!\n");
      }  
    }

    if (shell_is_interactive)
      /* Please only print shell prompts when standard input is not a tty */
      fprintf(stdout, "%d: ", ++line_num);

    /* Clean up memory */
    tokens_destroy(tokens);
  }

  return 0;
}
