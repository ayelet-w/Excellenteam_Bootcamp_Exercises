
#ifndef DNAANALYZERPROJECT_MANIPULATION_H
#define DNAANALYZERPROJECT_MANIPULATION_H

#include "DnaSequence.h"
class Manipulation {
public:
    DnaSequence slice(size_t start, size_t end) const;

    static DnaSequence concat(const DnaSequence& dna1,const DnaSequence& dna2);

    static DnaSequence pair(DnaSequence dna);

    static DnaSequence replace(DnaSequence dna, std::vector< std::pair<size_t ,char> > index_and_letter );
};


#endif
