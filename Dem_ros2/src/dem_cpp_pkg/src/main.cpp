#include<iostream>
#include"rclcpp/rclcpp.hpp"
#include<string>
using namespace std;
using namespace rclcpp;
class PersonNode :public rclcpp::Node
{
private:
    string name_;
    int age_;
public:
PersonNode(const string &node_name,const int &age,const string &name)
:Node(node_name)//调用父类的构造函数
{
    this->age_=age;
    this->name_=name;
}
void eat(const string &food)
{
    RCLCPP_INFO(this->get_logger(),"我是%s,%d岁,爱吃%s",this->name_.c_str(),this->age_,food.c_str());
}
};
int main(int argc,char** argv)
{
    rclcpp::init(argc,argv);//初始化
   auto node =std::make_shared<PersonNode>("cpp_node",23,"shit");//创建节点
   RCLCPP_INFO(node->get_logger(),"rfgthyujikol");//打印日志
   spin(node);//循环节点
   shutdown();//退出
    return 0;
}
