/*
 * json_object_new_object: create new json object
 */
#include<json-c/json.h>
#include<stdio.h>
int main(int argc,char** argv){
	fprintf(stdout,"JSON_C_VERSION:%s\n",JSON_C_VERSION);
	struct json_object *obj_json=json_object_new_object();
	struct json_object *obj_json_boolean=json_object_new_boolean(0);
	struct json_object *obj_json_int=json_object_new_int(1);
	struct json_object *obj_json_double=json_object_new_double(0.1);
	struct json_object *obj_json_string=json_object_new_string("foo");
	struct json_object *obj_json_array=json_object_new_array();
	json_object_object_add(obj_json,"bool",obj_json_boolean);
	json_object_object_add(obj_json,"int",obj_json_int);
	json_object_object_add(obj_json,"double",obj_json_double);
	json_object_object_add(obj_json,"string",obj_json_string);
	json_object_object_add(obj_json,"array",obj_json_array);
	int i;
	for(i=0;i<4;i++){
		json_object_array_add(obj_json_array,json_object_new_int(i));
	}
	while(json_object_array_length(obj_json_array)<8){
		//note difference in JSON_C_VERSION:0.12.1 and JSON_C_VERSION 0.13.99
		//note idx                               i-1
		json_object_array_put_idx(obj_json_array,i-1,json_object_new_int(10+i++));
	}
	if(obj_json!=NULL){
		fprintf(stdout,"JSON parsed\n");
		printf(
			"%s\n",
			json_object_to_json_string_ext(
				obj_json,
				JSON_C_TO_STRING_SPACED|
				JSON_C_TO_STRING_PRETTY
			)
		);
		//free(obj_json);???
	}else{
		fprintf(stderr,"Failed to parse JSON\n");
	}
	return 0;
}
