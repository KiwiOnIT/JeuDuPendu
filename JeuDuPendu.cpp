#include "JeuDuPendu.h"

std::vector<std::wstring> creerDico()
{
	std::vector<std::wstring> dico = {L"situation", L"salle", L"bureau", L"hotel", L"president", L"pensee", L"methode", L"village", L"utilisateur", L"sang", L"maths", L"autoroute", L"agence", L"intention", L"mariage", L"poete", L"etudiant", L"pollution", L"bureau", L"assurance", L"personne", L"sante", L"seance", L"avertissement", L"attitude", L"analyse", L"formateur", L"papier", L"attention", L"monnaie", L"chocolat", L"profondeur", L"revendeur", L"dîner", L"nuit", L"tiroir", L"tennis", L"chanteur", L"virus", L"college", L"four", L"oncle", L"arrivee", L"enregistrement", L"secteur", L"vol", L"emotion", L"signification", L"moment", L"ascenseur", L"laboratoire", L"enseignement", L"publicite", L"soeur", L"artisan", L"memoire", L"studio", L"objectif", L"devise", L"employeur", L"camera", L"marketing", L"quantite", L"vetements", L"conte", L"chef", L"solution", L"cousin", L"republique", L"signature", L"idee", L"moment", L"panier", L"devoirs", L"hopital", L"direction", L"mort", L"scene", L"comite", L"version", L"enfance", L"directeur", L"menu", L"boue", L"gens", L"amour", L"roi", L"dessin", L"logement", L"audition", L"insecte", L"lac", L"porte", L"categorie", L"theorie", L"film", L"inflation", L"media", L"arrivee", L"semaine", L"resultat", L"sante", L"recette", L"paiement", L"four", L"inspecteur", L"intention", L"chanson", L"appartement", L"salete", L"nourriture", L"medecine", L"croissance", L"funerailles", L"concept", L"gorge", L"realite", L"boue", L"soeur", L"contexte", L"cancer", L"acteur", L"pain", L"base", L"lecture", L"universite", L"climat", L"theorie", L"industrie", L"idee", L"volume", L"region", L"audience", L"securite", L"vetements", L"realisateur", L"donnees", L"opinion", L"confusion", L"camera", L"sympathie", L"signature", L"plainte", L"message", L"richesse", L"dessin", L"secretaire", L"aile", L"haut", L"poignet", L"corps", L"developper", L"sol", L"escargots", L"couinement", L"drogue", L"armee", L"triste", L"cerises", L"lapin", L"rock", L"impuissant", L"fleurs", L"vaches", L"pret", L"loufoque", L"jaune", L"enregistrer"};
	return dico;
}

std::wstring choisirMot(std::vector<std::wstring> &dico)
{
    int taille =  dico.size();
    srand(time(NULL));
	int i = static_cast<int>(rand() % taille);
	std::wstring mot = dico[i];
	return mot;
}

void afficherReponse(std::vector<wchar_t> &reponse)
{
	for (int i = 0 ; i < reponse.size(); i++)
	{
		std::wcout << reponse[i] << L" ";
	}
	std::wcout << std::endl;
}

std::vector<wchar_t> creerReponse(int lg)
{
	std::vector<wchar_t> tab(lg);
	for (int i = 0; i < tab.size(); i++)
	{
		tab[i] = L'_';
	}
	return tab;
}

bool tester(const std::wstring &mot, std::vector<wchar_t> &reponse, wchar_t car)
{
	bool check = false;
	int i = 0;
	while (i < mot.length())
	{
		if (car == mot[i])
		{
			reponse[i] = car;
			check = true;
		}
		i++;
	}
	return check;
}

bool estComplet(const std::wstring &mot, std::vector<wchar_t> &reponse)
{
	bool check = false;
	bool result = true;
	 int i = 0;
	 while (i < mot.length() && result)
	 {
		 if (reponse[i] != mot[i])
		 {
			 result = false;
		 }
		 i++;
	 }
	 return result;
}

void partie(std::vector<std::wstring> &dico)
{

	int compteur = 9;
	std::wstring mot = choisirMot(dico);
	std::vector<wchar_t> reponse = (creerReponse(mot.length()));
	bool perdu = false;
	bool check = false;

	while (!perdu && !check)
	{
		afficherReponse(reponse);
		std::wcout << std::endl;
		std::wcout << L"Nombre d'erreurs restantes : " << compteur << std::endl;
        char car;
        std::cout << "Enter a letter: ";
        std::cin >> car;
        std::cout << car;
		bool estBon = tester(mot,reponse, car);
		if (!estBon)
		{
			compteur = compteur - 1;
			std::wcout << std::endl;
			std::wcout << L"Mauvaise reponse" << std::endl;
		}
		if (compteur <= 0)
		{
			perdu = true;
            afficherReponse(reponse);
			std::wcout << std::endl;
			std::wcout << L"Vous avez perdu !" << std::endl;
			std::wcout << L"Le mot est " << mot << std::endl;
		}
		if (estComplet(mot,reponse))
		{
			perdu = true;
            afficherReponse(reponse);
			std::wcout << std::endl;
			std::wcout << L"Vous avez gagne !" << std::endl;
			std::wcout << L"Le mot est " << mot << std::endl;
		}
	}
}

int main()
{
	std::wcout << "Bienvenue dans le jeu du pendu !" << std::endl;
	std::vector<std::wstring> dico = creerDico();
	partie(dico);
    return 0;
}