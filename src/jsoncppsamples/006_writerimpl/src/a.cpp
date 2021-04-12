#include<iostream>
#include<json/json.h>
#include"MyWriter.h"
int main(int argc,char** argv){
	MyWriter myWriter;
	Json::Value val;
	MyWriter w;
	std::cout<<w.write(val)<<std::endl;
	return 0;
}
