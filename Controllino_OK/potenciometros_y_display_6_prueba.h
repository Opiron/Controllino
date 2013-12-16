// Changelog:
// 20120813: cleanup
// 2012????.Albert: implementation

#ifndef potenciometros_y_display_h


// Definitions and constants:

#define NUM_KNOB_GROUPS 8
#define NUM_KNOBS 4				// 4 knobs * 4 knobs/bank = 16 total knobs
#define NUM_MENUS 4
#define NUM_MIDI 16
#define NUM_CONTROL_CHANGE 127

#define BUTTON_IDLE 0
#define BUTTON_RELEASED 1
#define BUTTON_PRESSED 2
/*
Version para Mega
const int PIN_Encoder0A = 30;
const int PIN_Encoder0B = 31;
const int PIN_Button = 22;
*/
// version para UNO
/*const int PIN_Encoder0A = 0;
const int PIN_Encoder0B = 2;
*/

const int PIN_Encoder0A = 19;
const int PIN_Encoder0B = 18;
const int PIN_Button = 2;


enum EncoderIndexes
{
	MenuEncoderNdx = 0,
	KnobGroupEncoderNdx,
	KnobEncoderNdx,
	ControlChangeEncoderNdx,
	MidiChannelNdx,
	BehaviorNdx,
	KnobEncoderElems
};


enum MenuElems
{
	ME_KnobGroup = 0,
	ME_Knob,
	ME_ControlChange,
	ME_MidiChannel,
	ME_Behavior,
	ME_Elems
};

const char *menu_labels[ME_Elems] = { "K group:", "Knob:", "CC:", "Channel:", "lin/exp/log:" };


// Data structures:

typedef struct
{
    	int knob[NUM_KNOBS];
      	int behavior[NUM_KNOBS];
    	int control_change[NUM_KNOBS];
      	int channel[NUM_KNOBS];
} KnobStatus;


typedef struct
{
	int buttonPushCounter;		// counter for the number of button presses
	int buttonState;		// current state of the button
	int lastButtonState;		// previous state of the button
} Button;

typedef struct
{
	int encoder_target;			// it will point to knob_ndx/control_change_ndx/menu_ndx.
	int positions[KnobEncoderElems];
	int ultimaPosicionPinA;
} Encoder;

typedef struct
{
        int cc;
        int knob_value;
} MIDI_STATUS;

typedef struct
{
  	KnobStatus knobs[NUM_KNOB_GROUPS];
  	Encoder encoder;
	Button button;
        MIDI_STATUS midi_status[NUM_MIDI];
} ControlStatus;


// Function prototypes:

void input_update(ControlStatus *cs);
void output_update(ControlStatus *cs);
void screen_update(ControlStatus *cs);
int update_from_button(ControlStatus *cs);	// pulsador()
int update_from_encoder(ControlStatus *cs, int enc_pos, int x); // Paso de la estructura, retorno del valor de la funcion de encoder, valor maximo que puede alcanzar )
void input_update_knobs(ControlStatus *cs);
void lcd_draw_knob(ControlStatus *cs);
void lcd_draw_header();
void indicador_de_pulsacion(ControlStatus *cs);
void lcd_draw_menu(ControlStatus *cs);
void output_update_midi(ControlStatus *cs);
void ControlStatus_Init(ControlStatus *cs);
void update_encoder_targets(ControlStatus *cs);

// Macros:

#define MAX(x, y) (x > y? x : y)


#endif // potenciometros_y_display_h


