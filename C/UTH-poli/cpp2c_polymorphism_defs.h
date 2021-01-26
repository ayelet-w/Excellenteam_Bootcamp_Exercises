
#ifndef UTH_POLI_CPP2C_POLYMORPHISM_DEFS_H
#define UTH_POLI_CPP2C_POLYMORPHISM_DEFS_H

#include <stdio.h>

/* inline*/
void printFunc(const char* fname);


/* TextFormatter */
typedef struct TextFormatter TextFormatter;

typedef struct TextFormatter_virtualTable
{
    void (*Dtor)(TextFormatter *);

    void (*print)(const TextFormatter * const textFormatter, const char* text);

}TextFormatter_virtualTable;

struct TextFormatter
{
    TextFormatter_virtualTable * textFormatterVirtualTable;

};

void TextFormatterCtor(TextFormatter * const textFormatter);

void TextFormatterDtor_v(TextFormatter * textFormatter);



/* DefaultTextFormatter */

extern  int DefaultTextFormatter_next_id;

typedef struct DefaultTextFormatter
{
    TextFormatter base_TextFormatter;

    int id;

}DefaultTextFormatter;

void DefaultTextFormatterCtor(DefaultTextFormatter * const defaultTextFormatter);

void DefaultTextFormatterCopyCtor(DefaultTextFormatter * const defaultTextFormatter1,const DefaultTextFormatter * const defaultTextFormatter2);

DefaultTextFormatter * DefaultTextFormatter_operator_assingment(DefaultTextFormatter * const defaultTextFormatter1,const DefaultTextFormatter * const defaultTextFormatter2);

void DefaultTextFormatterDtor_v(DefaultTextFormatter * defaultTextFormatter);

void DefaultTextFormatter_print_v(const DefaultTextFormatter * const defaultTextFormatter, const char* text);

DefaultTextFormatter* generateFormatterArray();



/*PrePostFixer */
typedef struct PrePostFixer PrePostFixer;

typedef struct PrePostFixer_virtualTable
{
    TextFormatter_virtualTable base;

    void (*PrePostFixer_print_lch_v)(const PrePostFixer * const prePostFixer, long num, char symbol);

    char (*PrePostFixer_getDefaultSymbol_v)(const PrePostFixer * const prePostFixer);

}PrePostFixer_virtualTable;

struct PrePostFixer
{
    DefaultTextFormatter base_DefaultTextFormatter;

    const char* pre;

    const char* post;
};

void PrePostFixerCtor(PrePostFixer * const prePostFixer, const char* prefix, const char* postfix);

void PrePostFixerDtor_v(PrePostFixer * const prePostFixer);

void PrePostFixer_print_chp_v(const PrePostFixer * const prePostFixer, const char* text);

void PrePostFixer_print_lch_v(const PrePostFixer * const prePostFixer, long num, char symbol);

char PrePostFixer_getDefaultSymbol_v(const PrePostFixer * const prePostFixer);

void PrePostFixer_print_num_l(const PrePostFixer * const prePostFixer,long num);

void PrePostFixer_print_num_lch(const PrePostFixer * const prePostFixer,long num, char symbol);





/* PrePostDollarFixer */

static const char PrePostDollarFixer_DEFAULT_SYMBOL = '$';

typedef struct PrePostDollarFixer
{
    PrePostFixer base_prePostFixer;

}PrePostDollarFixer;

void PrePostDollarFixerCtor(PrePostDollarFixer * const postDollarFixer, const char* prefix, const char* postfix);

void PrePostDollarFixerCopyCtor(PrePostDollarFixer * const postDollarFixer,const PrePostDollarFixer * const other);

void PrePostDollarFixerDtor_v(PrePostDollarFixer * postDollarFixer);

void PrePostDollarFixer_print_ich(const PrePostDollarFixer * const postDollarFixer, int num, char symbol);

void PrePostDollarFixer_print_lch_v(const PrePostDollarFixer * const postDollarFixer, long num, char symbol);

void PrePostDollarFixer_print_dch(const PrePostDollarFixer * const postDollarFixer,double num, char symbol);

char PrePostDollarFixer_getDefaultSymbol_v(const PrePostDollarFixer * const postDollarFixer);



/*PrePostHashFixer */


static const char PrePostHashFixer_DEFAULT_SYMBOL = '#';

typedef struct PrePostHashFixer
{
    PrePostDollarFixer base_PrePostDollarFixer;

    int precision;

}PrePostHashFixer;

void PrePostHashFixerCtor(PrePostHashFixer * const prePostHashFixer, int prc);

void PrePostHashFixerDtor_v(PrePostHashFixer * prePostHashFixer);

void PrePostHashFixer_print_ich(const PrePostHashFixer * const prePostHashFixer, int num, char symbol);

void PrePostHashFixer_print_lch_v(const PrePostHashFixer * const prePostHashFixer, long num, char symbol);

void PrePostHashFixer_print_dch(const PrePostHashFixer * const prePostHashFixer, double num, char symbol);

char PrePostHashFixer_getDefaultSymbol_v(const PrePostHashFixer * const prePostHashFixer);



/* PrePostFloatDollarFixer */


static const char PrePostFloatDollarFixer_DEFAULT_SYMBOL = '@';

typedef struct PrePostFloatDollarFixer
{
    PrePostDollarFixer base_PrePostDollarFixer;

}PrePostFloatDollarFixer;

void PrePostFloatDollarFixerCtor(PrePostFloatDollarFixer * const prePostFloatDollarFixer,const char* prefix, const char* postfix);

void PrePostFloatDollarFixerCopyCtor(PrePostFloatDollarFixer * const prePostFloatDollarFixer1,const PrePostFloatDollarFixer * const prePostFloatDollarFixer2);

void PrePostFloatDollarFixerDtor(PrePostFloatDollarFixer * prePostFloatDollarFixer);

void PrePostFloatDollarFixer_print_f(const PrePostFloatDollarFixer * const prePostFloatDollarFixer, float num);

void PrePostFloatDollarFixer_print_fch(const PrePostFloatDollarFixer * const prePostFloatDollarFixer, float num, char symbol);

char PrePostFloatDollarFixer_getDefaultSymbol_v(const PrePostFloatDollarFixer * const prePostFloatDollarFixer);



/*PrePostChecker */

typedef struct PrePostChecker
{
    PrePostFloatDollarFixer base_PrePostFloatDollarFixer;

}PrePostChecker;

void PrePostCheckerCtor(PrePostChecker * const prePostChecker);

void PrePostCheckerDtor_v(PrePostChecker * prePostChecker);

void PrePostChecker_printThisSymbolUsingFunc(const PrePostChecker * const prePostChecker);

void PrePostChecker_printThisSymbolDirectly(const PrePostChecker * const prePostChecker);

void PrePostChecker_printDollarSymbolByCastUsingFunc(const PrePostChecker * const prePostChecker);

void PrePostChecker_printDollarSymbolByScopeUsingFunc(const PrePostChecker * const prePostChecker);

void PrePostChecker_printDollarSymbolByCastDirectly(const PrePostChecker * const prePostChecker);

void PrePostChecker_printDollarSymbolByScopeDirectly(const PrePostChecker * const prePostChecker);



/* Multiplier */

typedef struct Multiplier
{
    DefaultTextFormatter base_DefaultTextFormatter;

    int times;

}Multiplier;

void MultiplierCtor(Multiplier * const multiplier, int t);

void MultiplierCopyCtor(Multiplier * const multiplier1,const Multiplier * const multiplier2);

void Multiplier_operator_assiment(Multiplier * const multiplier1,const Multiplier * const multiplier2);

void MultiplierDtor_v(Multiplier * multiplier);

void Multiplier_print_v(const Multiplier * const multiplier, const char* text);


#endif

