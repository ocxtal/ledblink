# LED_Blinker

LEDを決まったパターンで点滅させる、PSoC3 / 5LP用のモジュールです。

## 使い方

![sch](https://bitbucket.org/suzukihajime/led_blinker/raw/master/sch.png)


	/* おまじない */
	LED_Blinker_1_Start();
	
	/* 10101000..0 のパターンで点滅 */
	LED_Blinker_1_SetPattern(0x0015);
	
	/* 3回点滅 (上と同じパターンになる) */
	LED_Blinker_1_SetPattern(LED_Blinker_1_REPEAT(3));