#include <stdio.h>
#include <jansson.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
    char *test="{\"name\":\"xigua\",\"age\":30,\"city\":\"New York\"}";
    json_error_t error;
    json_t *root=json_loads(test,0,&error);
    if(!root){
        printf("error:%s\n",error.text);
        printf("line:%d\n",error.line);
        exit(EXIT_FAILURE)
    }
    json_t *name=json_object_get(root,"name");
    json_t *age=json_object_get(root,"age");
    json_t *city=json_object_get(root,"city");


    const char *name_str=json_string_value(name);
    const char *city_str=json_string_value(city);
    int age_int=json_integer_value(age);
    
}