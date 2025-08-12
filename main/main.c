#include "allocator.h"
#include "matrix.h"
#include "matrix3.h"
#include "transform3.h"
#include "vector3.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static void test_transform3(void)
{
    matrix3_data_t rotation_array1[3][3] = {{1.0f, 0.0f, 0.0f},
                                            {0.0f, 0.0f, -1.0f},
                                            {0.0f, 1.0f, 0.0f}};

    vector3_data_t translation_array1[3] = {1.0f, 2.0f, 3.0f};

    matrix3_data_t rotation_array2[3][3] = {{0.0f, 1.0f, 0.0f},
                                            {-1.0f, 0.0f, 0.0f},
                                            {0.0f, 0.0f, 1.0f}};

    vector3_data_t translation_array2[3] = {-1.0f, 0.5f, 0.0f};

    transform3_t t1, t2, composed, inverse;
    vector3_t vec = {{1.0f, 0.0f, 0.0f}};
    vector3_t transformed_vec;

    assert(transform3_fill_with_arrays(&t1,
                                       &rotation_array1,
                                       &translation_array1) ==
           TRANSFORM3_ERR_OK);
    assert(transform3_fill_with_arrays(&t2,
                                       &rotation_array2,
                                       &translation_array2) ==
           TRANSFORM3_ERR_OK);

    assert(transform3_compose(&t1, &t2, &composed) == TRANSFORM3_ERR_OK);
    assert(transform3_inverse(&composed, &inverse) == TRANSFORM3_ERR_OK);
    assert(
        transform3_vector_transformation(&composed, &vec, &transformed_vec) ==
        TRANSFORM3_ERR_OK);

    printf("Transform 1:\n");
    transform3_print(&t1, "\n");

    printf("\nTransform 2:\n");
    transform3_print(&t2, "\n");

    printf("\nComposed transform:\n");
    transform3_print(&composed, "\n");

    printf("\nInverse of composed transform:\n");
    transform3_print(&inverse, "\n");

    printf("\nOriginal vector:\n");
    vector3_print(&vec, "\n");

    printf("\nTransformed vector:\n");
    vector3_print(&transformed_vec, "\n");
}

static void* allocator_alloc(void* user, size_t size)
{
    (void)user;

    return malloc(size);
}

static void allocator_dealloc(void* user, void* buffer)
{
    (void)user;

    free(buffer);
}

static matrix_data_t* matrix_allocate(void* user, matrix_size_t size)
{
    return allocator_allocate((allocator_t*)user, (size_t)size);
}

static void matrix_deallocate(void* user, matrix_data_t* data)
{
    allocator_deallocate((allocator_t*)user);
}

static void test_matrix(void)
{
    allocator_t allocator;
    allocator_initialize(
        &allocator,
        &(allocator_interface_t){.user = NULL,
                                 .alloc = allocator_alloc,
                                 .dealloc = allocator_dealloc});

    matrix_t matrix;
    assert(matrix_initialize(
               &matrix,
               &(matrix_allocator_t){.user = &allocator,
                                     .allocate = matrix_allocate,
                                     .deallocate = matrix_deallocate}) ==
           MATRIX_ERR_OK);

    assert(matrix_create_with_zeros(&matrix, 3, 4) == MATRIX_ERR_OK);
    matrix_print(&matrix, "\n");
    assert(matrix_delete(&matrix) == MATRIX_ERR_OK);
}

int main(int argc, char const** argv)
{
    test_matrix();

    return 0;
}
