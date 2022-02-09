#pragma once

#include <string>
#include <vector>
#include <iostream>

/**
 * Cette classe met en oeuvre le jeu du pendu
 * @author Lysnake
 */

class JeuDuPendu
{

public:
    /**
	 * Création d'un dictionnaire de mots
	 * @return dictionnaire initialisé
	 */
	virtual std::vector<std::wstring> creerDico();


	/**
	 * choix aléatoire d'un mot dans un dictionnaire
	 * @param dico dictionnaire des mots à choisir
	 * @return chaine choisie de manière aléatoire
	 */

	 virtual std::wstring choisirMot(std::vector<std::wstring> &dico);

	/**
	 * affiche la réponse du joueur
	 * @param reponse reponse du joueur
	 */

	 virtual void afficherReponse(std::vector<wchar_t> &reponse);

	 /**
	  * création d'un tableau de reponse contenant des '_'
	  * @param lg longueur du tableau à créer
	  * @return tableau de reponse contenant des '_'
	  */

	  virtual std::vector<wchar_t> creerReponse(int lg);

	/**
	 * teste la présence d'un caractère dans le mot
	 * et le place au bon endroit dans réponse
	 * @param mot mot à deviner
	 * @param reponse réponse à compléter si le caractère est présent dans le mot
	 * @param car caractère à chercher dans le mot
	 * @return vrai ssi le caractère est dans le mot à deviner
	 */

	 virtual bool tester(const std::wstring &mot, std::vector<wchar_t> &reponse, wchar_t car);

	 /**
	 * rend vrai ssi le mot est trouvé
	 * @param mot mot à deviner
	 * @param reponse réponse du joueur
	 * @return vrai ssi le mot est égal caractère par caractère à la réponse
	 */

	virtual bool estComplet(const std::wstring &mot, std::vector<wchar_t> &reponse);

	/**
	 * lancement d'une partie du jeu du pendu
	 * @param dico dictionnaire des mots à deviner
	 */

	virtual void partie(std::vector<std::wstring> &dico);

	virtual int main ();
};
