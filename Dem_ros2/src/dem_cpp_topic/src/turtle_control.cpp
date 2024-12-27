#include<rclcpp/rclcpp.hpp>
#include<iostream>
#include"geometry_msgs/msg/twist.hpp"
#include"turtlesim/msg/pose.hpp"
#include<math.h>
using namespace std::chrono_literals;
class TurtltcircleNode: public rclcpp::Node
{
private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr Publisher_;//创建发布者
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr   Surscriber_;//订阅者智能指针
    double target_x_{1.0};
    double target_y_{1.0};
    double k_{1.0};//比列系数
    double max_speed_{3.0};//最大线速度
public:
  explicit TurtltcircleNode(const std::string& node_name):Node(node_name)
  {//这里的话题不能随便搞
    Publisher_=this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
    Surscriber_=this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose",10,
    std::bind(&TurtltcircleNode::on_pose_recived,this,std::placeholders::_1));
  }
  
  void on_pose_recived(const turtlesim::msg::Pose::SharedPtr pose)//参数收到共享指针
  {
    //1、获取当前位置
    auto current_x=pose->x;
    auto current_y=pose->y;
    RCLCPP_INFO(get_logger(),"海龟当前位置x=%f,y=%f",current_x,current_y);

    //2、计算当前海龟位置之间的距离和角度差
    auto distance =std::sqrt(
      (target_x_-current_x)*(target_x_-current_x)
      +(target_y_-current_y)*(target_y_-current_y)
      );

    auto angle=std::atan2((target_y_-current_y),(target_x_-current_x));//角度差

    //3、控制海龟
    auto msg=geometry_msgs::msg::Twist();
    if(distance>0.1)
    {
      if (fabs(angle)>0.2)
      {
        msg.angular.z=fabs(angle);
      }
      else
      {
        msg.linear.x=k_*distance;
      }
    }

    //4、限制最大速度
    if(msg.linear.x>max_speed_)
    {
       msg.linear.x=max_speed_;
    }
    Publisher_->publish(msg);
  }
};

int main(int argc,char* argv[])
{
    rclcpp::init(argc,argv);
    auto node=std::make_shared<TurtltcircleNode>("turtle_control");
    //RCLCPP_INFO(node->get_logger(),"坐标：",this->msg.linear.x);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}