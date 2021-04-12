#include<iostream>
#include<json/json.h>
#include<json/reader.h>
#include<json/writer.h>
#include<json/value.h>
#include<string>
int main(int argc,char** argv){
	std::string s=
"{\
    \"book\":\"Alice in Wonderland\",\
    \"year\":1865,\
    \"characters\":\
    [\
        {\"name\":\"Jabberwock\", \"chapter\":1},\
        {\"name\":\"Cheshire Cat\", \"chapter\":6},\
        {\"name\":\"Mad Hatter\", \"chapter\":7}\
    ]\
}";
	Json::Value root;   
	Json::Reader reader;
	bool parsingSuccessful=reader.parse(s.c_str(),root);
	Json::Value obj;
	std::cout<<"Book: "<<obj["book"].asString()<< std::endl;
	std::cout<<"Year: "<<obj["year"].asUInt()<< std::endl;
	const Json::Value& characters=obj["characters"];
	for(int i=0;i<characters.size();i++){
		std::cout<<"    name: "<< characters[i]["name"].asString();
		std::cout<<" chapter: "<< characters[i]["chapter"].asUInt();
		std::cout<<std::endl;
	}
	return 0;
}
