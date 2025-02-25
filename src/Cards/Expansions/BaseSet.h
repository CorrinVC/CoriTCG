#pragma once

#include "../EnergyCard.h"
#include "../Expansion.h"
#include "../PokemonCard.h"
#include "../TrainerCard.h"

namespace Cori { namespace Expansions { namespace BaseSet {

    DataCard* _001Alakazam { new PokemonCard(
        "Alakazam", 80, EnergyType::Psychic, Stage::Stage2, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 1, Rarity::HoloRare
    )};

    DataCard* _002Blastoise { new PokemonCard(
        "Blastoise", 100, EnergyType::Water, Stage::Stage2, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 2, Rarity::HoloRare
    )};

    DataCard* _003Chansey { new PokemonCard(
        "Chansey", 120, EnergyType::Colorless, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 3, Rarity::HoloRare
    )};

    DataCard* _004Charizard { new PokemonCard(
        "Charizard", 120, EnergyType::Fire, Stage::Stage2, 3,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 4, Rarity::HoloRare
    )};

    DataCard* _005Clefairy { new PokemonCard(
        "Clefairy", 40, EnergyType::Colorless, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 5, Rarity::HoloRare
    )};

    DataCard* _006Gyarados { new PokemonCard(
        "Gyarados", 100, EnergyType::Water, Stage::Stage1, 3,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 6, Rarity::HoloRare
    )};

    DataCard* _007Hitmonchan { new PokemonCard(
        "Hitmonchan", 70, EnergyType::Fighting, Stage::Basic, 2,
        "Ken Sugimori", ExpansionID::BaseSet, 7, Rarity::HoloRare
    )};

    DataCard* _008Machamp { new PokemonCard(
        "Machamp", 100, EnergyType::Fighting, Stage::Stage2, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 8, Rarity::HoloRare
    )};

    DataCard* _009Magneton { new PokemonCard(
        "Magneton", 60, EnergyType::Lightning, Stage::Stage1, 1,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 9, Rarity::HoloRare
    )};

    DataCard* _010Mewtwo { new PokemonCard(
        "Mewtwo", 60, EnergyType::Psychic, Stage::Basic, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 10, Rarity::HoloRare
    )};

    DataCard* _011Nidoking { new PokemonCard(
        "Nidoking", 90, EnergyType::Grass, Stage::Stage2, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 11, Rarity::HoloRare
    )};

    DataCard* _012Ninetales { new PokemonCard(
        "Ninetales", 80, EnergyType::Fire, Stage::Stage1, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 12, Rarity::HoloRare
    )};

    DataCard* _013Poliwrath { new PokemonCard(
        "Poliwrath", 90, EnergyType::Water, Stage::Stage2, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 13, Rarity::HoloRare
    )};

    DataCard* _014Raichu { new PokemonCard(
        "Raichu", 80, EnergyType::Lightning, Stage::Stage1, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 14, Rarity::HoloRare
    )};

    DataCard* _015Venusaur { new PokemonCard(
        "Venusaur", 100, EnergyType::Grass, Stage::Stage2, 2,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 15, Rarity::HoloRare
    )};

    DataCard* _016Zapdos { new PokemonCard(
        "Zapdos", 90, EnergyType::Lightning, Stage::Basic, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 16, Rarity::HoloRare
    )};

    DataCard* _017Beedrill { new PokemonCard(
        "Beedrill", 80, EnergyType::Grass, Stage::Stage2, 0,
        "Ken Sugimori", ExpansionID::BaseSet, 17, Rarity::Rare
    )};

    DataCard* _018Dragonair { new PokemonCard(
        "Dragonair", 80, EnergyType::Colorless, Stage::Stage1, 2,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 18, Rarity::Rare
    )};

    DataCard* _019Dugtrio { new PokemonCard(
        "Dugtrio", 70, EnergyType::Fighting, Stage::Stage1, 2,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 19, Rarity::Rare
    )};

    DataCard* _020Electabuzz { new PokemonCard(
        "Electabuzz", 70, EnergyType::Lightning, Stage::Basic, 2,
        "Ken Sugimori", ExpansionID::BaseSet, 20, Rarity::Rare
    )};

    DataCard* _021Electrode { new PokemonCard(
        "Electrode", 80, EnergyType::Lightning, Stage::Stage1, 1,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 21, Rarity::Rare
    )};

    DataCard* _022Pidgeotto { new PokemonCard(
        "Pidgeotto", 60, EnergyType::Colorless, Stage::Stage1, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 22, Rarity::Rare
    )};

    DataCard* _023Arcanine { new PokemonCard(
        "Arcanine", 100, EnergyType::Fire, Stage::Stage1, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 23, Rarity::Uncommon
    )};

    DataCard* _024Charmeleon { new PokemonCard(
        "Charmeleon", 80, EnergyType::Fire, Stage::Stage1, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 24, Rarity::Uncommon
    )};

    DataCard* _025Dewgong { new PokemonCard(
        "Dewgong", 80, EnergyType::Water, Stage::Stage1, 3,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 25, Rarity::Uncommon
    )};

    DataCard* _026Dratini { new PokemonCard(
        "Dratini", 40, EnergyType::Colorless, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 26, Rarity::Uncommon
    )};

    DataCard* _027Farfetchd { new PokemonCard(
        "Farfetch'd", 50, EnergyType::Colorless, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 27, Rarity::Uncommon
    )};

    DataCard* _028Growlithe { new PokemonCard(
        "Growlithe", 60, EnergyType::Fire, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 28, Rarity::Uncommon
    )};

    DataCard* _029Haunter { new PokemonCard(
        "Haunter", 60, EnergyType::Psychic, Stage::Stage1, 1,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 29, Rarity::Uncommon
    )};

    DataCard* _030Ivysaur { new PokemonCard(
        "Ivysaur", 60, EnergyType::Grass, Stage::Stage1, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 30, Rarity::Uncommon
    )};

    DataCard* _031Jynx { new PokemonCard(
        "Jynx", 70, EnergyType::Psychic, Stage::Basic, 2,
        "Ken Sugimori", ExpansionID::BaseSet, 31, Rarity::Uncommon
    )};

    DataCard* _032Kadabra { new PokemonCard(
        "Kadabra", 60, EnergyType::Psychic, Stage::Stage1, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 32, Rarity::Uncommon
    )};

    DataCard* _033Kakuna { new PokemonCard(
        "Kakuna", 80, EnergyType::Grass, Stage::Stage1, 2,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 33, Rarity::Uncommon
    )};

    DataCard* _034Machoke { new PokemonCard(
        "Machoke", 80, EnergyType::Fighting, Stage::Stage1, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 34, Rarity::Uncommon
    )};

    DataCard* _035Magikarp { new PokemonCard(
        "Magikarp", 30, EnergyType::Water, Stage::Basic, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 35, Rarity::Uncommon
    )};

    DataCard* _036Magmar { new PokemonCard(
        "Magmar", 50, EnergyType::Fire, Stage::Basic, 2,
        "Ken Sugimori", ExpansionID::BaseSet, 36, Rarity::Uncommon
    )};

    DataCard* _037Nidorino { new PokemonCard(
        "Nidorino", 60, EnergyType::Grass, Stage::Stage1, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 37, Rarity::Uncommon
    )};

    DataCard* _038Poliwhirl { new PokemonCard(
        "Poliwhirl", 60, EnergyType::Water, Stage::Stage1, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 38, Rarity::Uncommon
    )};

    DataCard* _039Porygon { new PokemonCard(
        "Porygon", 30, EnergyType::Colorless, Stage::Basic, 1,
        "Tomoaki Imakuni", ExpansionID::BaseSet, 39, Rarity::Uncommon
    )};

    DataCard* _040Raticate { new PokemonCard(
        "Raticate", 60, EnergyType::Colorless, Stage::Stage1, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 40, Rarity::Uncommon
    )};

    DataCard* _041Seel { new PokemonCard(
        "Seel", 60, EnergyType::Water, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 41, Rarity::Uncommon
    )};

    DataCard* _042Wartortle { new PokemonCard(
        "Wartortle", 70, EnergyType::Water, Stage::Stage1, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 42, Rarity::Uncommon
    )};

    DataCard* _043Abra { new PokemonCard(
        "Abra", 30, EnergyType::Psychic, Stage::Basic, 0,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 43, Rarity::Common
    )};

    DataCard* _044Bulbasaur { new PokemonCard(
        "Bulbasaur", 40, EnergyType::Grass, Stage::Basic, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 44, Rarity::Common
    )};

    DataCard* _045Caterpie { new PokemonCard(
        "Caterpie", 40, EnergyType::Grass, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 45, Rarity::Common
    )};

    DataCard* _046Charmander { new PokemonCard(
        "Charmander", 50, EnergyType::Fire, Stage::Basic, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 46, Rarity::Common
    )};

    DataCard* _047Diglett { new PokemonCard(
        "Diglett", 30, EnergyType::Fighting, Stage::Basic, 0,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 47, Rarity::Common
    )};

    DataCard* _048Doduo { new PokemonCard(
        "Doduo", 50, EnergyType::Colorless, Stage::Basic, 0,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 48, Rarity::Common
    )};

    DataCard* _049Drowzee { new PokemonCard(
        "Drowzee", 50, EnergyType::Psychic, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 49, Rarity::Common
    )};

    DataCard* _050Gastly { new PokemonCard(
        "Gastly", 30, EnergyType::Psychic, Stage::Basic, 0,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 50, Rarity::Common
    )};

    DataCard* _051Koffing { new PokemonCard(
        "Koffing", 50, EnergyType::Grass, Stage::Basic, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 51, Rarity::Common
    )};

    DataCard* _052Machop { new PokemonCard(
        "Machop", 50, EnergyType::Fighting, Stage::Basic, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 52, Rarity::Common
    )};

    DataCard* _053Magnemite { new PokemonCard(
        "Magnemite", 40, EnergyType::Lightning, Stage::Basic, 1,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 53, Rarity::Common
    )};

    DataCard* _054Metapod { new PokemonCard(
        "Metapod", 70, EnergyType::Grass, Stage::Stage1, 2,
        "Ken Sugimori", ExpansionID::BaseSet, 54, Rarity::Common
    )};

    DataCard* _055NidoranM { new PokemonCard(
        L"Nidoran ♂", 40, EnergyType::Grass, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 55, Rarity::Common
    )};

    DataCard* _056Onix { new PokemonCard(
        "Onix", 90, EnergyType::Fighting, Stage::Basic, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 56, Rarity::Common
    )};

    DataCard* _057Pidgey { new PokemonCard(
        "Pidgey", 40, EnergyType::Colorless, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 57, Rarity::Common
    )};

    DataCard* _058Pikachu { new PokemonCard(
        "Pikachu", 40, EnergyType::Lightning, Stage::Basic, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 58, Rarity::Common
    )};

    DataCard* _059Poliwag { new PokemonCard(
        "Poliwag", 40, EnergyType::Water, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 59, Rarity::Common
    )};

    DataCard* _060Ponyta { new PokemonCard(
        "Ponyta", 40, EnergyType::Fire, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 60, Rarity::Common
    )};

    DataCard* _061Rattata { new PokemonCard(
        "Rattata", 30, EnergyType::Colorless, Stage::Basic, 0,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 61, Rarity::Common
    )};

    DataCard* _062Sandshrew { new PokemonCard(
        "Sandshrew", 40, EnergyType::Fighting, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 62, Rarity::Common
    )};

    DataCard* _063Squirtle { new PokemonCard(
        "Squirtle", 40, EnergyType::Water, Stage::Basic, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 63, Rarity::Common
    )};

    DataCard* _064Starmie { new PokemonCard(
        "Starmie", 60, EnergyType::Water, Stage::Stage1, 1,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 64, Rarity::Common
    )};

    DataCard* _065Staryu { new PokemonCard(
        "Staryu", 40, EnergyType::Water, Stage::Basic, 1,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 65, Rarity::Common
    )};

    DataCard* _066Tangela { new PokemonCard(
        "Tangela", 50, EnergyType::Grass, Stage::Basic, 2,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 66, Rarity::Common
    )};

    DataCard* _067Voltorb { new PokemonCard(
        "Voltorb", 40, EnergyType::Lightning, Stage::Basic, 1,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 67, Rarity::Common
    )};

    DataCard* _068Vulpix { new PokemonCard(
        "Vulpix", 50, EnergyType::Fire, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 68, Rarity::Common
    )};

    DataCard* _069Weedle { new PokemonCard(
        "Weedle", 40, EnergyType::Grass, Stage::Basic, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 69, Rarity::Common
    )};

    DataCard* _070ClefairyDoll { new TrainerCard(
        "Clefairy Doll", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 70, Rarity::Rare
    )};

    DataCard* _071ComputerSearch { new TrainerCard(
        "Computer Search", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 71, Rarity::Rare
    )};

    DataCard* _072DevolutionSpray { new TrainerCard(
        "Devolution Spray", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 72, Rarity::Rare
    )};

    DataCard* _073ImposterProfessorOak { new TrainerCard(
        "Imposter Professor Oak", TrainerType::Item, "Ken Sugimori",
        ExpansionID::BaseSet, 73, Rarity::Rare
    )};

    DataCard* _074ItemFinder { new TrainerCard(
        "Item Finder", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 74, Rarity::Rare
    )};

    DataCard* _075Lass { new TrainerCard(
        "Lass", TrainerType::Item, "Ken Sugimori",
        ExpansionID::BaseSet, 75, Rarity::Rare
    )};

    DataCard* _076PokémonBreeder { new TrainerCard(
        L"Pokémon Breeder", TrainerType::Supporter, "Ken Sugimori",
        ExpansionID::BaseSet, 76, Rarity::Rare
    )};

    DataCard* _077PokémonTrader { new TrainerCard(
        L"Pokémon Trader", TrainerType::Item, "Ken Sugimori",
        ExpansionID::BaseSet, 77, Rarity::Rare
    )};

    DataCard* _078ScoopUp { new TrainerCard(
        "Scoop Up", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 78, Rarity::Rare
    )};

    DataCard* _079SuperEnergyRemoval { new TrainerCard(
        "Super Energy Removal", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 79, Rarity::Rare
    )};

    DataCard* _080Defender { new TrainerCard(
        "Defender", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 80, Rarity::Uncommon
    )};

    DataCard* _081EnergyRetrieval { new TrainerCard(
        "Energy Retrieval", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 81, Rarity::Uncommon
    )};

    DataCard* _082FullHeal { new TrainerCard(
        "Full Heal", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 82, Rarity::Uncommon
    )};

    DataCard* _083Maintenance { new TrainerCard(
        "Maintenance", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 83, Rarity::Uncommon
    )};

    DataCard* _084PlusPower { new TrainerCard(
        "PlusPower", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 84, Rarity::Uncommon
    )};

    DataCard* _085PokémonCenter { new TrainerCard(
        L"Pokémon Center", TrainerType::Stadium, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 85, Rarity::Uncommon
    )};

    DataCard* _086PokémonFlute { new TrainerCard(
        L"Pokémon Flute", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 86, Rarity::Uncommon
    )};

    DataCard* _087Pokédex { new TrainerCard(
        L"Pokédex", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 87, Rarity::Uncommon
    )};

    DataCard* _088ProfessorOak { new TrainerCard(
        "Professor Oak", TrainerType::Item, "Ken Sugimori",
        ExpansionID::BaseSet, 88, Rarity::Uncommon
    )};

    DataCard* _089Revive { new TrainerCard(
        "Revive", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 89, Rarity::Uncommon
    )};

    DataCard* _090SuperPotion { new TrainerCard(
        "Super Potion", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 90, Rarity::Uncommon
    )};

    DataCard* _091Bill { new TrainerCard(
        "Bill", TrainerType::Supporter, "Ken Sugimori",
        ExpansionID::BaseSet, 91, Rarity::Common
    )};

    DataCard* _092EnergyRemoval { new TrainerCard(
        "Energy Removal", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 92, Rarity::Common
    )};

    DataCard* _093GustofWind { new TrainerCard(
        "Gust of Wind", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 93, Rarity::Common
    )};

    DataCard* _094Potion { new TrainerCard(
        "Potion", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 94, Rarity::Common
    )};

    DataCard* _095Switch { new TrainerCard(
        "Switch", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 95, Rarity::Common
    )};

    DataCard* _096DoubleColorlessEnergy { new EnergyCard(
        "Double Colorless Energy", false, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 96, Rarity::Uncommon
    )};

    DataCard* _097FightingEnergy { new EnergyCard(
        "Fighting Energy", true, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 97, Rarity::None
    )};

    DataCard* _098FireEnergy { new EnergyCard(
        "Fire Energy", true, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 98, Rarity::None
    )};

    DataCard* _099GrassEnergy { new EnergyCard(
        "Grass Energy", true, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 99, Rarity::None
    )};

    DataCard* _100LightningEnergy { new EnergyCard(
        "Lightning Energy", true, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 100, Rarity::None
    )};

    DataCard* _101PsychicEnergy { new EnergyCard(
        "Psychic Energy", true, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 101, Rarity::None
    )};

    DataCard* _102WaterEnergy { new EnergyCard(
        "Water Energy", true, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 102, Rarity::None
    )};

}

using namespace BaseSet;
const Expansion base { "Base Set", "BS", ExpansionID::BaseSet,
	{
	    _001Alakazam, _002Blastoise, _003Chansey, _004Charizard, 
	    _005Clefairy, _006Gyarados, _007Hitmonchan, _008Machamp, 
	    _009Magneton, _010Mewtwo, _011Nidoking, _012Ninetales, 
	    _013Poliwrath, _014Raichu, _015Venusaur, _016Zapdos, 
	    _017Beedrill, _018Dragonair, _019Dugtrio, _020Electabuzz, 
	    _021Electrode, _022Pidgeotto, _023Arcanine, _024Charmeleon, 
	    _025Dewgong, _026Dratini, _027Farfetchd, _028Growlithe, 
	    _029Haunter, _030Ivysaur, _031Jynx, _032Kadabra, 
	    _033Kakuna, _034Machoke, _035Magikarp, _036Magmar, 
	    _037Nidorino, _038Poliwhirl, _039Porygon, _040Raticate, 
	    _041Seel, _042Wartortle, _043Abra, _044Bulbasaur, 
	    _045Caterpie, _046Charmander, _047Diglett, _048Doduo, 
	    _049Drowzee, _050Gastly, _051Koffing, _052Machop, 
	    _053Magnemite, _054Metapod, _055NidoranM, _056Onix, 
	    _057Pidgey, _058Pikachu, _059Poliwag, _060Ponyta, 
	    _061Rattata, _062Sandshrew, _063Squirtle, _064Starmie, 
	    _065Staryu, _066Tangela, _067Voltorb, _068Vulpix, 
	    _069Weedle, _070ClefairyDoll, _071ComputerSearch, _072DevolutionSpray, 
	    _073ImposterProfessorOak, _074ItemFinder, _075Lass, _076PokémonBreeder, 
	    _077PokémonTrader, _078ScoopUp, _079SuperEnergyRemoval, _080Defender, 
	    _081EnergyRetrieval, _082FullHeal, _083Maintenance, _084PlusPower, 
	    _085PokémonCenter, _086PokémonFlute, _087Pokédex, _088ProfessorOak, 
	    _089Revive, _090SuperPotion, _091Bill, _092EnergyRemoval, 
	    _093GustofWind, _094Potion, _095Switch, _096DoubleColorlessEnergy, 
	    _097FightingEnergy, _098FireEnergy, _099GrassEnergy, _100LightningEnergy, 
	    _101PsychicEnergy, _102WaterEnergy, 
	}};
}}