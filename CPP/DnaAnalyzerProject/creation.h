#ifndef DNAANALYZERPROJECT_CREATION_H
#define DNAANALYZERPROJECT_CREATION_H
#include "DnaSequence.h"

class creation {
public:

    static DnaSequence new_command(char * seq);
    static DnaSequence dup_command(char * seq);
    static DnaSequence load_command(const char * file_name);
};


#endif