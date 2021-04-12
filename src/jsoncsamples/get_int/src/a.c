/*
 * json_object_get_int: extract integer value
 */

#include<json-c/json.h>
#include<stdio.h>
int main(int argc,char** argv){
	char* str_json="{\"foo\":0,\"bar\":1}";
	struct json_object* obj_json=json_tokener_parse(str_json);
	//check parsed
	if(obj_json!=NULL){
		fprintf(stdout,"JSON parsed\n");
		{
			const char* k="foo";
			struct json_object* val;
			if(json_object_object_get_ex(obj_json,k,&val)){
				fprintf(stdout,"%s:%d\n",k,json_object_get_int(val));
			}else{
				fprintf(stderr,"Failed to extract value\n");
			}
		}
		{
			const char* k="bar";
			struct json_object* val;
			if(json_object_object_get_ex(obj_json,k,&val)){
				fprintf(stdout,"%s:%d\n",k,json_object_get_int(val));
			}else{
				fprintf(stderr,"Failed to extract value\n");
			}
		}
	}else{
		fprintf(stderr,"Failed to parse JSON\n");
	}
	return 0;
}
