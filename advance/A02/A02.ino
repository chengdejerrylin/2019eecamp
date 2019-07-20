const int led[]={9,10,11,12};	
int i;					
int j=0;				
int direct=0;			
void setup() 
{    
  	for(i=0;i<4;i++)
    		pinMode(led[i],OUTPUT); 	
}
void loop() 
{
  	for(i=0;i<4;i++)
  	{
    		digitalWrite(led[i],LOW);	
  	}  
  	digitalWrite(led[j],HIGH); 	
  	delay(500);
  	if(direct==0)	//LED 在右移狀態?
  	{
     	if(j==3) //已右移至最右方?	
       		direct=1;	//改為左移。
     	else		//尚未移至最右方。
       		j=j+1; //繼續右移。       	
  	}
  	else				
  	{
     	if(j==0) //LED 在左移狀態。		
       		direct=0;	//改為右移。
     	else //尚未移至最左方。			
       		j=j-1; //繼續左移。  	
  }
}
