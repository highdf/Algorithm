# bomb解题思路

<!-- mtoc-start -->

  * [准备](#准备)
  * [phase_1解题思路](#phase_1解题思路)
  * [phase_2解题思路](#phase_2解题思路)
* [phase_3解题思路](#phase_3解题思路)

<!-- mtoc-end -->

## 准备
我的实验环境：ubuntu24+VMware

使用命令：

`wget https://github.com/happysnaker/CSAPPLabsAndNotes/blob/CSAPP/AllTheLabsHandout/bomb.tar`

获取实验文件，再通过命令`tar -xvf bomb.tar`解压压缩包，再使用从`cd bomb`进入实验目录，读者可以打开README文件，了
解个大概，要解决bomb问题，我们首先要获得bomb可执行文件的汇编代码,在linux系统上可使用`objdump -S bomb > bomb.s`得
到一个名为bomb.s的汇编语言文件,接下来只需要通过vim打开它就可以了,如图：

![empty][start]

为了方便测试，避免从命令行进行频繁的输入，我将结果存放在`answer`文件中，在测试时，输入`bomb answer`届可以了。  

## phase_1解题思路
现在我们开始解题，在vim中输入`/phase_1<enter>`找到phase_1的代码块,如下图：

![empty][phase_1-0]

我们来看第一行代码`mov 0x8 %rsp`，这行代码的意思是在栈空间中分配8个字节的空间，而2～3行是一个函数调用，从代码中
可以看出调用的函数为`strings_not_equal`，从名称上看，这个函数的作用应该是比较字符串是否相等。那么，第2行就是调用前的参数传递了，
不过，这里我们有一个疑问，既然是比较字符串是否相等，那么，不是应该传递两个参数吗，可为什么只有一个呢？***[p0]***
我们继续看4～5行,eax寄存器存放的是函数调用的返回值，而test指令是对其进行测试，根据代码，若为0,则跳转到爆炸指令之后，
反之，则执行爆炸函数。因此，我们的输入只要和pahse_1内部定义的字符串相等就可以了。

我们怎样才能得到这个字符串呢？我们需要用gdb来调试bomb获取该字符串，先回到终端，输入`gdb bomb`,`break phase_1`,`run`
进入调试，再输入`x/s 0x402400`就可以得到结果了。

![empty][phase_1-1]

最后，我给出了等价的c语言代码
```c
    char *key = "Border relations with Canada have never been better.";
    
    if(strings_not_equal(input,key) != 0) {
        explode_bomb;
    }

    retrun 0;
```

>p1:为什么只要一个参数传递呢？因为我们输入字符串是通过参数传递进入phase_1的，因此另一个参数（也就是我们的输入）已经
存放寄存器里了，因此，不需要再传递了。

## phase_2解题思路
接下来，我们来看`phase_2`，在vim中输入`/phase_2`，再通过`n`定位代码段`phase_2`，如图：

![image][phase_2-0]

执行`sub    $0x28,%rsp`分配了40的字节的内存块。  
`mov    %rsp,%rsi`
`#call   40145c <read_six_numbers>`
这两行代码是一个完整的函数调用，第一行将栈顶元素的地址作为参数进行传递，从函数名字可以大概看出这个函数的作用是读六个整数，我们跳过这个函数的实现，先看后面的代码。  

`cmpl   $0x1,(%rsp)`
`je     400f30 <pha`

在函数返回后，对栈顶元素与1进行的比较，若相等，则跳转到`400f30`处，反之，执行`call   40143a <explode_bomb>`，引爆炸弹。我们接着看`400f30`出的代码。  
`lea    0x4(%rsp),%rbx`
`lea    0x18(%rsp),%rbp`
这两行代码分别读取了栈顶偏移量为4与18的地址，`jmp    400f17 <phase_2+0x1b>`跳转到`400f17`处，  
`mov    -0x4(%rbx),%eax`
`add    %eax,%eax`
`cmp    %eax,(%rbx)`
`je     400f25 <phase_2+0x29>`
`0x4(%rbc)`的值刚好是栈顶元素，因此，这块代码的行为是区栈顶元素并扩大2倍与栈顶偏移量是4的元素比较，若想等，则跳转到`400f25`处，反之，则爆炸。  
我们来看`400f225`处的代码，  
`add    $0x4,%rbx`
`cmp    %rbp,%rbx`
`jne    400f17 <phase_2+0x1b>`
`jmp    400f3c <phase_2+0x40>`


# phase_3解题思路
打开bomb.s文件，然后，通过vim的查找模式找到phase_3代码段。

![empty][phase_3-0]

接着，我们开始读代码吧！  
开头的第一行:`sub    $0x18，%rsp`这行指令使用来完成栈分配的。  
看2到4行很显然是为第五行的函数调用准备参数，第五行就是函数调用了，我们来看看它调用的是什么函数?  
`call   400bf0 <__isoc99_sscanf@plt>`这其实就是对scanf的调用，同时，从2到4行的参数准备中可以看出，scanf会读入两个值。  
那读入这两个值是干什么的呢？我们接着往下看，在这里，程序对读入的值进行了测试 

![empty][phase_3-1]

由ja指令我们可以知道这两行代码是在判断读入的第一个值是否大于7，接着我们看一下大于7
和小于7分别会发生什么:大于7

![empty][phase_3-2]

小于7

![empty][phase_3-3]

我们看到如果第一个值大于7，就会引爆炸弹!反之，则不会。 
那么接下来发生了什么呢?我们看代码`jmp    *0x402470(,%rax,8)`这条指令的含义是使用`*0x402470(,%rax,8)`指向
的地址空间中的值作为跳转地址，此时，我们要想知道这个跳转地址是什么
就需要使用gdb来调试它了，输入`gdb bomb`进入gdb，再输入`break phase_3`与`run answer`来
设置断点与运行程序，再随便输入0与1，结果如图

![empty][phase_3-4]

再输入`x/7xg 0x`，它就输出了7个地址值，

![empty][phase_3-5]

而这些地址我们都可以在汇编代码中发现它们，我们选择其中 一个来查看

![empty][phase_3-6]

从图中我们看到有一个分支行为，若`0xc(%rsp)`处的值不等于0xcf， 则爆炸，反之，则回收内存，离开函数。  
最后，给出与phase_3行为相同的c语言代码

```c
    int num1,num2;
    int n = scanf("%d%d",&num1,&num2);

    if(n == 2) {
        switch(num1) {
            case 0:{
                if(num2 != 0xcf) {
                    explode_bomb();
                }
                break;
            }
            case 1:...
        }
    } else {
        explode_bomb();
    }

    return 0;
}
```
[start]: https://raw.githubusercontent.com/highdf/Picture/1c8736db1c9925c0e065912938014fc737da2fd5/bomb/start.png

[phase_1-0]: https://raw.githubusercontent.com/highdf/Picture/refs/heads/main/bomb/phase_1-0.png
[phase_1-1]: https://raw.githubusercontent.com/highdf/Picture/refs/heads/main/bomb/phase_1-1.png

[phase_3-0]: https://raw.githubusercontent.com/highdf/Picture/1c8736db1c9925c0e065912938014fc737da2fd5/bomb/phase_3-0.png
[phase_3-1]: https://raw.githubusercontent.com/highdf/Picture/1c8736db1c9925c0e065912938014fc737da2fd5/bomb/phase_3-1.png
[phase_3-2]: https://raw.githubusercontent.com/highdf/Picture/1c8736db1c9925c0e065912938014fc737da2fd5/bomb/phase_3-2.png
[phase_3-3]: https://raw.githubusercontent.com/highdf/Picture/1c8736db1c9925c0e065912938014fc737da2fd5/bomb/phase_3-3.png
[phase_3-4]: https://raw.githubusercontent.com/highdf/Picture/1c8736db1c9925c0e065912938014fc737da2fd5/bomb/phase_3-4.png
[phase_3-5]: https://raw.githubusercontent.com/highdf/Picture/1c8736db1c9925c0e065912938014fc737da2fd5/bomb/phase_3-5.png
[phase_3-6]: https://raw.githubusercontent.com/highdf/Picture/1c8736db1c9925c0e065912938014fc737da2fd5/bomb/phase_3-6.png
