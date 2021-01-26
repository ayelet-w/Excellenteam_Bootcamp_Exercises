

#ifndef DNAANALYZERPROJECT_FILEIO_H
#define DNAANALYZERPROJECT_FILEIO_H
#include "DnaSequence.h"

class fileIO {
public:
    static DnaSequence reading_dnaSeq_file(const char * path);
    static void writing_dnaSeq_file(const char * path, DnaSequence& dna);

};


#endif
