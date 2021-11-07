#pragma once
#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"
#define INT_MAX 2147483647
#define TH_TEN 10000
#define TWO_BI 2000000000


typedef struct mx_route {
    char *s;
    char *m;
    char *e;
    int a;
    int b;
    int c;
    struct mx_route *next;
}   r_mx;

//  Input error
int mx_bunch(const char *file);
int mx_error(int argc, char const argv[]);

//  Create Matrix
int mx_unic(char *argv);
void mx_unic_array(char *name, char **places)
void mx_elements(char *line, char *result[3]);
void mx_matrix_make(char *name, char **places, int num_places, int matrix[num_places][num_places]);

//  Algoritm
r_mx *mx_floyd_warshall(int num_places, int matrix[num_places][num_places], char **places);

//  Output
void mx_printer(char *a, char *b, int result);
void mx_output(int num_places, int matrix[num_places][num_places], char** places, r_mx *list);
void mx_big_array_printer(int num_places, char *array[num_places],  int integer[num_places]);
void mx_array_filler(int num_places, char *arr[num_places], int integer[num_places], r_mx *list, char *start, char *end);
void mx_array_editor(int num_places, char *arr[num_places], r_mx *list);
void mx_array_extender(int num_places, char *array[num_places], char *insert_element, int insert_count);
void mx_int_array_extender(int num_places, int array[num_places], int insert_element_1, int insert_element_2, int insert_count);
void mx_array_garbager(int num_places,  int integer[num_places]);
void mx_outer_array_recursion_editor(r_mx *list, int num_places, char *array[num_places], int arr_int[num_places], recursed);
void mx_array_recursion_editor(r_mx *list, int num_places, char *array[num_places], int arr_int[num_places], int pure_arr_int[num_places]);
int mx_list_value_validator(r_mx **list, void *data);
int mx_is_in_list(r_mx *list, char *start, char *end);
void mx_push_route_back(r_mx **list, char *start, char *middle, char *end, int s_distance, int m_distance, int e_distance);
void mx_push_route_front(r_mx **list, char *start, char *middle, char *end, int s_distance, int m_distance, int e_distance);
void mx_sort_route_list(r_mx *list, r_mx *new_list, char **unique_cities, int num_of_cities);
void mx_sort_route_list2(r_mx *new_route_list);
r_mx *mx_copy_r_list(r_mx *list);
r_mx *mx_r_list_reverse(r_mx *list);
r_mx *mx_create_route_node(char *start, char *middle, char *end, int s_distance, int m_distance, int e_distance);

#endif
