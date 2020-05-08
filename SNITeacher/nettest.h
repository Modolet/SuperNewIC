#ifndef NETTEST_H
#define NETTEST_H

#include "network.h"

class nettest : public network
{
public:
    nettest();
    bool Login(struct TEALogin);
    list<struct studentInfo> GetStudentList();
    bool sendMessage(int stuID,char* message);
};

#endif // NETTEST_H
