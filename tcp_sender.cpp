#include "./socket_lib/Socket.hpp"
#include <string.h>

using namespace std;

//#define IP   "127.0.0.1"
#define IP   "183.230.40.33"
#define PORT 80

#if 1
char *cmd = "GET /devices/634648/datapoints?first=0 HTTP/1.1\r\n\
User-Agent: curl/7.22.0 (x86_64-pc-linux-gnu) libcurl/7.22.0 OpenSSL/1.0.1 zlib/1.2.3.4 libidn/1.23 librtmp/2.3\r\n\
Host: 127.0.0.1\r\n\
Accept: */*\r\n\
api-key:nJCjW8bhvx=aWcIJcogptgbNo0I=\r\n\r\n";
#else
#endif

int main (void) {
    try {
        Socket::TCP client;
        client.connect_to (Socket::Address (IP, PORT));

        cout << "sending ..." << endl;
        //client.send_file ("input.bmp");
        client.send (cmd, strlen(cmd));
        //rcv
        char buf[512];
        memset (buf, 0, sizeof (buf));
        client.receive (buf, sizeof(buf));
        printf ("rcv:\n%s\n", buf);
    } catch (Socket::SocketException &e) {
        cout << e << endl;
    }

    return 0;
}
