#include<iostream>
#include<json/json.h>
using namespace std;
void r(Json::Value&,std::vector<std::string>,int);
int main(int argc,char** argv){
	std::vector<std::string> v{"foo","bar","baz","qux","klutz"}; 
	Json::Value j;
	r(j,v,10);
	Json::StyledWriter styledWriter;
	std::cout<<styledWriter.write(j);
	return 0;
}
void r(Json::Value& j,std::vector<std::string> v,int i){
	if(i<0){
		for(std::string x:v) 
			j[x]=x;
		return;
	}else{
		for(std::string x:v){
			j[x]=Json::Value();
			r(j[x],v,--i);
		}
	}

}
