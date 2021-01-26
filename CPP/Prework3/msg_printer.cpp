//
// Created by ayelet on 9/22/20.
//

#include "msg_printer.h"
#include <string.h>
//class MsgPrinter
MsgPrinter::MsgPrinter(const std::string &message) : message(message) {}

MsgPrinter::~MsgPrinter() {
    std::cout<<"End of MsgPrinter: "<<this->message<<"\n";
}

void MsgPrinter::print() {
    std::cout<<"Message: "<<this->message<<"\n";
};

//***********************************

//class MsgPrinterSurrounding
MsgPrinterSurrounding::MsgPrinterSurrounding(const std::string &message) : MsgPrinter(message)
{
    this->after=NULL;
    this->before=NULL;
}

MsgPrinterSurrounding::MsgPrinterSurrounding(const std::string &message, const std::string & before_msg, const std::string & after_msg) : MsgPrinter(message)
{
    this->before = new char[before_msg.size() + 1];
    std::copy(before_msg.begin(), before_msg.end(), this->before);
    this->before[before_msg.size()] = '\0';
    this->after = new char[after_msg.size() + 1];
    std::copy(after_msg.begin(), after_msg.end(), this->after);
    this->after[after_msg.size()] = '\0';
}

MsgPrinterSurrounding::MsgPrinterSurrounding(const std::string &message, const char * before_msg, const char * after_msg) : MsgPrinter(message)
{
    unsigned int len = sizeof(before_msg)/sizeof(char);
    this->before = new char[len];
    strcpy(this->before,before_msg);
    len = sizeof(after_msg) / sizeof(char);
    this->after = new char[len];
    strcpy(this->after,after_msg);
}

void MsgPrinterSurrounding::print_before() {
    if(this->before!=NULL)
       std::cout<<"Before: "<<this->before<<"\n";
    else
        std::cout<<"Before is NULL\n";
}

void MsgPrinterSurrounding::print_after() {
    if(this->after!=NULL)
       std::cout<<"After: "<<this->after<<"\n";
    else
        std::cout<<"After is NULL\n";
}

void MsgPrinterSurrounding::print() {
    this->print_before();
    MsgPrinter::print();
    this->print_after();
}

MsgPrinterSurrounding::~MsgPrinterSurrounding() {
    delete []this->before;
    delete []this->after;
    std::cout<<"End of MsgPrinterSorrounding: "<<this->message<<"\n";
}

MsgPrinterSurrounding::MsgPrinterSurrounding(const MsgPrinterSurrounding & source) : MsgPrinter(source.message)
{
    this->before = new char [sizeof(source.before)/sizeof(char)];
    strcpy(this->before,source.before);
    this->after = new char [sizeof(source.after)/sizeof(char)];
    strcpy(this->after,source.after);
}

MsgPrinterSurrounding &MsgPrinterSurrounding::operator=(const MsgPrinterSurrounding &source)  {
    this->message=source.message;
    this->before = new char [sizeof(source.before)/sizeof(char)];
    strcpy(this->before,source.before);
    this->after = new char [sizeof(source.after)/sizeof(char)];
    strcpy(this->after,source.after);
     return *this;
}

//***************************

//class MsgPrinterMultipleSurrounding
MsgPrinterMultipleSurrounding::MsgPrinterMultipleSurrounding(const std::string &message, unsigned char times)
        : MsgPrinterSurrounding(message), times(times) {}

MsgPrinterMultipleSurrounding::MsgPrinterMultipleSurrounding(const std::string &message, const std::string &beforeMsg,
                                                             const std::string &afterMsg, unsigned char times)
        : MsgPrinterSurrounding(message, beforeMsg, afterMsg), times(times) {}

MsgPrinterMultipleSurrounding::MsgPrinterMultipleSurrounding(const std::string &message, const char *beforeMsg,
                                                             const char *afterMsg, unsigned char times)
        : MsgPrinterSurrounding(message, beforeMsg, afterMsg), times(times) {}

MsgPrinterMultipleSurrounding::MsgPrinterMultipleSurrounding(const MsgPrinterSurrounding &source, unsigned char times)
        : MsgPrinterSurrounding(source), times(times) {}

void MsgPrinterMultipleSurrounding::set_times(unsigned char times) {
    this->times = times;
}

unsigned char MsgPrinterMultipleSurrounding::get_times() const {
    return times;
}

void MsgPrinterMultipleSurrounding::print_before() {
    for (int i = 0; i < this->times; ++i) {
        MsgPrinterSurrounding::print_before();
    }
}

void MsgPrinterMultipleSurrounding::print_after() {
    for (int i = 0; i < this->times; ++i) {
        MsgPrinterSurrounding::print_after();
    }
}

MsgPrinterMultipleSurrounding::~MsgPrinterMultipleSurrounding() {
    std::cout<<"End of MsgPrinterMultipleSurrounding: "<<this->message<<"\n";
}
