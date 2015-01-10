#ifndef API_H
#define API_H

#ifdef __cplusplus
extern "C" {
#endif


typedef void VirtualMachine_;

typedef struct {
    unsigned char *data;
    unsigned int len;
} result;
void free_res(result *_res);

VirtualMachine_ *makeJIT();
void freeJIT(VirtualMachine_* vm);
result *run(VirtualMachine_ *vm, char *code, int len);


#ifdef __cplusplus
} // extern "C"
#endif

#endif
