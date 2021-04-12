/*
 * json_object_object_foreach: a macro used for iterating through k:v in a json object
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
			enum json_type type_obj_json=json_object_get_type(v);
			switch(type_obj_json){
				case json_type_null:
					fprintf(stdout,"NULL\n");
					break;
				case json_type_boolean:
					fprintf(stdout,"Boolean\n");
					break;
				case json_type_double:
					fprintf(stdout,"Double\n");
					break;
				case json_type_int:
					fprintf(stdout,"Int\n");
					break;
				case json_type_object:
					fprintf(stdout,"Object\n");
					break;
				case json_type_array:
					fprintf(stdout,"Array\n");
					break;
				case json_type_string:
					fprintf(stdout,"String\n");
					break;
				default:
					fprintf(stderr,"Invalid type\n");
			}
		}
		//free(obj_json);???
	}else{
		fprintf(stderr,"Failed to parse JSON\n");
	}
	return 0;
}
