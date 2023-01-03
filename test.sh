#!/bin/bash

main() {
    valgrind ./push_swap 1 2 3
    valgrind ./push_swap 3 2 1
    valgrind ./push_swap 5 4 3 2 1
    valgrind ./push_swap -1 1
    valgrind ./push_swap 0 0
    # ./push_swap "3 2 1" #未実装
}

main;
exit 0