#include "types.h"
#include "user.h"
#include "stat.h"

int
main(int argc, char *argv[]) {
    set_MHRRN_system_level_parameter(atoi(argv[1]));
    exit();
}
