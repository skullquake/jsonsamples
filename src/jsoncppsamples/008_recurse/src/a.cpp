#include<iostream>
#include<fstream>
#include<json/json.h>
void prjsonv(const Json::Value&);
bool prjsonr(const Json::Value &root,unsigned short depth=0);
int main(int argc,char** argv){
	std::ifstream ifs("../res/b.json");
	Json::Reader reader;
	Json::Value obj;
	reader.parse(ifs,obj);
	prjsonr(obj);
	return 0;
}
void prjsonv(const Json::Value& val){
	if(val.isString()){
		std::cout<<"string("<<val.asString().c_str()<<")"<<std::endl; 
	}else if(val.isBool()){
		std::cout<<"bool("<<val.asBool()<<")"<<std::endl; 
	}else if(val.isInt()){
		std::cout<<"int("<<val.asInt()<<")"<<std::endl; 
	}else if(val.isUInt()){
		std::cout<<"uint("<<val.asUInt()<<")"<<std::endl; 
	}else if(val.isDouble()){
		std::cout<<"double("<<val.asDouble()<<")"<<std::endl; 
	}else {
		std::cout<<"unknown type=["<<val.type()<<"]"<<std::endl; 
	}
}
bool prjsonr(const Json::Value &root,unsigned short depth){
	depth+=1;
	std::cout<<" {type=["<<root.type()<<"], size="<<root.size()<<"}"<<std::endl;
	if(root.size()>0){
		std::cout<<std::endl;
		for(Json::Value::const_iterator itr=root.begin();itr!=root.end();itr++){
			for(int tab=0;tab<depth;tab++){
				std::cout<<"-";
			}
			std::cout<<" subvalue(";
			prjsonv(itr.key());
			std::cout<<") -";
			prjsonr(*itr,depth); 
		}
		return true;
	}else{
		std::cout<<" ";
		prjsonv(root);
		std::cout<<std::endl;
	}
	return true;
}
