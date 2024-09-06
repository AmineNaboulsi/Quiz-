#include <stdio.h>

int main(){
    int number_product , Option_selected;
    printf("Combien de produits ont été vendus aujourd'hui ?");
    scanf("%d" , &number_product);
    if(number_product<=0){
        printf("Invalid nombre ");
        return 0;
    }
    float AmountV[number_product];
    for (size_t i = 0; i < number_product; i++)
    {
        printf("Entrez le montant de la vente du produit %d :",i+1);
        scanf("%f", &AmountV[i]);
    }
    do{
        printf("1.Calculer le total des ventes\n");
        printf("2.Trouver la ventes la plus élevée et la plus basse\n");
        printf("3.Afficher les ventes supérieures à une moyenne\n");
        printf("4.Compter le nombre de ventes supérieures a 100\n");
        printf("5.Compter le nombre de ventes interieurs a 100\n");
        printf("6.Quiter\nEntez votre choix : ");
        scanf("%d", &Option_selected);
        if(Option_selected==1){
            float sum ;
            for (size_t i = 0; i < number_product; i++)
            {
                sum+=AmountV[i] ;
            }
            printf("\n-------------------------------------\n");
            printf("\nLe total des  ventes est : %.2f euros\n", sum);
            printf("\n-------------------------------------\n");
        }else if(Option_selected==2){
            float max = 0.0 , min = 0 ;
            if(number_product>0) min = AmountV[0];
            for (size_t i = 0; i < number_product; i++)
            {
                if(max<AmountV[i])max = AmountV[i];
                if(min>AmountV[i])min = AmountV[i];
            }
            printf("\n-------------------------------------\n");
            printf("\nMax : %.2f \nMin : %.2f \n", max , min);
            printf("\n-------------------------------------\n");
        }else if (Option_selected==3){
            int VentesB = 0;
            float moyenne ;
            //Je croit ce comparaission de etre o moyenne to tableaux
            /*for (size_t i = 0; i < number_product; i++) moyenne += AmountV[i];
            moyenne/=number_product;*/
            //Correction
            printf("Moyenne :");
            scanf("%f", &moyenne);
            for (size_t i = 0; i < number_product; i++) if(AmountV[i] > moyenne) VentesB++;
            printf("\n-------------------------------------\n");
            printf("Vente superieur au moyenne : %d",VentesB);
            printf("\n-------------------------------------\n");
        }
        else if (Option_selected == 4){
            int NB100 = 0;
            for (size_t i = 0; i < number_product; i++) if(AmountV[i] > 100) NB100++;
            printf("\n-------------------------------------\n");
            printf("Vente superieur au 100 est  : %d",NB100);
            printf("\n-------------------------------------\n");
        }
         else if (Option_selected == 5){
            int NB100 = 0;
            for (size_t i = 0; i < number_product; i++) if(AmountV[i] < 100) NB100++;
            printf("\n-------------------------------------\n");
            printf("Vente inferieur au 100 est  : %d",NB100);
            printf("\n-------------------------------------\n");
        }
    }while (Option_selected != 6);
    printf("Bye");

    return 0;
}