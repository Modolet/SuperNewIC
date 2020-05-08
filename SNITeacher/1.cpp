#include "1.h"
#include <QtNetwork/QTcpSocket>
#include <QMessageBox>

network::network()
{
    socket.connectToHost("sni.modolet.online",6666);
}

network::~network()
{

}

bool network::Login(TEALogin)
{
    return true;
}

