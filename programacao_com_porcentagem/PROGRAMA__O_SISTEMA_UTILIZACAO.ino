#define LDR A0 //define ldr como A0
float luminosidade; // armazena o valor da luminosidade
float amostra; //armazena a amostra

//Criando um objeto da classe LiquidCrystal e 
//inicializando com os pinos da interface.
#include "LiquidCrystal.h"
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{   
 
  lcd.begin(16, 2);  
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
lcd.print("Luminosidade = "); //Imprime na serial "Luminosidade = "   
lcd.print(amostra, 0); //Imprime a amostra sem casas decimais   
lcd.println("%"); //Imprime o símbolo de porcentagem 

  
if(amostra < 0) //Se a luminosidade estiver abaixo de 30%   
{     
lcd.print("Ok"); //Liga o LED   
}   
else //Senão   
{    
lcd.print("desligue o celular"); //Desliga o LED   
}   
delay(250); //Delay de 250 milissegundos    
}
