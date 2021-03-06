// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  5/22/21

#include "KeyValue.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for KeyValue
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++
const std::map<std::string, KeyValue::KeyType> KeyValue::_keyenum_mapping = {
	{"AC",				armorclass},
	{"ADDMENUITEM",		 	addmenuitem},
	{"ADVOBJ",			 	advanceobj},
	{"ALCHEMY",			 	alchemy},
	{"AMMO",				ammo},
	{"AMMOFX",			 	ammofx},
	{"AMOUNT",			 	amount},
	{"ANATOMY",			 	anatomy},
	{"ANIMALLORE",		 	animallore},
	{"ARCHERY",			 	archery},
	{"ARMSLORE",			armslore},
	{"ATT",				attack},
	{"BACKPACK",			backpack},
	{"BASERANGE",		 	baserange},
	{"BEGGING",			 	begging},
	{"BLACKSMITHING",	 		blacksmithing},
	{"BOWCRAFT",			bowcraft},
	{"BUSHIDO",			 	bushido},
	{"CAMPING",			 	camping},
	{"CARPENTRY",		 	carpentry},
	{"CARTOGRAPHY",		 	cartography},
	{"CARVE",			 	carve},
	{"CHIVALRY",			chivalry},
	{"COLD",				cold},
	{"COLOR",			 	color},
	{"COLOUR",			 	color},
	{"COLORLIST",		 	colorlist},
	{"COLOURLIST",		 	colorlist},
	{"COLORMATCHHAIR",	 	colormatchhair},
	{"COLOURMATCHHAIR",	 	colormatchhair},
	{"COOKING",			 	cooking},
	{"CORPSE",			 	corpse},
	{"CREATOR",			 	creator},
	{"CUSTOMSTRINGTAG",	 	customstringtag},
	{"CUSTOMINTTAG",		 	custominttag},
	{"DAMAGE",			 	damage},
	{"DECAY",			 	decay},
	{"DEF",				defense},
	{"DETECTINGHIDDEN",	 	detecthidden},
	{"DEX",				dexterity},
	{"DEXTERITY",		 	dexterity},
	{"DX",				dexterity},
	{"DEXADD",			 	dexterity2},
	{"DX2",				dexterity2},
	{"DIR",				direction},
	{"DIRECTION",		 	direction},
	{"DISPELLABLE",		 	dispellable},
	{"DISABLED",			disabled},
	{"DOORFLAG",			doorflag},
	{"DYE",				dye},
	{"DYEABLE",			 	dye},
	{"DYEHAIR",			 	dyehair},
	{"DYEBEARD",			dyebeard},
	{"ELEMENTRESIST",	 		elementresist},
	{"EMOTECOLOR",		 	emotecolor},
	{"EMOTECOLOUR",		 	emotecolor},
	{"ENTICEMENT",		 	enticement},
	{"EVALUATINGINTEL",	 	evaluteintel},
	{"FAME",				fame},
	{"FENCING",			 	fencing},
	{"FISHING",			 	fishing},
	{"FLAG",				flag},
	{"FLEEAT",			 	flee},
	{"FLEEINGSPEED",		 	fleespeed},
	{"FOCUS",			 	focus},
	{"FORENSICS",		 	forensics},
	{"FX1",				fx1},
	{"FX2",				fx2},
	{"FY1",				fy1},
	{"FY2",				fy2},
	{"FZ1",				fz1},
	{"FOOD",				food},
	{"GET",				get},
	{"GLOW",				glow},
	{"GLOWBC",			 	glowbc},
	{"GLOWTYPE",			glowtype},
	{"GOLD",				gold},
	{"GOOD",				good},
	{"HAIRCOLOR",		 	haircolor},
	{"HAIRCOLOUR",		 	haircolor},
	{"HEALING",			 	healing},
	{"HEAT",				heat},
	{"HERDING",			 	herding},
	{"HIDAMAGE",			high_damage},
	{"HIDING",			 	hiding},
	{"HP",				hitpoint},
	{"HPMAX",			 	maxhitpoint},
	{"ID",				identification},
	{"IMBUING",			 	imbuing},
	{"IN",				intelligence},
	{"INTELLIGENCE",		 	intelligence},
	{"INT",				intelligence},
	{"IN2",				intaddition},
	{"INTADD",			 	intaddition},
	{"INTERVAL",			interval},
	{"INSCRIPTION",		 	inscription},
	{"EQUIPITEM",		 	equipitem},
	{"ITEMLIST",			itemlist},
	{"ITEMID",			 	itemid},
	{"KARMA",			 	karma},
	{"KILLHAIR",			killhair},
	{"KILLBEARD",		 	killbeard},
	{"KILLPACK",			killpack},
	{"LAYER",			 	layer},
	{"LIGHT",			 	light},
	{"LIGHTNING",		 	lightning},
	{"LOCKPICKING",		 	lockpicking},
	{"LODAMAGE",			low_damage},
	{"LOOT",				loot},
	{"LUMBERJACKING",	 		lumberjacking},
	{"MACEFIGHTING",		 	macefighting},
	{"MAGERY",			 	magery},
	{"MAGICRESISTANCE",	 	magicresistance},
	{"MANA",				mana},
	{"MANAMAX",			 	maxmana},
	{"MAXRANGE",			maxrange},
	{"MAXHP",			 	maxhitpoint},
	{"MAXITEMS",			maxitems},
	{"MEDITATION",		 	meditation},
	{"MINING",			 	mining},
	{"MOVABLE",			 	movable},
	{"MORE",				more},
	{"MORE2",			 	more2},
	{"MOREX",			 	morex},
	{"MOREY",			 	morey},
	{"MOREZ",			 	morez},
	{"MUSICIANSHIP",		 	musicianship},
	{"MYSTICISM",		 	mysticism},
	{"NAME",				name},
	{"NAME2",			 	name2},
	{"NAMELIST",			namelist},
	{"NECROMANCY",		 	necromancy},
	{"NEWBIE",			 	newbie},
	{"NINJITSU",			ninjitsu},
	{"NOTRAIN",			 	notrain},
	{"NPCAI",			 	npcai},
	{"NPCLIST",			 	npclist},
	{"NPCWANDER",		 	npcwander},
	{"OFFSPELL",			offspell},
	{"PACKITEM",			packitem},
	{"PARRYING",			parrying},
	{"PEACEMAKING",		 	peacemaking},
	{"PILEABLE",			stackable},
	{"POLY",				poly},
	{"POISONDAMAGE",		 	poisondamage},
	{"POISONSTRENGTH",	 	poisonstrength},
	{"POISONED",			poisoned},
	{"POISONING",		 	poisoning},
	{"PRIV",				privilege},
	{"PROVOCATION",		 	provocation},
	{"RACE",				race},
	{"RAIN",				rain},
	{"RANK",				rank},
	{"REATTACKAT",		 	reattackat},
	{"RESISTFIRE",		 	resistfire},
	{"RESISTCOLD",		 	resistcold},
	{"RESISTLIGHTNING",	 	resistlightening},
	{"RESISTPOISON",		 	resistpoison},
	{"REMOVETRAPS",		 	removetraps},
	{"RESTOCK",			 	restock},
	{"RSHOPITEM",		 	rshopitem},
	{"RUNS",				runs},
	{"RUNNINGSPEED",		 	runningspeed},
	{"SAYCOLOR",			saycolor},
	{"SAYCOLOUR",		 	saycolor},
	{"SCRIPT",			 	script},
	{"SELLITEM",			sellitem},
	{"SHOPITEM",			shopitem},
	{"SHOPKEEPER",		 	shopkeeper},
	{"SHOPLIST",			shoplist},
	{"SK_MADE",			 	skill_made},
	{"SKILL",			 	skill},
	{"SKIN",				skin},
	{"SKINLIST",			skinlist},
	{"SNOOPING",			snooping},
	{"SNOW",				snow},
	{"SPADELAY",			spadelay},
	{"SPATTACK",			spattack},
	{"SPAWNOBJ",			spawnobject},
	{"SPAWNOBJLIST",		 	spawnobject_list},
	{"SPD",				speed},
	{"SPEED",			 	speed},
	{"SPELLWEAVING",		 	spellweaving},
	{"SPIRITSPEAK",		 	spiritspeak},
	{"SPLIT",			 	split},
	{"SPLITCHANCE",		 	splitchance},
	{"ST",				strength},
	{"STAMINA",			 	stamina},
	{"STAMINAMAX",		 	maxstamina},
	{"STR",				strength},
	{"STRENGTH",			strength},
	{"ST2",				stradd},
	{"STRADD",			 	stradd},
	{"STEALING",			stealing},
	{"STEALTH",			 	stealth},
	{"SWORDSMANSHIP",	 		swordsmanship},
	{"TACTICS",			 	tatics},
	{"TAILORING",		 	tailoring},
	{"TAMING",			 	taming},
	{"TAMEDHUNGER",		 	tamedhunger},
	{"TASTEID",			 	tasteid},
	{"THROWING",			throwing},
	{"TINKERING",		 	tinkering},
	{"TITLE",			 	title},
	{"TOTAME",			 	to_tame},
	{"TOPROV",			 	to_prov},
	{"TOPEACE",			 	to_peace},
	{"TRACKING",			tracking},
	{"TYPE",				type},
	{"VALUE",			 	worth},
	{"VETERINARY",		 	veterinary},
	{"VISIBLE",			 	isvisible},
	{"WALKINGSPEED",		 	walkingspeed},
	{"WEIGHT",			 	weigth},
	{"WEIGHTMAX",		 	maxweight},
	{"WILLHUNGER",		 	will_hunger},
	{"WIPE",				wipe},
	{"WRESTLING",		 	wrestling},
	{"LOCATION",			location}
};
/*
const std::map<KeyValue::KeyType, KeyValueType> KeyValue::_keytype_mapping = {
	{armorclass,		KeyValueType::numeric },
	{advanceobj,		KeyValueType::numeric},
	{alchemy,			KeyValueType::doublenumeric },
	{ammo, 			KeyValueType::text },
	{ammofx, 		 	KeyValueType::text },
	{amount, 		 	KeyValueType::numeric },
	{anatomy, 		 	KeyValueType::doublenumeric },
	{animallore,		KeyValueType::doublenumeric },
	{archery, 		 	KeyValueType::doublenumeric },
	{armslore, 			KeyValueType::doublenumeric },
	{attack, 			KeyValueType::doublenumeric },
	{backpack, 			KeyValueType::nodata },
	{baserange, 		KeyValueType::numeric },
	{begging, 		 	KeyValueType::doublenumeric },
	{blacksmithing,	 	KeyValueType::doublenumeric },
	{bowcraft,		 	KeyValueType::doublenumeric },
	{bushido,		 	KeyValueType::doublenumeric },
	{camping,		 	KeyValueType::doublenumeric },
	{carpentry,			KeyValueType::doublenumeric },
	{cartography,		KeyValueType::doublenumeric },
	{carve,			KeyValueType::numeric },
	{chivalry,		 	KeyValueType::doublenumeric },
	{cold,			KeyValueType::numeric },
	{color,			KeyValueType::numeric },
	{colorlist,			KeyValueType::text },
	{colormatchhair,		KeyValueType::nodata },
	{cooking,		 	KeyValueType::doublenumeric },
	{corpse,			KeyValueType::numeric },
	{creator,		 	KeyValueType::numeric },
	{customstringtag,		KeyValueType::text },
	{custominttag,		KeyValueType::text },
	{damage,			KeyValueType::doublenumeric },
	{decay,			KeyValueType::numeric },
	{defense,			KeyValueType::doublenumeric },
	{detecthidden,		KeyValueType::doublenumeric },
	{dexterity,			KeyValueType::doublenumeric },
	{dexterity2,		KeyValueType::numeric },
	{direction,			KeyValueType::text },
	{dispellable,		KeyValueType::nodata },
	{disabled,		 	KeyValueType::numeric },
	{doorflag,		 	KeyValueType::numeric },
	{dye,				KeyValueType::numeric },
	{dyebeard,		 	KeyValueType::numeric },
	{dyehair,		 	KeyValueType::numeric },
	{elementresist,	 	KeyValueType::text },
	{emotecolor,		KeyValueType::numeric },
	{enticement,		KeyValueType::doublenumeric },
	{equipitem,			KeyValueType::uppertext },
	{evaluteintel,		KeyValueType::doublenumeric },
	{fame,			KeyValueType::numeric },
	{fencing,			KeyValueType::doublenumeric },
	{fishing,			KeyValueType::doublenumeric },
	{flag,			KeyValueType::uppertext },
	{flee,			KeyValueType::numeric },
	{fleespeed,			KeyValueType::text },
	{focus,			KeyValueType::doublenumeric },
	{forensics,			KeyValueType::doublenumeric },
	{fx1,				KeyValueType::numeric },
	{fx2,				KeyValueType::numeric },
	{fy1,				KeyValueType::numeric },
	{fy2,				KeyValueType::numeric },
	{fz1,				KeyValueType::numeric },
	{food,			KeyValueType::uppertext },
	{get,				KeyValueType::uppertext },
	{glow,			KeyValueType::numeric },
	{glowbc,			KeyValueType::numeric },
	{gold,			KeyValueType::doublenumeric},
	{good,			KeyValueType::numeric },
	{haircolor,			KeyValueType::text },
	{healing,			KeyValueType::doublenumeric },
	{heat,			KeyValueType::numeric },
	{herding,			KeyValueType::doublenumeric },
	{high_damage,		KeyValueType::numeric },
	{hiding,			KeyValueType::doublenumeric },
	{hitpoint,			KeyValueType::doublenumeric },
	{maxhitpoint,		KeyValueType::doublenumeric },
	{identification,		KeyValueType::numeric },
	{imbuing,			KeyValueType::doublenumeric },
	{intaddition,		KeyValueType::numeric },
	{intelligence,		KeyValueType::doublenumeric },
	{interval,			KeyValueType::doublenumeric },
	{inscription,		KeyValueType::doublenumeric },
	{itemid,			KeyValueType::numeric },
	{itemlist,			KeyValueType::uppertext },
	{karma,			KeyValueType::numeric },
	{killhair,			KeyValueType::nodata },
	{killbeard,			KeyValueType::nodata },
	{killpack,			KeyValueType::nodata },
	{layer,			KeyValueType::numeric },
	{light,			KeyValueType::numeric },
	{lightning,			KeyValueType::numeric },
	{lockpicking,		KeyValueType::numeric },
	{low_damage,		KeyValueType::numeric },
	{loot,			KeyValueType::uppertext },
	{lumberjacking,		KeyValueType::doublenumeric },
	{macefighting,		KeyValueType::doublenumeric },
	{magery,			KeyValueType::doublenumeric },
	{magicresistance,		KeyValueType::doublenumeric },
	{mana,			KeyValueType::doublenumeric },
	{maxmana,			KeyValueType::doublenumeric },
	{maxhitpoint,		KeyValueType::numeric },
	{maxitems,			KeyValueType::numeric },
	{maxrange,			KeyValueType::numeric },
	{meditation,		KeyValueType::doublenumeric },
	{mining,			KeyValueType::doublenumeric },
	{movable,			KeyValueType::numeric },
	{more,			KeyValueType::numeric },
	{more2,			KeyValueType::numeric },
	{morex,			KeyValueType::numeric },
	{morey,			KeyValueType::numeric },
	{morez,			KeyValueType::numeric },
	{musicianship,		KeyValueType::doublenumeric },
	{mysticism,			KeyValueType::doublenumeric },
	{name,			KeyValueType::text },
	{name2,			KeyValueType::text },
	{namelist,			KeyValueType::text },
	{necromancy,		KeyValueType::doublenumeric },
	{newbie,			KeyValueType::nodata },
	{ninjitsu,			KeyValueType::doublenumeric },
	{notrain,			KeyValueType::nodata },
	{npcai,			KeyValueType::numeric },
	{npclist,			KeyValueType::uppertext },
	{npcwander,			KeyValueType::numeric },
	{offspell,			KeyValueType::numeric },
	{packitem,			KeyValueType::text},
	{parrying,			KeyValueType::doublenumeric },
	{peacemaking,		KeyValueType::doublenumeric },
	{stackable,			KeyValueType::numeric },
	{poisondamage,		KeyValueType::numeric },
	{poisonstrength,		KeyValueType::numeric },
	{poisoned,			KeyValueType::numeric },
	{poisoning,			KeyValueType::doublenumeric },
	{poly,			KeyValueType::numeric },
	{privilege,			KeyValueType::numeric },
	{provocation,		KeyValueType::doublenumeric },
	{race,			KeyValueType::numeric },
	{rain,			KeyValueType::numeric },
	{rank,			KeyValueType::numeric },
	{reattackat,		KeyValueType::numeric },
	{removetraps,		KeyValueType::doublenumeric },
	{restock,			KeyValueType::numeric },
	{resistfire,		KeyValueType::doublenumeric },
	{resistcold,		KeyValueType::doublenumeric },
	{resistlightening,	KeyValueType::doublenumeric },
	{resistpoison,		KeyValueType::doublenumeric },
	{rshopitem,			KeyValueType::text },
	{runningspeed,		KeyValueType::text },
	{runs,			KeyValueType::nodata },
	{saycolor,			KeyValueType::numeric},
	{script,			KeyValueType::text },
	{sellitem,			KeyValueType::text },
	{shopitem,			KeyValueType::text },
	{shopkeeper,		KeyValueType::nodata },
	{shoplist,			KeyValueType::text },
	{skill_made,		KeyValueType::numeric},
	{skill,			KeyValueType::doublenumeric },
	{skillvar,			KeyValueType::unknown},
	{skin,			KeyValueType::numeric},
	{skinlist,			KeyValueType::text },
	{snooping,			KeyValueType::doublenumeric },
	{snow,			KeyValueType::numeric },
	{spadelay,			KeyValueType::numeric },
	{spattack,			KeyValueType::numeric },
	{spawnobject,		KeyValueType::text },
	{spawnobject_list,	KeyValueType::text },
	{speed,			KeyValueType::numeric },
	{spellweaving,		KeyValueType::doublenumeric },
	{spiritspeak,		KeyValueType::doublenumeric },
	{split,			KeyValueType::numeric },
	{splitchance,		KeyValueType::numeric },
	{stamina,			KeyValueType::doublenumeric },
	{maxstamina,		KeyValueType::doublenumeric },
	{strength,			KeyValueType::doublenumeric },
	{stradd,			KeyValueType::numeric },
	{stealing,			KeyValueType::doublenumeric },
	{stealth,			KeyValueType::doublenumeric },
	{swordsmanship,		KeyValueType::doublenumeric },
	{tatics,			KeyValueType::doublenumeric },
	{tailoring,			KeyValueType::doublenumeric },
	{taming,			KeyValueType::doublenumeric },
	{tamedhunger,		KeyValueType::doublenumeric },
	{tasteid,			KeyValueType::doublenumeric },
	{throwing,			KeyValueType::doublenumeric },
	{tinkering,			KeyValueType::doublenumeric },
	{title,			KeyValueType::text },
	{to_tame,			KeyValueType::numeric },
	{to_prov,			KeyValueType::numeric },
	{to_peace,			KeyValueType::doublenumeric },
	{tracking,			KeyValueType::doublenumeric },
	{type,			KeyValueType::numeric },
	{worth,			KeyValueType::doublenumeric },
	{veterinary,		KeyValueType::doublenumeric },
	{isvisible,			KeyValueType::numeric },
	{walkingspeed,		KeyValueType::text },
	{weigth,			KeyValueType::numeric },
	{maxweight,			KeyValueType::numeric },
	{will_hunger,		KeyValueType::numeric },
	{wipe,			KeyValueType::numeric },
	{wrestling,			KeyValueType::doublenumeric },
	{location,			KeyValueType::text}
	
};
*/
//==============================================================================
KeyValue::KeyValue() {
	first_number = 0 ;
	second_number = 0 ;
	enum_key = KeyType::undefined;
	
}
//==============================================================================
KeyValue::KeyType KeyValue::lookupKeyEnum(const std::string &key){
	auto iter = KeyValue::_keyenum_mapping.find(key) ;
	if (iter != KeyValue::_keyenum_mapping.end()) {
		return iter->second ;
	}
	return undefined ;
}
//==============================================================================
std::string KeyValue::description() const {
	return original_line;
}
//==============================================================================
std::string KeyValue::origin() const {
	return std::string("Line: ")+std::to_string(linenumber) + std::string(" from: ")+fileorigin;
}
