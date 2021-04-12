/*
 * various array operations
 */
#include<json-c/json.h>
#include<stdio.h>
int main(int argc,char** argv){
	struct json_object *obj_json=json_object_new_object();
	struct json_array  *obj_json_array=json_object_new_array();
	int i;
	for(i=0;i<4;i++){
		json_object_array_add(obj_json_array,json_object_new_int(i));
	}
	while(json_object_array_length(obj_json_array)<8){
		json_object_array_put_idx(obj_json_array,i,json_object_new_int(i++));
	}
	json_object_object_add(obj_json,"array",obj_json_array);
	for(i=0;i<json_object_array_length(obj_json_array);i++){
		printf(
			"array[%d]:%d\n",
			i,
			json_object_get_int(
				json_object_array_get_idx(
					obj_json_array,
					i
				)
			)
		);
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
