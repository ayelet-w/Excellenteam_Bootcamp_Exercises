#include "cpp2c_polymorphism_defs.h"
#include <stdlib.h>

void doPrePostFixer()
{
    PrePostFixer angleBrackets;
    printf("\n--- start doPrePostFixer() ---\n\n");


    PrePostFixerCtor(&angleBrackets,"<<< ", " >>>");
    PrePostFixer_print_chp_v(&angleBrackets,"Hello World!");
    PrePostFixer_print_lch_v(&angleBrackets,-777,'\0');
    PrePostFixer_print_lch_v(&angleBrackets,350, '#');
    PrePostFixer_print_lch_v (&angleBrackets, (long)(3.14),'\0');

    printf("\n--- end doPrePostFixer() ---\n\n");

    PrePostFixerDtor_v(&angleBrackets);
}

void doPrePostDollarFixer()
{
    PrePostDollarFixer asterisks;
    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixerCtor(&asterisks,"***** ", " *****");
    PrePostDollarFixer_print_ich(&asterisks,-777,'$');
    PrePostDollarFixer_print_ich(&asterisks,350, '#');
    PrePostDollarFixer_print_dch(&asterisks,3.14f,'$');

    printf("\n--- end doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixerDtor_v(&asterisks);
}

void doPrePostChecker()
{
    PrePostChecker check;
    printf("\n--- start doPrePostChecker() ---\n\n");


    PrePostCheckerCtor(&check);
    PrePostChecker_printThisSymbolUsingFunc(&check);
    PrePostChecker_printThisSymbolDirectly(&check);
    PrePostChecker_printDollarSymbolByCastDirectly(&check);
    PrePostChecker_printDollarSymbolByScopeDirectly(&check);
    PrePostChecker_printDollarSymbolByCastUsingFunc(&check);
    PrePostChecker_printDollarSymbolByScopeUsingFunc(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");

    PrePostCheckerDtor_v(&check);
}

void doPrePostFloatDollarFixer()
{
    PrePostFloatDollarFixer hashes;
    PrePostDollarFixer hashes2;

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostFloatDollarFixerCtor(&hashes,"### ", " ###");
    PrePostFloatDollarFixer_print_f(&hashes,-777);
    PrePostFloatDollarFixer_print_fch(&hashes,350, '#');
    PrePostFloatDollarFixer_print_f(&hashes,3.14f);

    PrePostDollarFixerCopyCtor(&hashes2,&hashes.base_PrePostDollarFixer);
    PrePostDollarFixer_print_dch(&hashes2,7.5,'$');
    PrePostDollarFixer_print_ich(&hashes2, 100,'$');

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostDollarFixerDtor_v(&hashes2);
    PrePostFloatDollarFixerDtor(&hashes);
}

void runAsPrePostFixerRef(const PrePostFixer* pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    PrePostFixer_print_lch_v(pp, 123, '\0');

    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(const PrePostDollarFixer* pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    PrePostDollarFixer_print_ich(pp,123,'$');

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(const PrePostDollarFixer pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    PrePostDollarFixer_print_ich(&pp,123,'$');

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}

void runAsPrePostHashFixerRef(const PrePostHashFixer* pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    PrePostHashFixer_print_ich(pp, 123, '#');

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void doMultiplier()
{
    Multiplier m1;
    MultiplierCtor(&m1,3);
    Multiplier m2;
    MultiplierCtor(&m2, 5);
    Multiplier m3;
    Multiplier_operator_assiment(&m3, &m1);
    Multiplier m4;
    MultiplierCopyCtor(&m4,&m2);
    printf("\n--- start doMultiplier() ---\n\n");

    Multiplier_print_v(&m1,"abc ");
    Multiplier_print_v(&m2,"abc ");
    Multiplier_print_v(&m3,"abc ");
    Multiplier_print_v(&m4,"abc ");

    printf("\n--- start doMultiplier() ---\n\n");

    MultiplierDtor_v(&m4);
    MultiplierDtor_v(&m3);
    MultiplierDtor_v(&m2);
    MultiplierDtor_v(&m1);
}

void doFormatterArray()
{
    int i;
    PrePostDollarFixer postDollarFixer;
    Multiplier multiplier;
    PrePostChecker prePostChecker;
    PrePostDollarFixerCtor(&postDollarFixer,"!!! ", " !!!");
    MultiplierCtor(&multiplier,4);
    PrePostCheckerCtor(&prePostChecker);
    printf("\n--- start doFormatterArray() ---\n\n");

    DefaultTextFormatter formatters[] =
            {
                    postDollarFixer.base_prePostFixer.base_DefaultTextFormatter,
                    multiplier.base_DefaultTextFormatter,
                    prePostChecker.base_PrePostFloatDollarFixer.base_PrePostDollarFixer.base_prePostFixer.base_DefaultTextFormatter
            };

    for (i = 0; i < 3; ++i)
        DefaultTextFormatter_print_v(&formatters[i],"Hello World!");

    printf("\n--- end doFormatterArray() ---\n\n");

    PrePostCheckerDtor_v(&prePostChecker);
    MultiplierDtor_v(&multiplier);
    PrePostDollarFixerDtor_v(&postDollarFixer);
}

void doFormatterPtrs()
{
    int i;
    PrePostDollarFixer * postDollarFixer = malloc(sizeof(PrePostDollarFixer));
    Multiplier * multiplier = malloc(sizeof(Multiplier));
    PrePostChecker * prePostChecker = malloc(sizeof(PrePostChecker));
    PrePostDollarFixerCtor(postDollarFixer,"!!! ", " !!!");
    MultiplierCtor(multiplier,4);
    PrePostCheckerCtor(prePostChecker);
    printf("\n--- start doFormatterPtrs() ---\n\n");

    DefaultTextFormatter* pfmt[] =
            {
                    postDollarFixer,
                    multiplier,
                    prePostChecker
            };

    for (i = 0; i < 3; ++i)
        pfmt[i]->base_TextFormatter.textFormatterVirtualTable->print((const TextFormatter * const)pfmt[i],"Hello World!");

    for (i = 2; i >= 0; --i)
        pfmt[i]->base_TextFormatter.textFormatterVirtualTable->Dtor((const TextFormatter * const)pfmt[i]);

    printf("\n--- end doFormatterPtrs() ---\n\n");
}

void doFormatterDynamicArray()
{
    int i;
    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    DefaultTextFormatter* formatters = generateFormatterArray();

    for (i = 0; i < 3; ++i)
        DefaultTextFormatter_print_v(&formatters[i],"Hello World!");

    DefaultTextFormatterDtor_v(formatters);

    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}

int main()
{
    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();

    PrePostHashFixer hfix;
    runAsPrePostFixerRef(&hfix.base_PrePostDollarFixer.base_prePostFixer);
    runAsPrePostDollarFixerRef(&hfix.base_PrePostDollarFixer);
    runAsPrePostDollarFixerObj(hfix.base_PrePostDollarFixer);
    runAsPrePostHashFixerRef(&hfix);

    doMultiplier();

    doFormatterArray();
    doFormatterPtrs();
    doFormatterDynamicArray();

    printf("\n--- End main() ---\n\n");

    return 0;
}



