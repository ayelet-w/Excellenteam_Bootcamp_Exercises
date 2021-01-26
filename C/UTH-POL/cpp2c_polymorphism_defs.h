#ifndef UTH_POL_CPP2C_POLYMORPHISM_DEFS_H
#define UTH_POL_CPP2C_POLYMORPHISM_DEFS_H
#include <stdio.h>

/* inline*/
void printFunc(const char* fname)
{
    printf("%-60s | ", fname);
}


/* TextFormatter */
struct TextFormatter;

typedef struct TextFormatter_virtualTable
{
   void (*TextFormatterDtor_v)(TextFormatter *);

   void (*TextFormatter_print_pv)(const TextFormatter * const textFormatter, const char* text);

}TextFormatter_virtualTable;



typedef struct TextFormatter
{
    TextFormatter_virtualTable * textFormatterVirtualTable;

}TextFormatter;

void TextFormatterDtor_v(TextFormatter * textFormatter);

void TextFormatter_print_pv(const TextFormatter * const textFormatter, const char* text);

TextFormatter_virtualTable textFormatterVirtualTable =
        {
         TextFormatterDtor_v,
         TextFormatter_print_pv

        };



/* DefaultTextFormatter */
struct DefaultTextFormatter;

typedef struct DefaultTextFormatter_virtualTable
{
    TextFormatter_virtualTable base;

}DefaultTextFormatter_virtualTable;


static int next_id;
next_id = 0;


typedef struct DefaultTextFormatter
{
    TextFormatter base_TextFormatter;

    const int id;

}DefaultTextFormatter;

void DefaultTextFormatterCtor(DefaultTextFormatter * const defaultTextFormatter);

void DefaultTextFormatterCopyCtor(DefaultTextFormatter * const defaultTextFormatter1,const DefaultTextFormatter * const defaultTextFormatter2);

DefaultTextFormatter * DefaultTextFormatter_operator_assingment(DefaultTextFormatter * const defaultTextFormatter1,const DefaultTextFormatter * const defaultTextFormatter2);

void DefaultTextFormatterDtor_v(DefaultTextFormatter * defaultTextFormatter);

void DefaultTextFormatter_print_v(const DefaultTextFormatter * const defaultTextFormatter, const char* text);

DefaultTextFormatter* generateFormatterArray();

DefaultTextFormatter_virtualTable defaultTextFormatterVirtualTable = {
        {
           DefaultTextFormatter_print_v,
           DefaultTextFormatterDtor_v
        }
     };



/*PrePostFixer */
struct PrePostFixer;

typedef struct PrePostFixer_virtualTable
{
    DefaultTextFormatter_virtualTable base;

    void (*PrePostFixer_print_lch_v)(const PrePostFixer * const prePostFixer, long num, char symbol);

    char (*PrePostFixer_getDefaultSymbol_v)(const PrePostFixer * const prePostFixer);

}PrePostFixer_virtualTable;

typedef struct PrePostFixer
{
    DefaultTextFormatter base_DefaultTextFormatter;

    const char* pre;

    const char* post;
}PrePostFixer;

void PrePostFixerCtor(PrePostFixer * const prePostFixer, const char* prefix, const char* postfix);

void PrePostFixerDtor_v(PrePostFixer * const prePostFixer);

void PrePostFixer_print_chp_v(const PrePostFixer * const prePostFixer, const char* text);

void PrePostFixer_print_lch_v(const PrePostFixer * const prePostFixer, long num, char symbol);

char PrePostFixer_getDefaultSymbol_v(const PrePostFixer * const prePostFixer);

void PrePostFixer_print_num_l(const PrePostFixer * const prePostFixer,long num);

void PrePostFixer_print_num_lch(const PrePostFixer * const prePostFixer,long num, char symbol);

PrePostFixer_virtualTable PrePostFixer_VirtualTable = {
        {
             DefaultTextFormatter_print_v,
             DefaultTextFormatterDtor_v
        },
        PrePostFixer_getDefaultSymbol_v,
        PrePostFixer_print_lch_v
};



/* PrePostDollarFixer */
typedef struct PrePostDollarFixer_virtualTable
{
    PrePostFixer_virtualTable base;

}PrePostDollarFixer_virtualTable;
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

void PrePostDollarFixer_getDefaultSymbol_v(const PrePostDollarFixer * const postDollarFixer);



/*PrePostHashFixer */

typedef struct PrePostHashFixer_virtualTable
{
    PrePostDollarFixer_virtualTable base;

}PrePostHashFixer_virtualTable;

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

typedef struct PrePostFloatDollarFixer_virtualTable
{
    PrePostDollarFixer_virtualTable base;

}PrePostFloatDollarFixer_virtualTable;

static const char PrePostFloatDollarFixer_DEFAULT_SYMBOL = '@';

typedef struct PrePostFloatDollarFixer
{
    PrePostDollarFixer base_PrePostDollarFixer;

}PrePostFloatDollarFixer;

void PrePostFloatDollarFixerCtor(PrePostFloatDollarFixer * const prePostFloatDollarFixer,const char* prefix, const char* postfix);

void PrePostFloatDollarFixerDtor(PrePostFloatDollarFixer * prePostFloatDollarFixer);

void PrePostFloatDollarFixer_print_f(const PrePostFloatDollarFixer * const prePostFloatDollarFixer, float num);

void PrePostFloatDollarFixer_print_fch(const PrePostFloatDollarFixer * const prePostFloatDollarFixer, float num, char symbol);

char PrePostFloatDollarFixer_getDefaultSymbol_v(const PrePostFloatDollarFixer * const prePostFloatDollarFixer);



/*PrePostChecker */
typedef struct PrePostChecker_virtualTable
{
    PrePostFloatDollarFixer_virtualTable base;

}PrePostChecker_virtualTable;

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

void MultiplierDtor_v(Multiplier * multiplier);

void Multiplier_print_v(const Multiplier * const multiplier, const char* text);

#endif
