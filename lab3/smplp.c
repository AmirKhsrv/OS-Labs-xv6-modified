#include "types.h"
#include "user.h"
#include "stat.h"

int
main(int argc, char *argv[]) {
    set_MHRRN_process_level_parameter(atoi(argv[1]), atoi(argv[2]));
    exit();
}