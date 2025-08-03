#include "s21_grep.h"

int main(int argc, char **argv) {
  run_grep(argc, argv);
  return 0;
}

void run_grep(int argc, char **argv) {
  if (argc < 2) return;

  GrepOptions config = {0};
  char *pattern = NULL;
  int opt_index = parse_options(argc, argv, &config, &pattern);

  for (int i = opt_index; i < argc; i++) {
    process_file(argv[i], config, pattern);
  }

  free(pattern);
}

int parse_options(int argc, char **argv, GrepOptions *config, char **pattern) {
  int opt;
  while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (opt) {
      case 'e':
        set_pattern_from_option(config, pattern, optarg);
        break;
      case 'i':
        config->i_flag = true;
        break;
      case 'v':
        config->v_flag = true;
        break;
      case 'c':
        config->c_flag = true;
        break;
      case 'l':
        config->l_flag = true;
        break;
      case 'n':
        config->n_flag = true;
        break;
      case 'h':
        config->h_flag = true;
        break;
      case 's':
        config->s_flag = true;
        break;
      case 'f':
        set_pattern_from_file(config, pattern, optarg);
        break;
      case 'o':
        config->o_flag = true;
        break;
      default:
        break;
    }
  }

  if (!config->e_flag && !config->f_flag) {
    create_pattern(pattern, argv[optind]);
    optind++;
  }

  setup_config(config, argc);
  return optind;
}

void process_file(const char *path, GrepOptions config, const char *pattern) {
  FILE *file = fopen(path, "r");
  if (!file) {
    if (!config.s_flag) fprintf(stderr, ERROR_MSG, path);
    return;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, file)) != -1) {
    config.line_number++;
    if (line[read - 1] == '\n') line[read - 1] = '\0';
    handle_match_output(line, &config, pattern, path);
  }

  print_final_stats(config, path);
  free(line);
  fclose(file);
}

void handle_match_output(const char *line, GrepOptions *config,
                         const char *pattern, const char *path) {
  regex_t regex;
  if (regcomp(&regex, pattern, config->i_flag ? REG_ICASE : REG_EXTENDED) ==
      0) {
    bool is_match = (regexec(&regex, line, 0, NULL, 0) == 0);

    if (is_match ^ config->v_flag) {
      config->match_count++;
      if (!config->c_flag && !config->l_flag) {
        if (config->file_count > 1 && !config->h_flag) printf("%s:", path);
        if (config->n_flag) printf("%d:", config->line_number);

        if (!config->o_flag) {
          printf("%s\n", line);
        } else {
          print_matched_parts(regex, line);
        }
      }
    }
    regfree(&regex);
  }
}

void print_matched_parts(regex_t regex, const char *line) {
  regmatch_t match;
  const char *ptr = line;

  while (regexec(&regex, ptr, 1, &match, 0) == 0) {
    for (int i = match.rm_so; i < match.rm_eo; i++) {
      putchar(ptr[i]);
    }
    putchar('\n');
    ptr += match.rm_eo;
  }
}

void print_final_stats(GrepOptions config, const char *path) {
  if (config.c_flag) {
    if (config.l_flag) {
      printf(config.file_count > 1 ? "%s:1\n" : "1\n", path);
    } else {
      if (config.file_count > 1) printf("%s:", path);
      printf("%d\n", config.match_count);
    }
  }
  if (config.l_flag && config.match_count) printf("%s\n", path);
}

void set_pattern_from_option(GrepOptions *config, char **pattern,
                             const char *optarg) {
  if (!config->e_flag && !config->f_flag) {
    create_pattern(pattern, optarg);
    config->e_flag = true;
  } else {
    append_pattern(pattern, optarg);
  }
}

void set_pattern_from_file(GrepOptions *config, char **pattern,
                           const char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    if (!config->s_flag) fprintf(stderr, ERROR_MSG, filename);
    return;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, file)) != -1) {
    if (line[read - 1] == '\n') line[read - 1] = '\0';

    if (!config->e_flag && !config->f_flag) {
      create_pattern(pattern, line);
      config->f_flag = true;
    } else {
      append_pattern(pattern, line);
    }
  }

  free(line);
  fclose(file);
}

void create_pattern(char **pattern, const char *text) {
  *pattern = strdup(text);
  if (!*pattern) {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }
}

void append_pattern(char **pattern, const char *text) {
  size_t new_len = strlen(*pattern) + strlen(text) + 2;
  char *new_pattern = realloc(*pattern, new_len);
  if (!new_pattern) {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }
  *pattern = new_pattern;
  strcat(strcat(*pattern, "|"), text);
}

void setup_config(GrepOptions *config, int argc) {
  if (config->o_flag && (config->l_flag || config->v_flag || config->c_flag)) {
    config->o_flag = false;
  }
  config->file_count = argc - optind;
}