#include<rclcpp/rclcpp.hpp>
#include<iostream>
#include"geometry_msgs/msg/twist.hpp"
using namespace std::chrono_literals;
class TurtltcircleNode: public rclcpp::Node
{
private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr Publisher_;//创建发布者   
public:
  explicit TurtltcircleNode(const std::string& node_name):Node(node_name)
  {//这里的话题不能随便搞
    Publisher_=this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
    timer_=this->create_wall_timer(1000ms,std::bind(&TurtltcircleNode::timer_callback,this));
  }
  void timer_callback()
  {
    auto msg=geometry_msgs::msg::Twist();
    msg.linear.x=1.0;
    msg.angular.z=0.5;
    Publisher_->publish(msg);
  }
};

int main(int argc,char* argv[])
{
    rclcpp::init(argc,argv);
    auto node=std::make_shared<TurtltcircleNode>("turtle_cicle");
    //RCLCPP_INFO(node->get_logger(),"坐标：",this->msg.linear.x);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}