#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit lim;
    getrlimit(RLIMIT_STACK, &lim);
    rlim_t OL = lim.rlim_cur;
    printf("stack size: %ld\n", OL);

    getrlimit(RLIMIT_NPROC, &lim);
    OL = lim.rlim_cur;
    printf("process limit: %ld\n", OL);

    getrlimit(RLIMIT_NOFILE, &lim);
    OL = lim.rlim_cur;
    printf("max file descriptors: %ld\n", OL);
    return 0;
}
