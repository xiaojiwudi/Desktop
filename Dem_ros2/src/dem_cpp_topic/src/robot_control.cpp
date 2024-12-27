#define PI 3.1415926
#define MIN_DISTANCE 0.00001

#include <cstdlib>
#include <ctime>

#include "geometry_msgs/msg/transform_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "turtlesim/msg/pose.hpp"

using namespace std;
using namespace std::chrono_literals;
using std::placeholders::_1;

class RobotControl : public rclcpp::Node
{
public:
    RobotControl() : Node("robot_control")
    {
        // 关键变量的初始化
        init();
        // 订阅机器人运动的位姿话题
        _pose_sub = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, std::bind(&RobotControl::pose_callback, this, _1));
        // 创建控制机器人运动的话题
        _twist_pub = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 1);
    }

    // 初始化对象的变量
    void init()
    {
        // 初始化随机种子函数
        srand(time(0));

        // 初始化
        _robot_linear_velocity = 0.0;
        _robot_angular_velocity = 0.0;

        _world_x_min = 0.0;
        _world_x_max = 0.0;
        _world_y_min = 0.0;
        _world_y_max = 0.0;
    }

    void random_walk()
    {
        float r_l = static_cast<float>(rand()) / RAND_MAX;
        float r_a = static_cast<float>(rand()) / RAND_MAX;
        RCLCPP_INFO(this->get_logger(), "LV x=%.2f, AV =%.2f", r_l, r_a);
    }

    // 更新世界信息
    void update_world(float pos_x, float pos_y)
    {
        if (_world_x_min - pos_x > MIN_DISTANCE)
        {
            _world_x_min = pos_x;
        }
        if (pos_x - _world_x_max > MIN_DISTANCE)
        {
            _world_x_max = pos_x;
        }
        if (_world_y_min - pos_y > MIN_DISTANCE)
        {
            _world_y_min = pos_y;
        }
        if (pos_x - _world_x_max > MIN_DISTANCE)
        {
            _world_y_max = pos_y;
        }
    }

public:
    // 函数功能： 函数用于设置机器人的线性速度
    // 备注： 由于该部分内容涉及C++内容，通过函数封装，简化为C语言调用
    float set_linear_velocity(float v)
    {
        if (v < 0.0)
        {
            v = 0.0;
        }
        return _robot_linear_velocity = v >= _max_linear_velocity ? _max_linear_velocity : v;
    }

    // 函数功能：函数用于设置机器人的角速度，达到控制机器人朝向的效果
    // 备注： 由于该部分内容涉及C++内容，通过函数封装，简化为C语言调用
    float set_angular_velocity(float v)
    {
        return _robot_angular_velocity = v >= _max_angular_velocity ? _max_angular_velocity : v;
    }

    // 函数功能： 函数用于下发机器人的控制指令，即将设置的线性速度和角速度下发给机器人来执行
    // 备注： 由于该部分内容涉及C++内容，通过函数封装，简化为C语言调用
    void control_robot()
    {
        geometry_msgs::msg::Twist cmd_vle_msg;

        cmd_vle_msg.linear.x = _robot_linear_velocity;
        cmd_vle_msg.angular.z = _robot_angular_velocity;

        _twist_pub->publish(cmd_vle_msg);
    }

private:
    /*
    ! 函数功能: 回调函数，用于根据机器人当前位姿态信息来控制机器人下一步的状态，线速度和角速度
    ! 备注： 学生仅需在本函数内的 TODO(Begin)和 TODO(End)两注释之间完成自己的代码逻辑即可
    */
    void pose_callback(const turtlesim::msg::Pose &msg)
    {
        // 静态时间变量，用于记录上次下发命令的时间
        static rclcpp::Time last_time = this->get_clock()->now();
        // 获取当前时间
        rclcpp::Time now = this->get_clock()->now();

        // 获取上次控制指令和当前机器人状态的时间间隔，单位为秒s
        // 可以根据代码需求，接注释自己的代码
        rclcpp::Duration control_duration = now - last_time;
        double delta_time = control_duration.seconds();

        // 获取当前机器人的位置和状态信息
        // robot_pos_x, robot_pos_y 为机器人当前的位置x，y坐标值
        // robot_direction 为机器人当前的朝向
        // robot_linear_velocity, robot_angualr_velocity为机器人的线性速度和角速度
        // 可以根据代码需求，接注释自己的代码
        float robot_pos_x = msg.x;
        float robot_pos_y = msg.y;
        float robot_direction = msg.theta;
        float robot_linear_velocity = msg.linear_velocity;
        float robot_angular_velocity = msg.angular_velocity;

        //! TODO（Begin）
        //! 项目需求说明：移动机器人，使机器人在探索世界地图后，在世界地图上绘制一个最大的三角形
        //! 第一步：探索地图，确定地图的边界（默认世界地图是矩形）
        float r_l = 1.0;
        set_linear_velocity(r_l);
        float r_a;
        printf("           \n");
        /*if (pos_x == 5 + delta_time * r_l)
        {
            r_l = -1;
            r_a = 1.0;
            set_angular_velocity(r_a);
            set_linear_velocity(r_l);
            if (robot_direction >= PI / 2 && robot_direction <= PI / 2 + 0.01)
            {
                r_a = 0;
                set_angular_velocity(r_a);
                r_l = 1.0;
                set_linear_velocity(r_l);
            }
        }
        else if (robot_pos_y >= _world_y_max)
        {
            r_l = -1;
            r_a = 1.0;
            set_angular_velocity(r_a);
            set_linear_velocity(r_l);
            if (robot_direction <= PI && robot_direction >= PI - 0.001)
            {
                r_a = 0;
                set_angular_velocity(r_a);
                r_l = 1.0;
                set_linear_velocity(r_l);
            }
        }
        else if (robot_pos_x <= _world_x_min || robot_pos_y <= _world_y_min)
        {
            r_l = 0.0;
            r_a = 1.0;
            set_angular_velocity(r_a);
            set_linear_velocity(r_l);
            if (robot_direction > PI / 2 && robot_direction > PI / 2 + 0.1)
            {
                r_a = 0;
                set_angular_velocity(r_a);
                r_l = 1.5;
                set_linear_velocity(r_l);
            }
        }
        // r_l = 2.0;
        // set_linear_velocity(r_l);
        RCLCPP_INFO(this->get_logger(), "LV x=%.2f, AV =%.2f", r_l, r_a);
        RCLCPP_INFO(this->get_logger(), "x=%f, y=%f,direction=%f", robot_pos_x, robot_pos_y, robot_direction);*/
        //! 第二步：根据探索的世界地图，利用机器人绘制一个最大的三角形，规划机器人的路径
        //! 第三步：根据机器人当前的位置、朝向来调整机器人的线性速度和朝向
        //! 注意事项：

        // 更新世界地图信息
        update_world(robot_pos_x, robot_pos_y);
        float pos_x = robot_pos_x;
        float pos_y = robot_pos_y;
        float direction = robot_direction;
        float linear_velocity = robot_linear_velocity;
        float angular_velocity = robot_angular_velocity;
        // ! 参考代码，学生完成自己内容时，需要换成自己的内容
        // 让机器人在地图以随机速度和随机角度游走
        // 设置机器人的线性速度和角速度，并控制机器人移动
        // random_walk();

        /*
        ! 在此之间完成课程任务，此处结束
        ! TODO（End）
        */

        last_time = this->get_clock()->now();
        control_robot();
    }

private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr _twist_pub;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr _pose_sub;

    const float _max_linear_velocity = 1.5;
    const float _max_angular_velocity = PI / 2;

    // 单位是m/s，该指不能超过_max_linear_velocity
    float _robot_linear_velocity;
    // 单位是弧度/s，该值等于PI时，就是360/s，正值为逆时针，负值为逆时针
    // 该值不能超过_max_angular_velocity
    float _robot_angular_velocity;

    // 由于世界地图是矩形，可以通过记录长宽的最大、最小值来确定世界地图
    float _world_x_min;
    float _world_x_max;
    float _world_y_min;
    float _world_y_max;
};

int main(int argc, char *argv[])
{
    // ROS2 C++接口初始化
    rclcpp::init(argc, argv);
    // 创建ROS2节点对象并进行初始化,循环等待ROS2退出
    rclcpp::spin(std::make_shared<RobotControl>());
    // 关闭ROS2 C++接口
    rclcpp::shutdown();
    return 0;
}
