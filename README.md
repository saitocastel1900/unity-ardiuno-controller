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
おもちゃらぼ　さんを基に作成したので、おもちゃらぼ　さんの記事を見た方が速いかもです:https://nn-hokuson.hatenablog.com/entry/2017/09/12/192024  
```
byte x = 0;
byte y= 0;
byte z = 0;

void setup() {
Serial.begin(9600);
}

void loop() {
x++;
z--;

Serial.print(x);
Serial.print(",");
Serial.print(y);
Serial.print(",");
Serial.print(z);
Serial.print("\r\n");
}
```
**beginで転送速度を設定、printで値を転送しています**  

```
using System.Collections;
using System.Collections.Generic;
using System.Threading;
using System;
using System.IO.Ports;
using UnityEngine;
using UniRx;

public class Serial : MonoBehaviour {

    [SerializeField]private string portName;
    [SerializeField]private int baurate;

    private SerialPort serial;
    private bool isLoop = true;

    void Start () 
    {
        this.serial = new SerialPort (portName, baurate, Parity.None, 8, StopBits.One);

        try
        {
            this.serial.Open();
            //別スレッドで実行  
            Scheduler.ThreadPool.Schedule (() => ReadData ()).AddTo(this);
        } 
        catch(Exception e)
        {
            Debug.Log ("ポートが開けませんでした。設定している値が間違っている場合があります");
        }
    }
	
    //データ受信時に呼ばれる
    public void ReadData()
    {
        while (this.isLoop)
        {
            //ReadLineで読み込む
            string message = this.serial.ReadLine();
            Debug.Log( message );
        }
    }

    void OnDestroy()
    {
        this.isLoop = false;
        this.serial.Close ();
    }
}
```
**Serialを使うために using System.IO.Portsとしていますが、Portsを扱うためには事前にNETを設定する必要があります**  

## 加速度センサを使ってボールを動かしてみる(KXR94-2050)
#### 加速度センサとは？
- 1秒あたりの速度変化を検出できる(似ているセンサとして角速度センサがあるが、角速度は1秒間あたり何回転しているのかを検出できる)
- これを利用すればunity上でオブジェクトを動かしたりできる

```
void setup() {
  Serial.begin(9600);
}
 
void loop() {

  float x =  analogRead(A0)/100.0;
  float y =  analogRead(A1)/100.0;
  float z =  analogRead(A2)/100.0;

  Serial.print("X : ");
  Serial.print(x);
  Serial.print(" Y : ");
  Serial.print(y);
  Serial.print(" Z : ");
  Serial.println(z);
 
  delay(1000);
}
```
![image](https://user-images.githubusercontent.com/96648305/178147182-82ecca18-9d6d-4437-a7da-eb1aac86a8d1.png)

### 加速度センサを使ってボールを動かしてみる

# 参考資料
https://rikoubou.hatenablog.com/entry/2018/02/08/174506  
https://nn-hokuson.hatenablog.com/entry/2017/09/12/192024  
https://tips.hecomi.com/entry/2014/07/28/023525  
https://takahi5.hatenablog.com/entry/2014/05/21/194122  
https://framesynthesis.jp/blog/2014/12/17/  
https://algorithm.joho.info/arduino/kxm52/  
http://zattouka.net/GarageHouse/micon/Arduino/Acceleration/Acceleration.htm  
https://www.petitmonte.com/robot/howto_kxr94_2050.html


