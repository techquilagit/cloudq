#pragma once
#include <strinq.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#define INVALID_SOCKET_VAL -1
typedef int SocketType;
int OpenSocket();
void CloseSocket(int sock);
int ConnectToIP(Universal ip);
int SendTo(int sock, String request);
extern Intn Recv(Int32 sock, Universal buf, Size len, Int32 flags);
String FetchToRAM(Int32 sock, char* raw);
Int32 GetIPFromDNS(Universal dns);