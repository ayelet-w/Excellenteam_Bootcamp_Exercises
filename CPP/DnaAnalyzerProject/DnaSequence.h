
#ifndef DNAANALYZERPROJECT_DNASEQUENCE_H
#define DNAANALYZERPROJECT_DNASEQUENCE_H


#include <stdio.h>
#include <stdint.h>
#include <cstring>
#include <stdexcept>
#include "vector"
#include "Nucleotide.h"

typedef uint8_t nucleotide;

class DnaSequence {

public:

    DnaSequence() {}

    explicit DnaSequence(const char* dna_str);

    explicit DnaSequence(const std::string dna_str);

    DnaSequence(const DnaSequence &other);

    DnaSequence & operator = (const DnaSequence &other);

    DnaSequence & operator = (const char * dna_str);

    DnaSequence & operator = (const std::string & dna_str);

    ~DnaSequence();

    friend std::ostream &operator<<(std::ostream &os,const DnaSequence& dnaSequence);

    char & operator[](size_t pos);

    void insert(nucleotide nuc, size_t index);

    friend bool operator == (const DnaSequence &me, const DnaSequence &other);

    friend bool operator != (const DnaSequence &me, const DnaSequence &other);

    size_t getLen();

    char* to_string() const;

    size_t get_id() const{return m_id;}

    void set_id(size_t value){ m_id = value;}

    DnaSequence slice(size_t start, size_t end) const;

    DnaSequence pair() const;

    long find(const std::string & sequence) const;

    size_t count(const std::string & sequence) const;

    std::vector<int> findall(const std::string & sequence) const;

    std::vector<std::string> FindConsensus()const;

private:
    //static size_t id;
    nucleotide* m_data;
    size_t m_len;
    size_t m_id;
};

inline bool operator == (const DnaSequence &me, const DnaSequence &other)
{
    return !strcmp(me.to_string(),other.to_string()) && me.m_len == other.m_len;
}
inline bool operator != (const DnaSequence &me, const DnaSequence &other)
{
    return !(me == other);
}


#endif
