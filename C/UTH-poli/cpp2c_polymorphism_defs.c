
#include "cpp2c_polymorphism_defs.h"
#include  <stdlib.h>

void printFunc(const char* fname)
{
    printf("%-60s | ", fname);
}

DefaultTextFormatter_next_id = 0;

TextFormatter_virtualTable textFormatterVirtualTable =
        {
                .Dtor = TextFormatterDtor_v,
                .print = (void*)0

        };

TextFormatter_virtualTable defaultTextFormatterVirtualTable =
        {
                .print = DefaultTextFormatter_print_v,

                .Dtor = DefaultTextFormatterDtor_v
        };
PrePostFixer_virtualTable PrePostFixer_VirtualTable = {
        .base= {
                .print= PrePostFixer_print_chp_v,
                .Dtor = PrePostFixerDtor_v
        },
        .PrePostFixer_getDefaultSymbol_v = PrePostFixer_getDefaultSymbol_v,
        .PrePostFixer_print_lch_v = PrePostFixer_print_lch_v
};
PrePostFixer_virtualTable PrePostDollarFixerVirtualTable = {
        .base = {
                .Dtor = PrePostDollarFixerDtor_v,
                .print = PrePostFixer_print_chp_v
        },
        .PrePostFixer_getDefaultSymbol_v = PrePostDollarFixer_getDefaultSymbol_v,
        .PrePostFixer_print_lch_v = PrePostDollarFixer_print_lch_v
};
PrePostFixer_virtualTable PrePostHashFixerVirtualTable = {
        .base = {
                .Dtor = PrePostHashFixerDtor_v,
                .print = PrePostFixer_print_chp_v
        },
        .PrePostFixer_getDefaultSymbol_v = PrePostHashFixer_getDefaultSymbol_v,
        .PrePostFixer_print_lch_v = PrePostHashFixer_print_lch_v
};
PrePostFixer_virtualTable PrePostFloatDollarFixerVirtualTable = {
        .base = {
                .Dtor = PrePostFloatDollarFixerDtor,
                .print = PrePostFixer_print_chp_v
        },
        .PrePostFixer_getDefaultSymbol_v = PrePostFloatDollarFixer_getDefaultSymbol_v,
        .PrePostFixer_print_lch_v = PrePostHashFixer_print_lch_v
};
PrePostFixer_virtualTable PrePostCheckerVirtualTable = {
        .base = {
                .Dtor = PrePostCheckerDtor_v,
                .print = PrePostFixer_print_chp_v
        },
        .PrePostFixer_getDefaultSymbol_v = PrePostFloatDollarFixer_getDefaultSymbol_v,
        .PrePostFixer_print_lch_v = PrePostHashFixer_print_lch_v
};
TextFormatter_virtualTable MultiplierVirtualTable =
        {
                .print = Multiplier_print_v,

                .Dtor = MultiplierDtor_v
        };

/* TextFormatter Defs */
void TextFormatterCtor(TextFormatter * const textFormatter)
{
    textFormatter->textFormatterVirtualTable = &textFormatterVirtualTable;
}

void TextFormatterDtor_v(TextFormatter * textFormatter){}

/* DefaultTextFormatter Defs */

void DefaultTextFormatterCtor(DefaultTextFormatter * const defaultTextFormatter)
{
    TextFormatterCtor(&defaultTextFormatter->base_TextFormatter);

    defaultTextFormatter->base_TextFormatter.textFormatterVirtualTable = &defaultTextFormatterVirtualTable;

    defaultTextFormatter->id = DefaultTextFormatter_next_id++;

    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", defaultTextFormatter->id);
}

void DefaultTextFormatterDtor_v(DefaultTextFormatter * defaultTextFormatter)
{
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", defaultTextFormatter->id);

    defaultTextFormatter->base_TextFormatter.textFormatterVirtualTable = &textFormatterVirtualTable;

    TextFormatterDtor_v(&defaultTextFormatter->base_TextFormatter);
}

void DefaultTextFormatterCopyCtor(DefaultTextFormatter * const defaultTextFormatter1,const DefaultTextFormatter * const defaultTextFormatter2)
{
    defaultTextFormatter1->base_TextFormatter = defaultTextFormatter2->base_TextFormatter;

    defaultTextFormatter1->id = defaultTextFormatter2->id;

    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", defaultTextFormatter2->id, defaultTextFormatter1->id);
}

DefaultTextFormatter * DefaultTextFormatter_operator_assingment(DefaultTextFormatter * const defaultTextFormatter1,const DefaultTextFormatter * const defaultTextFormatter2)
{
    defaultTextFormatter1->base_TextFormatter = defaultTextFormatter2->base_TextFormatter;

    defaultTextFormatter1->id = defaultTextFormatter1->id;

    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", defaultTextFormatter2->id, defaultTextFormatter1->id);

    return defaultTextFormatter1;
}

void DefaultTextFormatter_print_v(const DefaultTextFormatter * const defaultTextFormatter, const char* text)
{
    printFunc("[DefaultTextFormatter::print(const char*)]");

    printf("%s\n", text);
}

DefaultTextFormatter* generateFormatterArray()
{
    DefaultTextFormatter* res = malloc(3 * sizeof(DefaultTextFormatter));

    return res;
}


/* PrePostFixer Defs */

void PrePostFixerCtor(PrePostFixer * const prePostFixer, const char* prefix, const char* postfix)
{
    DefaultTextFormatterCtor(&prePostFixer->base_DefaultTextFormatter);

    prePostFixer->base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable = &PrePostFixer_VirtualTable.base;

    prePostFixer->pre = prefix;

    prePostFixer->post = postfix;

    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", prePostFixer->pre, prePostFixer->post);
}


void PrePostFixerDtor_v(PrePostFixer * const prePostFixer)
{
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", prePostFixer->pre, prePostFixer->post);

    prePostFixer->base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable = &defaultTextFormatterVirtualTable;

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

void PrePostDollarFixerCtor(PrePostDollarFixer * const postDollarFixer, const char* prefix, const char* postfix)
{
    PrePostFixerCtor(&postDollarFixer->base_prePostFixer, prefix, postfix);

    postDollarFixer->base_prePostFixer.base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable = &PrePostDollarFixerVirtualTable;

    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", postDollarFixer->base_prePostFixer.pre, postDollarFixer->base_prePostFixer.post);
}

void PrePostDollarFixerCopyCtor(PrePostDollarFixer * const postDollarFixer,const PrePostDollarFixer * const other)
{
    PrePostFixerCtor(&postDollarFixer->base_prePostFixer,other->base_prePostFixer.pre,other->base_prePostFixer.post);

    postDollarFixer->base_prePostFixer.base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable = other->base_prePostFixer.base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable;
    
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", postDollarFixer->base_prePostFixer.pre, postDollarFixer->base_prePostFixer.pre);
}

void PrePostDollarFixerDtor_v(PrePostDollarFixer * postDollarFixer)
{
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n",  postDollarFixer->base_prePostFixer.pre, postDollarFixer->base_prePostFixer.pre);

    postDollarFixer->base_prePostFixer.base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable = &PrePostFixer_VirtualTable;

    PrePostFixerDtor_v(&postDollarFixer->base_prePostFixer);
}

void PrePostDollarFixer_print_ich(const PrePostDollarFixer * const postDollarFixer, int num, char symbol)
{
    printFunc("[PrePostDollarFixer::print(int, char)]");

    printf("-->\n");

    PrePostDollarFixer_print_lch_v(postDollarFixer,(long)(num), symbol);
}

void PrePostDollarFixer_print_lch_v(const PrePostDollarFixer * const postDollarFixer, long num, char symbol)
{
    printFunc("[PrePostDollarFixer::print(long, char)]");

    printf("-->\n");

    PrePostFixer_print_lch_v(&postDollarFixer->base_prePostFixer,num, symbol);
}

void PrePostDollarFixer_print_dch(const PrePostDollarFixer * const postDollarFixer,double num, char symbol)
{
    printFunc("[PrePostDollarFixer::print(double, char)]");

    printf("%s%c%f%s\n", postDollarFixer->base_prePostFixer.pre, symbol, num, postDollarFixer->base_prePostFixer.post);
}


char PrePostDollarFixer_getDefaultSymbol_v(const PrePostDollarFixer * const postDollarFixer)
{
    return PrePostDollarFixer_DEFAULT_SYMBOL;
}


/* PrePostHashFixer Defs */

void PrePostHashFixerCtor(PrePostHashFixer * const prePostHashFixer, int prc)
{
    PrePostDollarFixerCtor(&prePostHashFixer->base_PrePostDollarFixer,"===> ", " <===");

    prePostHashFixer->base_PrePostDollarFixer.base_prePostFixer.base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable = &PrePostHashFixerVirtualTable;

    prePostHashFixer->precision = prc;

    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", prePostHashFixer->base_PrePostDollarFixer.base_prePostFixer.pre, prePostHashFixer->base_PrePostDollarFixer.base_prePostFixer.pre, prePostHashFixer->precision);

    PrePostHashFixer_print_dch(prePostHashFixer,9999.9999, '#');
}

void PrePostHashFixerDtor_v(PrePostHashFixer * prePostHashFixer)
{
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", prePostHashFixer->base_PrePostDollarFixer.base_prePostFixer.pre,
           prePostHashFixer->base_PrePostDollarFixer.base_prePostFixer.post);

    prePostHashFixer->base_PrePostDollarFixer.base_prePostFixer.base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable = &PrePostDollarFixerVirtualTable;

    PrePostDollarFixerDtor_v(&prePostHashFixer->base_PrePostDollarFixer);

}

void PrePostHashFixer_print_ich(const PrePostHashFixer * const prePostHashFixer, int num, char symbol)
{
    printFunc("[PrePostHashFixer::print(int, char)]");
    printf("-->\n");

    PrePostHashFixer_print_dch(prePostHashFixer,(double)(num), symbol);
}

void PrePostHashFixer_print_lch_v(const PrePostHashFixer * const prePostHashFixer, long num, char symbol)
{
    printFunc("[PrePostHashFixer::print(long, char)]");
    printf("-->\n");

    PrePostHashFixer_print_dch(prePostHashFixer,(double)(num), symbol);
}

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

void PrePostFloatDollarFixerCtor(PrePostFloatDollarFixer * const prePostFloatDollarFixer,const char* prefix, const char* postfix)
{
    PrePostDollarFixerCtor(&prePostFloatDollarFixer->base_PrePostDollarFixer,prefix, postfix);

    prePostFloatDollarFixer->base_PrePostDollarFixer.base_prePostFixer.base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable =&PrePostFloatDollarFixerVirtualTable;

    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", prePostFloatDollarFixer->base_PrePostDollarFixer.base_prePostFixer.pre
           , prePostFloatDollarFixer->base_PrePostDollarFixer.base_prePostFixer.post);
}

void PrePostFloatDollarFixerCopyCtor(PrePostFloatDollarFixer * const prePostFloatDollarFixer1,const PrePostFloatDollarFixer * const prePostFloatDollarFixer2)
{
    prePostFloatDollarFixer1->base_PrePostDollarFixer = prePostFloatDollarFixer2->base_PrePostDollarFixer;
}

void PrePostFloatDollarFixerDtor(PrePostFloatDollarFixer * prePostFloatDollarFixer)
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", prePostFloatDollarFixer->base_PrePostDollarFixer.base_prePostFixer.pre
            , prePostFloatDollarFixer->base_PrePostDollarFixer.base_prePostFixer.post);

    prePostFloatDollarFixer->base_PrePostDollarFixer.base_prePostFixer.base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable =&PrePostDollarFixerVirtualTable;

    PrePostDollarFixerDtor_v(&prePostFloatDollarFixer->base_PrePostDollarFixer);
}

void PrePostFloatDollarFixer_print_f(const PrePostFloatDollarFixer * const prePostFloatDollarFixer, float num)
{
    printFunc("[PrePostFloatDollarFixer::print(float)]");

    printf("-->\n");

    PrePostFloatDollarFixer_print_fch(prePostFloatDollarFixer,num, PrePostFloatDollarFixer_DEFAULT_SYMBOL);
}

void PrePostFloatDollarFixer_print_fch(const PrePostFloatDollarFixer * const prePostFloatDollarFixer, float num, char symbol)
{
    printFunc("[PrePostFloatDollarFixer::print(float, char)]");

    printf("%s%c%.2f%s\n", prePostFloatDollarFixer->base_PrePostDollarFixer.base_prePostFixer.pre
            , symbol, num, prePostFloatDollarFixer->base_PrePostDollarFixer.base_prePostFixer.post);
}

char PrePostFloatDollarFixer_getDefaultSymbol_v(const PrePostFloatDollarFixer * const prePostFloatDollarFixer)
{
    return PrePostFloatDollarFixer_DEFAULT_SYMBOL;
}


/* PrePostChecker Defs */

void PrePostCheckerCtor(PrePostChecker * const prePostChecker)
{
    PrePostFloatDollarFixerCtor(&prePostChecker->base_PrePostFloatDollarFixer,"[[[[ ", " ]]]]");

    prePostChecker->base_PrePostFloatDollarFixer.base_PrePostDollarFixer.base_prePostFixer.base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable =&PrePostCheckerVirtualTable;

    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", prePostChecker->base_PrePostFloatDollarFixer.base_PrePostDollarFixer.base_prePostFixer.pre,
           prePostChecker->base_PrePostFloatDollarFixer.base_PrePostDollarFixer.base_prePostFixer.post);
}

void PrePostCheckerDtor_v(PrePostChecker * prePostChecker)
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n",  prePostChecker->base_PrePostFloatDollarFixer.base_PrePostDollarFixer.base_prePostFixer.pre,
           prePostChecker->base_PrePostFloatDollarFixer.base_PrePostDollarFixer.base_prePostFixer.post);

    prePostChecker->base_PrePostFloatDollarFixer.base_PrePostDollarFixer.base_prePostFixer.base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable =&PrePostFloatDollarFixerVirtualTable;

    PrePostFloatDollarFixerDtor(&prePostChecker->base_PrePostFloatDollarFixer);
}

void PrePostChecker_printThisSymbolUsingFunc(const PrePostChecker * const prePostChecker)
{
    printFunc("[PrePostChecker::printThisSymbolUsingFunc()]");

    printf("Default symbol is %c\n", PrePostFloatDollarFixer_getDefaultSymbol_v(&prePostChecker->base_PrePostFloatDollarFixer));
}

void PrePostChecker_printThisSymbolDirectly(const PrePostChecker * const prePostChecker)
{
    printFunc("[PrePostChecker::printThisSymbolDirectly()]");

    printf("Default symbol is %c\n", PrePostFloatDollarFixer_DEFAULT_SYMBOL);
}

void PrePostChecker_printDollarSymbolByCastUsingFunc(const PrePostChecker * const prePostChecker)
{
    printFunc("[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

    printf("Default symbol is %c\n", PrePostFloatDollarFixer_getDefaultSymbol_v(&prePostChecker->base_PrePostFloatDollarFixer));
}

void PrePostChecker_printDollarSymbolByScopeUsingFunc(const PrePostChecker * const prePostChecker)
{
    printFunc("[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

    printf("Default symbol is %c\n", PrePostDollarFixer_getDefaultSymbol_v(&prePostChecker->base_PrePostFloatDollarFixer.base_PrePostDollarFixer));
}

void PrePostChecker_printDollarSymbolByCastDirectly(const PrePostChecker * const prePostChecker)
{
    printFunc("[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n", PrePostDollarFixer_DEFAULT_SYMBOL);
}

void PrePostChecker_printDollarSymbolByScopeDirectly(const PrePostChecker * const prePostChecker)
{
printFunc("[PrePostChecker::printDollarSymbolByScopeDirectly()]");

printf("Default symbol is %c\n", PrePostDollarFixer_DEFAULT_SYMBOL);
}


/* Multiplier Defs */

void MultiplierCtor(Multiplier * const multiplier, int t)
{
    DefaultTextFormatterCtor(&multiplier->base_DefaultTextFormatter);

    multiplier->base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable = &MultiplierVirtualTable;

    multiplier->times = t;

    printf("--- Multiplier CTOR: times = %d\n", multiplier->times);
}

void MultiplierCopyCtor(Multiplier * const multiplier1,const Multiplier * const multiplier2)
{
    DefaultTextFormatterCtor(&multiplier1->base_DefaultTextFormatter);

    multiplier1->base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable = multiplier2->base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable;

    multiplier1->times = multiplier2->times;
}

void Multiplier_operator_assiment(Multiplier * const multiplier1,const Multiplier * const multiplier2)
{
    DefaultTextFormatterCtor(&multiplier1->base_DefaultTextFormatter);

    multiplier1->base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable = multiplier2->base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable;

    multiplier1->times = multiplier2->times;
}

void MultiplierDtor_v(Multiplier * multiplier)
{
    printf("--- Multiplier DTOR: times = %d\n", multiplier->times);

    multiplier->base_DefaultTextFormatter.base_TextFormatter.textFormatterVirtualTable = &defaultTextFormatterVirtualTable;

    DefaultTextFormatterDtor_v(&multiplier->base_DefaultTextFormatter);
}

void Multiplier_print_v(const Multiplier * const multiplier, const char* text)
{
    int i;

    printFunc("[Multiplier::print(const char*)]");

    for (i = 0; i < multiplier->times; ++i)
        printf("%s", text);

    printf("\n");
}