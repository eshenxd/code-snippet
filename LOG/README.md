#### log for c++

#### how to use
```cpp
	#define LOGF  // if you want to save the log info to the file log.txt
	#include "log.hpp" //include log.hpp file


	int main()
	{
		myLog(1);
		myLog(2);
		myLog("test my log file");
		myLog("%s %d %s", "test my log file", 2, "times");
	}
```

#### compile in linux
```
g++ main.cpp -o main -std=c++11 -D_DEBUG -DLOGF
```

#### changes in version 1.0
- 更改了整体架构，不再采用类的封装方式
- 修改了log级别控制，release下不再显示调试代码是打印的位置信息
- 不再采用默认的index，而是由每一次函数调用时通过参数index来指定

#### changes in version 1.1
- 做了相关修改，在linux下测试通过

#### wants to change
- 希望在下一个版本中采用更加完整的log输出分类，能够通过log level打印不同级别的log信息
