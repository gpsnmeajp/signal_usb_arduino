# signal_usb_arduino
シグナルタワーを制御するサンプル。  
使用しているシグナルタワー(24V有接点式)はリレー基板経由(Sainsmart 1982A)で制御している。

UART 9600bpsで、送られてきた文字列等の下位3bitを受信して反映。  
0x00は特別扱いして無視(無信号時間のみリセット)する。

一定時間無信号時間が続くと、デモモードとなり適当に点滅する。

https://github.com/gpsnmeajp/signal_usb_android_usb_host
