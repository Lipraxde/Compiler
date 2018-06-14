Makefile
----------------------------------------

| 指令         | 動作           |
| ------------ | -------------- |
|$ make        | 編譯 parser    |
|$ make clean  | 清除程式       |

Makefile 預設使用 flex、yacc，可以用 $ make LEX=lex YACC=yacc 來更換

$ make test 有額外使用到 diff、printf，diff可以透過 $ make DIFF=diff 來更換

在系上的 linux 工作站試過。

lex.l
----------------------------------------

修改一點點pseudocomments

目前有：

```
int Opt_S = 0;				/* list source code option */
int Opt_T = 0;				/* list token option */
int Opt_P = 0;				/* praser debug option */
int Opt_D = 0;				/* dump symbol table option */
int Opt_A = 0;				/* dump AST option */
```

Pseudo comment基本上沒什麼變動。

main.c main.h
----------------------------------------

對variable新增var_addr，來記錄它在local的位置。

err.c err.h
----------------------------------------

修正前一個作業的bug。

1. 忘了確認function宣告的頭尾
2. function invole的參數比較數量的邏輯錯誤

codegen.c codegen.h
----------------------------------------

做code generation，將語意分析完成的AST輸出成java bytecode。

沒有array、string variable的功能，不過function可以回傳string，不單單只有print可以用
string，string assignment因為沒有string variable，所以應該是沒有做出來。

多個compound statement照理來說是可以運作的，因為我計算symbol table的深度來分配local
variable的位置，即使還沒到或是已經離開那個compound statement，還是有分配位置給它(因為
一開始就要分配好的關係，不知道有沒有中途調整的方法)。

基本上沒有做足防護措施，假設經過語意分析後的AST是OK的。

parser
----------------------------------------

使用方式：　./parser [filename].p

產生 [filename].j 檔案，交由jasmin編譯成class檔。
