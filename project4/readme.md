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

###### 有些地方使用strdup()這種複製的手段，是因為從lex傳上來的yytext再讀到下一個token時會添加進多的字元。

stack.c stack.h
----------------------------------------

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

iterator用來依序輸出stack裡的資料，使用前要呼叫init_iter來初始化iterator，傳入-1表示從尾到頭，0表示從頭到尾，n、-n表示先忽略n筆資料。

stack_delete()用來釋放。

###### TODO: 應該將destoryer()放在_inst裡面，由註冊的方式來提供，不過由於並沒有要完整的模擬物件導向語言的寫法，所以其實不太需要特意使用這種方式，將來如果想更進一步OO化的話再想想辦法，可能就先弄一個一般化的struct {_inst; destoryer}吧。

type.c type.h
----------------------------------------

```c
const char *type_void;
const char *type_inte;
const char *type_real;
const char *type_bool;
const char *type_stri;

struct type_instance;

struct type
{
    struct type_instance *_inst;
    int             (*add_type)(struct type *self, const char *type);
    int             (*add_dime)(struct type *self, int upper, int lower);
    const char *    (*get_type)(struct type *self);
};

struct type * type_create(void);
int type_delete(void *self);
```

使用type_create()來取得type object，裡面具有add_type、add_dime、get_type三個基本功能。

add_type可以用來幫這個type物件添加這是void、integer、real、boolean、string的資訊。

add_dime的內部管理一個stack，將這個dimension的upper、lower值傳入並管理。

get_type會輸出一段字串，代表目前這個type的文字，須注意程式並沒有確認這個type是否應該具有dimension。(譬如說void \[n\])

type_delete()用來釋放。

###### TODO: 由於在可能要提供更強的type功能，譬如說定位出var\[123\]的位置，可能需要提供更強的功能。

attribute.c attribute.h
----------------------------------------

```c
#define attr_type 0
#define attr_code 1
#define attr_inte 2
#define attr_real 3
#define attr_bool 4
#define attr_stri 5

#define attr_field_arg  0x0001
#define attr_field_val  0x0002

struct attr_instance;

struct attr
{
    struct attr_instance *_inst;
    int             (*add_attr)(struct attr *self, void *target, int type);
    const char *    (*get_attr)(struct attr *self, int field);
};

struct attr * attr_create(void);
int attr_delete(void *self);
```

使用attr_create()來取得type object，裡面具有add_attr、get_attr三個基本功能。

實際上內部是一個stack，在add_attr時相當於將一筆資料與它的類型資訊push進stack。

get_attr則是依field來決定要將哪些資訊從stack裡面撈出來轉成文字。

attr_delete()用來釋放。

###### TODO: 實際上應該是由add_attr的時候從target裡面找出將其輸出成文字的function的，不過並沒有要完全像OO一樣，所以沒這樣做

symbol.c symbol.h
----------------------------------------

```c
const char *kind_prog;
const char *kind_func;
const char *kind_para;
const char *kind_vari;
const char *kind_forv;
const char *kind_cons;

struct symbol_instance;

struct symbol
{
    struct symbol_instance *_inst;
    int             (*set_name)(struct symbol *self, const char *name); // Max length = 32
    const char *    (*get_name)(struct symbol *self);
    int             (*set_level)(struct symbol *self, int n);
    int             (*get_level)(struct symbol *self);
    int             (*set_kind)(struct symbol *self, const char *kind);
    const char *    (*get_kind)(struct symbol *self);
    int             (*set_type)(struct symbol *self, struct type *type);
    const char *    (*get_type)(struct symbol *self);
    int             (*set_attr)(struct symbol *self, struct attr *attr);
    const char *    (*get_attr)(struct symbol *self);
};

struct symbol * symbol_create(void);
int symbol_delete(void *self);
```

使用symbol_create()來取得symbol object，有如一系set、get基本功能：

set_name較為特殊，會採用複製的方式，理論上不用複製的也行，只是為了限制identifier可識別長度32，方便處理而使用的。

symbol_delete()用來釋放。

main.c main.h
----------------------------------------

```c
int push_ident(const char *name);
int supply_kind(const char *kind);

int construct_attr(void);
int add_cons_attr(void *target, const char *type, int is_negative);
int supply_cons_attr(void);
int supply_func_attr(void); /* Add parameter attribute to function in add_type. */

int construct_type(void);
int add_type(const char *str);
int add_dim(int upper, int lower);
int supply_type(void);

int next_level(void);
int exit_level(void);
void dump_symbol(void);
```

主程式所在位置，提供function給yacc呼叫，內部維護一個symbol table的stack。

function的argument attribute會在supply_type的時候自動蒐集，不用另外呼叫方法。(依symbol的kind是不是parameter來決定)

TODO: Memory管理問題、OO化
----------------------------------------

原則上應該要保持自己malloc的自己釋放，唯獨stack目前較為特殊，可以傳入一個destroyer來釋放void \*指到的記憶體，因當初想的時候不夠健全。

在symbol裡面附加的type、attribute資訊並沒有被釋放：

因為有可能使用variable list宣告變數的時候指到同一個type object，無法確認何時可以free，要修改的話應該在提供type的時候使用複製的方式。

而attribute則是目前還沒想好怎麼做，亦不確定該不該有兩個symbol得attribute指向同一個attribute object。

由於parser並沒有要成為一個常駐程式，過程中有些memory leak無傷大雅。

要OO化的話最終就是建立一個general object，裡面提供相應的_inst、to_string、destoryer等等，然後依不同物件提供不同的create方式與它自己的struct宣告，使用時配合轉型使用。不過目前這樣也算是堪用了。

parser
----------------------------------------

使用方式：　./parser [filename]
