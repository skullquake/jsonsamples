/*
 * json_object_new_object: create new json object
 */
#include<json-c/json.h>
#include<stdio.h>
int main(int argc,char** argv){
	struct json_object *obj_json=json_object_new_object();
	struct json_object *obj_json_boolean=json_object_new_boolean(0);
	struct json_object *obj_json_int=json_object_new_int(1);
	struct json_object *obj_json_double=json_object_new_double(0.1);
	struct json_object *obj_json_string=json_object_new_string("foo");
	struct json_array  *obj_json_array=json_object_new_array();
	int i;
	for(i=0;i<4;i++){
		json_object_array_add(obj_json_array,json_object_new_int(i));
	}
	while(json_object_array_length(obj_json_array)<8){
		json_object_array_put_idx(obj_json_array,i,json_object_new_int(i++));
	}
	json_object_object_add(obj_json,"bool",obj_json_boolean);
	json_object_object_add(obj_json,"int",obj_json_int);
	json_object_object_add(obj_json,"double",obj_json_double);
	json_object_object_add(obj_json,"string",obj_json_string);
	json_object_object_add(obj_json,"array",obj_json_array);
	printf("%s\n",json_object_to_json_string(obj_json));
	return 0;
}
