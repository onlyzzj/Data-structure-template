#include"xunji.h"	


void xunji(void)//1�Ǽ�⵽���ߣ�0�Ǽ�⵽����
{	
	   	if((HW1==1)&&(HW2==1)&&(HW3==1)&&(HW4==1))
		{
			zhixian();
		}
		else if((HW1==1)&&(HW2==1)&&(HW3==0)&&(HW4==1))
		{
			manzuozhuan();
		}
		else if((HW1==1)&&(HW2==0)&&(HW3==1)&&(HW4==1))
		{
			manyouzhuan();
		}
		else if((HW1==0)&&(HW2==1)&&(HW3==1)&&(HW4==1))
		{    			      
			kuaiyouzhuan();
		}
		else if((HW1==1)&&(HW2==1)&&(HW3==1)&&(HW4==0))
		{
			kuaizuozhuan();
		}
}