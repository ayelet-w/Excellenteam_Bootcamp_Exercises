
#include "DnaCollection.h"
#include "iostream"
size_t DnaCollection::name_id = 1;
DnaSequenceDecorator DnaCollection::get_seq(std::string name)
{
    return m_collection[name];
}
DnaSequenceDecorator DnaCollection::get_seq_by_id(size_t id)
{
    std::map<std::string,DnaSequenceDecorator>::iterator i = m_collection.begin();

    for(i; i != m_collection.end(); i++)
    {
        if((*i).second.get_id() == id)
            return (*i).second;
    }
}
void DnaCollection::insert_seq(std::pair<std::string,DnaSequenceDecorator> value)
{
    value.second.set_id(name_id++);
    m_collection.insert(value);
}
void DnaCollection::print_by_name(std::string name)
{
    DnaSequenceDecorator dna = m_collection[name];
    std::cout<< "[" << dna.get_id() << "] " << name << ": " << dna.m_dnaSequence.to_string()<< "\n";
}

void DnaCollection::set_dna_by_name(DnaSequence dna, std::string name)
{
    m_collection[name].m_dnaSequence = dna;
}
