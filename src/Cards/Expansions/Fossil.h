#pragma once

#include "../EnergyCard.h"
#include "../Expansion.h"
#include "../PokemonCard.h"
#include "../TrainerCard.h"

namespace Cori { namespace Expansions { namespace Fossil {

    inline DataCard* _001Aerodactyl { (new PokemonCard(
        "Aerodactyl", 60, EnergyType::Fighting, Stage::Stage1, 2, 142,
        "Kagemaru Himeno", ExpansionID::Fossil, 1, Rarity::HoloRare))
        ->weakTo(EnergyType::Grass)->resists(EnergyType::Fighting)
    };

    inline DataCard* _002Articuno { (new PokemonCard(
        "Articuno", 70, EnergyType::Water, Stage::Basic, 2, 144,
        "Mitsuhiro Arita", ExpansionID::Fossil, 2, Rarity::HoloRare))
        ->resists(EnergyType::Fighting)
    };

    inline DataCard* _003Ditto { (new PokemonCard(
        "Ditto", 50, EnergyType::Colorless, Stage::Basic, 1, 132,
        "Keiji Kinebuchi", ExpansionID::Fossil, 3, Rarity::HoloRare))
        ->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _004Dragonite { (new PokemonCard(
        "Dragonite", 100, EnergyType::Colorless, Stage::Stage2, 1, 149,
        "Kagemaru Himeno", ExpansionID::Fossil, 4, Rarity::HoloRare))
        ->evolvesFrom("Dragonair")->resists(EnergyType::Fighting)
    };

    inline DataCard* _005Gengar { (new PokemonCard(
        "Gengar", 80, EnergyType::Psychic, Stage::Stage2, 1, 94,
        "Keiji Kinebuchi", ExpansionID::Fossil, 5, Rarity::HoloRare))
        ->evolvesFrom("Haunter")->resists(EnergyType::Fighting)
    };

    inline DataCard* _006Haunter { (new PokemonCard(
        "Haunter", 50, EnergyType::Psychic, Stage::Stage1, 0, 93,
        "Ken Sugimori", ExpansionID::Fossil, 6, Rarity::HoloRare))
        ->evolvesFrom("Gastly")->resists(EnergyType::Fighting)
    };

    inline DataCard* _007Hitmonlee { (new PokemonCard(
        "Hitmonlee", 60, EnergyType::Fighting, Stage::Basic, 1, 106,
        "Ken Sugimori", ExpansionID::Fossil, 7, Rarity::HoloRare))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _008Hypno { (new PokemonCard(
        "Hypno", 90, EnergyType::Psychic, Stage::Stage1, 2, 97,
        "Ken Sugimori", ExpansionID::Fossil, 8, Rarity::HoloRare))
        ->evolvesFrom("Drowzee")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _009Kabutops { (new PokemonCard(
        "Kabutops", 60, EnergyType::Fighting, Stage::Stage2, 1, 141,
        "Ken Sugimori", ExpansionID::Fossil, 9, Rarity::HoloRare))
        ->evolvesFrom("Kabuto")->weakTo(EnergyType::Grass)
    };

    inline DataCard* _010Lapras { (new PokemonCard(
        "Lapras", 80, EnergyType::Water, Stage::Basic, 2, 131,
        "Ken Sugimori", ExpansionID::Fossil, 10, Rarity::HoloRare))
        ->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _011Magneton { (new PokemonCard(
        "Magneton", 80, EnergyType::Lightning, Stage::Stage1, 2, 82,
        "Ken Sugimori", ExpansionID::Fossil, 11, Rarity::HoloRare))
        ->evolvesFrom("Magnemite")->weakTo(EnergyType::Fighting)
    };

    inline DataCard* _012Moltres { (new PokemonCard(
        "Moltres", 70, EnergyType::Fire, Stage::Basic, 2, 146,
        "Mitsuhiro Arita", ExpansionID::Fossil, 12, Rarity::HoloRare))
        ->resists(EnergyType::Fighting)
    };

    inline DataCard* _013Muk { (new PokemonCard(
        "Muk", 70, EnergyType::Grass, Stage::Stage1, 2, 89,
        "Mitsuhiro Arita", ExpansionID::Fossil, 13, Rarity::HoloRare))
        ->evolvesFrom("Grimer")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _014Raichu { (new PokemonCard(
        "Raichu", 90, EnergyType::Lightning, Stage::Stage1, 1, 26,
        "Mitsuhiro Arita", ExpansionID::Fossil, 14, Rarity::HoloRare))
        ->evolvesFrom("Pikachu")->weakTo(EnergyType::Fighting)
    };

    inline DataCard* _015Zapdos { (new PokemonCard(
        "Zapdos", 80, EnergyType::Lightning, Stage::Basic, 2, 145,
        "Mitsuhiro Arita", ExpansionID::Fossil, 15, Rarity::HoloRare))
        ->resists(EnergyType::Fighting)
    };

    inline DataCard* _016Aerodactyl { (new PokemonCard(
        "Aerodactyl", 60, EnergyType::Fighting, Stage::Stage1, 2, 142,
        "Kagemaru Himeno", ExpansionID::Fossil, 16, Rarity::Rare))
        ->weakTo(EnergyType::Grass)->resists(EnergyType::Fighting)
    };

    inline DataCard* _017Articuno { (new PokemonCard(
        "Articuno", 70, EnergyType::Water, Stage::Basic, 2, 144,
        "Mitsuhiro Arita", ExpansionID::Fossil, 17, Rarity::Rare))
        ->resists(EnergyType::Fighting)
    };

    inline DataCard* _018Ditto { (new PokemonCard(
        "Ditto", 50, EnergyType::Colorless, Stage::Basic, 1, 132,
        "Keiji Kinebuchi", ExpansionID::Fossil, 18, Rarity::Rare))
        ->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _019Dragonite { (new PokemonCard(
        "Dragonite", 100, EnergyType::Colorless, Stage::Stage2, 1, 149,
        "Kagemaru Himeno", ExpansionID::Fossil, 19, Rarity::Rare))
        ->evolvesFrom("Dragonair")->resists(EnergyType::Fighting)
    };

    inline DataCard* _020Gengar { (new PokemonCard(
        "Gengar", 80, EnergyType::Psychic, Stage::Stage2, 1, 94,
        "Keiji Kinebuchi", ExpansionID::Fossil, 20, Rarity::Rare))
        ->evolvesFrom("Haunter")->resists(EnergyType::Fighting)
    };

    inline DataCard* _021Haunter { (new PokemonCard(
        "Haunter", 50, EnergyType::Psychic, Stage::Stage1, 0, 93,
        "Ken Sugimori", ExpansionID::Fossil, 21, Rarity::Rare))
        ->evolvesFrom("Gastly")->resists(EnergyType::Fighting)
    };

    inline DataCard* _022Hitmonlee { (new PokemonCard(
        "Hitmonlee", 60, EnergyType::Fighting, Stage::Basic, 1, 106,
        "Ken Sugimori", ExpansionID::Fossil, 22, Rarity::Rare))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _023Hypno { (new PokemonCard(
        "Hypno", 90, EnergyType::Psychic, Stage::Stage1, 2, 97,
        "Ken Sugimori", ExpansionID::Fossil, 23, Rarity::Rare))
        ->evolvesFrom("Drowzee")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _024Kabutops { (new PokemonCard(
        "Kabutops", 60, EnergyType::Fighting, Stage::Stage2, 1, 141,
        "Ken Sugimori", ExpansionID::Fossil, 24, Rarity::Rare))
        ->evolvesFrom("Kabuto")->weakTo(EnergyType::Grass)
    };

    inline DataCard* _025Lapras { (new PokemonCard(
        "Lapras", 80, EnergyType::Water, Stage::Basic, 2, 131,
        "Ken Sugimori", ExpansionID::Fossil, 25, Rarity::Rare))
        ->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _026Magneton { (new PokemonCard(
        "Magneton", 80, EnergyType::Lightning, Stage::Stage1, 2, 82,
        "Ken Sugimori", ExpansionID::Fossil, 26, Rarity::Rare))
        ->evolvesFrom("Magnemite")->weakTo(EnergyType::Fighting)
    };

    inline DataCard* _027Moltres { (new PokemonCard(
        "Moltres", 70, EnergyType::Fire, Stage::Basic, 2, 146,
        "Mitsuhiro Arita", ExpansionID::Fossil, 27, Rarity::Rare))
        ->resists(EnergyType::Fighting)
    };

    inline DataCard* _028Muk { (new PokemonCard(
        "Muk", 70, EnergyType::Grass, Stage::Stage1, 2, 89,
        "Mitsuhiro Arita", ExpansionID::Fossil, 28, Rarity::Rare))
        ->evolvesFrom("Grimer")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _029Raichu { (new PokemonCard(
        "Raichu", 90, EnergyType::Lightning, Stage::Stage1, 1, 26,
        "Mitsuhiro Arita", ExpansionID::Fossil, 29, Rarity::Rare))
        ->evolvesFrom("Pikachu")->weakTo(EnergyType::Fighting)
    };

    inline DataCard* _030Zapdos { (new PokemonCard(
        "Zapdos", 80, EnergyType::Lightning, Stage::Basic, 2, 145,
        "Mitsuhiro Arita", ExpansionID::Fossil, 30, Rarity::Rare))
        ->resists(EnergyType::Fighting)
    };

    inline DataCard* _031Arbok { (new PokemonCard(
        "Arbok", 60, EnergyType::Grass, Stage::Stage1, 2, 24,
        "Ken Sugimori", ExpansionID::Fossil, 31, Rarity::Uncommon))
        ->evolvesFrom("Ekans")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _032Cloyster { (new PokemonCard(
        "Cloyster", 50, EnergyType::Water, Stage::Stage1, 2, 91,
        "Kagemaru Himeno", ExpansionID::Fossil, 32, Rarity::Uncommon))
        ->evolvesFrom("Shellder")->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _033Gastly { (new PokemonCard(
        "Gastly", 50, EnergyType::Psychic, Stage::Basic, 0, 92,
        "Mitsuhiro Arita", ExpansionID::Fossil, 33, Rarity::Uncommon))
        ->resists(EnergyType::Fighting)
    };

    inline DataCard* _034Golbat { (new PokemonCard(
        "Golbat", 60, EnergyType::Grass, Stage::Stage1, 0, 42,
        "Kagemaru Himeno", ExpansionID::Fossil, 34, Rarity::Uncommon))
        ->evolvesFrom("Zubat")->weakTo(EnergyType::Psychic)->resists(EnergyType::Fighting)
    };

    inline DataCard* _035Golduck { (new PokemonCard(
        "Golduck", 70, EnergyType::Water, Stage::Stage1, 1, 55,
        "Kagemaru Himeno", ExpansionID::Fossil, 35, Rarity::Uncommon))
        ->evolvesFrom("Psyduck")->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _036Golem { (new PokemonCard(
        "Golem", 80, EnergyType::Fighting, Stage::Stage2, 4, 76,
        "Kagemaru Himeno", ExpansionID::Fossil, 36, Rarity::Uncommon))
        ->evolvesFrom("Graveler")->weakTo(EnergyType::Grass)
    };

    inline DataCard* _037Graveler { (new PokemonCard(
        "Graveler", 60, EnergyType::Fighting, Stage::Stage1, 2, 75,
        "Kagemaru Himeno", ExpansionID::Fossil, 37, Rarity::Uncommon))
        ->evolvesFrom("Geodude")->weakTo(EnergyType::Grass)
    };

    inline DataCard* _038Kingler { (new PokemonCard(
        "Kingler", 60, EnergyType::Water, Stage::Stage1, 3, 99,
        "Kagemaru Himeno", ExpansionID::Fossil, 38, Rarity::Uncommon))
        ->evolvesFrom("Krabby")->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _039Magmar { (new PokemonCard(
        "Magmar", 70, EnergyType::Fire, Stage::Basic, 1, 126,
        "Mitsuhiro Arita", ExpansionID::Fossil, 39, Rarity::Uncommon))
        ->weakTo(EnergyType::Water)
    };

    inline DataCard* _040Omastar { (new PokemonCard(
        "Omastar", 70, EnergyType::Water, Stage::Stage2, 1, 139,
        "Ken Sugimori", ExpansionID::Fossil, 40, Rarity::Uncommon))
        ->evolvesFrom("Omanyte")->weakTo(EnergyType::Grass)
    };

    inline DataCard* _041Sandslash { (new PokemonCard(
        "Sandslash", 70, EnergyType::Fighting, Stage::Stage1, 1, 28,
        "Ken Sugimori", ExpansionID::Fossil, 41, Rarity::Uncommon))
        ->evolvesFrom("Sandshrew")->weakTo(EnergyType::Grass)->resists(EnergyType::Lightning)
    };

    inline DataCard* _042Seadra { (new PokemonCard(
        "Seadra", 60, EnergyType::Water, Stage::Stage1, 1, 117,
        "Ken Sugimori", ExpansionID::Fossil, 42, Rarity::Uncommon))
        ->evolvesFrom("Horsea")->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _043Slowbro { (new PokemonCard(
        "Slowbro", 60, EnergyType::Psychic, Stage::Stage1, 1, 80,
        "Kagemaru Himeno", ExpansionID::Fossil, 43, Rarity::Uncommon))
        ->evolvesFrom("Slowpoke")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _044Tentacruel { (new PokemonCard(
        "Tentacruel", 60, EnergyType::Water, Stage::Stage1, 0, 73,
        "Kagemaru Himeno", ExpansionID::Fossil, 44, Rarity::Uncommon))
        ->evolvesFrom("Tentacool")->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _045Weezing { (new PokemonCard(
        "Weezing", 60, EnergyType::Grass, Stage::Stage1, 1, 110,
        "Mitsuhiro Arita", ExpansionID::Fossil, 45, Rarity::Uncommon))
        ->evolvesFrom("Koffing")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _046Ekans { (new PokemonCard(
        "Ekans", 40, EnergyType::Grass, Stage::Basic, 1, 23,
        "Kagemaru Himeno", ExpansionID::Fossil, 46, Rarity::Common))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _047Geodude { (new PokemonCard(
        "Geodude", 50, EnergyType::Fighting, Stage::Basic, 1, 74,
        "Kagemaru Himeno", ExpansionID::Fossil, 47, Rarity::Common))
        ->weakTo(EnergyType::Grass)
    };

    inline DataCard* _048Grimer { (new PokemonCard(
        "Grimer", 50, EnergyType::Grass, Stage::Basic, 1, 88,
        "Mitsuhiro Arita", ExpansionID::Fossil, 48, Rarity::Common))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _049Horsea { (new PokemonCard(
        "Horsea", 40, EnergyType::Water, Stage::Basic, 0, 116,
        "Mitsuhiro Arita", ExpansionID::Fossil, 49, Rarity::Common))
        ->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _050Kabuto { (new PokemonCard(
        "Kabuto", 30, EnergyType::Fighting, Stage::Stage1, 1, 140,
        "Ken Sugimori", ExpansionID::Fossil, 50, Rarity::Common))
        ->weakTo(EnergyType::Grass)
    };

    inline DataCard* _051Krabby { (new PokemonCard(
        "Krabby", 50, EnergyType::Water, Stage::Basic, 2, 98,
        "Mitsuhiro Arita", ExpansionID::Fossil, 51, Rarity::Common))
        ->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _052Omanyte { (new PokemonCard(
        "Omanyte", 40, EnergyType::Water, Stage::Stage1, 1, 138,
        "Kagemaru Himeno", ExpansionID::Fossil, 52, Rarity::Common))
        ->weakTo(EnergyType::Grass)
    };

    inline DataCard* _053Psyduck { (new PokemonCard(
        "Psyduck", 50, EnergyType::Water, Stage::Basic, 1, 54,
        "Kagemaru Himeno", ExpansionID::Fossil, 53, Rarity::Common))
        ->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _054Shellder { (new PokemonCard(
        "Shellder", 30, EnergyType::Water, Stage::Basic, 1, 90,
        "Mitsuhiro Arita", ExpansionID::Fossil, 54, Rarity::Common))
        ->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _055Slowpoke { (new PokemonCard(
        "Slowpoke", 50, EnergyType::Psychic, Stage::Basic, 1, 79,
        "Miki Tanaka", ExpansionID::Fossil, 55, Rarity::Common))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _056Tentacool { (new PokemonCard(
        "Tentacool", 30, EnergyType::Water, Stage::Basic, 0, 72,
        "Kagemaru Himeno", ExpansionID::Fossil, 56, Rarity::Common))
        ->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _057Zubat { (new PokemonCard(
        "Zubat", 40, EnergyType::Grass, Stage::Basic, 0, 41,
        "Kagemaru Himeno", ExpansionID::Fossil, 57, Rarity::Common))
        ->weakTo(EnergyType::Psychic)->resists(EnergyType::Fighting)
    };

    inline DataCard* _058MrFuji { new TrainerCard(
        "Mr. Fuji", TrainerType::Item, "Ken Sugimori",
        ExpansionID::Fossil, 58, Rarity::Uncommon
    )};

    inline DataCard* _059EnergySearch { new TrainerCard(
        "Energy Search", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::Fossil, 59, Rarity::Common
    )};

    inline DataCard* _060Gambler { new TrainerCard(
        "Gambler", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::Fossil, 60, Rarity::Common
    )};

    inline DataCard* _061Recycle { new TrainerCard(
        "Recycle", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::Fossil, 61, Rarity::Common
    )};

    inline DataCard* _062MysteriousFossil { new TrainerCard(
        "Mysterious Fossil", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::Fossil, 62, Rarity::Common
    )};

}

using namespace Fossil;
inline Expansion fossil { "Fossil", ExpansionID::Fossil, 11,
	{
	    _001Aerodactyl, _002Articuno, _003Ditto, _004Dragonite, 
	    _005Gengar, _006Haunter, _007Hitmonlee, _008Hypno, 
	    _009Kabutops, _010Lapras, _011Magneton, _012Moltres, 
	    _013Muk, Fossil::_014Raichu, _015Zapdos, _016Aerodactyl, 
	    _017Articuno, _018Ditto, _019Dragonite, _020Gengar, 
	    _021Haunter, _022Hitmonlee, _023Hypno, _024Kabutops, 
	    _025Lapras, _026Magneton, _027Moltres, _028Muk, 
	    _029Raichu, _030Zapdos, _031Arbok, _032Cloyster, 
	    _033Gastly, _034Golbat, _035Golduck, _036Golem, 
	    _037Graveler, _038Kingler, _039Magmar, _040Omastar, 
	    _041Sandslash, _042Seadra, _043Slowbro, _044Tentacruel, 
	    _045Weezing, _046Ekans, _047Geodude, _048Grimer, 
	    _049Horsea, _050Kabuto, _051Krabby, _052Omanyte, 
	    _053Psyduck, _054Shellder, _055Slowpoke, _056Tentacool, 
	    _057Zubat, _058MrFuji, _059EnergySearch, _060Gambler, 
	    _061Recycle, _062MysteriousFossil, 
	}};
}}