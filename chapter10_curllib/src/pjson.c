#include <jansson.h>
#include <stdio.h>

/**
 * @file:测试jansson库,该库用于解析json数据 
 * 
 *
 * @brief 
 * 
 * @return int 
 */

int main() {
    char *text = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";
    json_error_t error;
    json_t *root = json_loads(text, 0, &error);

    if (!root) {
        fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);
        return 1;
    }

    json_t *name, *age, *city;
    const char *name_str;
    int age_int;
    const char *city_str;

    name = json_object_get(root, "name");
    age = json_object_get(root, "age");
    city = json_object_get(root, "city");

    name_str = json_string_value(name);
    age_int = json_integer_value(age);
    city_str = json_string_value(city);

    printf("Name: %s\n", name_str);
    printf("Age: %d\n", age_int);
    printf("City: %s\n", city_str);

    json_decref(root);

    return 0;
}