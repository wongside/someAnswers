# First Day

* << 运算符返回左侧的运算对象，若未遇到错误，检测成功。若为无效输入就是无效状态，条件为假。

* ​wchar_t 宽字符类型，对应的输入输出流为wcin wcout wcerr，与普通的类型定义在同一头文件中

* 不能拷贝或复值IO对象，所以IO对象不能直接作为形参或者返回类型（但是可以用引用的方式，并且由于读写IO会改变其状态，所以在引用时不能使用const）。

* 一个流一旦失败，其后续的IO操作都会失败。  

* 如果程序异常终止，缓冲区不会被刷新。（很有可能停留在缓冲区中待打印）

* fstream in(s),打开名为s的文件，s也可以是String类型或者指向字符串的指针（C风格）

* in.open(filename)将filename关联到in流

* 通过条件编译设置输出重定向，并把时间作为不同的标志

  ```C++
  #define LOCAL 1

  #if LOCAL
  #include <fstream>
  #include <ctime>
  #endif
  #if LOCAL
  	fstream cin("datain.txt",fstream::in);
  	fstream cout("dataout.txt",fstream::app);
  	cout << endl << "time:"<< time(0)%1000 << endl;
  #endif
  ```

  ​

