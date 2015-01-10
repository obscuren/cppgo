#include "api.h"

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

void free_res(result *_res)
{
    delete _res->data;
    delete _res;
}

class VirtualMachine
{
    public:
        VirtualMachine() { printf("created virtual machine\n"); };
        ~VirtualMachine() { printf("destructed virtual machine\n"); }

        result *run(char *_code, int _len);
};

result *VirtualMachine::run(char *_code, int _len)
{
    result *r = new result();

    r->data = (unsigned char *)malloc(11);
    r->len = 11;
    memset(r->data, 0, 11);

    r->data = (unsigned char *)strdup("hello world");

    return r;
}

VirtualMachine_ *makeJIT()
{
    VirtualMachine *vm = new VirtualMachine();
    return (VirtualMachine_*)vm;
}

void freeJIT(VirtualMachine_* _vm)
{
    VirtualMachine *vm = static_cast<VirtualMachine*>(_vm);
    delete vm;
}

result *run(VirtualMachine_ *_vm, char *code, int _len)
{
    VirtualMachine *vm = static_cast<VirtualMachine*>(_vm);
    return vm->run(code, _len);
}

