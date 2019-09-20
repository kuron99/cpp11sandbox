#include <cstdio>
#include <cstdlib>
#include <unistd.h>

void
func(size_t request_size){
    char *buf;
    buf = (char*)malloc(request_size);
    printf("request size: 0x%lx\n",request_size);
    printf("obtained pointer: 0x%lx\n",buf);
    size_t offset = *(size_t*)(buf-16);
    size_t size = *(size_t*)(buf-8);
    printf("size = 0x%x\n",size);
    if(size & 2){
        printf("Memory is mmapped.\n");
        size ^= 2;
        printf("offset = 0x%x\n",offset);
        printf("chunk size = 0x%x\n",size);
    }
    free(buf);
}

int
main(void){
    printf("page size = 0x%x\n",getpagesize());
    func(1<<18);
}
