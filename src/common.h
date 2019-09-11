#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define DEBUG_PRINT 0
#define DEBUGF(fmt, rest...) \
        ({if(DEBUG_PRINT) { printf("%s():%d " fmt "\n", __FUNCTION__, __LINE__, ##rest); }})
#define LOG(fmt, rest...) printf("descsock: " fmt "\n", ##rest);

#define DOORBELL_SOCKET "/var/run/server.sock"



#endif /*_COMMON_H_ */