#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int b;            // Number non-blank lines
  int e;            // Display $ at end of each line
  int n;            // Number all output lines
  int s;            // Squeeze multiple adjacent blank lines
  int t;            // Display TAB characters as ^I
  int v;            // Show non-printing characters
  int newLine;      // Flag for new line
  int counterB;     // Counter for blank lines
  int counterS;     // Counter for squeezed lines
  int emptyLine;    // Flag for empty line
  int numberFiles;  // Number of files to process
} options;

void s21_cat_programm(int argc, char **argv);
int scanOptions(int argc, char **argv, options *config);
void processFile(FILE *file, options *config);
void handleSpecialChars(char sym, options *config);
void handleLineNumbering(char sym, options *config);
void handleBlankLines(char sym, options *config);

#endif  // SRC_CAT_S21_CAT_H_