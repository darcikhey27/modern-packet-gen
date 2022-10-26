#ifndef _TYPES_H_
#define _TYPES_H_

typedef unsigned char           byte;
typedef unsigned char           u8;
typedef signed char             i8;
typedef unsigned short          u16;
typedef signed short            i16;
typedef unsigned                u32;
typedef int                     i32;
typedef unsigned long           u64;
typedef long                    i64;
typedef float                   f32;
typedef double                  f64;
typedef __int128_t              i128;
typedef __uint128_t             u128;

#define MODERN_PKT_GEN_PATHLEN   512

#define ETHERNET_ADDRESS_LENGTH ETH_ALEN

/* MAC address */
struct ethernet_mac_address {
    u8 address[ETHERNET_ADDRESS_LENGTH];
};

/* ethernet frame header */
struct ethernet_header {
    u8 ethernet_dest[ETHERNET_ADDRESS_LENGTH];
    u8 ethernet_source[ETHERNET_ADDRESS_LENGTH];
    u16 ethernet_type;
};

struct ip_header {
    u32 ihl:4;
    u32 version:4;
    u8 tos;
    u16 tot_len;
    u16 id;
    u16 frag_off;
    u8 ttl;
    u8 protocol;
    u16 check;
    u32 saddr;
    u32 daddr;
}
/* 
 * Redefining networking stuff to make it more readable
*/

#endif /* _TYPES_H_ */