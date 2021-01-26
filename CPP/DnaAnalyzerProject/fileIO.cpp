
#include "fileIO.h"

#include <fstream>

DnaSequence fileIO::reading_dnaSeq_file(const char * path){
    DnaSequence dna("");
    std::string line;
    std::ifstream my_file;
    my_file.open(path);
    getline(my_file,line);
    dna = line;
    my_file.close();
    return dna;
}
void fileIO::writing_dnaSeq_file(const char * path, DnaSequence& dna){
    std::ofstream my_file;
    my_file.open (path);
    my_file << dna.to_string();
    my_file.close();
}
