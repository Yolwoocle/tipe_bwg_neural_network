#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct matrix_t {
    double **values;
    int width;
    int height;
};
typedef struct matrix_t matrix;

matrix *new_matrix(int width, int height) {
    matrix *m = malloc(sizeof(matrix));

    m->width = width;    
    m->height = height;
    
    m->values = malloc(sizeof(double*) * height);
    for(int iy = 0; iy < height; iy++) {
        m->values[iy] = malloc(sizeof(double) * width);
    }

    return m;   
};

matrix *new_zero_matrix(int width, int height) {
    matrix *m = new_matrix(width, height);

    for(int iy = 0; iy < height; iy++) {
        for(int ix = 0; ix < width; ix++) {
            m->values[iy][ix] = 0.0;
        }
    }

    return m;
}

matrix *new_identity_matrix(int width, int height) {
    matrix *m = new_matrix(width, height);

    for(int iy = 0; iy < height; iy++) {
        for(int ix = 0; ix < width; ix++) {
            m->values[iy][ix] = (ix == iy) ? 1.0 : 0.0;
        }
    }

    return m;
}

matrix *print_matrix(matrix *m) {
    printf("[\n");
    for(int iy = 0; iy < m->height; iy++) {
        printf("\t");
        for(int ix = 0; ix < m->width; ix++) {
            printf("%.2f ", m->values[iy][ix]);
        }
        printf("\n");
    }
    printf("]\n");
}

void delete_matrix(matrix *m) {
    for(int iy = 0; iy < m->height; iy++) {
        free(m->values[iy]);
    }
    free(m->values);
    free(m);    
}

matrix *madd(matrix *m1, matrix *m2) {
    assert(m1->width == m2->width && m1->height == m2->height);

    matrix *res = new_matrix(m1->width, m1->height);

    for (int iy=0; iy < m1->height; iy++) {
        for (int ix=0; ix < m1->width; ix++) {
            res->values[iy][ix] = m1->values[iy][ix] + m2->values[iy][ix];
        }
    }

    return res;
}

matrix *mmul(matrix *a, matrix *b) {
    matrix *res = new_matrix(b->width, a->height);
    double sum = 0.0;

    for (int i=0; i<a->height; i++) {
        for (int j=0; j<b->width; j++) {
            sum = 0.0;
            for (int k=0; k<a->width; k++) {
                sum += a->values[i][k] * b->values[k][j];
            }
            res->values[i][j] = sum;
        }
    }

    return res;
}