
// Changelog:
// 20120813: cleanup
// 2012????.Albert: implementation


#ifndef CC_defs_h
#define CC_defs_h


char buffer[16];

prog_char string_0[] PROGMEM = "00-BankSelMSB";	// "String 0" etc are strings to store - change to suit.
prog_char string_1[] PROGMEM = "01-Mod Wheel";
prog_char string_2[] PROGMEM = "02-Breath Cntrl";
prog_char string_3[] PROGMEM = "03-CC 03";
prog_char string_4[] PROGMEM = "04-Foot Cntrl";
prog_char string_5[] PROGMEM = "05-Porta Time";
prog_char string_6[] PROGMEM = "06-Data Entry";	// "String 0" etc are strings to store - change to suit.
prog_char string_7[] PROGMEM = "07-Volume";
prog_char string_8[] PROGMEM = "08-Balance";
prog_char string_9[] PROGMEM = "09-CC 09";
prog_char string_10[] PROGMEM = "10-Pan";
prog_char string_11[] PROGMEM = "11-Expression ";
prog_char string_12[] PROGMEM = "12-fx Cntrl 1";
prog_char string_13[] PROGMEM = "13-fx Cntrl 2";
prog_char string_14[] PROGMEM = "14-CC 14";
prog_char string_15[] PROGMEM = "15-CC 15";
prog_char string_16[] PROGMEM = "16-GPCntrl1LSB1";
prog_char string_17[] PROGMEM = "17-GPCntrl1LSB2";
prog_char string_18[] PROGMEM = "18-GPCntrl1LSB3";
prog_char string_19[] PROGMEM = "19-GPCntrl1LSB3";
prog_char string_20[] PROGMEM = "20-CC 20";
prog_char string_21[] PROGMEM = "21-CC 21";
prog_char string_22[] PROGMEM = "22-CC 22";
prog_char string_23[] PROGMEM = "23-CC 23";
prog_char string_24[] PROGMEM = "24-CC 24";
prog_char string_25[] PROGMEM = "25-CC 25";
prog_char string_26[] PROGMEM = "26-CC 26";
prog_char string_27[] PROGMEM = "27-CC 27";
prog_char string_28[] PROGMEM = "28-CC 28";
prog_char string_29[] PROGMEM = "29-CC 29";
prog_char string_30[] PROGMEM = "30-CC 30";
prog_char string_31[] PROGMEM = "31-CC 31";
prog_char string_32[] PROGMEM = "32-BankSelLSB";
prog_char string_33[] PROGMEM = "33-Mod Wheel LSB";
prog_char string_34[] PROGMEM = "34-Breath Cntrl LSB";
prog_char string_35[] PROGMEM = "35-CC 35";
prog_char string_36[] PROGMEM = "36-Foot Cntrl LSB";
prog_char string_37[] PROGMEM = "37-Porta Time LSB";
prog_char string_38[] PROGMEM = "38-Data Entry LSB";
prog_char string_39[] PROGMEM = "39-Volume LSB";
prog_char string_40[] PROGMEM = "40-Balance LSB";
prog_char string_41[] PROGMEM = "41-CC 41";
prog_char string_42[] PROGMEM = "42-Pan LSB ";
prog_char string_43[] PROGMEM = "43-Expression LSB";
prog_char string_44[] PROGMEM = "44-fx 1 LSB  ";
prog_char string_45[] PROGMEM = "45-fx 2 LSB";
prog_char string_46[] PROGMEM = "46-CC 46";
prog_char string_47[] PROGMEM = "47-CC 47";
prog_char string_48[] PROGMEM = "48-GPCntrl1LSB  ";
prog_char string_49[] PROGMEM = "49-GPCntrl2LSB   ";
prog_char string_50[] PROGMEM = "50-GPCntrl3LSB   ";
prog_char string_51[] PROGMEM = "51-GPCntrl4LSB";
prog_char string_52[] PROGMEM = "52-CC 52";
prog_char string_53[] PROGMEM = "53-CC 53";
prog_char string_54[] PROGMEM = "54-CC 54";
prog_char string_55[] PROGMEM = "55-CC 55";
prog_char string_56[] PROGMEM = "56-CC 56";
prog_char string_57[] PROGMEM = "57-CC 57";
prog_char string_58[] PROGMEM = "58-CC 58";
prog_char string_59[] PROGMEM = "59-CC 59";
prog_char string_60[] PROGMEM = "60-CC 60";
prog_char string_61[] PROGMEM = "61-CC 61";
prog_char string_62[] PROGMEM = "62-CC 62";
prog_char string_63[] PROGMEM = "63-CC 63";
prog_char string_64[] PROGMEM = "64-Damper Pedal";
prog_char string_65[] PROGMEM = "65-Porta Pedal";
prog_char string_66[] PROGMEM = "66-Sostenuto";
prog_char string_67[] PROGMEM = "67-Soft Pedal";
prog_char string_68[] PROGMEM = "68-Legato Foot Sw";
prog_char string_69[] PROGMEM = "69-Hold-2";
prog_char string_70[] PROGMEM = "70-Sound Vari";
prog_char string_71[] PROGMEM = "71-Timbre/Harmonics";
prog_char string_72[] PROGMEM = "72-Realease Time";
prog_char string_73[] PROGMEM = "73-Attack Time";
prog_char string_74[] PROGMEM = "74-Brighness";
prog_char string_75[] PROGMEM = "75-Decay Time";
prog_char string_76[] PROGMEM = "76-Vib.Rate";
prog_char string_77[] PROGMEM = "77-Vib.Depth";
prog_char string_78[] PROGMEM = "78-Vib.Delay";
prog_char string_79[] PROGMEM = "79-Sound Ctrl10";
prog_char string_80[] PROGMEM = "80-GeneralPurp10 ";
prog_char string_81[] PROGMEM = "81-GeneralPurp6";
prog_char string_82[] PROGMEM = "82-GeneralPurp7";
prog_char string_83[] PROGMEM = "83-GeneralPurp8";
prog_char string_84[] PROGMEM = "84-PortaCntrl";
prog_char string_85[] PROGMEM = "85-CC 85";
prog_char string_86[] PROGMEM = "86-CC 86";
prog_char string_87[] PROGMEM = "87-CC 87";
prog_char string_88[] PROGMEM = "88-CC 88";
prog_char string_89[] PROGMEM = "89-CC 89";
prog_char string_90[] PROGMEM = "90-CC 90";
prog_char string_91[] PROGMEM = "91-Reverb Depth";
prog_char string_92[] PROGMEM = "92-Tremolo Depth";
prog_char string_93[] PROGMEM = "93-Chorus Depth";
prog_char string_94[] PROGMEM = "94-Detune Depth";
prog_char string_95[] PROGMEM = "95-Phaser Depth";
prog_char string_96[] PROGMEM = "96-Data Inc";
prog_char string_97[] PROGMEM = "97-Data Dec";
prog_char string_98[] PROGMEM = "98-NRPN LSB";
prog_char string_99[] PROGMEM = "99-NRPN-MSB";
prog_char string_100[] PROGMEM = "100-RPN LSB";
prog_char string_101[] PROGMEM = "101-RPN MSB";
prog_char string_102[] PROGMEM = "102-CC 102";
prog_char string_103[] PROGMEM = "103-CC 103";
prog_char string_104[] PROGMEM = "104-CC 104";
prog_char string_105[] PROGMEM = "105-CC 105";
prog_char string_106[] PROGMEM = "106-CC 106";
prog_char string_107[] PROGMEM = "107-CC 107";
prog_char string_108[] PROGMEM = "108-CC 108";
prog_char string_109[] PROGMEM = "109-CC 108";
prog_char string_110[] PROGMEM = "110-CC 110 ";
prog_char string_111[] PROGMEM = "111-CC 111";
prog_char string_112[] PROGMEM = "112-CC 112";
prog_char string_113[] PROGMEM = "113-CC 113";
prog_char string_114[] PROGMEM = "114-CC 114";
prog_char string_115[] PROGMEM = "115-CC 115";
prog_char string_116[] PROGMEM = "116-CC 116";
prog_char string_117[] PROGMEM = "117-CC 117";
prog_char string_118[] PROGMEM = "118-CC 118";
prog_char string_119[] PROGMEM = "119-CC 119";
prog_char string_120[] PROGMEM = "120-All Sound OFF";
prog_char string_121[] PROGMEM = "121-RST all Cntrl";
prog_char string_122[] PROGMEM = "122-Local Cntrl";
prog_char string_123[] PROGMEM = "123-All note Off";
prog_char string_124[] PROGMEM = "124-Omni Off";
prog_char string_125[] PROGMEM = "125-Omni On";
prog_char string_126[] PROGMEM = "126-Mono Mode On";

#define MAX_string 126

PROGMEM PGM_P string_table[] =	// change "string_table" name to suit
{
	string_0,
	string_1,
	string_2,
	string_3,
	string_4,
	string_5,
	string_6,
	string_7,
	string_8,
	string_9,
	string_10,
	string_11,
	string_12,
	string_13,
	string_14,
	string_15,
	string_16,
	string_17,
	string_18,
	string_19,
	string_20,
	string_21,
	string_22,
	string_23,
	string_24,
	string_25,
	string_26,
	string_27,
	string_28,
	string_29,
	string_30,
	string_31,
	string_32,
	string_33,
	string_34,
	string_35,
	string_36,
	string_37,
	string_38,
	string_39,
	string_40,
	string_41,
	string_42,
	string_43,
	string_44,
	string_45,
	string_46,
	string_47,
	string_48,
	string_49,
	string_50,
	string_51,
	string_52,
	string_53,
	string_54,
	string_55,
	string_56,
	string_57,
	string_58,
	string_59,
	string_60,
	string_61,
	string_62,
	string_63,
	string_64,
	string_65,
	string_66,
	string_67,
	string_68,
	string_69,
	string_70,
	string_71,
	string_72,
	string_73,
	string_74,
	string_75,
	string_76,
	string_77,
	string_78,
	string_79,
	string_80,
	string_81,
	string_82,
	string_83,
	string_84,
	string_85,
	string_86,
	string_87,
	string_88,
	string_89,
	string_90,
	string_91,
	string_92,
	string_93,
	string_94,
	string_95,
	string_96,
	string_97,
	string_98,
	string_99,
	string_100,
	string_101,
	string_102,
	string_103,
	string_104,
	string_105,
	string_106,
	string_107,
	string_108,
	string_109,
	string_110,
	string_111,
	string_112,
	string_113,
	string_114,
	string_115,
	string_116,
	string_117,
	string_118,
	string_119,
	string_120,
	string_121,
	string_122,
	string_123,
	string_124,
	string_125,
	string_126,
};




#endif	/* #ifndef CC_defs_h */
