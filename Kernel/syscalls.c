#include <stdint.h>
#include <syscalls.h>
#include <kbDriver.h>
#include <screenDriver.h>
#include <time.h>
#include <rtc.h>
#include <lib.h>
#define STDIN 0
#define STDOUT 1
#define STDERR 2

uint64_t sys_write(uint64_t fd, const char* buffer,uint64_t count){
    switch(fd){
        case STDOUT:
            
			while(count > 0){
				if(*buffer != '\0'){
						drawChar(*buffer,0xFFFFFF,0x000000);
				}
			
				buffer++;
				count--;
			}
			
            break;
        case STDERR:
          while(count > 0){
				 if(*buffer != '\0'){
						drawChar(*buffer,0xFF0000,0x000000);
				}
				
				buffer++;
				count--;
			}

            break;
			default:
			break;
    }
    return 0;
}

uint64_t sys_read(uint64_t fd,char * buffer,uint64_t count){
	switch(fd){
        case STDIN:
				
				while(count > 0){
				char c = getKeyASCII();
				if(c == -1){
					return 0;
				}
				*buffer = c;
				buffer++;
				count--;
				}
            break;
		default:
			break;
    }
    return 1;
	
}


void sys_beep(uint64_t timer){
  beep(timer);
}
	


uint64_t sys_drawRect(uint64_t x,uint64_t y,uint64_t width,uint64_t height,uint64_t color){
	return drawRect(x,y,width,height,color);
}

uint64_t sys_getHeight(){
	return getScreenHeight();
}
uint64_t sys_getWidth(){
	return getScreenWidth();
}

uint64_t sys_sleep(int ticks){
	if(ticks <= 0){
		return 0;
	}
	_sti();
	int start = ticks_elapsed();
	int end = ticks + start;
	while(ticks_elapsed() < end);
	return 1;
}

uint64_t sys_drawCircle(uint64_t x,uint64_t y,uint64_t radius,uint64_t color){
	return drawCircle(x,y,radius,color);
}

uint64_t sys_time(){
	displayDateTime();
	return 1;
}

uint64_t sys_clear(){
	clear();
	return 1;
}