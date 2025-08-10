#include "allocator.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

static void* allocator_alloc(void* user, size_t buffer_size)
{
    return malloc(buffer_size);
}

static void allocator_dealloc(void* user, void* buffer)
{
    free(buffer);
}

int main(int argc, char const** argv)
{
    allocator_t allocator;
    allocator_initialize(
        &allocator,
        &(allocator_interface_t){.user = NULL,
                                 .alloc = allocator_alloc,
                                 .dealloc = allocator_dealloc});

    void* buffer = allocator_allocate(&allocator, 30);

    snprintf(buffer, 30, "%s", "DUPA ZBITA\n");
    printf("Buf type: %d", allocator.type);
    allocator_deallocate(&allocator);

    allocator_deinitialize(&allocator);

    return 0;
}
