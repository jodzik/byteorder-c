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

static inline uint16_t u16_from_le(uint8_t const* buf) {
    return (uint16_t)((uint16_t)buf[0] | ((uint16_t)buf[1] << 8));
}

static inline void u16_to_le(uint8_t* buf, uint16_t val) {
    buf[0] = (uint8_t)(val & 0xff);
    buf[1] = (uint8_t)(val >> 8);
}

static inline uint32_t u32_from_le(uint8_t const* buf) {
    return (uint32_t)buf[0] | ((uint32_t)buf[1] << 8) |
           ((uint32_t)buf[2] << 16) | ((uint32_t)buf[3] << 24);
}

static inline void u32_to_le(uint8_t* buf, uint32_t val) {
    buf[0] = (uint8_t)(val & 0xff);
    buf[1] = (uint8_t)((val >> 8) & 0xff);
    buf[2] = (uint8_t)((val >> 16) & 0xff);
    buf[3] = (uint8_t)(val >> 24);
}

static inline uint64_t u64_from_le(uint8_t const* buf) {
    return (uint64_t)u32_from_le(buf) | ((uint64_t)u32_from_le(&buf[4]) << 32);
}

static inline void u64_to_le(uint8_t* buf, uint64_t val) {
    u32_to_le(buf, (uint32_t)(val & 0xffffffffULL));
    u32_to_le(&buf[4], (uint32_t)(val >> 32));
}

#endif

#endif