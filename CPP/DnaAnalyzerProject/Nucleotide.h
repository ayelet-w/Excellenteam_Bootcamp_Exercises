#ifndef DNAANALYZERPROJECT_NUCLEOTIDE_H
#define DNAANALYZERPROJECT_NUCLEOTIDE_H

#define BASE_MASK 0x3

class Nucleotide {
public:
    enum base
    {
        BASE_A = 0x0, // binary: 00
        BASE_C = 0x1, // binary: 01
        BASE_G = 0x2, // binary: 10
        BASE_T = 0x3 // binary: 11
    };
};


#endif
