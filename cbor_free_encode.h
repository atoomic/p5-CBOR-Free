#ifndef CBOR_FREE_ENCODE
#define CBOR_FREE_ENCODE

#include <stdbool.h>

#include "cbor_free_common.h"
#include "cbor_free_boolean.h"

#define MAX_ENCODE_RECURSE 98

#define ENCODE_ALLOC_CHUNK_SIZE 1024

//typedef struct {
//    void *addr;
//    IV count;
//} reftracker;

typedef struct {
    STRLEN buflen;
    STRLEN len;
    char *buffer;
    void **reftracker;
    uint8_t recurse_count;
    uint8_t scratch[9];
    bool is_canonical;
    //reftracker* reflist;
} encode_ctx;

SV * cbf_encode( pTHX_ SV *value, encode_ctx *encode_state, SV *RETVAL );

#endif
