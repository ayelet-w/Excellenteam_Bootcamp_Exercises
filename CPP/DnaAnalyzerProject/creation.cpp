

#include "creation.h"
#include "DnaSequence.h"
#include "fileIO.h"
#include <string>


DnaSequence creation::new_command(char *seq)
{
    DnaSequence dna(seq);
    return dna;
}

DnaSequence creation::dup_command(char * seq)
{
    return new_command(seq);
}
DnaSequence creation::load_command(const char * file_name)
{
   return fileIO::reading_dnaSeq_file(file_name);
}