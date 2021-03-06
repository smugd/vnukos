#include "VNK_Math.h"

/**
 * VNK_Min
 */
extern inline i8 VNK_MinI8(i8 a, i8 b) { return a < b ? a : b; }
extern inline u8 VNK_MinU8(u8 a, u8 b) { return a < b ? a : b; }
extern inline i16 VNK_MinI16(i16 a, i16 b) { return a < b ? a : b; }
extern inline u16 VNK_MinU16(u16 a, u16 b) { return a < b ? a : b; }
extern inline i32 VNK_MinI32(i32 a, i32 b) { return a < b ? a : b; }
extern inline u32 VNK_MinU32(u32 a, u32 b) { return a < b ? a : b; }
extern inline f32 VNK_MinF32(f32 a, f32 b) { return a < b ? a : b; }
extern inline f64 VNK_MinF64(f64 a, f64 b) { return a < b ? a : b; }

/**
 * VNK_Max
 */
extern inline i8 VNK_MaxI8(i8 a, i8 b) { return a > b ? a : b; }
extern inline u8 VNK_MaxU8(u8 a, u8 b) { return a > b ? a : b; }
extern inline i16 VNK_MaxI16(i16 a, i16 b) { return a > b ? a : b; }
extern inline u16 VNK_MaxU16(u16 a, u16 b) { return a > b ? a : b; }
extern inline i32 VNK_MaxI32(i32 a, i32 b) { return a > b ? a : b; }
extern inline u32 VNK_MaxU32(u32 a, u32 b) { return a > b ? a : b; }
extern inline f32 VNK_MaxF32(f32 a, f32 b) { return a > b ? a : b; }
extern inline f64 VNK_MaxF64(f64 a, f64 b) { return a > b ? a : b; }

/**
 * VNK_Abs
 */
extern inline i8 VNK_AbsI8(i8 a) { return a < 0 ? -a : a; }
extern inline u8 VNK_AbsU8(u8 a) { return a < 0 ? -a : a; }
extern inline i16 VNK_AbsI16(i16 a) { return a < 0 ? -a : a; }
extern inline u16 VNK_AbsU16(u16 a) { return a < 0 ? -a : a; }
extern inline i32 VNK_AbsI32(i32 a) { return a < 0 ? -a : a; }
extern inline u32 VNK_AbsU32(u32 a) { return a < 0 ? -a : a; }
extern inline f32 VNK_AbsF32(f32 a) { return a < 0 ? -a : a; }
extern inline f64 VNK_AbsF64(f64 a) { return a < 0 ? -a : a; }

f32 VNK_SinLookup[] = {
     0.000000,  0.017452,  0.034899,  0.052336,  0.069756,  0.087156,  0.104528,  0.121869,
     0.139173,  0.156434,  0.173648,  0.190809,  0.207912,  0.224951,  0.241922,  0.258819,
     0.275637,  0.292372,  0.309017,  0.325568,  0.342020,  0.358368,  0.374607,  0.390731,
     0.406737,  0.422618,  0.438371,  0.453991,  0.469472,  0.484810,  0.500000,  0.515038,
     0.529919,  0.544639,  0.559193,  0.573576,  0.587785,  0.601815,  0.615662,  0.629320,
     0.642788,  0.656059,  0.669131,  0.681998,  0.694658,  0.707107,  0.719340,  0.731354,
     0.743145,  0.754710,  0.766044,  0.777146,  0.788011,  0.798636,  0.809017,  0.819152,
     0.829038,  0.838671,  0.848048,  0.857167,  0.866025,  0.874620,  0.882948,  0.891007,
     0.898794,  0.906308,  0.913545,  0.920505,  0.927184,  0.933580,  0.939693,  0.945519,
     0.951057,  0.956305,  0.961262,  0.965926,  0.970296,  0.974370,  0.978148,  0.981627,
     0.984808,  0.987688,  0.990268,  0.992546,  0.994522,  0.996195,  0.997564,  0.998630,
     0.999391,  0.999848,  1.000000,  0.999848,  0.999391,  0.998630,  0.997564,  0.996195,
     0.994522,  0.992546,  0.990268,  0.987688,  0.984808,  0.981627,  0.978148,  0.974370,
     0.970296,  0.965926,  0.961262,  0.956305,  0.951056,  0.945519,  0.939693,  0.933580,
     0.927184,  0.920505,  0.913545,  0.906308,  0.898794,  0.891006,  0.882948,  0.874620,
     0.866025,  0.857167,  0.848048,  0.838671,  0.829038,  0.819152,  0.809017,  0.798635,
     0.788011,  0.777146,  0.766044,  0.754710,  0.743145,  0.731354,  0.719340,  0.707107,
     0.694658,  0.681998,  0.669131,  0.656059,  0.642788,  0.629321,  0.615661,  0.601815,
     0.587785,  0.573576,  0.559193,  0.544639,  0.529919,  0.515038,  0.500000,  0.484810,
     0.469472,  0.453991,  0.438371,  0.422618,  0.406737,  0.390731,  0.374606,  0.358368,
     0.342020,  0.325568,  0.309017,  0.292372,  0.275637,  0.258819,  0.241922,  0.224951,
     0.207912,  0.190809,  0.173648,  0.156434,  0.139173,  0.121869,  0.104528,  0.087156,
     0.069756,  0.052336,  0.034899,  0.017452, -0.000000, -0.017452, -0.034899, -0.052336,
    -0.069756, -0.087156, -0.104528, -0.121869, -0.139173, -0.156434, -0.173648, -0.190809,
    -0.207912, -0.224951, -0.241922, -0.258819, -0.275637, -0.292372, -0.309017, -0.325568,
    -0.342020, -0.358368, -0.374607, -0.390731, -0.406737, -0.422618, -0.438371, -0.453991,
    -0.469472, -0.484810, -0.500000, -0.515038, -0.529919, -0.544639, -0.559193, -0.573576,
    -0.587785, -0.601815, -0.615661, -0.629320, -0.642788, -0.656059, -0.669131, -0.681998,
    -0.694658, -0.707107, -0.719340, -0.731354, -0.743145, -0.754710, -0.766045, -0.777146,
    -0.788011, -0.798635, -0.809017, -0.819152, -0.829038, -0.838671, -0.848048, -0.857167,
    -0.866025, -0.874620, -0.882948, -0.891006, -0.898794, -0.906308, -0.913545, -0.920505,
    -0.927184, -0.933581, -0.939693, -0.945519, -0.951056, -0.956305, -0.961262, -0.965926,
    -0.970296, -0.974370, -0.978148, -0.981627, -0.984808, -0.987688, -0.990268, -0.992546,
    -0.994522, -0.996195, -0.997564, -0.998630, -0.999391, -0.999848, -1.000000, -0.999848,
    -0.999391, -0.998630, -0.997564, -0.996195, -0.994522, -0.992546, -0.990268, -0.987688,
    -0.984808, -0.981627, -0.978148, -0.974370, -0.970296, -0.965926, -0.961262, -0.956305,
    -0.951056, -0.945519, -0.939693, -0.933580, -0.927184, -0.920505, -0.913545, -0.906308,
    -0.898794, -0.891006, -0.882948, -0.874620, -0.866025, -0.857167, -0.848048, -0.838670,
    -0.829038, -0.819152, -0.809017, -0.798635, -0.788011, -0.777146, -0.766044, -0.754710,
    -0.743145, -0.731354, -0.719340, -0.707107, -0.694658, -0.681998, -0.669131, -0.656059,
    -0.642788, -0.629320, -0.615661, -0.601815, -0.587785, -0.573577, -0.559193, -0.544639,
    -0.529919, -0.515038, -0.500000, -0.484809, -0.469471, -0.453991, -0.438371, -0.422618,
    -0.406736, -0.390731, -0.374607, -0.358368, -0.342020, -0.325568, -0.309017, -0.292372,
    -0.275638, -0.258819, -0.241922, -0.224951, -0.207912, -0.190809, -0.173648, -0.156434,
    -0.139173, -0.121869, -0.104529, -0.087156, -0.069756, -0.052336, -0.034900, -0.017453
};

#define VNK_PI 3.141592

f32 VNK_SinF32(f32 a)
{
    return VNK_SinLookup[(int) (a * 180.0f / VNK_PI)       % 360];
}

f32 VNK_CosF32(f32 a)
{
    return VNK_SinLookup[(int)((a * 180.0f / VNK_PI) + 90) % 360];
}

f32 VNK_CeilF32(f32 a)
{
    int b = (int)a;
    if (a == b) {
        return b;
    }
    return b + 1;
}