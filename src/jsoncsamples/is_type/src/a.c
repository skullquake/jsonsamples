/*
 * json_object_is_type: does type checking
 */

#include<json-c/json.h>
#include<stdio.h>
int main(int argc,char** argv){
	char* str_json="{\"foo\":\"bar\",\"baz\":[1,2,3,4],\"qux\":{\"klutz\":[5,6,7,8]}}";
	struct json_object* obj_json=json_tokener_parse(str_json);
	//check parsed
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
		json_object_object_foreach(obj_json,k,v){
			printf("%s:",k);
			      if(json_object_is_type(v,json_type_null)){
				fprintf(stdout,"json_type_null");
			}else if(json_object_is_type(v,json_type_boolean)){
				fprintf(stdout,"json_type_boolean");
			}else if(json_object_is_type(v,json_type_double)){
				fprintf(stdout,"json_type_double");
			}else if(json_object_is_type(v,json_type_int)){
				fprintf(stdout,"json_type_int");
			}else if(json_object_is_type(v,json_type_object)){
				fprintf(stdout,"json_type_object");
			}else if(json_object_is_type(v,json_type_array)){
				fprintf(stdout,"json_type_array");
			}else if(json_object_is_type(v,json_type_string)){
				fprintf(stdout,"json_type_string");
			}else{
				fprintf(stderr,"Invalid Type");
			}
			fprintf(stdout,"\n");
		}
	}else{
		fprintf(stderr,"Failed to parse JSON\n");
	}
	return 0;
}
