#!/bin/bash

# Màu sắc (tự định nghĩa, không cần colors.sh)
BLUE=$(tput setaf 4)
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
RESET=$(tput sgr0)
BOLD=$(tput bold)

rendu_dir="../src"

# Kiểm tra thư mục rendu có tồn tại không
if [ ! -d "$rendu_dir" ]; then
    echo "${RED}${BOLD}FAIL: Directory $rendu_dir does not exist${RESET}"
    exit 1
fi

# Tìm file .c
c_files=$(find "$rendu_dir" -name "*.c" -type f)
if [ -z "$c_files" ]; then
    echo "${RED}${BOLD}FAIL: No .c files found in $rendu_dir${RESET}"
    exit 1
fi

# Compile chương trình
echo "${BLUE}Compiling n_queens program...${RESET}"
gcc -Wall -Werror -Wextra -o n_queens_test $c_files 2>/dev/null
if [ $? -ne 0 ]; then
    echo "${RED}${BOLD}FAIL: Compilation error${RESET}"
    exit 1
fi

# -----------------------------
# TEST CASES
# -----------------------------

# Test 1: n=2 -> 0 solutions
echo "${BLUE}Testing n=2...${RESET}"
./n_queens_test 2 > output2.txt 2>/dev/null
lines=$(wc -l < output2.txt)
if [ $lines -ne 0 ]; then
    echo "${RED}${BOLD}FAIL: n=2 should have 0 solutions, got $lines${RESET}"
    cat output2.txt
    exit 1
fi

# Test 2: n=3 -> 0 solutions
echo "${BLUE}Testing n=3...${RESET}"
./n_queens_test 3 > output3.txt 2>/dev/null
lines=$(wc -l < output3.txt)
if [ $lines -ne 0 ]; then
    echo "${RED}${BOLD}FAIL: n=3 should have 0 solutions, got $lines${RESET}"
    cat output3.txt
    exit 1
fi

# Test 3: n=4 -> exactly 2 solutions
echo "${BLUE}Testing n=4...${RESET}"
./n_queens_test 4 > output4.txt 2>/dev/null
lines=$(wc -l < output4.txt)
if [ $lines -ne 2 ]; then
    echo "${RED}${BOLD}FAIL: n=4 should have 2 solutions, got $lines${RESET}"
    cat output4.txt
    exit 1
fi

# Validate known n=4 solutions
sort output4.txt > sorted4.txt
echo -e "1 3 0 2\n2 0 3 1" | sort > expected4.txt
if ! diff -q sorted4.txt expected4.txt >/dev/null; then
    echo "${RED}${BOLD}FAIL: n=4 solutions don't match expected${RESET}"
    echo "Expected:"
    cat expected4.txt
    echo "Got:"
    cat sorted4.txt
    exit 1
fi

# Test 4: n=8 -> 92 solutions
echo "${BLUE}Testing n=8...${RESET}"
./n_queens_test 8 > output8.txt 2>/dev/null
lines=$(wc -l < output8.txt)
if [ $lines -ne 92 ]; then
    echo "${RED}${BOLD}FAIL: n=8 should have 92 solutions, got $lines${RESET}"
    exit 1
fi

# Test 5: n=0 -> 0 solutions
echo "${BLUE}Testing n=0...${RESET}"
./n_queens_test 0 > output0.txt 2>/dev/null
lines=$(wc -l < output0.txt)
if [ $lines -ne 0 ]; then
    echo "${RED}${BOLD}FAIL: n=0 should have 0 solutions, got $lines${RESET}"
    exit 1
fi

# Test 6: wrong number of arguments
echo "${BLUE}Testing wrong number of arguments...${RESET}"
./n_queens_test > temp.txt 2>&1
if [ $? -eq 0 ]; then
    echo "${RED}${BOLD}FAIL: Should fail with no arguments${RESET}"
    exit 1
fi

./n_queens_test 4 5 > temp.txt 2>&1
if [ $? -eq 0 ]; then
    echo "${RED}${BOLD}FAIL: Should fail with too many arguments${RESET}"
    exit 1
fi

# -----------------------------
# Nếu qua hết test
# -----------------------------
echo "${GREEN}${BOLD}PASSED 🎉${RESET}"

# Cleanup
rm -f n_queens_test output*.txt temp.txt sorted4.txt expected4.txt
exit 0
