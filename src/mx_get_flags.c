#include "uls.h"

static void check_output_flags(t_flags *opts, char *flags);
static void check_info_flag(t_flags *opts, char *flags);
static void check_l_miniflags(t_flags *opts, char *flags);
static void check_gn_flags(t_flags *opts, char *flags);

t_flags *mx_get_flags(t_flags *fl, char *flags) {
    if(*++flags == '\0') {
        exit(1);
    }
    if(mx_is_valid_flag(flags)) {
        check_output_flags(fl, flags);
        check_info_flag(fl, flags);
        check_l_miniflags(fl, flags);
        check_gn_flags(fl, flags);
        if(!isatty(STDOUT_FILENO))
            fl->flag_G = false;
    }
    else {
        mx_printerr("usage: uls [-lC1aAGrRTngucSt] [file ...]\n");
        exit(1);
    }
    return fl;
}

static void check_output_flags(t_flags *opts, char *flags) {
    while(*flags) {
        switch (*flags) {
            case 'l': opts->flag_l = true;
                opts->flag_C = false;
                opts->flag_1 = false;
                break;
            case 'C': opts->flag_C = true;
                opts->flag_l = false;
                opts->flag_1 = false;
                break;
            case '1': opts->flag_1 = true;
                opts->flag_C = false;
                opts->flag_l = false;
                break;
            case 'r': opts->flag_r = true;
                break;
        }
        flags++;
    }
}

static void check_info_flag(t_flags *opts, char *flags) {
    while(*flags) {
        switch (*flags) {
            case 'a': opts->flag_a = true;
                opts->flag_A = false;
                break;
            case 'A':
                opts->flag_A = !opts->flag_a ? true : false;
                break;
            case 'G': opts->flag_G = true;
                break;
            case 'R': opts->flag_R = true;
                break;
            case 'S': opts->flag_S = true;
                break;
            case 't':
                opts->flag_t = !opts->flag_S ? true : false;
        }
        flags++;
    }
}

static void check_l_miniflags(t_flags *opts, char *flags) {
    while(*flags) {
        switch (*flags) {
        case 'T': opts->flag_T = true;
            break;
        case 'u': opts->flag_u = true;
            opts->flag_c = false;
            break;
        case 'c': opts->flag_c = true;
            opts->flag_u = false;
            break;
        }
        flags++;
    }
}

static void check_gn_flags(t_flags *opts, char *flags){
    while(*flags) {
        switch (*flags) {
            case 'n': opts->flag_n = true;
            opts->flag_l = true;
            opts->flag_C = false;
            opts->flag_1 = false;
            break;
        case 'g': opts->flag_g = true;
            opts->flag_l = true;
            opts->flag_C = false;
            opts->flag_1 = false;
            break;
        }
        flags++;
    }
}
