#include "s21_cat.h"

static const char *ERROR_01 = "s21_cat: %s: No such file or directory\n";
static const char *ERROR_02 = "s21_cat: invalid option -- '%c'\n";

int main(int argc, char **argv) {
  s21_cat_programm(argc, argv);
  return 0;
}

void s21_cat_programm(int argc, char **argv) {
  if (argc <= 1) return;

  options config = {0};
  if (!scanOptions(argc, argv, &config)) return;

  for (int x = (argc - config.numberFiles); x < argc; x++) {
    FILE *file = fopen(argv[x], "r");
    if (file == NULL) {
      fprintf(stderr, ERROR_01, argv[x]);
      continue;
    }
    processFile(file, &config);
    fclose(file);
  }
}

int scanOptions(int argc, char **argv, options *config) {
  int indexStartFiles = 1;
  int status = 1;

  for (int x = 1; x < argc && argv[x][0] == '-'; x++) {
    indexStartFiles = x + 1;

    if (!strcmp(argv[x], "-b") || !strcmp(argv[x], "--number-nonblank")) {
      config->b = 1;
      config->n = 0;
    } else if (!strcmp(argv[x], "-s") || !strcmp(argv[x], "--squeeze-blank")) {
      config->s = 1;
    } else if (!strcmp(argv[x], "-n") || !strcmp(argv[x], "--number")) {
      if (!config->b) config->n = 1;
    } else if (!strcmp(argv[x], "-T")) {
      config->t = 1;
    } else if (!strcmp(argv[x], "-v")) {
      config->v = 1;
    } else if (!strcmp(argv[x], "-t")) {
      config->t = 1;
      config->v = 1;
    } else if (!strcmp(argv[x], "-e")) {
      config->e = 1;
      config->v = 1;
    } else if (!strcmp(argv[x], "-E")) {
      config->e = 1;
    } else {
      fprintf(stderr, ERROR_02, argv[x][1]);
      status = 0;
      break;
    }
  }

  config->numberFiles = argc - indexStartFiles;
  return status;
}

void processFile(FILE *file, options *config) {
  char sym;
  while ((sym = getc(file)) != EOF) {
    config->emptyLine = 0;
    handleBlankLines(sym, config);
    handleLineNumbering(sym, config);
    handleSpecialChars(sym, config);

    if (config->emptyLine == 0) {
      printf("%c", sym);
    }
  }
}

void handleBlankLines(char sym, options *config) {
  if (!config->s) return;

  if (config->counterS == 0 && sym == '\n') {
    config->counterS = 1;
  } else if (config->counterS != 0 && sym == '\n') {
    config->counterS++;
    config->emptyLine = 1;
  } else if (config->counterS > 1 && sym != '\n') {
    config->counterS = 0;
    config->e ? printf("$\n") : printf("\n");
    if (config->n) printf("%6d\t", config->n++);
  } else {
    config->counterS = 0;
  }
}

void handleLineNumbering(char sym, options *config) {
  if (!config->n && !config->b) return;

  if (config->newLine && !(config->newLine = 0)) {
    printf("%6d\t", config->n++);
  }
  if (config->n == 1) printf("%6d\t", config->n++);
  if (config->b == 1) printf("%6d\t", config->b++);

  if (sym == '\n') {
    if (config->n && !config->emptyLine) config->newLine = 1;
    if (config->b) config->counterB++;
  }

  if (sym != '\n' && config->counterB && !config->counterS) {
    if (!(config->counterB = 0)) printf("%6d\t", config->b++);
  }
}

void handleSpecialChars(char sym, options *config) {
  if (sym == '\n' && config->e && !config->emptyLine) {
    printf("$");
  }
  if (config->v) {
    if (sym < 32 && sym != 9 && sym != 10) {
      printf("^%c", sym + 64);
    }
    if (sym == 127) {
      printf("^?");
    }
  }
  if (config->t && sym == '\t') {
    printf("^I");
  }
}