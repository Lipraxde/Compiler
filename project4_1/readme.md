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

S、T、P基本上沒什麼變動。

D選項的symbol table輸出改成只會輸出最基本的資訊(level、name、kind)，因為把project3整
個重寫過了。

A選項會把AST畫出來。

yacc.y
----------------------------------------

在重寫project3的時候順便把ASP建立起來，之前因為yacc用的不熟所以沒有特意去建AST，到了這
次作業後發覺有AST可以保留更多資訊、取得資訊更容易。

一邊parser一邊做error decantation有點麻煩，會讓yacc裡面的東西變得不太好閱讀，寫的時候
也不是很好寫，所以我就做成把整個檔案parser一遍後才做處理。不過寫一寫後覺得要改成一邊parser
一邊弄好像也不是那麼難了。

main.c main.h
----------------------------------------

主程式所在位置，包含symbol table與走訪AST。

err.c err.h
----------------------------------------

偵測語義錯誤用的，main.c裡面要適時的呼叫err.h提供的function。

parser
----------------------------------------

使用方式：　./parser [filename]
