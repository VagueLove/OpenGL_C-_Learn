PC（Windows）上安装与设置

# A安装库与开发环境

## A1.开发环境

- 使用vs2019，创建vs的一个自定义模板方便后续新项目的创建（会自动添加必要的库和依赖项）

## A2.查看显卡是否支持OpenGL4.3

[查看自己机器上的显卡支持openGL的版本_支持opengl的显卡列表_妙为的博客-CSDN博客](https://blog.csdn.net/aoxuestudy/article/details/120995097)（转载）

## A3.安装GLFW

- ### 使用CMake编译GLFW源码

  （1）下载GLFW源码[下载 |格利福 (glfw.org)](https://www.glfw.org/download.html)

  （2）下载安装CMake

  [Windows下CMake的下载与安装详解_cmake下载_wendy_ya的博客-CSDN博客](https://blog.csdn.net/didi_ya/article/details/123029415)（转载）

  （3）运行CMake选择GLFW源码所在的位置和期望构建的目标文件夹

  ![image-20230901104443998](D:\Typora\picture\image-20230901104443998.png)

  ![image-20230901104511320](D:\Typora\picture\image-20230901104511320.png)

  如果变红再次单击Configure

  ![image-20230901104611232](C:\Users\a'su's\Pictures\贫困资料\image-20230901104611232.png)

  单击Generate

  ![image-20230901104734691](D:\Typora\picture\image-20230901104734691.png)

用vs2019打开GLFW.sln

![image-20230901105334142](D:\Typora\picture\image-20230901105334142.png)

编译，得到glfw3.lib，注意该文件的位置

![image-20230901105052649](D:\Typora\picture\image-20230901105052649.png)

找到最开始下载的glfw的源码中的include文件中的GLFW文件

## A4.准备GLEW（64位二进制文件）

glew链接：[GLEW: The OpenGL Extension Wrangler Library (sourceforge.net)](https://glew.sourceforge.net/)

![image-20230901105721567](D:\Typora\picture\image-20230901105721567.png)

所需要的项目：

- glew32.lib

  ![image-20230901105936071](D:\Typora\picture\image-20230901105936071.png)

- glew32.dll

  ![image-20230901110011648](D:\Typora\picture\image-20230901110011648.png)

- GL文件夹

  ![image-20230901110051793](D:\Typora\picture\image-20230901110051793.png)

## A5.准备GLM（数学库）

下载链接：[GLM download | SourceForge.net](https://sourceforge.net/projects/glm.mirror/)

![image-20230901111052359](D:\Typora\picture\image-20230901111052359.png)

所需要的是glm

## A6.准备SOIL2（图像加载库）

**安装SOIL2需要使用premake的工具**

参考博客：[OpenGL学习预备篇——使用premake配置SOIL2库_opengl soil配置_亭墨的博客-CSDN博客](https://blog.csdn.net/qq_43419761/article/details/129557050)

下载SOIL2

SOIL下载
   https://github.com/SpartanJ/SOIL2/releases

###    上面已经给出了SOIL2的github地址，我们可以点进去，

![image-20230901111926107](D:\Typora\picture\image-20230901111926107.png)

### 点击tags切换

![image-20230901111907346](D:\Typora\picture\image-20230901111907346.png)

### **这里选择的release 1.2.0**

###  将下载下来的SOIL2和premake进行解压，**并将premake5.exe放进SOIL2文件夹中**

![image-20230901112417151](D:\Typora\picture\image-20230901112417151.png)

### 在该文件夹中打开cmd运行命令：

### 	**premake5.exe vs2019**

![image-20230901113526661](D:\Typora\picture\image-20230901113526661.png)



此时文件夹中会多出一个make的文件夹，在其中打开windows文件夹，**找到SOIL2.sln**

如果vs提示升级库点击确定

![image-20230901113651028](D:\Typora\picture\image-20230901113651028.png)

**右键单击soli2-static-lib，选择生成**

成功后，文件夹中会多lib和obj

![image-20230901113844762](D:\Typora\picture\image-20230901113844762.png)

## A7.准备共享的lib和include文件夹

所需要项目的文件的位置：

![image-20230901105052649](D:\Typora\picture\image-20230901105052649.png)

- ![image-20230901111052359](D:\Typora\picture\image-20230901111052359.png)

- glew32.lib

  ![image-20230901105936071](D:\Typora\picture\image-20230901105936071.png)

- glew32.dll

  ![image-20230901110011648](D:\Typora\picture\image-20230901110011648.png)

- GL文件夹

  ![image-20230901110051793](D:\Typora\picture\image-20230901110051793.png)

  

![image-20230901114115244](D:\Typora\picture\image-20230901114115244.png)

![image-20230901114325215](D:\Typora\picture\image-20230901114325215.png)



文件夹为：

![image-20230901114446034](D:\Typora\picture\image-20230901114446034.png)



![image-20230901114503329](D:\Typora\picture\image-20230901114503329.png)

![image-20230901114627119](D:\Typora\picture\image-20230901114627119.png)

## A8.在VS中开发和部署OpenGL项目

将我们得到的共享文件放在电脑的某个位置，例如我放在C盘下

![image-20231101101247118](D:\Typora\picture\image-20231101101247118.png)





### 打开vs2019创建一个C++空项目

![image-20230901115605753](D:\Typora\picture\image-20230901115605753.png)

<img src="D:\Typora\picture\image-20230901115917277.png" alt="image-20230901115917277" style="zoom: 67%;" />

### 在包含项目中添加之前我们创建的include文件夹

![image-20231101101524331](D:\Typora\picture\image-20231101101524331.png)



$(SolutionDir)是一个宏，是当前项目的位置。

<img src="D:\Typora\picture\image-20230901120650912.png" alt="image-20230901120650912" style="zoom: 67%;" />



### 然后在链接器，常规，附加目录中添加之前的lib文件夹

![image-20231101101652815](D:\Typora\picture\image-20231101101652815.png)



### 在输入中的附加依赖项添加glfw3.lib,glew32.lib,soil2-debug.lib，opengl32.lib。

### 下面我以为opengl32.lib已经作为标准WindowsSDK的一部分提供了，没写，后面就报错了，希望你们添上。

<img src="D:\Typora\picture\image-20231101101902815.png" alt="image-20231101101902815" style="zoom:67%;" />

## A.9导出模板

### 选择项目->导出模板->项目模板

<img src="D:\Typora\picture\image-20231101102408191.png" alt="image-20231101102408191" style="zoom:67%;" />

### 安装好模板后，创建一个新的OpenGLC++项目

1. 新建项目
2. 选择OpenGL模板
3. 从x86修改为x64
4. 在你创建的项目中的同名子文件中，添加glew32.dll,src是我之前的文件夹
5. ![image-20231101103759428](D:\Typora\picture\image-20231101103759428.png)



​      				![image-20231101103841791](D:\Typora\picture\image-20231101103841791.png)		

6. 添加一个.cpp文件进行测试

```c++
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


void init(GLFWwindow* window) { }

void display(GLFWwindow* window, double currentTime)
{
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
int main()
{
	using namespace std;
	if (!glfwInit())
		exit(EXIT_FAILURE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	GLFWwindow* window = glfwCreateWindow(600, 600, "Hello, world", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK)
		exit(EXIT_FAILURE);
	glfwSwapInterval(1);

	init(window);

	while (!glfwWindowShouldClose(window))
	{
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
```



7. 输出结果为：

   ![image-20231101104205215](D:\Typora\picture\image-20231101104205215.png)

# OpenGL的图像管线

# A.1 OpenGL管线

# A.2 C++/OpenGL应用程序

在我们尝试编写着色器之前，我们先用编写一个简单的C++/OpenGL应用程序，创建一个GLFWwindow实例并为其设置背景色。

```
- 初始化GLFW库
- 实例化GLFWwindow
- 初始化GLEW库
- 调用一次init()函数
- 重复调用display()函数
```

将每个程序的初始化任务都放在init（）函数中，用于绘制GLFWwindow的代码都放在display（）函数中。



```c++
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


void init(GLFWwindow* window){ }

void display(GLFWwindow* window, double currentTime)
{
	//让我们指定颜色缓冲区清除后填充的值，rgba表示，此处为红色
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	//用于清除窗口的颜色缓冲区
	glClear(GL_COLOR_BUFFER_BIT);
}
int main()
{
	using namespace std;
	if (!glfwInit())
		exit(EXIT_FAILURE);
	//指定计算机必需与OpenGL版本4.3的兼容，主版本号为4，次版本号为3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwCreateWindow,创建宽，高位600像素，顶部标题为Hello，World，
	// 另外两个参数分别用来表示允许全屏显示和资源共享
	GLFWwindow* window = glfwCreateWindow(600, 600, "Hello, World", nullptr, nullptr);
	//关联当前GFLW窗口和OpenGL上下文
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		exit(EXIT_FAILURE);
	//开启垂直同步
	glfwSwapInterval(1);

	init(window);

	while (!glfwWindowShouldClose(window))
	{
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		//处理窗口相关的事件（如按键事件）
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
```



# A.3顶点着色器和片段着色器

OpenGL只能绘制几类非常简单的东西，如点、线、三角形。这些简单的东西叫图元。

图元由顶点组成，如三角形由三个顶点。

顶点来源有很多，如从文件读取并由C++/OpenGL应用载入缓冲区，直接在C++中硬编码，或者直接在GLSL代码中生成。

在加载顶点之前，C++/OpenGL应用程序必须编译并链接合适的GLSL顶点着色器和片段着色器程序，之后将他们载入管线。

我们会使用一个OpenGL的函数来构建图形，所有的顶点都会被传入顶点着色器，被逐次处理。

- glDrawArrays()

语法：

```c++
void WINAPI glDrawArrays(
   GLenum  mode,//要呈现的基元类型
   GLint   first,//已启用的数组中的起始索引。
   GLsizei count//要呈现的所引数
);
```

- 使用C++硬编码的方式，画一个点

```c++
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

+#define numVAOs 1
+unsigned int renderingProgram;
+unsigned int vao[numVAOs];

+unsigned int createShaderProgram()
{
	+const char* vshaderSource =
		+"#version 430 \n"//版本型号
		+"void main(void) \n"
		+"{gl_Position = vec4(0.0, 0.0, 0.0, 1.0); }";
    //gl_Position内置的坐标变量，前三个参数对应坐标的(x,y,z)，第四个参数后面会说到
	+const char* fshaderSource =
		+"#version 430 \n"
		+"out vec4 color; \n"
		+"void main(void) \n"
		+"{ color = vec4(0.0, 0.0, 1.0, 1.0); }";

	//创建顶点着色器和片段着色器
	+unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
	+unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);

	+glShaderSource(vShader, 1, &vshaderSource, NULL); 
	+glShaderSource(fShader, 1, &fshaderSource, NULL);
	+glCompileShader(vShader);
	+glCompileShader(fShader);

	+unsigned int vfProgram = glCreateProgram();
	+glAttachShader(vfProgram, vShader);
	+glAttachShader(vfProgram, fShader);
	+glLinkProgram(vfProgram);

	+return vfProgram;
}

void init(GLFWwindow* window)
{ 
	+renderingProgram = createShaderProgram();
	+glGenVertexArrays(numVAOs, vao);
	+glBindVertexArray(vao[0]);
}

void display(GLFWwindow* window, double currentTime)
{
	+glUseProgram(renderingProgram);
	+glPointSize(30.0f);//设置点的大小
	+glDrawArrays(GL_POINTS, 0, 1);
}
int main()
{
	using namespace std;
	if (!glfwInit())
		exit(EXIT_FAILURE);
	//指定计算机必需与OpenGL版本4.3的兼容，主版本号为4，次版本号为3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwCreateWindow,创建宽，高位600像素，顶部标题为Hello，World，
	// 另外两个参数分别用来表示允许全屏显示和资源共享
	GLFWwindow* window = glfwCreateWindow(600, 600, "Hello, World", nullptr, nullptr);
	//关联当前GFLW窗口和OpenGL上下文
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		exit(EXIT_FAILURE);
	//开启垂直同步
	glfwSwapInterval(1);

	init(window);

	while (!glfwWindowShouldClose(window))
	{
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		//处理窗口相关的事件（如按键事件）
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
```

运行结果：

![image-20230906193926306](D:\Typora\picture\image-20230906193926306.png)

**在这GLuint是OpenGL中的数据类型，表示的就是无符号整数，所以我用unsigned int。**

1. `#define numVAOs 1`：这行代码定义了一个宏`numVAOs`，并将其值设置为1。这是为了在后面的代码中使用这个宏。
2. `unsigned int renderingProgram;`：声明一个无符号整数类型的变量`renderingProgram`，用于存储渲染程序的ID。
3. `unsigned int vao[numVAOs];`：声明一个无符号整数类型的数组`vao`，大小为`numVAOs`，用于存储顶点着色器程序的ID。
4. `unsigned int createShaderProgram()`：该函数用于创建一个渲染程序。
5. `const char* vshaderSource `:用于存储顶点着色器的源代码。
6. `const char* fshaderSource `：用于存储片段着色器的源代码。
7. `unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);`：调用OpenGL函数`glCreateShader`创建一个顶点着色器，并将其赋值给变量`vShader`。
8. `unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);`：调用OpenGL函数`glCreateShader`创建一个片段着色器，并将其赋值给变量`fShader`。
9. `glShaderSource(vShader, 1, &vshaderSource, NULL);`：调用OpenGL函数`glShaderSource`将顶点着色器的源代码传递给顶点着色器。
10. `glShaderSource(fShader, 1, &fshaderSource, NULL);`：调用OpenGL函数`glShaderSource`将片段着色器的源代码传递给片段着色器。
11. `glCompileShader(vShader);`：调用OpenGL函数`glCompileShader`编译顶点着色器。
12. `glCompileShader(fShader);`：调用OpenGL函数`glCompileShader`编译片段着色器。
13. `unsigned int vfProgram = glCreateProgram();`：调用OpenGL函数`glCreateProgram`创建一个渲染程序，并将其赋值给变量`vfProgram`。
14. `glAttachShader(vfProgram, vShader);`：调用OpenGL函数`glAttachShader`将顶点着色器添加到渲染程序中。
15. `glAttachShader(vfProgram, fShader);`：调用OpenGL函数`glAttachShader`将片段着色器添加到渲染程序中。
16. `glLinkProgram(vfProgram);`：调用OpenGL函数`glLinkProgram`链接渲染程序。
17. `glGenVertexArrays(numVAOs, vao);`：调用OpenGL函数`glGenVertexArrays`创建一个顶点着色器数组，并将其赋值给变量`vao[0]`。
18. `glBindVertexArray(vao[0]);`：调用OpenGL函数`glBindVertexArray`将顶点着色器数组绑定到当前的渲染程序中。

**在片段着色器中同样有一个变量能让我们访问输入片段的坐标，叫作gl_FragCoord。让我们来使用它基于位置来设置每个像素的值。**

```c++
const char* fshaderSource =
		"#version 430 \n"
		"out vec4 color; \n"
		"void main(void) \n"
		"{ if(gl_FragCoord.x < 255) color = vec4(1.0, 0.0, 0.0, 1.0); else color = vec4(0.0, 0.0, 1.0, 1.0);}";		
```

同时我们需要将该点设置得更大一点。

```C++
glPointSize(430.0f);
```

运行结果：

![image-20230906194644502](D:\Typora\picture\image-20230906194644502.png)



# A.4检测OpenGL和GLSL的错误

## 为什么需要检测？

- 编译与运行GLSL的代码与普通的代码不一样，GLSL的编译发生在C++运行时
- GLSL的代码并没有在CPU中运行而是在GPU中运行，因此操作系统并不能捕获OpenGL运行时的错误

以上两点让调试变得很困难，我们常常很难判断着色器的运行是否失败，以及为什么失败。

## 如何实现呢？

- printShaderLog（）：当GLSL代码编译失败时，显示OpenGL日志内容。
- printProgramLog（）：当GLSL链接失败时，显示OpenGL日志内容。
- checkOpenGLError（）：检查OpenGL错误标志，即是否发生OpenGL错误。（既可以用于检查GLSL代码编译错误，又可以见检查OpenGL运行时的错误，强烈推荐使用。）

### 具体实现代码及测试结果：

```c++
//添加三个函数
//捕获GLSL代码编译失败信息函数
void printShaderLog(unsigned int shader)
{
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
	if (len > 0)
	{
		log = (char*)malloc(len);
		glGetShaderInfoLog(shader, len, &chWrittn, log);
		std::cout << "Shader Info Log: " << log << std::endl;
		free(log);
	}
}
//捕获GLSL链接失败信息函数
void printProgramLog(int prog)
{
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetShaderiv(prog, GL_INFO_LOG_LENGTH, &len);
	if (len > 0)
	{
		log = (char*)malloc(len);
		glGetProgramInfoLog(prog, len, &chWrittn, log);
		std::cout << "Program Info Log: " << std::endl;
		free(log);
	}
}
//检查OpenGL错误函数
bool checkOpenGLError()
{
	bool foundError = false;
	int glErr = glGetError();
	while (glErr != GL_NO_ERROR)
	{
		std::cout << "glError: " << glErr << std::endl;
		foundError = true;
		glErr = glGetError();
	}
	return foundError;
}

//修改unsigned int createShaderProgram()函数进行测试
unsigned int createShaderProgram()
{
	const char* vshaderSource =
		"#version 430 \n"//版本型号
		"void main(void) \n"
		"{gl_Position = vec4(0.0, 0.0, 0.0, 1.0); }";
	//gl_Position内置的坐标变量，前三个参数对应坐标的(x,y,z)，第四个参数后面会说到
	const char* fshaderSource =
		"#version 430 \n"
		"out vec4 color; \n"
		"void main(void) \n"
		"{ if(gl_FragCoord.x < 255) color = vec4(1.0, 0.0, 0.0, 1.0); else color = vec4(0.0, 0.0, 1.0, 1.0);}";


	+//捕获编译着色器时的错误
	+int vertComplied;
	+int fragComplied;
	+int linked;
	//创建顶点着色器和片段着色器
	unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vShader, 1, &vshaderSource, NULL);
	glShaderSource(fShader, 1, &fshaderSource, NULL);
	glCompileShader(vShader);
	+checkOpenGLError();
	+glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertComplied);
	+if (vertComplied != 1)
	+{
	+	std::cout << "vertex compilation faild" << std::endl;
	+	printShaderLog(vShader);
	+}
	glCompileShader(fShader);
	+checkOpenGLError();
	+glGetShaderiv(fShader, GL_COMPILE_STATUS, &fragComplied);
	+if (fragComplied != 1)
	+{
	+	std::cout << "fragment compilation faild" << std::endl;
	+	printShaderLog(fShader);
	+}

	//捕获链接着色器的错误
	unsigned int vfProgram = glCreateProgram();
	glAttachShader(vfProgram, vShader);
	glAttachShader(vfProgram, fShader);
	glLinkProgram(vfProgram);
	+checkOpenGLError();
	+glGetProgramiv(vfProgram, GL_LINK_STATUS, &linked);
	+if (linked != 1)
	+{
	+	std::cout << "linking faild" << std::endl;
	+	printProgramLog(vfProgram);
	+}
	return vfProgram;
}
```



![image-20230908150759670](D:\Typora\picture\image-20230908150759670.png)



# A.5从文件中读取GLSL源码

## 我们为什么要选择从文件中读取GLSL源代码

- 当程序变得复杂时，再将GLSL着色器源代码内联存储在字符串中就不合适了。

我们将两个着色器的源代码从主文件中剪切放在对应的文件vertShader.glsl和fragShader.glsl中

![image-20230908154337417](D:\Typora\picture\image-20230908154337417.png)

## 代码实现

```C++
//vertShader.glsl文件
#version 430 
void main(void) 
{
	gl_Position = vec4(0.0, 0.0, 0.0, 1.0); 
}
//fragShader.glsl文件
#version 430   
out vec4 color;   
void main(void)   
{ 
	if(gl_FragCoord.x < 255) 
		color = vec4(1.0, 0.0, 0.0, 1.0); 
	else color = vec4(0.0, 0.0, 1.0, 1.0);
}

//Application.cpp文件其他不变
//函数createShaderProgram中更改如下：
unsigned int createShaderProgram()
{
	std::string vertShaderStr = readShaderSource("./res/shaders/vertShader.glsl");
	std::string fragShaderStr = readShaderSource("./res/shaders/fragShader.glsl");
	const char* vertShaderSrc = vertShaderStr.c_str();
	const char* fragShaderSrc = fragShaderStr.c_str();
	//捕获编译着色器时的错误
	int vertComplied;
	int fragComplied;
	int linked;
	//创建顶点着色器和片段着色器
	unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vShader, 1, &vertShaderSrc, NULL);
	glShaderSource(fShader, 1, &fragShaderSrc, NULL);

```

![image-20230908154801882](D:\Typora\picture\image-20230908154801882.png)

# A.6从顶点构建对象

我们想要绘制的不仅仅是一个单独的点，而是由很多顶点组成的对象。现在让我们先用三个顶点来绘制一个三角形。

## 如何绘制呢？

1. 修改顶点着色器，以便让3个不同的点输出到后续的管线阶段
2. 修改glDrawArrays()，指定3个点

## 代码实现：

```c++
//vertShader.glsl文件
#version 430 
void main(void) 
{
	if(gl_VertexID == 0)
		gl_Position = vec4(0.25, -0.25, 0.0, 1.0);
	else if(gl_VertexID == 1)
		gl_Position = vec4(-0.25, -0.25, 0.0, 1.0);
	else
		gl_Position = vec4(0.25, 0.25, 0.0, 1.0); 
}
//fragShader.glsl文件
#version 430   
out vec4 color;   
void main(void)   
{ 
	color = vec4(1.0, 0.0, 0.0, 1.0); 
}
//Application.cpp文件中的display函数修改

//glPointSize(430.0f);//设置点的大小
glDrawArrays(GL_TRIANGLES, 0, 3);
```



![image-20230908155839008](D:\Typora\picture\image-20230908155839008.png)

# A.7实现简单的场景动画

## 如何实现呢？

我们只需要定义一个变量，再定义一个变量增量，这样我们可以对那三个顶点的坐标的值加上变量的值，通过控制增量的变化来控制绘制出的三角形的移动。

## 代码实现：

```c++
//vertShader.glsl文件
#version 430 
uniform float offset;
void main(void) 
{
	if(gl_VertexID == 0)
		gl_Position = vec4(0.25+offset, -0.25, 0.0, 1.0);
	else if(gl_VertexID == 1)
		gl_Position = vec4(-0.25+offset, -0.25, 0.0, 1.0);
	else
		gl_Position = vec4(0.25+offset, 0.25, 0.0, 1.0); 
}
//Application.cpp文件中的display函数修改
void display(GLFWwindow* window, double currentTime)
{
	glClear(GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(renderingProgram);

	x += inc;
	if (x > 1.0) inc = -inc;
	if (x < -1.0) inc = -inc;

	unsigned int offsetLoc = glGetUniformLocation(renderingProgram, "offset");
	glProgramUniform1f(renderingProgram, offsetLoc, x);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}
```







