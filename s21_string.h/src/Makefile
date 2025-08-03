CC=gcc
CFLAGS=-Wall -Wextra -Werror -lm -std=c11
TEST_FLAGS=-lcheck -lm -lpthread -lsubunit
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

SRC_DIR=.
TEST_DIR=tests
BUILD_DIR=.
REPORT_DIR=report
FUNCS_DIR = funcs/

SOURCES=$(shell find $(SRC_DIR) -name "*.c" -not -path "./$(TEST_DIR)/*")
OBJECTS=$(SOURCES:.c=.o)

TEST_SOURCES=$(shell find $(TEST_DIR) -name "*.c")
TEST_OBJECTS=$(TEST_SOURCES:.c=.o)

.PHONY: all rebuild clean 

all: s21_string.a

s21_string.a: $(OBJECTS)
	ar rcs s21_string.a $(OBJECTS)
	ranlib s21_string.a

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $< -o $@

test: $(TEST_OBJECTS) s21_string.a
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(TEST_OBJECTS) s21_string.a $(TEST_FLAGS) -o test
	./test

gcov_report:
	mkdir -p $(REPORT_DIR)
	lcov -t "s21_string_test" -o $(REPORT_DIR)/s21_string_test.info -c -d .
	genhtml -o $(REPORT_DIR) $(REPORT_DIR)/s21_string_test.info
	
clean:
	rm -rf *.o
	rm -rf *.deb
	rm -rf s21_string.a
	rm -rf test
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf $(TEST_DIR)/*.o
	rm -rf $(TEST_DIR)/*.gcda
	rm -rf $(TEST_DIR)/*.gcno
	rm -rf $(OBJECTS) $(FUNCS_DIR)*.o
	rm -rf $(OBJECTS) $(FUNCS_DIR)*.gcno
	rm -rf $(OBJECTS) $(FUNCS_DIR)*.gcda

clean_report:
	rm -rf $(REPORT_DIR)

format:
	chmod +x *
	./format.sh

rebuild: format clean all

retest: rebuild test