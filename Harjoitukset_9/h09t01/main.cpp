#include <iostream>
#include <iterator>
#include <map>
#include <string>
using namespace std;
 
int main()
{
   string hakusana;

   std::map< std::string, std::string > sanakirja;
   sanakirja["kissa"]  = "kat";
   sanakirja["koira"]  = "hund";
   sanakirja["pallo"]  = "boll";
   sanakirja["kisuli"] = "kat";
   sanakirja.insert(std::make_pair(std::string("vihainen"), "arg"));
 
   std::map< std::string, std::string >::iterator mi;
 
   // tulostaa kaikki (aakkosjärjestyksessä)
   for (mi = sanakirja.begin(); mi != sanakirja.end(); ++mi)
       cout << mi->first << ": " << mi->second << '\n';

  // Tapa A: Helppo, mutta ei tule ilmoitusta löytymättömästä sanasta
  while (hakusana != "a")
  {
    cout << "Anna suomenkielinen hakusana (lopetus: a)>";
    cin >> hakusana;
    cout << "Hakutulos: " << sanakirja[hakusana] << endl;
  }

  // Tapa B: ok
  while (hakusana != "l")
  {
    cout << "Anna suomenkielinen hakusana (lopetus: l)>";
    cin >> hakusana;
    mi = sanakirja.find(hakusana);
    if (mi != sanakirja.end())
       cout << "Hakutulos: " << sanakirja[hakusana] << endl;
    else if (hakusana != "l")
       cout << "Hakutulos: " << "Sanaa " << hakusana << " ei löytynyt" << endl;
  }
  
  // Ruotsisanan etsiminen. Map ei suunniteltu tähän. Haku yhtä hankalaa
  // kuin järjestämättömästä datasta:
  while (hakusana != "s") {
    int loytyi = 0;
    cout << "Anna ruotsinkielinen hakusana (lopetus: s)>";
    cin >> hakusana;
    for (mi = sanakirja.begin(); mi != sanakirja.end(); ++mi ) {
       if (mi->second == hakusana) {
          cout << "Hakutulos: " << mi->first << endl;
          loytyi = 1;
       }
    }
    if (!loytyi && hakusana != "s")
       cout << "Hakutulos: " << "Sanaa " << hakusana << " ei löytynyt" << endl;
  }
}

