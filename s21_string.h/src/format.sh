clang-format -style=Google -n *.c *.h funcs/* tests/*
cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h funcs/*.c tests/*.c tests*.h

