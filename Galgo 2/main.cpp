#include <iostream>
#include "Parser.h"

using namespace std;

// Precondicion: @batallasCSV1 es una cadena de caracteres en formato CSV con los siguientes campos: battle_number,name,attacker_king,defender_king
// @batallasCSV2 es una cadena de caracteres en formato CSV con los siguientes campos: battle_number,location,region,attacker_outcome
// Postcondicion: Imprime por salida estandard con el siguiente formato
// Ganadores
// 		Batalla [battle_number]-[battle_name] en [location] - [region]
// 			Atacante Ganador: [attacker_king]
//
// Perdedores
// 		Batalla [battle_number] en [location] - [region]
// 			Atacante Perdedor: [attacker_king]
// Es decir primero todas las batallas en las que el rey atacante gano (attacker_outcome tiene el valor win), con el titulo de Ganadores.
// Segundo todas las batallas en las que el rey atacante perdio, con el titulo de perdedores.
void MostrarInformeBatallas(char batallasCSV1[], char batallasCSV2[]);

int main() {
	char batallas1[] = "battle_number,name,attacker_king,defender_king\n1,Battle of the Golden Tooth,Joffrey/Tommen Baratheon,Robb Stark\n2,Battle at the Mummer\'s Ford,Joffrey/Tommen Baratheon,Robb Stark\n3,Battle of Riverrun,Joffrey/Tommen Baratheon,Robb Stark\n4,Battle of the Green Fork,Robb Stark,Joffrey/Tommen Baratheon\n5,Battle of the Whispering Wood,Robb Stark,Joffrey/Tommen Baratheon\n6,Battle of the Camps,Robb Stark,Joffrey/Tommen Baratheon\n7,Sack of Darry,Joffrey/Tommen Baratheon,Robb Stark\n8,Battle of Moat Cailin,Balon/Euron Greyjoy,Robb Stark\n9,Battle of Deepwood Motte,Balon/Euron Greyjoy,Robb Stark\n10,Battle of the Stony Shore,Balon/Euron Greyjoy,Robb Stark\n11,Battle of Torrhen\'s Square,Robb Stark,Balon/Euron Greyjoy\n12,Battle of Winterfell,Balon/Euron Greyjoy,Robb Stark\n13,Sack of Torrhen\'s Square,Balon/Euron Greyjoy,Balon/Euron Greyjoy\n14,Sack of Winterfell,Joffrey/Tommen Baratheon,Robb Stark\n15,Battle of Oxcross,Robb Stark,Joffrey/Tommen Baratheon\n16,Siege of Storm\'s End,Stannis Baratheon,Renly Baratheon\n17,Battle of the Fords,Joffrey/Tommen Baratheon,Robb Stark\n18,Sack of Harrenhal,Robb Stark,Joffrey/Tommen Baratheon\n19,Battle of the Crag,Robb Stark,Joffrey/Tommen Baratheon\n20,Battle of the Blackwater,Stannis Baratheon,Joffrey/Tommen Baratheon\n21,Siege of Darry,Robb Stark,Joffrey/Tommen Baratheon\n22,Battle of Duskendale,Robb Stark,Joffrey/Tommen Baratheon\n23,Battle of the Burning Septry,,\n24,Battle of the Ruby Ford,Joffrey/Tommen Baratheon,Robb Stark\n25,Retaking of Harrenhal,Joffrey/Tommen Baratheon,\n26,The Red Wedding,Joffrey/Tommen Baratheon,Robb Stark\n27,Siege of Seagard,Robb Stark,Joffrey/Tommen Baratheon\n28,Battle of Castle Black,Stannis Baratheon,Mance Rayder\n29,Fall of Moat Cailin,Joffrey/Tommen Baratheon,Balon/Euron Greyjoy\n30,Sack of Saltpans,,\n31,Retaking of Deepwood Motte,Stannis Baratheon,Balon/Euron Greyjoy\n32,Battle of the Shield Islands,Balon/Euron Greyjoy,Joffrey/Tommen Baratheon\n33,|Invasion of Ryamsport, Vinetown, and Starfish Harbor|,Balon/Euron Greyjoy,Joffrey/Tommen Baratheon\n34,Second Seige of Storm\'s End,Joffrey/Tommen Baratheon,Stannis Baratheon\n35,Siege of Dragonstone,Joffrey/Tommen Baratheon,Stannis Baratheon\n36,Siege of Riverrun,Joffrey/Tommen Baratheon,Robb Stark\n37,Siege of Raventree,Joffrey/Tommen Baratheon,Robb Stark\n38,Siege of Winterfell,Stannis Baratheon,Joffrey/Tommen Baratheon\n";
	char batallas2[] = "battle_number,location,region,attacker_outcome\n1,Golden Tooth,The Westerlands,win\n2,Mummer\'s Ford,The Riverlands,win\n3,Riverrun,The Riverlands,win\n4,Green Fork,The Riverlands,loss\n5,Whispering Wood,The Riverlands,win\n6,Riverrun,The Riverlands,win\n7,Darry,The Riverlands,win\n8,Moat Cailin,The North,win\n9,Deepwood Motte,The North,win\n10,Stony Shore,The North,win\n11,Torrhen\'s Square,The North,win\n12,Winterfell,The North,win\n13,Torrhen\'s Square,The North,win\n14,Winterfell,The North,win\n15,Oxcross,The Westerlands,win\n16,Storm\'s End,The Stormlands,win\n17,Red Fork,The Riverlands,loss\n18,Harrenhal,The Riverlands,win\n19,Crag,The Westerlands,win\n20,King\'s Landing,The Crownlands,loss\n21,Darry,The Riverlands,win\n22,Duskendale,The Crownlands,loss\n23,,The Riverlands,win\n24,Ruby Ford,The Riverlands,win\n25,Harrenhal,The Riverlands,win\n26,The Twins,The Riverlands,win\n27,Seagard,The Riverlands,win\n28,Castle Black,Beyond the Wall,loss\n29,Moat Cailin,The North,win\n30,Saltpans,The Riverlands,win\n31,Deepwood Motte,The North,win\n32,Shield Islands,The Reach,win\n33,|Ryamsport, Vinetown, Starfish Harbor|,The Reach,win\n34,Storm\'s End,The Stormlands,win\n35,Dragonstone,The Stormlands,win\n36,Riverrun,The Riverlands,win\n37,Raventree,The Riverlands,win\n38,Winterfell,The North,\n";


	char pruebas[] = "32,Shield Islands,The Reach,win\n33,|Ryamsport, Vinetown, Starfish Harbor|,The Reach,win\n34,Storm\'s End,The Stormlands,win\n";
	ArchivoCsv* test = Parsear(pruebas);
	Mostrar(test);
	// MostrarInformeBatallas(batallas1, batallas2);

	return 0;
}

void MostrarInformeBatallas(char batallasCSV1[], char batallasCSV2[]) {
	ArchivoCsv* batallas1 = Parsear(batallasCSV1);
	ArchivoCsv* batallas2 = Parsear(batallasCSV2);
	ArchivoCsv* batallas = MergeArchivos(batallas1, batallas2);
	// Mostrar(batallas);

}
