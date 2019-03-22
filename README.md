# HUD_QT
This project develops a HUD interface used in cars with QT framework.

# 程序说明
* UI画面的动态改变有两种方式，1)一种是自己随机变化，这需要将UI/src/widget.cpp中第24行，timer->start(T)打开，则每过Tms，槽函数jumpToWorkPage()会被执行，使UI的限速、转弯、前方道路名等图标随机变化；2)另一种是根据接收到的信息来确定UI内容，目前只调了速度和前方距离，消息的内容简陋地由两个int数据表示，定义为UI/include/widget.h中的CANMessage结构体，当type为0时，表示是UI开关信息，当type为1时，表示发送速度信息……

* 接收的信息被放在一个队列中，定义在UI/include/widget.h中，为std::queue<CANMessage> messages; 本来是不需要队列的，收到消息直接显示即可，但因为一个未知的原因（可能与Qt的多线程操作有关），用回调函数直接调用更新UI的函数会失效，所以在widget.cpp中每200ms刷新一下UI。而这200ms内可能已经收到了多个信息，所以先把它们按队列的方式存起来，等下次刷新时按顺序地显示出来。如果找到了回调失效的原因，可去掉相关代码。
  
* 在Widget类被创建时，实例化了一个叫做Exchange的类，这个类定义在Communicate/exchange.cpp(exchange.h)中，Exchange类会创建一个线程以UNIX域套接字协议不断poll发送到名为UNIX_RCV_ADDR的文件的信息，收到信息后，直接调用UI更新函数即可，但这样调用不能更新UI，所以在被调函数【void Widget::handleRecvCmds(int type, int value, void \*handle)】中将信息存储在队列中，让timer去异步执行。

* 编译出的target在运行时，需要访问到libexchange.so。

* Communicate/test是测试CAN向UI发送信息，当UI运行起来后(./target)，再执行./test 1 133，则是设置速度为133，./test 2 3590是设置前方距离，./test 0 0是关闭UI，./test 0 1是开启UI。

* 最先设计时有4个页面，所以程序中有dialog1.cpp~dialog4.cpp，但目前只用到了dialog1.cpp，也没有涉及到页面切换的相关操作。

* 前方距离的数字仍有缺失，目前只有3、5、9、0四张图片。

