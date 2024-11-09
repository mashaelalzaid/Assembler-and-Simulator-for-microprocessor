
#include "decoder.h"

control_flags_t check_control_flags(unsigned char byte) {
    control_flags_t flags;

    flags.j = (byte & 0x80) ? 1 : 0; // Most significant bit (bit 7)
    flags.c = (byte & 0x40) ? 1 : 0; 
    flags.d1 = (byte & 0x20) ? 1 : 0; 
    flags.d0 = (byte & 0x10) ? 1 : 0; 
    flags.Sreg = (byte & 0x08) ? 1 : 0; 
    flags.s = (byte & 0x04) ? 1 : 0; 
    flags.imm1 = (byte & 0x02) ? 1 : 0; 
    flags.imm2 = (byte & 0x01) ? 1 : 0; // Least significant bit (bit 0)

    return flags;
}
