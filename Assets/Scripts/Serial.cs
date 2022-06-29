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
