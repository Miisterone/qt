#include <QCoreApplication>
#include "tcp.h"
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Tcp tcp;
    tcp.startServer(7007);
    tcp.GetPath();

    QObject::connect(&tcp, &Tcp::newConnection, &tcp, &Tcp::handleNewConnection);


    Server server;
    server.createDatabase();

    return a.exec();
}
