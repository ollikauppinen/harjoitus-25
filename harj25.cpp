/**********************************************************
*Tehtävä: Harjoitus25
*Tekijä: Olli Kauppinen
*PVM: 03.12.2013
*Kuvaus:
*Muuta harjoituksen 24 toiminnallisuutta niin, etta
*varaat henkilötiedoille tilan dynaamisesti (max 10 hlo).
*Muuta valikko alla olevan esimerkin mukaiseksi ja toteuta valikossa
*näkyvät toiminnot.
*
*VALIKKO
*0 Lopeta
*1 Lisaa henkilo
*2 Nayta henkilo
*3 Nayta kaikki henkilot
*4 Poista henkilon tiedot
*
* Versio 1.0 H4718 03.12.2013
***********************************************************/

#include <iostream>
using namespace std;



struct TIEDOT
{
	char nimi[20];
	float kmatka;
	int hat;
};

const int MAX_TAULU = 10;

int Valikko(void);
void TulostaKaikkiTIEDOT(TIEDOT hlo[], int lkm);
void LisaaHenkilo(TIEDOT [], int *lkm);
void TulostaHenkilo(TIEDOT hlo[]);
void PoistaHLO(TIEDOT hlo[], int *hlo_lkm);


int main()
{
	int valinta = 0;
	int lkm = 0;
	bool jatka = true;
	TIEDOT* hlo = new TIEDOT [MAX_TAULU];
	

	do
	{
		cout << "\nHenkiloita rekisterissa " << lkm << " kpl" << endl;
		cout << "Max. 10 kpl." << endl;
		valinta = Valikko();
		cout << endl;

		switch (valinta)
		{
			case 0:
			{
				cout << "\nGood bye.\n";
				jatka = false;
				break;
			}

			case 1:
			{
				if (lkm < 10)
				{
				LisaaHenkilo(hlo, &lkm);
				}
				
				else
				{
				cout << "Taulukko taysi!" << endl;
				}
				break;
			}

			case 2:
			{
				TulostaHenkilo(hlo);
				break;
			}

			case 3:
			{

				TulostaKaikkiTIEDOT(hlo, lkm);

				break;
			}

			case 4:
			{
				PoistaHLO(hlo, &lkm);

				break;
			}

			default:
			{
				cout << "\nVaara valinta\n";
				break;
			}
		}
	}

	while (jatka == true);
	delete [] hlo;

}

int Valikko(void)
{
	int valinta;

	cout << "\nVALIKKO\n\n0 Lopeta\n1 Lisaa henkilo\n2 Tulosta hlo\n3 Tulosta kaikki" << endl;
	cout << "4 Poista henkilon tiedot" << endl;
	cin >> valinta;

	return valinta;
}

void TulostaKaikkiTIEDOT(TIEDOT hlo[],int lkm)
{
	cout << "Listaus:" << endl;
	for (int ind = 0; (ind < lkm); ind++)
	{
		cout << ind+1 << ". Nimi: " << hlo[ind].nimi << ", koulumatka: " << hlo[ind].kmatka << " km, hatun koko: " << hlo[ind].hat << endl;
	}
}

void LisaaHenkilo(TIEDOT hlo[], int *hlo_lkm)
{
	cout << "\nEtunimi?\n";
	cin >> hlo[*hlo_lkm].nimi;
	cout << "\nKoulumatka?\n";
	cin >> hlo[*hlo_lkm].kmatka;
	cout << "\nHatun koko?\n";
	cin >> hlo[*hlo_lkm].hat;

	(*hlo_lkm)++;
}

void TulostaHenkilo(TIEDOT hlo[])
{
	int nro;
	cout << "Henkilo nro? " << endl;
	cin >> nro;
	if (nro > 10)
	{
		cout << "Valinta ei mahdollinen, max maara 10" << endl;

	}
	else
	{
	 cout << "Nimi: " << hlo[nro-1].nimi << ", koulumatka: " << hlo[nro-1].kmatka << " km, hatun koko: " << hlo[nro-1].hat << endl;
	}
}

void PoistaHLO(TIEDOT hlo[], int *hlo_lkm)
{
	int nro;

	cout << "Valitse poistettava henkilo: " << endl;
	cin >> nro;

	*hlo[nro-1].nimi = NULL;
	hlo[nro-1].kmatka = 0;
	hlo[nro-1].hat = 0;

	for (nro; nro <= *hlo_lkm; nro++)
	{
		hlo[nro-1] = hlo[nro];
	}

	(*hlo_lkm)--;
}

