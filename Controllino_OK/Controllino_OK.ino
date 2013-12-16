//
//
// Changelog:
// 20120818: fixes
// 20120813: cleanup
// 2012????.Albert: implementation

// http://en.wikipedia.org/wiki/The_C_Programming_Language

#include <MIDI.h> 
#include "avr/pgmspace.h"
#include "potenciometros_y_display_6_prueba.h"
#include "CC_defs.h"
#include "constants.h"
#include "U8glib.h"

U8GLIB_ST7920_128X64 u8g(3, 5, 6, 9, 10, 11, 7, 8, 13, U8G_PIN_NONE, U8G_PIN_NONE, 12, 4);	// 8Bit Com: D0..D7: 3, 5, 6, 9, 10, 11, 7, 8 en=13, di=12,rw=4


ControlStatus current_status;


//#define DEBUG_MENU
//#define DEBUG_KNOBS
//#define DEBUG_MIDI
//#define ENCODER
//#define ENCODER_PRIMER_PASO
//#define ENCODER_SEGUNDO_PASO
//#define BOTON_PULSADO
//#define SALIDA 

void setup()	// -----------------------------------------------------------------------------------------------------------------------------------
{
	#if defined(DEBUG_MENU) || defined(DEBUG_MIDI) || defined(ENCODER) || defined(SALIDA) || defined(ENCODER_PRIMER_PASO) || defined(ENCODER_SEGUNDO_PASO) || defined(BOTON_PULSADO) || defined(DEBUG_KNOBS)
	Serial.begin(9600);
	#else
        MIDI.begin(MIDI_CHANNEL_OMNI); // de esta manera recibe os 16 canales
        #endif
        ControlStatus_Init(&current_status);
    }

    void loop()
    {
    	static unsigned int clock = 0;
    	const unsigned int period = 100;

    	input_update(&current_status);

	if ((clock % period) == 0)	// trigger every 'period' (e.g. 1 every 5 times)
	{
                input_update(&current_status);//zz!
		// clock: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
		// clock % period: 0 1 2 3 4 0 1 2 3 4 0 1 2 3 4 0
		screen_update(&current_status);
		output_update(&current_status);
		
	}
}

//--------------------------------- EMPIEZAN LAS FUNCIONES ----------------------------------------------------------------------------------------------------------


void input_update(ControlStatus *cs)
{
        // Menu and submenu handling:
        
        #ifdef ENCODER

        char btmp[127];
        sprintf(btmp, "cs->encoder.encoder_target %i", cs->encoder.encoder_target);
Serial.println(btmp);//zz

#endif


	switch ( cs->encoder.encoder_target ) // Vale 0
	{
		case MenuEncoderNdx:

                cs->encoder.positions[cs->encoder.encoder_target] = update_from_encoder(cs, cs->encoder.positions[cs->encoder.encoder_target], NUM_MENUS);//NUM_MENUS
                
                /* 
                  int update_from_encoder(ControlStatus *cs, int enc_pos, int x);
                  
                  int update_from_encoder = ( Paso de la estructura, parametro del valor de la funcion de encoder, valor maximo que puede alcanzar en este caso NUM_MENUS )
                  
                  ejemplo:
                  
                  update_from_encoder(cs, cs->encoder.positions[cs->encoder.encoder_target], NUM_MENUS): 3
                  cs->encoder.positions[cs->encoder.encoder_target]: 3
                  Valor de cs->encoder.encoder_target: 0

                  update_from_encoder(cs, cs->encoder.positions[cs->encoder.encoder_target], NUM_MENUS): 4
                  cs->encoder.positions[cs->encoder.encoder_target]: 4
                  Valor de cs->encoder.encoder_target: 0
                  
                  */
                  
                  #ifdef ENCODER_PRIMER_PASO

                  char btmp[127];
                  char btmp1[127];
                  char btmp2[127];
                  sprintf(btmp, "cs->encoder.positions[cs->encoder.encoder_target]: %i", cs->encoder.positions[cs->encoder.encoder_target]);
                  sprintf(btmp1, "update_from_encoder(cs, cs->encoder.positions[cs->encoder.encoder_target], NUM_MENUS): %i", update_from_encoder(cs, cs->encoder.positions[cs->encoder.encoder_target], NUM_MENUS));
                  sprintf(btmp2, "Valor de cs->encoder.encoder_target: %i", cs->encoder.encoder_target );
                Serial.println(btmp1);//zz
                Serial.println(btmp);
                Serial.println(btmp2);
                Serial.println("\n");
                ,
                #endif
                
                

                if (update_from_button(&current_status) == BUTTON_PRESSED)
                {
                	switch (cs->encoder.positions[MenuEncoderNdx])
                	{
                		case ME_KnobGroup:
                		cs->encoder.encoder_target = KnobGroupEncoderNdx;
                		break;

                		case ME_Knob:
                		cs->encoder.encoder_target = KnobEncoderNdx;
                		break;

                		case ME_ControlChange:
                		cs->encoder.encoder_target = ControlChangeEncoderNdx;
                		break;

                		case ME_MidiChannel:
                		cs->encoder.encoder_target = MidiChannelNdx;
                		break;

                		case ME_Behavior:
                		cs->encoder.encoder_target = BehaviorNdx;
                		break;
                	}

                	#ifdef ENCODER_SEGUNDO_PASO

                	char btmp[127];
                	char btmp1[127];
                	char btmp2[127];
                	sprintf(btmp, "cs->encoder.positions[cs->encoder.encoder_target]: %i", cs->encoder.positions[cs->encoder.encoder_target]);
                	sprintf(btmp1, "update_from_encoder(cs, cs->encoder.positions[cs->encoder.encoder_target], NUM_MENUS): %i", update_from_encoder(cs, cs->encoder.positions[cs->encoder.encoder_target], NUM_MENUS));
                	sprintf(btmp2, "Valor de cs->encoder.encoder_target: %i", cs->encoder.encoder_target );
                Serial.println(btmp1);//zz
                Serial.println(btmp);
                Serial.println(btmp2);
                Serial.println("\n");
                
                #endif



            }
            update_encoder_targets(cs);
            break;

	case KnobGroupEncoderNdx:// ----------------------------------------------------------------------------------Case-0

		// Serial.println("Knob group");
		cs->encoder.positions[cs->encoder.encoder_target] =
		update_from_encoder(&current_status, cs->encoder.positions[cs->encoder.encoder_target], NUM_KNOB_GROUPS);

		#ifdef DEBUG_MENU
		sprintf(btmp, "KnobGroupEncoderNdx: %i", cs->encoder.positions[cs->encoder.encoder_target]);
                Serial.println(btmp);//zz
                #endif

		if (update_from_button(&current_status) == BUTTON_RELEASED)	// pressed
		{  
			
			cs->encoder.encoder_target = MenuEncoderNdx;	// Return to menu.
		}
		break;

	case KnobEncoderNdx: // --------------------------------------------------------------------------------------Case-1

		// Serial.println("Knob");
		cs->encoder.positions[cs->encoder.encoder_target] =
		update_from_encoder(&current_status, cs->encoder.positions[cs->encoder.encoder_target], NUM_KNOBS);

		#ifdef DEBUG_MENU
		sprintf(btmp, "KnobEncoderNdx: %i", cs->encoder.positions[cs->encoder.encoder_target]);
                Serial.println(btmp);//zz
                #endif

		if (update_from_button(&current_status) == BUTTON_RELEASED)	// pressed
		{
			cs->encoder.encoder_target = MenuEncoderNdx;	// Return to menu.
		}
		break;

	case MidiChannelNdx:		// --------------------------------------------------------------------------Case-2 
								// Canal Midi
		// #include"canalMIDI.h"

		// Serial.println("Canal Midi");
		cs->encoder.positions[cs->encoder.encoder_target] =
		update_from_encoder(&current_status, cs->encoder.positions[cs->encoder.encoder_target], NUM_MIDI);

		#ifdef DEBUG_MENU
		sprintf(btmp, "MidiChannelNdx: %i", cs->encoder.positions[cs->encoder.encoder_target]);
                Serial.println(btmp);//zz
                #endif

                if (update_from_button(&current_status) == BUTTON_RELEASED)
                {
			// Assign midi channel
			int group = cs->encoder.positions[KnobGroupEncoderNdx];
			int knob = cs->encoder.positions[KnobEncoderNdx];
			cs->knobs[group].channel[knob] = cs->encoder.positions[cs->encoder.encoder_target];
			// Return to menu:
			cs->encoder.encoder_target = MenuEncoderNdx;
		}
		break;

	case ControlChangeEncoderNdx:	// -------------------------------------------------------------------------Case-3 
									// Control Change
		// Serial.println("Control Change");

		cs->encoder.positions[cs->encoder.encoder_target] =
		update_from_encoder(&current_status, cs->encoder.positions[cs->encoder.encoder_target], NUM_CONTROL_CHANGE);

		#ifdef DEBUG_MENU
		sprintf(btmp, "ControlChangeEncoderNdx: %i", cs->encoder.positions[cs->encoder.encoder_target]);
                Serial.println(btmp);//zz
                #endif


		if (update_from_button(&current_status) == BUTTON_RELEASED)	// pressed
		{
			// Assign control change:
			int group = cs->encoder.positions[KnobGroupEncoderNdx];
			int knob = cs->encoder.positions[KnobEncoderNdx];
			cs->knobs[group].control_change[knob] = cs->encoder.positions[cs->encoder.encoder_target];
			// Return to menu:
			cs->encoder.encoder_target = MenuEncoderNdx;
		}
		break;

	case BehaviorNdx: // --------------------------------------------------------------------------------------Case-4

	#ifdef DEBUG_MENU
	sprintf(btmp, "BehaviorNdx: %i", cs->encoder.positions[cs->encoder.encoder_target]);
                Serial.println(btmp);//zz
                #endif

		cs->encoder.encoder_target = MenuEncoderNdx;	// Unimplemented:
														// return to menu.
														break;

	}//switch

        // Read knob data:
        input_update_knobs(cs);
        
    }



//--------------------------------------------------- mas funciones-----------------------------------------------------------------------------------------------


void output_update(ControlStatus *cs)
{
        // Update MIDI parameters, if required:
        output_update_midi(cs);
    }



    void screen_update(ControlStatus *cs)
    {
	// Prepare LCD for drawing:
	u8g.firstPage();

	// Draw frame and constant parts:
	do
	{
                // Draw frame and constant parts:
                
                lcd_draw_header();

                // Dynamic data:
                lcd_draw_menu(cs);
                lcd_draw_knob(cs);
                input_update(cs);
            }
            while (u8g.nextPage());
        }




        int update_from_button(ControlStatus * cs)
        {
	// read the pushbutton input pin:
	int salida = BUTTON_IDLE;	// Initialize, always

	if (cs)
	{
		cs->button.buttonState = digitalRead(PIN_Button); // PIN_Button = 2;

		// compare the buttonState to its previous state
		if (cs->button.buttonState != cs->button.lastButtonState)
		{
			// if the state has changed, increment the counter
			if (cs->button.buttonState == HIGH)
			{
				// if the current state is HIGH then the button
				// wend from off to on:
				cs->button.buttonPushCounter++;

				#ifdef BOTON_PULSADO
				Serial.println("on");
				Serial.print("number of button pushes: ");
				Serial.println(cs->button.buttonPushCounter);
				#endif
				salida = BUTTON_PRESSED;
				
			}
			else
			{
				// if the current state is LOW then the button
				// wend from on to off:
				#ifdef DEBUG_MENU
				Serial.println("off");
				#endif
				salida = BUTTON_RELEASED;
				
				
			}
		}
		// save the current state as the last state, 
		// for next time through the loop
		cs->button.lastButtonState = cs->button.buttonState;
		
		#ifdef SALIDA
		Serial.print(salida == BUTTON_PRESSED? "BUTTON_PRESSED" : salida == BUTTON_RELEASED? "BUTTON_RELEASED" : "" );
		#endif

	}
	
	return salida;
}





int update_from_encoder(ControlStatus *cs, int enc_pos, int x)
{
	if (cs)
	{
		int lecturaPin = digitalRead(PIN_Encoder0A);
		if ((cs->encoder.ultimaPosicionPinA == HIGH) && (lecturaPin == LOW))
		{
			if (digitalRead(PIN_Encoder0B) == HIGH)
			{
				#ifdef DEBUG_MENU
				Serial.println("-");
				#endif

				enc_pos--;
				// lcd.clear();
			}
			else
			{
				#ifdef DEBUG_MENU
                                Serial.println("+");//zz!
                                #endif
                                enc_pos++;
				// lcd.clear();
			}
		}
		cs->encoder.ultimaPosicionPinA = lecturaPin;
		if (enc_pos < 0)
		{
			#ifdef DEBUG_MENU
                        Serial.println("- [0]");//zz!
                        #endif
                        enc_pos = 0;
                    }
                    if (enc_pos > x)
                    {
                    	enc_pos = x;
                    }
                }
                return enc_pos;
            }



            void input_update_knobs(ControlStatus * cs)
            {
            	const int inputs[NUM_KNOBS] = { A3, A2, A1, A0 };
            	const int knob_group = cs->encoder.positions[KnobGroupEncoderNdx];
            	
            	for ( int i = 0; i < NUM_KNOBS; i++ )
            	{
            		const int raw_input = analogRead(inputs[i]);
            		const int ADC_res_bits = 10;
      const int meaning_adc_bits = 4;  // Use 4 of the 10 ADC bits (e.g. 2**4 = 16 steps instead of 2**10 = 1024)
      const int remove_mask = ~(1 << (ADC_res_bits - meaning_adc_bits)) - 1;
      const int knob_current_value = raw_input & remove_mask;  // = (raw_input / 64) * 64;
      if ( cs->knobs[knob_group].knob[i] != knob_current_value )  // knob changed?
      {
      	delay(10);
      	cs->knobs[knob_group].knob[i] = knob_current_value;
      	#ifdef DEBUG_KNOBS

      	char btmp[32];
      	sprintf(btmp, "knob[%i, %i]: %i", 
      		knob_group, i, knob_current_value);
        Serial.println(btmp);//zz!
        #endif        
    }
}
}


void lcd_draw_knob(ControlStatus * cs)
{
	const int knob_group = cs->encoder.positions[KnobGroupEncoderNdx];
	
	u8g.setFont(u8g_font_micro);

	for ( int i = 0; i < NUM_KNOBS; i++ )
	{
		const int value = map(cs->knobs[knob_group].knob[i], 0, 1023, 0, 20);
		const int pct = map(cs->knobs[knob_group].knob[i], 0, 1023, 0, 107);

	// X, Y ; ancho , alto Linea vertical mas estrcha (debajo del restangulo )
	// rectangulo que sube o baja

	u8g.drawLine(2 + 20 * i, 60, 2 + 20 * i, 40);
	u8g.drawBox(1 + 20 * i, (60 - value), 3, 100);

        // Knob %
        u8g.drawStr(1 + 20 * i + 6, 64 - value, strcpy_P(buzzer, (char *)pgm_read_word(&(strin_table[pct]))));        // sample
    }
}




void lcd_draw_header()
{
	u8g.drawFrame(79, 0, 49, 64);	// X, Y ; ancho , alto Recuadro grupo
	u8g.drawLine(0, 30, 79, 30);	// linea entre el texto y los potes
	u8g.drawLine(0, 37, 79, 37);	// "" ""
	u8g.drawLine(79, 24, 128, 24);	// linea separadora grupo y auto
}


void indicador_de_pulsacion(ControlStatus * cs)
{

    //u8g.setFont(u8g_font_6x10);
    u8g.drawStr( 80, 15,"d"  );
}



void lcd_draw_menu(ControlStatus *cs)
{
	u8g.setFont(u8g_font_micro);
        const int font_width = 4;  // 4 point-wide font
        const int font_height = 6;  // 6 point-tall font
        const int menu_pos = cs->encoder.positions[MenuEncoderNdx];

        // Draw cursor:
        u8g.drawStr(1, 5 + (menu_pos * font_height), ">");

	// Draw menu entries:
	for ( int i = 0; i < ME_Elems; i++ )
	{	                
                // Draw text:
                
                
                
                u8g.drawStr(8, 5 + i*font_height, menu_labels[i]);
                if ( i != ME_ControlChange )  // Draw all except CC
                {
                	
    		  // Draw value:
                  //const int text_offset = (strlen(menu_labels[i]) ) * font_width;
                  
                  const int text_offset = (strlen(menu_labels[i]) ) * font_width;
                  
                  
                  
                  const int value = cs->encoder.positions[i+1];
                  const char *text = value >= 0 && value <= MAX_strin? (char *)pgm_read_word(&(strin_table[value])) : "???!";
                  u8g.drawStr(8 + text_offset, 5 + i*font_height, strcpy_P(buzzer, text));
              }
          }
	// Draw extra elements:

	const int cc_text_offset = (strlen(menu_labels[ME_ControlChange]) + 1) * font_width;
	const int value = cs->encoder.positions[ControlChangeEncoderNdx];
	const char *cc_text = value >= 0 && value <= MAX_string? (char *)pgm_read_word(&(string_table[value])) : "???!";
    	u8g.drawStr(8 + cc_text_offset, 5 + ME_ControlChange*font_height, strcpy_P(buffer, cc_text));	// Muestra  el  porcentaje que se mueve
    	
    	
    }



    void output_update_midi(ControlStatus *cs)
    {
    	const int knob_group = cs->encoder.positions[KnobGroupEncoderNdx];

    	for ( int i = 0; i < NUM_KNOBS; i++ )
    	{
    		const int midi_channel = cs->knobs[knob_group].channel[i];
    		const int cc = cs->knobs[knob_group].control_change[i];
    		const int value = map(cs->knobs[knob_group].knob[i], 0, 1023, 0, 137);
    		
    		if ( midi_channel >= 0 &&  midi_channel < NUM_MIDI  && cs->midi_status[midi_channel].cc != cc ||  cs->midi_status[midi_channel].knob_value != value )  
    		{
    			cs->midi_status[midi_channel].cc = cc;
    			cs->midi_status[midi_channel].knob_value = value;
    			MIDI.sendControlChange(cc,value,midi_channel);
                  //sendControlChange (byte ControlNumber, byte ControlValue, byte Channel)

                }
}
}


void ControlStatus_Init(ControlStatus * cs)
{
	memset(cs, 0, sizeof(ControlStatus));

	cs->button.buttonPushCounter = 1;	// Counter for the number of button presses
	cs->button.buttonState = 1;		// Current state of the button
	cs->button.lastButtonState = 0;      	// Previous state of the button

	cs->encoder.encoder_target = 0;
	cs->encoder.ultimaPosicionPinA = LOW;
	for ( int i = 0; i < NUM_KNOB_GROUPS; i++ )
	{
		for ( int j = 0; j < NUM_KNOBS; j++ )
		{
			cs->knobs[i].knob[j] = 0;
			cs->knobs[i].behavior[j] = 0;
			cs->knobs[i].control_change[j] = 0;
			cs->knobs[i].channel[j] = 0;
		}
	}      
	for ( int i = 0; i < NUM_MIDI; i++ )
	{
		cs->midi_status[i].cc = 0;
		cs->midi_status[i].knob_value = 0;
	}
}


void update_encoder_targets(ControlStatus *cs)
{
	const int knob_group = MAX(0, cs->encoder.positions[KnobGroupEncoderNdx]);
	const int knob = MAX(0, cs->encoder.positions[KnobEncoderNdx]);
	cs->encoder.positions[ControlChangeEncoderNdx] = MAX(0, cs->knobs[knob_group].control_change[knob]);
	cs->encoder.positions[MidiChannelNdx] = MAX(0, cs->knobs[knob_group].channel[knob]); 
	
	cs->encoder.positions[BehaviorNdx] = MAX(0, cs->knobs[knob_group].behavior[knob]);
}

