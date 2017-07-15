# Algorithms-for-job-hunting

### 项目说明：
  - 本项目用于小组成员维护`在找工作中遇到的常用算法`，用以总结以及分享学习经验,也便于大家对知识的回顾。
  - 关于项目编译请参考[`编译说明`](#build "build");
  - **参与项目维护前**，请参阅[`维护规则`](#maintenance "maintenance");
       
### <a id="build"> 编译说明： </a>
  - Windows：
     - None
  - Linux：
     - 在根目录打开终端运行指令：g++ -std=c++11 main.cpp -o Algs
     - 生成可执行文件 Algs，然后直接在终端输入 ./Algs 即可看到算法运行结果

### 目录结构：
> #### Algorithm-for-job-hunting  `项目根目录` 
>> | 文件名 | 说明 |
>> | :------| :----|
>> |[main.cpp](./main.cpp) | |
>> |[TestExample.txt](./TestExample.txt) |  测试用例文件，输入重定向后读取的文件 <br>注意：当用到此文件，需要针对不同算法输入需求，做对应的用例设置|
>> | ...| | 
>> #### src  `算法源代码目录，用于放置所有算法代码`
>>> | 文件名 | 说明 |
>>> | :------| :----|
>>> |[Algs.h](./src/Algs.h) |  用于include所有算法的头文件,可通过该文件查询已实现的算法目录|
>>> |[BubbleSort.h](./src/BubbleSort.h) | 冒泡排序|
>>> | ... | |
### <a id="maintenance"> 维护规则： </a>
**1、名字空间:** <br>
	小组成员编写的算法类，请包含在自己的名字空间中，以免命名冲突；

**2、添加现有算法不同版本:** <br>
	当需要对项目中**已有的算法文件**，添加自己的算法版本时，请在自己的名字空间中，以大写字母'C'+'文件名'声明类，并在类中实现自己的算法，另外需要实现一个**静态的测试接口 test()**；<br>
	eg. 成员 FreshMan 需要添加自己的[`冒泡排序`](./src/BubbleSort.h)版本：
```  C++
//BubbleSort.h   //文件名.h

//文件描述、头文件引用等...

namespace Chirl  //成员Chirl的冒泡排序版本;
{
	class CBubbleSort
	{
		//...	
	};
};


namespace FreshMan         //FreshMan 的名字空间
{
	class CBubbleSort  //类名 = C + BubbleSort (文件名) 
        {
		void BubbleSort()
		{
			   //具体算法类;
		}

		static void test()   //静态测试函数接口，方便在main中调用，调试;
		{
			  //具体测试代码;
		}
	};
};	

```
**3、test接口:** <br>
	**功能：** test接口主要用于读取算法的测试数据，以及调用对应的算法；<br>
	**注意：** 为方便输入重定向后，在[TestExample.txt](./TestExample.txt)编辑测试用例，请在test接口合适位置放置一个测试用例，或则对本算法的输入格式进行清晰的描述(可参照[BubbleSort.h](./src/BubbleSort.h)中的test写法);
``` C++
//test接口简单示例;
static void test()
{
    /*********测试用例************
        10
        51 49 18 93 6 23 13 55 19 1
    ******************************/
   
   //测试代码....
}

``` 
**4、添加新算法:** <br>
	当需要添加新算法时，请创建**对应算法名的头文件**，并以2中的规则添加名字空间以及类；同时，请在[Args.h](./src/Algs.h)中**引用该头文件**，并加以简单的注释说明;

**5、main中调用对应的算法：** <br>
	直接调用对应名字空间中需要的算法test函数;<br>
	为了方便测试，这里可以通过设置输入重定向开关'REIOS'，设置从文档读取测试用例，或从控制台读取;
	如果想要从文档中读取，请在[TestExample.txt](./TestExample.txt)中按照代码需求编辑对应的测试用例;
		eg. 调用Chirl的第一题算法：
``` C++
//main.cpp中
#include "Algs.h"
int main(int argc, char **argv)
{
#define REIOS 1  //输入重定向开关, 1 重定向到根目录下"TestExample.txt"文件中;
                 //               0 从控制台输入;   
	//....
	
	Chirl::CBubbleSort::test();   //通过指定名字空间(Chirl)选择不同成员的算法;
				      //通过指定算法类名(CBubbleSort)调用其test接口，调用特定成员的该算法实现;
	
	//...
	return 0;
}
```

### 项目相关问题：
   - 请联系 ：ChirlChen@163.com
