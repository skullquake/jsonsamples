#include<iostream>
#include<json/json.h>
using namespace std;
int main(int argc,char** argv){
    Json::Value val;
    std::cin>>val;
    std::cout<<val;
    return 0;
}
