#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct _funcionario{
    char nome[50];
    float sal;
    int nd;
} funcionario;

typedef struct hora {
    float hed, hen, somahora, faltHoras;
    int diasfalt;
} hora;

typedef struct _desconto {
    float desceven, gastref, vales;
} desconto;


hora HoraExtra();
funcionario Funcionario();
desconto Desconto();

int main(){
    //Declaracao de variaveis
    funcionario funcionario;
    hora hora_extra;
    desconto desconto;
    float calcHoraExt, salFami, salarioMin, salBrut, INAMPS, faltas, impostos, descTotal, salLiqu;
    int op;


    do{

        funcionario = Funcionario();

        //definindo o salario minimo
        printf("Digite o salario minimo vigente:\n");
        scanf("%f",&salarioMin);

        hora_extra = HoraExtra();

        desconto = Desconto();

        //calculo das horas extras
        calcHoraExt = hora_extra.hed * (funcionario.sal/160) + (hora_extra.hen * 1.2) * (funcionario.sal/160);
        printf("As quantia que as horax extras render�o foi de R$ %.2f\n",calcHoraExt);

        //Calculo do salario familia
        salFami = funcionario.nd * 0.05 * salarioMin;
        printf("O salario familia foi de R$ %.2f\n",salFami);

        //Calculo do salario Bruto
        salBrut = funcionario.sal + calcHoraExt + salFami;
        printf("O salario bruto total foi de R$%.2f\n",salBrut);

        //Calculo do INAMPS
        INAMPS = 0.08 * funcionario.sal;
        printf("O INAMPS totalizou a quantia de R$%.2f \n",INAMPS);

        //Calculo das faltas
        faltas = hora_extra.faltHoras * (funcionario.sal/160);
        printf("A quantidade de descontos gerados por faltas foi de R$ %.2f\n",faltas);

        //Calculo dos impostos
        impostos = 0.08 * salBrut;
        printf("Os descontos por impostos foi de R$ %.2f \n",impostos);

        //Calculo do desconto total
        descTotal = impostos + faltas + INAMPS + desconto.desceven + desconto.gastref + desconto.vales;
        printf("O desconto total foi de R$%.2f \n",descTotal);

        //Calculo do salario liquido
        salLiqu = salBrut - descTotal;
        printf("O salario liquido foi de R$%.2f",salLiqu);

        printf("Deseja emitir outra nota: '1' para sim e '2' para nao:\n");
        scanf("%d",&op);

    }while(op == 1);

    return 0;
}

funcionario Funcionario(){

    funcionario x;

   //Atribuicao de dados ao funcionario
    printf("Digite o nome do funcionario:\n");
    scanf("%s",&x.nome);

    printf("Digite o salario do funcionario:\n");
    scanf("%f",&x.sal);

    printf("Digite quantos dependentes o %s possui:\n", x.nome);
    scanf("%d",&x.nd);

    return x;
}

hora HoraExtra(){

    hora y;


    //atribuicao de dados as horas
    printf("Digite as horas extras noturnas, diuna e o numeros de dias faltado:\n");
    scanf("%f%f%d",&y.hed, &y.hen, &y.diasfalt);


    y.somahora = y.hed + y.hen;

    if(y.somahora > 104){
        do{
            printf("ERROR! Numero de horas extras invalido, digite novamente:\n");
            scanf("%f%f",&y.hed, &y.hen);

            y.somahora = y.hed + y.hen;
        }while (y.somahora > 104);
    }

    y.faltHoras = y.diasfalt * 8;

    return y;
}

desconto Desconto(){

    desconto z;

     //atribuicao de desconto
    printf("Digite os descontos eventuais, os gastos com refeicao e os vales retirados durante o mes:\n");
    scanf("%f%f%f",&z.desceven, &z.gastref, &z.vales);

    return z;
}