//
// Created by ayelet on 12/13/20.
//

#ifndef DNAANALYZERPROJECT_FACTORYCOMMAND_H
#define DNAANALYZERPROJECT_FACTORYCOMMAND_H
#include "ICommand.h"

class FactoryCommand {
public:
    ICommand get_command(std::string);
};


#endif //DNAANALYZERPROJECT_FACTORYCOMMAND_H
