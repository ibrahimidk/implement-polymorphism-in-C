#include "cpp2c_polymorphism_defs.h"
#include<stdio.h>
#include<stdlib.h>

void TextFormatter_TextFormatter_t(TextFormatter*const tf) 
{
	tf->tff.dtor = _TextFormatter_TextFormatter_t;
}
void _TextFormatter_TextFormatter_t(TextFormatter*const tf ) {}



/* DefaultTextFormatter */

static int Ider_next_id = 0;

static int DefaultTextFormatter_Ider_getId()
{
	return (Ider_next_id)++;
}



void DefaultTextFormatter_DefaultTextFormatter_d(DefaultTextFormatter*const this)
{
	TextFormatter_TextFormatter_t(&this->tf);
	this->tf.tff.print = DefaultTextFormatter_print;
	int* i = (int*)&this->id;
	*i = DefaultTextFormatter_Ider_getId(); 
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}

void DefaultTextFormatter_DefaultTextFormatter(DefaultTextFormatter*const this, const DefaultTextFormatter*const other)
{
	this->tf = other->tf;
	*(int*)&this->id = other->id;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);
}

void DefaultTextFormatter_operator_as(DefaultTextFormatter*const this, const DefaultTextFormatter* const other)
{
	this->tf = other->tf;
	*(int*)&this->id = other->id;
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, this->id);
}

void _DefaultTextFormatter(DefaultTextFormatter*const this)
{
	_TextFormatter_TextFormatter_t(&this->tf);
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
}

void DefaultTextFormatter_print(const void *const this, const char* const text)
{
    printFunc("[DefaultTextFormatter::print(const char*)]");    
    printf("%s\n", text);
}

DefaultTextFormatter* generateFormatterArray()
{
	DefaultTextFormatter *tmp = malloc(sizeof(DefaultTextFormatter) * 3);
	DefaultTextFormatter_DefaultTextFormatter_d(&tmp[0]);
	DefaultTextFormatter_DefaultTextFormatter_d(&tmp[1]);
	DefaultTextFormatter_DefaultTextFormatter_d(&tmp[2]);
	
	return tmp;
	
}


/**/


void PrePostFixer_PrePostFixer_pcc(PrePostFixer* const this, const char* prefix, const char* postfix)
{
	DefaultTextFormatter_DefaultTextFormatter_d(&this->ppff.dtf);
	this->ppff.dtf.tf.tff.print = PrePostFixer_print_c;
	this->pre = prefix;
	this->post = postfix;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}

void _PrePostFixer_PrePostFixer_p(PrePostFixer*const this)
{

	_DefaultTextFormatter(&this->ppff.dtf);
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}

void PrePostFixer_print_c(const void *const this, const char* text)
{
    printFunc("[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", ((PrePostFixer*)this)->pre, text, ((PrePostFixer*)this)->post);
}


/* PrePostDollarFixer */

/*PrePostDollarFixer_DEFAULT_SYMBOL = '$';*/
void PrePostDollarFixer_PrePostDollarFixer_pcc(PrePostDollarFixer* const this, const char* prefix, const char* postfix)
{
	PrePostFixer_PrePostFixer_pcc(&(this->ppf), prefix, postfix);
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", PrePostFixer_getPrefix((&(this->ppf))), PrePostFixer_getPostfix((&(this->ppf))));
}

PrePostDollarFixer* PrePostDollarFixer_PrePostDollarFixer_pp(PrePostDollarFixer *const this, const PrePostDollarFixer* const other)
{	
	
	DefaultTextFormatter_DefaultTextFormatter_d(&this->ppf.ppff.dtf);
	this->ppf.ppff.dtf.tf.tff.print = PrePostFixer_print_c;
	this->ppf.pre = other->ppf.pre;
	this->ppf.post = other->ppf.post;
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n",  PrePostFixer_getPrefix((&(this->ppf))), PrePostFixer_getPostfix((&(this->ppf))));
	return this;
}

void _PrePostDollarFixer_PrePostDollarFixer_p(PrePostDollarFixer* const this)
{
	_PrePostFixer_PrePostFixer_p(&(this->ppf));
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", PrePostFixer_getPrefix((&(this->ppf))), PrePostFixer_getPostfix((&(this->ppf))));
}

void PrePostDollarFixer_print_pic(const PrePostDollarFixer* const this, int num, char symbol)
{
    printFunc("[PrePostDollarFixer::print(int, char)]"); 
    printf("-->\n");

    PrePostDollarFixer_print_plc(this, (long)(num), symbol);
}
void PrePostDollarFixer_print_pi(const PrePostDollarFixer* const this, int num)
{
    printFunc("[PrePostDollarFixer::print(int, char)]"); 
    printf("-->\n");

    PrePostDollarFixer_print_plc(this, (long)(num), PrePostDollarFixer_DEFAULT_SYMBOL);

}

void PrePostDollarFixer_print_plc(const PrePostDollarFixer* const this, long num, char symbol )
{
    printFunc("[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");

    PrePostDollarFixer_print_pdc(this, num, symbol);
}

void PrePostDollarFixer_print_pl(const PrePostDollarFixer* const this, long num)
{
    printFunc("[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");

    PrePostDollarFixer_print_pdc(this, num, PrePostDollarFixer_DEFAULT_SYMBOL);
}

void PrePostDollarFixer_print_pdc(const PrePostDollarFixer* const this, double num, char symbol)
{
    printFunc("[PrePostDollarFixer::print(double, char)]"); 
    printf("%s%c%F%s\n", PrePostFixer_getPrefix((&(this->ppf))), symbol, num, PrePostFixer_getPostfix((&(this->ppf))));
}

void PrePostDollarFixer_print_pd(const PrePostDollarFixer* const this, double num)
{
    printFunc("[PrePostDollarFixer::print(double, char)]"); 
    printf("%s%c%F%s\n", PrePostFixer_getPrefix((&(this->ppf))), PrePostDollarFixer_DEFAULT_SYMBOL, num, PrePostFixer_getPostfix((&(this->ppf))));
}




/* PrePostHashFixer */
void PrePostHashFixer_PrePostHashFixer_p(PrePostHashFixer* const this)
{
	PrePostFixer_PrePostFixer_pcc( &(this->ppdf.ppf), "===> ", " <===");
	this->precision = 4;
	
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", PrePostFixer_getPrefix((&(this->ppdf.ppf))),  PrePostFixer_getPostfix((&(this->ppdf.ppf))), this->precision);   

    PrePostHashFixer_print_pdc(this, 9999.9999, PrePostHashFixer_DEFAULT_SYMBOL);
	
}
void PrePostHashFixer_PrePostHashFixer_pi(PrePostHashFixer* const this, int prc)
{
	PrePostFixer_PrePostFixer_pcc( &(this->ppdf.ppf), "===> ", " <===");
	this->precision = prc;
	
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", PrePostFixer_getPrefix((&(this->ppdf.ppf))),  PrePostFixer_getPostfix((&(this->ppdf.ppf))), this->precision);   

    PrePostHashFixer_print_pdc(this, 9999.9999, PrePostHashFixer_DEFAULT_SYMBOL);
	
}

void _PrePostHashFixer_PrePostHashFixer_p(PrePostHashFixer* const this)
{
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", PrePostFixer_getPrefix((&(this->ppdf.ppf))),  PrePostFixer_getPostfix((&(this->ppdf.ppf))));
}

void PrePostHashFixer_print_pic(const PrePostHashFixer*const this, int num, char symbol)
{
    printFunc("[PrePostHashFixer::print(int, char)]"); 
    printf("-->\n");

    PrePostHashFixer_print_pdc(this, (double)num, symbol);
}

void PrePostHashFixer_print_pi(const PrePostHashFixer*const this, int num)
{
    printFunc("[PrePostHashFixer::print(int, char)]"); 
    printf("-->\n");

    PrePostHashFixer_print_pdc(this, (double)num, PrePostHashFixer_DEFAULT_SYMBOL);
}


void PrePostHashFixer_print_plc(const PrePostHashFixer* const this, long num, char symbol)
{
    printFunc("[PrePostHashFixer::print(long, char)]"); 
    printf("-->\n");

    PrePostHashFixer_print_pdc(this, (double)num, symbol);
}


void PrePostHashFixer_print_pl(const PrePostHashFixer* const this, long num)
{
    printFunc("[PrePostHashFixer::print(long, char)]"); 
    printf("-->\n");

    PrePostHashFixer_print_pdc(this, (double)num, PrePostHashFixer_DEFAULT_SYMBOL);
}


/* end of PrePostHashFixer */

/* PrePostFloatDollarFixer */

void PrePostFloatDollarFixer_PrePostFloatDollarFixer_pcc(PrePostFloatDollarFixer* const this, const char* prefix, const char* postfix)
{
	PrePostFixer_PrePostFixer_pcc( &(this->ppdf.ppf), prefix, postfix);
	
	printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n",  PrePostFixer_getPrefix((&(this->ppdf.ppf))),  PrePostFixer_getPostfix((&(this->ppdf.ppf))));
}

void _PrePostFloatDollarFixer_PrePostFloatDollarFixer_p(PrePostFloatDollarFixer* const this)
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", PrePostFixer_getPrefix((&(this->ppdf.ppf))),  PrePostFixer_getPostfix((&(this->ppdf.ppf))));
}

void PrePostFloatDollarFixer_print_pf(const PrePostFloatDollarFixer* const this, float num)
{
    printFunc("[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

    PrePostFloatDollarFixer_print_pfc(this, num, PrePostFloatDollarFixer_DEFAULT_SYMBOL);
}

void PrePostFloatDollarFixer_print_pfc(const PrePostFloatDollarFixer* const this, float num, char symbol)
{
    printFunc("[PrePostFloatDollarFixer::print(float, char)]"); 

    printf("%s%c%.2F%s\n", PrePostFixer_getPrefix((&(this->ppdf.ppf))), symbol, num, PrePostFixer_getPostfix((&(this->ppdf.ppf))));
}

/* end of PrePostFloatDollarFixer */

/* PrePostChecker */


void PrePostChecker_PrePostChecker_p(PrePostChecker* const this)
{
	PrePostFloatDollarFixer_PrePostFloatDollarFixer_pcc(&(this->ppfdf), "[[[[ ", " ]]]]");
	
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", PrePostFixer_getPrefix((&(this->ppfdf.ppdf.ppf))),  PrePostFixer_getPostfix((&(this->ppfdf.ppdf.ppf))));
}

void _PrePostChecker_PrePostChecker_p(PrePostChecker* const this)
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", PrePostFixer_getPrefix((&(this->ppfdf.ppdf.ppf))),  PrePostFixer_getPostfix((&(this->ppfdf.ppdf.ppf))));
}

void PrePostChecker_printThisSymbolUsingFunc_p(const PrePostChecker*const this)
{
    printFunc("[PrePostChecker::printThisSymbolUsingFunc()]");

    printf("Default symbol is %c\n", PrePostFloatDollarFixer_getDefaultSymbol(this->ppfdf));
}

void PrePostChecker_printThisSymbolDirectly_p(const PrePostChecker* const this)
{
    printFunc("[PrePostChecker::printThisSymbolDirectly()]");

    printf("Default symbol is %c\n", PrePostFloatDollarFixer_DEFAULT_SYMBOL);
}

void PrePostChecker_printDollarSymbolByCastUsingFunc_p(const PrePostChecker*const this)
{
    printFunc("[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

    printf("Default symbol is %c\n", getDefaultSymbol());
}

void PrePostChecker_printDollarSymbolByScopeUsingFunc_p(const PrePostChecker* const this)
{
    printFunc("[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

    printf("Default symbol is %c\n", PrePostFloatDollarFixer_getDefaultSymbol(this->ppfdf.ppdf));
}

void PrePostChecker_printDollarSymbolByCastDirectly_p(const PrePostChecker*const this)
{
    printFunc("[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n", PrePostDollarFixer_DEFAULT_SYMBOL);
}

void PrePostChecker_printDollarSymbolByScopeDirectly_p(const PrePostChecker* const this)
{
    printFunc("[PrePostChecker::printDollarSymbolByScopeDirectly()]");

    printf("Default symbol is %c\n",  PrePostDollarFixer_DEFAULT_SYMBOL);
}










