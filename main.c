#define _GNU_SOURCE
#include <cloudq.h>
int ConnectToIP(Universal ip) {
    SocketType sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET_VAL) return -1;
    struct sockaddr_in ServerAddr;
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(80);
    ServerAddr.sin_addr.s_addr = inet_addr(ip);
    int res = connect(sock, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
    if (res < 0) {
        close(sock);
        return -2;
    }
    return (int)sock;
}
int OpenSocket() {
    SocketType sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET_VAL) return -1;
    return (int)sock;
}
void CloseSocket(int sock) {
    if (sock >= 0) { 
        CLOSE_SOCKET((SocketType)sock);
    }
}
String FetchToRAM(Int32 sock, char* raw) {
    String responce;
    responce.data = raw;
    char chunk;
    Size totalb = 0;
    while (Recv(sock, &chunk, 1, 0) > 0) {
        raw[totalb] = chunk;
        totalb++;
    }
    responce.size = totalb;
    return responce;
}
Int32 GetIPFromDNS(Universal dns) {
    struct addrinfo hints, *res;
    for (Size i = 0; i < sizeof(hints); i++) {
        ((char*)&hints)[i] = 0;
    }
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(dns, "80", &hints, &res) != 0) return -1;
    struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
    Int32 ip_packed = (Int32)ipv4->sin_addr.s_addr;
    freeaddrinfo(res);
    return ip_packed;
}