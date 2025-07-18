
#ifndef CONFIGURA_GERAL_H
#define CONFIGURA_GERAL_H

// Joystick Analógico KY-023
#define JOYSTICK_X_PIN 27 // VRx output
#define JOYSTICK_Y_PIN 26 // VRy output
#define JOYSTICK_SW_PIN 22 // SW button

// Limiares do Joystick (valores do ADC)
#define JOYSTICK_LIMIAR_CIMA    3000 // Valor do ADC para considerar "para cima"
#define JOYSTICK_LIMIAR_BAIXO   1000 // Valor do ADC para considerar "para baixo"
#define JOYSTICK_CENTRO_MIN     1500 // Início da faixa morta (deadzone) central
#define JOYSTICK_CENTRO_MAX     2500 // Fim da faixa morta (deadzone) central

#endif // CONFIGURA_GERAL_H