
#include "Management.h"
#include "fileIO.h"
void Management::save(DnaSequence dna, const char * file_name)
{
    fileIO::writing_dnaSeq_file(file_name, dna);
}

void Management::rename(std::string old_name, std::string new_name) {

}
