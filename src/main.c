#include <sys/socket.h>
#include <sys/un.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#include "common.h"
#include "sys.h"
#include "inet_api.h"
#include "main.h"

int
initialize_doorbell_socket()
{
    int fd;
    int rv;
    int backlog = 10;
    struct sockaddr_un server_addr;

    // XXX temporary, do cleanup
    unlink(DOORBELL_SOCKET);

    /* get handle for a socket */
    fd = socket(PF_UNIX, SOCK_STREAM, 0);
    if (fd < 0) {
        LOG("Failed to get UNIX socket: %s", strerror(errno));
        return -1;
    }

    /* Set socket type and path */
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, DOORBELL_SOCKET, sizeof(server_addr.sun_path) -1);

    /* bind server address information to the socket fd */
    rv = bind(fd, (struct sockaddr *)&server_addr, sizeof(server_addr.sun_path) -1);
    if (rv < 0) {
        LOG("Failed to bind UNIX socket %s", strerror(errno));
        return -1;
    }

    /* Listen on socket */
    rv = listen(fd, backlog);
    if(rv < 0) {
        LOG("Error on listen %s", strerror(errno));
    }

    return fd;
}

int
main(int argc, char *argv[])
{

    char buf[BUFSIZ];

    get_sys_interfaces(buf);

    printf("buf:\n%s\n", buf);

    printf("compiled!\n");
    return EXIT_SUCCESS;
}
