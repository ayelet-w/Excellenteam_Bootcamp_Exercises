

#include "DnaSequence.h"
Nucleotide base_nucleotide;
//size_t DnaSequence::id = 0;
DnaSequence::DnaSequence(const char* dna_str)
{
    if(!strcmp(dna_str,"") || dna_str == NULL)
    {
        m_len = 0;
        m_data = new uint8_t[0];
        return;
    }
    size_t dna_len = strlen(dna_str);

    m_len = dna_len;

    //number of bytes necessary to store dna_str as a bitset
    size_t dna_bytes = (dna_len / 4) + (dna_len % 4 != 0);

    m_data = new uint8_t[dna_bytes];

    std::memset(m_data, 0, dna_bytes);

    // for each base of the DNA sequence

    for (size_t i = 0; i < dna_len; ++i)
    {
        uint8_t shift = 6 - 2 * (i % 4);

        switch (dna_str[i])
        {
            case 'A':
                m_data[i / 4] |= base_nucleotide.BASE_A << shift;
                break;
            case 'C':
                m_data[i / 4] |= base_nucleotide.BASE_C << shift;
                break;
            case 'G':
                m_data[i / 4] |= base_nucleotide.BASE_G << shift;
                break;
            case 'T':
                m_data[i / 4] |= base_nucleotide.BASE_T << shift;
                break;
            default:
                throw std::invalid_argument("invalid DNA");
        }

        shift = (shift == 0) ? 6 : shift - 2;
    }
    //m_id = id++;
}
DnaSequence::DnaSequence(const std::string dna_str)
{
    size_t dna_len = dna_str.length();

    m_len = dna_len;

    //number of bytes necessary to store dna_str as a bitset
    size_t dna_bytes = (dna_len / 4) + (dna_len % 4 != 0);

    m_data = new uint8_t[dna_bytes];

    std::memset(m_data, 0, dna_bytes);

    // for each base of the DNA sequence

    for (size_t i = 0; i < dna_len; ++i)
    {
        uint8_t shift = 6 - 2 * (i % 4);

        switch (dna_str[i])
        {
            case 'A':
                m_data[i / 4] |= base_nucleotide.BASE_A << shift;
                break;
            case 'C':
                m_data[i / 4] |= base_nucleotide.BASE_C << shift;
                break;
            case 'G':
                m_data[i / 4] |= base_nucleotide.BASE_G << shift;
                break;
            case 'T':
                m_data[i / 4] |= base_nucleotide.BASE_T << shift;
                break;
            default:
                throw std::invalid_argument("invalid DNA");
        }

        shift = (shift == 0) ? 6 : shift - 2;
    }
    //m_id = id++;
}

DnaSequence::DnaSequence(const DnaSequence &other)
{
    size_t dna_bytes = (other.m_len / 4) + (other.m_len % 4 != 0);

    m_data = new uint8_t[dna_bytes];

    for(int i = 0; i < dna_bytes; i++)
    {
        m_data[i] = other.m_data[i];
    }

    m_len = other.m_len;
    m_id = other.m_id;
}

DnaSequence & DnaSequence::operator = (const DnaSequence &other)
{
    size_t dna_bytes = (other.m_len / 4) + (other.m_len % 4 != 0);

    m_data = new uint8_t[dna_bytes];

    for(int i = 0; i < dna_bytes; i++)
    {
        m_data[i] = other.m_data[i];
    }

    m_len = other.m_len;

    m_id = other.m_id;

    return *this;
}

DnaSequence & DnaSequence::operator = (const char* dna_str)
{
    size_t dna_len = strlen(dna_str);

    m_len = dna_len;

    //number of bytes necessary to store dna_str as a bitset
    size_t dna_bytes = (dna_len / 4) + (dna_len % 4 != 0);

    m_data = new uint8_t[dna_bytes];

    std::memset(m_data, 0, dna_bytes);

    // for each base of the DNA sequence

    for (size_t i = 0; i < dna_len; ++i)
    {
        uint8_t shift = 6 - 2 * (i % 4);

        switch (dna_str[i])
        {
            case 'A':
                m_data[i / 4] |= base_nucleotide.BASE_A << shift;
                break;
            case 'C':
                m_data[i / 4] |= base_nucleotide.BASE_C << shift;
                break;
            case 'G':
                m_data[i / 4] |= base_nucleotide.BASE_G << shift;
                break;
            case 'T':
                m_data[i / 4] |= base_nucleotide.BASE_T << shift;
                break;
            default:
                throw std::invalid_argument("invalid DNA");
        }

        shift = (shift == 0) ? 6 : shift - 2;
    }
    return *this;
}

DnaSequence & DnaSequence::operator = (const std::string & dna_str)
{
    size_t dna_len = dna_str.length();

    m_len = dna_len;

    //number of bytes necessary to store dna_str as a bitset
    size_t dna_bytes = (dna_len / 4) + (dna_len % 4 != 0);

    m_data = new uint8_t[dna_bytes];

    std::memset(m_data, 0, dna_bytes);

    // for each base of the DNA sequence

    for (size_t i = 0; i < dna_len; ++i)
    {
        uint8_t shift = 6 - 2 * (i % 4);

        switch (dna_str[i])
        {
            case 'A':
                m_data[i / 4] |= base_nucleotide.BASE_A << shift;
                break;
            case 'C':
                m_data[i / 4] |= base_nucleotide.BASE_C << shift;
                break;
            case 'G':
                m_data[i / 4] |= base_nucleotide.BASE_G << shift;
                break;
            case 'T':
                m_data[i / 4] |= base_nucleotide.BASE_T << shift;
                break;
            default:
                throw std::invalid_argument("invalid DNA");
        }

        shift = (shift == 0) ? 6 : shift - 2;
    }

    return *this;
}

DnaSequence::~DnaSequence()
{
    delete[] m_data;
}

std::ostream &operator<<(std::ostream &os,const DnaSequence& dnaSequence)
{
    os << (std::string)dnaSequence.to_string();
    return os;
}

char & DnaSequence::operator[](size_t pos)
{
//    if(pos > this->getLen())
//    {
//        throw DNAException((char *)"Invalid index");
//    }
    char* str = to_string();
    return str[pos];
}

void DnaSequence::insert(nucleotide nuc, size_t index)
{
//    if(index > this->getLen())
//    {
//        throw DNAException((char *)"Invalid index");
//    }
    std::string temp = this->to_string();
    temp[index] = nuc;
    *this = temp;
}

size_t DnaSequence:: getLen()
{
    return m_len;
}

char* DnaSequence::to_string() const
{
    char* dna_str = new char[m_len + 1];

    // for each base of the DNA sequence
    for (size_t i = 0; i < m_len; ++i)
    {
        uint8_t shift = 6 - 2 * (i % 4);
        uint8_t mask = BASE_MASK << shift;

        // get the i-th DNA base
        uint8_t base = (m_data[i / 4] & mask) >> shift;

        switch (base)
        {
            case 0x0:
                dna_str[i] = 'A';
                break;
            case 0x1:
                dna_str[i] = 'C';
                break;
            case 0x2:
                dna_str[i] = 'G';
                break;
            case 0x3:
                dna_str[i] = 'T';
                break;
            default:
                throw std::runtime_error("invalid DNA base");
        }
    }

    dna_str[m_len] = '\0';
    return dna_str;
}

DnaSequence DnaSequence::slice(size_t start, size_t end) const
{
//    if(start > this->m_len || end > this->m_len)
//    {
//        throw DNAException((char *)"Invalid index");
//    }
    std::string res_str = this->to_string();
    res_str = res_str.substr(start+1,end-start-1);
    return DnaSequence(res_str);
}
DnaSequence DnaSequence::pair() const
{
    std::string dna_str;
    std::string result;
    int j,i;
    dna_str = this->to_string();
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

long DnaSequence::find(const std::string &sequence) const
{
    std::string dna_str = this->to_string();
    return dna_str.find(sequence);
}

size_t DnaSequence::count(const std::string &sequence) const/* returns*/
{
    std::string dna_str;
    long index;
    long result;
    dna_str = this->to_string();
    index = dna_str.find(sequence);
    result = 0;
    while(index != -1)
    {
        result++;
        dna_str.erase(index,sequence.length());
        index = dna_str.find(sequence);
    }
    return result;
}
std::vector<int> DnaSequence::findall(const std::string &sequence) const/* returns*/
{
    std::string dna_str;
    long index;
    std::vector<int> result;
    dna_str = this->to_string();
    index = dna_str.find(sequence);
    while(index != -1)
    {
        result.push_back(index + sequence.size()*result.size());
        dna_str.erase(index,sequence.length());
        index = dna_str.find(sequence);
    }
    return result;
}



std::vector<std::string> DnaSequence::FindConsensus() const
{
    std::string dna_seq = this->to_string();
    std::vector<std::string> ConsensusSequence;
    std::string startcodons = "ATG";
    std::string endcodons[] = {"TAG", "TAA", "TGA"};
    std::vector<int> start_list = this->findall(startcodons);
    std::vector<int>::iterator it = start_list.begin();
    for (; it != start_list.end(); it++) {
        DnaSequence new_dna(this->slice((*it), dna_seq.length()));
        std::string new_string= new_dna.to_string();
        if (new_string.empty())
            return ConsensusSequence;
        for (size_t i = 0; i < endcodons->size(); ++i) {
            std::vector<int> endcodon_list = new_dna.findall(endcodons[i]);
            std::vector<int>::iterator it1 = endcodon_list.begin();
            for (; it1 != endcodon_list.end(); it1++) {
                if ((*it1) % 3 == 0) {
                    std::string get_seq = (new_dna.slice(0, (*it) + 3)).to_string();
                    ConsensusSequence.push_back(get_seq);
                }
            }
        }
    }
    return ConsensusSequence;
}