#define _GNU_SOURCE     /* To get defns of NI_MAXSERV and NI_MAXHOST */
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <fcntl.h>
#include <unistd.h>
/* Tun/Tap related. */
#include <netinet/ether.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <sys/ioctl.h>
#include <linux/if_link.h>

#include "common.h"
#include "inet_api.h"



/*
 * Takes a char pointer with pre-allocated size of atleast BUFSIZ/8192 bytes
 * Return a string with all linux interfaces names separated by comma
 */
int sys_get_interfaces(char *buf)
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

int
tap_open(const char *name)
{
    struct ifreq ifr = {{{0}}};
    int fd = -1, res = -1;

    fd = open("/dev/net/tun", O_RDWR);
    if (fd < 0) {
        LOG("Error opening /dev/net/tun");
        return fd;
    }

    ifr.ifr_flags = IFF_TAP | IFF_NO_PI;
    strncpy(ifr.ifr_name, name, IFNAMSIZ);

    res = ioctl(fd, TUNSETIFF, &ifr);
    if (res < 0) {
        LOG("TUNSETIFF ioctl failed: %s", strerror(errno));
        close(fd);
        return res;
    }

    return fd;
}

void
get_interface_mac(int fd, u8 *mac)
{
    struct ifreq ifr = {0};
    if(fd < 0) {
        LOG("Bad tap fd for get_hwaddr()");
        return;
    }

    /* Get MAC address */
    if(ioctl(fd, SIOCGIFHWADDR, &ifr) < 0) {
        LOG("Failed to get MAC address.");
        return;
    }

    memcpy(mac, ifr.ifr_hwaddr.sa_data, ETH_ALEN);
}