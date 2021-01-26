//
// Created by ayelet on 9/22/20.
//

#ifndef PREWORK3_MSG_PRINTER_H
#define PREWORK3_MSG_PRINTER_H
#include <iostream>

class MsgPrinter  {
protected:
     std::string message;//change the const
public:
    //ctor and dtor
    MsgPrinter(const std::string &message);

    virtual ~MsgPrinter();
    //functions
    virtual void print();
};


class MsgPrinterSurrounding:public MsgPrinter
{
private:

    char * before;
    char * after;

public:
    //ctor
    MsgPrinterSurrounding(const std::string &message);

    MsgPrinterSurrounding(const std::string &message, const std::string & before_msg, const std::string & after_msg);

    MsgPrinterSurrounding(const std::string &message, const char * before_msg, const char * after_msg);
    //copy ctor
    MsgPrinterSurrounding(const MsgPrinterSurrounding & source);

    virtual ~MsgPrinterSurrounding();

    MsgPrinterSurrounding& operator=(const MsgPrinterSurrounding& source);

    void print();

protected:
    //function
    virtual void print_before();

    void print_after();
};


class MsgPrinterMultipleSurrounding:public MsgPrinterSurrounding
{
private:
    unsigned char times;
public:
    //ctor and dtor
    MsgPrinterMultipleSurrounding(const std::string &message, unsigned char times=2);

    MsgPrinterMultipleSurrounding(const std::string &message, const std::string &beforeMsg, const std::string &afterMsg,
                                  unsigned char times=2);

    MsgPrinterMultipleSurrounding(const std::string &message, const char *beforeMsg, const char *afterMsg,
                                  unsigned char times=2);

    MsgPrinterMultipleSurrounding(const MsgPrinterSurrounding &source, unsigned char times=2);

     ~MsgPrinterMultipleSurrounding();

    //set and get
    void set_times(unsigned char times);

    unsigned char get_times() const;

    void print_before();

    void print_after();

};

#endif //PREWORK3_MSG_PRINTER_H
