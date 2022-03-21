# C++学习笔记

#### 入门

* ##### hello world程序

  ~~~c++
  #include <iostream>
  int main(){
      std::cout << "Hello, World!" << std::endl;
      return 0;
  }
  ~~~

  

#### string操作

* getline读取一整行

  ~~~c++
  int main(){
      string line;
      while (getline(cin, line))
          cout << line << endl;
      return 0;
  }
  ~~~

* 只输出非空的行

  empty函数：如果string为空，返回真

  ~~~c++
  while (getlien(cin, line))
      if(! line.empty())
          cout << line << endl;
  ~~~

* size函数返回string对象中字符的个数

* cctype头文件中的函数

  | 函数       | 作用                                               |
  | ---------- | -------------------------------------------------- |
  | islower(c) | 当c是小写字母时为真                                |
  | isspace(c) | 当c是空白时为真                                    |
  | isupper(c) | 当c是大写字母时为真                                |
  | tolower(c) | 如果c是大写字母，输出对应的小写字母，否则原样输出c |
  | toupper(c) | 如果c是小写字母，输出对应的大写字母，否则原样输出c |

  

#### 迭代器

* 迭代器实现将第一个字符改为大写

~~~c++
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s("some string");
    if (s.begin() != s.end()){
        auto it = s.begin();
        *it = toupper(*it);
    }
    cout << s << endl;
    return 0;
}
~~~



* ##### 


#### 顺序容器

* ##### 各种顺序容器

  vector（**⭐最常用**）：快速随机访问，在尾部之外的位置插入或删除元素可能很慢         

  deque：快速随机访问，在头尾插入/删除速度很快

  list：只支持双向顺序访问，**在list中任何位置插入/删除都很快**

  foward_list：只支持单向顺序访问，在任何位置插入/删除都很快

  array：固定大小数组。支持快速随机访问，但**不能添加或删除**元素

  string：与vector类似，专门用来保存字符。随机访问快

* ##### 顺序容器的操作

  |        操作         |                             作用                             |
  | :-----------------: | :----------------------------------------------------------: |
  |      c.clear()      |                  删除c中所有元素，返回void                   |
  |    c.push_back()    |                                                              |
  | c.begin(), c.end()  |                                                              |
  |    c.pop_back()     |               删除c中尾元素，若c为空，返回void               |
  |    c.pop_front()    |               删除c中首元素，若c为空，返回void               |
  |     c.erase(p)      | 删除迭代器p所指定的元素，返回一个指向被删元素之后元素的迭代器 |
  | c.back(), c.front() |                  返回c中尾元素/首元素的引用                  |
  |     c.resize(n)     | 调整c的大小为n个元素。若n<c.size()，则多出的元素被丢弃；若添加新元素，对新元素的值进行初始化 |
  |   c.resize(n, t)    |      调整c的大小为n个元素，任何新添加的元素被初始化为t       |
  
  ~~~c++
  #删除list中所有奇数元素的例子
  list<int> lst = {0,1,2,3,4,5,6,7,8,9};
  auto it = lst.begin();
  while(*it != lst.end()){
      if(*it % 2)
          it = lst.erase(it);
      else
          ++it;
  }
  ~~~
  
  

* ##### foward_list 操作

  



#### 泛型算法

