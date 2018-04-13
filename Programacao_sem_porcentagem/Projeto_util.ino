#define LDR A0 //define ldr como A0
float luminosidade; // armazena o valor da luminosidade
float amostra; //armazena a amostra

//Criando um objeto da classe LiquidCrystal e 
//inicializando com os pinos da interface.
#include "LiquidCrystal.h"
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{   
 
  lcd.begin(16, 1);  
  lcd.setCursor(0,1);
  lcd.clear();  
  lcd.print("projeto cinema");
} 
void loop() 
{   
amostra = 0; //Zera a variável amostra     
for(int i=0; i < 100 ; i++)   //Pega 100 amostras   
{   
luminosidade = analogRead(LDR); //Armazena o valor lido pelo LDR   
luminosidade = (luminosidade / 1024) * 100; //Transforma o valor lido em porcentagem 
amostra = amostra + luminosidade; //Armazena na variável amostra   
}   
amostra = amostra/100; //Tira a média das amostras   
  
if(amostra < 30) //Se a luminosidade estiver abaixo de 30%   
{     
lcd.print("______________"); //Liga o LED   
}   
else //Senão   
{    
lcd.print("  Desligue o Aparelho"); //Desliga o LED   
}   
delay(300); //Delay de 250 milissegundos    
}
