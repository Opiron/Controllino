// Changelog:
// 20120813: cleanup
// 2012????.Albert: implementation



#ifndef constants_h
#define constants_h

#include "Arduino.h"


char buzzer[16];

prog_char strin_0[] PROGMEM = "0";	// "String 0" etc are strings to store 								// change to suit.
prog_char strin_1[] PROGMEM = "1";
prog_char strin_2[] PROGMEM = "2";
prog_char strin_3[] PROGMEM = "3";
prog_char strin_4[] PROGMEM = "4";
prog_char strin_5[] PROGMEM = "5";
prog_char strin_6[] PROGMEM = "6";	// "String 0" etc are strings to store -									// change to suit.
prog_char strin_7[] PROGMEM = "7";
prog_char strin_8[] PROGMEM = "8";
prog_char strin_9[] PROGMEM = "9";
prog_char strin_10[] PROGMEM = "10";
prog_char strin_11[] PROGMEM = "11";
prog_char strin_12[] PROGMEM = "12";
prog_char strin_13[] PROGMEM = "13";
prog_char strin_14[] PROGMEM = "14";
prog_char strin_15[] PROGMEM = "15";
prog_char strin_16[] PROGMEM = "16";
prog_char strin_17[] PROGMEM = "17";
prog_char strin_18[] PROGMEM = "18";
prog_char strin_19[] PROGMEM = "19";
prog_char strin_20[] PROGMEM = "20";
prog_char strin_21[] PROGMEM = "21";
prog_char strin_22[] PROGMEM = "22";
prog_char strin_23[] PROGMEM = "23";
prog_char strin_24[] PROGMEM = "24";
prog_char strin_25[] PROGMEM = "25";
prog_char strin_26[] PROGMEM = "26";
prog_char strin_27[] PROGMEM = "27";
prog_char strin_28[] PROGMEM = "28";
prog_char strin_29[] PROGMEM = "29";
prog_char strin_30[] PROGMEM = "30";
prog_char strin_31[] PROGMEM = "31";
prog_char strin_32[] PROGMEM = "32";
prog_char strin_33[] PROGMEM = "33";
prog_char strin_34[] PROGMEM = "34";
prog_char strin_35[] PROGMEM = "35";
prog_char strin_36[] PROGMEM = "36";
prog_char strin_37[] PROGMEM = "37";
prog_char strin_38[] PROGMEM = "38";
prog_char strin_39[] PROGMEM = "39";
prog_char strin_40[] PROGMEM = "40";
prog_char strin_41[] PROGMEM = "41";
prog_char strin_42[] PROGMEM = "42";
prog_char strin_43[] PROGMEM = "43";
prog_char strin_44[] PROGMEM = "44";
prog_char strin_45[] PROGMEM = "45";
prog_char strin_46[] PROGMEM = "46";
prog_char strin_47[] PROGMEM = "47";
prog_char strin_48[] PROGMEM = "48";
prog_char strin_49[] PROGMEM = "49";
prog_char strin_50[] PROGMEM = "50";
prog_char strin_51[] PROGMEM = "51";
prog_char strin_52[] PROGMEM = "52";
prog_char strin_53[] PROGMEM = "53";
prog_char strin_54[] PROGMEM = "54";
prog_char strin_55[] PROGMEM = "55";
prog_char strin_56[] PROGMEM = "56";
prog_char strin_57[] PROGMEM = "57";
prog_char strin_58[] PROGMEM = "58";
prog_char strin_59[] PROGMEM = "59";
prog_char strin_60[] PROGMEM = "60";
prog_char strin_61[] PROGMEM = "61";
prog_char strin_62[] PROGMEM = "62";
prog_char strin_63[] PROGMEM = "63";
prog_char strin_64[] PROGMEM = "64";
prog_char strin_65[] PROGMEM = "65";
prog_char strin_66[] PROGMEM = "66";
prog_char strin_67[] PROGMEM = "67";
prog_char strin_68[] PROGMEM = "68";
prog_char strin_69[] PROGMEM = "69";
prog_char strin_70[] PROGMEM = "70";
prog_char strin_71[] PROGMEM = "71";
prog_char strin_72[] PROGMEM = "72";
prog_char strin_73[] PROGMEM = "73";
prog_char strin_74[] PROGMEM = "74";
prog_char strin_75[] PROGMEM = "75";
prog_char strin_76[] PROGMEM = "76";
prog_char strin_77[] PROGMEM = "77";
prog_char strin_78[] PROGMEM = "78";
prog_char strin_79[] PROGMEM = "79";
prog_char strin_80[] PROGMEM = "80";
prog_char strin_81[] PROGMEM = "81";
prog_char strin_82[] PROGMEM = "82";
prog_char strin_83[] PROGMEM = "83";
prog_char strin_84[] PROGMEM = "84";
prog_char strin_85[] PROGMEM = "85";
prog_char strin_86[] PROGMEM = "86";
prog_char strin_87[] PROGMEM = "87";
prog_char strin_88[] PROGMEM = "88";
prog_char strin_89[] PROGMEM = "89";
prog_char strin_90[] PROGMEM = "90";
prog_char strin_91[] PROGMEM = "91";
prog_char strin_92[] PROGMEM = "92";
prog_char strin_93[] PROGMEM = "93";
prog_char strin_94[] PROGMEM = "94";
prog_char strin_95[] PROGMEM = "95";
prog_char strin_96[] PROGMEM = "96";
prog_char strin_97[] PROGMEM = "97";
prog_char strin_98[] PROGMEM = "98";
prog_char strin_99[] PROGMEM = "99";
prog_char strin_100[] PROGMEM = "100";

#define MAX_strin 100

PROGMEM PGM_P strin_table[] =	// change "string_table" name to suit
{
	strin_0,
	strin_1,
	strin_2,
	strin_3,
	strin_4,
	strin_5,
	strin_6,
	strin_7,
	strin_8,
	strin_9,
	strin_10,
	strin_11,
	strin_12,
	strin_13,
	strin_14,
	strin_15,
	strin_16,
	strin_17,
	strin_18,
	strin_19,
	strin_20,
	strin_21,
	strin_22,
	strin_23,
	strin_24,
	strin_25,
	strin_26,
	strin_27,
	strin_28,
	strin_29,
	strin_30,
	strin_31,
	strin_32,
	strin_33,
	strin_34,
	strin_35,
	strin_36,
	strin_37,
	strin_38,
	strin_39,
	strin_40,
	strin_41,
	strin_42,
	strin_43,
	strin_44,
	strin_45,
	strin_46,
	strin_47,
	strin_48,
	strin_49,
	strin_50,
	strin_51,
	strin_52,
	strin_53,
	strin_54,
	strin_55,
	strin_56,
	strin_57,
	strin_58,
	strin_59,
	strin_60,
	strin_61,
	strin_62,
	strin_63,
	strin_64,
	strin_65,
	strin_66,
	strin_67,
	strin_68,
	strin_69,
	strin_70,
	strin_71,
	strin_72,
	strin_73,
	strin_74,
	strin_75,
	strin_76,
	strin_77,
	strin_78,
	strin_79,
	strin_80,
	strin_81,
	strin_82,
	strin_83,
	strin_84,
	strin_85,
	strin_86,
	strin_87,
	strin_88,
	strin_89,
	strin_90,
	strin_91,
	strin_92,
	strin_93,
	strin_94,
	strin_95,
	strin_96,
	strin_97,
	strin_98,
	strin_99,
	strin_100,

};


#endif // #ifndef constants_h
