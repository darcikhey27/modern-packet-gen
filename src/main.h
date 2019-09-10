#ifndef _MAIN_H_
#define _MAIN_H_

#define DEBUG_PRINT 0
#define DEBUGF(fmt, rest...) \
        ({if(DEBUG_PRINT) { printf("%s():%d " fmt "\n", __FUNCTION__, __LINE__, ##rest); }})
#define LOG(fmt, rest...) printf("descsock: " fmt "\n", ##rest);

#define DOORBELL_SOCKET "/var/run/server.sock"

int initialize_doorbell_socket(void);

#endif
