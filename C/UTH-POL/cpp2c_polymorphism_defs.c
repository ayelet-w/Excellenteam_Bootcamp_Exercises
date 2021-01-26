
#include "cpp2c_polymorphism_defs.h"


/* DefaultTextFormatter Defs */

void DefaultTextFormatterCtor(DefaultTextFormatter * const defaultTextFormatter)
{
    defaultTextFormatter->base_TextFormatter = defaultTextFormatterVirtualTable;

    defaultTextFormatter->id = next_id++;

    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", id);
}

void DefaultTextFormatterDtor_v(DefaultTextFormatter * defaultTextFormatter)
{
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", id);

    defaultTextFormatter->base_TextFormatter = textFormatterVirtualTable;
}

void DefaultTextFormatterCopyCtor(DefaultTextFormatter * const defaultTextFormatter1,const DefaultTextFormatter * const defaultTextFormatter2)
{
    defaultTextFormatter1->base_TextFormatter = defaultTextFormatter2->base_TextFormatter;

    defaultTextFormatter1->id = defaultTextFormatter1->id;

    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", defaultTextFormatter2->id, defaultTextFormatter1->id);
}

DefaultTextFormatter * DefaultTextFormatter_operator_assingment(DefaultTextFormatter * const defaultTextFormatter1,const DefaultTextFormatter * const defaultTextFormatter2)
{
    defaultTextFormatter1->base_TextFormatter = defaultTextFormatter2->base_TextFormatter;

    defaultTextFormatter1->id = defaultTextFormatter1->id;

    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", defaultTextFormatter2->id, defaultTextFormatter1->id);

    return *defaultTextFormatter1;
}

void DefaultTextFormatter_print_v(const DefaultTextFormatter * const defaultTextFormatter, const char* text)
{
    printFunc("[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);
}

DefaultTextFormatter* generateFormatterArray()
{
    return new DefaultTextFormatter[3];
}


/* PrePostFixer Defs */

void PrePostFixerCtor(PrePostFixer * const prePostFixer, const char* prefix, const char* postfix)
{
    DefaultTextFormatterCtor(&prePostFixer->base_DefaultTextFormatter);

    prePostFixer->base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable = PrePostFixer_VirtualTable;

    prePostFixer->pre = prefix;

    prePostFixer->post = prefix;

    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", pre, post);
}


void PrePostFixerDtor_v(PrePostFixer * const prePostFixer)
{
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", pre, post);

    prePostFixer->base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable = defaultTextFormatterVirtualTable;

    DefaultTextFormatterDtor_v(&prePostFixer->base_DefaultTextFormatter);
}

void PrePostFixer_print_chp_v(const PrePostFixer * const prePostFixer, const char* text)
{
    printFunc("[PrePostFixer::print(const char*)]");

    printf("%s%s%s\n", prePostFixer->pre, text, prePostFixer->post);
}

char PrePostFixer_getDefaultSymbol_v(const PrePostFixer * const prePostFixer)
{
    return '\0';
}

void PrePostFixer_print_lch_v(const PrePostFixer * const prePostFixer, long num, char symbol)
{
    printFunc("[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol)
        PrePostFixer_print_num_lch(prePostFixer,num, symbol);
    else
        PrePostFixer_print_num_l(prePostFixer,num);
}

void PrePostFixer_print_num_l(const PrePostFixer * const prePostFixer,long num)
{
    printFunc("[PrePostFixer::print_num(long)]");
    printf("%s%ld%s\n", prePostFixer->pre, num, prePostFixer->post);
}

void PrePostFixer_print_num_lch(const PrePostFixer * const prePostFixer,long num, char symbol)
{
    printFunc("[PrePostFixer::print_num(long, char)]");
    printf("%s%c%ld%s\n", prePostFixer->pre, symbol, num, prePostFixer->post);
}

/*PrePostDollarFixer Defs */

void PrePostDollarFixer_getDefaultSymbol_v(const PrePostDollarFixer * const postDollarFixer)
{
    return PrePostDollarFixer_DEFAULT_SYMBOL
}

/* PrePostHashFixer Defs */

void PrePostHashFixer_print_dch(const PrePostHashFixer * const prePostHashFixer, double num, char symbol)
{
    printFunc("[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", prePostHashFixer->base_PrePostDollarFixer.base_prePostFixer.pre, symbol, prePostHashFixer->precision, num, prePostHashFixer->base_PrePostDollarFixer.base_prePostFixer.post);
}

char PrePostHashFixer_getDefaultSymbol_v(const PrePostHashFixer * const prePostHashFixer)
{
    return PrePostHashFixer_DEFAULT_SYMBOL;
}


/*PrePostFloatDollarFixer Defs */

char PrePostFloatDollarFixer_getDefaultSymbol_v(const PrePostFloatDollarFixer * const prePostFloatDollarFixer);
{
    return PrePostFloatDollarFixer_DEFAULT_SYMBOL;
}


/* Multiplier Defs */

void MultiplierCtor(Multiplier * const multiplier, int t)
{
   DefaultTextFormatterCtor(&multiplier->base_DefaultTextFormatter);

   multiplier->times = t;

   printf("--- Multiplier CTOR: times = %d\n", multiplier->times);
}

void MultiplierDtor_v(Multiplier * multiplier)
{
    printf("--- Multiplier DTOR: times = %d\n", multiplier->times);

    DefaultTextFormatterDtor_v(&multiplier->base_DefaultTextFormatter);
}