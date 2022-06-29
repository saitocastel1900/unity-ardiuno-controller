# unity-ardiuno-controller
Ardiunoをコントローラーとしたゲームのプロジェクトです。ご自由にお使いください。

## まずはLチカ
```
const int LED_PIN=13;

void setup() {
    pinMode( LED_PIN, OUTPUT );
}
void loop() {
    digitalWrite( LED_PIN, HIGH );
    delay(100);
    digitalWrite( LED_PIN, LOW );
    delay(1000);
}
```
**13番ピンはボード上にあるLEDを指します。**  

![0](https://user-images.githubusercontent.com/96648305/176534709-bd2c9bf2-2d8b-493e-8c12-ba726bae2cbc.jpg)  


## ArdiunoとUnityでシリアル通信をしてみる
-UniRxを使用する(UniRxを利用しない方法はありますが、設定が大変なのでここでは利用しないことにしました)


## 加速度センサを使ってボールを動かしてみる

# 参考資料
https://rikoubou.hatenablog.com/entry/2018/02/08/174506  
https://nn-hokuson.hatenablog.com/entry/2017/09/12/192024  
https://tips.hecomi.com/entry/2014/07/28/023525  
https://takahi5.hatenablog.com/entry/2014/05/21/194122  
https://framesynthesis.jp/blog/2014/12/17/  
https://algorithm.joho.info/arduino/kxm52/  
http://zattouka.net/GarageHouse/micon/Arduino/Acceleration/Acceleration.htm  


