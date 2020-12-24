struct numbers{
     int a;
     int b;
};
program CALC_PROG{
   version CALC_VERS{
       int add(numbers)=1;
       int sub(numbers)=1;
       int mul(numbers)=1;
       int div(numbers)=1;
   }=1;
}=0x4562877;
