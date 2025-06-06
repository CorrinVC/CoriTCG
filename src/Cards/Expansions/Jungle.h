#pragma once

#include "../EnergyCard.h"
#include "../Expansion.h"
#include "../PokemonCard.h"
#include "../TrainerCard.h"

namespace Cori { namespace Expansions { namespace Jungle {

    inline DataCard* _001Clefable { (new PokemonCard(
        "Clefable", 70, EnergyType::Colorless, Stage::Stage1, 2, 36,
        "Mitsuhiro Arita", ExpansionID::Jungle, 1, Rarity::HoloRare))
        ->evolvesFrom("Clefairy")->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _002Electrode { (new PokemonCard(
        "Electrode", 90, EnergyType::Lightning, Stage::Stage1, 1, 101,
        "Mitsuhiro Arita", ExpansionID::Jungle, 2, Rarity::HoloRare))
        ->evolvesFrom("Voltorb")->weakTo(EnergyType::Fighting)
    };

    inline DataCard* _003Flareon { (new PokemonCard(
        "Flareon", 70, EnergyType::Fire, Stage::Stage1, 1, 136,
        "Kagemaru Himeno", ExpansionID::Jungle, 3, Rarity::HoloRare))
        ->evolvesFrom("Eevee")->weakTo(EnergyType::Water)
    };

    inline DataCard* _004Jolteon { (new PokemonCard(
        "Jolteon", 70, EnergyType::Lightning, Stage::Stage1, 1, 135,
        "Kagemaru Himeno", ExpansionID::Jungle, 4, Rarity::HoloRare))
        ->evolvesFrom("Eevee")->weakTo(EnergyType::Fighting)
    };

    inline DataCard* _005Kangaskhan { (new PokemonCard(
        "Kangaskhan", 90, EnergyType::Colorless, Stage::Basic, 3, 115,
        "Mitsuhiro Arita", ExpansionID::Jungle, 5, Rarity::HoloRare))
        ->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _006MrMime { (new PokemonCard(
        "Mr. Mime", 40, EnergyType::Psychic, Stage::Basic, 1, 122,
        "Ken Sugimori", ExpansionID::Jungle, 6, Rarity::HoloRare))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _007Nidoqueen { (new PokemonCard(
        "Nidoqueen", 90, EnergyType::Grass, Stage::Stage2, 3, 31,
        "Ken Sugimori", ExpansionID::Jungle, 7, Rarity::HoloRare))
        ->evolvesFrom("Nidorina")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _008Pidgeot { (new PokemonCard(
        "Pidgeot", 80, EnergyType::Colorless, Stage::Stage2, 0, 18,
        "Kagemaru Himeno", ExpansionID::Jungle, 8, Rarity::HoloRare))
        ->evolvesFrom("Pidgeotto")->weakTo(EnergyType::Lightning)->resists(EnergyType::Fighting)
    };

    inline DataCard* _009Pinsir { (new PokemonCard(
        "Pinsir", 60, EnergyType::Grass, Stage::Basic, 1, 127,
        "Kagemaru Himeno", ExpansionID::Jungle, 9, Rarity::HoloRare))
        ->weakTo(EnergyType::Fire)
    };

    inline DataCard* _010Scyther { (new PokemonCard(
        "Scyther", 70, EnergyType::Grass, Stage::Basic, 0, 123,
        "Ken Sugimori", ExpansionID::Jungle, 10, Rarity::HoloRare))
        ->weakTo(EnergyType::Fire)->resists(EnergyType::Fighting)
    };

    inline DataCard* _011Snorlax { (new PokemonCard(
        "Snorlax", 90, EnergyType::Colorless, Stage::Basic, 4, 143,
        "Ken Sugimori", ExpansionID::Jungle, 11, Rarity::HoloRare))
        ->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _012Vaporeon { (new PokemonCard(
        "Vaporeon", 80, EnergyType::Water, Stage::Stage1, 1, 134,
        "Kagemaru Himeno", ExpansionID::Jungle, 12, Rarity::HoloRare))
        ->evolvesFrom("Eevee")->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _013Venomoth { (new PokemonCard(
        "Venomoth", 70, EnergyType::Grass, Stage::Stage1, 0, 49,
        "Ken Sugimori", ExpansionID::Jungle, 13, Rarity::HoloRare))
        ->evolvesFrom("Venonat")->weakTo(EnergyType::Fire)->resists(EnergyType::Fighting)
    };

    inline DataCard* _014Victreebel { (new PokemonCard(
        "Victreebel", 80, EnergyType::Grass, Stage::Stage2, 2, 71,
        "Ken Sugimori", ExpansionID::Jungle, 14, Rarity::HoloRare))
        ->evolvesFrom("Weepinbell")->weakTo(EnergyType::Fire)
    };

    inline DataCard* _015Vileplume { (new PokemonCard(
        "Vileplume", 80, EnergyType::Grass, Stage::Stage2, 2, 45,
        "Keiji Kinebuchi", ExpansionID::Jungle, 15, Rarity::HoloRare))
        ->evolvesFrom("Gloom")->weakTo(EnergyType::Fire)
    };

    inline DataCard* _016Wigglytuff { (new PokemonCard(
        "Wigglytuff", 80, EnergyType::Colorless, Stage::Stage1, 2, 40,
        "Mitsuhiro Arita", ExpansionID::Jungle, 16, Rarity::HoloRare))
        ->evolvesFrom("Jigglypuff")->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _017Clefable { (new PokemonCard(
        "Clefable", 70, EnergyType::Colorless, Stage::Stage1, 2, 36,
        "Mitsuhiro Arita", ExpansionID::Jungle, 17, Rarity::Rare))
        ->evolvesFrom("Clefairy")->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _018Electrode { (new PokemonCard(
        "Electrode", 90, EnergyType::Lightning, Stage::Stage1, 1, 101,
        "Mitsuhiro Arita", ExpansionID::Jungle, 18, Rarity::Rare))
        ->evolvesFrom("Voltorb")->weakTo(EnergyType::Fighting)
    };

    inline DataCard* _019Flareon { (new PokemonCard(
        "Flareon", 70, EnergyType::Fire, Stage::Stage1, 1, 136,
        "Kagemaru Himeno", ExpansionID::Jungle, 19, Rarity::Rare))
        ->evolvesFrom("Eevee")->weakTo(EnergyType::Water)
    };

    inline DataCard* _020Jolteon { (new PokemonCard(
        "Jolteon", 70, EnergyType::Lightning, Stage::Stage1, 1, 135,
        "Kagemaru Himeno", ExpansionID::Jungle, 20, Rarity::Rare))
        ->evolvesFrom("Eevee")->weakTo(EnergyType::Fighting)
    };

    inline DataCard* _021Kangaskhan { (new PokemonCard(
        "Kangaskhan", 90, EnergyType::Colorless, Stage::Basic, 3, 115,
        "Mitsuhiro Arita", ExpansionID::Jungle, 21, Rarity::Rare))
        ->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _022MrMime { (new PokemonCard(
        "Mr. Mime", 40, EnergyType::Psychic, Stage::Basic, 1, 122,
        "Ken Sugimori", ExpansionID::Jungle, 22, Rarity::Rare))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _023Nidoqueen { (new PokemonCard(
        "Nidoqueen", 90, EnergyType::Grass, Stage::Stage2, 3, 31,
        "Ken Sugimori", ExpansionID::Jungle, 23, Rarity::Rare))
        ->evolvesFrom("Nidorina")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _024Pidgeot { (new PokemonCard(
        "Pidgeot", 80, EnergyType::Colorless, Stage::Stage2, 0, 18,
        "Kagemaru Himeno", ExpansionID::Jungle, 24, Rarity::Rare))
        ->evolvesFrom("Pidgeotto")->weakTo(EnergyType::Lightning)->resists(EnergyType::Fighting)
    };

    inline DataCard* _025Pinsir { (new PokemonCard(
        "Pinsir", 60, EnergyType::Grass, Stage::Basic, 1, 127,
        "Kagemaru Himeno", ExpansionID::Jungle, 25, Rarity::Rare))
        ->weakTo(EnergyType::Fire)
    };

    inline DataCard* _026Scyther { (new PokemonCard(
        "Scyther", 70, EnergyType::Grass, Stage::Basic, 0, 123,
        "Ken Sugimori", ExpansionID::Jungle, 26, Rarity::Rare))
        ->weakTo(EnergyType::Fire)->resists(EnergyType::Fighting)
    };

    inline DataCard* _027Snorlax { (new PokemonCard(
        "Snorlax", 90, EnergyType::Colorless, Stage::Basic, 4, 143,
        "Ken Sugimori", ExpansionID::Jungle, 27, Rarity::Rare))
        ->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _028Vaporeon { (new PokemonCard(
        "Vaporeon", 80, EnergyType::Water, Stage::Stage1, 1, 134,
        "Kagemaru Himeno", ExpansionID::Jungle, 28, Rarity::Rare))
        ->evolvesFrom("Eevee")->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _029Venomoth { (new PokemonCard(
        "Venomoth", 70, EnergyType::Grass, Stage::Stage1, 0, 49,
        "Ken Sugimori", ExpansionID::Jungle, 29, Rarity::Rare))
        ->evolvesFrom("Venonat")->weakTo(EnergyType::Fire)->resists(EnergyType::Fighting)
    };

    inline DataCard* _030Victreebel { (new PokemonCard(
        "Victreebel", 80, EnergyType::Grass, Stage::Stage2, 2, 71,
        "Ken Sugimori", ExpansionID::Jungle, 30, Rarity::Rare))
        ->evolvesFrom("Weepinbell")->weakTo(EnergyType::Fire)
    };

    inline DataCard* _031Vileplume { (new PokemonCard(
        "Vileplume", 80, EnergyType::Grass, Stage::Stage2, 2, 45,
        "Keiji Kinebuchi", ExpansionID::Jungle, 31, Rarity::Rare))
        ->evolvesFrom("Gloom")->weakTo(EnergyType::Fire)
    };

    inline DataCard* _032Wigglytuff { (new PokemonCard(
        "Wigglytuff", 80, EnergyType::Colorless, Stage::Stage1, 2, 40,
        "Mitsuhiro Arita", ExpansionID::Jungle, 32, Rarity::Rare))
        ->evolvesFrom("Jigglypuff")->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _033Butterfree { (new PokemonCard(
        "Butterfree", 70, EnergyType::Grass, Stage::Stage2, 0, 12,
        "Kagemaru Himeno", ExpansionID::Jungle, 33, Rarity::Uncommon))
        ->evolvesFrom("Metapod")->weakTo(EnergyType::Fire)->resists(EnergyType::Fighting)
    };

    inline DataCard* _034Dodrio { (new PokemonCard(
        "Dodrio", 70, EnergyType::Colorless, Stage::Stage1, 0, 85,
        "Mitsuhiro Arita", ExpansionID::Jungle, 34, Rarity::Uncommon))
        ->evolvesFrom("Doduo")->weakTo(EnergyType::Lightning)->resists(EnergyType::Fighting)
    };

    inline DataCard* _035Exeggutor { (new PokemonCard(
        "Exeggutor", 80, EnergyType::Grass, Stage::Stage1, 3, 103,
        "Kagemaru Himeno", ExpansionID::Jungle, 35, Rarity::Uncommon))
        ->evolvesFrom("Exeggcute")->weakTo(EnergyType::Fire)
    };

    inline DataCard* _036Fearow { (new PokemonCard(
        "Fearow", 70, EnergyType::Colorless, Stage::Stage1, 0, 22,
        "Mitsuhiro Arita", ExpansionID::Jungle, 36, Rarity::Uncommon))
        ->evolvesFrom("Spearow")->weakTo(EnergyType::Lightning)->resists(EnergyType::Fighting)
    };

    inline DataCard* _037Gloom { (new PokemonCard(
        "Gloom", 60, EnergyType::Grass, Stage::Stage1, 1, 44,
        "Keiji Kinebuchi", ExpansionID::Jungle, 37, Rarity::Uncommon))
        ->evolvesFrom("Oddish")->weakTo(EnergyType::Fire)
    };

    inline DataCard* _038Lickitung { (new PokemonCard(
        "Lickitung", 90, EnergyType::Colorless, Stage::Basic, 3, 108,
        "Mitsuhiro Arita", ExpansionID::Jungle, 38, Rarity::Uncommon))
        ->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _039Marowak { (new PokemonCard(
        "Marowak", 60, EnergyType::Fighting, Stage::Stage1, 1, 105,
        "Mitsuhiro Arita", ExpansionID::Jungle, 39, Rarity::Uncommon))
        ->evolvesFrom("Cubone")->weakTo(EnergyType::Grass)->resists(EnergyType::Lightning)
    };

    inline DataCard* _040Nidorina { (new PokemonCard(
        "Nidorina", 70, EnergyType::Grass, Stage::Stage1, 1, 30,
        "Ken Sugimori", ExpansionID::Jungle, 40, Rarity::Uncommon))
        ->evolvesFrom(L"Nidoran ♀")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _041Parasect { (new PokemonCard(
        "Parasect", 60, EnergyType::Grass, Stage::Stage1, 1, 47,
        "Ken Sugimori", ExpansionID::Jungle, 41, Rarity::Uncommon))
        ->evolvesFrom("Paras")->weakTo(EnergyType::Fire)
    };

    inline DataCard* _042Persian { (new PokemonCard(
        "Persian", 70, EnergyType::Colorless, Stage::Stage1, 0, 53,
        "Kagemaru Himeno", ExpansionID::Jungle, 42, Rarity::Uncommon))
        ->evolvesFrom("Meowth")->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _043Primeape { (new PokemonCard(
        "Primeape", 70, EnergyType::Fighting, Stage::Stage1, 1, 57,
        "Kagemaru Himeno", ExpansionID::Jungle, 43, Rarity::Uncommon))
        ->evolvesFrom("Mankey")->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _044Rapidash { (new PokemonCard(
        "Rapidash", 70, EnergyType::Fire, Stage::Stage1, 0, 78,
        "Mitsuhiro Arita", ExpansionID::Jungle, 44, Rarity::Uncommon))
        ->evolvesFrom("Ponyta")->weakTo(EnergyType::Water)
    };

    inline DataCard* _045Rhydon { (new PokemonCard(
        "Rhydon", 100, EnergyType::Fighting, Stage::Stage1, 3, 112,
        "Kagemaru Himeno", ExpansionID::Jungle, 45, Rarity::Uncommon))
        ->evolvesFrom("Rhyhorn")->weakTo(EnergyType::Grass)->resists(EnergyType::Lightning)
    };

    inline DataCard* _046Seaking { (new PokemonCard(
        "Seaking", 70, EnergyType::Water, Stage::Stage1, 1, 119,
        "Kagemaru Himeno", ExpansionID::Jungle, 46, Rarity::Uncommon))
        ->evolvesFrom("Goldeen")->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _047Tauros { (new PokemonCard(
        "Tauros", 60, EnergyType::Colorless, Stage::Basic, 2, 128,
        "Kagemaru Himeno", ExpansionID::Jungle, 47, Rarity::Uncommon))
        ->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _048Weepinbell { (new PokemonCard(
        "Weepinbell", 70, EnergyType::Grass, Stage::Stage1, 1, 70,
        "Kagemaru Himeno", ExpansionID::Jungle, 48, Rarity::Uncommon))
        ->evolvesFrom("Bellsprout")->weakTo(EnergyType::Fire)
    };

    inline DataCard* _049Bellsprout { (new PokemonCard(
        "Bellsprout", 40, EnergyType::Grass, Stage::Basic, 1, 69,
        "Kagemaru Himeno", ExpansionID::Jungle, 49, Rarity::Common))
        ->weakTo(EnergyType::Fire)
    };

    inline DataCard* _050Cubone { (new PokemonCard(
        "Cubone", 40, EnergyType::Fighting, Stage::Basic, 1, 104,
        "Mitsuhiro Arita", ExpansionID::Jungle, 50, Rarity::Common))
        ->weakTo(EnergyType::Grass)->resists(EnergyType::Lightning)
    };

    inline DataCard* _051Eevee { (new PokemonCard(
        "Eevee", 50, EnergyType::Colorless, Stage::Basic, 1, 133,
        "Kagemaru Himeno", ExpansionID::Jungle, 51, Rarity::Common))
        ->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _052Exeggcute { (new PokemonCard(
        "Exeggcute", 50, EnergyType::Grass, Stage::Basic, 1, 102,
        "Mitsuhiro Arita", ExpansionID::Jungle, 52, Rarity::Common))
        ->weakTo(EnergyType::Fire)
    };

    inline DataCard* _053Goldeen { (new PokemonCard(
        "Goldeen", 40, EnergyType::Water, Stage::Basic, 0, 118,
        "Kagemaru Himeno", ExpansionID::Jungle, 53, Rarity::Common))
        ->weakTo(EnergyType::Lightning)
    };

    inline DataCard* _054Jigglypuff { (new PokemonCard(
        "Jigglypuff", 60, EnergyType::Colorless, Stage::Basic, 1, 39,
        "Kagemaru Himeno", ExpansionID::Jungle, 54, Rarity::Common))
        ->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _055Mankey { (new PokemonCard(
        "Mankey", 30, EnergyType::Fighting, Stage::Basic, 0, 56,
        "Kagemaru Himeno", ExpansionID::Jungle, 55, Rarity::Common))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _056Meowth { (new PokemonCard(
        "Meowth", 50, EnergyType::Colorless, Stage::Basic, 1, 52,
        "Mitsuhiro Arita", ExpansionID::Jungle, 56, Rarity::Common))
        ->weakTo(EnergyType::Fighting)->resists(EnergyType::Psychic)
    };

    inline DataCard* _057NidoranF { (new PokemonCard(
        L"Nidoran ♀", 60, EnergyType::Grass, Stage::Basic, 1, 29,
        "Ken Sugimori", ExpansionID::Jungle, 57, Rarity::Common))
        ->weakTo(EnergyType::Psychic)
    };

    inline DataCard* _058Oddish { (new PokemonCard(
        "Oddish", 50, EnergyType::Grass, Stage::Basic, 1, 43,
        "Keiji Kinebuchi", ExpansionID::Jungle, 58, Rarity::Common))
        ->weakTo(EnergyType::Fire)
    };

    inline DataCard* _059Paras { (new PokemonCard(
        "Paras", 40, EnergyType::Grass, Stage::Basic, 1, 46,
        "Ken Sugimori", ExpansionID::Jungle, 59, Rarity::Common))
        ->weakTo(EnergyType::Fire)
    };

    inline DataCard* _060Pikachu { (new PokemonCard(
        "Pikachu", 50, EnergyType::Lightning, Stage::Basic, 1, 25,
        "Ken Sugimori", ExpansionID::Jungle, 60, Rarity::Common))
        ->weakTo(EnergyType::Fighting)
    };

    inline DataCard* _061Rhyhorn { (new PokemonCard(
        "Rhyhorn", 70, EnergyType::Fighting, Stage::Basic, 3, 111,
        "Mitsuhiro Arita", ExpansionID::Jungle, 61, Rarity::Common))
        ->weakTo(EnergyType::Grass)->resists(EnergyType::Lightning)
    };

    inline DataCard* _062Spearow { (new PokemonCard(
        "Spearow", 50, EnergyType::Colorless, Stage::Basic, 0, 21,
        "Mitsuhiro Arita", ExpansionID::Jungle, 62, Rarity::Common))
        ->weakTo(EnergyType::Lightning)->resists(EnergyType::Fighting)
    };

    inline DataCard* _063Venonat { (new PokemonCard(
        "Venonat", 40, EnergyType::Grass, Stage::Basic, 1, 48,
        "Mitsuhiro Arita", ExpansionID::Jungle, 63, Rarity::Common))
        ->weakTo(EnergyType::Fire)
    };

    inline DataCard* _064PokéBall { new TrainerCard(
        L"Poké Ball", TrainerType::Item, "Keiji Kinebuchi",
        ExpansionID::Jungle, 64, Rarity::Common
    )};

}

using namespace Jungle;
inline Expansion jungle { "Jungle", ExpansionID::Jungle, 11,
	{
	    _001Clefable, _002Electrode, _003Flareon, _004Jolteon, 
	    _005Kangaskhan, _006MrMime, _007Nidoqueen, _008Pidgeot, 
	    _009Pinsir, _010Scyther, _011Snorlax, _012Vaporeon, 
	    _013Venomoth, _014Victreebel, _015Vileplume, _016Wigglytuff, 
	    _017Clefable, _018Electrode, _019Flareon, _020Jolteon, 
	    _021Kangaskhan, _022MrMime, _023Nidoqueen, _024Pidgeot, 
	    _025Pinsir, _026Scyther, _027Snorlax, _028Vaporeon, 
	    _029Venomoth, _030Victreebel, _031Vileplume, _032Wigglytuff, 
	    _033Butterfree, _034Dodrio, _035Exeggutor, _036Fearow, 
	    _037Gloom, _038Lickitung, _039Marowak, _040Nidorina, 
	    _041Parasect, _042Persian, _043Primeape, _044Rapidash, 
	    _045Rhydon, _046Seaking, _047Tauros, _048Weepinbell, 
	    _049Bellsprout, _050Cubone, _051Eevee, _052Exeggcute, 
	    _053Goldeen, _054Jigglypuff, _055Mankey, _056Meowth, 
	    _057NidoranF, _058Oddish, _059Paras, _060Pikachu, 
	    _061Rhyhorn, _062Spearow, _063Venonat, _064PokéBall, 
	    
	}};
}}