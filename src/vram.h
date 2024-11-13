#ifndef GAMEBOY_VRAM_H
#define GAMEBOY_VRAM_H

#include "general.h"

#define VRAM_SIZE 65536 // 64KB Video RAM

extern struct EmulatorConfig config;

// VRAM debug print
#define VRAM_DEBUG_PRINT(fmt, ...)                                \
    if (config.debug_mode && config.verbose_level >= DEBUG_LEVEL) \
    {                                                             \
        PRINT_TIME_IN_SECONDS();                                  \
        PRINT_LEVEL(DEBUG_LEVEL);                                 \
        printf("VRM: ");                                          \
        printf(fmt, ##__VA_ARGS__);                               \
    }

#define VRAM_INFO_PRINT(fmt, ...)                                \
    if (config.debug_mode && config.verbose_level >= INFO_LEVEL) \
    {                                                            \
        PRINT_TIME_IN_SECONDS();                                 \
        PRINT_LEVEL(INFO_LEVEL);                                 \
        printf("VRM: ");                                         \
        printf(fmt, ##__VA_ARGS__);                              \
    }

#define VRAM_TRACE_PRINT(fmt, ...)                                \
    if (config.debug_mode && config.verbose_level >= TRACE_LEVEL) \
    {                                                             \
        PRINT_TIME_IN_SECONDS();                                  \
        PRINT_LEVEL(TRACE_LEVEL);                                 \
        printf("VRM: ");                                          \
        printf(fmt, ##__VA_ARGS__);                               \
    }

#define VRAM_WARN_PRINT(fmt, ...)                                \
    if (config.debug_mode && config.verbose_level >= WARN_LEVEL) \
    {                                                            \
        PRINT_TIME_IN_SECONDS();                                 \
        PRINT_LEVEL(WARN_LEVEL);                                 \
        printf("VRM: ");                                         \
        printf(fmt, ##__VA_ARGS__);                              \
    }

#define VRAM_ERROR_PRINT(fmt, ...) \
    {                               \
        PRINT_TIME_IN_SECONDS();    \
        PRINT_LEVEL(ERROR_LEVEL);   \
        printf("VRM: ");            \
        printf(fmt, ##__VA_ARGS__); \
    }

#define VRAM_EMERGENCY_PRINT(fmt, ...) \
    {                                   \
        PRINT_TIME_IN_SECONDS();        \
        PRINT_LEVEL(EMERGENCY_LEVEL);   \
        printf("VRM: ");                \
        printf(fmt, ##__VA_ARGS__);     \
    }

struct VRam
{
    // Data members
    uint8_t vram_byte[VRAM_SIZE];

    // Method pointers
    uint8_t (*get_vram_byte)(struct VRam *, uint16_t);
    void (*set_vram_byte)(struct VRam *, uint16_t, uint8_t);
    uint16_t (*get_vram_word)(struct VRam *, uint16_t);
    void (*set_vram_word)(struct VRam *, uint16_t, uint16_t);
};

// Function declarations
uint8_t vram_get_byte(struct VRam *self, uint16_t address);
void vram_set_byte(struct VRam *self, uint16_t address, uint8_t byte);
uint16_t vram_get_word(struct VRam *self, uint16_t address);
void vram_set_word(struct VRam *self, uint16_t address, uint16_t word);
struct VRam *create_vram(void);
void free_vram(struct VRam *self);

#endif