#ifndef _INET_API_H_
#define _INET_API_H_


int get_sys_interfaces(char *buf);

int set_interface_ip(char *if_name, char *ip_addr, char *net_mask);

int set_interface_mac(char *if_name, char *mac);

#endif /* _INET_API_H_ */