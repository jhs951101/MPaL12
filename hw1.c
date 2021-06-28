char hour[3]; // hour[]: LCD 에 출력할 hour 값을 담는 string
char minute[3]; // minute[]: LCD 에 출력할 minute 값을 담는 string
char second[3]; // second[]: LCD 에 출력할 second 값을 담는 string
int ho = 12; // ho: 정수형 hour
int mi = 0; // mi: 정수형 minute
int se = 0-10; // se: 정수형 second
char* toStr(int n) // 2 자리 정수를 char 형 배열로 변환해주는 함수
{
 char s[3];

 int i = 1;
 while(i >= 0){
 int b = n % 10;
 s[i] = b + 48;

 i--;
 n /= 10;
 }
 s[2] = '\0';

 return s;
}
void SysTickHandler(void)
{
 Decrement_TimingDelay();

 if(gExNum == (unsigned int)SysTick_with_LCD)
 {
 if( time_count == 10 ){ // 1 초가 지날 때마다 인터럽에 의한 액션이 발생

 int t = ho * 3600 + mi * 60 + se;

 t++; // 시, 분, 초를 모두 초단위로 변환한 다음 +1 시킴

 t %= (3600 * 24);

 ho = t / 3600;
 t %= 3600;

 mi = t / 60;
 t %= 60;

 se = t; // 초 단위로 변환했던 시, 분, 초를 다시 할당함

 strcpy(hour, toStr(ho));
 strcpy(minute, toStr(mi));
 strcpy(second, toStr(se));

 LCD_DisplayStringLine(20, hour);
 LCD_DisplayStringLine(40, " :");
 LCD_DisplayStringLine(60, minute);
 LCD_DisplayStringLine(80, " :");
 LCD_DisplayStringLine(100, second);

 time_count = 0;
 }
 }

 time_count++;
}
