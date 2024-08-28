#ifndef B_UTIL_H_
#define B_UTIL_H_

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <cstdint>

#define println(m, ...) printf(m,  __VA_ARGS__, "\n");
#define ASSERT(_e, ...) if (!(_e)) { fprintf(stderr, __VA_ARGS__); exit(B_UNKF); }

#ifdef DEBUG
#define LOG(m, ...) printf(m, __VA_ARGS__);
#endif
#ifndef DEBUG
#define LOG(m, ...) 
#endif

#define dot(v0, v1)                  \
    ({ const v2 _v0 = (v0), _v1 = (v1); (_v0.x * _v1.x) + (_v0.y * _v1.y); })
#define length(v) ({ const v2 _v = (v); sqrtf(dot(_v, _v)); })
#define normalize(u) ({              \
        const v2 _u = (u);           \
        const f32 l = length(_u);    \
        (v2) { _u.x / l, _u.y / l }; \
    })
#define min(a, b) ({ __typeof__(a) _a = (a), _b = (b); _a < _b ? _a : _b; })
#define max(a, b) ({ __typeof__(a) _a = (a), _b = (b); _a > _b ? _a : _b; })
#define sign(a) ({                                       \
        __typeof__(a) _a = (a);                          \
        (__typeof__(a))(_a < 0 ? -1 : (_a > 0 ? 1 : 0)); \
    })

typedef float    f32;
typedef double   f64;
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;
typedef size_t   usize;
typedef ssize_t  isize;

typedef struct v2_s  { f32 x, y; } v2;
typedef struct v2i_s { i32 x, y; } v2i;

typedef SDL_Event bInputEvent;

typedef enum {
    B_SUCCESS        = 0, 
    B_UNKF           = 1, // unkf = unknown failure
    B_OTHER          = -1, 
    B_SDL_INIT_FAIL  = -2, // failed to initialize SDL ()
    B_SDL_RUN_FAIL   = -3, // sdl failed during runtime
    B_SDL_CLOSE_FAIL = -4, // sdl failed while shut down
    B_UNFIT_ID       = -5  // error during pipeline update
} bReturnType;

#endif