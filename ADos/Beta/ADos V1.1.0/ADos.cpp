/**
 * @begindate:2021/3/10(貌似是)
**/

/*****************************************************
 *          A           FFFFFFFF AAAAAAAA            *
 *         AAA          FF      AFF      ANNNNNNNN   *
 *        AAAAA         FF    A   FFF     N          *
 *       AAA AAA        FF   A     FFF     ANNNNNNN  *
 *      AAA   AAA       FF    A   FFF     A      N   *
 *     AAAAAAAAAAA      FF      AFF      ANNNNNNN    *
 *    AAA       AAA     FF   FFF AAAAAAAA            *
 *   AAA         AAA    FFFFF                        *
******************************************************/

/* ********************************
  更新日志:
    2021/3/10 第一行源代码
    2021/7/6  ADos 1.0.0(Beta)
    2021/7/25 ADos 1.1.0(Beta)
      内容:1.根目录切换磁盘时更新
           2.界面优化
           3.文件系统优化
           4.内存对齐优化
* *********************************/

/*注意:color命令暂时停用!*/

//下面的注释屏蔽了一些现在暂时无用的类与函数和变量，就近的结构会展现出来
/**(Beta)**/
/*********************************************************************
 *              ADos 1.1.0 —————— AFAN Studio                        *
 *********************************************************************
 *                                                                   *
 *              Progect Name : ADos                                  *
 *                                                                   *
 *              File    Name : (能分文件的时候再说)                  *
 *                                                                   *
 *              Programmer   : gmx                                   *
 *                                                                   *
 *              Start   Date : 2021/3/10                             *
 *                                                                   *
 *              Last  Update : 2021/7/25                             *
 *                                                                   *
 *-------------------------------------------------------------------*
 * Function:                                                         *
 *   Sleep -- 休眠，与MFC中的Sleep的休眠时间相同                     *
 *   Printer -- 打印提示:                                            *
 *     Printer::Printer -- 类的构造函数，用于打印初始化提醒          *
 *     Printer::~Printer -- 类的析构函数，用于打印退出提醒           *
 *   CProgress -- ASG库中的用于打印进度条的类，未来会发布:           *
 *     CProgress::progress_bar -- 用于打印进度条或者磁盘状况条       *
 *   date -- 获取日期                                                *
 *   Logger -- 写日志文件:                                           *
 *     operator>> -- 重定义">>"运算符                                *
 *   GetUUID -- 生成UUID（全球唯一）                                 *
 *   PID -- 生成进程/线程PID                                         *
 *   MEMORY -- ADos系统内存管理:                                     *
 *     MEMORY::init -- 初始化内存                                    *
 *     MEMORY::toexit -- 释放内存                                    *
 *     MEMORY::GetThreadState -- 获取进程/线程状态                   *
 *     MEMORY::MEMORY -- 类的构造函数                                *
 *     MEMROY::~MEMORY -- 类的析构函数                               *
 *     MEMORY::CreateThread -- 创造进程/线程                         *
 *     MEMORY::ReleaseThread -- 释放进程/线程内存                    *
 *     MEMORY::RunThread -- 启动进程/线程                            *
 *     MEMORY::BlockThread -- 挂起进程/线程                          *
 *     MEMORY::KillThread -- 杀死进程/线程                           *
 *     MEMORY::showThread -- 显示正在运行、新建或挂起的进程/线程     *
 *     MEMORY::GetThreadMessage -- 获取进程/线程信息                 *
 *   FAT -- FAT文件系统:                                             *
 *     FAT::init -- 初始化磁盘                                       *
 *     FAT::getBlock -- 获取空磁盘                                   *
 *     FAT::addBlock -- 回收磁盘块                                   *
 *   FCB:                                                            *
 *     FCB::FCB -- 构造函数，用于初始化                              *
 *     FCB::~FCB -- 析构函数                                         *
 *     FCB::setFileAccess -- 设置文件保护方式/类型                   *
 *     FCB::getTime -- 获取时间                                      *
 *       File:                                                       *
 *         File::File -- 构造函数                                    *
 *         File::~File -- 析构函数                                   *
 *         File::addContent -- 添加文件                              *
 *         File::release -- 释放内存                                 *
 *         File::toString -- string数组转string                      *
 *       Folder:                                                     *
 *          Folder::addChild -- 添加子目录                           *
 *          Folder::Folder -- 构造函数                               *
 *          Folder::count -- 判断是否还有下一个文件夹                *
 *          Folder::find -- 查找文件夹                               *
 *          Folder::erase -- 擦除数据                                *
 *          Folder::size -- 获取文件夹大小                           *
 *   DiskManager -- 磁盘类:                                          *
 *     DiskManager::DiskWrite -- 创建磁盘文件                        *
 *     DiskManager::DiskMkdir -- 创建磁盘文件夹                      *
 *     DiskManager::DiskRmdir -- 删除磁盘文件夹                      *
 *     DiskManager::DiskCkdir -- 查找目录                            *
 *     DiskManager::DiskManagers -- 命令的实现，用于控制磁盘         *
 *     DiskManager::GetPath -- 获取路径（目录）                      *
 *     DiskManager::AllMEm -- 获取磁盘空间大小                       *
 *     DiskManager::usedMem -- 获取已用磁盘空间                      *
 *     DiskManager::run -- run命令实现（暂时保留）                   *
 *     DiskManager::SFM -- SFM命令实现                               *
 *     DiskManager::format -- 格式化实现                             *
 *     DiskManager::Mkdir -- Mkdir命令实现                           *
 *     DiskManager::Rmdir -- Rmdir命令实现                           *
 *     DiskManager::ls -- ls命令实现                                 *
 *     DiskManager::cd -- cd命令实现                                 *
 *     DiskManager::create -- create命令实现，用于创建文件           *
 *     DiskManager::open -- 打开文件                                 *
 *     DiskManager::close -- 关闭文件                                *
 *     DiskManager::write -- 写文件                                  *
 *     DiskManager::read -- 读文件                                   *
 *     DiskManager::rm -- 删除文件                                   *
 *     DiskManager::input -- 用于输入命令                            *
 *     DiskManager::DiskManager -- 构造函数，初始化磁盘              *
 *   Register -- 注册表类（保留）                                    *
 *   AES -- AES加密（CSDN上的代码，我也没搞懂……）                    *
 *   ASSOCEXE -- 更改扩展名默认文件:                                 *
 *     ASSOCEXE::getexten -- 获取文件扩展名                          *
 *     ASSOCEXE::ExtenNoneSpace -- 去除文件扩展名后的空格            *
 *     ASSOCEXE::FilepathNoneSpace -- 去除文件名后的空格             *
 *     ASSOCEXE::help -- 帮助函数                                    *
 *     ASSOCEXE::show -- 显示扩展名及其绑定文件                      *
 *     ASSOCEXE::show_s -- 显示现有扩展名                            *
 *     ASSOCEXE::binding -- 更改扩展名绑定文件                       *
 *     ASSOCEXE::split -- 判断格式是否正确(是否含有"&")              *
 *     ASSOCEXE::__init__ -- 初始化变量tmpExten与tmpFilenamePath     *
 *     ASSOCEXE::ASSOCEXE -- 构造函数，初始化变量extension           *
 *     ASSOCEXE::~ASSOCEXE -- 析构函数，释放变量空间                 *
 *     ASSOCEXE::ASSOC -- 接口，用于输入指令                         *
 *   CDEXE(CDK) -- 切换磁盘:                                         *
 *     CDEXE::help -- 帮助函数                                       *
 *     CDEXE::pos -- 查找子串位置                                    *
 *     CDEXE::changeMenu -- 更改磁盘目录                             *
 *     CDEXE::CD -- 接口，用于输入指令                               *
 *   COLOREXE --  更改颜色:                                          *
 *     COLOREXE::settxtcolor -- 设置前景颜色                         *
 *     COLOREXE::setcolor -- 设置颜色                                *
 *     COLOREXE::COLOR -- 接口，用于输入指令                         *
 *   COUNTEREXE -- 计算器:                                           *
 *     COUNTEREXE::level -- 判断运算符                               *
 *     COUNTEREXE::in_setCheck -- 检测是否有无用符号                 *
 *     COUNTEREXE::del_space -- 删除空格                             *
 *     COUNTEREXE::to_string -- 转string                             *
 *     COUNTEREXE::change -- 更改为后缀表达式（貌似是）              *
 *     COUNTEREXE::compute -- 计算                                   *
 *     COUNTEREXE::Judge_rectangle -- 判断是都有特殊符号             *
 *     COUNTEREXE::cal_rect_number -- 求三角函数                     *
 *     COUNTEREXE::Judge_factorial -- 判断是否为求阶乘               *
 *     COUNTEREXE::cal_factorial_number -- 求阶乘数字                *
 *     COUNTEREXE::cal_factorial -- 利用数组求阶乘                   *
 *     COUNTEREXE::COUNTER -- 接口，用于输入算式                     *
 *   CONFIGEXE -- 查看系统设置信息:                                  *
 *     CONFIGEXE::help -- 帮助函数                                   *
 *     CONFIGEXE::ac -- 输出用户设置                                 *
 *     CONFIGEXE::aboutcpu -- 输出cpu信息                            *
 *     CONFIGEXE::_adisk -- 输出磁盘信息                             *
 *     CONFIGEXE::_kb -- 输出键盘信息                                *
 *     CONFIGEXE::_ms -- 输出鼠标信息                                *
 *     CONFIGEXE::_usb -- 输出USB接口信息                            *
 *     CONFIGEXE::_a -- 命令转换并调用函数                           *
 *     CONFIGEXE::CONFIG -- 接口，用于输入指令                       *
 *   Date -- 用于输出日期                                            *
 *   parseHostAndPagePath -- 获取网页路径                            *
 *   GSCer -- 获取网页源代码                                         *
 *   GetIPer -- 获取网址IP                                           *
 *   HILLEXE -- Hill密码加密:                                        *
 *     HILLEXE::HILLEXE -- 构造函数，功能的实现                      *
 *   INSTALLEXE -- 下载软件或插件:                                   *
 *     INSTALLEXE::help -- 帮助函数                                  *
 *     INSTALLEXE::Delete -- 删除软件或插件                          *
 *     INSTALLEXE::showOrinstall -- 显示或下载软件或插件             *
 *     INSTALLEXE::INSTALL -- 接口，用于输入命令                     *
 *   MEMORYEXE -- 内存使用查看                                       *
 *     MEMORYEXE::init -- 初始化                                     *
 *     MEMORYEXE::show -- 显示情况                                   *
 *     MEMORYEXE::MEMORYEXE -- 构造函数                              *
 *     MEMORYEXE::~MEMORYEXE -- 析构函数，释放内存                   *
 *   VIRGINIAEXE -- Virginia密码加密                                 *
 *     VIRGINIAEXE::Init -- 初始化维吉尼亚方阵                       *
 *     VIRGINIAEXE::Encode -- 加密                                   *
 *     VIRGINIAEXE::Dncode -- 解密                                   *
 *     VIRGINIAEXE::VIRGINIA -- 接口，用于输入文字                   *
 *   copyright -- 版权声明                                           *
 *   help -- 主帮助函数                                              *
 *   findSubStringNUM -- 统计字符出现次数                            *
 *   SystemDkInit -- 系统磁盘初始化                                  *
 *   exits -- 退出函数（Ctrl+C）                                     *
 *   ADosMain -- 系统主函数                                          *
 *   main -- 程序主函数                                              *
 *********************************************************************/
#include <bits/stdc++.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <sys/timeb.h>
#include <stdio.h>
#include <setjmp.h>
#include <termio.h>

#define PACK_SIZE 32
//#define DEBUG
//#define MST
using namespace std;

/*define.h*/
#define CHINESE 0x00000000
#define ENGLISH 0x00000001
#define chooseprinter(l,r) do{printf("%s (1), %s (2)\n",l,r);}while(0);
#define CHOOSE(t,l,r) do{printf("%s\n",t);chooseprinter(l,r)}while(0);
#define CHECK(t,y,n) printf("%s请按(%s), 否则请按(%s)\n",t,y,n);
#define WRITEFILEOK(t) printf("[\033[92mOK\033[0m]%s\n",t);
#define DIV_ROUND_UP(n) ceil(n)
#ifdef DEBUG
    #define Log_Pt() cout<<__LINE__<<" "<<"successd"<<endl;
#endif
#ifdef MST
    #define GetSize(type) cout<<sizeof(type)<<endl;
#endif

#define TRUNCOLOR(number)   "\033["#number"m"
#define TXTNORMAL           cout<<TRUNCOLOR(0)
#define TXTBLACK            cout<<TRUNCOLOR(30)
#define TXTRED              cout<<TRUNCOLOR(31)
#define TXTGREEN            cout<<TRUNCOLOR(32)
#define TXTYELLOW           cout<<TRUNCOLOR(33)
#define TXTBLUE             cout<<TRUNCOLOR(34)
#define TXTPURPLE           cout<<TRUNCOLOR(35)
#define TXTBGREEN           cout<<TRUNCOLOR(36)
#define TXTWHITE            cout<<TRUNCOLOR(37)
#define TXTBRIGHTBLACK      cout<<TRUNCOLOR(90)
#define TXTBRIGHTRED        cout<<TRUNCOLOR(91)
#define TXTBRIGHTGREEN      cout<<TRUNCOLOR(92)
#define TXTBRIGHTYELLOW     cout<<TRUNCOLOR(93)
#define TXTBRIGHTBLUE       cout<<TRUNCOLOR(94)
#define TXTBRIGHTPURPLE     cout<<TRUNCOLOR(95)
#define TXTBRIGHTBGREEN     cout<<TRUNCOLOR(96)
#define TXTBRIGHTWHITE      cout<<TRUNCOLOR(97)

#define BKGNORMAL           cout<<TRUNCOLOR(0)
#define BKGBLACK            cout<<TRUNCOLOR(40)
#define BKGRED              cout<<TRUNCOLOR(41)
#define BKGGREEN            cout<<TRUNCOLOR(42)
#define BKGYELLOW           cout<<TRUNCOLOR(43)
#define BKGBLUE             cout<<TRUNCOLOR(44)
#define BKGPURPLE           cout<<TRUNCOLOR(45)
#define BKGBGREEN           cout<<TRUNCOLOR(46)
#define BKGWHITE            cout<<TRUNCOLOR(47)
#define BKGBRIGHTBLACK      cout<<TRUNCOLOR(100)
#define BKGBRIGHTRED        cout<<TRUNCOLOR(101)
#define BKGBRIGHTGREEN      cout<<TRUNCOLOR(102)
#define BKGBRIGHTYELLOW     cout<<TRUNCOLOR(103)
#define BKGBRIGHTBLUE       cout<<TRUNCOLOR(104)
#define BKGBRIGHTPURPLE     cout<<TRUNCOLOR(105)
#define BKGBRIGHTBGREEN     cout<<TRUNCOLOR(106)
#define BKGBRIGHTWHITE      cout<<TRUNCOLOR(107)

#define HAS_MEMBER(member)\
        template<typename T, typename... Args>class has_member_##member\
        {\
            private:\
                template<typename U> static auto Check(int)->decltype(std::declval<U>().member(std::declval<Args>()...), std::true_type());\
                template<typename U> static auto Check(...)->decltype(std::false_type());\
            public:\
                static const bool value = std::is_same<decltype(Check<T>(0)), std::true_type>::value;\
        };
        
#define using(__declare, __on_enter_expr, __on_leave_expr)\
            for(__declare, *_ptr = NULL;\
                _ptr++ == NULL ? \
                    ((__on_enter_expr), 1) : 0;\
                __on_leave_expr\
                )
                
#define PRINT_HELP(__on_enter_expr__, __on_leave_expr__) using(int a = 0, __on_enter_expr__, __on_leave_expr__)
#define print(text) printf("%s\n", text)
#define pterr(var, err) cout<<"\""<<var<<"\""<<err<<endl

#define SETCOLOR(var, _0_, _1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, _9_, _A_, _B_, _C_, _D_, _E_, _F_, num) switch(var)\
        {\
            case '0':\
                _0_;\
            break;\
            case '1':\
                _1_;\
            break;\
            case '2':\
                _2_;\
            break;\
            case '3':\
                _3_;\
            break;\
            case '4':\
                _4_;\
            break;\
            case '5':\
                _5_;\
            break;\
            case '6':\
                _6_;\
            break;\
            case '7':\
                _7_;\
            break;\
            case '8':\
                _8_;\
            break;\
            case '9':\
                _9_;\
            break;\
            case 'A':\
                _A_;\
            break;\
            case 'B':\
                _B_;\
            break;\
            case 'C':\
                _C_;\
            break;\
            case 'D':\
                _D_;\
            break;\
            case 'E':\
                _E_;\
            break;\
            case 'F':\
                _F_;\
            break;\
            default:\
                return num;\
            break;\
        }
#define BACKSPACE 127

#ifdef NULL
#undef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
#endif

#define MEMNULL 0

static const unsigned char sbox[256]={
    0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,
    0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76,
    0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,
    0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0,
    0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,
	0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15,
	0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,
	0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75,
	0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,
	0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,
	0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,
	0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf,
	0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,
	0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8,
	0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,
	0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2,
	0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,
	0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73,
	0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,
	0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb,
	0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,
	0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79,
	0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,
	0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08,
	0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,
	0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a,
	0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,
	0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e,
	0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,
	0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf,
	0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,
	0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16
};
static const unsigned char contrary_sbox[256]={
	0x52,0x09,0x6a,0xd5,0x30,0x36,0xa5,0x38,
	0xbf,0x40,0xa3,0x9e,0x81,0xf3,0xd7,0xfb,
	0x7c,0xe3,0x39,0x82,0x9b,0x2f,0xff,0x87,
	0x34,0x8e,0x43,0x44,0xc4,0xde,0xe9,0xcb,
	0x54,0x7b,0x94,0x32,0xa6,0xc2,0x23,0x3d,
	0xee,0x4c,0x95,0x0b,0x42,0xfa,0xc3,0x4e,//0x4e
	0x08,0x2e,0xa1,0x66,0x28,0xd9,0x24,0xb2,
	0x76,0x5b,0xa2,0x49,0x6d,0x8b,0xd1,0x25,
	0x72,0xf8,0xf6,0x64,0x86,0x68,0x98,0x16,
	0xd4,0xa4,0x5c,0xcc,0x5d,0x65,0xb6,0x92,
	0x6c,0x70,0x48,0x50,0xfd,0xed,0xb9,0xda,
	0x5e,0x15,0x46,0x57,0xa7,0x8d,0x9d,0x84,
	0x90,0xd8,0xab,0x00,0x8c,0xbc,0xd3,0x0a,
	0xf7,0xe4,0x58,0x05,0xb8,0xb3,0x45,0x06,
	0xd0,0x2c,0x1e,0x8f,0xca,0x3f,0x0f,0x02,
	0xc1,0xaf,0xbd,0x03,0x01,0x13,0x8a,0x6b,
	0x3a,0x91,0x11,0x41,0x4f,0x67,0xdc,0xea,
	0x97,0xf2,0xcf,0xce,0xf0,0xb4,0xe6,0x73,
	0x96,0xac,0x74,0x22,0xe7,0xad,0x35,0x85,
	0xe2,0xf9,0x37,0xe8,0x1c,0x75,0xdf,0x6e,
	0x47,0xf1,0x1a,0x71,0x1d,0x29,0xc5,0x89,
	0x6f,0xb7,0x62,0x0e,0xaa,0x18,0xbe,0x1b,
	0xfc,0x56,0x3e,0x4b,0xc6,0xd2,0x79,0x20,
	0x9a,0xdb,0xc0,0xfe,0x78,0xcd,0x5a,0xf4,
	0x1f,0xdd,0xa8,0x33,0x88,0x07,0xc7,0x31,
	0xb1,0x12,0x10,0x59,0x27,0x80,0xec,0x5f,
	0x60,0x51,0x7f,0xa9,0x19,0xb5,0x4a,0x0d,
	0x2d,0xe5,0x7a,0x9f,0x93,0xc9,0x9c,0xef,
	0xa0,0xe0,0x3b,0x4d,0xae,0x2a,0xf5,0xb0,
	0xc8,0xeb,0xbb,0x3c,0x83,0x53,0x99,0x61,
	0x17,0x2b,0x04,0x7e,0xba,0x77,0xd6,0x26,
	0xe1,0x69,0x14,0x63,0x55,0x21,0x0c,0x7d
};

static const unsigned char Rcon[10]={
	0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1b,0x36};

int loginif = 0;

pid_t pid;

jmp_buf env;

string out = "C:\\system\\>>># ";

bool Initflag = false;
bool InsOrDel = true;
bool virinstall = false;
bool hill = false;

/*#include <define.h>*/

struct Port{
    /*端口*/
    bool Port[1024] = {0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,
                               1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,
                               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                               0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,1,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,
                               0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0};
};

/* textcolor*/
enum textcolor
{
    BLACK = 30,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    BLUEGREEN,
    WHITE,
    BRIGHTBLACK = 90,
    BRIGHTRED,
    BRIGHTGREEN,
    BRIGHTYELLOW,
    BRIGHTBLUE,
    BRIGHTPURPLE,
    BRIGHTBLUEGREEN,
    BRIGHTWHITE,
    NORMAL = 0
};
/* textbkcolor*/
enum textbkcolor
{
    BKBLACK = 40,
    BKRED,
    BKGREEN,
    BKYELLOW,
    BKBLUE,
    BKPURPLE,
    BKBLUEGREEN,
    BKWHITE,
    BKBRIGHTBLACK = 100,
    BKBRIGHTRED,
    BKBRIGHTGREEN,
    BKBRIGHTYELLOW,
    BKBRIGHTBLUE,
    BKNORMAL = 0
};
void Sleep(long int times)
{
    struct timeval delay;
    delay.tv_sec = 0;
    delay.tv_usec = times * 1000;
    select(0, NULL, NULL, NULL, &delay);
}
//输出提示用
class Printer{
    public:
    Printer(){
        cout<<"初始化系统中，请稍等... 建议宽度:全屏（进入网址https://code.xueersi.com/ide/code/15768230后拉满屏）"<<endl;
    }
    ~Printer(){
        cout<<"释放内存中..."<<endl;
    }
};
Printer printer;

class ADosClass
{
    public:
    void CreateUserFile()
    {
        filename = "user" + username + ".h";
        cout<<filename<<endl;
        int fd = creat(filename.c_str(), O_CREAT | O_EXCL);
        if(fd == -1)
        {
            cout<<"error";
        }
        cout<<fd;
        close(fd);
    }
    int GetSystemLanguages() { return language; }
    protected:
    int memory = 4;//GB
    int kernel = 2;
    const char* cpuname = "ADosCpu";//就叫这个吧
    unsigned int language = CHINESE;
    string username, filename;
    string userpassword;
    int DKmemory;
};

struct SystemSet
{
    unsigned int languages/*GetSystemLanguages()*/;
    textcolor txtcokor;
    textbkcolor txtbkcolor;
    int DKmem;
    int Mainmem, Othermem;
    int ExDkNumber;
    string ExDk1Name, ExDk2Name;
    int ExDk1mem, ExDk2mem;
    int used1, used2;
    int usemain;
    bool hasping;
};
const int memory = 8 * 1088;
const int kernel = 2;
const char* cpuname = "ADosCpu";
const char* ip = "172.169.1.108";
struct softandhard_log//游客设置用
{
    bool ping;
    bool install;
    bool gsc;//Get source code
    bool Getip;
    bool ipconfig;
    bool TextEncryption;
    bool FileEncryption;
    bool Virginia;
    bool Hill;
    bool Inet;//翻译
};
struct EXTENSION//增加的时候不要忘记修改ASSOC的show函数、show_b函数和show_s函数
{
    string _7z   = "__null";
    string _adexe = "ADos内核";
    string _adll  = "dos.adexe";
    string _C     = "BOOK.adexe";
    string _cpp   = "BOOK.adexe";
    string _h     = "BOOK.adexe";
    string _log   = "BOOK.adexe";
    string _me    = "BOOK.adexe";
    string _txt   = "BOOK.adexe";
    string _txtmd = "BOOK.adexe";
    string _tz    = "__null";
    string _rar   = "__null";
    string _zip   = "__null";
};
softandhard_log logn = {
    .ping = true,
    .install = true,
    .gsc = true,
    .Getip = true,
    .ipconfig = true,
    .TextEncryption = true,
    .FileEncryption = false,
    .Virginia = false,
    .Hill = false,
    .Inet = false
};
SystemSet sysset = {
    .languages = CHINESE,
    .txtcokor = NORMAL,
    .txtbkcolor = BKNORMAL,
    .DKmem = 512,
    .used1 = 0, 
    .used2 = 0,
    .usemain = 0
};
struct forDisk
{
    SystemSet *syset = &sysset;
    int Mainmem = syset->Mainmem, Othermem = syset->Othermem;
    int ExDkNumber = syset->ExDkNumber;
    string ExDk1Name = syset->ExDk1Name, ExDk2Name = syset->ExDk2Name;
    int ExDk1mem = syset->ExDk1mem, ExDk2mem = syset->ExDk2mem;
    int MainmemSurplus = syset->Mainmem - syset->usemain - 5;//运算法则先->再-
    int ExDk1memSurplus = syset->ExDk1mem - syset->used1;
    int ExDk2memSurplus = syset->ExDk2mem - syset->used2;
};
//对所有硬件的描述

class CProgress:public ADosClass
{
    private:
    const char *ponit[6]={" ", "▏", "▎", "▍", "▊", "█"};
    public:
    void progress_bar(int per)
    {
    	int i=0;
    	int num0=0;
     
    	printf("\r  [");
     
    	num0  = (100-per)/5;
     
    	i = per;
    	while(i>5)
    	{
    		printf("%s", ponit[5]);
    		i -= 5;
    	}
     
    	if(i)
    	{
    		printf("%s", ponit[i]);
    	}
     
    	for(i=0;i<num0;i++)
    	{
    		printf("%s", ponit[0]);
    	}
     
    	printf(" ] %2d%%", per);
     
    	if(per == 100)
    	{
    	    Sleep(200);
    		printf("\n\033[92mdone\033[0m");
    	}
    }
    void progress(int all, int per)
    {
    	int i=0;
    	int num0=0;
     
    	printf("\r  [\033[92m");
     
    	num0  = (all-per)/5;
     
    	i = per;
    	while(i>5)
    	{
    		printf("%s", ponit[5]);
    		i -= 5;
    	}
     
    	if(i)
    	{
    		printf("%s", ponit[i]);
    	}
     
    	for(i=0;i<num0;i++)
    	{
    		printf("%s", ponit[0]);
    	}
     
    	printf("\033[0m ] %2d%%\n", per);
     
    	if(per == all)
    	{
    		printf("\n\033[31m磁盘已满\033[0m\n");
    	}
    }
};

string date(){
    time_t t;
    tm *local;
    char buf[128] = {0};
    t = time(NULL);
    local = localtime(&t);
    strftime(buf, 64, "%Y-%m-%d %H:%M:%S", local);
    return buf;
}

class Logger{
    public:
    const Logger &operator>>(const char* cstr) const;
};

Logger tmper;//写日志文件用

//内存
//Memory.h
//生成UUID
static string GetUUID(){
    static random_device rd;
    static uniform_int_distribution<uint16_t> dist(0ULL, 0xFFFFULL);
    uint64_t ab = dist(rd);
    uint64_t cd = dist(rd);
    uint32_t a, b, c, d;
    stringstream ss;
    ab = (ab & 0xFFFFFFFFFFFF0FFFULL) | 0x0000000000004000ULL;
    cd = (cd & 0x3FFFFFFFFFFFFFFFULL) | 0x8000000000000000ULL;
    a = (ab >> 32U);
    b = (ab & 0xFFFFFFFFU);
    c = (cd >> 32U);
    d = (cd & 0xFFFFFFFFU);
    ss << hex << nouppercase << setfill('0');
    ss << setw(8) << (a) << '-';
    ss << setw(4) << (b >> 16U) << '-';
    ss << setw(4) << (b & 0xFFFFU) << '-';
    ss << setw(4) << (c >> 16U) << '-';
    ss << setw(4) << (c & 0xFFFFU);
    ss << setw(8) << d;
    return ss.str();
}
//生成PID
static int PID(int mem){
    static random_device rd;
    static uniform_int_distribution<uint16_t> dist(0ULL, 0xFFFFULL);
    uint64_t ab = dist(rd);
    unsigned int seedVal;
    struct timeb timeBuf;
    ftime(&timeBuf);
    seedVal = ((((unsigned int)timeBuf.time& 0xFFFF) + 
            (unsigned int)timeBuf.millitm)^(unsigned int)timeBuf.millitm);
    srand((unsigned int)seedVal);
    int pidtmp = rand() % 2400 + mem;
    srand(pidtmp + ab);
    int pidrand = rand() % (8 * 1088);
    return pidrand;
}

#define NEW      0x00000001
#define RUNNABLE 0x00000002
#define RUNNING  0x00000004
#define BLOCKED  0x00000008
#define DEAD     0x00000010
#define CANNOT   0x00000020
#define CAN      0x00000040
#define SYSTEM   0x00000080
#define NONESYS  0x00000100
vector<bool> Memory(8 * 1088, false);
vector<string> UUIDMem(8 * 1088, "");
vector<string> Name(8 * 1088, "");
vector<bool> VirtMem;
vector<string> VirtName;
vector<string> VirtUUID;
#pragma pack(push)
#pragma pack(4)
struct MemMessage{
    string memName;
    string FileName;
    double cpu;
    int Usrmem;
    int VirtMem;
    int addr;
    int Virtaddr;
    int PID;
    unsigned int flag;//can close?is system? and state
    string Text;
    string copyright;
};
#pragma pack(pop)
MemMessage _NullMsg;
vector<MemMessage> SysMemMsg(75, _NullMsg);
class MEMORY{
    public:
    int forHardwear;
    private:
    void init(){
        string UUIDToThread;
        for(int i = 0; i <= 8 * 1088; i ++){
            UUIDToThread = GetUUID();
            UUIDMem.insert(UUIDMem.begin() + i, UUIDToThread);
        }
        WRITEFILEOK("内存编号完成");
        for(int i = 0; i <= 1440; i ++){
            Memory.insert(Memory.begin() + i, true);
        }
        for(int i = 0; i <= 1440; i ++){
            Name.insert(Name.begin() + i, "ADos");
        }
        WRITEFILEOK("系统内存初始化完成");
        int virtmem = Memory.capacity() - Memory.size();// 虚拟内存=vector里可存总内存-设定的可存内存
        //cout<<virtmem<<endl;
        forHardwear = virtmem;
        VirtMem.assign(virtmem, false);
        VirtUUID.assign(virtmem, "(__null)");
        for(int i = 0; i <= virtmem; i ++){
            UUIDToThread = GetUUID();
            VirtUUID.insert(VirtUUID.begin() + i, UUIDToThread);
/*#ifdef DEBUG
    Log_Pt();
#endif*/
        }
        for(int i = 0; i <= 960; i ++){
            VirtMem.insert(VirtMem.begin() + i, true);
        }
        for(int i = 0; i <= 960; i ++){
            VirtName.insert(VirtName.begin() + i, "ADos");
        }
    #if __cplusplus >= 201103L
        VirtMem.shrink_to_fit();//把可存总内存调整到设定的可存内存
        Memory.shrink_to_fit();
        UUIDMem.shrink_to_fit();
        Name.shrink_to_fit();
        VirtName.shrink_to_fit();
        VirtUUID.shrink_to_fit();
    #endif
        MemMessage MemMsg = {
            .memName = "ADos",
            .FileName = "ADos内核",
            .cpu = 2400.0 / (8 * 1088),
            .addr = 0,
            .Virtaddr = 0,
            .Usrmem = (int)ceil(2400 * 0.6),
            .VirtMem = (int)ceil(2400 * 0.4),
            .PID = PID(2400),
            .Text = "ADos内核",
            .copyright = "AFAN Studio",
            .flag = CANNOT | SYSTEM | RUNNING
        };
        SysMemMsg.push_back(MemMsg);
    }
    void toexit(){
        Memory.clear();
        UUIDMem.clear();
        Name.clear();
        VirtMem.clear();
        SysMemMsg.clear();
    #if __cplusplus >= 201103L
        Memory.shrink_to_fit();
        UUIDMem.shrink_to_fit();
        Name.shrink_to_fit();
        VirtMem.shrink_to_fit();
        SysMemMsg.shrink_to_fit();
    #endif
    }
    const char* GetThreadState(int addr, string ThreadName){
        if(addr > (Memory.capacity() - 2400)) return NULL;
        if(Name[addr] != ThreadName || Name[addr - 1] == ThreadName) return NULL;
        if(addr <= 2400) return NULL;
        MemMessage msgtmp;
        unsigned int flagint;
        string returnvar = "(_null)";
        for(int i = 0; i <= SysMemMsg.size(); i ++){
            msgtmp = SysMemMsg[i];
            if(msgtmp.memName == ThreadName){
                flagint = SysMemMsg[i].flag;
            }
        }
        for (int i = 0; i <= 9; i++)
    	{
    		bool hasFlag = (flagint >> i) & 1;
    		if (hasFlag)
    		{
    		    cout<<i<<endl;
    		    switch(i)
                {
                    case 0:
                        returnvar = "新进程";
                    break;
                    case 1:
                        returnvar = "可运行";
                    break;
                    case 2:
                        returnvar = "运行中";
                    break;
                    case 3:
                        returnvar = "挂起中";
                    break;
                    case 4:
                        returnvar = "已结束";
                    break;
                    case 5:
                        returnvar = returnvar + "|不能结束";
                    break;
                    case 6:
                        returnvar = returnvar + "|可以结束";
                    break;
                    case 7:
                        returnvar = returnvar + "|系统进程";
                    break;
                    case 8:
                        returnvar = returnvar + "|非系统进程";
                    break;
                    default:
                        puts("error");
                        cout<<i;
                        break;
                }
    		}
    	}
        return returnvar.c_str();
    }
    //tuple<vector<bool>, vector<string>, vector<string>> MemMonitor{Memory, UUIDMem, Name};
    public:
    MEMORY(){
        init();
        WRITEFILEOK("内存初始化完成");
    }
    ~MEMORY(){
       toexit(); 
    }
#ifdef DEBUG
    void test(int addr, string ThreadName){
        GetThreadState(addr, ThreadName);
    }
#endif
    int CreateThread(string name, string filename, int mem/*byte*/,
                    string text = "(_null)", 
                    string copyright = "(_null)", 
                    unsigned int flag = CAN | NONESYS | NEW){
        if(mem > (Memory.capacity() - 1440)){
            return -1;
        }
        int addr = find(Memory.begin(), Memory.end(), false) - Memory.begin();
        int Virtaddr = find(VirtMem.begin(), VirtMem.end(), false) - VirtMem.begin();
        if(mem > Memory.capacity() - addr){
            return -1;
        }
        for(int i = addr; i <= (int)ceil(addr + mem * 0.6); i ++){
            Memory.insert(Memory.begin() + i, true);
        }
        for(int i = addr; i <= (int)ceil(addr + mem * 0.6); i ++){
            Name.insert(Name.begin() + i, name);
        }
        for(int i = Virtaddr; i <= (int)ceil(Virtaddr + mem * 0.4); i ++){
            VirtMem.insert(VirtMem.begin() + i, true);
        }
        for(int i = Virtaddr; i <= (int)ceil(Virtaddr + mem * 0.4); i ++){
            VirtName.insert(VirtName.begin() + i, name);
        }
        MemMessage MemMsg = {
            .memName = name,
            .FileName = filename,
            .cpu = (double)(mem / (8.0 * 1088.0)),
            .addr = addr,
            .Virtaddr = Virtaddr,
            .Usrmem = (int)ceil(mem * 0.6),
            .VirtMem = (int)ceil(mem * 0.4),
            .PID = PID(mem),
            .Text = text,
            .copyright = copyright,
            .flag = flag
        };
        SysMemMsg.push_back(MemMsg);
        return addr;
    }
    int ReleaseThread(int addr, string ThreadName){
        if(addr > (Memory.capacity() - 1440)) return -1;
        if(Name[addr] != ThreadName || Name[addr - 1] == ThreadName) return -1;
        if(addr <= 1440) return -1;
        int Virtaddr;
        for(int i = 0; i <= VirtName.size(); i ++){
            if(ThreadName == VirtName[i]){
                Virtaddr = i;
                break;
            }
        }
        MemMessage msgtmp;
        for(int i = addr; i <= Name.capacity() && Name[i] == ThreadName; i ++){
            Memory[i] = false;
            Name[i] = "";
        }
        for(int i = Virtaddr; i <= VirtName.capacity() && VirtName[i] == ThreadName; i ++){
            VirtMem[i] = false;
            VirtName[i] = "";
        }
        for(vector<MemMessage>::reverse_iterator it = SysMemMsg.rbegin(); it != SysMemMsg.rend(); ++it){
            msgtmp = *it;
            if(msgtmp.memName == ThreadName){
                *it = _NullMsg;
            }
        }
#ifdef DEBUG
        Log_Pt();
#endif
        return 0;
    }
    int RunThread(int addr, string ThreadName){
        if(addr > (Memory.capacity() - 1440)) return -1;
        if(Name[addr] != ThreadName || Name[addr - 1] == ThreadName) return -1;
        if(addr <= 1440) return -1;
        MemMessage msgtmp;
        for(vector<MemMessage>::reverse_iterator it = SysMemMsg.rbegin(); it != SysMemMsg.rend(); ++it){
            msgtmp = *it;
            if(msgtmp.memName == ThreadName){
                it->flag = it->flag & ~(NEW);
                it->flag = it->flag | RUNNING;
                break;
            }
        }
        return 0;
    }
    int BlockThread(int addr, string ThreadName){
        if(addr > (Memory.capacity() - 1440)) return -1;
        if(Name[addr] != ThreadName || Name[addr - 1] == ThreadName) return -1;
        if(addr <= 1440) return -1;
        MemMessage msgtmp;
        for(vector<MemMessage>::reverse_iterator it = SysMemMsg.rbegin(); it != SysMemMsg.rend(); ++it){
            msgtmp = *it;
            if(msgtmp.memName == ThreadName){
                it->flag = it->flag & ~(RUNNING);
                it->flag = it->flag | BLOCKED;
                break;
            }
        }
        return 0;
    }
    int KillThread(int addr, string ThreadName){
        if(addr > (Memory.capacity() - 1440)) return -1;
        if(Name[addr] != ThreadName || Name[addr - 1] == ThreadName) return -1;
        if(addr <= 1440) return -1;
        MemMessage msgtmp;
        for(vector<MemMessage>::reverse_iterator it = SysMemMsg.rbegin(); it != SysMemMsg.rend(); ++it){
            msgtmp = *it;
            if(msgtmp.memName == ThreadName){
                it->flag = it->flag & ~(RUNNING);
                it->flag = it->flag | DEAD;
            }
        }
        return this->ReleaseThread(addr, ThreadName);
    }
    void showThread(){
        MemMessage msgtmp;
        cout<<setfill(' ')<<"进程名称"<<"     "<<"文件名称"<<"     "<<"cpu使用率"<<"     "<<"使用内存"<<"   "<<"虚拟内存"<<"   "<<"PID"<<"   "<<"描述"<<"     "<<"版权"<<"     "<<"起始地址"<<endl;
#define _ msgtmp
        for(vector<MemMessage>::reverse_iterator it = SysMemMsg.rbegin(); it != SysMemMsg.rend(); ++it){
            msgtmp = *it;
            if(msgtmp.memName != _NullMsg.memName){
                cout<<_.memName<<"     "<<_.FileName<<"     "<<_.cpu<<"     "<<_.Usrmem<<"   "<<_.VirtMem<<"   "<<_.PID<<"   "<<_.Text<<"     "<<_.copyright<<"     "<<_.addr<<endl;
                continue;
            }
        }
#undef _
    }
    MemMessage GetThreadMessage(int addr, string ThreadName){
        MemMessage msgtmp;
        if(addr > (Memory.capacity() - 1440)) return msgtmp;
        if(Name[addr] != ThreadName || Name[addr - 1] == ThreadName) return msgtmp;
        if(addr <= 1440) return msgtmp;
        for(vector<MemMessage>::iterator it = SysMemMsg.begin(); it != SysMemMsg.end(); it ++){
           msgtmp = *it;
            if(msgtmp.memName == ThreadName){
                break;
            }
        }
        return msgtmp;
    }
};

//初始化内存
MEMORY Mem;

#pragma pack(push)
#pragma pack(4)
class AllHard : 
            protected ADosClass
{
    private:
    struct AboutDisk{
        string name;
        string showName;
        string shortName;
        string longName;
        string PartType; //分区类型
        string state;
        string UUID;
        string divName;
        int DiskMem;
        int protectMem; //受保护空间
        string mker; //供应商
        string FilePath; //驱动程序地址
        string date; //初始化时间
        bool issys; //是否为系统必须
        bool isopen; //是否为启动盘
        bool canDel; //是否可删除
        string text; //备注
    };
    struct cpu{
        string cpuname;
        string showname;
        string longName;
        string shortName;
        string divname; //驱动名称
        string UUID;
        int cpumem;
        int Virtmem; //虚拟内存
        int hardwareUse; //硬件所需
        int protect; //受保护空间
        int canuse; //用户与程序可使用的空间
        int cpuKernelNum;
        int ThreadMax;
        string mker; //供应商
        string FilePath; //驱动程序地址
        string date; //初始化时间
        bool issys; //是否为系统必须
        bool canDel; //是否可删除
        string text; //备注
    };
    struct Disk{
        int DiskNum;
        int AllMem;
        AboutDisk disk1;
        AboutDisk disk2;
        AboutDisk disk3;
        AboutDisk disk4;
    #if DiskNum > 4
        vector<AboutDisk> otherdisk;
    #endif
    };
    struct USB{
        string USBname;
        string showname;
        string longName;
        string shortName;
        string divname; //驱动名称
        string USBmemLow; //内存范围下限
        string USBmemHigh; //内存范围上限
        string UUID;
        string mker; //供应商
        string FilePath; //驱动程序地址
        string date; //初始化时间
        bool issys; //是否为系统必须
        bool canDel; //是否可删除
        string text; //备注
    };
    struct Keyboard{
        string kbname;
        string showname;
        string longName;
        string shortName;
        string divname; //驱动名称
        string UUID;
        string mker; //供应商
        string FilePath; //驱动程序地址
        string date; //初始化时间
        bool issys; //是否为系统必须
        bool canDel; //是否可删除
        bool iss; //包括特殊符号
        string text; //备注
    };
    struct Mouse{
        string msname;
        string showname;
        string longName;
        string shortName;
        string divname; //驱动名称
        string UUID;
        string mker; //供应商
        string FilePath; //驱动程序地址
        string date; //初始化时间
        bool issys; //是否为系统必须
        bool canDel; //是否可删除
        string text; //备注
    };
    struct AboutComputer{
        string ip;
        string UUID;
        string showname;
        string username;
    #if login != 1
        string password; //加密后
    #endif
        string Aboutcopyright;
        string Version;
        string text; //描述
    };
    public:
    cpu* cpus = new cpu;
    Disk* disk = new Disk;
    USB* usb = new USB;
    Keyboard* kb = new Keyboard;
    Mouse* ms = new Mouse;
    AboutComputer* ac = new AboutComputer;
    AllHard(){
        //cpu信息初始化
        cpus->cpuname = cpuname;
        cpus->showname = "cpu";
        cpus->longName = "处理器";
        cpus->shortName = "cpu";
        cpus->divname = "ADosCpu.sys";
        cpus->UUID = GetUUID();
        cpus->cpumem = 8 * 1088;
        cpus->Virtmem = Mem.forHardwear;
        cpus->hardwareUse = 8 * 5;
        cpus->protect = 8 * 5;
        cpus->canuse = cpus->cpumem - cpus->hardwareUse - cpus->protect;
        cpus->cpuKernelNum = 2;
        cpus->ThreadMax = 128;
        cpus->mker = "AFAN Studio";
        cpus->FilePath = "C:\\system\\Program\\sysProgram\\dirve\\cpu\\ADosCpu.sys";
        cpus->date = date();
        cpus->issys = true;
        cpus->canDel = false;
        cpus->text = "central processing unit";
        WRITEFILEOK("cpu初始化完成");
        //硬盘初始化
        disk->DiskNum = 4;
        disk->AllMem = 8 * 1024 * 1024; //1MB
        //C:
        disk->disk1.name = "ADosDisk";
        disk->disk1.showName = "C:";
        disk->disk1.longName = "C盘";
        disk->disk1.shortName = "DiskC";
        disk->disk1.PartType = "FAT";
        disk->disk1.state = "良好";
        disk->disk1.UUID = GetUUID();
        disk->disk1.divName = "ADosDiskC.sys";
        disk->disk1.DiskMem = 8 * 1024 * 256;//256KB
        disk->disk1.protectMem = 8 * 1024; //1KB
        disk->disk1.mker = "AFAN Studio";
        disk->disk1.FilePath = "C:\\system\\Program\\sysProgram\\dirve\\disk\\ADosDiskC.sys";
        disk->disk1.date = date();
        disk->disk1.issys = true;
        disk->disk1.isopen = true;
        disk->disk1.canDel = false;
        disk->disk1.text = "\"C:\"盘为主盘，不可格式化或者删除";
        WRITEFILEOK("C盘初始化完成");
        //E:
        disk->disk2.name = "ADosDisk";
        disk->disk2.showName = "E:";
        disk->disk2.longName = "E盘";
        disk->disk2.shortName = "DiskE";
        disk->disk2.PartType = "FAT";
        disk->disk2.state = "良好";
        disk->disk2.UUID = GetUUID();
        disk->disk2.divName = "ADosDiskE.sys";
        disk->disk2.DiskMem = 8 * 1024 * 256;//256KB
        disk->disk2.protectMem = 8 * 1024; //1KB
        disk->disk2.mker = "AFAN Studio";
        disk->disk2.FilePath = "C:\\system\\Program\\sysProgram\\dirve\\disk\\ADosDiskE.sys";
        disk->disk2.date = date();
        disk->disk2.issys = true;
        disk->disk2.isopen = false;
        disk->disk2.canDel = true;
        disk->disk2.text = "\"E:\"盘为扩展盘";
        WRITEFILEOK("E盘初始化完成");
        //F:
        disk->disk3.name = "ADosDisk";
        disk->disk3.showName = "F:";
        disk->disk3.longName = "F盘";
        disk->disk3.shortName = "DiskF";
        disk->disk3.PartType = "FAT";
        disk->disk3.state = "良好";
        disk->disk3.UUID = GetUUID();
        disk->disk3.divName = "ADosDiskF.sys";
        disk->disk3.DiskMem = 8 * 1024 * 256;//256KB
        disk->disk3.protectMem = 8 * 1024; //1KB
        disk->disk3.mker = "AFAN Studio";
        disk->disk3.FilePath = "C:\\system\\Program\\sysProgram\\dirve\\disk\\ADosDiskF.sys";
        disk->disk3.date = date();
        disk->disk3.issys = true;
        disk->disk3.isopen = false;
        disk->disk3.canDel = true;
        disk->disk3.text = "\"F:\"盘为扩展盘";
        WRITEFILEOK("F盘初始化完成");
        //T:
        disk->disk4.name = "ADosDisk";
        disk->disk4.showName = "T:";
        disk->disk4.longName = "T盘";
        disk->disk4.shortName = "DiskT";
        disk->disk4.PartType = "FAT";
        disk->disk4.state = "良好";
        disk->disk4.UUID = GetUUID();
        disk->disk4.divName = "ADosDiskT.sys";
        disk->disk4.DiskMem = 8 * 1024 * 256;//256KB
        disk->disk4.protectMem = 8 * 1024; //1KB
        disk->disk4.mker = "AFAN Studio";
        disk->disk4.FilePath = "C:\\system\\Program\\sysProgram\\dirve\\disk\\ADosDiskT.sys";
        disk->disk4.date = date();
        disk->disk4.issys = true;
        disk->disk4.isopen = false;
        disk->disk4.canDel = false;
        disk->disk4.text = "\"T:\"盘为日志文件储存盘，不可删除";
        WRITEFILEOK("T盘初始化完成");
        //USB初始化
        usb->USBname = "ADosUSB";
        usb->showname = "USB";
        usb->longName = "USB接口";
        usb->shortName = "USB";
        usb->divname = "ADosUSB.sys";
        usb->USBmemLow = UUIDMem[100];
        usb->USBmemHigh = UUIDMem[120];
        usb->UUID = GetUUID();
        usb->mker = "AFAN Studio";
        usb->FilePath = "C:\\system\\Program\\sysProgram\\dirve\\usb\\ADosUSB.sys";
        usb->date = date();
        usb->issys = true;
        usb->canDel = false;
        usb->text = "USB接口";
        WRITEFILEOK("USB初始化完成");
        //键盘初始化
        kb->kbname = "ADosKeyboard";
        kb->showname = "KeyBoard";
        kb->longName = "键盘";
        kb->shortName = "KB";
        kb->divname = "ADosKB.sys";
        kb->UUID = GetUUID();
        kb->mker = "AFAN Studio";
        kb->FilePath = "C:\\system\\Program\\sysProgram\\dirve\\KeyBoard\\ADosKB.sys";
        kb->date = date();
        kb->issys = true;
        kb->canDel = false;
        kb->text = "键盘";
        WRITEFILEOK("键盘初始化完成");
        //鼠标初始化
        ms->msname = "ADosMouse";
        ms->showname = "Mouse";
        ms->longName = "鼠标";
        ms->shortName = "MS";
        ms->divname = "ADosMS.sys";
        ms->UUID = GetUUID();
        ms->mker = "AFAN Studio";
        ms->FilePath = "C:\\system\\Program\\sysProgram\\dirve\\Mouse\\ADosMs.sys";
        ms->date = date();
        ms->issys = true;
        ms->canDel = false;
        ms->text = "鼠标";
        WRITEFILEOK("鼠标初始化完成");
        //用户初始化
        ac->ip = ip;
        ac->UUID = GetUUID();
        //ac->showname = username;
        //ac->username = username;
        ac->Aboutcopyright = "AFAN Studio";
        ac->Version = "1.0.0";
        ac->text = "(__null)";
        WRITEFILEOK("硬件初始化完成");
        WRITEFILEOK("用户初始化完成");
    }
    ~AllHard(){
        delete cpus;
        delete disk;
        delete usb;
        delete kb;
        delete ms;
        delete ac;
    }
};
#pragma pack(pop)

//初始化硬件
AllHard hard;

//File-OS 来源:lewisbyte(github)
//ps:文件系统这一方面我是真的菜，这一段文件系统是从GitHub上扒下来的，有一点儿改动
/*Access.h*/
enum Access{
    ReadOnly = 0,
    Write = 1,
    Executable = 2, //可执行
    System = 3 //系统
};
/*FileType.h*/
enum FileType{
    FOLDER, //文件夹
    DOCUMENT//文档
};
/*FAT.h, FAT.cpp*/

const static int BLOCK_SIZE = 4096 / sizeof(bool);

class FAT{
public:
    stack<int> freeDiskBlock;
    stack<int> fullDiskBlock;
    //初始化
    void init(string blocks[]){
        for(int i = 0; i < BLOCK_SIZE; i ++){
            this->freeDiskBlock.push(i);
            blocks[i].clear();
        }
    }
    //获取空磁盘
    int getBlock(){
        if(this->freeDiskBlock.size() > 0){
            int blockId = this->freeDiskBlock.top();
            this->freeDiskBlock.pop();
            this->fullDiskBlock.push(blockId);
            return blockId;
        }
        return -1;
    }
    //回收磁盘块
    void addBlock(int block, string blocks[]){
        this->freeDiskBlock.push(block);
        blocks[block].clear();
    }
};

/*FCB.h, FCB.cpp*/

const int N = 4096;

class FCB{
public:
    string name;//文件名：      文件名.扩展名
    int nodeId;//文件标识：     操作系统管理文件的唯一标识
    FileType type;//文件类型：  由扩展名给出
    string path;//文件位置：    文件所存放设备的具体位置
    int size;//文件大小：       以字节或块为单位的文件长度
    Access access;//文件保护方式
    string modifyDate;//文件创建或修改的日期
    FCB *index[N];//索引表
    FCB *father;//父节点
    
    FCB(){
        this->access = Write;
        this->modifyDate = getTime();
        this->size = N;
    }
    ~FCB(){
        NULL;
    }
    void setFileAccess(Access access){
        this->access = access;
    }
    string getTime(){
        time_t t = time(0);
        char tmp[64];
        strftime(tmp, sizeof(tmp), "%Y/%m/%d %X", localtime(&t));
        return tmp;
    }
};
/*File.h, File.cpp*/
class File: public FCB{
public:
    File(){
        
    }
    File(string _name, FileType _type, FAT &fat){
        this->name = _name;
        this->type = _type;
        this->size = 0;
        this->index[size] = fat.getBlock();
    }
    File(string _name, FileType _type, FAT &fat, Access access){
        this->name = _name;
        this->type = _type;
        this->size = 0;
        this->index[size] = fat.getBlock();
        this->access = access;
    }
    ~File(){
        
    }
    //序列化
    void Serialization(){
        //__null，我也不知道为啥，可能暂留
    }
    //反序列化
    void Deserialization(){
        //__null，同上 
    }
    
    bool addContent(const char* content, string blocks[], FAT &fat){
        int len = strlen(content);
        for(int i = 0; i < len; i ++){
            if(blocks[index[size]].length() <= N){
                blocks[index[size]] += content[i];
            }else{
                index[++size] = fat.getBlock();
                blocks[index[size]] += content[i];
            }
        }
        this->modifyDate = this->getTime();
        return false;
    }
    
    void release(FAT &fat, string *blocks){
        for(int i = 0; i < this->size; i++){
            fat.addBlock(index[i], blocks);
        }
    }
    
    string toString(string blocks[]){
        string s;
        for(int i = 0; i <= this->size; i++){
            s += blocks[index[i]];
        }
        return s;
    }
    
    //文件索引
    int index[N];
    //上一级文件夹
    FCB *father;
};

/*Folder.h, Folder.cpp*/

class Folder : public FCB{
public:
    vector<FCB *> child;
    
    void addChild(FCB *file){
        this->child.push_back(file);
    }
    Folder(string _name, FileType _type){
        this->name = _name;
        this->type = _type;
    }
    bool count(FCB *file){
        int size = child.size();
        for(int i = 0; i < size; i++){
            if(child[i]->type == file->type && child[i]->name == file->name){
                return true;
            }
        }
        return false;
    }
    
    FCB *find(FCB *file){
        int size = child.size();
        for(int i = 0; i < size; i++){
            if(child[i]->type == file->type && child[i]->name == file->name){
                return child[i];
            }
        }
        return NULL;
    }
    
    int find(string file){
        int size = child.size();
        for(int i = 0; i < size; i++){
            if(child[i]->name == file){
                return i;
            }
        }
        return -1;
    }
    
    bool erase(FCB *file){
        int size = child.size();
        vector<FCB *>::iterator it;
        for(it = child.begin(); it != child.end(); it++){
            if((*it)->type == file->type && (*it)->name == file->name){
                child.erase(it);
                return true;
            }
        }
        return false;
    }
    int size(){
        return child.size();
    }
private:
    int childSize;
};

/*DiskManager.h, DiskManager.cpp*/
class DiskManager{
private:
    string rootPath, tmpmessages;
    const string ACCESS[4] = {"\033[92m  只读\033[0m", "可修改", "\033[96m可执行\033[0m", "\033[94m  系统\033[0m"};
    queue<FCB *> persistQueue;//持久化队列
    string blocks[N];
    ofstream *outs = NULL;
    ifstream *in   = NULL;
    FAT fat;
    int totalMem = 512;
    int used = 0;
public:
    void DiskWrite(File *file){
        printf("%s\n", file->path.c_str());
        outs = new ofstream(file->path.c_str());
        if(outs->is_open()){
            outs->close();
        }
    }
    void DiskWrite(File *file, int tempint){
        //printf("%s\n", file->path.c_str());
        outs = new ofstream(file->path.c_str());
        if(outs->is_open()){
            outs->close();
        }
    }
    //创建磁盘文件夹
    bool DiskMkdir(string dirName){
        return mkdir(dirName.c_str(), S_IRWXU) == 0;
    }
    //删除磁盘文件夹
    bool DiskRmdir(string dirName){
        return rmdir(dirName.c_str()) == 0;
    }
    //查找
    bool DiskCkdir(string dirName){
        if(access(dirName.c_str(), 0) == -1){
            return mkdir(dirName.c_str(), S_IRWXU) == 0;
        }
        return false;
    }
    void DiskRmdir(Folder *f){
        //DFS删除
        for(int i = 0; i < f->child.size(); i ++){
            //判断文件类型
            if(f->child[i]->type == DOCUMENT){
                printf("%s\n", f->child[i]->path.c_str());
                remove(f->child[i]->path.c_str());
                delete f->child[i];
            }else{
                this->DiskRmdir((Folder *)f->child[i]);
            }
        }
        printf("%s\n", f->path.c_str());
        this->DiskRmdir(f->path.c_str());
    }

    int DiskManagers(string argv1, string DiskName){
        if(argv1 == "FORMAT"){
            this->format(blocks);
        }else if(argv1 == "MKDIR"){
            this->Mkdir();
        }else if(argv1 == "RMDIR"){
            this->Rmdir();
        }else if(argv1 == "LS"){
            this->ls();
        }else if(argv1 == "CD"){
            this->cd();
        }else if(argv1 == "CREATE"){
            this->create();
        }else if(argv1 == "OPEN"){
            this->open();
        }else if(argv1 == "CLOSE"){
            this->close();
        }else if(argv1 == "RM"){
            this->rm();
        }else if(argv1 == "SFM"){ //设置文件保护方式
            this->SFM();
        }else if(argv1 == "RUN"){ //运行可执行脚本文件（暂时保留）
            this->run();
        }
        out = this->root->path + ">>># ";
        return 0;
    }
    /*接口函数，获取目录*/
    string GetPath() const{
        return (this->root->path + ">>># ");
    }
    /*接口函数，获取磁盘总空间*/
    int AllMem() const{
        return totalMem;
    }
    /*接口函数，获取磁盘已用空间*/
    int usedMem(){
        return used;
    }
    void run(){
        string name;
        cin>>name;
        File *file = (File *)this->root->find(new File(name, DOCUMENT, fat));
        if(file != NULL){
            if(file->access == Executable){
                string firstline = readThefirstLine(file->path.c_str());
                if(firstline == "!#!/"){
                    
                }
                else{
                    cout<<"该文件非可执行脚本文件"<<endl;
                }
            }
        }
        else{
            cout<<"无法打开此文件，该文件非可执行文件"<<endl;
        }
    }
    //一些命令的实现
    //格式化
    void format(string *blocks){
        fat.init(blocks);
        while(root->father != root){
            this->root = (Folder *) (this->root->father);
        }
        this->DiskRmdir(this->root);
        root->child.clear();
        printf("%s\n", "磁盘格式化成功！");
        tmpmessages = *blocks + " success";
    }
    void format(string *blocks, int n){
        string *block = blocks;
        fat.init(block);
        while(root->father != root){
            this->root = (Folder *) (this->root->father);
        }
        this->DiskRmdir(this->root);
        root->child.clear();
        //printf("%s\n", "磁盘格式化成功！");
        //tmpmessages = *blocks + " success";
    }
    void SFM(){
        string name;
        int acctmp;
        cin>>name>>acctmp;
        int i = this->root->find(name);
        if(i != -1){
            root->child[i]->access = (Access)(acctmp <= 2 ? acctmp : root->child[i]->access);
            tmpmessages =  name + " success";
        } else {
            cout<<"无此文件"<<endl;
            tmpmessages = name + " failed";
        }
    }
    void Mkdir(){
        string name;
        cin >> name;
        Folder *childFile = new Folder(name, FileType::FOLDER);
        //设置父节点
        childFile->father = (this->root);
        childFile->path   = this->root->path + name + "\\";
        //判断文件是否重复
        if(this->root->count(childFile)){
            //文件重复报错
            cout<<"创建文件夹失败，文件夹名出现重复"<<endl;
            tmpmessages = name + " failed";
        } else {
            cout<<"创建文件夹成功"<<endl;
            this->DiskMkdir(childFile->path);
            this->root->addChild(childFile);
            tmpmessages =  name + " success";
        }
    }
    void Mkdir(string name){
        string pathname = name;
        Folder *childFile = new Folder(pathname, FileType::FOLDER);
        //设置父节点
        childFile->father = (this->root);
        childFile->path   = this->root->path + pathname + "\\";
        //判断文件是否重复
        if(this->root->count(childFile)){
            //文件重复报错
            //cout<<"创建文件夹失败，文件夹名出现重复"<<endl;
        } else {
            //cout<<"创建文件夹成功"<<endl;
            this->DiskMkdir(childFile->path);
            this->root->addChild(childFile);
        }
    }
    void Rmdir(){
        string name;
        cin >> name;
        Folder *childFile = new Folder(name, FileType::FOLDER);
        if(this->root->erase(childFile)){
            this->DiskRmdir(childFile);
            cout<<"文件夹删除成功"<<endl;
            tmpmessages = name + " success";
        } else {
            cout<<"无此文件夹，删除文件夹失败"<<endl;
            tmpmessages = name + " failed";
        }
    }
    void Rmdir(string filenamepath){
        string name = filenamepath;
        Folder *childFile = new Folder(name, FileType::FOLDER);
        if(this->root->erase(childFile)){
            this->DiskRmdir(childFile);
            //cout<<"文件夹删除成功"<<endl;
        } else {
            //cout<<"无次文件夹，删除文件夹失败"<<endl;
        }
    }
    void ls(){
        cout<<setw(10)<<"访问权限"<<setw(20)<<"文件大小"<<setw(25)<<"修改日期"<<setw(20)<<"文件名"<<endl;
        int size = this->root->size();
        for(int i = 0; i < size; i++){
            cout<<setw(10) << (this->root->child[i]->type != FOLDER ? ACCESS[this->root->child[i]->access] : "\033[93m文件夹\033[0m")
                <<setw(20)
                <<(this->root->child[i]->type != FOLDER ? ((File *) this->root->child[i])->toString(blocks).size() : 0) <<setw(25)
                <<this->root->child[i]->modifyDate
                <<setw(20)<<this->root->child[i]->name
                <<endl;
        }
        tmpmessages = "success";
    }
    void cd(){
        string name;
        cin >> name;
        if(name == ".."){
            this->root = (Folder *) (this->root->father);
            tmpmessages = name + " success";
        } else {
            if(this->root->count(new Folder(name, FOLDER))){
                if(this->root->find(new Folder(name, FOLDER))->type != FOLDER){
                    cout<<"无此文件夹"<<endl;
                    tmpmessages = name + " failed";
                }else{
                    root = (Folder *) this->root->find(new Folder(name, FOLDER));
                    tmpmessages = name + " success";
                }
            }else{
                cout<<"无此文件夹"<<endl;
                tmpmessages = name + " failed";
            }
        }
    }
    void cd(string name){
        string pathname = name;
        if(pathname == ".."){
            this->root = (Folder *) (this->root->father);
        } else {
            if(this->root->count(new Folder(pathname, FOLDER))){
                if(this->root->find(new Folder(pathname, FOLDER))->type != FOLDER){
                    //cout<<"无此文件夹"<<endl;
                }else{
                    root = (Folder *) this->root->find(new Folder(pathname, FOLDER));
                }
            }else{
                //cout<<"无此文件夹"<<endl;
            }
        }
    }
    void create(){
        string name;
        int acctmp;
        cin>>name>>acctmp;
        if(acctmp > 2){
            return;
        }
        File *childFile = new File(name, DOCUMENT, fat, (Access)acctmp);
        childFile->father = (this->root);
        childFile->path = this->root->path + name;
        if(this->root->count(childFile)){
            cout<<"创建文件失败，此文件已存在！！"<<endl;
            tmpmessages =  childFile->path + " failed";
        } else {
            cout<<"创建文件成功！"<<endl;
            this->root->addChild(childFile);
            this->DiskWrite(childFile);
            tmpmessages = childFile->path + " success";
        }
    }
    void create(string name, int acc){
        Access acctmp = (Access)acc;
        string pathname = name;
        File *childFile = new File(pathname, DOCUMENT, fat, acctmp);
        childFile->father = (this->root);
        childFile->path = this->root->path + pathname;
        if(this->root->count(childFile)){
            //cout<<"创建文件失败，此文件已存在！！"<<endl;
        } else {
            //cout<<"创建文件成功！"<<endl;
            this->root->addChild(childFile);
            this->DiskWrite(childFile, 1);
        }
    }
    //用户调用
    void open(){
        string name, cmd;
        cin>>name;
        File *file = (File *)this->root->find(new File(name, DOCUMENT, fat));
        if(file != NULL){
            cout<<"文件读写流打开成功！"<<endl;
            cout<<out;
            while(cin>>cmd){
                cin.clear();
                cin.sync();
                cout<<out;
                if(cmd == "write"){
                    if(file->access == Write){
                        this->write(file->path.c_str(), file);
                    }
                    else{
                        pterr(name, "不可写");
                        tmpmessages = file->path + " " + cmd + " failed";
                    }
                } else if(cmd == "read"){
                    this->read(file->path.c_str());
                } else if (cmd == "close") {
                    this->close();
                    break;
                }
                cin.clear();
                cin.sync();
            }
            tmpmessages = file->path + " " + cmd + " success";
        } else {
            printf("无法打开文件读写流，无此文件！\n");
            tmpmessages = file->path + " " + cmd + " failed";
        }
    }
    //内核调用
    void open(string name, string cmd, string text = "(__null)"){
        string pathname = name, tempcmd = cmd, temptxt = text;
        File *file = (File *)this->root->find(new File(pathname, DOCUMENT, fat));
        if(file != NULL){
            //cout<<"文件读写流打开成功！"<<endl;
            //cout<<out;
            //cout<<out;
            if(tempcmd == "write"){
                this->write(file->path.c_str(), file, temptxt);
            } else if(tempcmd == "read"){
                this->read(file->path.c_str());
            } else if (tempcmd == "close") {
                this->close();
            }
        } else {
            //printf("无法打开文件读写流，无此文件！\n");
        }
    }
    void close(){
        if(outs == NULL || in == NULL){
            cout<<"无文件读写流需要关闭！"<<endl;
            tmpmessages = "none";
        }
        else{
            outs->close();
            in->close();
            cout<<"文件读写流关闭成功！"<<endl;
            tmpmessages = "success";
        }
    }
    void write(const char *s, File *file){
        //if(in != NULL)in->close();
        string content;
        getline(cin, content);
        file->addContent(content.c_str(), blocks, fat);
        content = file->toString(blocks);
        outs = new ofstream(s);
        if(outs->is_open()){
            *outs << content;
        }
        //outs->close();
        string tmpstres = s;
        tmpmessages =  tmpstres + " " + content + " success";
    }
    void write(const char *s, File *file, string text){
        string content = text;
        if(in != NULL)in->close();
        file->addContent(content.c_str(), blocks, fat);
        content = file->toString(blocks);
        outs = new ofstream(s);
        if(outs->is_open()){
            *outs << content;
        }
        outs->close();
    }
    void read(const char* s){
        string content;
        //if(outs != NULL) outs->close();
        in = new ifstream(s);
        if(in->is_open()){
            while(getline(*in, content)){
                cout<<content<<endl;
            }
        }
        in->close();
        string tmpfiler = s;
        tmpmessages = tmpfiler + " success";
    }
    string readThefirstLine(const char* s){
        string content;
        //if(outs != NULL) outs->close();
        in = new ifstream(s);
        if(in->is_open()){
            getline(*in, content);
        }
        in->close();
        return content;
    }
    void rm(){
        string name;
        cin >> name;
        File *childFile = new File(name, DOCUMENT, fat);
        if(this->root->count(childFile)){
            if(childFile->access != System){
                childFile = (File *) this->root->find(childFile);
                remove(childFile->path.c_str());
                childFile->release(fat, blocks);
                this->root->erase(childFile);
                cout<<"删除文件成功！"<<endl;
                tmpmessages = childFile->path + " " + "success";
            }
            else{
                cout<<"此文件为系统文件，删除失败"<<endl;
                tmpmessages = childFile->path + " " + "failed";
            }
        }else{
            cout<<"无此文件，删除失败！"<<endl;
            tmpmessages = childFile->path + " " + "failed";
        }
    }
    void rm(string name){
        string Pathname = name;
        File *childFile = new File(Pathname, DOCUMENT, fat);
        if(this->root->count(childFile)){
            childFile = (File *) this->root->find(childFile);
            remove(childFile->path.c_str());
            childFile->release(fat, blocks);
            this->root->erase(childFile);
            //cout<<"删除文件成功！"<<endl;
        }else{
            //cout<<"无此文件，删除失败！"<<endl;
        }
    }
    /*DiskManager(string argv1, string DiskName){
        DiskManagers(argv1,DiskName);
    }*/
    void input(string argv1){
        DiskManagers(argv1, this->DiskNames);
        tmper >> out.c_str() >> " " >> date().c_str() >> " " >> argv1.c_str() >> " " >> tmpmessages.c_str() >> "\n";
    }
    DiskManager(){
        
    }
    DiskManager(string DiskName, string rootpath){
        rootPath = rootpath;
        fat.init(blocks);
        root = new Folder(rootPath, FileType::FOLDER);
        root->path = rootPath;
        this->DiskMkdir(rootPath);
        root->father = root;
        this->DiskNames = DiskName;
        string InitOK = "[\033[92mOK\033[0m]" + DiskName + "盘文件系统初始化完成";
        cout<<InitOK<<endl;
    }
    DiskManager(int computername, string DiskName, string rootpath){
        rootPath = rootpath;
        fat.init(blocks);
        root = new Folder(rootPath, FileType::FOLDER);
        root->path = rootPath;
        this->DiskMkdir(rootPath);
        root->father = root;
        this->DiskNames = DiskName;
    }
private:
    Folder *root;
    string DiskNames;
};
class FileSystem:protected ADosClass
{
    public:
    const char* login_init_ = "C:\n..system\n...dos.adexe\n...open.adexe\n...Ping.adexe\n...Ping.adll\n...install.adexe\n...gsc.adexe\n...GetIp.adexe\n...GetIp.adll\n...ipconfig.adexe\n...TE.adexe\n...TE.txtmd\n...FE.txtmd\n...En.adll\n...BOOK.adexe\n...READ.ME\nE:\n..tmp\nF:\n..tmp\n";
    const string C_init_ = "..system\n...dos.adexe\n...open.adexe\n...Ping.adexe\n...Ping.adll\n...install.adexe\n...gsc.adexe\n...GetIp.adexe\n...GetIp.adll\n...ipconfig.adexe\n...TE.adexe\n...TE.txtmd\n...FE.txtmd\n...En.adll\n...BOOK.adexe\n...READ.ME";
    string E_init_ = "..tmp";
    string F_init_ = "..tmp";
    const string README = "是的，这就是README文件\n    其实我也想要做这个大项目好久了。这也是我第一次做这么庞大的一个项目，有不好的地方请多包容，我技术不好，难免有不好的地方，请见谅。\n    要是说我为什么想做这么个项目，其实也是手痒痒。而且因为我以前也做了一个类似于终端的东西，可是没做出来，所以这次想要挑战一下。我看了编程社区的许多类似于此类的作品，u1s1，都很不错，但是都有些不太好的地方，比如说加载动画时间太长、输出超长等问题，所以我这次连logo都没加，就是怕加载特效太慢或者输出超长，而且编程社区的C++也只能做dos。本来我也是想要做一个能够保存用户设"
    "置的功能，奈何学而思编程社区的限制（不允许代码创建文件或者创建完运行结束就更换目录），所以就无法实现了。关于界面这一块，我最近正在做一个专属于C++的图形库，但是因为没做完并没有发出来，我在这个项目里也就只引用了部分函数。等回头那个库做好了、发出来了以后我会更新界面的。还有就是关于开源的这个问题，我想好了，以后我在编程社区发的所有的项目如果没有特殊说明的情况下都会开源，各位大佬可以帮我补充或者修改内容，完善逻辑上和技术上的不足，代码注释我会好好写的，有不好的地方跟我说，我改正(doge)。然后我还想说明以下几点:\n"    
    "    1.不许抄袭（这亘古不变的了都）。\n    2.改编的话是可以的，但是改编的时候要将作品改为改编，转载时要改为转载，其次附上该作品网址。\n    3.如果你发现任何bug或者需要改进的地方又或者是希望增加的功能请发送至邮箱afanstudio@163.com，如果你想要把你写的程序加入其中，也可以和我说，并把源代码发到上述邮箱。最好是可以传参的程序。\n                        by DxiesLawiye(郭墨轩)";
};
/*一些可连接主机，想添加自己主机的在这里添加，现在没用了
class Administrator256{
    private:
    Port tmp;
    Port *port = &tmp;
    public:
};
class AfanStudio{
    private:
    Port tmp;
    Port *port = &tmp;
    public:
};
class TmpComputer{
    private:
    Port tmp;
    Port *port = &tmp;
    public:
};
class Doser{
    private:
    Port tmp;
    Port *port = &tmp;
    public:
};
int getch()
{
    cout<<endl;
    system("stty -echo");
    int c;
    system("stty raw");
    c = getchar();
    system("stty -raw");
    system("stty echo");
    return (c - '0');
}*/

//注册表（保留）
/*Type.h*/
enum Type{ //值的类型
    RG_PC, //字符串
    RG_BINARY //二进制数
};

enum regPath{
    CURRENT_USR,
    _SYSTEM
};

/*key.h*/
struct key{
    string showname;
    Type _type;
    string _name;
    string _key; //值
    regPath _regpath;
    bool _isEx; //是否是扩展名
};

/*Registry.cpp*/
class Registry{
    public:
    void AddKey(key* _key){
        if(_key->_regpath == CURRENT_USR){
            HKEY_CURRENT_USR.push_back(_key);
        } else if (_key->_regpath == _SYSTEM){
            HKEY_SYSTEM.push_back(_key);
        }
    }
    void show(regPath _rpath){
        if(_rpath == CURRENT_USR){
            cout<<"HKEY_CURRENT_USR"<<endl;
            key* keytmp;
            for(vector<key *>::reverse_iterator it = HKEY_CURRENT_USR.rbegin(); it != HKEY_CURRENT_USR.rend(); ++it){
                keytmp = *it;
                if(keytmp->showname != ""){
                    cout<<"|-"<<keytmp->showname<<endl;
                    continue;
                }
            }
        } else if (_rpath == _SYSTEM){
            cout<<"HKEY_SYSTEM"<<endl;
            key* keytmp;
            for(vector<key *>::reverse_iterator it = HKEY_SYSTEM.rbegin(); it != HKEY_SYSTEM.rend(); ++it){
                keytmp = *it;
                if(keytmp->showname != ""){
                    cout<<"|-"<<keytmp->showname<<endl;
                    continue;
                }
            }
        }
    }
    private:
    vector<key *> HKEY_CURRENT_USR;
    vector<key *> HKEY_SYSTEM;
};

Registry reg;
/*Open.cpp*/
class Open:protected ADosClass
{
    private:
    int login = 0;
    int addr;
    protected:
    inline bool finduserfile(string name){
        ifstream tofindfile(name);
        if(!tofindfile)
            return false;
        tofindfile.close();
        return true;
    }
    void CreatePwEdit(char* password, int len)
    {
        int i = 0;
        system("stty -icanon");
        system("stty -echo");
        
        while(i < len)
        {
            password[i] = getchar();
            if(i == 0 && password[i] == BACKSPACE)
            {
                i = 0;
                password[i] = '\0';
                continue;
            }
            else if(password[i] == BACKSPACE)
             {
                printf("\b \b");
                password[i]='\0';
                i = i - 1;
                continue;
            }
            else if(password[i] == '\n')
            {
                password[i] = '\0';
                break;
            }
            else
            {
               printf("*");
             }
           i++;
        }
        system("stty echo");
        system("stty icanon");
    }
    void loading()
    {
        printf("ADos\n");
        printf("loading...\n");
        usleep(200000);
        cout<<"用户名:";
        cin>>username;
        hard.ac->showname = username;
        hard.ac->username = username;
        string tmp = "user" + username + ".h";
        filename = tmp;
        printf("加载配置文件:");
        int inttmp = finduserfile(filename);
        if(inttmp == true)
        {
            cout<<"\n请输入密码"<<endl;
            cin>>userpassword;
        }
        //usleep(200000);
        sleep(2);
        system("clear");
    }
    void loadusrfile(){
        
    }
    void writeusrfile()
    {
        cout<<"开始储存配置"<<endl;
        cout<<"开始创建用户文件,请输入用户名"<<endl;
        cin>>username;
        CreateUserFile();
        cout<<"正在打开文件"<<endl;
        ofstream writefile(filename);
        if(writefile.is_open() == 0)
        {
            cerr<<"open file failed";
            writefile.close();
            return;
        }
        cout<<"开始写入硬件信息"<<endl;
        writefile<<"[SystemHardware]\n";
        cout<<"写入基本硬件信息"<<endl;
        writefile<<"cpu:ADosCpu\n";
        WRITEFILEOK("写入cpu名称")
        writefile<<"kernel:2\n";//内核数
        WRITEFILEOK("写入内核数量")
        writefile<<"memory:4\n";//总内存
        WRITEFILEOK("写入总内存")
        cout<<"开始写入配置"<<endl;
        writefile<<"[SystemSet]\n";
        writefile<<"language:Chinese\n";
        WRITEFILEOK("写入语言设置")
        writefile<<"DKmemory:"<<sysset.DKmem<<"\n";
        WRITEFILEOK("写入磁盘总空间")
        writefile<<"Mainmemory:"<<sysset.Mainmem<<"\n";
        WRITEFILEOK("写入主分区空间")
        writefile<<"Othermem:"<<sysset.Othermem<<"\n";
        WRITEFILEOK("写入扩展分区空间")
        writefile<<"ExDkNumber:"<<sysset.ExDkNumber<<"\n";
        WRITEFILEOK("写入扩展分区数量")
        writefile<<"ExDk1Name:"<<sysset.ExDk1Name<<"\n";
        writefile<<sysset.ExDk1Name<<":"<<sysset.ExDk1mem<<"\n";
        writefile<<"ExDk2Name:"<<sysset.ExDk2Name<<"\n";
        writefile<<sysset.ExDk2Name<<":"<<sysset.ExDk2mem<<"\n";
        WRITEFILEOK("写入扩展分区信息")
        
        writefile.close();
    }
    void ChooseSet()
    {
        CHOOSE("\n请选择语言(目前只支持中文)","中文", "English(不可选)")
        int tmp;
        cin >> tmp;
        if(tmp == 1)
        {
            sysset.languages = CHINESE;
        }
        system("clear");
        CHOOSE("请选择磁盘大小","512MB","256MB")
        cin >> tmp;
        if(tmp != 2)
        {
            sysset.DKmem = 512;
        }
        else
        {
            sysset.DKmem = 256;
        }
        system("clear");
        CHOOSE("是否全部分给主分区","是","否")
        cin >> tmp;
        if(tmp != 2)
        {
            sysset.Mainmem = sysset.DKmem;
            sysset.ExDk1Name = "__null";
            sysset.ExDk2Name = "__null";
        }
        else
        {
            memagain:int memtmp;
            printf("请填入分配空间数(10~125MB)\n");
            cin>>memtmp;
            if(memtmp <= 125 && memtmp >= 10)
            {
                sysset.Mainmem = memtmp;
                sysset.Othermem = sysset.DKmem - memtmp;
            }
            else
            {
                goto memagain;
            }
        }
        if(sysset.Othermem != 0)
        {
            CHOOSE("请选择扩展分区数量","1","2")
            cout<<endl;
            cin >> tmp;
            if(tmp != 2)
            {
                sysset.ExDkNumber = 1;
                cout << "请输入扩展分区名称" << endl;
                cin >> sysset.ExDk1Name;
                sysset.ExDk2Name = "__null";
                sysset.ExDk1mem = sysset.Othermem;
                sysset.ExDk2mem = MEMNULL;
            }
            else
            {
                sysset.ExDkNumber = 2;
                cout << "请输入扩展分区名称" << endl;
                printf("分区1:");
                string tmpname1, tmpname2;
                cin >> tmpname1;
                sysset.ExDk1Name = tmpname1;
                cout<<endl;
                printf("分区2:");
                cin >> tmpname2;
                sysset.ExDk2Name = tmpname2;
                cinmemagain:cout<<endl;
                cout<<"输入分区"<<"\""<<tmpname1<<"\"所需空间(MB)"<<endl;
                int Dk1mem;
                cin>>Dk1mem;
                if(Dk1mem >= sysset.Othermem)
                    goto cinmemagain;
                sysset.ExDk1mem = Dk1mem;
                sysset.ExDk2mem = sysset.Othermem - sysset.ExDk1mem;
                printf("分区%s空间:%dMB\n", sysset.ExDk2Name.c_str(), sysset.ExDk2mem);
                CHECK("确认如此分配","Y","N")
                char check;
                cin >> check;
                if(check != 'Y')
                    goto cinmemagain;
            }
            system("clear");
        }
        CHOOSE("是否安装ping","是","否")
        cout<<endl;
        cin >> tmp;
        if(tmp != 2)
            sysset.hasping = true;
        else
            sysset.hasping = false;
        CHOOSE("选择文件系统（这个其实就是充数的…选啥都行，我技术不到哪儿）","NTFS","FAT")
        cout<<endl;
        cin>>tmp;
        system("clear");
#define Dk1Name sysset.ExDk1Name.c_str()
#define Dk2Name sysset.ExDk2Name.c_str()
        printf("语言:Chinese\n磁盘空间:%dMB\n主分区空间:%dMB\n扩展分区数量:%d\n扩展分区名称:%s,%s\n扩展分区空间:%s:%d,%s:%d\n",sysset.DKmem,
                sysset.Mainmem,sysset.ExDkNumber,Dk1Name,Dk2Name,Dk1Name,sysset.ExDk1mem,Dk2Name,sysset.ExDk2mem);
        writeusrfile();
    }
    void SetupSystem()
    {
        
    }
    /*void delfile()
    {
        remove(filename.c_str());
    }*/
    CProgress pro;
    void Animation()
    {
        for(int i = 0; i <= 100; i ++)
    	{
    		pro.progress_bar(i);
    		Sleep(20);
    	}
    }
    public:
    Open(){
        addr = Mem.CreateThread("Open", "Open.adexe", 8 * 200,
                                "the basic of the system", "AFAN Studio", 
                                CANNOT|SYSTEM|NEW);
        Mem.RunThread(addr, "Open");
    }
    ~Open(){
        Mem.KillThread(addr, "Open");
    }
    void login_init_()
    {
        sysset={
            .languages = CHINESE,
            .txtcokor = NORMAL,
            .txtbkcolor = BKNORMAL,
            .DKmem = 512,
            .Mainmem = 120,
            .Othermem = 392,
            .ExDkNumber = 2,
            .ExDk1Name = "E", 
            .ExDk2Name = "F",
            .ExDk1mem = 200, 
            .ExDk2mem = 192,
            .hasping = true
        };
    }
    void openmain()
    {
        loading();
#ifdef DEBUG
        cout<<filename;
#endif
        cout<<"游客登录请输入1(目前只能游客登录)"<<endl;
        cin>>login;
        if(login != 1){
            if(finduserfile(filename) == false)
            {
                sleep(2);
                ChooseSet();
            }
        }
        Animation();
        cout<<endl<<"正在初始化"<<endl;
        if(login == 1)
        {
            login_init_();
            loginif = login;
            cout<<"初始化完成"<<endl;
        }
        //SetupSystem();
        //delfile();
    }
    /*void tmpfunc()
    {
        ChooseSet();
    }*/
};

/*创建磁盘分区*/
DiskManager dk_C("C","C:\\system\\");
DiskManager dk_E("E","E:\\root\\");
DiskManager dk_F("F","F:\\root\\");
//dk_tmp:T盘为一个临时文件盘
DiskManager dk_tmp("T","T:\\temp\\");

const Logger &Logger::operator>>(const char* cstr) const{
    //dk_tmp.cd("Temp");
    dk_tmp.open("cmdtemp.tmp", "write", cstr);
    //dk_tmp.cd("..");
    return *this;
}

/*function*/
//software.cpp
class AES
{
    private:
    static unsigned char x2time(unsigned char x){
        if(x&0x80){
            return (((x<<1)^0x1B)&0xFF);
        }
        return x<<1;
    }
    static unsigned char x3time(unsigned char x){
        return (x2time(x)^x);
    }
    static unsigned char x4time(unsigned char x){
        return (x2time(x2time(x)));
    }
    static unsigned char x8time(unsigned char x){
        return (x2time(x2time(x2time(x))));
    }
    static unsigned char x9time(unsigned char x){//1001
        return (x8time(x)^x);
    }
    static unsigned char xBtime(unsigned char x){//1011
        return (x8time(x)^x2time(x)^x);
    }
    static unsigned char xDtime(unsigned char x){//1101
        return (x8time(x)^x4time(x)^x);
    }
    static unsigned char xEtime(unsigned char x){//1110
        return (x8time(x)^x4time(x)^x2time(x));
    }
    static void MixColumns(unsigned char *col)
    {
        unsigned char tmp[4],xt[4];
        for(int i = 0;i < 4; i ++, col += 4)
        {
            tmp[0]=x2time(col[0])^x3time(col[1])^col[2]^col[3];
            tmp[1]=col[0]^x2time(col[1])^x3time(col[2])^col[3];
            tmp[0]=col[0]^col[1]^x2time(col[2])^x3time(col[3]);
            tmp[0]=x3time(col[0])^col[1]^col[2]^x2time(col[3]);
            col[0]=tmp[0];
            col[1]=tmp[1];
            col[2]=tmp[2];
            col[3]=tmp[3];
        }
    }
    static void Contrary_MixColumns(unsigned char *col)
    {
    	unsigned char tmp[4];
    	unsigned char xt2[4];//colx2
    	unsigned char xt4[4];//colx4
    	unsigned char xt8[4];//colx8
    	int x;
    	for(x=0;x<4;x++,col+=4)
    	{
    		tmp[0]=xEtime(col[0])^xBtime(col[1])^xDtime(col[2])^x9time(col[3]);
    		tmp[1]=x9time(col[0])^xEtime(col[1])^xBtime(col[2])^xDtime(col[3]);
    		tmp[2]=xDtime(col[0])^x9time(col[1])^xEtime(col[2])^xBtime(col[3]);
    		tmp[3]=xBtime(col[0])^xDtime(col[1])^x9time(col[2])^xEtime(col[3]);
    		col[0]=tmp[0];
    		col[1]=tmp[1];
    		col[2]=tmp[2];
    		col[3]=tmp[3];
    	}
    }
    static void ShiftRows(unsigned char *col)
    {
    	unsigned char t;
    	/*1nd row*/
    	t=col[1];col[1]=col[5];col[5]=col[9];col[9]=col[13];col[13]=t;
    	/*2rd row*/
    	t=col[2];col[2]=col[10];col[10]=t;
    	t=col[6];col[6]=col[14];col[14]=t;
    	/*3th row*/
    	t=col[15];col[15]=col[11];col[11]=col[7];col[7]=col[3];col[3]=t;
    	/*4th row*/
    }
    static void Contrary_ShiftRows(unsigned char *col)
    {
    	unsigned char t;
    	/*1nd row*/
    	t=col[13];col[13]=col[9];col[9]=col[5];col[5]=col[1];col[1]=t;
    	/*2rd row*/
    	t=col[2];col[2]=col[10];col[10]=t;
    	t=col[6];col[6]=col[14];col[14]=t;
    	/*3th row*/
    	t=col[3];col[3]=col[7];col[7]=col[11];col[11]=col[15];col[15]=t;
    	/*4th row*/
    }
    static void SubBytes(unsigned char *col)
    {
    	int x;
    	for(x=0;x<16;x++)
    	{
    		col[x]=sbox[col[x]];
    	}
    }
    static void Contrary_SubBytes(unsigned char *col)
    {
    	int x;
    	for(x=0;x<16;x++)
    	{
    		col[x]=contrary_sbox[col[x]];
    	}
    }
    static void AddRoundKey(unsigned char *col,unsigned char *expansionkey,int round)//密匙加
    {
    	int x;				
    	for(x=0;x<16;x++)
    	{
    		col[x]^=expansionkey[(round<<4)+x];
    	}
    }
    public:
    void AesEncrypt(unsigned char *blk,unsigned char *expansionkey,int Nr)//加密一个区块
    {
    	int round;
    	AddRoundKey(blk,expansionkey,0);
    	for(round=1;round<=(Nr-1);round++)	
    	{
    		SubBytes(blk);		
    		ShiftRows(blk);		
    		MixColumns(blk);	
    		AddRoundKey(blk,expansionkey,round);
    	}
    	SubBytes(blk);
    	ShiftRows(blk);
    	AddRoundKey(blk,expansionkey,Nr);
    }
    void Contrary_AesEncrypt(unsigned char *blk,unsigned char *expansionkey,int Nr)
    {
    	int x;
    	AddRoundKey(blk,expansionkey,Nr);
    	Contrary_ShiftRows(blk);
    	Contrary_SubBytes(blk);
    	for(x=(Nr-1);x>=1;x--)
    	{
    		AddRoundKey(blk,expansionkey,x);
    		Contrary_MixColumns(blk);
    		Contrary_ShiftRows(blk);
    		Contrary_SubBytes(blk);
    	}
    	AddRoundKey(blk,expansionkey,0);
    }
    void ScheduleKey(unsigned char *inkey,unsigned char *outkey,int Nk,int Nr)//安排一个保密密钥使用
    {
    	unsigned char temp[4],t;
    	int x,i;
    	/*copy the key*/
    	for(i=0;i<(4*Nk);i++)
    	{
    		outkey[i]=inkey[i];
    	}
    	i=Nk;
    	while(i<(4*(Nr+1))) 
    	{
    		for(x=0;x<4;x++) 
    			temp[x]=outkey[(4*(i-1))+x];
    		if(i%Nk==0)
    		{
    			t=temp[0];temp[0]=temp[1];temp[1]=temp[2];temp[2]=temp[3];temp[3]=t;
    			for(x=0;x<4;x++)
    			{
    				temp[x]=sbox[temp[x]];
    			}
    			temp[0]^=Rcon[(i/Nk)-1];
    		}
    		for(x=0;x<4;x++)
    		{
    			outkey[(4*i)+x]=outkey[(4*(i-Nk))+x]^temp[x];
    		}
    		++i;
    	}
    }
    public:
    AES(void){
        unsigned char pt[17],key[17];
        unsigned char expansionkey[15*16];
        int i;
        int j;
        printf("please input plaintext\n");//输入无格式的字符串字符个数不得少于六个！！！！尽量用不同的数字或字母
        scanf("%s",pt);
        printf("please input key\n");//输入加密钥匙密匙个数不得低于六个！！！！尽量用不同的数字或字母
        scanf("%s",key);
        
        /*加密*/
        ScheduleKey(key,expansionkey,4,10);	//1、密钥扩展生成
        AesEncrypt(pt,expansionkey,10);		//2、AES 加密
        printf("AesEncrypt text is: ");	//输出密码文件
        for (i = 0; i < 16; i++)
        {
            printf("%02x ", pt[i]);
        }
        printf("\n");
        printf("\n");
        
        /*解密*/
        Contrary_AesEncrypt(pt,expansionkey,10);//AES 解密
        printf("after Contrary_AesEncrypt,plaintext is: ");//将解密文件输出
        for (i = 0; i < 16; i++)
        {
            printf("%c ", pt[i]);
        }
        printf("\n");
        printf("\n");
    }
};
#define EXTEN20     "                    "
#define FILEPATH20  "                    "
#define EXTENMAX    20
#define FILEPATHMAX 20
class ASSOCEXE
{
    private:
    EXTENSION tmp, *extension, returnenten;
    FileSystem filesys;
    int temp;
    string tmpExten = EXTEN20, tmpFilenamePath = FILEPATH20, filesystemp;//不加EXTEN20和FILEPATH20的话会赋值失败
    string getexten(string filePathName)
    {
        string tmpstr = EXTEN20;
        bool flag = false;
        for(int i = 0; i <= filePathName.length(); i ++)
        {
            if(filePathName[i] == '.')
            {
                flag = true;
            }
            if(flag == true){
                for(int j = 0; filePathName[i] != '\0'; i++, j ++)
                {
                    tmpstr[j] = filePathName[i];
                }
            }
        }
        return tmpstr;
    }
    void ExtenNoneSpace(string &ExtensionCall)
    {
        int index = 0;
        if(!ExtensionCall.empty())
        {
            while((index = ExtensionCall.find(' ', index)) != string::npos)
            {
                ExtensionCall.erase(index, 1);
            }
        }
    }
    void FilepathNoneSpace(string &filePathName)
    {
        int index = 0;
        if(!filePathName.empty())
        {
            while((index = filePathName.find(' ', index)) != string::npos)
            {
                filePathName.erase(index, 1);
            }
        }
    }
    void help(){
        PRINT_HELP(printf("==========================ASSOC==============================\n"),
                printf("=============================================================\n"))
        {
            print("ASSOC                                显示或修改文件扩展名关联。");
            print("ASSOC -a [后缀名]&[可执行文件地址]   绑定或修改绑定");
            print("ASSOC -b show                        显示绑定文件扩展名的软件。");
            print("ASSOC -h help                        帮助。");
            print("ASSOC -r return                      恢复默认设置。");
            print("ASSOC -s show                        显示全部文件扩展名。");
        }
    }
    int show(string argv)//避免警告所以不使用const char*
    {
        if(argv != "show")
        {
            return 0;
        }
        printf("7z:%s\nadexe:%s\nadll:%s\nC:%s\ncpp:%s\nh:%s\nlog:%s\n"
            "me:%s\ntxt:%s\ntxtmd:%s\ntz:%s\nrar:%s\nzip:%s\n", extension->_7z.c_str(),
            extension->_adexe.c_str(), extension->_adll.c_str(), extension->_C.c_str(),
            extension->_cpp.c_str(), extension->_h.c_str(), extension->_log.c_str(),
            extension->_me.c_str(), extension->_txt.c_str(), extension->_txtmd.c_str(),
            extension->_tz.c_str(), extension->_rar.c_str(), extension->_zip.c_str());
        return 1;
    }
#define Extenf(t) if(ExtensionCall == t)
#define Extenif(t) else if(ExtensionCall == t)
#define Extenof(t, v) else if(ExtensionCall == t || ExtensionCall == v)
    int show_s(string argv)
    {
        if(argv != "show"){
            return 0;
        }
        printf("7z\nadexe\nadll\nC\ncpp\nh\nlog\n"
            "me\ntxt\ntxtmd\ntz\nrar\nzip\n");
        return 1;
    }
    int binding(string ExtensionCall, string filePathName)
    {
        filesystemp = filesys.login_init_;
        /*大量if*/
        if(filesystemp.find(filePathName) == -1)
        {
            return 0;
        }
        string tempstr = getexten(filePathName);
        ExtenNoneSpace(tempstr);
        if(tempstr != ".adexe")
        {
            pterr(filePathName, "不是可执行文件");
            return -1;
        }
        Extenf("7z"){
            extension->_7z = filePathName;
        }
        Extenif("adexe"){
            pterr(ExtensionCall, "不能更改");
            return 3;
        }
        Extenif("adll"){
            pterr(ExtensionCall, "不能更改");
            return 3;
        }
        Extenof("C", "c"){
            extension->_C = filePathName;
        }
        Extenif("cpp"){
            extension->_cpp = filePathName;
        }
        Extenif("cpp"){
            extension->_cpp = filePathName;
        }
        Extenif("h"){
            extension->_h = filePathName;
        }
        Extenif("log"){
            extension->_log = filePathName;
        }
        Extenif("me"){
            extension->_me = filePathName;
        }
        Extenif("txt"){
            extension->_txt = filePathName;
        }
        Extenif("txtmd"){
            extension->_txtmd = filePathName;
        }
        Extenif("tz"){
            extension->_tz = filePathName;
        }
        Extenif("rar"){
            extension->_rar = filePathName;
        }
        Extenif("zip"){
            extension->_zip = filePathName;
        }
        else
        {
            return 2;
        }
        return 1;
    }
    bool split(string argv, string &ExtensionCall, string &filePathName)
    {
        bool hasAnd = false;
        for(int i = 0; i <= argv.length(); i ++)
        {
            if(argv[i] == '&'){
                hasAnd = true;
                continue;
            }
            if(!hasAnd){
                ExtensionCall[i] = argv[i];
                continue;
            }
            for(int j = 0; argv[i] != '\0'; i ++, j ++)
            {
                filePathName[j] = argv[i];
            }
        }
        return hasAnd;
    }
    void __init__()
    {
        tmpExten        = EXTEN20;
        tmpFilenamePath = FILEPATH20;
    }
    public:
    ASSOCEXE(){
        extension = &tmp;
    }
    ~ASSOCEXE(){
        __init__();
    }
    int ASSOC(const char* argv1, const char* argv2)//假装是个main函数的入口函数
    {
        if(argv1[0] != '-')
        {
            pterr(argv1, "格式不符合要求");
            help();
            return -1;
        }
        switch(argv1[1])
        {
            case 'a':
                if(!split(argv2, tmpExten, tmpFilenamePath))
                {
                    pterr(argv2, "缺少\"&\"");
                    break;
                }
                cout<<tmpExten<<endl<<tmpFilenamePath<<endl;
                if(tmpExten.length() > EXTENMAX || tmpFilenamePath.length() > FILEPATHMAX)
                {
                    cout<<"文件扩展名或者文件名长度大于20，请重新输入！"<<endl;
                    break;
                }
                ExtenNoneSpace(tmpExten);
                FilepathNoneSpace(tmpFilenamePath);
                temp = binding(tmpExten, tmpFilenamePath);
                if(temp == 0){
                    pterr(tmpFilenamePath, "无此文件");
                }
                else if(temp == 1){
                    cout<<"修改成功！"<<endl;
                }
                else if(temp == 2){
                    pterr(tmpExten, "无此后缀名");
                }
                __init__();//不加的话会出问题，比如字符的覆盖不会覆盖整个字符串
            break;
            case 'b':
                temp = show(argv2);
                if(temp == 0)
                {
                    pterr(argv2, "没有找到此命令或文件");
                }
            break;
            case 'h':
                help();
            break;
            case 'r':
                extension = &returnenten;//利用C++自动补充缺省函数的特性
                cout<<"重置成功！"<<endl;
            break;
            case 's':
                temp = show_s(argv2);
                if(temp == 0)
                {
                    pterr(argv2, "没有找到此命令或文件");
                }
            break;
            default:
                help();
                printf("您所输入的指令有问题，请重新输入.\n");
            break;
        }
        return 0;
    }
};
/*设置默认的控制台前景和背景颜色。

COLOR -s [前景色&背景色]


颜色属性由两个十六进制数字指定 -- 第一个为前景，第二个则为
背景。每个数字可以为以下任何值之一:

    0 = 黑色       8 = 灰色
    1 = 蓝色       9 = 淡蓝色
    2 = 绿色       A = 淡绿色
    3 = 浅绿色     B = 淡浅绿色
    4 = 红色       C = 淡红色
    5 = 紫色       D = 淡紫色
    6 = 黄色       E = 淡黄色
    7 = 白色       F = 亮白色

如果没有给定任何参数，该命令会将颜色还原到启动时的颜色。
例如: "COLOR -s cf" 在亮白色上产生亮红色*/
FileSystem tmpfsys;
FileSystem *fsys = &tmpfsys;
class CDEXE
{
    private:
    int tmp;
    string tmpPath;
    void help(){
        PRINT_HELP(printf("==========================CDK=============================\n"),
                    printf("==========================================================\n"))
            {
                print("CDK -a [路径]                             进入所输入的路径。");
                print("CDK -r return                             回到最初路径。");
                print("CDK -h help                               帮助。");
            }
    }
    int pos(string T, string P){
        int position;
        position = T.find(P);
        return position;
    }
    int changeMenu(string Path)
    {
        string tmpx;
        char ch = out[0];
        tmpx.push_back(out[0]);
        tmpPath = tmpx + ":\\" + Path + ">>># ";
        if(tmpPath == out)
        {
            return 0;
        }
        if(Path == "C:" || Path == "C"){
            out = dk_C.GetPath();
            return 0;
        }
        if(Path == "E:" || Path == "E"){
            out = dk_E.GetPath();
            return 0;
        }
        if(Path == "F:" || Path == "F"){
            out = dk_F.GetPath();
            return 0;
        }
        if(Path == "T:" || Path == "T"){
            out = dk_tmp.GetPath();
            return 0;
        }
        else{
            int i = 0, j = 0;
            bool flag = false;
            tmpPath = "";
            //开始拆分,这一部分已经废弃了，想要试试可以试试
            do{
                if(Path.find('\\') == string::npos)
                {
                    tmpPath = Path;
                }
                else
                {
                    return 3;
                }
                tmp = pos(fsys->login_init_, tmpPath);
                if(tmp == string::npos){
                    return -1;
                }
                if(out.find("E:") != string::npos && fsys->E_init_.find(tmpPath) == string::npos)
                {
                    return 2;
                }
                if(out.find("F:") != string::npos && fsys->F_init_.find(tmpPath) == string::npos)
                {
                    return 2;
                }
                if(out.find("C:") != string::npos && fsys->C_init_.find(tmpPath) == string::npos)
                {
                    return 2;
                }
                if(fsys->login_init_[tmp - 2] != '.' || (fsys->login_init_[tmp - 2] == '.' && fsys->login_init_[tmp - 1] == '.' && fsys->login_init_[tmp - 3] == '.'))
                {
                    return 1;
                }
                j = 0;
                flag = true;
            }while(flag != true);
            tmpPath = out;
            regex pattern("\\\\>>># ");
            tmpPath = regex_replace(out, pattern, "\\");//正则表达式分割替换字符串
            out = tmpPath + Path + ">>># ";
            tmpPath = "";
            return 0;
        }
        return -1;
    }
    public:
    int CD(const char* argv1, const char* argv2)
    {
        if(argv1[0] != '-')
        {
            pterr(argv1, "格式不符合要求");
            help();
            return -1;
        }
        switch(argv1[1])
        {
            case 'a':
                tmp = changeMenu(argv2);
                if(tmp == 3){
                    pterr(argv2, "一次请只输入一级路径");
                }
                if(tmp == 2){
                    pterr(argv2, "文件夹不在此目录下");
                }
                if(tmp == 1){
                    pterr(argv2, "不是文件夹");
                }
                if(tmp == -1){
                    pterr(argv2, "路径不存在");
                }
                if(tmp == -2){
                    pterr(argv2, "路径格式错误");
                }
            break;
            case 'h':
                help();
            break;
            case 'r':
                out = "C:\\system>>># ";
            break;
            default:
                help();
                printf("您所输入的指令有问题，请重新输入.\n");
            break;
        }
        return 0;
    }
};
class COLOREXE
{
    private:
    int tmp;
    void help(){
        PRINT_HELP(printf("===========================COLOR===============================\n"),
                printf("===============================================================\n"))
        {
            print("设置默认的控制台前景和背景颜色。");
            print("COLOR -s [前景色]                                     设置颜色。");
            print("");
            print("颜色可以使以下任何数值");
            print("0 = 黑色       8 = 灰色");
            print("1 = 蓝色       9 = 淡蓝色");
            print("2 = 绿色       A = 淡绿色");
            print("3 = 浅绿色     B = 淡浅绿色");
            print("4 = 红色       C = 淡红色");
            print("5 = 紫色       D = 淡紫色");
            print("6 = 黄色       E = 淡黄色");
            print("7 = 白色       F = 亮白色");
            print("");
            print("如果参数为\"n\"，该命令会将颜色还原到启动时的颜色。");
            print("COLOR -h help                                         获取帮助。");
        }
    }
    int settxtcolor(char txtcolor)
    {
        SETCOLOR(txtcolor, TXTBLACK, TXTBLUE, TXTBGREEN, TXTGREEN, TXTRED, TXTPURPLE, 
            TXTYELLOW, TXTNORMAL, TXTWHITE, TXTBRIGHTBLUE, TXTBRIGHTBGREEN, TXTBRIGHTGREEN,
            TXTBRIGHTRED, TXTBRIGHTPURPLE, TXTBRIGHTYELLOW, TXTBRIGHTWHITE, -1)
        return 0;
    }
    int setbkcolor(char bkcolor)
    {
        SETCOLOR(bkcolor, BKGBLACK, BKGBLUE, BKGBGREEN, BKGGREEN, BKGRED, BKGPURPLE, 
            BKGYELLOW, BKGNORMAL, BKGWHITE, BKGBRIGHTBLUE, BKGBRIGHTBGREEN, BKGBRIGHTGREEN,
            BKGBRIGHTRED, BKGBRIGHTPURPLE, BKGBRIGHTYELLOW, BKGBRIGHTWHITE, -2)
        return 0;
    }
    int setcolor(char txtcolor/*, char isand, char bkcolor*/)
    {
        /*if(isand != '&')
        {
            return 3;
        }
        if(setbkcolor(txtcolor) == -2)
        {
            return -2;
        }*/
        if(txtcolor == 'n')
        {
            BKGNORMAL;
            return 0;
        }
        if(settxtcolor(txtcolor) == -1)
        {
            return -1;
        }
        return 0;
    }
    public:
    int COLOR(const char* argv1, const char* argv2){
        if(argv1[0] != '-')
        {
            pterr(argv1, "格式不符合要求");
            help();
            return -1;
        }
        switch(argv1[1])
        {
            case 'h':
                help();
            break;
            case 's':
                tmp = setcolor(argv2[0]/*, argv2[1], argv2[2]*/);
                if(tmp == -1)
                {
                    pterr(argv2[0], "颜色不存在");
                }
                /*if(tmp == -2)
                {
                    pterr(argv2[2], "颜色不存在");
                }
                if(tmp == 3)
                {
                    pterr(argv2[1], "连接符号错误");
                }*/
            break;
            default:
                help();
                printf("您所输入的指令有问题，请重新输入.\n");
            break;
        }
        return 0;
    }
};
class COUNTEREXE
{
    private:
    string formula;
    stack<char> opt;//操作符栈
    stack<double> val;//操作数栈
    int LargeNumberFactorial[1000] = { 0 };//求阶乘所用数组
    
    const int IN = 0;
    const int OUT = 1;
    
    char opt_set[10] = "+-*/()=.";
    
    int level(char theOpt){
        switch(theOpt){
            case '(':
                return 0;
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case ')':
                return 3;
        }
        return -1;
    }
    
    bool in_setCheck(char theChar){
        for(int i = 0; i < 8; i++){
            if(theChar == opt_set[i])
                return true;
        }
        return false;
    }
    
    bool del_space(string& theString){
        string res;
        for(int i = 0; i < theString.length(); i++){
            if(in_setCheck(theString[i]) || isdigit(theString[i]))
                res += theString[i];
            else if(theString[i] == ' ') {}
            else{
                cout<<"表达式错误！"<<endl;
                return false;
            }
        }
        theString = res;
        return true;
    }
    
    string to_string(int theInt){
        if(theInt == 0)
            return string("0");
        bool neg = false;
        if(theInt < 0){
            neg = true;
            theInt = -theInt;
        }
        string res;
        while(theInt != 0){
            char c = (theInt % 10) + '0';
            res = c + res;
            theInt /= 10;
        }
        if(neg){
            res = '-' + res;
        }
        return res;
    }
    
    bool change(string &form, string &to){
        int tint = 0;
        int state =  OUT;
        char c;
        
        for(int i = 0; i < form.length(); i ++){
            c = form[i];
            if(isdigit(c)){
                to = to + c;
                tint *= 10;
                tint += c - '0';
                state = IN; //状态改为在数字内
            }
            else{
                if(state == IN && c == '.'){
                    to = to + '.';
                    tint = 0;
                    continue;
                }
                if(state == IN && c != '.'){
                    to += ' ';
                    tint = 0;
                }
                if(c == '='){
                    break;
                }
                else if(c == '(')
                    opt.push(c);
                else if(c == ')'){
                    while(!opt.empty() && opt.top() != '('){
                        to += opt.top();
                        to += ' ';
                        opt.pop();
                    }
                    opt.pop();
                }
                else{
                    while(true){
                        if(opt.empty() || opt.top() == '(')
                            opt.push(c);
                        else if(level(c) > level(opt.top())){
                            opt.push(c);
                        }
                        else{
                            to += opt.top();
                            to += ' ';
                            opt.top();
                            continue;
                        }
                        break;
                    }
                }
                state = OUT;
            }
        }
        while(!opt.empty()){
            to += opt.top();
            to += ' ';
            opt.pop();
        }
        return true;
    }
    bool compute(string &theExp)
    {
    	int theInt = 0; //暂存数字
    	int state = OUT;//初始状态为在数字外
    	char c;
    	bool dot = false;
    	double count = 1.0;
    	for (int i = 0; i < theExp.length(); i++)
    	{
    		c = theExp[i];
    		if (isdigit(c)|| c == '.') {
    			if (isdigit(c)) {
    				theInt *= 10;
    				theInt += c - '0';
    				state = IN; //状态为在数字内
    				if (dot == true)
    					count *= 10.0;
    			}
    			if (c == '.') {
    				dot = true;
    				continue;
    			}
    		}
    		else{
    			dot = false;
    			double ans = theInt / count;			
    			count = 1.0;
    			if (state == IN) {
    				val.push(ans);
    				theInt = 0;
    			}
    			double x, y;
    			if (c != ' ') {
    				x = val.top();val.pop();
    				y = val.top();val.pop();
    
    				switch (c) {
    				case '+':val.push(x + y); break;
    				case '-':val.push(y - x); break;
    				case '*':val.push(x * y); break;
    				case '/':val.push(y / x); break;
    				default:cout << "未知的错误!" << endl;
    				}
    			}
    			state = OUT;
    		}
    	}
    	return true;
    }
    int Judge_rectangle(string& theStr)
    {
    	string str1 = "sin";
    	string str2 = "cos";
    	string str3 = "tan";
    	string str4 = "arcsin";
    	string str5 = "arccos";
    	string str6 = "arctan";
    	const char* show1, *show2, *show3, *show4, *show5, *show6;
    	show4 = strstr(theStr.c_str(), str4.c_str());
    	if (show4 != NULL)
    		return 4;
    	show5 = strstr(theStr.c_str(), str5.c_str());
    	if (show5 != NULL)
    		return 5;
    	show6 = strstr(theStr.c_str(), str6.c_str());
    	if (show6 != NULL)
    		return 6;	
    	show1 = strstr(theStr.c_str(), str1.c_str());
    	if (show1 != NULL)
    		return 1;
    	show2 = strstr(theStr.c_str(), str2.c_str());
    	if (show2 != NULL)
    		return 2;
    	show3 = strstr(theStr.c_str(), str3.c_str());
    	if (show3 != NULL)
    		return 3;
    	return 0;
    }
    
    /*求三角函数里包含的数字并求出对应的结果*/
    double cal_rect_number(string& theStr, int theInt)
    {
    	int number = 0;
    	for (int i = 0; theStr[i] != ')'; i++)
    	{
    		if (isdigit(theStr[i])) {
    			number *= 10;
    			number += theStr[i] - '0';
    		}
    	}
    	double ans = 0.0;
    	switch (theInt)
    	{
    	case 1:ans = sin(number); break;
    	case 2:ans = cos(number); break;
    	case 3:ans = tan(number); break;
    	case 4:ans = asin(number); break;
    	case 5:ans = acos(number); break;
    	case 6:ans = atan(number); break;
    	default:return 0;
    		break;
    	}
    	return ans;
    }
    
    /*判断是否为求阶乘*/
    bool Judge_factorial(string& theStr)
    {
    	int len = theStr.length();
    	for (int i = 0; i < len; i++)
    		if (theStr[i] == '!')
    			return true;
    	return false;
    }
    
    /*求阶乘所求的数字*/
    int cal_factorial_number(string& theStr)
    {
    	int number = 0;
    	for (int i = 0; theStr[i] != '!'; i++)
    	{
    		if (isdigit(theStr[i])) {
    			number *= 10;
    			number += theStr[i] - '0';
    		}
    	}
    	return  number;
    }
    
    /*利用数组求阶乘*/
    int cal_factorial(int theInt)
    {
    	LargeNumberFactorial[0] = 1;
    	LargeNumberFactorial[1] = 1;
    	int digit = 1;
    	for (int i = 1; i <= theInt; i++)
    	{
    		for (int j = 1; j <= digit; j++)
    		{
    			LargeNumberFactorial[j] *= i;
    		}
    		for (int j = 1; j <= digit; j++)
    		{
    			if (LargeNumberFactorial[j] > 10)
    			{
    				for (int k = 1; k <= digit; k++)
    				{
    					if (LargeNumberFactorial[digit] > 9)
    						digit++;
    					LargeNumberFactorial[k + 1] += LargeNumberFactorial[k] / 10;
    					LargeNumberFactorial[k] %= 10;
    				}
    			}
    		}
    	}
    	return digit;
    }
    public:
    int COUNTER(){
        getline(cin,formula);
        //判断是否三角函数和反三角函数并求值
		if(Judge_rectangle(formula) != 0) {		
			double res = 0;
			res = cal_rect_number(formula, Judge_rectangle(formula));
			if (res)
				cout << "结果为: " << fixed << setprecision(9) << res << endl;
		}

		//求阶乘的情况
		else if (Judge_factorial(formula)) {
			int n = cal_factorial_number(formula);
			cout << "结果为: ";
			for (int i = cal_factorial(n); i > 0; i--)
				cout << LargeNumberFactorial[i];
			cout << endl;
		}

		//是加减乘除的情况
		else{
			while (!opt.empty()) {
				opt.pop();
			}
			while (!val.empty()) {
				val.pop();
			}
			del_space(formula);//去除空格
			string cng_exp;
			cng_exp.clear();
			change(formula, cng_exp);	//转换为后缀表达式
			compute(cng_exp);//计算后缀表达式
			double stdans = val.top();
			cout << "结果为:" << (double)stdans << endl;
		}
        return 0;
    }
};
class CONFIGEXE{
    private:
    void help(){
        PRINT_HELP(printf("==========================CONFIG=============================\n"),
                    printf("==============================================================\n"))
            {
                print("CONFIG -a ac                             用户信息");
                print("CONFIG -a cpu                            cpu信息");
                print("CONFIG -a disk                           磁盘信息");
                print("CONFIG -a kb                             键盘信息");
                print("CONFIG -a ms                             鼠标信息");
                print("CONFIG -a usb                            usb接口信息");
                print("CONFIG -h help                           帮助。");
            }
    }
    void ac(){
        PRINT_HELP(printf("==========================Computer=============================\n"),
                    printf("================================================================\n"))
            {
                cout<<"ip："<<hard.ac->ip<<endl;
                cout<<"UUID："<<hard.ac->UUID<<endl;
                cout<<"显示名称："<<hard.ac->showname<<endl;
                cout<<"用户名称："<<hard.ac->username<<endl;
                cout<<"版权："<<hard.ac->Aboutcopyright<<endl;
                cout<<"版本："<<hard.ac->Version<<endl;
                cout<<"描述："<<hard.ac->text<<endl;
            }
    }
    void aboutcpu(){
        PRINT_HELP(printf("==========================CPU=============================\n"),
                    printf("============================================================\n"))
            {
                cout<<"名称："<<hard.cpus->cpuname<<endl;
                cout<<"显示名称："<<hard.cpus->showname<<endl;
                cout<<"长名称："<<hard.cpus->longName<<endl;
                cout<<"短名称："<<hard.cpus->shortName<<endl;
                cout<<"驱动名称："<<hard.cpus->divname<<endl;
                cout<<"UUID："<<hard.cpus->UUID<<endl;
                cout<<"总内存："<<hard.cpus->cpumem<<endl;
                cout<<"虚拟内存："<<hard.cpus->Virtmem<<endl;
                cout<<"硬件占用内存："<<hard.cpus->hardwareUse<<endl;
                cout<<"保护内存："<<hard.cpus->protect<<endl;
                cout<<"可用内存："<<hard.cpus->canuse<<endl;
                cout<<"核心数："<<hard.cpus->cpuKernelNum<<endl;
                cout<<"线程上限："<<hard.cpus->ThreadMax<<endl;
                cout<<"制造商："<<hard.cpus->mker<<endl;
                cout<<"驱动程序路径："<<hard.cpus->FilePath<<endl;
                cout<<"安装时间："<<hard.cpus->date<<endl;
                cout<<"是否为系统："<<hard.cpus->issys<<endl;
                cout<<"是否可删除："<<hard.cpus->canDel<<endl;
                cout<<"备注："<<hard.cpus->text<<endl;
            }
    }

    void _adisk(){
        system("clear");
         PRINT_HELP(printf("==========================DISK=============================\n"),
                    printf("==============================================================\n"))
            {
                cout<<"数量："<<hard.disk->DiskNum<<endl;
                cout<<"总内存："<<hard.disk->AllMem<<endl;
                PRINT_HELP(printf("==========================C:=============================\n"),
                    printf("==============================================================\n"))
                {
                    cout<<"名称："<<hard.disk->disk1.name<<endl;
                    cout<<"显示名称："<<hard.disk->disk1.showName<<endl;
                    cout<<"长名称："<<hard.disk->disk1.longName<<endl;
                    cout<<"短名称："<<hard.disk->disk1.shortName<<endl;
                    cout<<"分区类型："<<hard.disk->disk1.PartType<<endl;
                    cout<<"状态：\033[92m"<<hard.disk->disk1.state<<"\033[0m"<<endl;
                    cout<<"UUID："<<hard.disk->disk1.UUID<<endl;
                    cout<<"驱动名称："<<hard.disk->disk1.divName<<endl;
                    cout<<"磁盘空间（byte）："<<hard.disk->disk1.DiskMem<<endl;
                    cout<<"保护空间（byte）："<<hard.disk->disk1.protectMem<<endl;
                    cout<<"制造商："<<hard.disk->disk1.mker<<endl;
                    cout<<"驱动路径："<<hard.disk->disk1.FilePath<<endl;
                    cout<<"安装时间："<<hard.disk->disk1.date<<endl;
                    cout<<"是否为系统："<<hard.disk->disk1.issys<<endl;
                    cout<<"是否为启动盘："<<hard.disk->disk1.isopen<<endl;
                    cout<<"是否可删除："<<hard.disk->disk1.canDel<<endl;
                    cout<<"备注："<<hard.disk->disk1.text<<endl;
                }
                PRINT_HELP(printf("==========================E:=============================\n"),
                    printf("==============================================================\n"))
                {
                    cout<<"名称："<<hard.disk->disk2.name<<endl;
                    cout<<"显示名称："<<hard.disk->disk2.showName<<endl;
                    cout<<"长名称："<<hard.disk->disk2.longName<<endl;
                    cout<<"短名称："<<hard.disk->disk2.shortName<<endl;
                    cout<<"分区类型："<<hard.disk->disk2.PartType<<endl;
                    cout<<"状态：\033[92m"<<hard.disk->disk2.state<<"\033[0m"<<endl;
                    cout<<"UUID："<<hard.disk->disk2.UUID<<endl;
                    cout<<"驱动名称："<<hard.disk->disk2.divName<<endl;
                    cout<<"磁盘空间（byte）："<<hard.disk->disk2.DiskMem<<endl;
                    cout<<"保护空间（byte）："<<hard.disk->disk2.protectMem<<endl;
                    cout<<"制造商："<<hard.disk->disk2.mker<<endl;
                    cout<<"驱动路径："<<hard.disk->disk2.FilePath<<endl;
                    cout<<"安装时间："<<hard.disk->disk2.date<<endl;
                    cout<<"是否为系统："<<hard.disk->disk2.issys<<endl;
                    cout<<"是否为启动盘："<<hard.disk->disk2.isopen<<endl;
                    cout<<"是否可删除："<<hard.disk->disk2.canDel<<endl;
                    cout<<"备注："<<hard.disk->disk2.text<<endl;
                }
                PRINT_HELP(printf("==========================F:=============================\n"),
                    printf("==============================================================\n"))
                {
                    cout<<"名称："<<hard.disk->disk3.name<<endl;
                    cout<<"显示名称："<<hard.disk->disk3.showName<<endl;
                    cout<<"长名称："<<hard.disk->disk3.longName<<endl;
                    cout<<"短名称："<<hard.disk->disk3.shortName<<endl;
                    cout<<"分区类型："<<hard.disk->disk3.PartType<<endl;
                    cout<<"状态：\033[92m"<<hard.disk->disk3.state<<"\033[0m"<<endl;
                    cout<<"UUID："<<hard.disk->disk3.UUID<<endl;
                    cout<<"驱动名称："<<hard.disk->disk3.divName<<endl;
                    cout<<"磁盘空间（byte）："<<hard.disk->disk3.DiskMem<<endl;
                    cout<<"保护空间（byte）："<<hard.disk->disk3.protectMem<<endl;
                    cout<<"制造商："<<hard.disk->disk3.mker<<endl;
                    cout<<"驱动路径："<<hard.disk->disk3.FilePath<<endl;
                    cout<<"安装时间："<<hard.disk->disk3.date<<endl;
                    cout<<"是否为系统："<<hard.disk->disk3.issys<<endl;
                    cout<<"是否为启动盘："<<hard.disk->disk3.isopen<<endl;
                    cout<<"是否可删除："<<hard.disk->disk3.canDel<<endl;
                    cout<<"备注："<<hard.disk->disk3.text<<endl;
                }
                PRINT_HELP(printf("==========================T:=============================\n"),
                    printf("==============================================================\n"))
                {
                    cout<<"名称："<<hard.disk->disk4.name<<endl;
                    cout<<"显示名称："<<hard.disk->disk4.showName<<endl;
                    cout<<"长名称："<<hard.disk->disk4.longName<<endl;
                    cout<<"短名称："<<hard.disk->disk4.shortName<<endl;
                    cout<<"分区类型："<<hard.disk->disk4.PartType<<endl;
                    cout<<"状态：\033[92m"<<hard.disk->disk4.state<<"\033[0m"<<endl;
                    cout<<"UUID："<<hard.disk->disk4.UUID<<endl;
                    cout<<"驱动名称："<<hard.disk->disk4.divName<<endl;
                    cout<<"磁盘空间（byte）："<<hard.disk->disk4.DiskMem<<endl;
                    cout<<"保护空间（byte）："<<hard.disk->disk4.protectMem<<endl;
                    cout<<"制造商："<<hard.disk->disk4.mker<<endl;
                    cout<<"驱动路径："<<hard.disk->disk4.FilePath<<endl;
                    cout<<"安装时间："<<hard.disk->disk4.date<<endl;
                    cout<<"是否为系统："<<hard.disk->disk4.issys<<endl;
                    cout<<"是否为启动盘："<<hard.disk->disk4.isopen<<endl;
                    cout<<"是否可删除："<<hard.disk->disk4.canDel<<endl;
                    cout<<"备注："<<hard.disk->disk4.text<<endl;
                }
            }
            cout<<"按任意键退出"<<endl;
            string tmp;
            cin>>tmp;
            system("clear");
    }
    void _kb(){
        PRINT_HELP(printf("==========================KeyBoard=============================\n"),
                    printf("============================================================\n"))
            {
                cout<<"名称："<<hard.kb->kbname<<endl;
                cout<<"显示名称："<<hard.kb->showname<<endl;
                cout<<"长名称："<<hard.kb->longName<<endl;
                cout<<"短名称："<<hard.kb->shortName<<endl;
                cout<<"驱动名称："<<hard.kb->divname<<endl;
                cout<<"UUID："<<hard.kb->UUID<<endl;
                cout<<"制造商："<<hard.kb->mker<<endl;
                cout<<"驱动程序路径："<<hard.kb->FilePath<<endl;
                cout<<"安装时间："<<hard.kb->date<<endl;
                cout<<"是否为系统："<<hard.kb->issys<<endl;
                cout<<"是否可删除："<<hard.kb->canDel<<endl;
                cout<<"备注："<<hard.kb->text<<endl;
            }
    }
    void _ms(){
        PRINT_HELP(printf("==========================Mouse=============================\n"),
                    printf("============================================================\n"))
            {
                cout<<"名称："<<hard.ms->msname<<endl;
                cout<<"显示名称："<<hard.ms->showname<<endl;
                cout<<"长名称："<<hard.ms->longName<<endl;
                cout<<"短名称："<<hard.ms->shortName<<endl;
                cout<<"驱动名称："<<hard.ms->divname<<endl;
                cout<<"UUID："<<hard.ms->UUID<<endl;
                cout<<"制造商："<<hard.ms->mker<<endl;
                cout<<"驱动程序路径："<<hard.ms->FilePath<<endl;
                cout<<"安装时间："<<hard.ms->date<<endl;
                cout<<"是否为系统："<<hard.ms->issys<<endl;
                cout<<"是否可删除："<<hard.ms->canDel<<endl;
                cout<<"备注："<<hard.ms->text<<endl;
            }
    }
    void _usb(){
        PRINT_HELP(printf("==========================USB=============================\n"),
                    printf("============================================================\n"))
            {
                cout<<"名称："<<hard.usb->USBname<<endl;
                cout<<"显示名称："<<hard.usb->showname<<endl;
                cout<<"长名称："<<hard.usb->longName<<endl;
                cout<<"短名称："<<hard.usb->shortName<<endl;
                cout<<"驱动名称："<<hard.usb->divname<<endl;
                cout<<"内存范围："<<hard.usb->USBmemLow<<"~"<<hard.usb->USBmemHigh<<endl;
                cout<<"UUID："<<hard.usb->UUID<<endl;
                cout<<"制造商："<<hard.usb->mker<<endl;
                cout<<"驱动程序路径："<<hard.usb->FilePath<<endl;
                cout<<"安装时间："<<hard.usb->date<<endl;
                cout<<"是否为系统："<<hard.usb->issys<<endl;
                cout<<"是否可删除："<<hard.usb->canDel<<endl;
                cout<<"备注："<<hard.usb->text<<endl;
            }
    }
    void _a(string argv2){
        if(argv2 == "ac"){
            ac();
        }
        else if(argv2 == "cpu"){
            aboutcpu();
        }
        else if(argv2 == "disk"){
            _adisk();
        }
        else if(argv2 == "usb"){
            _usb();
        }
        else if(argv2 == "kb"){
            _kb();
        }
        else if(argv2 == "ms"){
            _ms();
        }
    }
    public:
    int CONFIG(const char* argv1, const char* argv2){
        if(argv1[0] != '-')
        {
            pterr(argv1, "格式不符合要求");
            help();
            return -1;
        }
        switch(argv1[1])
        {
            case 'a':
                _a(argv2);
            break;
            case 'h':
                help();
            break;
            case 'r':
            break;
            default:
                help();
                printf("您所输入的指令有问题，请重新输入.\n");
            break;
        }
        return 0;
    }
};
void Date(){
    time_t t;
    tm *local;
    char buf[128] = {0};
    t = time(NULL);
    local = localtime(&t);
    strftime(buf, 64, "%Y-%m-%d %H:%M:%S", local);
    cout<<buf<<endl;
}
#define MAXMEMNAME 1
#define MAXMEMCHAR " "
/*DISK命令没啥用了*/
#if (0)
class DISKEXE : 
            public forDisk
{
    private:
    CProgress pro;
    int tmp;
    void help(){
        PRINT_HELP(printf("==========================DISK==============================\n"),
                    printf("============================================================\n"))
            {
                print("DISK -a [磁盘名|磁盘名]&[所需空间]       重新分配磁盘空间。");
                print("DISK -b [磁盘名]                         格式化磁盘。");
                print("DISK -d [磁盘名]                         清空磁盘分区。");
                print("DISK -s show                             查看磁盘空间使用情况。");
                print("DISK -h help                             帮助。");
                print("DISK -r return                           恢复出厂设置");
            }
    }
    bool split_and(string argv, string &diskname, string &needmem)
    {
        bool hasAnd = false;
        for(int i = 0; i <= argv.length(); i ++)
        {
            if(argv[i] == '&'){
                hasAnd = true;
                continue;
            }
            if(!hasAnd){
                diskname[i] = argv[i];
                continue;
            }
            for(int j = 0; argv[i] != '\0'; i ++, j ++)
            {
                needmem[j] = argv[i];
            }
        }
        return hasAnd;
    }
    bool split_or(string diskname, string &Disk1, string &Disk2)
    {
        bool hasOr = false;
        for(int i = 0; i <= diskname.length(); i ++)
        {
            if(diskname[i] == '|'){
                hasOr = true;
                continue;
            }
            if(!hasOr){
                Disk1[i] = diskname[i];
                continue;
            }
            for(int j = 0; diskname[i] != '\0'; i ++, j ++)
            {
                Disk2[j] = diskname[i];
            }
        }
        return hasOr;
    }
    void _show_DK()
    {
        printf("C:\n");
        pro.progress(Mainmem, fsys->C_init_.length() / 8);
        printf("%s:\n", ExDk1Name.c_str());
        pro.progress(ExDk1mem, fsys->E_init_.length() / 8);
    }
    void _show_DKS()
    {
        printf("C:\n");
        pro.progress(Mainmem, (fsys->C_init_.length() / 8));
        printf("%s:\n", ExDk1Name.c_str());
        pro.progress(ExDk1mem, (fsys->E_init_.length() / 8));
        printf("%s:\n", ExDk2Name.c_str());
        pro.progress(ExDk2mem, (fsys->F_init_.length() / 8));
    }
    void _show()
    {
        if(ExDkNumber == 1)
        {
            _show_DK();
        }
        if(ExDkNumber == 2)
        {
            _show_DKS();
        }
    }
    int show(string argv)
    {
        if(argv != "show")
        {
            return -1;
        }
        _show();
        return 0;
    }
    int DeleteMem(string DiskName)
    {
        if(DiskName == "C" || DiskName == "c")
        {
            return -1;
        }
        if(DiskName == ExDk1Name)
        {
            int tmpi;
            CHECK("是否清除？", "1", "2")
            cin >>tmpi;
            if(tmpi == 1)
            {
                ExDk1memSurplus = 0;
                fsys->E_init_ = "";
                return 1;
            }
        }
        if(DiskName == ExDk2Name)
        {
             int tmpi;
            CHECK("是否清除？", "1", "2")
            cin >>tmpi;
            if(tmpi == 1)
            {
                ExDk2memSurplus = 0;
                fsys->F_init_ = "";
                return 1;
            }
        }
        return 0;
    }
    public:
    int DISK(const char* argv1, const char* argv2){
        if(argv1[0] != '-')
        {
            pterr(argv1, "格式不符合要求");
            help();
            return -1;
        }
        switch(argv1[1])
        {
            case 'a':
            break;
            case 'b':
                CHECK("确定格式化？", "1", "2")
                int temps;
                cin >> temps;
                if(temps == 1)
                {
                    tmp = DeleteMem(argv2);
                    if(tmp == -1)
                    {
                        cout<<"不能清空该硬盘内容，格式化失败"<<endl;
                    }
                    else{
                        cout << "已完成" << endl;
                    }
                }
                else{
                    cout<<"已取消格式化"<<endl;
                }
            break;
            case 'd':
                tmp = DeleteMem(argv2);
                if(tmp == -1)
                {
                    cout<<"不能清空该硬盘内容"<<endl;
                }
            break;
            case 's':
                tmp = show(argv2);
                if(tmp == -1)
                {
                    pterr(argv2, "应该为show");
                }
                if(tmp == 1)
                {
                    cout<<"\033[92m清除成功!\033[0m"<<endl;
                }
            break;
            case 'h':
                help();
            break;
            case 'r':
            break;
            default:
                help();
                printf("您所输入的指令有问题，请重新输入.\n");
            break;
        }
        return 0;
    }
};
#endif
int FindFile(const char* file)
{
    if((access(file,0)) != -1)
    {
        printf("File %s exists.", file);
        return 1;
    }
    return 0;
}
//GetIP
void parseHostAndPagePath(const string Url, string &hostUrl, string &pagePath){
    hostUrl=Url;
    pagePath="/";
    int pos=hostUrl.find("http://");
    if(-1!=pos)
        hostUrl=hostUrl.replace(pos,7,"");
    pos=hostUrl.find("https://");
    if(-1!=pos)
        hostUrl=hostUrl.replace(pos,8,"");
    pos=hostUrl.find("/");
    if(-1!=pos){
        pagePath=hostUrl.substr(pos);
        hostUrl=hostUrl.substr(0,pos);
    }
}
 
string GSCer(const string Url){
    struct hostent *host;
    string hostUrl, pagePath;
    parseHostAndPagePath(Url, hostUrl, pagePath);
    if(0==(host=gethostbyname(hostUrl.c_str()))){
        cout<<"gethostbyname error\n"<<endl;
        exit(1);
    }
 
    struct sockaddr_in pin;
    int port=80;
    bzero(&pin,sizeof(pin));
    pin.sin_family=AF_INET;
    pin.sin_port=htons(port);
    pin.sin_addr.s_addr=((struct in_addr*)(host->h_addr))->s_addr;
    int isock;
    if((isock = socket(AF_INET, SOCK_STREAM, 0))==-1){
        cout<<"open socket error\n"<<endl;
        exit(1);
    }
 
    string requestHeader;
    requestHeader="GET "+pagePath+" HTTP/1.1\r\n";
    requestHeader+="Host: "+hostUrl+"\r\n";
    requestHeader+="Accept: */*\r\n";
    requestHeader+="User-Agent: Mozilla/4.0(compatible)\r\n";
    requestHeader+="connection:Keep-Alive\r\n";
    requestHeader+="\r\n";
 
    if(connect(isock, (const sockaddr*)&pin, sizeof(pin))==-1){
        cout<<"connect error\n"<<endl;
        exit(1);
    }
    if(send(isock, requestHeader.c_str(), requestHeader.size(), 0)==-1){
        cout<<"send error\n"<<endl;
        exit(1);
    }
 
    struct timeval timeout={1,0};
    setsockopt(isock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(struct timeval));
    char c;
    bool flag=true;
    while(recv(isock, &c, 1, 0)>0){
        if('\r'==c){
            continue;
        }else if('\n'==c){
            if(false==flag)
                break;
            flag=false;
        }else{
            flag=true;
        }
    }
 
    int len, BUFFER_SIZE=512;
    char buffer[BUFFER_SIZE];
    string pageContent="";
    while((len = recv(isock, buffer, BUFFER_SIZE-1, 0))>0){
        buffer[len]='\0';
        pageContent+=buffer;
    }
 
    return pageContent;
}
void GetIPer(const char* hostname){
    struct hostent *h;
    if((h = gethostbyname(hostname)) == NULL){
        pterr(hostname, "无法得到IP！");
        return;
    }
    cout<<"HostName:"<<h->h_name<<endl;
    printf("IP Address:%s\n", inet_ntoa(*((struct in_addr*)h->h_addr)));
}
class GTEXE{
    protected:
    
    public:
};

class HILLEXE{
    private:
    static const int MAX = 60;
    int K1[2][2] = {0}, K2[2][2] = {0};
    int temp1[2] = {0}, temp2[2] = {0};
    char text[MAX] = {0}, result[MAX] = {0};
    int T1[MAX] = {0}, T2[MAX] = {0};
    int len, flag = 0, temp, temps, i, j, num = 0;
    public:
    HILLEXE(){
        printf("欢迎使用Hill密码\n");
        cout<<"请填写文字（60个字符以内）"<<endl;
        cin>>text;
        cout<<"请选择加密（1）还是解密（2）"<<endl;
        cin>>num;
        cout<<"请输入秘钥（用空格分开的数组,横二竖二共四个数）\n";
        for(i = 0; i < 2; i++){
            for(j = 0; j < 2; j++){
                cin>>K1[i][j];
            }
        }
        if(num == 1){
            len = strlen(text);
            if(len % 2 == 1){
                text[len] = 'a';
                len = strlen(text);
                flag = 1;
            }
            for(i = 0; i < len; i ++){
                if(text[i] >= 'A' && text[i] <= 'Z'){
                    text[i] = text[i] + 32;
                }
                
                T1[i] = text[i] - 'a';
            }
            for(i = 0; i < len; i += 2){
                temp1[0] = T1[i];
                temp1[1] = T1[i + 1];
                //储存密文int值
                temp2[0] = (temp1[0] * K1[0][0] + temp1[i] * K1[1][0]) % 26;
                temp2[1] = (temp1[0] * K1[0][1] + temp1[i] * K1[1][1]) % 26;
                T2[i] = temp2[0];
                T2[i + 1] = temp2[1];
            }
            if(flag == 1)
                len = len - 1;
            for(i = 0; i < len; i++)
                result[i] = T2[i] + 'a';
            cout<<"明文"<<text<<"的密文为："<<result<<endl;
        } else if(num == 2){
            len = strlen(text);
            if(len % 2 == 1){
                text[len] = 'a';
                len = strlen(text);
                flag = 1;
            }
            for(i = 0; i < len; i ++){
                if(text[i] >= 'A' && text[i] <= 'Z'){
                    text[i] = text[i] + 32;
                }
                
                T1[i] = text[i] - 'a';
            }
            //K的逆
            temp = -1;
            for(i = 1; temp < 0; i++){
                temp = (K1[0][0] * K1[1][1] - K1[0][1] * K1[1][0]) + 26 * i;
            }
            i = 1;
            while(1){
                if((temp * i) % 26 == 1){
                    temps = i;
                    break;
                }
                i ++;
            }
            K2[0][0] = K1[1][1] * temps;
            K2[0][1] = (((-1 * K1[0][1]) + 26) * temps) % 26;
            K2[1][0] = (((-1 * K1[1][0]) + 26) * temps) % 26;
            K2[1][1] = K1[0][0] * temps;
            //得到解密结果后储存在T2中
            for(i = 0; i < len; i += 2){
                temp2[0] = T2[i];
                temp2[1] = T2[i + 1];
                //储存密文int值
                temp1[0] = (temp2[0] * K2[0][0] + temp2[i] * K2[1][0]) % 26;
                temp1[1] = (temp2[0] * K2[0][1] + temp2[i] * K2[1][1]) % 26;
                T1[i] = temp1[0];
                T1[i + 1] = temp1[1];
            }
            if(flag == 1)
                len = len - 1;
            for(i = 0; i < len; i++)
                result[i] = T1[i] + 'a';
            cout<<"密文"<<text<<"的明文为："<<result<<endl;
        }
    }
};
#define INSTALLMAX 3 //要添加插件或者软件的在这里添加
class INSTALLEXE
{
    private:
    string canInstall[INSTALLMAX] = {"Hill.adexe", "Virginia.adexe", "INET.adexe"};//这里也要添加
    void help(){
        PRINT_HELP(printf("==========================INSTALL==============================\n"),
                    printf("===============================================================\n"))
            {
                print("INSTALL -d [名称]                删除某个软件。");
                print("INSTALL -s [名称]                下载。");
                print("INSTALL -s show                  显示能下载的内容。");
            }
    }
    bool Delete(string argv){
        string tmpstrs = argv;
        transform(tmpstrs.begin(), tmpstrs.end(), tmpstrs.begin(), towlower);
        if((tmpstrs == "hill" || tmpstrs == "hill.adexe") && logn.Hill == true){
            logn.Hill = false;
            InsOrDel = false;
        }
        else if((tmpstrs == "virginia" || tmpstrs == "virginia.adexe") && logn.Virginia == true){
            logn.Virginia = false;
            InsOrDel = false;
        }
        else if((tmpstrs == "inet" || tmpstrs == "inet.adexe") && logn.Inet == true){
            logn.Inet = false;
            InsOrDel = false;
        }
        else{
            pterr(argv.c_str(), "不存在或者未下载！");
            return false;
        }
        cout<<"删除成功！"<<endl;
        return true;
    }
    bool showOrinstall(string argv){
        string tmpstrs = argv;
        transform(tmpstrs.begin(), tmpstrs.end(), tmpstrs.begin(), towlower);
        if(argv == "show"){
            for(int i = 0; i <= INSTALLMAX - 1; i ++){
                cout << canInstall[i] << endl;
            }
            return true;
        }
        if((tmpstrs == "hill" || tmpstrs == "hill.adexe") && logn.Hill != true){
            logn.Hill = true;
        }
        else if((tmpstrs == "virginia" || tmpstrs == "virginia.adexe") && logn.Virginia != true){
            logn.Virginia = true;
        }
        else if((tmpstrs == "inet" || tmpstrs == "inet.adexe") && logn.Inet != true){
            logn.Inet = true;
        }
        else{
            pterr(argv.c_str(), "不存在或者已下载过！");
            return false;
        }
        cout<<"下载成功！"<<endl;
        return true;
    }
    public:
    int INSTALL(const char* argv1, const char* argv2){
        if(argv1[0] != '-')
        {
            pterr(argv1, "格式不符合要求");
            help();
            return -1;
        }
        switch(argv1[1])
        {
            case 'd':
                Delete(argv2);
            break;
            case 's':
                showOrinstall(argv2);
            break;
            case 'h':
                help();
            break;
            default:
                help();
                printf("您所输入的指令有问题，请重新输入.\n");
            break;
        }
        return 0;
    }
};
struct AboutApp{
    string name;
    int PID;
    string beginmem;
    string endmem;
    string Virtmembegin;
    string Virtmemend;
    int appmem;
};
AboutApp _NullApp;
vector<AboutApp> appMem(50, _NullApp);
class MEMORYEXE{
    private:
    const string sysBegin = UUIDMem[0];
    const string sysEnd = UUIDMem[1439];
    const string sysVirtBegin = VirtUUID[0], sysVirtEnd = VirtUUID[959];
    const string UserMembegin = UUIDMem[1439], UserMemend = UUIDMem[8703];
    int appNum = 0;
    MemMessage msgtmp;
    AboutApp abtmp;
    void init(){
        for(vector<MemMessage>::reverse_iterator it = SysMemMsg.rbegin(); it != SysMemMsg.rend(); ++it){
            if(it->memName != _NullMsg.memName){
                msgtmp = *it;
                appMem[appNum].name = msgtmp.memName;
                appMem[appNum].PID = msgtmp.PID;
                appMem[appNum].beginmem = UUIDMem[msgtmp.addr];
                appMem[appNum].endmem = UUIDMem[msgtmp.addr + msgtmp.Usrmem];
                appMem[appNum].Virtmembegin = VirtUUID[msgtmp.Virtaddr];
                appMem[appNum].Virtmemend = VirtUUID[msgtmp.Virtaddr + msgtmp.VirtMem];
                ++appNum;
                continue;
            }
            break;
        }
        for(vector<AboutApp>::reverse_iterator it = appMem.rbegin(); it != appMem.rend(); ++it){
            abtmp = *it;
            if(abtmp.name == _NullApp.name){
                appMem.pop_back();
            }
        }
    }
    void show(){
        int size = appMem.size();
        cout<<"共有"<<size<<"个进程/线程正在运行"<<endl;
        cout<<"序号"<<" 名称"<<"     "<<"PID"<<"     "<<"内存占用"<<"                           "<<"虚拟内存占用"<<endl;
        int i = 1;
        for(vector<AboutApp>::iterator it = appMem.begin(); it <= appMem.end() - 1; it++, i ++){
            cout<<i<<". "<<it->name<<"     "<<it->PID<<"     "<<it->beginmem<<"~"<<it->endmem<<"   "<<it->Virtmembegin<<"~"<<it->Virtmemend<<endl;
        }
    }
    public:
    MEMORYEXE(){
        init();
        show();
    }
};

/*Ping 拷贝自https://www.cnblogs.com/ggjucheng/archive/2012/02/17/2355564.html*/
#define PACKET_SIZE 4096
#define MAX_WAIT_SIZE 5
#define MAX_NO_PACKETS 3
struct IcmpEchoReply{
    int icmpSeq;
    int icmpLen;
    int ipTtl;
    double rtt;
    string fromAddr;
    bool isReply;
};
struct PingResult{
    int dataLen;
    int nsend;
    int nreceived;
    string ip;
    string error;
    vector<IcmpEchoReply> IcmpEchoReplys;
};
class Ping{
    public:
        Ping(void)
            : m_maxPacketSize(4),
              m_datalen(56),
              m_nsend(0),
              m_nreceived(0),
              m_icmp_seq(0)
        {}
        int useping(){
            string hostorip;
            cin>>hostorip;
            int nsend = 0, nreceived = 0;
            bool ret;
            PingResult pingResult;
            for(int count = 1; count < 4; count++){
                ret = ping(hostorip, 1, pingResult);
                if(count == 1){
                    printf("PING %s(%s): %d bytes data in ICMP packets.\n", hostorip.c_str(), pingResult.ip.c_str(),
                                                                            pingResult.dataLen);
                }
                if(!ret){
                    printf("%s\n",pingResult.error.c_str());
                    break;
                }
                show(pingResult);
                nsend += pingResult.nsend;
                nreceived += pingResult.nreceived;
            }
            if(ret){
                printf("%d packets transmitted, %d received, %%%d lost\n", nsend, nreceived,
                    (nsend - nreceived) / nsend * 100);
            }
            return 0;
        }
    private:
        void show(PingResult pingResult){
            for(unsigned int i = 0; i < pingResult.IcmpEchoReplys.size(); i ++){
                IcmpEchoReply icmpEchoReply = pingResult.IcmpEchoReplys.at(i);
                if(icmpEchoReply.isReply){
                    printf("%d byte from %s: icmp_swq=%u ttl=%d rtt=%.3f ms\n",
                            icmpEchoReply.icmpLen,
                            icmpEchoReply.fromAddr.c_str(),
                            icmpEchoReply.icmpSeq,
                            icmpEchoReply.ipTtl,
                            icmpEchoReply.rtt);
                } else {
                    printf("request timeout\n");
                }
            }
        }
        bool ping(string host, PingResult &pingResult){
            return ping(host, 1, pingResult);
        }
        bool ping(string host, int count, PingResult &pingResult){
            struct protoent *protocol;
            int size = 50 * 1024;
            IcmpEchoReply icmpEchoReply;
            bool ret;
            
            m_nsend = 0;
            m_nreceived = 0;
            pingResult.IcmpEchoReplys.clear();
            m_maxPacketSize = count;
            m_pid = getpid();
            
            pingResult.dataLen = m_datalen;
            
            if((protocol = getprotobyname("icmp")) == NULL){
                perror("getprotobyname");
                return false;
            }
            /*生成使用ICMP的原始套接字，这种套接字只有root才能生成*/
            if((m_sockfd = socket(AF_INET, SOCK_RAW, protocol->p_proto)) < 0){
                extern int errno;
                pingResult.error = strerror(errno);
                return false;
            }
            /*扩大套接字接收缓冲区到50kb这样做主要为了减小接收缓冲区溢出的可能性，
            若无意中ping一个广播地址或多播地址，将会引来大量应答*/
            setsockopt(m_sockfd, SOL_SOCKET, SO_RCVBUF, &size, sizeof(size));
            /*获取main的进程id，用于设置ICMP的标志符*/
            if(!getsockaddr(host.c_str(), &m_dest_addr)){
                pingResult.error = "unknow host" + host;
                return false;
            }
            pingResult.ip = inet_ntoa(m_dest_addr.sin_addr);
            sendPacket(); /*发送所有ICMP报文*/
            recvPacket(pingResult); /*接收所有ICMP报文*/
            pingResult.nsend = m_nsend;
            pingResult.nreceived = m_nreceived;
            close(m_sockfd);
            return true;
        }
    private:
        /*校验和算法*/
        unsigned short getChksum(unsigned short *addr, int len){
            int nleft = len;
            int sum = 0;
            unsigned short *w = addr;
            unsigned short answer = 0;
            /*把ICMP报头二进制数据以2字节为单位累加起来*/
            while(nleft>1){
                sum+=*w++;
                nleft -= 2;
            }
            /*若ICMP报头为奇数个字节，会剩下最后一字节，把最后一个字节视为一个2字节的数据的高子杰，这个2字节数据的低字节为0，继续累加*/
            if(nleft == 1){
                *(unsigned char*)(&answer) = *(unsigned char*)w;
                sum += answer;
            }
            sum = (sum>>16)+(sum&0xffff);
            sum += (sum>>16);
            answer = ~sum;
            return answer;
        }
        /*设置ICMP报头*/
        int packIcmp(int pack_no, struct icmp *icmp){
            int i, packsize;
            struct icmp *picmp;
            struct timeval *tval;
            
            picmp = icmp;
            picmp->icmp_type = ICMP_ECHO;
            picmp->icmp_code = 0;
            picmp->icmp_cksum = 0;
            picmp->icmp_seq = pack_no;
            picmp->icmp_id = m_pid;
            packsize = 8 + m_datalen;
            tval = (struct timeval *)icmp->icmp_data;
            gettimeofday(tval, NULL); /*记录发送时间*/
            picmp->icmp_cksum = getChksum((unsigned short*)icmp, packsize); //校验算法
            return packsize;
        }
        /*剥去ICMP报头*/
        bool unpackIcmp(char* buf, int len, struct IcmpEchoReply *icmpEchoReply){
            int i, iphdrlen;
            struct ip *ip;
            struct icmp *icmp;
            struct timeval *tvsend, tvrecv, tvresult;
            double rtt;
            
            ip = (struct ip*)buf;
            iphdrlen = ip->ip_hl << 2; /*求ip报头长度，即ip报头的长度标志×4*/
            icmp = (struct icmp *)(buf + iphdrlen); /*越过ip报头，指向ICMP报头*/
            len -= iphdrlen; /*ICMP报头及ICMP数据报的总长度*/
            if(len < 8){
                printf("ICMP packets\'s length is less than 8\n");
                return false;
            }   
            /*确保所接受的是我所发的的ICMP的回应*/
            if((icmp->icmp_type == ICMP_ECHOREPLY) && (icmp->icmp_id == m_pid)){
                tvsend = (struct timeval *)icmp->icmp_data;
                gettimeofday(&tvrecv, NULL); /*记录接收时间*/
                tvresult = tvSub(tvrecv, *tvsend); /*接收和发送的时间差*/
                rtt = tvresult.tv_sec * 1000 + tvresult.tv_usec / 1000; /*以毫秒为单位计算rtt*/
                icmpEchoReply->rtt = rtt;
                icmpEchoReply->icmpSeq = icmp->icmp_seq;
                icmpEchoReply->ipTtl = ip->ip_ttl;
                icmpEchoReply->icmpLen = len;
                return true;
            }
            return false;
        }
        /*两个timeval结构相减*/
        struct timeval tvSub(struct timeval timeval1, struct timeval timeval2){
            struct timeval result;
            result = timeval1;
            if(result.tv_usec < timeval2.tv_usec && result.tv_usec < 0 && timeval2.tv_usec < 0){
                --result.tv_sec;
                result.tv_usec += 1000000;
            }
            result.tv_sec -= timeval2.tv_sec;
            return result;
        }
        bool getsockaddr(const char* hostOrIp, sockaddr_in* sockaddr){
            struct hostent *host;
            struct sockaddr_in dest_addr;
            unsigned long inaddr = 0l;
            bzero(&dest_addr, sizeof(dest_addr));
            dest_addr.sin_family = AF_INET;
            /*判断是主机名还是ip名*/
            if((inaddr = inet_addr(hostOrIp)) == INADDR_NONE){
                if((host = gethostbyname(hostOrIp)) == NULL)/*是主机名*/{
                    return false;
                }
                memcpy((char*)&dest_addr.sin_addr, host->h_addr, host->h_length);
            }
            /*是IP地址*/
            else if(!inet_aton(hostOrIp, &dest_addr.sin_addr)){
                return false;
            }
            *sockaddr = dest_addr;
            return true;
        }
        /*发送三个ICMP报文*/
        bool sendPacket(void){
            size_t packetsize;
            while(m_nsend < m_maxPacketSize){
                m_nsend ++;
                m_icmp_seq ++;
                packetsize = packIcmp(m_icmp_seq, (struct icmp *)m_sendpacket); /*设置ICMP报头*/
                
                if(sendto(m_sockfd, m_sendpacket, packetsize, 0, (struct sockaddr *) &m_dest_addr, sizeof(m_dest_addr)) < 0){
                    perror("sendto error");
                    continue;
                }
            }
            return true;
        }
        /*接受所有ICMP报文*/
        bool recvPacket(PingResult &pingResult){
            int len;
            extern int errno;
            struct IcmpEchoReply icmpEchoReply;
            int maxfds = m_sockfd + 1;
            int nfd = 0;
            fd_set rset;
            FD_ZERO(&rset);
            socklen_t fromlen = sizeof(m_from_addr);
            struct timeval timeout;
            timeout.tv_sec = 4;
            timeout.tv_usec = 0;
            
            for(int recvCount = 0; recvCount < m_maxPacketSize; recvCount++){
                FD_SET(m_sockfd, &rset);
                if((nfd = select(maxfds, &rset, NULL, NULL, &timeout)) == -1){
                    perror("select error");
                    continue;
                }
                if(nfd == 0){
                    icmpEchoReply.isReply = false;
                    pingResult.IcmpEchoReplys.push_back(icmpEchoReply);
                    continue;
                }
                if(FD_ISSET(m_sockfd, &rset)){
                    if((len = recvfrom(m_sockfd, m_recvpacket, sizeof(m_recvpacket), 0, (struct sockaddr *)&m_from_addr, &fromlen)) < 0){
                        if(errno == EINTR)
                            continue;
                        perror("recvfrom error");
                        continue;
                    }
                    icmpEchoReply.fromAddr = inet_ntoa(m_from_addr.sin_addr);
                    if(icmpEchoReply.fromAddr != pingResult.ip){
                        recvCount--;
                        continue;
                    }
                }
                if(unpackIcmp(m_recvpacket, len, &icmpEchoReply) == false){
                    recvCount--;
                    continue;
                }
                icmpEchoReply.isReply = true;
                pingResult.IcmpEchoReplys.push_back(icmpEchoReply);
                m_nreceived++;
            }
            return true;
        }
    private:
        char m_sendpacket[PACKET_SIZE];
        char m_recvpacket[PACKET_SIZE];
        int m_maxPacketSize;
        int m_sockfd;
        int m_datalen;
        int m_nsend;
        int m_nreceived;
        int m_icmp_seq;
        struct sockaddr_in m_dest_addr;
        struct sockaddr_in m_from_addr;
        pid_t m_pid;
};
class VIRGINIAEXE
{
    private:
#define MINCHAR 32
#define CHARSUM 94
    char table[CHARSUM][CHARSUM];
    //初始化维吉尼亚方阵
    bool Init()
    {
        for(int i = 0; i < CHARSUM; i ++)
        {
            for(int j = 0; j < CHARSUM; j ++)
            {
                table[i][j] = MINCHAR + (i + j) % CHARSUM;
            }
        }
        return true;
    }
    //加密
    bool Encode(char* key, char* source, char* dest)
    {
        char* tempSource = source;
        char* tempKey = key;
        char* tempDest = dest;
        do{
            *tempDest = table[(*tempKey) - MINCHAR][(*tempSource) - MINCHAR];
            tempDest++;
            if(!(*(++tempKey)))
                tempKey = key;
        }while(*tempSource++);
        dest[strlen(source)] = 0;
        return true;
    }
    //解密
    bool Dncode(char* key, char* source, char* dest)
    {
        char* tempSource = source;
        char* tempKey = key;
        char* tempDest = dest;
        char offset;
        do{
            offset = (*tempSource) - (*tempKey);
            offset = offset >- 0 ? offset : offset + CHARSUM;
            *tempDest = MINCHAR + offset;
            tempDest++;
            if(!(*(++tempKey)))
                tempKey = key;
        }while(*++tempSource);
        dest[strlen(source)] = 0;
        return true;
    }
    public:
    int VIRGINIA()
    {
        if(!Init())
        {
            cout<<"初始化错误!"<<endl;
            return 1;
        }
        char key[256];
        char str1[256];
        char str2[256];
        int operation;
        while(1)
        {
            do
            {
                PRINT_HELP(printf("==========请选择一个操作==========\n"),
                    printf("==================================\n"))
                {
                    print("1.加密");
                    print("2.解密");
                    print("-1.退出");
                }
                cin>>operation;
            }while(operation != -1 && operation != 1 && operation != 2);
            if(operation == -1)
                return 0;
            else if(operation == 1){
                cout<<"请输入密钥:";
                cin>>key;
                cout<<"请输入待加密字符串:";
                cin>>str1;
                Encode(key, str1, str2);
                cout<<"加密后字符串:"<<str2<<endl;
            }
            else if(operation == 2){
                cout<<"请输入密钥:";
                cin>>key;
                cout<<"请输入待解密字符串:";
                cin>>str1;
                Dncode(key, str1, str2);
                cout<<"解密后字符串:"<<str2<<endl;
            }
        }
    }
};
void copyright()
{
    cout<<"\033[3;0H";
    cout<<"版权归属AFANStudio，第一次使用请输入READ.ME命令来查看readme文件，随后可以查看doc文件夹下文档"<<endl;
}
int getch(void){
    struct termios tm, tm_old;
    int fd = 0, ch;
    if(tcgetattr(fd, &tm) < 0){
        return -1;
    }
    tm_old = tm;
    cfmakeraw(&tm);
    if(tcsetattr(fd, TCSANOW, &tm) < 0){
        return -1;
    }
    
    ch = getchar();
    if(tcsetattr(fd, TCSANOW, &tm_old) < 0){
        return -1;
    }
    
    return ch;
}
void help()
{
    system("clear");
    /*方法很笨，没办法*/
    PRINT_HELP(printf("==================help==================\n"),
                printf("========================================\n"))
    {
        print("ASSOC          显示或修改文件扩展名关联");
        //print("BOOK           打开文件（用BOOK.adexe）。");
        print("CD             切换目录。");
        print("CDK            切换磁盘。（如果访问非当下\n磁盘的文件时请先使用此命令，后使用CD命令）");
        print("CLOER          改变颜色。（停用）");
        print("CLOSE          关闭文件。");
        print("CLS            清屏。");
        print("CONFIG         查看配置信息。");
        print("COUNTER        计算器。");
        print("DATE           显示日期。");
        //print("DISK           显示磁盘详情。");
        print("EXIT           退出。");
        print("FORMAT         格式化文件储存器。");
        print("GETIP          获取网页IP。");
        print("GSC            获取网页源代码（会超长）。");
        print("GT             获取网页文字内容。\n（技术不达标，以后更新）");
        print("HELP           获取帮助。");
        print("HILL           hill密码加密（下载后使\n用，有bug）。");
        print("INSTALL        安装");
        print("LS             显示目录");
        print("MEMORY         内存使用情况");
        print("MKDIR          用于创建子目录。");
        print("PING           检查网络。（连不上网，\n无法使用）");
        print("READ           读文件。");
        print("RMDIR          用于删除子目录。");
        //print("SEARCH         搜索可连接的远程主机。");建立完成数据库以后更新
        print("SFM            设置文件权限");
        print("TASK           任务监视器");
        print("TCLEAR         清理缓存");
        //print("TELNET         链接远程主机。（先使用\nSEARCH获取可连接主机）");建立完成数据库以后更新
        //print("INET           翻译（下载后后使用\n，技术原因暂不支持）。");
        print("VIRGINIA       Virginia密码加密（下载后\n使用）。");
        print("WRITE          写文件。");
        print("输入一个命令然后输入参数\"-h\"和内容\"help\"\n就可以触发帮助。密码加密程序可以直接输入\n指令不带参数");
        print("详细帮助文档请见https://code.xueersi.com/ide/code/19393077");
    }
    cout<<"按任意键退出"<<endl;
    string tmp;
    cin>>tmp;
    system("clear");
}

//统计字符出现次数
int findSubStringNUM(string targetString, string subString){
    int n = 0, sum = 0;
    string temp = targetString;
    while(1){
        n = temp.find(subString);
        if(n != -1){
            temp = temp.substr(n+subString.length(), temp.length()-subString.length());
            sum ++;
        }
        else break;
    }
    return sum;
}


void SystemDkInit(){
#ifndef _
    #define _ dk_C
        //所有的乱码都是辖敲的，相当于脸滚键盘+复制，没啥用只是为了仿真。
    if(Initflag == false){
        _.Mkdir("usr");
        _.Mkdir("Doc");
        _.Mkdir("Program");
        //_.Mkdir("temp");
        _.cd("usr");
        _.Mkdir("DOS_READ.ME");
        _.cd("DOS_READ.ME");
        _.create("READ.ME", 0);
        _.open("READ.ME", "write", "是的，这就是README文件\n    其实我也想要做这个大项目好久了。这也是我第一次做这么庞大的一个项目，有不好的地方请多包容，我技术不好，难免有不好的地方，请见谅。\n    要是说我为什么想做这么个项目，其实也是手痒痒。而且因为我以前也做了一个类似于终端的东西，可是没做出来，所以这次想要挑战一下。我看了编程社区的许多类似于此类的作品，u1s1，都很不错，但是都有些不太好的地方，比如说加载动画时间太长、输出超长等问题，所以我这次连logo都没加，就是怕加载特效太慢或者输出超长，而且编程社区的C++也只能做dos。本来我也是想要做一个能够保存用户设"
        "置的功能，奈何学而思编程社区的限制（不允许代码创建文件或者创建完运行结束就更换目录），所以就无法实现了。关于界面这一块，我最近正在做一个专属于C++的图形库，但是因为没做完并没有发出来，我在这个项目里也就只引用了部分函数。等回头那个库做好了、发出来了以后我会更新界面的。还有就是关于开源的这个问题，我想好了，以后我在编程社区发的所有的项目如果没有特殊说明的情况下都会开源，各位大佬可以帮我补充或者修改内容，完善逻辑上和技术上的不足，代码注释我会好好写的，有不好的地方跟我说，我改正(doge)。然后我还想说明以下几点:\n"    
        "    1.不许抄袭（这亘古不变的了都）。\n    2.改编的话是可以的，但是改编的时候要将作品改为改编，转载时要改为转载，其次附上该作品网址。\n    3.如果你发现任何bug或者需要改进的地方又或者是希望增加的功能请发送至邮箱afanstudio@163.com，如果你想要把你写的程序加入其中，也可以和我说，并把源代码发到上述邮箱。最好是可以传参的程序。 \n                       by DxiesLawiye(郭墨轩)");
        //dk_C.open("READ.ME", "close");
        _.cd("..");
        _.cd("..");
        _.cd("Doc");
        _.Mkdir("help");
        _.cd("help");
        _.Mkdir("zh_cn");
        _.cd("zh_cn");
        _.create("help.txt", 0);
        _.open("help.txt", "write", "详情请见：https://code.xueersi.com/ide/code/19393077");
        _.create("development.txt", 0);
        _.open("development.txt", "write", "详情请见：https://code.xueersi.com/ide/code/19514323");
        _.create("AboutAfan.txt", 0);
        _.open("AboutAfan.txt", "write", "AFAN工作室于2020年4月6日上午10：00成立，室长：郭墨轩。官网：https://sh21594074.icoc.vc/");
        _.cd("..");
        _.cd("..");
        _.cd("..");
        _.cd("Program");
        _.Mkdir("sysProgram");
        _.Mkdir("InstallProgram");
        _.cd("sysProgram");
        _.Mkdir("dirve");
        _.cd("dirve");
        _.Mkdir("cpu");
        _.cd("cpu");
        _.create("ADosCpu.sys", 3);
        _.open("ADosCpu.sys", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \448 ^%&$@#  $ d f f s f s s a s d f c x s s s s d f fr r e a a s x d ed e ew s s s s$ @ s s we r g h j k l o u h g f d s s x x x z s s q s  c1 1 0 25 220w  s w q a x x d r e s a sx x z 1 e3");
        _.cd("..");
        _.Mkdir("disk");
        _.cd("disk");
        _.create("ADosDiskC.sys",3);
        _.open("ADosDiskC.sys", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \448 ^%&$@#  $ d f f s f s s a s a s w q q 1 2 3 4  d d a 3  d 5 r d sd a d f r f s x x f f f fg fd fd s  d f c x s s s s d f fr r e a a s x d ed e ew s s s s$ @ s s we r g h j k l o u h g f d s s x x x z s s q s  c1 1 0 25 220w  s w q a x x d r e s a sx x z 1 e3");
        _.create("ADosDiskE.sys", 3);
        _.create("ADosDiskF.sys", 3);
        _.create("ADosDiskT.sys", 3);
        _.open("ADosDiskE.sys", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \448 ^%&$@#  $ d f f s f s s a s a s w q q 1 2 3 4  d d a 3  d 5 r d sd a d f r f s x x f f f fg fd fd s  d f c x s s s s d f fr r e a a s x d ed e ew s s s s$ @ s s we r g h j k l o u h g f d s s x x x z s s q s  c1 1 0 25 220w  s w q a x x d r e s a sx x z 1 e3");
        _.open("ADosDiskF.sys", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \448 ^%&$@#  $ d f f s f s s a s a s w q q 1 2 3 4  d d a 3  d 5 r d sd a d f r f s x x f f f fg fd fd s  d f c x s s s s d f fr r e a a s x d ed e ew s s s s$ @ s s we r g h j k l o u h g f d s s x x x z s s q s  c1 1 0 25 220w  s w q a x x d r e s a sx x z 1 e3");
        _.open("ADosDiskT.sys", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \448 ^%&$@#  $ d f f s f s s a s a s w q q 1 2 3 4  d d a 3  d 5 r d sd a d f r f s x x f f f fg fd fd s  d f c x s s s s d f fr r e a a s x d ed e ew s s s s$ @ s s we r g h j k l o u h g f d s s x x x z s s q s  c1 1 0 25 220w  s w q a x x d r e s a sx x z 1 e3");
        _.cd("..");
        _.Mkdir("usb");
        _.cd("usb");
        _.create("ADosUSB.sys", 3);
        _.open("ADosUSB.sys", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \448 ^%&$@#  $ d f f s d d a f s s a s d f c x s s s s d f fr r e a a s x d ed e ew s s s s$ @ s s we r g h j k l o u h g f d s s x x x z s s q s  c1 1 0 25 220w  s w q a x x d r e s a sx x z 1 e3");
        _.cd("..");
        _.Mkdir("Mouse");
        _.cd("usb");
        _.create("ADosMs.sys", 3);
        _.open("ADosMs.sys", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \448 ^%&$@#  $ d f f s d d a s a s d f o o i j h b g c x s s s s d f fr r e a a s x d ed e ew s s s s$ @ s s we r g h j k l o u h g f d s s x x x z s s q s  c1 1 0 25 220w  s w q a x x d r e s a sx x z 1 e3");
        _.cd("..");
        _.Mkdir("KeyBoard");
        _.cd("KeyBoard");
        _.create("ADosKB.sys", 3);
        _.open("ADosKB.sys", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \448 ^%&$@#  $ d f f s d  o o o  i  g f rf  j i i is  i o j j sjs e fhh h d a f s s a s d f c x s s s s d f fr r e a a s x d ed e ew s s s s$ @ s s we r g h j k l o u h g f d s s x x x z s s q s  c1 1 0 25 220w  s w q a x x d r e s a sx x z 1 e3");
        _.cd("..");
        _.cd("..");
        _.create("dos.adexe", 2);
        _.open("dos.adexe", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \468 ^%&$@#  $ 烫烫烫烫烫烫烫烫烫烫烫 駍？婱銿棼\n F雮崒$ 宎D U夊SWV冹|?怐 媇.壷婾?壪峂?鑹E饗E^P钘??兡!? \n y<?< =========== !?????????????????????ddddd dkjnvnbn DOS::@@100044sffddfxoodjgjojge yeogsaiuiuiuiuiursuirjkle;m baiutyjvmc");
        _.create("open.adexe", 2);
        _.open("open.adexe", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \468 ^%&$@#  $ XXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGXXPADDINGPADDINGX   ?   80<0??????\n"
                    "252?2K2_2????? 333$3.343R3[3n3t3???????\n"
                    "4%4Q4???{5???????????6?6E6K6Q6W6]6d6k6r6y6?6?????????????\n"
                    "77\"70777D7M7V7");
        _.create("Ping.adexe", 2);
        _.open("Ping.adexe", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \468 ^%&$@#  $ \n欁P 荻>s荻>s荻>s晕簊芏>s晕玸芏>s晕璼潭>s荻?s敹>s晕絪潭>s晕穝薅>s晕猻芏>s晕痵芏>sRich荻>s\ngetaddrinfo Ping.adll  ?_Ping\n烫烫烫烫烫烫烫 lsjkfhduhisdhduhisd 鵾");
        _.create("Ping.adll", 3);
        _.open("Ping.adll", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \478 ^%&$@#  $ \n踭`?5槨??謰鴫]鋲}鄩}軆?墋?鹯Cj ??兰59t?鹯3?7?謰餵 ??兰5??珠狂??婱?M鋟9E鄑聣M鋴賶]詨E鄫癶?h攌?鑁??榄??儅 u&?些?   j栲??Y?u?s  j栊??榘??杩??楱??悙    w?禘?簊?    ???   ");
        _.create("install.adexe", 2);
        _.open("install.adexe", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \468 ^%&$@#  $ \n 晟烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫 栲斤棍鲁 %#%&%￥%*￥%￥# Daijfdsjlogv");
        _.create("gsc.adexe", 2);
        _.open("gsc.adexe", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \468 ^%&$@#  $ \n {{{{{#eeddsfdjvbne juenr oeir jm a $%#^ nksltyq3%Y WE$^><><>   b/n$^W&BU#W#%nj6hb*/5640n467");
        _.create("GetIp.adexe", 2);
        _.open("GetIp.adexe", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \468 ^%&$@#  $ \n M$e$^ghdfsg21 RH 2d1h hjrje ^$h DT 哙鵈醃\n getaddrinfo GetIp.adll  ?__GetIp::GetIp\n dfdgd 烫烫烫烫烫烫烫烫烫");
        _.create("GetIp.adll", 3);
        _.open("GetIp.adll", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \478 ^%&$@#  $ \n @@adll @@__GetIp::GetIp @@__GetIp::~GetIp &pravite dasdgjn mjknsjng  gwn##jkid  ijeq$## kjea !V@#$");
        _.cd("..");
        _.cd("InstallProgram");
        _.Mkdir("AES");
        _.cd("AES");
        _.create("AES.adexe", 2);
        _.open("AES.adexe", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \468 ^%&$@#  $ \n jjerjojgrjsognjklzngworkgnoeknwrgklsdnvglksdn,xcznvgoiwrksdgnms;dakg;jifksl4087/%&$&%$#&$% 0841hrt120trh454n2$^&FD54t0rh rthy");
        _.cd("..");
        _.Mkdir("Hill");
        _.Mkdir("Virginia");
        _.cd("..");
        _.cd("..");
        //dk_tmp.Mkdir("Temp");
        dk_tmp.cd("Temp");
        dk_tmp.create("cmdtemp.tmp", 1);
        //dk_tmp.cd("..");
        Initflag = true;
    }
    string UUID = GetUUID();
    string tmpfilename = UUID + ".tmp";
    //添加软件后这里不要忘记要改
    if(logn.Hill == true && hill == false && InsOrDel == true){
        int number = findSubStringNUM(out.c_str(), "\\");
        for(int i = 1; i <= number - 2; i ++){
            _.cd("..");
        }
        _.cd("Program");
        _.cd("InstallProgram");
        _.cd("Hill");
        _.create("Hill.adexe", 2);
        _.open("Hill.adexe", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \468 ^%&$@#  $ \n hfjwehgjhjxlhgshj uehjr gjkh jhg    erjgh jrh gflsjhsfd&rf%dgfgji gf d4005 4 5dfg40gsjk  3# kj sfvkjbkmdf540 r5s4gf048540hgfb&%$&^&dfg540 054 405et054 th");
        _.cd("..");
        _.cd("..");
        _.cd("..");
        //dk_tmp.cd("Temp");
        dk_tmp.create(tmpfilename, 1);
        dk_tmp.open(tmpfilename, "write", "install Hill.adexe");
        //dk_tmp.cd("..");
        hill = true;
    }
    if(logn.Virginia == true && virinstall == false && InsOrDel == true){
        int number = findSubStringNUM(out.c_str(), "\\");
        for(int i = 1; i <= number - 2; i ++){
            _.cd("..");
        }
        _.cd("Program");
        _.cd("InstallProgram");
        _.cd("Virginia");
        _.create("Virginia.adexe", 2);
        _.open("Virginia.adexe", "write", "AFAN\n@Djfji 20 54654210  dsd sxuh ndfsnfnuen ifvje hg \468 ^%&$@#  $ \n hdhghbvhsd gfhghwert ggggggggggggrhf  iagr tahkbr hvkbnaspq  ?>>>>>>>>>>>>>>>>gqerguh ><wegfu  {{{{  r === wrj  484018*/40 j &^$%#*#$%% 114514");
        _.cd("..");
        _.cd("..");
        _.cd("..");
        //dk_tmp.cd("Temp");
        dk_tmp.create(tmpfilename, 1);
        dk_tmp.open(tmpfilename, "write", "install Virginia.adexe");
        //dk_tmp.cd("..");
        virinstall = true;
    }
    if(logn.Hill == false && hill == true && InsOrDel == false){
        int number = findSubStringNUM(out.c_str(), "\\");
        for(int i = 1; i <= number - 2; i ++){
            _.cd("..");
        }
        _.cd("Program");
        _.cd("InstallProgram");
        _.cd("Hill");
        _.rm("Hill.adexe");
        _.cd("..");
        _.cd("..");
        _.cd("..");
        //dk_tmp.cd("Temp");
        dk_tmp.create(tmpfilename, 1);
        dk_tmp.open(tmpfilename, "write", "Delete Hill.adexe");
        //dk_tmp.cd("..");
        hill = false;
        InsOrDel = true;
    }
    if(logn.Virginia == false && virinstall == true && InsOrDel == false){
        int number = findSubStringNUM(out.c_str(), "\\");
        for(int i = 1; i <= number - 2; i ++){
            _.cd("..");
        }
        _.cd("Program");
        _.cd("InstallProgram");
        _.cd("Virginia");
        _.rm("Virginia.adexe");
        _.cd("..");
        _.cd("..");
        _.cd("..");
        //dk_tmp.cd("Temp");
        dk_tmp.create(tmpfilename, 1);
        dk_tmp.open(tmpfilename, "write", "Delete Virginia.adexe");
        //dk_tmp.cd("..");
        virinstall = false;
        InsOrDel = true;
    }
    #undef _
#endif
}

void exitclass(int temps){
    if(pid == 0)
        kill(pid, SIGTSTP);
}
/*main.cpp*/
HAS_MEMBER(instruct)
int ADosMain()
{
#ifdef DEBUG
    Log_Pt();
#endif
    Open DosOpen;
#ifdef DEBUG
    Log_Pt();
#endif
    DosOpen.openmain();
    system("clear");
    copyright();
    sleep(3);
    cout<<"\033[3;0H"<<"\033[K";
    cout<<"\033[0;0H";
    cout<<"\033[s";
    string instruct, parameter, content, tmpstr;
    ASSOCEXE    assoc;
    CDEXE       cd;
    COLOREXE    color;
    CONFIGEXE   config;
    COUNTEREXE  counter;
    //DISKEXE     disk;
    //HILLEXE     hill;
    INSTALLEXE  install;
    Ping        pinger;
    VIRGINIAEXE virginia;
    int         addr;
    string      lastins;
    bool        EndFlag = 0;
    /*初始化磁盘内容*/
    SystemDkInit();
#ifdef DEBUG
    int ta = Mem.CreateThread("Test", "Test.adexe", 8 * 5);
    int tb = Mem.CreateThread("Test2", "Test.adexe", 8 * 5);
    int tc = Mem.CreateThread("Test3", "Test.adexe", 8 * 5);
    int td = Mem.CreateThread("Test4", "Test.adexe", 8 * 5);
    int te = Mem.CreateThread("Test5", "Test.adexe", 8 * 5);
    cout<<ta<<endl<<tb<<endl<<tc<<endl<<td<<endl<<te<<endl;
    //Mem.test(ta, "Test");
#ifdef DEBUG
    Log_Pt();
#endif
#endif
    //cout<<Mem.CreateTread("Test", 5)<<endl;
    if(loginif == 1)
    {
        while(true){
            cout<<"\033[u"<<"\033[K";
            cout<<endl;
            cout<<setfill('_')<<setw(100)<<"\n";
            cout<<setfill(' ');
            cout<<"\033[0;0H";
            cout<<"\033[s";
            SystemDkInit();
            tmpstr = instruct + " " + parameter + " " + content;
            lastins = instruct;
            instruct = "\0";
            parameter = "\0";
            content = "\0";
            if(out[0] != 'T')
                tmper >> out.c_str() >> " " >> date().c_str() >> " " >> tmpstr.c_str() >> " " >> "\n";
            //DIV_ROUND_UP(fsys->C_init_.length());
            cout << out;
            signal(SIGINT, exitclass);
            cin >> instruct; 
            system("clear");
            cout<<out<<instruct<<" "<<parameter<<" "<<content;
            cout<<setfill('_')<<setw(100)<<"\n";
            cout<<setfill(' ');
            cout<<"\033[3;0H";
            transform(instruct.begin(), instruct.end(), instruct.begin(), towupper);
            Mem.KillThread(addr, lastins);
            addr = Mem.CreateThread(instruct, instruct + ".adexe", 8 * 10, instruct, "AFAN Studio");
            Mem.RunThread(addr, instruct);
            if(instruct == "EXIT")
                return 0;//保障内存释放
            else if(instruct == "AES"){
                pid = vfork();
                if(pid == 0){
                    AES aes;
                    _exit(0);
                }
                continue;
            }
            else if(instruct == "HELP"){
                help();
                continue;
            }
            else if(instruct == "READ.ME"){
                cout<<fsys->README<<endl;
                continue;
            }
            else if(instruct == "CLS"){
                system("clear");
                continue;
            }
            else if((instruct == "VIRGINIA") && logn.Virginia == true){
                pid = vfork();
                if(pid == 0){
                    virginia.VIRGINIA();
                    _exit(0);
                }
                continue;
            }
            else if((instruct == "VIRGINIA") && logn.Virginia == false){
                pterr(instruct, "未下载，请使用install指令下载！");
                continue;
            }
            else if(instruct == "TCLEAR"){
                //dk_tmp.Rmdir("Temp");
                //dk_tmp.Mkdir("Temp");
                //dk_tmp.cd("Temp");
                dk_tmp.rm("cmdtemp.tmp");
                dk_tmp.create("cmdtemp.tmp", 1);
                //dk_tmp.cd("..");
                continue;
            }
            else if(instruct == "CD"){
                switch(out[0]){
                    case 'C':
                        dk_C.input(instruct);
                    break;
                    case 'E':
                        dk_E.input(instruct);
                    break;
                    case 'F':
                        dk_F.input(instruct);
                    break;
                    case 'T':
                        dk_tmp.input(instruct);
                    break;
                }
                continue;
            }
            else if(instruct == "CREATE"){
                switch(out[0]){
                    case 'C':
                        dk_C.input(instruct);
                    break;
                    case 'E':
                        dk_E.input(instruct);
                    break;
                    case 'F':
                        dk_F.input(instruct);
                    break;
                }
                continue;
            }
            else if(instruct == "OPEN"){
                switch(out[0]){
                    case 'C':
                        dk_C.input(instruct);
                    break;
                    case 'E':
                        dk_E.input(instruct);
                    break;
                    case 'F':
                        dk_F.input(instruct);
                    break;
                    case 'T':
                        dk_tmp.input(instruct);
                    break;
                }
                continue;
            }
            else if(instruct == "LS"){
                switch(out[0]){
                    case 'C':
                        dk_C.input(instruct);
                    break;
                    case 'E':
                        dk_E.input(instruct);
                    break;
                    case 'F':
                        dk_F.input(instruct);
                    break;
                    case 'T':
                        dk_tmp.input(instruct);
                    break;
                }
                continue;
            }
            else if(instruct == "FORMAT"){
                switch(out[0]){
                    case 'T':
                    case 'C':
                        cout<<"此盘不可格式化！"<<endl;
                    break;
                    case 'E':
                        dk_E.input(instruct);
                    break;
                    case 'F':
                        dk_F.input(instruct);
                    break;
                }
                continue;
            }
            else if(instruct == "MKDIR"){
                switch(out[0]){
                    case 'C':
                        dk_C.input(instruct);
                    break;
                    case 'E':
                        dk_E.input(instruct);
                    break;
                    case 'F':
                        dk_F.input(instruct);
                    break;
                }
                continue;
            }
            else if(instruct == "RMDTR"){
                switch(out[0]){
                    case 'C':
                        dk_C.input(instruct);
                    break;
                    case 'E':
                        dk_E.input(instruct);
                    break;
                    case 'F':
                        dk_F.input(instruct);
                    break;
                }
                continue;
            }
            else if(instruct == "CLOSE"){
                switch(out[0]){
                    case 'C':
                        dk_C.input(instruct);
                    break;
                    case 'E':
                        dk_E.input(instruct);
                    break;
                    case 'F':
                        dk_F.input(instruct);
                    break;
                }
                continue;
            }
            else if(instruct == "RM"){
                switch(out[0]){
                    case 'C':
                        dk_C.input(instruct);
                    break;
                    case 'E':
                        dk_E.input(instruct);
                    break;
                    case 'F':
                        dk_F.input(instruct);
                    break;
                }
                continue;
            }
            else if(instruct == "SFM"){
                switch(out[0]){
                    case 'C':
                        dk_C.input(instruct);
                    break;
                    case 'E':
                        dk_E.input(instruct);
                    break;
                    case 'F':
                        dk_F.input(instruct);
                    break;
                }
                continue;
            }
            else if(instruct == "USED"){
                cout<<dk_C.usedMem()<<"b"<<endl;
                cout<<dk_E.usedMem()<<"b"<<endl;
                cout<<dk_F.usedMem()<<"b"<<endl;
                cout<<dk_tmp.usedMem()<<"b"<<endl;
                continue;
            }
            else if(instruct == "COUNTER"){
                pid = vfork();
                if(pid == 0){
                    counter.COUNTER();
                    _exit(0);
                }
                continue;
            }
            else if(instruct == "DATE"){
                Date();
                continue;
            }
            else if(instruct == "MEMORY"){
                MEMORYEXE memory;
                continue;
            }
            else if(instruct == "HILL" && logn.Hill == true){
                pid = vfork();
                if(pid == 0){
                    HILLEXE hill;
                    _exit(0);
                }
                continue;
            }
            else if(instruct == "HILL" && logn.Hill == false){
                pterr(instruct, "未下载，请使用install指令下载！");
                continue;
            }
            else if(instruct == "PING"){
                pinger.useping();
                continue;
            }
            else if(instruct == "TASK"){
                Mem.showThread();
                #ifdef DEBUG
                Log_Pt();
                Mem.KillThread(ta, "Test");
                Log_Pt();
                Mem.KillThread(tb, "Test2");
                Mem.KillThread(tc, "Test3");
                Mem.KillThread(td, "Test4");
                Mem.KillThread(te, "Test5");
                #endif
                continue;
            }
            cin >> parameter; 
            if(instruct == "GETIP"){
                GetIPer(parameter.c_str());
                continue;
            }
            else if(instruct == "GSC"){
                GSCer(parameter);
#if 0
                cout<<GSCer(parameter)<<endl;//想看的自己打开
#endif
                cout<<"（会超长，就不放开了）"<<endl;
                continue;
            }
            cin >> content;//利用cin遇到空格就停止读取的特性
    /*#define INSTRUCT has_member_##instruct
                if(INSTRUCT<ASSOCEXE>::value == false){
                    printf("\"%s\"不是命令，也不是可执行文件\n",instruct.c_str());
                    cout<<INSTRUCT<Ping,ASSOCEXE>::value<<endl;
                    continue;
                }*/
            if(instruct == "ASSOC")
            {
                assoc.ASSOC(parameter.c_str(), content.c_str());
                continue;
            }
            else if(instruct == "CDK")
            {
                cd.CD(parameter.c_str(), content.c_str());
                continue;
            }
            else if(instruct == "COLOR")
            {
                color.COLOR(parameter.c_str(), content.c_str());
                continue;
            }
            else if(instruct == "CONFIG")
            {
                config.CONFIG(parameter.c_str(), content.c_str());
                continue;
            }
            else if(instruct == "INSTALL")
            {
                install.INSTALL(parameter.c_str(), content.c_str());
                continue;
            }
            printf("\"%s\"不是命令，也不是可执行文件\n",instruct.c_str());
            cin.clear();
        }
    }
    //DosOpen.tmpfunc();
    return 0;
}
int main()
{
#ifdef MST
    GetSize(AllHard);
    GetSize(string);
#endif
    int savereturn = ADosMain();
    cout<<endl;
    cout<<"正在释放内存..."<<endl;
    Sleep(100);
    system("clear");
    cout<<"\033[8m\033[?25l";
    return savereturn;
}
