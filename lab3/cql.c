#include "types.h"
#include "user.h"
#include "stat.h"

int
main(int argc, char *argv[]) {
    change_queue_level(atoi(argv[1]), atoi(argv[2]));
    exit();
}
