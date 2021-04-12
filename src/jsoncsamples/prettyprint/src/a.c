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
		//free(obj_json);???
	}else{
		fprintf(stderr,"Failed to parse JSON\n");
	}
	return 0;
}
