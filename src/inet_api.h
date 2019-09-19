#ifndef _INET_API_H_
#define _INET_API_H_


int sys_get_interfaces(char *buf);

int set_interface_ip(char *if_name, char *ip_addr, char *net_mask);

int set_interface_mac(char *if_name, char *mac);

void get_interface_mac(int tap_fd, u8 *mac);

int tap_open(const char *name);

#endif /* _INET_API_H_ */