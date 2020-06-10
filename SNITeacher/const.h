#ifndef CONST_H
#define CONST_H
#include <QString>
//--------------------------------------这里是宏定义---------------------------------
//公共宏定义+++++++++++++++++++++++++
#define MSGFLAG             0x6666
//教师和服务器的通信ID+++++++++++++++++
#define TEAMSGLOGIN         0x1001
#define TEAMSGGETSTUINFO    0x1002
#define TEAMSGSEND          0x1003


//--------------------------------------这里是宏定义------------------------------end

//--------------------------------------这里是各种数据结构体---------------------------
//结构体基类+++++++++++++++++++++++++++++++
struct baseData
{
    short   msgID;
    short   msgFlag;
    short   MsgLen;
    baseData(short id,short len)
    {
        msgID   = id;
        msgFlag = MSGFLAG;
        MsgLen  = len;
    }
};

//登录结构体+++++++++++++++++++++++++++++++
struct TEALogin : public baseData
{
    int         userID;
    char        userPWD[16];
    TEALogin():baseData(TEAMSGLOGIN,sizeof(struct TEALogin)){};
};

////学生信息结构体++++++++++++++++++++++++++++
//struct studentInfo : public baseData
//{
//    int     stuID;
//    char    stuName[20];
//    studentInfo():baseData(TEAMSGGETSTUINFO,sizeof (struct studentInfo)){};
//};
////发送消息结构体++++++++++++++++++++++++++++
//struct teaSendMessage : public baseData
//{
//    int     stuID;
//    char    message[256];
//    teaSendMessage():baseData(TEAMSGSEND,sizeof(struct teaSendMessage)){};
//};
//教师信息结构体
struct info{
    QString name;
    QString sign;
};
//学生信息结构体
struct studentInfo{
    int id;
    QString name;
    QString classroom;
    QString sign;
    QString sex;
};

//--------------------------------------这里是各种数据结构体------------------------end




#endif // CONST_H
