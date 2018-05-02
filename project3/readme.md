Makefile
----------------------------------------

| 指令         | 動作           |
| ------------ | -------------- |
|$ make        | 編譯 parser    |
|$ make test   | 自動測試       |
|$ make clean  | 清除程式、log  |

./p_program/        測試用的P program。

./ans_token_log/    經過手動檢查的答案

./test_token_log/   自動測試產生的log

Makefile 預設使用 flex、yacc，可以用 $ make LEX=lex YACC=yacc 來更換

$ make test 有額外使用到 diff、printf，diff可以透過 $ make DIFF=diff 來更換

在系上的 linux 工作站試過。

lex.l
----------------------------------------

因為 project1 的 scanner 我寫的時候把keyword用"|"給結合起來，return token 的時候會有點小麻煩，所以我決定採用提供的答案。

基本上修改的地方就是加上引用 yacc 的 header `#include "y.tab.h"`

在 match token 後 return ID 給 yacc，這個 ID 由 y.tab.h 定義。

另外我有新增 Opt_P 這個 pseudo comment，要提供給 yacc.y 決定要不要輸出 debug log，預設是關閉。

yacc.y
----------------------------------------

我寫了個 macro，輸出log用的，要用 do {} while(0) 包起來，原因上網查很容易找到。

%token [ID] 就是用來定義要辨識的 ID，定義好後就 lex.l 就可以 return ID，可以在 y.tab.h 裡面看到是怎麼定義的，基本上是由數字表示。

%start program 表示將 program 視為 start symbol。

定義 BNF 的區塊我分為：name、constant data、type part、list、expression、node。

為了讓之後產生AST的時候我可能會方便點，才會這樣分，node 部分的東西就會將地下 match 的資料放到這個 node 下面，list 則是用串接的方式(也可以轉換成 node，不過以 expression 為例的話做成 list 後續排序法來表示會容易做很多)，從 debug log 來看就很容易知道大概會長怎樣了。

基本上建議從 start symbol 來開始看，放在最後一個，因為我習慣要用到的東西先定義好。

parser
----------------------------------------

使用方式：　./parser [filename]
