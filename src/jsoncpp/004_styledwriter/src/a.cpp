#include<iostream>
#include<json/json.h>
using namespace std;
int main(int argc,char** argv){
    Json::Value val;
    std::cin>>val;
    Json::StyledWriter styledWriter;
    std::cout<<styledWriter.write(val);
    return 0;
}
