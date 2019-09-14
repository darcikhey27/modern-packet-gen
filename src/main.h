#ifndef _MAIN_H_
#define _MAIN_H_

#include "common.h"

typedef struct {
    u32 id;
    bool active;
} pkt_gen_client_t;

/*
 * Function prototypes
 */
int initialize_doorbell_socket(void);



#endif /*_MAIN_H_ */
