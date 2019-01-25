#include "sys.h"
#include "delay.h"
#include "usart.h"

__asm void undef(void)
{
    DCI  0xF123                         // DCI is not an ARM assmebly instruction
    DCI  0x4567
    BX   LR
}

int main(void)
{ 
	delay_init(168);
	uart_init(115200);

	int a, b, c;
	int coredump_test_mode = 3;
	
	if (coredump_test_mode == 0) {
		SCB->CCR |= 0x10;
		a = 10;
		b = 0;
		c = a / b;
	} else if (coredump_test_mode == 1) {
		//SCB->CCR |= 0x10;
		//SCB->SHCSR |= 0x00070000;
		b = *(int*)0x0A000000;//
	} else if (coredump_test_mode == 2) {
		undef();
	} else if (coredump_test_mode == 3) {
		typedef void (*t_funcPtr)(void);
		t_funcPtr MyFunc = (t_funcPtr)(0x0001000 | 0x0);
		MyFunc();
	}
}

