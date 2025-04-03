
### 状态机
OpenGL 自身是一个巨大的状态机(State Machine)：一系列的变量描述的OpenGL此刻应当如何运行。OpenGL的状态通常被称为OpenGL上下文(context)。通常使用如下途径去更改OpenGL状态：设置选项，操作缓冲，最后使用当前OpenGL上下文来渲染。
因此会有状态设置函数(state-changing function)和状态使用函数(State-Using Function)。

### 对象
OpenGL库是用C语言写的，同时支持多种语言的派生，但其内核仍是一个C库，同时OpenGL开发的时候引入了一些抽象层。`对象`就是其中一个。可以把对象看作一个C风格的结构体(struct)：
```C
struct object_name {
    float option1;
    int option2;
    char[] name;
};
```

Ubuntu下环境配置
https://www.cnblogs.com/jiujiubashiyi/p/16429717.html
