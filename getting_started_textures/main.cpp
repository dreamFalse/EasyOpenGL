#include <glad/glad.h>
#include <GLFW/glfw3.h>
 
#include <iostream>
#include<math.h>

#include "shader.h"
 
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
 
int main()
{
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
 
    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
 
    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
 
 
    // Shader Initialization
    Shader myShader("/home/fhh/learn/learnOpenGL/getting_started_shaders/vertexShader.glsl", "/home/fhh/learn/learnOpenGL/getting_started_shaders/fragmentShader.glsl");
 
 
    float vertices[] = {
        // 位置             // 颜色
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,    // left  
         0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,    // right 
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top   
    }; 
 
    unsigned int VBO, VAO;
	//创建VAO对象
    glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	//创建VBO对象，把顶点数组复制到一个顶点缓冲中，供OpenGL使用
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // 缓冲绑定到GL_ARRAY_BUFFER
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // 顶点数据复制到缓冲的内存中
 
	//解释顶点数据方式
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0); // 顶点数据的解释
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
 
    // 解绑VAO
	glBindVertexArray(0); 
	// 解绑VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
 
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);
 
        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // float timeValue = glfwGetTime();
        // float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
        // int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
        myShader.use();
        // myShader.setFloat("ourColor", greenValue);
 
        // draw our first triangle
        // glUseProgram(shaderProgram); // 激活shaderProgram，怎么画
        // glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
        glBindVertexArray(VAO); // 画什么
        glDrawArrays(GL_TRIANGLES, 0, 3); // 开始画
 
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
 
    // optional: de-allocate all resources
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(myShader.ID);
    glfwTerminate();
    
    return 0;
}
 
//键盘按键回调函数  
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
 
//调整窗口大小回调函数
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
 