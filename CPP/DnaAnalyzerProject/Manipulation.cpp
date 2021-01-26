
#include "Manipulation.h"

DnaSequence Manipulation::replace(DnaSequence dna, std::vector< std::pair<size_t ,char> > index_and_letter )
{
    std::string res = dna.to_string();
    for (int i = 0; i < index_and_letter.size(); i++)
    {
        res[index_and_letter[i].first] = index_and_letter[i].second;
    }
    return DnaSequence(res);
}

DnaSequence Manipulation::pair(DnaSequence dna) {
    std::string dna_str;
    std::string result;
    int j,i;
    dna_str = dna.to_string();
    j = dna_str.length()-1;
    result.resize(dna_str.length());
    for( i = 0; i < dna_str.length(); i++,j--)
    {
        switch (dna_str[i])
        {
            case 'A':
                result[j] = 'T';
                break;
            case 'C':
                result[j] = 'G';
                break;
            case 'G':
                result[j] = 'C';
                break;
            case 'T':
                result[j] = 'A';
                break;
        }
    }
    return DnaSequence(result);
}

DnaSequence Manipulation::concat(const DnaSequence& dna1, const DnaSequence& dna2)
{
    std::string seq = (std::string)dna1.to_string() + (std::string)dna2.to_string();
    return DnaSequence(seq);
}
