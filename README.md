# push_swap
42 Tokyoの課題です。課題の説明については，後程追加します。

# 要件

- a, b という名前の 二つのスタックを使用する
- プログラムが実行された最初の段階で
  - スタック a はランダムな個数の整数を**重複なく**含む。
  - スタック b は空の状態である。
  
- プログラムの目的は， スタック a に含まれる整数を，昇順にソートすることである。この時， 以下の操作のみが使える

sa
sb
ss
pa
pb
ra
rb
rr
rra
rrb
rrr

- "push_swap" program

提出するプログラムは以下の条件を満たす必要がある

- Makefile は ソースコードをコンパイルし， relink を起こしてはならない。
- グローバル変数を使ってはならない
- 実行可能ファイルの名前は`push_swap` で，プログラムを実行する際にコマンドライン引数が整数の列の形式で与えられる。**この時，最初の引数は，スタックの先頭にくるようにしなければならないことに注意。**
- プログラムはスタック a をソートするために使った， 操作列を表示しなければならない
- その際操作列の表示は '\n'で区切られる必要がある
- プログラムの目的は， ソートを最小の操作列で実現することである。したがって， プログラムの操作列は評価の際に最低限の基準を満たすか確認される
- もちろん，スタック a が操作列によって適切にソートされていない場合も， 評価は 0 になる
- パラメータが適切な形式でない場合は，プログラムは何も出力せずにプロンプトに制御を戻す
- エラーが生じた場合は， "Error\n"という文字列を標準エラーに出力する
- 有効でない入力の例: intではない数が含まれる, int の最大値よりも大きい数が含まれる， または/かつ, 重複した数が含まれる