/* for c */

#ifndef __CPP2C_POLYMORPHISM_H__
#define __CPP2C_POLYMORPHISM_H__

#define printFunc(fname) printf("%-60s | ", (const char*)fname)

typedef struct TextFormatter TextFormatter;
typedef struct TextFormatter_funcs TextFormatter_funcs;

typedef void (*ptr_dtor_TextFormatter)(TextFormatter*const tf);
typedef void (*ptr_TextFormatter_print_tc)(const void *const this, const char* const text); 

struct TextFormatter_funcs
{
	ptr_dtor_TextFormatter dtor;
	ptr_TextFormatter_print_tc print;		
};

struct TextFormatter
{	
	TextFormatter_funcs tff;	
};


void TextFormatter_TextFormatter_t(TextFormatter*const tf);
void _TextFormatter_TextFormatter_t(TextFormatter*const tf );


/*  end of TextFormator  */


/* DefaultTextFormatter */
typedef struct DefaultTextFormatter DefaultTextFormatter;
typedef struct Ider Ider;


struct Ider
{
	int Ider_next_id;
};

void Ider_Ider_i(Ider*const ider);
void _Ider_Ider_i(Ider*const ider);

struct DefaultTextFormatter
{
	TextFormatter tf;
	Ider ider;
	const int id;	
	
};

static int DefaultTextFormatter_Ider_getId();


void DefaultTextFormatter_DefaultTextFormatter_d(DefaultTextFormatter*const this);
void DefaultTextFormatter_DefaultTextFormatter(DefaultTextFormatter*const this, const DefaultTextFormatter*const other);
void DefaultTextFormatter_operator_as(DefaultTextFormatter*const this, const DefaultTextFormatter* const other);
void _DefaultTextFormatter(DefaultTextFormatter*const this);
void DefaultTextFormatter_print(const void *const this, const char* const text);

DefaultTextFormatter* generateFormatterArray();

/*  end of DefaultTextFormatter  */

/* PrePostFixer */

typedef struct PrePostFixer PrePostFixer;
typedef struct PrePostFixer_funcs PrePostFixer_funcs;

typedef void (*ptr_PrePostFixer_print_lc)(long num, char symbol);
typedef char (*ptr_PrePostFixer_getDefaultSymbol_p)(const PrePostFixer *const this);

#define PrePostFixer_print_lc(this, long_num, char_symbol) \
    printFunc("[PrePostFixer::print(long, char)]");\
    printf("-->\n");\
    if (symbol) \
    	print_num(num, symbol);\
    else\
        print_num(num);
	
#define PrePostFixer_getDefaultSymbol_p(this)\
	'\0'

#define PrePostFixer_getPrefix(this)\
	this->pre
	
#define PrePostFixer_getPostfix(this)\
	this->post
	
#define PrePostFixer_print_num_pl(this, num)\
    printFunc("[PrePostFixer::print_num(long)]");\
        printf("%s%ld%s\n", this->pre, num, this->post);
    

#define PrePostFixer_print_num_plc(this, long_num, char_symbol)\
    printFunc("[PrePostFixer::print_num(long, char)]");\
    printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);
        
struct PrePostFixer_funcs
{
	DefaultTextFormatter dtf;
	ptr_PrePostFixer_print_lc pplc;
	ptr_PrePostFixer_getDefaultSymbol_p pgdp;
};


struct PrePostFixer
{
	PrePostFixer_funcs ppff;
	
    const char* pre;
    const char* post;
};

void PrePostFixer_PrePostFixer_pcc(PrePostFixer* const this, const char* prefix, const char* postfix);
void _PrePostFixer_PrePostFixer_p(PrePostFixer*const this);
void PrePostFixer_print_c(const void *const this, const char* text);



/* end of PrePostFixer */

/* PrePostDollarFixer  */

#define PrePostDollarFixer_DEFAULT_SYMBOL '$'

#define getDefaultSymbol()\
	PrePostDollarFixer_DEFAULT_SYMBOL

typedef struct
{
	PrePostFixer ppf;
	
} PrePostDollarFixer;

void PrePostDollarFixer_PrePostDollarFixer_pcc(PrePostDollarFixer* const this, const char* prefix, const char* postfix);
PrePostDollarFixer* PrePostDollarFixer_PrePostDollarFixer_pp(PrePostDollarFixer *const this, const PrePostDollarFixer* const other);
void _PrePostDollarFixer_PrePostDollarFixer_p(PrePostDollarFixer* const this);

void PrePostDollarFixer_print_pic(const PrePostDollarFixer* const this, int num, char symbol);
void PrePostDollarFixer_print_pi(const PrePostDollarFixer* const this, int num);

void PrePostDollarFixer_print_plc(const PrePostDollarFixer* const this, long num, char symbol);
void PrePostDollarFixer_print_pl(const PrePostDollarFixer* const this, long num);

void PrePostDollarFixer_print_pdc(const PrePostDollarFixer* const this, double num, char symbol);
void PrePostDollarFixer_print_pd(const PrePostDollarFixer* const this, double num);


/*end of PrePostDollarFixer  */

/* PrePostHashFixer */

#define PrePostHashFixer_DEFAULT_SYMBOL '#'

#define PrePostHashFixer_print_pdc(this, num, symbol)\
    printFunc("[PrePostHashFixer::print(double, char)]");\
    printf("%s[%c%.*F]%s\n",  PrePostFixer_getPrefix((&(this->ppdf.ppf))), symbol, this->precision, num, PrePostFixer_getPostfix((&(this->ppdf.ppf))));
    
    
#define PrePostHashFixer_getDefaultSymbol_p(this)\
	PrePostHashFixer_DEFAULT_SYMBOL
	

    
typedef struct
{
	PrePostDollarFixer ppdf;
	
	int precision;
	
} PrePostHashFixer;

void PrePostHashFixer_PrePostHashFixer_pi(PrePostHashFixer* const this, int prc);
void PrePostHashFixer_PrePostHashFixer_p(PrePostHashFixer* const this);
void _PrePostHashFixer_PrePostHashFixer_p(PrePostHashFixer* const this);


void PrePostHashFixer_print_pic(const PrePostHashFixer*const this, int num, char symbol);
void PrePostHashFixer_print_pi(const PrePostHashFixer*const this, int num);
void PrePostHashFixer_print_plc(const PrePostHashFixer* const this, long num, char symbol);
void PrePostHashFixer_print_pl(const PrePostHashFixer* const this, long num);
/*void PrePostHashFixer_print_pdc(const PrePostHashFixer* const this, double num, char symbol = DEFAULT_SYMBOL);*/ /* inline */
/*char PrePostHashFixer_getDefaultSymbol_p(this) const;*/ /* inline */


/* end of PrePostHashFixer */

/* PrePostFloatDollarFixer */

#define PrePostFloatDollarFixer_DEFAULT_SYMBOL '@'

#define PrePostFloatDollarFixer_getDefaultSymbol(this)\
	PrePostFloatDollarFixer_DEFAULT_SYMBOL

typedef struct
{
	PrePostDollarFixer ppdf;
	
	
} PrePostFloatDollarFixer;


void PrePostFloatDollarFixer_PrePostFloatDollarFixer_pcc(PrePostFloatDollarFixer* const this, const char* prefix, const char* postfix);
void _PrePostFloatDollarFixer_PrePostFloatDollarFixer_p(PrePostFloatDollarFixer* const this);
void PrePostFloatDollarFixer_print_pf(const PrePostFloatDollarFixer* const this, float num);
void PrePostFloatDollarFixer_print_pfc(const PrePostFloatDollarFixer* const this, float num, char symbol);

/*char getDefaultSymbol() const;*/ /* inline */

/* end of PrePostFloatDollarFixer */

/* PrePostChecker */


typedef struct
{
	PrePostFloatDollarFixer ppfdf;
} PrePostChecker; 


void PrePostChecker_PrePostChecker_p(PrePostChecker* const this);
void _PrePostChecker_PrePostChecker_p(PrePostChecker* const this);
    
void PrePostChecker_printThisSymbolUsingFunc_p(const PrePostChecker*const this);
void PrePostChecker_printThisSymbolDirectly_p(const PrePostChecker* const this);    
void PrePostChecker_printDollarSymbolByCastUsingFunc_p(const PrePostChecker*const this);
void PrePostChecker_printDollarSymbolByScopeUsingFunc_p(const PrePostChecker* const this);
void PrePostChecker_printDollarSymbolByCastDirectly_p(const PrePostChecker*const this);
void PrePostChecker_printDollarSymbolByScopeDirectly_p(const PrePostChecker* const this);

/* end of PrePostChecker */

#endif /* __CPP2C_POLYMORPHISM_H__ */










