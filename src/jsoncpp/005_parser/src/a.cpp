#include<iostream>
#include<json/json.h>
int main(int argc,char** argv){
	Json::Value val;
	Json::Reader reader;
	bool b=reader.parse(std::cin,val);
	if(!b)
		std::cout<<"Error:"<<reader.getFormattedErrorMessages()<<std::endl;
	else
		std::cout<<val;
	return 0;
}
