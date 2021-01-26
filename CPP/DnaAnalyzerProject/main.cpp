#include <iostream>
#include "DnaCollection.h"
#include "creation.h"
#include "Management.h"
#include "Manipulation.h"
std::vector<std::string> split(const std::string& str,const std::string& sep = " "){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    std::vector<std::string> arr;
    current=strtok(cstr,sep.c_str());
    while(current != NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}
DnaSequenceDecorator get_seq_dec(DnaCollection & dnaCollection,std::string seq)
{
    DnaSequenceDecorator res;
    if(seq[0] == '@') {
        seq = seq.substr(1, seq.size());
        res = dnaCollection.get_seq(seq);
    }
    else if(seq[0] == '#')
    {
        seq = seq.substr(1, seq.size());
        int id;
        sscanf(seq.c_str(), "%d", &id);
        res = dnaCollection.get_seq_by_id(id);
    }
    return res;
}
void command_new(DnaCollection & dnaCollection,std::vector<std::string> &input)
{
    static size_t id_name_new = 1;
    std::string seq;
    std::string name = "";
    seq = input[1];
    if(input.size() == 2)
    {
        DnaSequence new_seq= creation::new_command((char *) seq.c_str());
        DnaSequenceDecorator DecDna;
        char num = id_name_new + 48;
        name = name + "seq" + num;
        id_name_new++;
        DecDna.m_dnaSequence = new_seq;
        DecDna.m_name = name;
        dnaCollection.insert_seq(std::pair<std::string,DnaSequenceDecorator>(name, DecDna));
        dnaCollection.print_by_name(name);
    }
    else{
        name = input[2];
        name = name.substr(1, name.size());
        DnaSequence new_seq= creation::new_command((char *) seq.c_str());
        DnaSequenceDecorator DecDna;
        DecDna.m_dnaSequence = new_seq;
        DecDna.m_name = name;
        dnaCollection.insert_seq(std::pair<std::string,DnaSequenceDecorator>(name, DecDna));
        dnaCollection.print_by_name(name);
    }
}
void command_dup(DnaCollection &dnaCollection,std::vector<std::string> &input)
{
    static size_t id_name_dup = 1;
    std::string command;
    std::string seq;
    std::string name;
    char *data;
    DnaSequenceDecorator seq_dec = get_seq_dec(dnaCollection,input[1]);
    if (input.size() == 2)
    {
        DnaSequence dup_dna = creation::dup_command(seq_dec.m_dnaSequence.to_string());
        char num = id_name_dup + 48;
        name = seq_dec.get_name() + "_" + num;
        id_name_dup++;
        DnaSequenceDecorator DecDna;
        DecDna.m_dnaSequence = dup_dna;
        DecDna.m_name = name;
        dnaCollection.insert_seq(std::pair<std::string, DnaSequenceDecorator> (name, DecDna));
        dnaCollection.print_by_name(name);
    }
    else if (input.size() == 3)
    {
        DnaSequence dup_dna = creation::dup_command(seq_dec.m_dnaSequence.to_string());
        DnaSequenceDecorator DecDna;
        name = input[2].substr(1,input[2].size());
        DecDna.m_dnaSequence = dup_dna;
        DecDna.m_name = name;
        dnaCollection.insert_seq(std::pair<std::string, DnaSequenceDecorator> (name, DecDna));
        dnaCollection.print_by_name(name);
    }
}
void command_save(DnaCollection &dnaCollection,std::vector<std::string> &input)
{
    std::string command;
    std::string seq;
    std::string name;
    DnaSequence dna;
    seq = input[1];
    dna = get_seq_dec(dnaCollection,seq).m_dnaSequence;
    if(input.size() == 2)
    {
        std::string file_name = seq + ".rawdna.txt";
        Management::save(dna,file_name.c_str());
    }
    else{
        name = input[2];
        name += ".txt";
        Management::save(dna,name.c_str());
    }

}
void command_load(DnaCollection & dnaCollection, std::vector<std::string> &input)
{
    std::string command;
    std::string file_name;
    std::string seq_name;
    file_name = input[1] + ".txt";
    if(input.size() == 2)
        seq_name = input[1].substr(0,input[1].find('.'));
    else
        seq_name = input[2].substr(1,input.size());
    DnaSequence load_item = creation::load_command(file_name.c_str());
    DnaSequenceDecorator DecDna;
    DecDna.m_dnaSequence = load_item;
    DecDna.m_name = seq_name;
    dnaCollection.insert_seq(std::pair<std::string,DnaSequenceDecorator>(seq_name, DecDna));
    dnaCollection.print_by_name(seq_name);
}
void command_replace(DnaCollection & dnaCollection, std::vector<std::string> & input)
{
    static size_t id_name_replace = 1;
    std::string seq;
    std::vector<std::pair<size_t ,char> > index_and_letter;
    std::string name;
    size_t index_nekudataim = 0;
    for (int k = 1; k < input.size(); k++)
    {
        if(input[k] == ":")
            index_nekudataim = k;
    }
    if (index_nekudataim == 0)
    {
        size_t i = 2;
        while(i != input.size())
        {
            std::pair<size_t ,char> element;
            sscanf(input[i].c_str(), "%d", &element.first);
            element.second = input[++i][0];
            index_and_letter.push_back(element);
            i++;
        }
        seq = input[1].substr(1,input[1].size());
        DnaSequence dna_to_replace = get_seq_dec(dnaCollection,input[1]).m_dnaSequence;
        seq = get_seq_dec(dnaCollection,input[1]).m_name;
        DnaSequence dna_replace = Manipulation::replace(dna_to_replace, index_and_letter);
        dnaCollection.set_dna_by_name(dna_replace,seq);
        dnaCollection.print_by_name(seq);
        return;
    }
    int i = 2;
    while(input[i] != ":")
    {
        std::pair<size_t ,char> element;
        sscanf(input[i].c_str(), "%d", &element.first);
        element.second = input[++i][0];
        index_and_letter.push_back(element);
        i++;
    }
    seq = input[1].substr(1,input[1].size());
    DnaSequence dna_to_replace = get_seq_dec(dnaCollection,input[1]).m_dnaSequence;
    seq = get_seq_dec(dnaCollection,input[1]).m_name;
    DnaSequence dna_replace = Manipulation::replace(dna_to_replace, index_and_letter);
    if (input[++i][0] == '@' && input[i][1] == '@' && input[i].size() == 2)
    {
        char num = id_name_replace + 48;
        name = seq + "_r" + num;
        id_name_replace++;
        DnaSequenceDecorator DecDna;
        DecDna.m_dnaSequence = dna_replace;
        DecDna.m_name = name;
        dnaCollection.insert_seq(std::pair<std::string, DnaSequenceDecorator>(name, DecDna));
        dnaCollection.print_by_name(name);
    }
    else
    {
        name = input[i].substr(1,input[i].size());
        DnaSequenceDecorator DecDna;
        DecDna.m_dnaSequence = dna_replace;
        DecDna.m_name = name;
        dnaCollection.insert_seq(std::pair<std::string, DnaSequenceDecorator>(name, DecDna));
        dnaCollection.print_by_name(name);
    }

}
void command_pair(DnaCollection & dnaCollection, std::vector<std::string> & input)
{
    static size_t id_name_pair = 1;
    std::string name;
    DnaSequenceDecorator seq_dec = get_seq_dec(dnaCollection,input[1]);
    DnaSequence dna_to_pair = seq_dec.m_dnaSequence;
    DnaSequence dna_pair = Manipulation::pair(dna_to_pair);
    if(input.size() == 2)
    {
        name = seq_dec.m_name;
        dnaCollection.set_dna_by_name(dna_pair,name);
        dnaCollection.print_by_name(name);
    }
    else if (input[3][0] == '@' && input[3][1] == '@' && input[3].size() == 2)
    {
        char num = id_name_pair + 48;
        name = seq_dec.m_name + "_p" + num;
        id_name_pair++;
        DnaSequenceDecorator DecDna;
        DecDna.m_dnaSequence = dna_pair;
        DecDna.m_name = name;
        dnaCollection.insert_seq(std::pair<std::string, DnaSequenceDecorator>(name, DecDna));
        dnaCollection.print_by_name(name);
    }
    else
    {
        name = input[3].substr(1,input[3].size());
        DnaSequenceDecorator DecDna;
        DecDna.m_dnaSequence = dna_pair;
        DecDna.m_name = name;
        dnaCollection.insert_seq(std::pair<std::string, DnaSequenceDecorator>(name, DecDna));
        dnaCollection.print_by_name(name);
    }
}

void command_concat(DnaCollection & dnaCollection, std::vector<std::string> & input)
{
    static size_t id_name_concat = 1;
    size_t index_nekudataim = 0;
    std::string name = get_seq_dec(dnaCollection,input[1]).m_name;
    for (int i = 1; i < input.size(); i++)
    {
        if(input[i] == ":")
            index_nekudataim = i;
    }
    if(index_nekudataim == 0)//the concat on the first seq
    {
        DnaSequence dna_res_concat = get_seq_dec(dnaCollection,input[1]).m_dnaSequence;
        DnaSequence dna_second_concat;
        for(int i = 2; i < input.size(); i++)
        {
            dna_second_concat = get_seq_dec(dnaCollection,input[i]).m_dnaSequence;
            dna_res_concat = Manipulation::concat(dna_res_concat,dna_second_concat);
        }
        dnaCollection.set_dna_by_name(dna_res_concat,name);
        dnaCollection.print_by_name(name);
        return;
    }
    DnaSequence dna_res_concat = get_seq_dec(dnaCollection,input[1]).m_dnaSequence;
    DnaSequence dna_second_concat;
    for(int i = 2; i < index_nekudataim; i++)
    {
        dna_second_concat = get_seq_dec(dnaCollection,input[i]).m_dnaSequence;
        dna_res_concat = Manipulation::concat(dna_res_concat,dna_second_concat);
    }
    if (input[index_nekudataim + 1][0] == '@' && input[index_nekudataim + 1][1] == '@' && input[index_nekudataim + 1].size() == 2)
    {
        char num = id_name_concat + 48;
        name = name + "_c" + num;
        id_name_concat++;
    }
    else
    {
        name = input[index_nekudataim + 1].substr(1,input[index_nekudataim + 1].size());
    }
    DnaSequenceDecorator DecDna;
    DecDna.m_dnaSequence = dna_res_concat;
    DecDna.m_name = name;
    dnaCollection.insert_seq(std::pair<std::string, DnaSequenceDecorator>(name, DecDna));
    dnaCollection.print_by_name(name);
}

int main()
{
   DnaCollection dnaCollection;
    std::cout<<"> cmd >>> ";
    std::string line;
    std::getline (std::cin,line);
    std::vector<std::string> input = split(line);
    while(input[0] != "quit")
    {
        if (input[0] == "new") {
            command_new(dnaCollection, input);
        } else if (input[0] == "dup") {
            command_dup(dnaCollection, input);
        } else if (input[0] == "load") {
            command_load(dnaCollection, input);
        } else if (input[0] == "save") {
            command_save(dnaCollection, input);
        }
        else if(input[0] == "replace")
        {
            command_replace(dnaCollection, input);
        }
        else if(input[0] == "pair")
        {
            command_pair(dnaCollection, input);
        }
        else if(input[0] == "concat")
        {
            command_concat(dnaCollection, input);
        }
        std::cout<<"> cmd >>> ";
        std::getline (std::cin,line);
        input = split(line);
    }
    return 0;
}