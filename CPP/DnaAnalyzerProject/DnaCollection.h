

#ifndef DNAANALYZERPROJECT_DNACOLLECTION_H
#define DNAANALYZERPROJECT_DNACOLLECTION_H
#include "DnaSequenceDecorator.h"
#include "map"

class DnaCollection {
public:
    DnaSequenceDecorator get_seq(std::string name);
    DnaSequenceDecorator get_seq_by_id(size_t id);
    void insert_seq(std::pair<std::string,DnaSequenceDecorator> value );
    void print_by_name(std::string name);
    void set_dna_by_name(DnaSequence dna, std::string name);
private:
    std::map<std::string,DnaSequenceDecorator> m_collection;
    static size_t name_id;
};

#endif
