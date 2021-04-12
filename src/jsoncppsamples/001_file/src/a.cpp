#include<iostream>
#include<fstream>
#include<json/json.h>
int main(int argc,char** argv){
	std::ifstream ifs("../res/a.json");
	Json::Reader reader;
	Json::Value obj;
	reader.parse(ifs,obj);
	std::cout<<"Book: "<<obj["book"].asString()<<std::endl;
	std::cout<<"Year: "<< obj["year"].asUInt()<<std::endl;
	const Json::Value& characters=obj["characters"];
	for(int i=0;i<characters.size();i++){
		std::cout<< "    name: "<<characters[i]["name"].asString();
		std::cout<<" chapter: " << characters[i]["chapter"].asUInt();
		std::cout<<std::endl;
	}
	return 0;
}
