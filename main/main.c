#include "matrix3.h"
#include "transform3.h"
#include "vector3.h"
#include <stdio.h>

void test_transform3()
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

    transform3_fill_with_arrays(&t1, &rotation_array1, &translation_array1);
    transform3_fill_with_arrays(&t2, &rotation_array2, &translation_array2);

    transform3_compose(&t1, &t2, &composed);
    transform3_inverse(&composed, &inverse);
    transform3_vector_transformation(&composed, &vec, &transformed_vec);

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

int main(int argc, char const** argv)
{
    test_transform3();

    return 0;
}
