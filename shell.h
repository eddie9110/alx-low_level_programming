#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>


#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - A singly linked list.
 * @num: Number field.
 * @str: String.
 * @next: Points to the next node.
 */

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} str_lst;

/**
 *struct passinfo - Has arguements to pass into a function.
 *@arg: String generated from getline containing arguements.
 *@argv: Array of strings generated from arguements.
 *@path: Full path for the current command.
 *@argc: Argument count.
 *@line_count: Error count.
 *@err_num: Error code.
 *@linecount_flag: Input line count.
 *@fname: Program's filename.
 *@env: Local copy of environment variables.
 *@environ: Modified copy of environ.
 *@history: History node.
 *@alias: Alias node.
 *@env_changed: Checks to see if environ was changed.
 *@status: Status of the last executed command.
 *@cmd_buf: Address of pointer if chaining.
 *@cmd_buf_type: CMD_type ||, &&, ;.
 *@readfd: File descriptor from which to read line input.
 *@histcount: History line count.
 */

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	int status;
	int linecount_flag;
	unsigned int line_count;
	int err_num;
	char *fname;
	str_lst *history;
	str_lst *alias;
	str_lst *env;
	int env_changed;
	char **environ;

	char **cmd_buf;
	int readfd;
	int cmd_buf_type;
	int histcount;
} pssdinfo;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - Builtin string and related functions.
 *@type: Builtin command flag.
 *@func: Function.
 */

typedef struct builtin
{
	char *type;
	int (*func)(pssdinfo *);
} bltin_tble;

int hsh(pssdinfo *, char **);
int cstfndbuiltin(pssdinfo *);
void cstfndcmd(pssdinfo *);
void cstforkcmd(pssdinfo *);

int cst_iscmd(pssdinfo *, char *);
char *cst_dupchars(char *, int, int);
char *cst_findpath(pssdinfo *, char *, char *);

int loophsh(char **);

void cstaputs(char *);
int cstaputchar(char);
int cstputfd(char c, int fd);
int cstputinfd(char *str, int fd);

int cststr_len(char *);
int cststr_cmp(char *, char *);
char *starts_with(const char *, const char *);
char *cststr_cat(char *, char *);

char *cststr_cpy(char *, char *);
char *cststr_dup(const char *);
void cst_puts(char *);
int myput_char(char);

char *cststrn_cpy(char *, char *, int);
char *cststrn_cat(char *, char *, int);
char *cststr_char(char *, char);

char **cststrtow(char *, char *);
char **cststrtow2(char *, char);

char *cstsetmem(char *, char, unsigned int);
void cstfree(char **);
void *cstrealloc(void *, unsigned int, unsigned int);

int bfreeptr(void **);

int cst_intrctive(pssdinfo *);
int cstisdelim(char, char *);
int cst_isalpha(int);
int cst_atoi(char *);

int cst_erratoi(char *);
void cstprinterror(pssdinfo *, char *);
int cstprintdec(int, int);
char *cstconvnumb(long int, int, int);
void cstrmvcomments(char *);

int cstmyexit(pssdinfo *);
int cstmycd(pssdinfo *);
int cstmyhelp(pssdinfo *);

int cst_histlst(pssdinfo *);
int cst_alias(pssdinfo *);

ssize_t cst_getinput(pssdinfo *);
int cstget_line(pssdinfo *, char **, size_t *);
void sigintHandler(int);

void clear_info(pssdinfo *);
void set_info(pssdinfo *, char **);
void free_info(pssdinfo *, int);

char *cstget_env(pssdinfo *, const char *);
int cstprt_env(pssdinfo *);
int cstset_env(pssdinfo *);
int cstunset_env(pssdinfo *);
int cstgenenv_list(pssdinfo *);

char **cstget_environ(pssdinfo *);
int cstunset_environ(pssdinfo *, char *);
int cstsetenviron(pssdinfo *, char *, char *);

char *cstgethistfile(pssdinfo *info);
int cstwritehist(pssdinfo *info);
int cstreadhist(pssdinfo *info);
int cst_buildhistlist(pssdinfo *info, char *buf, int linecount);
int cstrenmbhist(pssdinfo *info);

str_lst *cstaddnode(str_lst **, const char *, int);
str_lst *cstaddnodeatend(str_lst **, const char *, int);
size_t cst_printliststr(const str_lst *);
int cstdeletenodeatindx(str_lst **, unsigned int);
void cstfreelst(str_lst **);

size_t cst_listlen(const str_lst *);
char **cst_listtostrings(str_lst *);
size_t cst_printlist(const str_lst *);
str_lst *cst_ndestartswith(str_lst *, char *, char);
ssize_t cst_getnodeindx(str_lst *, str_lst *);

int is_chain(pssdinfo *, char *, size_t *);
void check_chain(pssdinfo *, char *, size_t *, size_t, size_t);
int replace_alias(pssdinfo *);
int replace_vars(pssdinfo *);
int replace_string(char **, char *);

#endif
