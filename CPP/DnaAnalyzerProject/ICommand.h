

#ifndef DNAANALYZERPROJECT_COMMAND_H
#define DNAANALYZERPROJECT_COMMAND_H

#include "DnaCollection.h"


class ICommand
{
public:
    virtual void execute(DnaCollection & dnaCollection, std::vector<std::string> & input) = 0;
};


#endif //DNAANALYZERPROJECT_COMMAND_H
