#include <iostream>
using namespace std;

/* Definir una estructura de datos que permita parsear una cadena de caracteres en formato CSV */

const int CantMaxChars = 200;

struct PersonaCSV {
    char texto[CantMaxChars];
    char sepador;
    int cantElementos;
};


int main() {
    char cadena[] = "nombre;apellido;direccion;localidad;provincia;pais"; 
    char batallas1[]="battle_number,name,attacker_king,defender_king\n1,Battle of the Golden Tooth,Joffrey/Tommen Baratheon,Robb Stark\n2,Battle at the Mummer\'s Ford,Joffrey/Tommen Baratheon,Robb Stark\n3,Battle of Riverrun,Joffrey/Tommen Baratheon,Robb Stark\n4,Battle of the Green Fork,Robb Stark,Joffrey/Tommen Baratheon\n5,Battle of the Whispering Wood,Robb Stark,Joffrey/Tommen Baratheon\n6,Battle of the Camps,Robb Stark,Joffrey/Tommen Baratheon\n7,Sack of Darry,Joffrey/Tommen Baratheon,Robb Stark\n8,Battle of Moat Cailin,Balon/Euron Greyjoy,Robb Stark\n9,Battle of Deepwood Motte,Balon/Euron Greyjoy,Robb Stark\n10,Battle of the Stony Shore,Balon/Euron Greyjoy,Robb Stark\n11,Battle of Torrhen\'s Square,Robb Stark,Balon/Euron Greyjoy\n12,Battle of Winterfell,Balon/Euron Greyjoy,Robb Stark\n13,Sack of Torrhen\'s Square,Balon/Euron Greyjoy,Balon/Euron Greyjoy\n14,Sack of Winterfell,Joffrey/Tommen Baratheon,Robb Stark\n15,Battle of Oxcross,Robb Stark,Joffrey/Tommen Baratheon\n16,Siege of Storm\'s End,Stannis Baratheon,Renly Baratheon\n17,Battle of the Fords,Joffrey/Tommen Baratheon,Robb Stark\n18,Sack of Harrenhal,Robb Stark,Joffrey/Tommen Baratheon\n19,Battle of the Crag,Robb Stark,Joffrey/Tommen Baratheon\n20,Battle of the Blackwater,Stannis Baratheon,Joffrey/Tommen Baratheon\n21,Siege of Darry,Robb Stark,Joffrey/Tommen Baratheon\n22,Battle of Duskendale,Robb Stark,Joffrey/Tommen Baratheon\n23,Battle of the Burning Septry,,\n24,Battle of the Ruby Ford,Joffrey/Tommen Baratheon,Robb Stark\n25,Retaking of Harrenhal,Joffrey/Tommen Baratheon,\n26,The Red Wedding,Joffrey/Tommen Baratheon,Robb Stark\n27,Siege of Seagard,Robb Stark,Joffrey/Tommen Baratheon\n28,Battle of Castle Black,Stannis Baratheon,Mance Rayder\n29,Fall of Moat Cailin,Joffrey/Tommen Baratheon,Balon/Euron Greyjoy\n30,Sack of Saltpans,,\n31,Retaking of Deepwood Motte,Stannis Baratheon,Balon/Euron Greyjoy\n32,Battle of the Shield Islands,Balon/Euron Greyjoy,Joffrey/Tommen Baratheon\n33,";

    int i = 0;
    while (cadena[i] != '\0') {
       (cadena[i] != ',') ?  cout << cadena[i] : cout << endl;
        i++;
    }



    return 0;
}
