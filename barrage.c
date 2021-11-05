#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// faire une struct pour chaque centrale électrique, contenant la temperature, debit, rendements, chutte brute
// rendement machine est généralement entre 80 et 90%
// rendement génératrice généralement entre 80 et 95%
// ou alors : P_el = rendement_total*P_hydr

//cf p. 24-25 : avec les pertes, pauses pour cause de chute du réseaux hydrolique, ... on peut admettre
//un rendement total moyen relativement pessimiste de 70% et le supposer cst
// donc est ce qu'on prend juste un rendement moyen total ?!


struct Centrale {
	double diametre;
	double Dh;
	double chutte_brutte;
	double longueur;
	double rugosite;
	double rendement_tot;
};

double perte_en_charge(struct Centrale * bieudron, double temperature, double debit){
	//Pour une température entre 0 et 30 degré, la viscosité se calcule comme suit:
	double viscosite_cinematique = (1.78*pow(10,-6))/(1 + (0.0337*temperature) + (0.000221*pow(temperature,2)));
	double Re = (debit/(bieudron->diametre*M_PI))*bieudron->Dh/viscosite_cinematique;
	//étant donné que la formule de Colebrook est très compliquée, nous utilisons la formule "Swamee-Jain equation"
	//car : assume full-flowing circular pipe (cf page wikipedia "Darcy friction factor formulae")
	double temp = log10(((bieudron->rugosite/bieudron->Dh)/3.7) + (5.74/pow(Re,0.9)));
	double coeff_perte = 0.25/pow(temp,2);
	double dHr = coeff_perte*(bieudron->longueur/pow(bieudron->Dh,5))*((8*pow(debit,2))/(pow(M_PI,2)*9.81));
	return dHr;
}

//énergie électrique produite par jour:
double production_E(struct Centrale * bieudron, double debit, double temperature, double perte_en_charge()){
	double rho_eau = 999.87 + 0.0655*temperature - 8.46875*pow(10,-3)*pow(temperature,2) + 5.46875*pow(10,-5)+pow(temperature,2);

	double chutte_nette = bieudron->chutte_brutte - perte_en_charge(&bieudron, temperature, debit);
	double P_hydr = rho_eau*debit*9.81*chutte_nette;
	//double P_mecanique = rendement_machine*P_hydr;
	//puissance électrique en kilowatt-heure
	//double P_electrique = rendement_generatrice*P_mecanique/1000;
	double P_electrique = bieudron->rendement_tot*P_hydr;
	//énergie électrique produite par jour, en joule
	double E_produite = P_electrique*24*3.6*pow(10,6);

	return E_produite;
}

int main(int argc, char * argv[]) {

	//Pour la centrale de Bieudron:
	//suppose que l'eau remplit tout le tuyau et que ce tuyau a un diamètre intérieur constant
	struct Centrale bieudron;
	bieudron.diametre = 4.2;
	bieudron.Dh = pow(((bieudron.diametre)/2),2)*M_PI*4/(M_PI*(bieudron.diametre));
	bieudron.chutte_brutte = 1883;
	bieudron.longueur = 4230;
	bieudron.rugosite = 0.15;
	bieudron.rendement_tot = 0.7;
	//info pour calcul : debit max = 75 m^3 /s ; Dh = 4.2 ; viscosité = 0.00000101 => Re = 2.3*10^7
	//=> ne peut pas utiliser la formule simplifiée de lambda
	double debit = 75;
	//exemple de température:
	double temperature = 20;

	//double v_absolue = debit/(diametre_bieudron*M_PI);

	double E = production_E(&bieudron, debit, temperature, perte_en_charge);
	double a = bieudron.Dh;
	printf("L'usine de Bieudron produit au maximum %f joules par jour.\n", E);
	return 0;
}
