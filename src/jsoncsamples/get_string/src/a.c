/*
 * json_object_get_string: extract string value
 */

#include<json-c/json.h>
#include<stdio.h>
int main(int argc,char** argv){
	char* str_json="{\"foo\":\"bar\",\"baz\":\"qux\"}";
	struct json_object* obj_json=json_tokener_parse(str_json);
	//check parsed
	if(obj_json!=NULL){
		fprintf(stdout,"JSON parsed\n");
		{
			const char* k="foo";
			struct json_object* val;
			if(json_object_object_get_ex(obj_json,k,&val)){
				fprintf(stdout,"%s:%s\n",k,json_object_get_string(val));
			}else{
				fprintf(stderr,"Failed to extract value\n");
			}
		}
		{
			const char* k="baz";
			struct json_object* val;
			if(json_object_object_get_ex(obj_json,k,&val)){
				fprintf(stdout,"%s:%s\n",k,json_object_get_string(val));
			}else{
				fprintf(stderr,"Failed to extract value\n");
			}
		}
	}else{
		fprintf(stderr,"Failed to parse JSON\n");
	}
	return 0;
}
