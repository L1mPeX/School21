#ifndef S21_GREP_H
#define S21_GREP_H

#define _POSIX_C_SOURCE 200809L

#include <getopt.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ERROR_MSG "s21_grep: %s: No such file or directory\n"
#define BUFFER_SIZE 256
#define MAX_NESTING_LEVEL 4

typedef struct {
  bool e_flag;
  bool i_flag;
  bool v_flag;
  bool c_flag;
  bool l_flag;
  bool n_flag;
  bool h_flag;
  bool s_flag;
  bool f_flag;
  bool o_flag;
  int file_count;
  int line_number;
  int match_count;
} GrepOptions;

// Main function declaration
int main(int argc, char **argv);

// Other function declarations
void run_grep(int argc, char **argv);
int parse_options(int argc, char **argv, GrepOptions *config, char **pattern);
void process_file(const char *path, GrepOptions config, const char *pattern);
void handle_match_output(const char *line, GrepOptions *config,
                         const char *pattern, const char *path);
void print_final_stats(GrepOptions config, const char *path);
void print_matched_parts(regex_t regex, const char *line);
void set_pattern_from_option(GrepOptions *config, char **pattern,
                             const char *optarg);
void set_pattern_from_file(GrepOptions *config, char **pattern,
                           const char *filename);
void create_pattern(char **pattern, const char *text);
void append_pattern(char **pattern, const char *text);
void setup_config(GrepOptions *config, int argc);

#endif  // S21_GREP_H