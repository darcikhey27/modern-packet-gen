#ifndef _PKT_CONF_H
#define _PKT_CONF_H

#include "types.h"

typedef enum {
    ICMP = 0,
    ARP,
    TCP,
    /* XXX: Add more */

} pkt_type_t;

struct pkt_conf {
    pkt_type_t  type;
    u32         length;
};

extern struct pkt_conf pkt_conf;

#endif
