#include<iostream>
#include<json/json.h>
using namespace std;
int main(int argc,char** argv){
    Json::Value val;
    std::cin>>val;
    Json::FastWriter fastWriter;
    std::cout<<fastWriter.write(val);
    return 0;
}
