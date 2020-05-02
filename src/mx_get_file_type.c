#include "uls.h"

char mx_get_file_type(mode_t val) {
    switch (val & 0xF000) {
        case 0x1000:
            return 'p'; // FIFO/pipe
        case 0x2000:
            return 'c'; // character device
        case 0x4000:
            return 'd'; // directory
        case 0x6000:
            return 'b'; // block device
        case 0x8000:
            return '-'; // regular file
        case 0xA000:
            return 'l'; // symlink
        case 0xC000:
            return 's'; // socket
        default:
            return '?'; // unknown
    }
}

char mx_get_file_perm(mode_t val) {
    switch (val & 0x001) {
        case 0x200:
            return '-'; // noexec
        default:
            return 'x'; // executable
    }
}
