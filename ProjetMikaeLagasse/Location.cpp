//But : Écrire un programme pour calculer le montant qu’un individu devra débourser pour faire un voyage dans une
//		automobile louée.L’algorithme tient *compte du kilométrage parcouru* et de la *durée du voyage* qui sont
//		soumises par le requérant.
//Nom : Mikael Lagasse
//Date : 16 Septembre 2020

/*		Notes

		Coût de la location de 45$ par jour et comprend 250 km gratuits par jour

		La consommation du véhicule est 7.6 litres aux 100 km	

		1 litre d’essence coûte 1.25$

		0.05$ du kilomètre est exigé pour chaque kilomètre supplémentaire.

*/

#include<iostream>		//Parce qu'on en a toujours de besoin pour cin/cout.

using namespace std;	//Parce que std:: , C'EST NON.




// KM : La déclaration des variables en dehors du main, c'est NON !!!!
int jours;				//Nombre de jours.
float km;				//Distance du voyage calculer en Km.
int kmG;				//Utiliser pour stocker le kilometrage qu'on aura gratuitement avec la location.
int prixLocation = 45;	//Prix de la location par jours.
float prixL = 1.25;		//Prix du litre.
float extraKm = 0.05;	//Frais par extra Kilometre.
float cons;				//Utiliser pour calculer le total de litre qui nous faudra.
float totalGaz;			//Prix total du gaz calculer a la fin.


int main()
{
	setlocale(LC_ALL, "");		//Pour les accents et tout
		
	cout << "Combien de jour souhaitez vous louez l'automobile en question : \n";
	cin >> jours;		//L'utilisateur nous donne le nombre de jours qu'il veut louer l'automobile.
	// KM : Il faudrait valider la valeur entrée
	
	
	kmG = jours * 250;	//Kilometre Gratuits = Nombre de jours de location * 250km.
	cout << "Le voyage en kilometrage : \n";
	cin >> km;			//On demande la distance du voyage total.
	// KM : Il faudrait valider la saisie
	
	
	//FR : Ici , on veut verifier le total de kilometrage (plus grand ou plus petit) avec le kilometrage donner gratuitement lors de la location.
	//Car si le kilometrage gratuit est plus grand que le kilometrage du voyage , on lui fera pas payer de frais 
	//et on va "skip" une partie du code , car on calculerait des 0 un peu partout sinon.
	
	if (km > kmG)		//Donc si le kilometrage total du voyage est plus grand que le kilometrage donner gratuitement :
	{
		// KM : C'est sûrement une belle présentation, mais je n'ai pas pu la voir
		cout << "\nDonc.(Les kilometres gratuits par jours on ete soustrait du nombre de kilometre total.)\n";
		cout << "\n------FACTURE-------" << endl;
		cout << "  " << jours * prixLocation << " $   pour la location\n";		//Calcul du prix de la location (Nombre de jours * 45$).
		km -= kmG;		//On doit ce souvenir qu'on a 250km/jours qui sont gratuits , donc avant de calculer les frais d'extra sur le kilometrage , on doit enlever les 250km gratuits).
		cout << "+ " << km * extraKm << " $   d'extra (Kilometre supplementaire)\n";		//Calcul des frais d'extra (Kilometrage * 0.05$).
		cons = (7.6 * km) / 100;		//Ici , c'est le produit croisee qui nous permet de determiner la consommation (en L) de la voiture pour ensuite pouvoir calculer le prix total du gaz.
		totalGaz = cons * prixL;		//Calcul du prix total du gaz (Consommation total (Litres) * Prix du litre (1.25$).
		cout << "+ " << totalGaz << " $   niveau gaz\n";		//On l'affiche ensuite.
		cout << "----------------------" << endl;
		cout << " " << (jours * prixLocation) + (km * extraKm) + (totalGaz) << " $    est le total du voyage en question.\n\n";		//total TOTAL (Tout les frais calculer ensembles).
	}
	else               //Si le kilometrage total du voyage est plus petit que le kilometrage donner gratuitement :
	{
		cout << "\nDonc.\n";
		cout << "\n------FACTURE-------" << endl;
		cout << "  " << jours * prixLocation << " $   pour la location\n";		//Calcul du prix de la location (Nombre de jours * 45$).
		cout << "         " << "Rien a payer pour le gaz , car on excéde pas les " << 250 * jours << " Km gratuit.\n";		//On explique a l'utilisateur pourquoi il-n'y-a pas d'autre frais
		cout << "----------------------" << endl;
		cout << " " << jours * prixLocation << " $    est donc le total du voyage en question.\n\n";		//total TOTAL (Tout les frais calculer ensembles).
	}
}


/*			tests
------------------------------------------------

Jours = 2
Kilometrage total du voyage = 500km

Donc , on executerais la partie "else" , car le kilometrage du voyage ne depasse pas le kilometrage donner gratuitement.

Total = 90$ , car on paye juste les frais de location.

------------------------------------------------

Jours = 6
Kilometrage total tu voyage = 2000km

Kilometrage du voyage (2000) - Kilometrage gratuit (1500) = 500km de frais a payer

On execute la partie "if"

500km * 0.05$ ( Frais extra Km) = 25$

Consommation de l'automobile = (7.6L * Kilometrage ) / 100

Ensuite , "Prix du Litre * Consommation de l'automobile" nous donnera le total a payer niveau gaz. 
Donc , 38l * 1.25$ = 47.5$ de gaz.

Donc au TOTAL : 342.5$
*/
/*
•	La solution est bien nommée et comporte un projet 						5 / 5
•	Les fichiers sources contiennent l'identification complète du programme et de son auteur	5 / 5
•	Le code source est sans erreur de compilation 							15 / 15
•	Le programme est fonctionnel 15 / 20				// KM : Valider les saisies
•	Le programme passe le plan de tests 15 / 20			// KM : Manque valeurs improbables
•	Le code source est largement commenté 20 / 20
•	La solution est déposée dans LEA et dans GitHub.L'adresse est envoyée via Outlook	15/15



Note 90 / 100
Quel beau travail !!! Le code est bien structuré et commenté
*/
