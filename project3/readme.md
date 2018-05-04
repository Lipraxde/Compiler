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

配合yylval來回傳常數資訊。

還有修改125~137行，為了在即使不print token的tag時也可以取得字串常數。

yacc.y
----------------------------------------

原本我寫的list是right-recursive的，將之改為left-recursive，因為一邊parse一邊push的順序會造成些小問題。

為了使用$$、$n符號，要定義symbol的type，譬如：`%type <value>   int_const`，可以定義那些type則可使用`%union`來提供。

當parser遇到一個symbol時，會push這個symbol的name到stack裡面去。

當parser遇到一個type時，會使用add_type()提供。

當parser遇到一個dimension時，會使用add_dim()增加目前type的維度。

當parser可以確認symbol的kind時，會盡快使用supply_kind()提供kind的資訊。

當parser可以確認symbol的type時，會盡快使用supply_type()提供type資訊。

當parser進入一個新的scope時，使用next_level()增加level。

當parser離開一個scope時，使用exit_level()減少level。

在parser要提供任意資訊給stack裡的symbol前，都要先呼叫相應的construct。(symbol在使用push_ident()時自動產生，目前只有attribute、type兩種construct)

stack.c stack.h
----------------------------------------

提供stack的功能。

```c
struct stack
{
    struct stack_instance   *_inst;
    int    (*push)(struct stack *self, void *p);       // Push void *
    void * (*pop)(struct stack *self);                 // Pop void *
    int    (*init_iter)(struct stack *self, int n);    // Iterator initialize, negative mean iterate form tail to head
    void * (*iterator)(struct stack *self);            // Iterator will return void * and setup next iterate.
};

struct stack *stack_create(void);
int stack_delete(struct stack *self, int (*destroyer)(void *));
```

使用stack_create()來取得stack object，裡面具有push、pop、init_iter、iterator四個基本功能。

所使用的

iterator用來依序輸出stack裡的資料，使用前要呼叫init_iter來初始化iterator，傳入-1表示從尾到頭，0表示從頭到尾，n、-n表示先忽略n筆資料。

stack_delete()用來釋放

###### TODO: 應該將destoryer()放在\_inst裡面，由註冊的方式來提供，不過由於並沒有要完整的模擬物件導向語言的寫法，所以其實不太需要特意使用這種方式。


----------------------------------------


TODO Memory管理問題
----------------------------------------

原則上應該要保持自己malloc的自己釋放，唯獨stack目前較為特殊，可以傳入一個destroyer來釋放void \*指到的記憶體，因當初想的時候不夠健全。

在symbol裡面附加的type、attribute資訊並沒有被釋放：

因為有可能使用variable list宣告變數的時候指到同一個type object，無法確認何時可以free，要修改的話應該在提供type的時候使用複製的方式。

而attribute則是目前還沒想好怎麼做，亦不確定該不該有兩個symbol得attribute指向同一個attribute object。

由於parser並沒有要成為一個常駐程式，過程中有些memory leak無傷大雅。

parser
----------------------------------------

使用方式：　./parser [filename]
