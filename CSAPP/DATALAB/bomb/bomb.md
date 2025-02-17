### bomb解题思路

<!-- vim-markdown-toc GFM -->

* [前言](#前言)
* [实验环境](#实验环境)
* [准备](#准备)
* [汇编小结](#汇编小结)
* [phase_1解题思路](#phase_1解题思路)
* [phase_2解题思路](#phase_2解题思路)
* [phase_3解题思路](#phase_3解题思路)
* [phase_4解题思路](#phase_4解题思路)
* [phase_5解题思路](#phase_5解题思路)

<!-- vim-markdown-toc -->

#### 前言
- 这是一篇关于CSAPP中bomb实验的学习笔记，介绍了其中Phase_1~phase_5的解法，若有错漏，望不吝指正。  

#### 实验环境
- 虚拟机：VMware
- 操作系统：Ubuntu24.04
- 工具：
    1. vim
        - **介绍**：在终端高效编辑文本文件的编辑器  
        - **下载命令**：sudo apt install vim  
    2. gdb
        - **介绍**：在终端调试C语言可执行程序的调试器  
        - 下载命令：sudo apt install gdb  
    3. objdump
        - **介绍**：用于生成可执行文件的汇编代码  
        - 属于Ubntu系统预装程序，无需手动下载  
- 获取实验文件
```bash
wget https://csapp.cs.cmu.edu/3e/bomb.tar # 下载实验文件
tar -xvf bomb.tar && cd bomb # 解压并进入目录
```

#### 准备
- 文档阅读  
使用`vim bomb.c`查看`bomb`程序的大致执行过程。  
- 获取汇编文件
```bash
objdump -S bomb > bomb.s # 在当前目录下生成汇编文件bomb.s
```
- 查看结果  
使用命令`vim bomb.s`打开文件查看是否成功。如图：  
![image][start]
为了在测试过程中频繁的反复输入，可以创建一个`answer`文件，用于存放答案，测试时将其作为参数传递即可。  
```bash
touch answer # 创建参数文件
bomb answer  # 执行bomb，并传递参数answer
```

#### 汇编小结
在本节会简单介绍一些基本汇编指令的使用语法与语义。  
- 指令的一般格式
    1. 指令操作符 操作数0 操作数1 ...
    2. 指令操作符的作用是标识指令的具体行为。
    3. 操作数标识了指令操作的对象，一条完整的指令中操作数的数量会因操作符的不同而不同，在下文的具体指令的介绍中，读者可以看到有些指令需要两个操作数，有的只需要一个。
- 操作数语法与语义
    1. 常量
        - 语法：在一条汇编指令文本中，常量使用`$`作为前缀，数值用十六进制表达。  
        - 语义：在`mov $0xa %rsi`这条完整的汇编指令中，字符串`$0xa`的语义就是一个常量10。
    2. 寄存器
        - 语法：使用`%`作为前缀符，后面紧跟一个寄存器的标识符。
        - 语义：在汇编指令`mav $0xb %rsi`中，操作数`%rsi`的语义是使用寄存器`rsi`。
    3. 内存寻址
        - 语法：在对内存空间的标识中，没有使用像寄存器那样使用字符串进行标识，而是通过内存地址来标识一片内存空间。文本格式为`offset(%a %b M)`，其中，`offset`是一个十六进制的字符串，标识一个数值。括号内`%a`称为基址寄存器，存储一个内存地址值。`%b`也是一个寄存器，称为变址寄存器。`M`是一个十六进制的字符串，标识一个数，称为比例常量。。`offset(%a %b M)`指向的内存地址是运算表达式`%a+%b*M+offset`的值。
        - 语义：汇编指令`mov 0xa(%rsi %rdi 2) %rax`中，字符串`0xa(%rsi %rdi 4)`标识一个你存地址，假设寄存器`%rsi`与`%rdi`的值是`0xffff0011`与`0xffff0100`，则上述文本标识的内存地址是`0xffff0011+0xffff0100*2+0xa`

- 寻址方式
    1. 寄存器标识符寻址：
- 传送指令相关
    

--- 

#### phase_1解题思路
现在我们开始解题，在vim中输入`/phase_1<enter>`找到phase_1的代码块。  
```asm
sub    $0x8,%rsp
mov    $0x402400,%esi
call   401338 <strings_not_equal>
test   %eax,%eax
je     400ef7 <phase_1+0x17>
call   40143a <explode_bomb>
add    $0x8,%rsp
ret
```
我们来看第一行代码`sub 0x8 %rsp`，这行代码的意思是在栈空间中分配8个字节的空间，而2～3行是一个函数调用，从代码中可以看出调用的函数为`strings_not_equal`，从名称上看，这个函数的作用应该是比较字符串是否相等。那么，第2行就是调用前的参数传递了，不过，这里我们有一个疑问，既然是比较字符串是否相等，不是应该传递两个参数吗，可为什么只有一个呢[^1]？  
我们继续看4～5行,eax寄存器存放的是函数调用的返回值，而test指令是对其进行测试，根据代码，若为0,则跳转到爆炸指令之后，反之，则执行爆炸函数。因此，我们的输入只要和phase_1内部定义的字符串相等就可以了。  
我们怎样才能得到这个字符串呢？我们需要用gdb来调试bomb获取该字符串，先回到终端，输入`gdb bomb`,`break phase_1`,`run`进入调试，再输入`x/s 0x402400`就可以得到结果了。  
![image][phase_1-1]
最后，我给出了等价的C语言代码
```c
void phase_1(char *input){
    char *key = "Border relations with Canada have never been better.";

    if(strings_not_equal(input,key) != 0) {
        explode_bomb();
    }
}
```

---

#### phase_2解题思路
我们来看`phase_2`，在vim中输入`/phase_2`，再通过`n`定位代码段`phase_2`，如图：
![image][phase_2-0]
执行`sub    $0x28,%rsp`在栈上分配了40字节的内存块。  
```asm
mov    %rsp,%rsi
#call   40145c <read_six_numbers>
```
两行代码是一个的函数调用，第一行将栈顶地址（%rsp的值）作为参数进行传递，从函数名字可以大概看出这个函数的作用是读六个整数，我们来看这个函数到底做了什么？  
用`/read_six_numbers`跳转到定义代码块处，如图：
![image][phase_2-1]
`mov    %rsp,%rsi`我们可以知道这个函数的参数是phase_2的栈顶指针。  
```asm
mov    %rsi,%rdx
lea    0x4(%rsi),%rcx
lea    0x14(%rsi),%rax
mov    %rax,0x8(%rsp)
lea    0x10(%rsi),%rax
mov    %rax,(%rsp)
lea    0xc(%rsi),%r9
lea    0x8(%rsi),%r8
mov    $0x4025c3,%esi
mov    $0x0,%eax
call   400bf0 <__isoc99_sscanf@plt>
```
一大段乍看起来有一点可怕，但我们仔细一看会发现这其实是一个函数调用，只不过调用的参数比较多，一共有6个，并且，调用的函数是scanf，这个函数我们就熟悉了，它会读取用户的输入，并将读到的值写入参数指定的内存块中。最后，我们来看这些值会写入到哪里？因为rsi的值是phase_2的栈顶指针，所以，读入的值被写入到了离栈顶偏移量为0,4,8,12,16,20的位置。
回到phase_2我们继续看接下来发生了什么？  
```asm
cmpl   $0x1,(%rsp)
je     400f30 <phase_2+0x34>
call   40143a <explode_bomb>
```
函数返回后，对栈顶元素与1进行的比较，若相等，则跳转到`400f30`处，反之，执行`call   40143a <explode_bomb>`，引爆炸弹。因此，结合`read_six_number`的行为，我们可以知道我们有输入的第一个数是1。我们接着看`400f30`处的代码。  
```asm
lea    0x4(%rsp),%rbx
lea    0x18(%rsp),%rbp
jmp    400f17 <phase_2+0x1b>
```
两行代码分别获取了栈顶偏移量为4与24的地址，并跳转到`400f17`处，我们接着看`400f17`处的代码。  
```asm
mov    -0x4(%rbx),%eax
add    %eax,%eax
cmp    %eax,(%rbx)
je     400f25 <phase_2+0x29>
call   40143a <explode_bomb>
```
`0x4(%rbx)`的值刚好是栈顶元素，因此，这块代码的行为是取栈顶元素，并乘以2后与栈顶偏移量是4的元素比较，若相等，则跳转到`400f25`处，反之，则爆炸。我们来看`400f25`处的代码。  
```asm
add    $0x4,%rbx
cmp    %rbp,%rbx
jne    400f17 <phase_2+0x1b>
jmp    400f3c <phase_2+0x40>
```
这段代码更新了rbx寄存器的值，再测试了rbp与rbx是否相等，若相等，则执行：
```asm
add    $0x28,%rsp
pop    %rbx
pop    %rbp
ret
```
很显然这段代码回收了分配的空间，并执行ret返回给调用者。若不相等，则：  
```asm
mov    -0x4(%rbx),%eax
add    %eax,%eax
cmp    %eax,(%rbx)
je     400f25 <phase_2+0x29>
```
这段代码在之前执行过一次，但与之前一次不同的是rbx的值增加了4字节，因此，这段代码的行为是测试rbx与前一个值是否为2倍的关系，若是，则增加rbx，再测试，直到测试完第六个数为止。反之，则爆炸。  
综合一下，phase_2的行为就是用户读入6个数，要求第一个数是1，并且，后面5个数按公比为2的等比数列递增。  
最后，我给出等价的C语言实现。  
```c
int a[6];

scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);

if(a[0] != 1) {
    explode_bomb();
}

for(int i = 1;i < 6;i ++) {
    if(a[i] != a[i-1] * 2) {
        explode_bomb();
    }
}
```

---

#### phase_3解题思路
打开bomb.s文件，然后，通过输入`/phase_3`查找`phase_3`的代码段，如图：
![image][phase_3-0]
接着，我们开始读代码吧！  
开头的第一行:`sub    $0x18，%rsp`这行指令用于来完成栈分配的。接下来：
```asm
lea    0xc(%rsp),%rcx
lea    0x8(%rsp),%rdx
mov    $0x4025cf,%esi
mov    $0x0,%eax
call   400bf0 <__isoc99_sscanf@plt>
```
`call   400bf0 <__isoc99_sscanf@plt>`这其实就是对scanf的调用，同时，从2到4行的参数准备中可以看出，scanf会读入两个值。那读入这两个值是干什么的呢？我们接着往下看：  
```asm
cmp    $0x1,%eax
jg     400f6a <phase_3+0x27>
call   40143a <explode_bomb>
```
这里，测试了返回值，若返回值大于1，则跳转到`400f6a`处，反之，则引爆炸弹。这里，之所以这样做，是为了测试用户是否读入2个数，如果没有，就引爆炸弹。我们来看`400f6a`那里发生了什么？  
```asm
cmpl   $0x7,0x8(%rsp)
ja     400fad <phase_3+0x6a>
mov    0x8(%rsp),%eax
jmp    *0x402470(,%rax,8)
```
这里测试了读入的第一个值与7的大小关系，如果大于7,则跳转到`400fad`处，
```asm
400fad:	e8 88 04 00 00       	call   40143a <explode_bomb>
```
这里，他引爆了炸弹。因此，第一个输入值不能大于7。  
如果小于7，接着就进行了间接跳转，跳转目标存储在`0x402470(,%rax,8)`内存地址处，此时，我们要想知道这个跳转地址是什么
就需要使用gdb来调试它了，回到终端，输入`gdb bomb`进入gdb，再输入`break phase_3`与`run answer`来设置断点与运行程序，再随便输入0与1，结果如图
![image][phase_3-1]
再输入`x/8xg 0x402470`，它就输出了7个地址值，
![image][phase_3-2]
而这些地址我们都可以在汇编代码中发现它们，我们选择其中 一个来查看
![image][phase_3-3]
从图中我们看到有一个分支行为，若`0xc(%rsp)`处的值不等于0xcf， 则爆炸，反之，则回收内存，离开函数。所以，`phase_3`的行为就是根据用户输入第一个的0~7的值，执行不同的分支，测试不同的第二个输入。  
最后，给出与phase_3行为相同的C语言代码：
```c
int num1,num2;
int n = scanf("%d%d",&num1,&num2);

if(n == 2) {
    switch(num1) {
        case 0: if (num2 != 207) explode_bomb(); break;
        case 1: if (num2 != 707) explode_bomb(); break;
        case 2: if (num2 != 256) explode_bomb(); break;
        case 3: if (num2 != 389) explode_bomb(); break;
        case 4: if (num2 != 206) explode_bomb(); break;
        case 5: if (num2 != 682) explode_bomb(); break;
        case 6: if (num2 != 327) explode_bomb(); break;
        case 7: if (num2 != 311) explode_bomb(); break;
        default: explode(); // 实际由ja指令处理
    }
} else {
    explode_bomb();
}

return 0;
```

---

#### phase_4解题思路
现在就要开始上强度了，问题难度再增加了一节，上代码：
```asm
sub    $0x18,%rsp
lea    0xc(%rsp),%rcx
lea    0x8(%rsp),%rdx
mov    $0x4025cf,%esi
mov    $0x0,%eax
call   400bf0 <__isoc99_sscanf@plt>
```
这里和之前的问题一样，分配了24字节的内存块，然后，传递了两个参数，调用scanf读取两个整数，接下来：
```asm
cmp    $0x2,%eax
jne    401035 <phase_4+0x29>
```
这里测试了返回值，若不为2,即没有读两个数，就跳转到`explode_bomb`引爆炸弹。反之，则执行：
```asm
cmpl   $0xe,0x8(%rsp)
jbe    40103a <phase_4+0x2e>
call   40143a <explode_bomb>
```
对读入的第一个数进行了测试，若大于0xe或小于0[^2]，则执行`<explode_bomb`引爆炸弹。  
若小于等于0xe，则执行跳转，我们来看`0x40103a`处有什么？  
```asm
mov    $0xe,%edx
mov    $0x0,%esi
mov    0x8(%rsp),%edi
call   400fce <func4>
```
这里显然是一个函数调用，传递的参数分别是读入第一个数,0x0与0xe，我们先不深入了解`func`的行为，看看返回后发生了什么？  
```asm
test   %eax,%eax
jne    401058 <phase_4+0x4c>
cmpl   $0x0,0xc(%rsp)
je     40105d <phase_4+0x51>
call   40143a <explode_bomb>
```
测试返回值若非0则爆炸，否则检查第二个输入值是否非0,若为0,则爆炸。反之，跳转到`40105d`：
```asm
40105d:	48 83 c4 18          	add    $0x18,%rsp
```
回收内存块，退出函数。好了,现在我们可以确定有输入的第二个值是0，现在我们只需要确定第一个值了。因为，先前读入的第一个值被作为参数传递给了`func`函数，并要求func4返回值是0，那么，我们来看在`func`里发生了什么？  
输入`/func4`命令的定位函数，如图：

![image][phase_4-0]

先看第一块：
```asm
mov    %edx,%eax
sub    %esi,%eax
mov    %eax,%ecx
shr    $0x1f,%ecx
add    %ecx,%eax
```
开始的两行用参数edx-esi并将结果写入eax,ecx中，然后右移ecx31位再加上eax，用C语言描述就是：
```c
int eax = edx - esi;
eax = (eax >> 31) + eax;
```
这里进行第二步运算是在对eax进行向0取整，至于为什么这么做？我也不知道，若读者知道，望不吝指点。  
```asm
sar    $1,%eax
lea    (%rax,%rsi,1),%ecx
cmp    %edi,%ecx
jle    400ff2 <func4+0x24>
```
这里对eax进行了右移1位的操作，等价于对其进行除以2的运算，接着更新ecx的数值为eax+rsi，再对ecx与edi(即用户读入的第一个数)进行了测试，若小于等于，则跳转到`400ff2`处，
```asm 
mov    $0x0,%eax
cmp    %edi,%ecx
jge    401007 <func4+0x39>
```
这里又测试了edi与ecx，若大于等于0,则，跳转`401007`处，我们来看：
```asm
add    $0x8,%rsp
ret
```
显然，这段的作用是退出该函数，因此，我们可以得到一个结论，当且仅当，edi与ecx相等时，会退出该函数。那么,在edi分别大于或小于ecx时，发生了什么？我们又回到此处代码块：
```asm
sar    $1,%eax
lea    (%rax,%rsi,1),%ecx
cmp    %edi,%ecx
jle    400ff2 <func4+0x24>
```
由此处可知，若edi大于ecx会发生跳转到：
```asm 
mov    $0x0,%eax
cmp    %edi,%ecx
jge    401007 <func4+0x39>
```
在第三行代码处，由于ecx小于edi因此不会发生跳转，所以，将执行：
```asm
lea    0x1(%rcx),%esi
call   400fce <func4>
lea    0x1(%rax,%rax,1),%eax
```
在这里更新了原始参数esi为rcx+1其余的不变，再递归调用了函数func4，最后返回后，更新返回值为`2 * eax + 1`，此时我们已经有一点混乱了，这都是什么和是什么？所以先让自己放松一下，理理思路！！  
接下来看，ecx大于edi的情况：
```asm
lea    -0x1(%rcx),%edx
call   400fce <func4>
add    %eax,%eax
jmp    401007 <func4+0x39>
```
若ecx大于edi，则会更更新原始参数edx，然后递归调用func，接着更新返回值为`2 * eax`，最后，跳转到`401007`处，退出函数。
综合起来看func的行为就是递归二分查找法找【esi,edx】(初始值是0与0xe)之间的一个值，其中esi存放的是查找区间的下限，edx存放查找区间的上限，edi是用户的输入作为查找项，以下是等价的c代码：
```c
int eax = ( edx - esi ) / 2;
//edx 上限，esi 下限
int ecx = (esi + eax);
int re;

if(edi > ecx) {
    re = func(edi,ecx + 1,edx);        
    re = re * 2 + 1;
} else if(edi < ecx) {
    re = func(edi,esi,ecx - 1);
    re = re * 2;
} else {
    re = 0;
}
```
在phase_4中要求func的返回值为0,才不会爆炸，那么edi为多少时,func会返回0呢？  
最后，我给出phase_4的C语言代码：
```c
{
    int a, b;
    if (sscanf(input, "%d %d", &a, &b) != 2 || a > 14 || b != 0) 
        explode_bomb();

    if (func4(a, 0, 14) != 0)
        explode_bomb();
}
```

#### phase_5解题思路
```asm
push   %rbx
sub    $0x20,%rsp
mov    %rdi,%rbx
mov    %fs:0x28,%rax
                             
mov    %rax,0x18(%rsp)
xor    %eax,%eax
call   40131b <string_length>
```
开始时，phase_5与其他的差不多，分配了栈空间，准备调用参数%rbx，调用函数`string_length`，从函数名中我们可以大致知道这个函数的作用是验证参数字符串的长度。我们看看返回后发生了什么？
```asm
cmp    $0x6,%eax
je     4010d2 <phase_5+0x70>
call   40143a <explode_bomb>
```
函数返回后，测试返回值与6的大小关系，如果等于6,则跳转到`0x4010d2`处，反之，则引爆炸弹。看看`0x4010d2`处有什么？  
```asm
mov    $0x0,%eax
jmp    40108b <phase_5+0x29>
```
这里，将%eax的值置于0，然后跳转到`0x40108b`处。  
```asm
movzbl (%rbx,%rax,1),%ecx
mov    %cl,(%rsp)
mov    (%rsp),%rdx
and    $0xf,%edx
```
%rbx是指向输入字符串的指针，因此，这条指令的含义是读第%rax（rax的初始值是0）个字符，写入%rcx中。  
cl寄存器是rcx寄存器的后8位，因此结合上一条指令我们可以知道这块代码读取了输入字符串的第rax个字符，并将其写入到了rdx寄存器中，然后，执行and指令，这条指令的含义是将寄存器edx中数据的后四位取出到rdx中，那么，取出的四位机器吗是用来干什么的呢？接着往下看：
```asm
movzbl 0x4024b0(%rdx),%edx
mov    %dl,0x10(%rsp,%rax,1)
add    $0x1,%rax
cmp    $0x6,%rax
jne    40108b <phase_5+0x29>
```
取出基址是0x4024b0，以输入字符的低4位作为偏移量,从地址`0x4024b0 + rdx`读取数据，写入到edx中，然后，再将其写入到离栈顶元素的偏移是rax+0x10的地方，将rax加1，最后测试rax的值。  
当小于6时，跳转到40108b，我们来看40108b那里有什么，
```asm
movzbl (%rbx,%rax,1),%ecx
mov    %cl,(%rsp)
mov    (%rsp),%rdx
and    $0xf,%edx
movzbl 0x4024b0(%rdx),%edx
mov    %dl,0x10(%rsp,%rax,1)
add    $0x1,%rax
cmp    $0x6,%rax
jne    40108b <phase_5+0x29>
```
又回到了这里，很显然，这块代码是一个循环体，它的行为是依次取出输入字符串的各位，然后将这个字符的后四位机器码解释为int类型，作为基址是4024b0的偏移量rax，并将这个地址上的数据依次写入离栈顶元素偏移量是0x10的地方，接着来看写完6个值后，程序做了什么？  
```asm
movb   $0x0,0x16(%rsp)
mov    $0x40245e,%esi
lea    0x10(%rsp),%rdi
call   401338 <strings_not_equal>
```
第一行代码将0写入栈顶偏移量为22的地方，它为什么这么做呢？因为在之前程序用循环向栈顶偏移16的位置写入了6个字符，因此，这行指令是为了给这六个字符构成的字符串加上一个字符串结束符。剩下的代码是一个参数调用，传递的参数分别是0x40245e与16+%rsp，从名称上看出函数的作用是比较两个字符串是否相等，因此，我们可以知道两个参数都是某两个字符串的地址值。而其中一个是由循环写入的，至于另一个字符串是什么？我们等会在看，先看返回后发生了什么？  
```asm
test   %eax,%eax
je     4010d9 <phase_5+0x77>
call   40143a <explode_bomb>
```
返回后，测试了返回值，若为0,则跳转到4010d9处，反之，则引爆炸弹。那么，4010d9处有什么呢？
```asm
mov    0x18(%rsp),%rax
xor    %fs:0x28,%rax
                                     
je     4010ee <phase_5+0x8c>
call   400b30 <__stack_chk_fail@plt>
add    $0x20,%rsp
pop    %rbx
ret
```
显然，这块代码是函数返回。  那么，phase_5的行为我们就能确定了，先读取六个字符，然后，用这六个字符机器码的后四位为偏移量从内存地址0x4024b0处取六个字符，写入栈顶偏移为0x10处，构成一个长度为6的字符串，最后，将其与地址是0x40245e的字符串比较，若相等，则，离开函数，反之，引爆炸弹。  
综上，要解题就要知道0x401338处的字符串和0x4024b0处的字符,从而推出使用的偏移量，再根据偏移量求出字符即可。  
最后，给出等价的C语言代码：
```c
char charset[16] = {读者需通过gdb查看};
char input[7];
char target0[7];
char *target1 = "读者需通过gdb查看";

scanf("%s",input);

for(int i = 0;i < 6;i ++) {
    int a = input[i] & 0xf;
    target0[i] = charset[a];
}
target0[6] = '\0';

if(strings_not_equal(target0,target1) != 0) {
    explode_bomb;
}

return 0;
```

[^1]:为什么只要一个参数传递呢？因为我们输入字符串是通过参数传递进入phase_1的，在寄存器%rdi中，因此另一个参数（也就是我们的输入）已经存放%rdi里了，因此，不需要再传递了，只需要传递答案字符串的地址给%rsi即可。  

[^2]:这里为什么还有一个小于0呢？因为指令`jbe    40103a <phase_4+0x2e>`是一个无符号数比较，若输入的第一个数小于0，则它的机器码会在0x10000000~0xffffffff之间，而这个范围的数在无符号的解释下都是极大的值。  

[start]: https://raw.githubusercontent.com/highdf/Picture/refs/heads/main/bomb/start.png
[phase_1-0]: https://raw.githubusercontent.com/highdf/Picture/refs/heads/main/bomb/phase_1-0.png
[phase_1-1]: https://raw.githubusercontent.com/highdf/Picture/refs/heads/main/bomb/phase_1-1.png
[phase_2-0]:https://raw.githubusercontent.com/highdf/Picture/refs/heads/main/bomb/phase_2-0.png
[phase_2-1]:https://raw.githubusercontent.com/highdf/Picture/refs/heads/main/bomb/phase_2-1.png
[phase_3-0]: https://raw.githubusercontent.com/highdf/Picture/refs/heads/main/bomb/phase_3-0.png
[phase_3-1]: https://raw.githubusercontent.com/highdf/Picture/refs/heads/main/bomb/phase_3-1.png
[phase_3-2]: https://raw.githubusercontent.com/highdf/Picture/refs/heads/main/bomb/phase_3-2.png
[phase_3-3]: https://raw.githubusercontent.com/highdf/Picture/refs/heads/main/bomb/phase_3-3.png
[phase_4-0]: https://raw.githubusercontent.com/highdf/Picture/refs/heads/main/bomb/phase_4-0.png
