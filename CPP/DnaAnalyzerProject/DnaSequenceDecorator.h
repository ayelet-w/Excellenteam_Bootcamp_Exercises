//
// Created by ayelet on 11/29/20.
//

#ifndef DNAANALYZERPROJECT_DNASEQUENCEDECORATOR_H
#define DNAANALYZERPROJECT_DNASEQUENCEDECORATOR_H
#include "DnaSequence.h"

class DnaSequenceDecorator {
public:
    DnaSequence m_dnaSequence;
    size_t m_id;
    std::string m_name;
    size_t get_id(){return m_id;};
    void set_id(size_t id){m_id = id;};
    void set_name(std::string name){m_name = name;};
    std::string get_name(){return m_name;};
};


#endif //DNAANALYZERPROJECT_DNASEQUENCEDECORATOR_H
