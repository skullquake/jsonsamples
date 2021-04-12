#ifndef MYWRITER_H
#define MYWRITER_H
#include<json/json.h>
class MyWriter:public Json::Writer{
	public:
		std::string write(const Json::Value&);
	private:
	protected:
};
#endif
