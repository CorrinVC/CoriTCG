#pragma once

#include "../EnergyCard.h"
#include "../Expansion.h"
#include "../PokemonCard.h"
#include "../TrainerCard.h"

namespace Cori { namespace Expansions { namespace BaseSet {

    inline DataCard* _001Alakazam { (new PokemonCard(
        "Alakazam", 80, EnergyType::Psychic, Stage::Stage2, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 1, Rarity::HoloRare))
        ->evolvesFrom("Kadabra")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _002Blastoise { (new PokemonCard(
        "Blastoise", 100, EnergyType::Water, Stage::Stage2, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 2, Rarity::HoloRare))
        ->evolvesFrom("Wartortle")->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _003Chansey { (new PokemonCard(
        "Chansey", 120, EnergyType::Colorless, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 3, Rarity::HoloRare))
        ->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _004Charizard { (new PokemonCard(
        "Charizard", 120, EnergyType::Fire, Stage::Stage2, 3,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 4, Rarity::HoloRare))
        ->evolvesFrom("Charmeleon")->weakTo(EnergyType::Water)->resists(EnergyType::Fighting)
    };

    inline DataCard* _005Clefairy { (new PokemonCard(
        "Clefairy", 40, EnergyType::Colorless, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 5, Rarity::HoloRare))
        ->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _006Gyarados { (new PokemonCard(
        "Gyarados", 100, EnergyType::Water, Stage::Stage1, 3,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 6, Rarity::HoloRare))
        ->evolvesFrom("Magikarp")->weakTo(EnergyType::Grass)->resists(EnergyType::Fighting)
    };

    inline DataCard* _007Hitmonchan { (new PokemonCard(
        "Hitmonchan", 70, EnergyType::Fighting, Stage::Basic, 2,
        "Ken Sugimori", ExpansionID::BaseSet, 7, Rarity::HoloRare))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _008Machamp { (new PokemonCard(
        "Machamp", 100, EnergyType::Fighting, Stage::Stage2, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 8, Rarity::HoloRare))
        ->evolvesFrom("Machoke")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _009Magneton { (new PokemonCard(
        "Magneton", 60, EnergyType::Lightning, Stage::Stage1, 1,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 9, Rarity::HoloRare))
        ->evolvesFrom("Magnemite")->weakTo(EnergyType::Fighting)
    };

    inline DataCard* _010Mewtwo { (new PokemonCard(
        "Mewtwo", 60, EnergyType::Psychic, Stage::Basic, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 10, Rarity::HoloRare))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _011Nidoking { (new PokemonCard(
        "Nidoking", 90, EnergyType::Grass, Stage::Stage2, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 11, Rarity::HoloRare))
        ->evolvesFrom("Nidorino")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _012Ninetales { (new PokemonCard(
        "Ninetales", 80, EnergyType::Fire, Stage::Stage1, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 12, Rarity::HoloRare))
        ->evolvesFrom("Vulpix")->weakTo(EnergyType::Water)
    };

    inline DataCard* _013Poliwrath { (new PokemonCard(
        "Poliwrath", 90, EnergyType::Water, Stage::Stage2, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 13, Rarity::HoloRare))
        ->evolvesFrom("Poliwhirl")->weakTo(EnergyType::Grass)
    };

    inline DataCard* _014Raichu { (new PokemonCard(
        "Raichu", 80, EnergyType::Lightning, Stage::Stage1, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 14, Rarity::HoloRare))
        ->evolvesFrom("Pikachu")->weakTo(EnergyType::Fighting)
    };

    inline DataCard* _015Venusaur { (new PokemonCard(
        "Venusaur", 100, EnergyType::Grass, Stage::Stage2, 2,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 15, Rarity::HoloRare))
        ->evolvesFrom("Ivysaur")->weakTo(EnergyType::Fire)
    };

    inline DataCard* _016Zapdos { (new PokemonCard(
        "Zapdos", 90, EnergyType::Lightning, Stage::Basic, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 16, Rarity::HoloRare))
        ->resists(EnergyType::Fighting)
    };

    inline DataCard* _017Beedrill { (new PokemonCard(
        "Beedrill", 80, EnergyType::Grass, Stage::Stage2, 0,
        "Ken Sugimori", ExpansionID::BaseSet, 17, Rarity::Rare))
        ->evolvesFrom("Kakuna")->weakTo(EnergyType::Fire)->resists(EnergyType::Fighting)
    };

    inline DataCard* _018Dragonair { (new PokemonCard(
        "Dragonair", 80, EnergyType::Colorless, Stage::Stage1, 2,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 18, Rarity::Rare))
        ->evolvesFrom("Dratini")->resists(EnergyType::Psychic)
    };

    inline DataCard* _019Dugtrio { (new PokemonCard(
        "Dugtrio", 70, EnergyType::Fighting, Stage::Stage1, 2,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 19, Rarity::Rare))
        ->evolvesFrom("Diglett")->weakTo(EnergyType::Grass)->resists(EnergyType::Lightning)
    };

    inline DataCard* _020Electabuzz { (new PokemonCard(
        "Electabuzz", 70, EnergyType::Lightning, Stage::Basic, 2,
        "Ken Sugimori", ExpansionID::BaseSet, 20, Rarity::Rare))
        ->weakTo(EnergyType::Fighting)
    };

    inline DataCard* _021Electrode { (new PokemonCard(
        "Electrode", 80, EnergyType::Lightning, Stage::Stage1, 1,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 21, Rarity::Rare))
        ->evolvesFrom("Voltorb")->weakTo(EnergyType::Fighting)
    };

    inline DataCard* _022Pidgeotto { (new PokemonCard(
        "Pidgeotto", 60, EnergyType::Colorless, Stage::Stage1, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 22, Rarity::Rare))
        ->evolvesFrom("Pidgey")->weakTo(EnergyType::Lightning)->resists(EnergyType::Fighting)
    };

    inline DataCard* _023Arcanine { (new PokemonCard(
        "Arcanine", 100, EnergyType::Fire, Stage::Stage1, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 23, Rarity::Uncommon))
        ->evolvesFrom("Growlithe")->weakTo(EnergyType::Water)
    };

    inline DataCard* _024Charmeleon { (new PokemonCard(
        "Charmeleon", 80, EnergyType::Fire, Stage::Stage1, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 24, Rarity::Uncommon))
        ->evolvesFrom("Charmander")->weakTo(EnergyType::Water)
    };

    inline DataCard* _025Dewgong { (new PokemonCard(
        "Dewgong", 80, EnergyType::Water, Stage::Stage1, 3,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 25, Rarity::Uncommon))
        ->evolvesFrom("Seel")->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _026Dratini { (new PokemonCard(
        "Dratini", 40, EnergyType::Colorless, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 26, Rarity::Uncommon))
        ->resists(EnergyType::Psychic)
    };

    inline DataCard* _027Farfetchd { (new PokemonCard(
        "Farfetch'd", 50, EnergyType::Colorless, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 27, Rarity::Uncommon))
        ->weakTo(EnergyType::Lightning)->resists(EnergyType::Fighting)
    };

    inline DataCard* _028Growlithe { (new PokemonCard(
        "Growlithe", 60, EnergyType::Fire, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 28, Rarity::Uncommon))
        ->weakTo(EnergyType::Water)
    };

    inline DataCard* _029Haunter { (new PokemonCard(
        "Haunter", 60, EnergyType::Psychic, Stage::Stage1, 1,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 29, Rarity::Uncommon))
        ->evolvesFrom("Gastly")->resists(EnergyType::Fighting)
    };

    inline DataCard* _030Ivysaur { (new PokemonCard(
        "Ivysaur", 60, EnergyType::Grass, Stage::Stage1, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 30, Rarity::Uncommon))
        ->evolvesFrom("Bulbasaur")->weakTo(EnergyType::Fire)
    };

    inline DataCard* _031Jynx { (new PokemonCard(
        "Jynx", 70, EnergyType::Psychic, Stage::Basic, 2,
        "Ken Sugimori", ExpansionID::BaseSet, 31, Rarity::Uncommon))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _032Kadabra { (new PokemonCard(
        "Kadabra", 60, EnergyType::Psychic, Stage::Stage1, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 32, Rarity::Uncommon))
        ->evolvesFrom("Abra")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _033Kakuna { (new PokemonCard(
        "Kakuna", 80, EnergyType::Grass, Stage::Stage1, 2,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 33, Rarity::Uncommon))
        ->evolvesFrom("Weedle")->weakTo(EnergyType::Fire)
    };

    inline DataCard* _034Machoke { (new PokemonCard(
        "Machoke", 80, EnergyType::Fighting, Stage::Stage1, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 34, Rarity::Uncommon))
        ->evolvesFrom("Machop")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _035Magikarp { (new PokemonCard(
        "Magikarp", 30, EnergyType::Water, Stage::Basic, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 35, Rarity::Uncommon))
        ->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _036Magmar { (new PokemonCard(
        "Magmar", 50, EnergyType::Fire, Stage::Basic, 2,
        "Ken Sugimori", ExpansionID::BaseSet, 36, Rarity::Uncommon))
        ->weakTo(EnergyType::Water)
    };

    inline DataCard* _037Nidorino { (new PokemonCard(
        "Nidorino", 60, EnergyType::Grass, Stage::Stage1, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 37, Rarity::Uncommon))
        ->evolvesFrom(L"Nidoran ♂")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _038Poliwhirl { (new PokemonCard(
        "Poliwhirl", 60, EnergyType::Water, Stage::Stage1, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 38, Rarity::Uncommon))
        ->evolvesFrom("Poliwag")->weakTo(EnergyType::Grass)
    };

    inline DataCard* _039Porygon { (new PokemonCard(
        "Porygon", 30, EnergyType::Colorless, Stage::Basic, 1,
        "Tomoaki Imakuni", ExpansionID::BaseSet, 39, Rarity::Uncommon))
        ->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _040Raticate { (new PokemonCard(
        "Raticate", 60, EnergyType::Colorless, Stage::Stage1, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 40, Rarity::Uncommon))
        ->evolvesFrom("Rattata")->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _041Seel { (new PokemonCard(
        "Seel", 60, EnergyType::Water, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 41, Rarity::Uncommon))
        ->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _042Wartortle { (new PokemonCard(
        "Wartortle", 70, EnergyType::Water, Stage::Stage1, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 42, Rarity::Uncommon))
        ->evolvesFrom("Squirtle")->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _043Abra { (new PokemonCard(
        "Abra", 30, EnergyType::Psychic, Stage::Basic, 0,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 43, Rarity::Common))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _044Bulbasaur { (new PokemonCard(
        "Bulbasaur", 40, EnergyType::Grass, Stage::Basic, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 44, Rarity::Common))
        ->weakTo(EnergyType::Fire)
    };

    inline DataCard* _045Caterpie { (new PokemonCard(
        "Caterpie", 40, EnergyType::Grass, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 45, Rarity::Common))
        ->weakTo(EnergyType::Fire)
    };

    inline DataCard* _046Charmander { (new PokemonCard(
        "Charmander", 50, EnergyType::Fire, Stage::Basic, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 46, Rarity::Common))
        ->weakTo(EnergyType::Water)
    };

    inline DataCard* _047Diglett { (new PokemonCard(
        "Diglett", 30, EnergyType::Fighting, Stage::Basic, 0,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 47, Rarity::Common))
        ->weakTo(EnergyType::Grass)->resists(EnergyType::Lightning)
    };

    inline DataCard* _048Doduo { (new PokemonCard(
        "Doduo", 50, EnergyType::Colorless, Stage::Basic, 0,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 48, Rarity::Common))
        ->weakTo(EnergyType::Lightning)->resists(EnergyType::Fighting)
    };

    inline DataCard* _049Drowzee { (new PokemonCard(
        "Drowzee", 50, EnergyType::Psychic, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 49, Rarity::Common))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _050Gastly { (new PokemonCard(
        "Gastly", 30, EnergyType::Psychic, Stage::Basic, 0,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 50, Rarity::Common))
        ->resists(EnergyType::Fighting)
    };

    inline DataCard* _051Koffing { (new PokemonCard(
        "Koffing", 50, EnergyType::Grass, Stage::Basic, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 51, Rarity::Common))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _052Machop { (new PokemonCard(
        "Machop", 50, EnergyType::Fighting, Stage::Basic, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 52, Rarity::Common))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _053Magnemite { (new PokemonCard(
        "Magnemite", 40, EnergyType::Lightning, Stage::Basic, 1,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 53, Rarity::Common))
        ->weakTo(EnergyType::Fighting)
    };

    inline DataCard* _054Metapod { (new PokemonCard(
        "Metapod", 70, EnergyType::Grass, Stage::Stage1, 2,
        "Ken Sugimori", ExpansionID::BaseSet, 54, Rarity::Common))
        ->evolvesFrom("Caterpie")->weakTo(EnergyType::Fire)
    };

    inline DataCard* _055NidoranM { (new PokemonCard(
        L"Nidoran ♂", 40, EnergyType::Grass, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 55, Rarity::Common))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _056Onix { (new PokemonCard(
        "Onix", 90, EnergyType::Fighting, Stage::Basic, 3,
        "Ken Sugimori", ExpansionID::BaseSet, 56, Rarity::Common))
        ->weakTo(EnergyType::Grass)
    };

    inline DataCard* _057Pidgey { (new PokemonCard(
        "Pidgey", 40, EnergyType::Colorless, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 57, Rarity::Common))
        ->weakTo(EnergyType::Lightning)->resists(EnergyType::Fighting)
    };

    inline DataCard* _058Pikachu { (new PokemonCard(
        "Pikachu", 40, EnergyType::Lightning, Stage::Basic, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 58, Rarity::Common))
        ->weakTo(EnergyType::Fighting)
    };

    inline DataCard* _059Poliwag { (new PokemonCard(
        "Poliwag", 40, EnergyType::Water, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 59, Rarity::Common))
        ->weakTo(EnergyType::Grass)
    };

    inline DataCard* _060Ponyta { (new PokemonCard(
        "Ponyta", 40, EnergyType::Fire, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 60, Rarity::Common))
        ->weakTo(EnergyType::Water)
    };

    inline DataCard* _061Rattata { (new PokemonCard(
        "Rattata", 30, EnergyType::Colorless, Stage::Basic, 0,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 61, Rarity::Common))
        ->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _062Sandshrew { (new PokemonCard(
        "Sandshrew", 40, EnergyType::Fighting, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 62, Rarity::Common))
        ->weakTo(EnergyType::Grass)->resists(EnergyType::Lightning)
    };

    inline DataCard* _063Squirtle { (new PokemonCard(
        "Squirtle", 40, EnergyType::Water, Stage::Basic, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 63, Rarity::Common))
        ->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _064Starmie { (new PokemonCard(
        "Starmie", 60, EnergyType::Water, Stage::Stage1, 1,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 64, Rarity::Common))
        ->evolvesFrom("Staryu")->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _065Staryu { (new PokemonCard(
        "Staryu", 40, EnergyType::Water, Stage::Basic, 1,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 65, Rarity::Common))
        ->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _066Tangela { (new PokemonCard(
        "Tangela", 50, EnergyType::Grass, Stage::Basic, 2,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 66, Rarity::Common))
        ->weakTo(EnergyType::Fire)
    };

    inline DataCard* _067Voltorb { (new PokemonCard(
        "Voltorb", 40, EnergyType::Lightning, Stage::Basic, 1,
        "Keiji Kinebuchi", ExpansionID::BaseSet, 67, Rarity::Common))
        ->weakTo(EnergyType::Fighting)
    };

    inline DataCard* _068Vulpix { (new PokemonCard(
        "Vulpix", 50, EnergyType::Fire, Stage::Basic, 1,
        "Ken Sugimori", ExpansionID::BaseSet, 68, Rarity::Common))
        ->weakTo(EnergyType::Water)
    };

    inline DataCard* _069Weedle { (new PokemonCard(
        "Weedle", 40, EnergyType::Grass, Stage::Basic, 1,
        "Mitsuhiro Arita", ExpansionID::BaseSet, 69, Rarity::Common))
        ->weakTo(EnergyType::Fire)
    };

    inline DataCard* _070ClefairyDoll { new TrainerCard(
        "Clefairy Doll", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 70, Rarity::Rare
    )};

    inline DataCard* _071ComputerSearch { new TrainerCard(
        "Computer Search", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 71, Rarity::Rare
    )};

    inline DataCard* _072DevolutionSpray { new TrainerCard(
        "Devolution Spray", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 72, Rarity::Rare
    )};

    inline DataCard* _073ImposterProfessorOak { new TrainerCard(
        "Imposter Professor Oak", TrainerType::Item, "Ken Sugimori",
        ExpansionID::BaseSet, 73, Rarity::Rare
    )};

    inline DataCard* _074ItemFinder { new TrainerCard(
        "Item Finder", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 74, Rarity::Rare
    )};

    inline DataCard* _075Lass { new TrainerCard(
        "Lass", TrainerType::Item, "Ken Sugimori",
        ExpansionID::BaseSet, 75, Rarity::Rare
    )};

    inline DataCard* _076PokémonBreeder { new TrainerCard(
        L"Pokémon Breeder", TrainerType::Supporter, "Ken Sugimori",
        ExpansionID::BaseSet, 76, Rarity::Rare
    )};

    inline DataCard* _077PokémonTrader { new TrainerCard(
        L"Pokémon Trader", TrainerType::Item, "Ken Sugimori",
        ExpansionID::BaseSet, 77, Rarity::Rare
    )};

    inline DataCard* _078ScoopUp { new TrainerCard(
        "Scoop Up", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 78, Rarity::Rare
    )};

    inline DataCard* _079SuperEnergyRemoval { new TrainerCard(
        "Super Energy Removal", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 79, Rarity::Rare
    )};

    inline DataCard* _080Defender { new TrainerCard(
        "Defender", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 80, Rarity::Uncommon
    )};

    inline DataCard* _081EnergyRetrieval { new TrainerCard(
        "Energy Retrieval", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 81, Rarity::Uncommon
    )};

    inline DataCard* _082FullHeal { new TrainerCard(
        "Full Heal", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 82, Rarity::Uncommon
    )};

    inline DataCard* _083Maintenance { new TrainerCard(
        "Maintenance", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 83, Rarity::Uncommon
    )};

    inline DataCard* _084PlusPower { new TrainerCard(
        "PlusPower", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 84, Rarity::Uncommon
    )};

    inline DataCard* _085PokémonCenter { new TrainerCard(
        L"Pokémon Center", TrainerType::Stadium, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 85, Rarity::Uncommon
    )};

    inline DataCard* _086PokémonFlute { new TrainerCard(
        L"Pokémon Flute", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 86, Rarity::Uncommon
    )};

    inline DataCard* _087Pokédex { new TrainerCard(
        L"Pokédex", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 87, Rarity::Uncommon
    )};

    inline DataCard* _088ProfessorOak { new TrainerCard(
        "Professor Oak", TrainerType::Item, "Ken Sugimori",
        ExpansionID::BaseSet, 88, Rarity::Uncommon
    )};

    inline DataCard* _089Revive { new TrainerCard(
        "Revive", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 89, Rarity::Uncommon
    )};

    inline DataCard* _090SuperPotion { new TrainerCard(
        "Super Potion", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 90, Rarity::Uncommon
    )};

    inline DataCard* _091Bill { new TrainerCard(
        "Bill", TrainerType::Supporter, "Ken Sugimori",
        ExpansionID::BaseSet, 91, Rarity::Common
    )};

    inline DataCard* _092EnergyRemoval { new TrainerCard(
        "Energy Removal", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 92, Rarity::Common
    )};

    inline DataCard* _093GustofWind { new TrainerCard(
        "Gust of Wind", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 93, Rarity::Common
    )};

    inline DataCard* _094Potion { new TrainerCard(
        "Potion", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 94, Rarity::Common
    )};

    inline DataCard* _095Switch { new TrainerCard(
        "Switch", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 95, Rarity::Common
    )};

    inline DataCard* _096DoubleColorlessEnergy { new EnergyCard(
        "Double Colorless Energy", false, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 96, Rarity::Uncommon
    )};

    inline DataCard* _097FightingEnergy { new EnergyCard(
        "Fighting Energy", true, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 97, Rarity::None
    )};

    inline DataCard* _098FireEnergy { new EnergyCard(
        "Fire Energy", true, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 98, Rarity::None
    )};

    inline DataCard* _099GrassEnergy { new EnergyCard(
        "Grass Energy", true, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 99, Rarity::None
    )};

    inline DataCard* _100LightningEnergy { new EnergyCard(
        "Lightning Energy", true, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 100, Rarity::None
    )};

    inline DataCard* _101PsychicEnergy { new EnergyCard(
        "Psychic Energy", true, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 101, Rarity::None
    )};

    inline DataCard* _102WaterEnergy { new EnergyCard(
        "Water Energy", true, "Keiji Kinebuchi",
        ExpansionID::BaseSet, 102, Rarity::None
    )};

}

using namespace BaseSet;
inline Expansion base { "Base Set", ExpansionID::BaseSet, 11,
	{
	    _001Alakazam, _002Blastoise, _003Chansey, _004Charizard, 
	    _005Clefairy, _006Gyarados, _007Hitmonchan, _008Machamp, 
	    _009Magneton, _010Mewtwo, _011Nidoking, _012Ninetales, 
	    _013Poliwrath, BaseSet::_014Raichu, _015Venusaur, _016Zapdos, 
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