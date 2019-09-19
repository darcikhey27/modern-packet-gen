#define _GNU_SOURCE     /* To get defns of NI_MAXSERV and NI_MAXHOST */
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <linux/if_link.h>

#include "common.h"
#include "inet_api.h"



/*
 * Takes a char pointer with pre-allocated size of atleast BUFSIZ/8192 bytes
 * Return a string with all linux interfaces names
 */
int get_sys_interfaces(char *buf)
{
    struct ifaddrs *ifaddr, *ifa;
    char temp[BUFSIZ];

    /*XXX: check str len */
    if(buf == NULL) {
        LOG("buf is null");
        return -1;
    }

    if (getifaddrs(&ifaddr) == -1) {
        LOG("getifaddrs %s", strerror(errno));
        return -1;
    }

    /*
     * Walk through linked list, maintaining head pointer so we
     * can free list later
     */
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }
        
        /* comma separated values*/
        sprintf(temp, "%s,", ifa->ifa_name);
        strcat(buf, temp);   
    }

    freeifaddrs(ifaddr);

    return 1;
}
