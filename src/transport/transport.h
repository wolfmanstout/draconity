#pragma once
#include "cpptoml.h"

extern "C" {

#include <bson.h>
#include <stdint.h>

#define PUBLISH_TID 0

typedef struct __attribute__((packed)) {
    uint32_t tid, length;
} MessageHeader;

typedef bson_t *(*transport_msg_fn)(const std::vector<uint8_t> &msg);
extern void draconity_transport_main(transport_msg_fn callback, std::shared_ptr<cpptoml::table> config);
extern void draconity_transport_publish(const std::vector<uint8_t> msg);

} // extern "C"