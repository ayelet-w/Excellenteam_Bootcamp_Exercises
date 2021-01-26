
#ifndef DNAANALYZERPROJECT_MANAGEMENT_H
#define DNAANALYZERPROJECT_MANAGEMENT_H
#include "DnaSequence.h"

class Management {
public:
    static void save(DnaSequence dna, const char * file_name);

    static void rename(std::string old_name, std::string new_name);
};


#endif
