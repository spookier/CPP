#!/bin/bash

# Path to your compiled PmergeMe binary
BIN=./PmergeMe

echo "===== Basic small test ====="
$BIN 3 5 9 7 4

echo -e "\n===== All same numbers ====="
$BIN 7 7 7 7 7

echo -e "\n===== Invalid input (negative number) ====="
$BIN 1 2 -3 4

echo -e "\n===== Invalid input (not a number) ====="
$BIN 1 2 abcd 3

echo -e "\n===== Invalid input (zero) ====="
$BIN 1 0 3

echo -e "\n===== Edge case: 1 value ====="
$BIN 42

echo -e "\n===== Edge case: no values ====="
$BIN

echo -e "\n===== Large test: 3000 shuffled values ====="
ARGS=$(shuf -i 1-100000 -n 3000 | tr '\n' ' ')
$BIN $ARGS

echo -e "\n===== Already sorted ====="
$BIN 1 2 3 4 5 6 7 8 9 10

echo -e "\n===== Reverse sorted ====="
$BIN 10 9 8 7 6 5 4 3 2 1
