#!/bin/bash

main() {
    echo "-------------- system test ---------------"
    # valgrind ./push_swap 1 2 3
    # valgrind ./push_swap 3 2 1
    # ./push_swap 5 4 3 2 1 # valgrind と実行すると無限ループ！！！！
    # valgrind ./push_swap -1 1
    # valgrind ./push_swap 0 0
    # ./push_swap 4 3 2 1   # valgrind と 実行すると無限ループ
    # ./push_swap "3 2 1" #未実装
    # ./push_swap 4 -100   3 50 55 100
    ./push_swap 3 4 5 2 1
    echo "-------------- finish system test ----------------"
}

main;
exit 0
