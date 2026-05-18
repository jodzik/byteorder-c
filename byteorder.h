#ifndef BYTEORDER_H_
#define BYTEORDER_H_

#include <stdint.h>

#ifdef __ZEPHYR__

#include <zephyr/sys/byteorder.h>

static inline uint16_t u16_from_le(uint8_t const* buf) {
    return sys_get_le16(buf);
}

static inline void u16_to_le(uint8_t* buf, uint16_t val) {
    sys_put_le16(val, buf);
}

static inline uint32_t u32_from_le(uint8_t const* buf) {
    return sys_get_le32(buf);
}

static inline void u32_to_le(uint8_t* buf, uint32_t val) {
    sys_put_le32(val, buf);
}

static inline uint32_t u64_from_le(uint8_t const* buf) {
    return sys_get_le64(buf);
}

static inline void u64_to_le(uint8_t* buf, uint32_t val) {
    sys_put_le64(val, buf);
}

#else

uint16_t u16_from_be(uint8_t const* buf);
void u16_to_be(uint8_t* buf, uint16_t val);

uint32_t u32_from_be(uint8_t const* buf);
void u32_to_be(uint8_t* buf, uint32_t val);

#endif

#endif