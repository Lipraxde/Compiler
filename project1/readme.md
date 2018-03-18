Makefile
----------------------------------------

| 指令         | 動作           |
| ------------ | -------------- |
|$ make        | 編譯 scanner   |
|$ make test   | 自動測試       |
|$ make clean  | 清除程式、log  |

./p_program/        測試用的，只用來檢查 token有沒有切對

./ans_token_log/    經過手動檢查的答案

./test_token_log/   自動測試產生的log

Makefile 預設使用 flex，可以用 $ make LEX=lex 來更換

$ make test 有額外使用到 diff、printf，diff可以透過 $ make DIFF=diff 來更換

在系上的 linux 工作站試過。

lex.l
----------------------------------------

scanner 的程式碼

修改過 token() 這個 macor，改為：

`#define token(fmt, ...)    {LIST; if (Opt_T) printf("<" fmt ">\n", ##__VA_ARGS__);}`

有些　Compiler 不支援 ##，出現錯誤的話把它拿掉。

可以辨識 delimiters、keyword、identifiers、string、integer、floating-point、scientfic notations、comments、pseudocomments。

scanner
----------------------------------------

使用方式：　./scanner [filename]
