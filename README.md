# LED_Blinker

Blinks a LED with a constant pattern, an excercise on Verilog HDL and Datapath modules on  PSoC3 / 5LP.

## Usage

Place the module as follows. Note that the input clock is divided by 16 into a period.

![img](https://github.com/ocxtal/ledblinker/blob/master/sch.png)

```C
/* charm */
LED_Blinker_1_Start();
	
/* blink with a pattern 10101000..0 */
LED_Blinker_1_SetPattern(0x0015);
	
/* blink three times, similar pattern as above */
LED_Blinker_1_SetPattern(LED_Blinker_1_REPEAT(3));
```

## License

MIT

Copyright (c) 2015-2016 Hajime Suzuki