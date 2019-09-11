#ifndef _PKT_CONF_H
#define _PKT_CONF_H

#include <linux/if_ether.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>


#include "types.h"

typedef enum {
    ICMP = 0,
    ARP,
    TCP,
    /* XXX: Add more */

} pkt_type_t;

struct pkt_conf {
    /* Link layer */
    struct ethhdr   ether_header;
    /* Internet layer */
    struct iphdr    ip_header;
    /* Transport layer */
    union {
        struct udphdr   udp_header;
        struct tcphdr   tcp_hader;
    }l4;

    /* Add rest of packet options here */

};

extern struct pkt_conf pkt_conf;

#endif
